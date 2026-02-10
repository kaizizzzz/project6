#ifndef L_H
#define L_H

#include "datastruct.h"

#include <QSerialPort>
#include <QWidget>

namespace Ui {
class L;
}

class L : public QWidget
{
    Q_OBJECT

public:
    explicit L(QWidget *parent = nullptr);
    ~L();
    void updateconnectionStatus(bool connected);
    void calculateLRange();
    void logMessage(QString str);
    void sendCommand(QString cmd);
    void startMeasure_briget();
    void wValueToFile(double Value_L, double Q, double Rs);
    bool eventFilter(QObject *obj,QEvent *event) override; // 事件过滤器

private slots:
    void on_pushButton_clicked();

    void on_pushButton_Excel_clicked();

    void on_pushButton_selectExcel_clicked();

    void on_connectButton_briget_clicked();

    void on_pushButtonSetting_clicked();

private:
    Ui::L *ui;
    bool isConnected;
    double minValue;
    double maxValue;
    QString fileName_Excel;
    brigetestData dataSettings;
    //
    QSerialPort *serial;
};

#endif // L_H
