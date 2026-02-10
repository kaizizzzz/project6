#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_action_R_triggered();

    void on_action_C_triggered();

    void on_action_L_triggered();

    void on_action_VA_triggered();

    void on_action_DC_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
