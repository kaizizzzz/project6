#ifndef VA_H
#define VA_H

#include <QWidget>
#include "visatype.h"
#include <datastruct.h>
#include <qserialport.h>

namespace Ui {
class va;
}

class va : public QWidget
{
    Q_OBJECT

public:
    explicit va(QWidget *parent = nullptr);
    ~va();
    void updateconnectionStatus(bool connected);
    void initialVisaManager();
    void logMessage(QString str);
    void startMeasure();
    void startMeasure_briget();
    void wValueToFile(double value);
    void calculateRRange();
    bool eventFilter(QObject *obj,QEvent *event) override; // 事件过滤器
    void sendCommand(QString cmd);

private slots:
    void on_connectButton_clicked();

    void on_disConnectButton_clicked();

    void on_pushButton_clicked();

    void on_pushButton_Excel_clicked();

    void on_pushButton_selectExcel_clicked();

    void on_pushButtonSetting_clicked();

    void on_connectButton_briget_clicked();

private:
    Ui::va *ui;
    bool isConnected;
    QString fileName_Excel;
    double minValue;
    double maxValue;
    brigetestData dataSettings;
    // Visa
    ViStatus status;
    ViSession defaultRM;
    ViSession instrument;
    //
    QSerialPort *serial;
};

#endif // VA_H
