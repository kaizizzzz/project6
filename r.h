#ifndef R_H
#define R_H

#include "visatype.h"
#include <QWidget>
#include <qdatetime.h>

namespace Ui {
class R;
}

class R : public QWidget
{
    Q_OBJECT

public:
    explicit R(QWidget *parent = nullptr);
    ~R();
    void startMeasure();
    void updateconnectionStatus(bool connected);
    void initialVisaManager();
    void logMessage(QString str);
    void measureVA();
    void wValueToFile(double value, QString unit);

private slots:
    void on_pushButton_clicked();
    // void getTimes(int t);
    // void getInternalSeconds(int internalS);
    void on_connectButton_clicked();
    void on_disConnectButton_clicked();

    void on_pushButton_Excel_clicked();


private:
    Ui::R *ui;
    bool isConnected;
    QString obj; // 检测对象
    int t; // 测量次数
    int Count; // 已经测量次数
    QTime internalS; // 测量间隔
    QString fileName_Excel;
    QString fileName_temExcel;
    // Visa
    ViStatus status;
    ViSession defaultRM;
    ViSession instrument;
    static const QString cmd[4];
};

#endif // R_H
