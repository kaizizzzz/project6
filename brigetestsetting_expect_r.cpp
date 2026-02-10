#include "brigetestsetting_expect_r.h"
#include "datastruct.h"
#include "ui_brigetestsetting_expect_r.h"

brigetestsetting_expect_R::brigetestsetting_expect_R(QString mod, QWidget *parent)
    :QDialog(parent)
    , ui(new Ui::brigetestsetting_expect_R)
{
    ui->setupUi(this);
    setWindowTitle("测量参数设置");
    if( mod == "C" ){
        ui->comboBox_function->addItem("Cp-Q");
        ui->comboBox_function->addItem("Cs-Q");
    }
    else if( mod == "L" ){
        // 电感界面
        ui->comboBox_function->addItem("Ls-Q");
        ui->comboBox_function->addItem("Lp-Q");
    }
}

brigetestsetting_expect_R::~brigetestsetting_expect_R()
{
    delete ui;
}

void brigetestsetting_expect_R::on_pushButton_confirm_clicked()
{
    brigetestData data;
    data.function = ui->comboBox_function->currentText().remove('-').toUpper();
    //qDebug() << data.function;
    switch (ui->comboBox_frequency->currentIndex()) {
    case 0: data.frequency = "100"; break;
    case 1: data.frequency = "120"; break;
    case 2: data.frequency = "1000"; break;
    case 3: data.frequency = "10000"; break;
    default:
        break;
    }
    //qDebug() << data.frequency;
    data.voltage = ui->comboBox_voltage->currentText();
    //qDebug() << data.voltage;
    data.outPutResister = ui->comboBox_ouPutResister->currentText().remove("Ω");
    //qDebug() << data.outPutResister;
    data.is_Q = ui->checkBox_Q->isChecked();
    //qDebug() << ui->checkBox_Q->isChecked();
    data.is_Rs = ui->checkBox_Rs->isChecked();
    data.isInitialized = true;
    settingData(data);
    this->accept();
}


void brigetestsetting_expect_R::on_pushButton_cancel_clicked()
{
    this->reject();
}

