#include "r.h"
#include "ui_r.h"

#include <QFile>
#include <QMessageBox>
#include <device_dm3068.h>
#include <qthread.h>
#include <qtimer.h>
#include <visa.h>
#include <QFileDialog>
#include <xlsxformat.h>
#include <xlsxdocument.h>
const QString R::cmd[4] = {
    ":MEASure:VOLTage:DC?\n", // 直流电压  V
    ":MEASure:VOLTage:AC?\n", // 交流电压  V
    ":MEASure:CURRent:DC?\n", // 直流电流  A
    ":MEASure:CURRent:AC?\n"  // 交流电流  A
};
R::R(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::R)
{
    ui->setupUi(this);
    updateconnectionStatus(false);
    initialVisaManager();
    // // 设备选择
    // connect(ui->comboBox, &QComboBox::currentIndexChanged, this, [=](int index){
    //     //logMessage(QString("%1").arg(index));
    //     if( index == 0 ){
    //         ui->comboBox_2->clear();
    //         ui->comboBox_2->insertItem(0, "DM3068");
    //         ui->comboBox_2->insertItem(1 , "34461A");
    //         return;
    //     }
    //     ui->comboBox_2->clear();
    //     ui->comboBox_2->insertItem(0, "TH2810B+");
    // });
}

R::~R()
{
    delete ui;
}

void R::startMeasure()
{
    int iS = internalS.hour()*3600 + internalS.minute()*60 + internalS.second();
    QTimer *Qt = new QTimer;
    Qt->setInterval(iS*1000);
    Count = 0;
    connect(Qt, &QTimer::timeout, this, [=](){
        Count++;
        QString curTime = QDateTime::currentDateTime().toString("yyyy-M-d H:m:s");
        logMessage(QString(curTime + ":即将进行第%1次测量").arg(Count));
        measureVA();
        if( Count >= t ){
            // 测量结束，提示生成的文档名，提示合并文档
            QMessageBox::information(this,"检测完成",QString("已生成单独的测试文档"));
            Qt->stop();
            logMessage(QString("检测结束,文档已保存至\n%1").arg(fileName_temExcel));
        }
    });
    Qt->start();
}

void R::updateconnectionStatus(bool connected)
{
    // 更新连接状态
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
}

void R::initialVisaManager()
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

void R::logMessage(QString str)
{
    ui->logMessageEdit->append(str);
}

void R::measureVA()
{
    const char* measureNames[]={
        "直流电压","交流电压","直流电流","交流电流"
    };
    double value;
    int i;
    if( obj == "直流电压" ) i=0;
    else if( obj == "交流电压" ) i=1;
    else if( obj == "直流电流" ) i=2;
    else i=3;
    ViUInt32 writeCount = 0;
    status= viWrite(instrument,
                     (ViBuf)cmd[i].toUtf8().constData(),
                     cmd[i].length(),
                     &writeCount);
    if( status < VI_SUCCESS ){
        logMessage(QString("%1数据请求失败").arg(measureNames[i]));
        return;
    }
    char buffer[256] = {0};
    ViUInt32 retCount = 0;
    status = viRead(instrument,(ViBuf)buffer, 255, &retCount);
    if( status < VI_SUCCESS ){
        logMessage(QString("%1直流电压数据读取失败").arg(measureNames[i]));
        return;
    }
    buffer[retCount] = '\0';
    QString val(buffer);
    value = val.toDouble();
    QString mod = (i<2) ? "V" : "A";
    logMessage(QString("%1值: %2 %3").arg(measureNames[i]).arg(value).arg(mod));
    QThread::sleep(2);
    wValueToFile(value,mod);
}

void R::wValueToFile(double value, QString unit)
{
    // bool fileExists = QFile::exists(fileName);
    // 写入数据
    QXlsx::Document xlsx(fileName_temExcel);
    // 格式
    QXlsx::Format textFormat;
    textFormat.setFontBold(false);
    textFormat.setFontSize(10);
    textFormat.setFontName("宋体");
    // textFormat.setBorderStyle(QXlsx::Format::BorderThin);
    textFormat.setHorizontalAlignment(QXlsx::Format::AlignHCenter);
    textFormat.setVerticalAlignment(QXlsx::Format::AlignVCenter);
    // 寻找写一个空单元格
    int row = 5,col = 1;
    while(true){
        std::shared_ptr<QXlsx::Cell> cell = xlsx.cellAt(row, col);
        if( row > 1000 ){
            QMessageBox::critical(this,"提示","已寻找超过1000行");
            return;
        }
        if( !cell ){
            xlsx.write(row, col, QDateTime::currentDateTime().toString("yyyy.M.d H:m"));
            xlsx.write(row, col+1, QString("%1 %2").arg(value).arg(unit));
            break;
        }
        if( col+2 > 10 ){
            col = 1;
            row++;
            continue;
        }
        col+=2;
    }
    xlsx.save();
}



void R::on_pushButton_clicked()
{
    if( isConnected != true ){
        QMessageBox::critical(this,"提示","未连接到任何设备");
        return;
    }
    device_dm3068 *d= new device_dm3068(this);
    connect(d, &device_dm3068::detectionObj, this, [=](QString object){
        obj = object;
        logMessage(QString("检测对象为: %1").arg(obj));
    });
    connect(d, &device_dm3068::times, this, [=](int times){
        this->t = times;
        logMessage(QString("测量次数: %1 次").arg(t));
    });
    connect(d, &device_dm3068::internalSeconds, this, [=](QTime iS){
        this->internalS = iS;
        logMessage(QString("测量时间间隔: %1 小时 %2 分 %3 秒")
                       .arg(this->internalS.hour())
                       .arg(this->internalS.minute())
                       .arg(this->internalS.second()));
    });
    int ret = d->exec();
    if( ret == QDialog::Accepted ){
        logMessage("--开始测量--");
        // 建立新的检测数据表
        QString curDir = QDir::currentPath();
        fileName_temExcel = QString("%1/临时的%2检测数据.xlsx").arg(curDir).arg(obj);
        if (QFile::exists(fileName_temExcel)) {
            QFile::remove(fileName_temExcel);
            logMessage(QString("删除已存在的文件: %1").arg(fileName_temExcel));
        }
        QFile::copy("电压电流数据检测模板.xlsx", fileName_temExcel);
        // 修改基本信息
        QXlsx::Document xlsx(fileName_temExcel);
        xlsx.load();
        xlsx.write("A1", QString("%1 检测记录表（附页表）").arg(obj));
        xlsx.saveAs(fileName_temExcel);
        // 开始测量
        startMeasure();
    }
}


void R::on_connectButton_clicked()
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


void R::on_disConnectButton_clicked()
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


void R::on_pushButton_Excel_clicked()
{
    // 让用户选择保存位置
    QString defaultFileName = QString("电压电流检测_2.xlsx");
    fileName_Excel = QFileDialog::getSaveFileName(
        this,
        "新建电压电流检测文档", // title
        QDir::currentPath() + "/" + defaultFileName,
        "Excel文件 (*.xlsx *.xls)"
        );

    if (fileName_Excel.isEmpty()) {
        // 用户取消了
        return;
    }

    // 复制文件
    if (QFile::copy("电压电流检测.xlsx", fileName_Excel)) {
        QMessageBox::information(this, "成功", "已创建新的电压电流检测测试表");
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
    xlsx.selectSheet("电压电流检测");
    xlsx.write("P2",ui->lineEditOrder->text());
    if(ui->radioButtonFirst->isChecked()) {
        xlsx.write("A3","✓初始检测          □中间检测          □最终检测",textFormat);
    } else if(ui->radioButtonMiddle->isChecked()) {
        xlsx.write("A3","□初始检测          ✓中间检测          □最终检测",textFormat);
    } else  {
        xlsx.write("A3","□初始检测          □中间检测          ✓最终检测",textFormat);
    }

    xlsx.write("C5",ui->lineEditName->text());
    xlsx.write("G5",ui->lineEditNumber1->text());
    xlsx.write("I5",ui->lineEditSpecification->text());
    xlsx.write("N5",ui->lineEditBatch->text());
    xlsx.write("C6",ui->lineEditLocation->text());
    xlsx.write("I6",ui->lineEditManufacturer->text());
    xlsx.write("P6",ui->lineEditQualityLevel->text());
    xlsx.write("C8",ui->lineEditTemperature->text());
    xlsx.write("I8",ui->lineEditHumidity->text());
    xlsx.write("P8",ui->lineEditPressure->text(),textFormat);
    xlsx.write("E9",ui->comboBox->currentText());
    xlsx.write("I9",ui->comboBox_2->currentText());
    xlsx.write("P9",ui->dateEditMin->dateTime().toString("yyyy.M.d")+ "-" +
                    ui->dateEditMax->dateTime().toString("yyyy.M.d"));


    // 保存文件
    if (xlsx.saveAs(fileName_Excel)) {
        logMessage(QString("基本信息保存成功"));
        return;
    } else {
        logMessage(QString("基本信息保存失败"));
        return;
    }
}


// void R::on_pushButton_selectExcel_clicked()
// {
//     // 弹出文件选择对话框
//     QString selectedFile = QFileDialog::getOpenFileName(
//         this,                        // 父窗口
//         "选择电压电流检测文件",             // 对话框标题
//         QDir::currentPath(),                 // 默认打开目录
//         "Excel文件 (*.xlsx *.xls);;" // 文件过滤器
//         "所有文件 (*.*)"              // 可选的更多过滤器
//         );

//     if (selectedFile.isEmpty()) {
//         // 取消了选择
//         return;
//     }
//     fileName_Excel = selectedFile;
//     QMessageBox::information(this,"提示","可以开始测试了");
//     logMessage("已经选择了\n" + fileName_Excel + "\n作为测试输出文件");
// }

