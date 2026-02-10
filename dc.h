#ifndef DC_H
#define DC_H

#include <QTimer>
#include <QWidget>
#include <qserialport.h>
#include <hardware/device.h>
#include <hardware/pm.h>
#include <hardware/testproject.h>

namespace Ui {
class DC;
}

class DC : public QWidget
{
    Q_OBJECT

public:
    explicit DC(QWidget *parent = nullptr);
    ~DC();
    void logMessage(QString str);
    void updateconnectionStatus(int cnt);// 指定一个连接便签变化 1, 2, 3

private slots:
    void on_connectButton_1_clicked();

    void on_pushButton_test1_clicked();

    void on_connectButton_2_clicked();

    void on_pushButton_test2_clicked();

    void on_pushButton_test4_clicked();

    void on_pushButton_test3_clicked();

    void on_connectButton_3_clicked();

private:
    Ui::DC *ui;
    // 设备对象
    Device* inputDevice;
    Device* loadDevice;
    Device* loadDevice_negative;
    // 电源模块对象
    PM* powerModule;
    // 测试项目对象 需要两个，因为正输出负输出作为一个处理了
    TestProject *test = nullptr;
    TestProject *test_negative = nullptr;
};

#endif // DC_H
