#include "brigetestersetting.h"
#include "ui_brigetestersetting.h"

brigetestersetting::brigetestersetting(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::brigetestersetting)
{
    ui->setupUi(this);
    setWindowTitle("电桥测试设置");
}

brigetestersetting::~brigetestersetting()
{
    delete ui;
}

void brigetestersetting::on_pushButton_confirm_clicked()
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
    data.isInitialized = true;
    settingData(data);
    this->accept();
}


void brigetestersetting::on_pushButton_cancel_clicked()
{
    this->reject();
}

