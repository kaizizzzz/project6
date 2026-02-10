#ifndef C_H
#define C_H

#include "datastruct.h"

#include <QWidget>
#include <qserialport.h>

namespace Ui {
class c;
}

class c : public QWidget
{
    Q_OBJECT

public:
    explicit c(QWidget *parent = nullptr);
    ~c();
    void updateconnectionStatus(bool connected);
    void calculateCRange();
    void logMessage(QString str);
    void sendCommand(QString cmd);
    void startMeasure_briget();
    void wValueToFile(double Value_C, double Q, double Rs);
    bool eventFilter(QObject *obj,QEvent *event) override; // 事件过滤器

private slots:
    void on_pushButton_Excel_clicked();

    void on_pushButton_selectExcel_clicked();

    void on_connectButton_briget_clicked();

    void on_pushButtonSetting_clicked();

    void on_pushButton_clicked();

private:
    Ui::c *ui;
    bool isConnected;
    double minValue;
    double maxValue;
    QString fileName_Excel;
    brigetestData dataSettings;
    //
    QSerialPort *serial;
};

#endif // C_H
