#include "l.h"
#include "ui_l.h"

#include <QKeyEvent>
#include <brigetestsetting_expect_R.h>
#include <qfiledialog.h>
#include <qmessagebox.h>
#include <qthread.h>
#include <xlsxdocument.h>
#include <xlsxformat.h>

L::L(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::L)
{
    ui->setupUi(this);
    ui->pushButton->setShortcut(Qt::Key_Space);
    updateconnectionStatus(false);
    calculateLRange();
    // 在连接上设备前无法设置参数
    ui->pushButtonSetting->setEnabled(false);
    // 计算电容值范围
    connect(ui->lineEditCStandard, &QLineEdit::textChanged,
            this, &L::calculateLRange);
    connect(ui->lineEditPrecision, &QLineEdit::textChanged,
            this, &L::calculateLRange);
    connect(ui->comboBoxUnit, &QComboBox::currentIndexChanged,
            this, &L::calculateLRange);
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

L::~L()
{
    delete ui;
}

void L::updateconnectionStatus(bool connected)
{
    if(connected){
        ui->connectionLabel_briget->setText("状态:已连接");
        ui->connectionLabel_briget->setStyleSheet("color: rgb(0, 255, 0)");
        ui->connectButton_briget->setEnabled(false);
    }
}

void L::calculateLRange()
{
    //qDebug() << "发生什么了";
    bool ok;
    // 获取标准值
    double standardValue = ui->lineEditCStandard->text().toDouble(&ok);
    if (!ok || standardValue <= 0) {
        ui->lineEditCRange->setText("请输入有效的标准值");
        return;
    }

    // 获取精确度
    double precision = ui->lineEditPrecision->text().toDouble(&ok);
    if (!ok || precision < 0) {
        ui->lineEditCRange->setText("请输入有效的精确度");
        return;
    }

    // 获取单位
    QString unit = ui->comboBoxUnit->currentText();
    double unitFactor = 1.0;
    if (unit == "mH") {
        unitFactor = 1e-3;
    } else if (unit == "μH") {
        unitFactor = 1e-6;
    } else if (unit == "nH") {
        unitFactor = 1e-9;
    } else if (unit == "pH") {
        unitFactor = 1e-12;
    }

    // 计算实际电感
    double actualValue = standardValue * unitFactor;

    // 计算范围
    minValue = actualValue * (1.0 - precision / 100.0);
    maxValue = actualValue * (1.0 + precision / 100.0);

    // 格式化显示
    QString rangeText;
    if (unit == "H") {
        rangeText = QString("%1 H ~ %2 H").arg(minValue, 0, 'f', 3).arg(maxValue, 0, 'f', 3);
    } else if (unit == "mH") {
        rangeText = QString("%1 mH ~ %2 mH").arg(minValue*1e3, 0, 'f', 3).arg(maxValue*1e3, 0, 'f', 3);
    } else if (unit == "μH") {
        rangeText = QString("%1 μH ~ %2 μH").arg(minValue*1e6, 0, 'f', 3).arg(maxValue*1e6, 0, 'f', 3);
    } else if (unit == "nH") {
        rangeText = QString("%1 nH ~ %2 nH").arg(minValue*1e9, 0, 'f', 3).arg(maxValue*1e9, 0, 'f', 3);
    } else if (unit == "pH") {
        rangeText = QString("%1 pH ~ %2 pH").arg(minValue*1e12, 0, 'f', 3).arg(maxValue*1e12, 0, 'f', 3);
    }
    //qDebug() << rangeText;
    ui->lineEditCRange->setText(rangeText);
}

void L::logMessage(QString str)
{
    ui->logMessageEdit->append(str);
}

void L::sendCommand(QString cmd)
{
    serial->write(cmd.toUtf8());
    serial->waitForBytesWritten(100);
}

void L::startMeasure_briget()
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
    double value_L = response.toDouble();
    // logMessage(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss  ")
    //            + QString("电容值: %1 F").arg(value_C));
    double Q = NAN;
    double Rs = NAN;
    // Q值
    if( dataSettings.is_Q ){
        QString response = QString::fromUtf8(data).trimmed().split(',')[1];
        Q = response.toDouble();
        //qDebug() << "Q= " << Q;
    }
    // Rs值
    if( dataSettings.is_Rs ){
        sendCommand(QString("FUNC:IMP CSRS\n"));  // 设置测量功能
        QThread::msleep(1000);
        sendCommand("TRIG\n");
        QThread::msleep(1000);
        sendCommand("FETC?\n");
        // 等待直到有数据可读或超时
        serial->waitForReadyRead(1000);
        QByteArray data_LsRs = serial->readAll();
        while(data_LsRs.isEmpty()) {
            // 尝试再次读取
            QThread::msleep(100);
            data_LsRs = serial->readAll();
        }
        qDebug() << QString::fromUtf8(data_LsRs).trimmed();
        QString response_2 = QString::fromUtf8(data_LsRs).trimmed().split(',')[1];
        Rs = response_2.toDouble();
        //qDebug() << "Rs= " << Rs;
        // 要切换回原来的模式
        sendCommand(QString("FUNC:IMP %1\n").arg(dataSettings.function));
    }
    QThread::msleep(1000);
    wValueToFile(value_L, Q, Rs);
}

void L::wValueToFile(double Value_L, double Q, double Rs)
{
    double original_Value_L = Value_L;
    // qDebug() << Value_L << " " << Q << " " << Rs;
    QString unit_L,unit_Rs;
    // 格式化数据
    if( Value_L > 1 ){
        unit_L = "H";
    }
    else if ( Value_L > 1e-3){
        unit_L = "mH"; Value_L = Value_L * 1e3;
    }
    else if ( Value_L > 1e-6){
        unit_L = "μH"; Value_L = Value_L * 1e6;
    }
    else if ( Value_L > 1e-9){
        unit_L = "nH"; Value_L = Value_L * 1e9;
    }
    else{
        unit_L = "pH"; Value_L = Value_L * 1e12;
    }
    // 格式化电阻
    if( Rs > 1000000.0 ){
        unit_Rs = "MΩ"; Rs = Rs / 1000000.0;
    }
    else if( Rs > 1000.0 ){
        unit_Rs = "kΩ"; Rs = Rs / 1000.0;
    }
    else if( Rs > 1.0){
        unit_Rs = "Ω";
    }
    else{
        unit_Rs = "mΩ"; Rs = Rs * 1e3;
    }
    QStringList text; // 需要写入的文本
    // 这个数据合格吗
    bool isPass = ( original_Value_L > minValue && original_Value_L < maxValue );
    // 不合格需要提示是否需要重新测
    QMessageBox::StandardButton ret = QMessageBox::No;
    if( dataSettings.is_Q && dataSettings.is_Rs ){
        text << QString("%1 %2").arg(Value_L).arg(unit_L) << QString(" %1").arg(Q) << QString(" %1 %2").arg(Rs).arg(unit_Rs);
        ret = QMessageBox::question(this, "数据不合格,是否需要重新检测?", text[0] + text[1] + text[2]);
    }
    else if( dataSettings.is_Q ){
        text << QString("%1 %2").arg(Value_L).arg(unit_L) << QString("%1").arg(Q);
        ret = QMessageBox::question(this, "数据不合格,是否需要重新检测?", text[0] + text[1]);
    }
    else if( dataSettings.is_Rs ){
        text << QString("%1 %2").arg(Value_L).arg(unit_L) << QString("%1 %2").arg(Rs).arg(unit_Rs);
        ret = QMessageBox::question(this, "数据不合格,是否需要重新检测?", text[0] + text[1]);
    }
    else{
        text << QString("%1 %2").arg(Value_L).arg(unit_L);
        ret = QMessageBox::question(this, "数据不合格,是否需要重新检测?", text[0]);
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
    int row = 5 ,col = 1;
    QXlsx::Document xlsx(fileName_Excel);


    //写入检测数据
    qDebug() << "开始写入数据";
    xlsx.selectSheet("检测数据");
    if( dataSettings.is_Q || dataSettings.is_Rs ){
        // Q or Rs 存在
        while(true){
            std::shared_ptr<QXlsx::Cell> cell = xlsx.cellAt( row, col);
            if( !cell ){
                xlsx.write( row, col, QDateTime::currentDateTime().toString("yyyy-M-d h:m"), textFormat);
                xlsx.write( row, col+1, text[0], textFormat);
                int i=2;
                if( dataSettings.is_Q ){
                    xlsx.write( row, col+i, text[1], textFormat);
                    i++;
                }
                if( dataSettings.is_Rs ){
                    xlsx.write( row, col+i, text[2], textFormat);
                }
                break;
            }
            QVariant cellValue = cell->value();
            if (cellValue.isNull() || cellValue.toString().trimmed().isEmpty()) {
                xlsx.write( row, col, QDateTime::currentDateTime().toString("yyyy-M-d h:m"), textFormat);
                xlsx.write( row, col+1, text[0], textFormat);
                int i=2;
                if( dataSettings.is_Q ){
                    xlsx.write( row, col+i, text[1], textFormat);
                    i++;
                }
                if( dataSettings.is_Rs ){
                    xlsx.write( row, col+i, text[2], textFormat);
                }
                break;
            }
            row++;
        }
    }else{
        // 无 Q Rs
        while(true){
            std::shared_ptr<QXlsx::Cell> cell = xlsx.cellAt( row, col);
            if( row > 1000 ){
                QMessageBox::critical(this,"提示","已寻找超过1000行");
                return;
            }
            if( !cell ){
                xlsx.write( row, col, QDateTime::currentDateTime().toString("yyyy-M-d h:m"), textFormat);
                xlsx.write( row, col+1, text[0], textFormat);
                break;
            }
            QVariant cellValue = cell->value();
            if (cellValue.isNull() || cellValue.toString().trimmed().isEmpty()) {
                xlsx.write( row, col, QDateTime::currentDateTime().toString("yyyy-M-d h:m"), textFormat);
                xlsx.write( row, col+1, text[0], textFormat);
                break;
            }
            if( col+2 > 10 ){
                row++;
                col=1;
                continue;
            }
            col+=2;
        }
    }

    //是否合格
    int pass = xlsx.read("D4").toInt();
    int imPass = xlsx.read("F4").toInt();
    if( isPass ){
        pass++;
        xlsx.write("D4",pass,textFormat);
    }
    else{
        imPass++;
        xlsx.write("F4",imPass,textFormat);
    }
    xlsx.selectSheet("电感");
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

bool L::eventFilter(QObject *obj, QEvent *event)
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

void L::on_pushButton_clicked()
{
    if( !isConnected ){
        QMessageBox::critical(this,"提示","未连接到任何设备");
        return;
    }
    // 防止连续多次测量
    ui->pushButton->setEnabled(false);
    startMeasure_briget();
    ui->pushButton->setEnabled(true);
}


void L::on_pushButton_Excel_clicked()
{
    // 让用户选择保存位置
    QString defaultFileName = QString("电感器件检测_2.xlsx");
    fileName_Excel = QFileDialog::getSaveFileName(
        this,
        "新建电感器件检测文档", // title
        QDir::currentPath() + "/" + defaultFileName,
        "Excel文件 (*.xlsx *.xls)"
        );

    if (fileName_Excel.isEmpty()) {
        return; // 用户取消了
    }

    // 复制文件
    if (QFile::copy("电感器件检测.xlsx", fileName_Excel)) {
        QMessageBox::information(this, "成功", "已创建新的电感器件检测测试表,在设备连接后可以按下空格开始检测第一个数据");
    } else {
        QMessageBox::warning(this, "失败",
                             QString("复制失败！\n"));
    }

    // 写入基本信息
    // 设置默认字体格式
    QXlsx::Format textFormat;
    textFormat.setFontBold(false);
    textFormat.setFontSize(12);
    textFormat.setFontName("宋体");
    textFormat.setBorderStyle(QXlsx::Format::BorderThin);
    textFormat.setHorizontalAlignment(QXlsx::Format::AlignHCenter);
    textFormat.setVerticalAlignment(QXlsx::Format::AlignVCenter);

    QXlsx::Document xlsx(fileName_Excel);
    xlsx.selectSheet("电感");
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
    xlsx.write("N5",ui->lineEditBatch->text());
    xlsx.write("R5",ui->lineEditNumber2->text(),textFormat);
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
    QString r = ui->lineEditCRange->text();
    xlsx.write("C21","□ 外观颜色应均匀，标识应清晰完整，本体应无破裂、崩缺、残缺等现象。\n"
                      "□ 电感值：        " + r);


    // 保存文件
    if (xlsx.saveAs(fileName_Excel)) {
        logMessage(QString("基本信息保存成功"));
        return;
    } else {
        logMessage(QString("基本信息保存失败"));
        return;
    }
}


void L::on_pushButton_selectExcel_clicked()
{
    QString selectedFile = QFileDialog::getOpenFileName(
        this,
        "选择Excel文件",             // 对话框标题
        QDir::currentPath(),                 // 默认打开目录
        "Excel文件 (*.xlsx *.xls);;" // 文件过滤器
        "所有文件 (*.*)"              // 可选的更多过滤器
        );

    if (selectedFile.isEmpty()) {
        return;
    }
    fileName_Excel = selectedFile;
    QMessageBox::information(this,"提示","测试前依照文档内容设置电感值范围");
    logMessage("已经选择了\n" + fileName_Excel + "\n作为测试输出文件");
}


void L::on_connectButton_briget_clicked()
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


void L::on_pushButtonSetting_clicked()
{
    if( !isConnected ){
        QMessageBox::critical(this, "提示", "未连接到设备");
        return;
    }
    brigetestsetting_expect_R* bts = new brigetestsetting_expect_R("L",this);
    // 传递数据信号槽
    connect(bts, &brigetestsetting_expect_R::settingData, this,[=](brigetestData data){
        this->dataSettings = data;
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
    this->isConnected = true;
    QMessageBox::information(this,"提示","电桥测量参数设置完成");
}

