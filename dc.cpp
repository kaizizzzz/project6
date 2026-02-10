#include "dc.h"
#include "ui_dc.h"

#include <hardware/device.h>

#include <QThread>
#include <qmessagebox.h>

DC::DC(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DC)
{
    ui->setupUi(this);
    this->inputDevice = new Device();
    this->loadDevice = new Device();
    this->loadDevice_negative = new Device();
    // 数据填写自动改变电源模块参数
    powerModule = new PM();
    powerModule->inputV_min = ui->lineEdit_minV->text().toDouble();
    powerModule->inputV_standard = ui->lineEdit_standardV->text().toDouble();
    powerModule->inputV_max = ui->lineEdit_maxV->text().toDouble();
    powerModule->load_max = ui->lineEdit_maxLoad->text().toDouble();
    powerModule->load_min = ui->lineEdit_minLoad->text().toDouble();
    powerModule->lineRegulation = ui->lineEdit_lineRegulation->text().toDouble();
    powerModule->loadRegulation = ui->lineEdit_loadRegulation->text().toDouble();
    powerModule->outputV_standard = ui->lineEdit_standardOutputV->text().toDouble();
    powerModule->channel = 1;
    connect(ui->lineEdit_minV, &QLineEdit::textChanged, this,[=](){
        powerModule->inputV_min = ui->lineEdit_minV->text().toDouble();
    });
    connect(ui->lineEdit_standardV, &QLineEdit::textChanged, this,[=](){
        powerModule->inputV_standard = ui->lineEdit_standardV->text().toDouble();
    });
    connect(ui->lineEdit_maxV, &QLineEdit::textChanged, this,[=](){
        powerModule->inputV_max = ui->lineEdit_maxV->text().toDouble();
    });
    connect(ui->lineEdit_maxLoad, &QLineEdit::textChanged, this,[=](){
        powerModule->load_max = ui->lineEdit_maxLoad->text().toDouble();
    });
    connect(ui->lineEdit_minLoad, &QLineEdit::textChanged, this,[=](){
        powerModule->load_min = ui->lineEdit_minLoad->text().toDouble();
    });
    connect(ui->lineEdit_lineRegulation, &QLineEdit::textChanged, this,[=](){
        powerModule->lineRegulation = ui->lineEdit_lineRegulation->text().toDouble();
    });
    connect(ui->lineEdit_loadRegulation, &QLineEdit::textChanged, this,[=](){
        powerModule->loadRegulation = ui->lineEdit_loadRegulation->text().toDouble();
    });
    // 单双路输出
    connect(ui->radioButton_singgleChannel, &QRadioButton::clicked, this,[=](){
        powerModule->channel = 1;
    });
    connect(ui->radioButton_dualChannel, &QRadioButton::clicked, this,[=](){
        powerModule->channel = 2;
    });
    //
}

DC::~DC()
{
    delete ui;
}

void DC::logMessage(QString str)
{
    ui->textEdit->append(str);
}

void DC::updateconnectionStatus(int cnt)
{
    if( cnt == 1 ){
        ui->Label_connection_1->setText("状态:已连接");
        ui->Label_connection_1->setStyleSheet("color: rgb(0, 255, 0)");
        ui->connectButton_1->setEnabled(false);
    }else if( cnt == 2 ){
        ui->Label_connection_2->setText("状态:已连接");
        ui->Label_connection_2->setStyleSheet("color: rgb(0, 255, 0)");
        ui->connectButton_2->setEnabled(false);
    }else if( cnt == 3 ){
        ui->Label_connection_2->setText("状态:已连接");
        ui->Label_connection_2->setStyleSheet("color: rgb(0, 255, 0)");
        ui->connectButton_2->setEnabled(false);
    }
}

void DC::on_connectButton_1_clicked()
{
    this->inputDevice->setPortName(ui->lineEdit_com_1->text());
    if( inputDevice->connect() ){
        qDebug() << "输入设备连接成功";
        updateconnectionStatus(1);
    }
}


void DC::on_pushButton_test1_clicked()
{
    disconnect(test, nullptr, nullptr, nullptr);
    if( powerModule->channel == 2 ){
        //双路输出
        if( !inputDevice->isConnected || !loadDevice->isConnected || !loadDevice_negative->isConnected ){
            QMessageBox::information(this,"提示","输入设备或负载设备未连接");
            return;
        }
        if( !test ){
            test = new TestProject(this, inputDevice, loadDevice, powerModule);
        }
        if( !test_negative ){
            test_negative = new TestProject(this, inputDevice, loadDevice_negative, powerModule);
        }
        connect( test, &TestProject::end_LR, this, [=](){
            // 完成正输出后的处理
            // 计算正输出线性调节率存入powerModule
            powerModule->V_regulation_positive = abs( powerModule->outputV_maxInputV_maxLoad
                                                     -powerModule->outputV_minInputV_maxLoad )
                                                 /powerModule->outputV_standard;
            powerModule->V_regulation_positive *= 100;
            logMessage(QString("最小输出电压，满载，输出电压： %1 V").arg(powerModule->outputV_minInputV_maxLoad));
            logMessage(QString("最大输出电压，满载，输出电压： %1 V").arg(powerModule->outputV_maxInputV_maxLoad));
            logMessage(QString("正输出线性调节率: %1 %").arg(powerModule->V_regulation_positive, 0 , 'f', 6));
            test_negative->startTestSequence_LR(); // 正输出测量完毕后，开始负输出的线性调节率测试
        });
        connect( test_negative, &TestProject::end_LR, this, [=](){
            // 完成负输出后的处理
            // 计算负输出线性调节率存入powerModule
            powerModule->V_regulation_negative = abs( powerModule->outputV_maxInputV_maxLoad
                                                     -powerModule->outputV_minInputV_maxLoad )
                                                 /powerModule->outputV_standard;
            powerModule->V_regulation_negative *= 100;
            logMessage(QString("最小输出电压，满载，输出电压： %1 V").arg(powerModule->outputV_minInputV_maxLoad));
            logMessage(QString("最大输出电压，满载，输出电压： %1 V").arg(powerModule->outputV_maxInputV_maxLoad));
            logMessage(QString("负输出线性调节率: %1 %").arg(powerModule->V_regulation_positive, 0 , 'f', 6));
        });
        test->startTestSequence_LR(); // 开始正输出测试
    }else{
        //单路输出
        if( !inputDevice->isConnected || !loadDevice->isConnected){
            QMessageBox::information(this,"提示","输入设备或负载设备未连接");
            return;
        }
        if( !test ){
            test = new TestProject(this, inputDevice, loadDevice, powerModule);
        }
        connect(test, &TestProject::end_LR, this, [=](){
            // 完成了线性调节率测试
            powerModule->V_regulation_positive = abs( powerModule->outputV_maxInputV_maxLoad
                                                     -powerModule->outputV_minInputV_maxLoad )
                                                 /powerModule->outputV_standard;
            powerModule->V_regulation_positive *= 100.0;
            logMessage(QString("最小输出电压，满载，输出电压： %1 V").arg(powerModule->outputV_minInputV_maxLoad));
            logMessage(QString("最大输出电压，满载，输出电压： %1 V").arg(powerModule->outputV_maxInputV_maxLoad));
            logMessage(QString("线性调节率: %1 %").arg(powerModule->V_regulation_positive, 0 , 'f', 6));
        });
        test->startTestSequence_LR();
    }
    logMessage("==========开始线性调节率测试==========");
}


void DC::on_connectButton_2_clicked()
{
    this->loadDevice->setPortName(ui->lineEdit_com_2->text());
    if( loadDevice->connect() ){
        qDebug() << "负载设备连接成功";
        updateconnectionStatus(2);
    }
}


void DC::on_pushButton_test2_clicked()
{
    disconnect(test, nullptr, nullptr, nullptr);
    if( powerModule->channel == 2 ){
        // 双路输出
        if( !inputDevice->isConnected || !loadDevice->isConnected || !loadDevice_negative->isConnected ){
            QMessageBox::information(this,"提示","输入设备或负载设备未连接");
            return;
        }
        if( !test ){
            test = new TestProject(this, inputDevice, loadDevice, powerModule);
        }
        if( !test_negative ){
            test_negative = new TestProject(this, inputDevice, loadDevice_negative, powerModule);
        }
        connect( test, &TestProject::end_LoadR, this, [=](){
            // 完成正输出测试后的处理
            // 计算正输出负载调节率
            powerModule->A_regulation_positive = abs( powerModule->outputV_staInputV_minload
                                                     -powerModule->outputV_staInputV_maxload )
                                                 /powerModule->outputV_standard;
            powerModule->A_regulation_positive *= 100.0;
            logMessage(QString("额定输入电压，低载，输出电压： %1 V").arg(powerModule->outputV_staInputV_minload));
            logMessage(QString("额定输入电压，满载，输出电压： %1 V").arg(powerModule->outputV_staInputV_maxload));
            logMessage(QString("正输出负载调节率: %1 %").arg(powerModule->A_regulation_positive, 0 , 'f', 6));
            test_negative->startTestSequence_LoadR();
        });
        connect( test_negative, &TestProject::end_LoadR, this, [=](){
            // 完成负输出后的处理
            powerModule->A_regulation_negative = abs( powerModule->outputV_staInputV_minload
                                                     -powerModule->outputV_staInputV_maxload )
                                                 /powerModule->outputV_standard;
            powerModule->A_regulation_negative *= 100;
            logMessage(QString("额定输入电压，低载，输出电压： %1 V").arg(powerModule->outputV_staInputV_minload));
            logMessage(QString("额定输入电压，满载，输出电压： %1 V").arg(powerModule->outputV_staInputV_maxload));
            logMessage(QString("负输出负载调节率: %1 %").arg(powerModule->A_regulation_positive, 0 , 'f', 6));
        });
        test->startTestSequence_LoadR();

    }else{
        if( !inputDevice->isConnected || !loadDevice->isConnected){
            QMessageBox::information(this,"提示","输入设备或负载设备未连接");
            return;
        }
        if( !test ){
            test = new TestProject(this, inputDevice, loadDevice, powerModule);
        }
        connect( test, &TestProject::end_LoadR, this, [=](){
            // 完成了线性调节率测试
            powerModule->A_regulation_positive = abs( powerModule->outputV_staInputV_minload
                                                     -powerModule->outputV_staInputV_maxload )
                                                 /powerModule->outputV_standard;
            powerModule->A_regulation_positive *= 100.0;
            logMessage(QString("额定输入电压，低载，输出电压： %1 V").arg(powerModule->outputV_staInputV_minload));
            logMessage(QString("额定输入电压，满载，输出电压： %1 V").arg(powerModule->outputV_staInputV_maxload));
            logMessage(QString("负载调节率: %1 %").arg(powerModule->A_regulation_positive, 0 , 'f', 6));
        });
        test->startTestSequence_LoadR();
    }
    logMessage("==========开始负载调节率测试==========");
}

void DC::on_pushButton_test4_clicked()
{
    disconnect(test, nullptr, nullptr, nullptr);
    if( !inputDevice->isConnected || !loadDevice->isConnected){
        QMessageBox::information(this,"提示","输入设备或负载设备未连接");
        return;
    }
    logMessage("==========开始效率测试===============");
    powerModule->η = ( powerModule->outputV_staInputV_maxload * powerModule->load_max ) /
                     ( powerModule->input_actV * powerModule->inputA_staInputV_maxload );
    powerModule->η *= 100; //变成百分比形式
    logMessage(QString("效率: %1 %").arg(powerModule->η, 0, 'f', 6));
}


void DC::on_pushButton_test3_clicked()
{
    disconnect(test, nullptr, nullptr, nullptr);
    if( !inputDevice->isConnected || !loadDevice->isConnected){
        QMessageBox::information(this,"提示","输入设备或负载设备未连接");
        return;
    }
    logMessage("==========开始输入电流测试===========");
    if(!test){
        test = new TestProject(this, inputDevice, loadDevice, powerModule);
    }
    connect( test, &TestProject::end_Input_A, this, [=](){
        logMessage(QString("输入电流: %1 A").arg(powerModule->input_A));
    });
    test->startTestSequence_Input_A();
}


void DC::on_connectButton_3_clicked()
{
    this->loadDevice_negative->setPortName(ui->lineEdit_com_3->text());
    if( loadDevice->connect() ){
        qDebug() << "负载设备连接成功";
        updateconnectionStatus(3);
    }
}

