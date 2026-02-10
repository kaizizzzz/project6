                                                                  #include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    adjustSize();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_action_R_triggered()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_action_C_triggered()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_action_L_triggered()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_action_VA_triggered()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_action_DC_triggered()
{
    ui->stackedWidget->setCurrentIndex(4);
}

