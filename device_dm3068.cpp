#include "device_dm3068.h"
#include "ui_device_dm3068.h"

device_dm3068::device_dm3068(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::device_dm3068)
{
    ui->setupUi(this);
    adjustSize();
}

device_dm3068::~device_dm3068()
{
    delete ui;
}

void device_dm3068::on_pushButton_confirm_clicked()
{
    int cnt = ui->comboBox->currentIndex();
    int t=ui->spinBox_count->value();
    QTime iS=ui->internalTimeEdit->time();
    if( cnt == 0 ) detectionObj("直流电压");
    else if( cnt == 1 ) detectionObj("交流电压");
    else if( cnt == 2 ) detectionObj("直流电流");
    else detectionObj("交流电流");
    times(t);
    internalSeconds(iS);
    this->accept();
}


void device_dm3068::on_pushButton_cancel_clicked()
{
    this->reject();
}

