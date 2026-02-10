#include "va.h"
#include "qevent.h"
#include "ui_va.h"
#include "visa.h"

#include <brigetestersetting.h>
#include <qfile.h>
#include <qfiledialog.h>
#include <qmessagebox.h>
#include <qserialport.h>
#include <qserialportinfo.h>
#include <qthread.h>
#include <xlsxdocument.h>

va::va(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::va)
{
    ui->setupUi(this);
    ui->pushButton->setShortcut(Qt::Key_Space);
    updateconnectionStatus(false);
    initialVisaManager();
    calculateRRange(); // 界面打开计算一次电阻值范围
    ui->pushButtonSetting->setEnabled(false);
    // qt自动连接槽函数有问题
    connect(ui->pushButtonSetting, &QPushButton::clicked, this, &va::on_pushButtonSetting_clicked);
    connect(ui->connectButton_briget, &QPushButton::clicked, this, &va::on_connectButton_briget_clicked);
    // 当选择电桥时,电桥设置按钮才可用
    // connect(ui->comboBox, &QComboBox::currentIndexChanged, this, [=](int cur){
    //     if( cur == 1 ){
    //         ui->pushButtonSetting->setEnabled(true);
    //     }else{
    //         ui->pushButtonSetting->setEnabled(false);
    //     }
    // });
    // 计算电阻值范围
    connect(ui->lineEditResistorStandard, &QLineEdit::textChanged,
            this, &va::calculateRRange);
    connect(ui->lineEditPrecision, &QLineEdit::textChanged,
            this, &va::calculateRRange);
    connect(ui->comboBoxUnit, &QComboBox::currentIndexChanged,
            this, &va::calculateRRange);
    // 设备选择
    connect(ui->comboBox, &QComboBox::currentIndexChanged, this, [=](int index){
        //logMessage(QString("%1").arg(index));
        if( index == 0 ){
            ui->comboBox_2->clear();
            ui->comboBox_2->insertItem(0, "DM3068");
            ui->comboBox_2->insertItem(1 , "34461A");
            return;
        }
        ui->comboBox_2->clear();
        ui->comboBox_2->insertItem(0, "TH2810B+");
    });

    // 为所有控件安装事件过滤器
    QList<QWidget*> allWidgets = this->findChildren<QWidget*>();
    for (QWidget* widget : allWidgets) {
        // 检查是否为输入控件
        if (qobject_cast<QLineEdit*>(widget) ||
            qobject_cast<QComboBox*>(widget) ||
            qobject_cast<QDateEdit*>(widget) ||
            qobject_cast<QTextEdit*>(widget)) {
            widget->installEventFilter(this);
        }
    }
}

va::~va()
{
    delete ui;
}

void va::updateconnectionStatus(bool connected)
{
    // 更新连接状态
    if( ui->comboBox->currentText() == "数字万用表" ){
        if(connected){
            ui->connectionLabel->setText("状态:已连接");
            ui->connectionLabel->setStyleSheet("color: rgb(0, 255, 0)");
            ui->connectButton->setEnabled(false);
            ui->disConnectButton->setEnabled(true);
        }else{
            ui->connectionLabel->setText("状态:未连接");
            ui->connectionLabel->setStyleSheet("color: rgb(255, 0, 0)");
            ui->disConnectButton->setEnabled(false);
            ui->connectButton->setEnabled(true);
        }
    }else{
        if(connected){
            ui->connectionLabel_briget->setText("状态:已连接");
            ui->connectionLabel_briget->setStyleSheet("color: rgb(0, 255, 0)");
            ui->connectButton_briget->setEnabled(false);
        }
    }
}

void va::initialVisaManager()
{
    status = viOpenDefaultRM(&defaultRM);
    if( status < VI_SUCCESS){
        logMessage("无法打开VISA资源管理器");
        QMessageBox::critical(this,"VISA错误","无法初始化VISA资源管理器");
    }else{
        logMessage("成功初始化VISA资源管理器");
    }
    ui->disConnectButton->setEnabled(false);
}

void va::logMessage(QString str)
{
    ui->logMessageEdit->append(str);
}

void va::startMeasure()
{
    QString cmd=":MEASure:FRESistance?\n";
    ViUInt32 writeCount = 0;
    //开启电阻测量
    status= viWrite(instrument,
                     (ViBuf)cmd.toUtf8().constData(),
                     cmd.length(),
                     &writeCount);
    if( status < VI_SUCCESS ){
        logMessage("电阻数据请求失败");
        return;
    }
    char buffer[256] = {0};
    ViUInt32 retCount = 0;

    status = viRead(instrument,(ViBuf)buffer, 255, &retCount);
    if( status < VI_SUCCESS ){
        logMessage("数据读取失败");
    }

    buffer[retCount] = '\0';
    QString val(buffer); bool ok;
    double value = val.toDouble(&ok);
    // int min = ui->minLineEdit->text().toInt();
    // int max = ui->maxLineEdit->text().toInt();
    // if( value < min || value > max ){
    //     logMessage("超出测量判据");
    //     return;
    // }
    logMessage(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss  ")
               + QString("电阻值: %1 Ω").arg(value));
    wValueToFile(value);
}

void va::startMeasure_briget()
{
    sendCommand("TRIG\n");
    QThread::msleep(1000);
    sendCommand("FETC?\n");
    // 等待直到有数据可读或超时
    serial->waitForReadyRead(1000);
    QByteArray data = serial->readAll();
    while(data.isEmpty()) {
        // 尝试再次读取
        QThread::msleep(100);
        data = serial->readAll();
    }
    QString response = QString::fromUtf8(data).trimmed().split(',')[0];
    double value = response.toDouble();
    logMessage(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss  ")
               + QString("电阻值: %1 Ω").arg(value));
    wValueToFile(value);
}

void va::wValueToFile(double value)
{
    // qDebug() << "fileName_Excel" << fileName_Excel;
    QXlsx::Document xlsx(fileName_Excel);
    xlsx.selectSheet("检测数据");
    QString unit;
    double displayValue;

    if (value >= 1000000) { // 1 MΩ 以上
        displayValue = value / 1000000.0;
        unit = "MΩ";
    } else if (value >= 1000) { // 1 kΩ 以上
        displayValue = value / 1000.0;
        unit = "kΩ";
    } else if (value >= 1.0  ){ // 1 Ω 以上
        displayValue = value;
        unit = "Ω";
    }else{ // 小于 1 Ω
        displayValue = value * 1000.0;
        unit = "mΩ";
    }
    QMessageBox::StandardButton ret = QMessageBox::No;
    if( value < minValue || value > maxValue ){
        ret = QMessageBox::question(this,"数据不合格是否需要重新检测",QString("%1 %2").arg(displayValue).arg(unit));
    }
    if( ret == QMessageBox::Yes ){
        // 需要重新测，不写入数据
        return;
    }
    // 格式
    QXlsx::Format textFormat;
    textFormat.setFontBold(false);
    textFormat.setFontSize(10);
    textFormat.setFontName("宋体");
    // textFormat.setBorderStyle(QXlsx::Format::BorderThin);
    textFormat.setHorizontalAlignment(QXlsx::Format::AlignHCenter);
    textFormat.setVerticalAlignment(QXlsx::Format::AlignVCenter);

    int row=4,col=1;
    while(true){
        std::shared_ptr<QXlsx::Cell> cell = xlsx.cellAt(row, col); // 列A = 1
        if( row >1000 ){
            QMessageBox::critical(this,"提示","已寻找超过1000行");
            return;
        }
        if( !cell ){
            xlsx.mergeCells(QXlsx::CellRange(row, col, row, col+1));
            xlsx.write( row, col, QString("%1 %2").arg(displayValue).arg(unit), textFormat);
            break;
        }
        QVariant cellValue = cell->value();
        if (cellValue.isNull() || cellValue.toString().trimmed().isEmpty()) {
            xlsx.mergeCells(QXlsx::CellRange(row, col, row, col+1));
            xlsx.write( row, col, QString("%1 %2").arg(displayValue).arg(unit), textFormat);
            break;
        }
        if( col+2 > 18 ){
            row++;
            col = 1;
            continue;
        }
        col = col + 2;
    }
    //是否合格
    int pass = xlsx.read("B3").toInt();
    int imPass = xlsx.read("D3").toInt();
    if( value < minValue || value > maxValue ){
        imPass++;
        xlsx.write("D3",QString("%1").arg(imPass),textFormat);
    }
    else{
        pass++;
        xlsx.write("B3",QString("%1").arg(pass),textFormat);
    }
    xlsx.selectSheet("电阻");
    xlsx.write("A23",QString("本项目检测 %1 只合格, %2 只不合格。").arg(pass).arg(imPass),textFormat);

    // 保存文件
    if (xlsx.saveAs(fileName_Excel)) {
        logMessage(QString("测量数据保存成功"));
        return;
    } else {
        logMessage(QString("测量数据保存失败"));
        return;
    }
}

void va::calculateRRange()
{
    bool ok;
    // 获取标准值
    double standardValue = ui->lineEditResistorStandard->text().toDouble(&ok);
    if (!ok || standardValue <= 0) {
        ui->lineEditResistorRange->setText("请输入有效的标准值");
        return;
    }

    // 获取精确度
    double precision = ui->lineEditPrecision->text().toDouble(&ok);
    if (!ok || precision < 0) {
        ui->lineEditResistorRange->setText("请输入有效的精确度");
        return;
    }

    // 获取单位
    QString unit = ui->comboBoxUnit->currentText();
    double unitFactor = 1.0;
    if (unit == "kΩ") {
        unitFactor = 1000.0;
    } else if (unit == "MΩ") {
        unitFactor = 1000000.0;
    } else if (unit == "Ω") {
        unitFactor = 1.0;
    } else if (unit == "mΩ"){
        unitFactor = 1e-3;
    }

    // 计算实际电阻值（以Ω为单位）
    double actualValue = standardValue * unitFactor;

    // 计算范围
    minValue = actualValue * (1.0 - precision / 100.0);
    maxValue = actualValue * (1.0 + precision / 100.0);

    // 格式化显示
    QString rangeText;
    if (unit == "Ω") {
        rangeText = QString("%1 Ω ~ %2 Ω").arg(minValue, 0, 'f', 2).arg(maxValue, 0, 'f', 2);
    } else if (unit == "kΩ") {
        rangeText = QString("%1 kΩ ~ %2 kΩ").arg(minValue/1000.0, 0, 'f', 2).arg(maxValue/1000.0, 0, 'f', 2);
    } else if (unit == "MΩ") {
        rangeText = QString("%1 MΩ ~ %2 MΩ").arg(minValue/1000000.0, 0, 'f', 2).arg(maxValue/1000000.0, 0, 'f', 2);
    } else if (unit == "mΩ"){
        rangeText = QString("%1 mΩ ~ %2 mΩ").arg(minValue*1e3, 0, 'f', 2).arg(maxValue*1e3, 0, 'f', 2);
    }

    ui->lineEditResistorRange->setText(rangeText);
}

bool va::eventFilter(QObject *obj, QEvent *event)
{
    if( event->type() == QEvent::KeyPress ){
        QKeyEvent* KeyE = static_cast<QKeyEvent*>(event); // c++版本 我需要重新处理键盘事件对象，keyEvent是继承event的，这里我知道一定是keyEvent
        if( KeyE->key() == Qt::Key_Space && !KeyE->isAutoRepeat() ){
            if( qobject_cast<QLineEdit*>(obj) ){ // Qt版本
                on_pushButton_clicked();
                return true;
            }
        }
    }
    return QWidget::eventFilter(obj, event);
}

void va::sendCommand(QString cmd)
{
    serial->write(cmd.toUtf8());
    serial->waitForBytesWritten(100);
    // qDebug() << "发送命令:" << cmd.trimmed();

}

void va::on_connectButton_clicked()
{
    QString ipAddress = ui->ipEdit->text().trimmed();
    // 创建资源请求串
    QString resourceString = QString("TCPIP0::%1::INSTR").arg(ipAddress);
    logMessage(QString("正在连接: %1").arg(resourceString));

    status = viOpen(defaultRM,
                    (ViRsrc)resourceString.toUtf8().constData(),
                    VI_NULL, VI_NULL, &instrument);

    if (status < VI_SUCCESS) {
        logMessage("连接失败");
        QMessageBox::critical(this, "连接错误",
                              QString("无法连接到设备 %1").arg(ipAddress));
        instrument = VI_NULL;
        updateconnectionStatus(false);
        return;
    }
    // 5秒超时
    viSetAttribute(instrument, VI_ATTR_TMO_VALUE, 5000);

    // 测试连接
    char buffer[256] = {0};
    ViUInt32 retCount = 0;

    // 发送识别命令
    status = viWrite(instrument, (ViBuf)"*IDN?\n", 5, &retCount);

    if (status >= VI_SUCCESS) {
        status = viRead(instrument, (ViBuf)buffer, 255, &retCount);
        if (status >= VI_SUCCESS) {
            buffer[retCount] = '\0';
            logMessage(QString("设备识别: %1").arg(buffer));

            isConnected = true; // 连接标识
            updateconnectionStatus(true);
            logMessage("连接成功!");
        }
    }
    // 连接失败
    if (!isConnected) {
        logMessage("连接失败");
        viClose(instrument);
        instrument = VI_NULL;
    }
}


void va::on_disConnectButton_clicked()
{
    status = viClose(instrument);
    if( status == VI_SUCCESS ){
        isConnected = false;
        updateconnectionStatus(false);
        logMessage("已断开连接");
    }else{
        logMessage("断开连接失败");
    }
}


void va::on_pushButton_clicked()
{
    if( isConnected != true ){
        QMessageBox::critical(this,"提示","未连接到任何设备");
        return;
    }
    // 防止连续多次测量
    ui->pushButton->setEnabled(false);
    // 根据测量设备选择测量函数
    if( ui->comboBox->currentText() == "电桥" ){
        startMeasure_briget();
    }
    else{
        startMeasure();
    }
    ui->pushButton->setEnabled(true);
}



void va::on_pushButton_Excel_clicked()
{
    // 让用户选择保存位置
    QString defaultFileName = QString("电阻器件检测_2.xlsx");
    fileName_Excel = QFileDialog::getSaveFileName(
        this,
        "新建电阻器件检测文档", // title
        QDir::currentPath() + "/" + defaultFileName,
        "Excel文件 (*.xlsx *.xls)"
        );

    if (fileName_Excel.isEmpty()) {
        return; // 用户取消了
    }

    // 复制文件
    if (QFile::copy("电阻器件检测.xlsx", fileName_Excel)) {
        QMessageBox::information(this, "成功", "已创建新的电阻器件检测测试表,在设备连接后可以按下空格开始检测第一个数据");
    } else {
        QMessageBox::warning(this, "失败",
                             QString("复制失败！\n"));
    }

    // 写入基本信息
        // 设置默认字体格式
    QXlsx::Format textFormat;
    textFormat.setFontBold(false);
    textFormat.setFontSize(10);
    textFormat.setFontName("宋体");
    textFormat.setBorderStyle(QXlsx::Format::BorderThin);
    textFormat.setHorizontalAlignment(QXlsx::Format::AlignHCenter);
    textFormat.setVerticalAlignment(QXlsx::Format::AlignVCenter);

    QXlsx::Document xlsx(fileName_Excel);
    xlsx.selectSheet("电阻");
    xlsx.write("P2",ui->lineEditOrder->text());
    if(ui->radioButtonFirst->isChecked()) {
        xlsx.write("A3","✓初始检测          □中间检测          □最终检测",textFormat);
    } else if(ui->radioButtonMiddle->isChecked()) {
        xlsx.write("A3","□初始检测          ✓中间检测          □最终检测",textFormat);
    } else  {
        xlsx.write("A3","□初始检测          □中间检测          ✓最终检测",textFormat);
    }

    xlsx.write("C5",ui->lineEditName->text(),textFormat);
    xlsx.write("G5",ui->lineEditNumber1->text(),textFormat);
    xlsx.write("I5",ui->lineEditSpecification->text(),textFormat);
    xlsx.write("N5",ui->lineEditBatch->text(),textFormat);
    xlsx.write("R5",ui->lineEditNumber2->text());
    xlsx.write("C6",ui->lineEditLocation->text(),textFormat);
    xlsx.write("I6",ui->lineEditManufacturer->text(),textFormat);
    xlsx.write("P6",ui->lineEditQualityLevel->text(),textFormat);
    xlsx.write("C8",ui->lineEditTemperature->text(),textFormat);
    xlsx.write("I8",ui->lineEditHumidity->text(),textFormat);
    xlsx.write("P8",ui->lineEditPressure->text(),textFormat);
    xlsx.write("E9",ui->comboBox->currentText(),textFormat);
    xlsx.write("I9",ui->comboBox_2->currentText(),textFormat);
    xlsx.write("P9",ui->dateEditMin->dateTime().toString("yyyy.M.d")+ "-" +
                         ui->dateEditMax->dateTime().toString("yyyy.M.d"),textFormat);
    xlsx.write("E10",ui->comboBox_3->currentText(),textFormat);
    xlsx.write("I10",ui->comboBox_4->currentText(),textFormat);
    xlsx.write("P10",ui->dateEditMin_2->dateTime().toString("yyyy.M.d")+ "-" +
                          ui->dateEditMax_2->dateTime().toString("yyyy.M.d"),textFormat);
    QString r = ui->lineEditResistorRange->text();
    xlsx.write("C21","□ 外观颜色应均匀，标识应清晰完整，本体应无破裂、崩缺、残缺等现象。\n"
                     "□ 电阻值：        " + r);


    // 保存文件
    if (xlsx.saveAs(fileName_Excel)) {
        logMessage(QString("基本信息保存成功"));
        return;
    } else {
        logMessage(QString("基本信息保存失败"));
        return;
    }
}

void va::on_pushButton_selectExcel_clicked()
{
    //qDebug() << "当前工作目录是:" << QDir::currentPath();
    // 弹出文件选择对话框
    QString selectedFile = QFileDialog::getOpenFileName(
        this,                        // 父窗口
        "选择Excel文件",             // 对话框标题
        QDir::currentPath(),                 // 默认打开目录
        "Excel文件 (*.xlsx *.xls);;" // 文件过滤器
        "所有文件 (*.*)"              // 可选的更多过滤器
        );

    if (selectedFile.isEmpty()) {
        // 取消了选择
        return;
    }
    fileName_Excel = selectedFile;
    QMessageBox::information(this,"提示","测试前依照文档内容设置电阻值范围");
    logMessage("已经选择了\n" + fileName_Excel + "\n作为测试输出文件");
}



void va::on_pushButtonSetting_clicked()
{
    brigetestersetting *bts = new brigetestersetting(this);
    // 传递数据信号槽
    connect(bts, &brigetestersetting::settingData, this,[=](brigetestData data){
        this->dataSettings = data; // 结构体
        // qDebug() << "传递后的数据:";
        // qDebug() << this->dataSettings.function
        //          << this->dataSettings.frequency
        //          << this->dataSettings.voltage
        //          << this->dataSettings.outPutResister;
    });
    int ret = bts->exec();
    if( ret == QDialog::Rejected ){
        return;
    }
    // 发送测试参数
    sendCommand("TRIG:SOUR BUS\n"); // 设置触发源为BUS模式
    QThread::msleep(100);
    sendCommand(QString("FUNC:IMP %1\n").arg(dataSettings.function));  // 设置测量功能
    QThread::msleep(100);
    sendCommand(QString("FREQ %1\n").arg(dataSettings.frequency));    // 设置测试频率
    QThread::msleep(100);
    sendCommand(QString("VOLT %1\n").arg(dataSettings.voltage));    // 设置测试电平
    QThread::msleep(100);
    sendCommand(QString("ORES %1\n").arg(dataSettings.outPutResister)); // 设置输出内阻
    QThread::msleep(100);
    sendCommand("APER FAST\n");// 设置测量速度
    QThread::msleep(100);
    sendCommand("FUNC:IMP:RANG:AUTO ON\n");// 设置量程为自动
    QThread::msleep(100);


    QMessageBox::information(this,"提示","电桥测量参数设置完成");
}

void va::on_connectButton_briget_clicked()
{
    if( ui->portEdit->text().isEmpty() ){
        QMessageBox::critical(this, "提示", "输入设备端口号");
        return;
    }
    serial = new QSerialPort(this);
    serial->setPortName(QString("COM%1").arg(ui->portEdit->text()));
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setParity(QSerialPort::NoParity);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    if(serial->open(QIODevice::ReadWrite)){
        logMessage(QString("识别到 COM%1").arg(ui->portEdit->text()));
        isConnected = true;
        updateconnectionStatus(true);
        ui->pushButtonSetting->setEnabled(true);
        logMessage("可以开始设置仪器参数");
    }else{
        qDebug() << "打开失败";
    }
}

