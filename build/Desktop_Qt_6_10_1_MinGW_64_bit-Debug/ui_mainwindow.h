/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <c.h>
#include <dc.h>
#include <l.h>
#include <r.h>
#include <va.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_R;
    QAction *action_C;
    QAction *action_L;
    QAction *action_VA;
    QAction *action_DC;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    va *page_R;
    c *page_C;
    L *page_L;
    R *page_VA;
    DC *page;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(539, 475);
        action_R = new QAction(MainWindow);
        action_R->setObjectName("action_R");
        action_R->setMenuRole(QAction::MenuRole::NoRole);
        action_C = new QAction(MainWindow);
        action_C->setObjectName("action_C");
        action_C->setMenuRole(QAction::MenuRole::NoRole);
        action_L = new QAction(MainWindow);
        action_L->setObjectName("action_L");
        action_L->setMenuRole(QAction::MenuRole::NoRole);
        action_VA = new QAction(MainWindow);
        action_VA->setObjectName("action_VA");
        action_VA->setMenuRole(QAction::MenuRole::NoRole);
        action_DC = new QAction(MainWindow);
        action_DC->setObjectName("action_DC");
        action_DC->setMenuRole(QAction::MenuRole::NoRole);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        page_R = new va();
        page_R->setObjectName("page_R");
        stackedWidget->addWidget(page_R);
        page_C = new c();
        page_C->setObjectName("page_C");
        stackedWidget->addWidget(page_C);
        page_L = new L();
        page_L->setObjectName("page_L");
        stackedWidget->addWidget(page_L);
        page_VA = new R();
        page_VA->setObjectName("page_VA");
        stackedWidget->addWidget(page_VA);
        page = new DC();
        page->setObjectName("page");
        stackedWidget->addWidget(page);

        verticalLayout->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

        toolBar->addAction(action_R);
        toolBar->addAction(action_C);
        toolBar->addAction(action_L);
        toolBar->addAction(action_VA);
        toolBar->addAction(action_DC);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\346\265\213\350\257\225", nullptr));
        action_R->setText(QCoreApplication::translate("MainWindow", "\347\224\265\351\230\273", nullptr));
        action_C->setText(QCoreApplication::translate("MainWindow", "\347\224\265\345\256\271", nullptr));
        action_L->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\204\237", nullptr));
        action_VA->setText(QCoreApplication::translate("MainWindow", "\347\224\265\345\216\213\347\224\265\346\265\201", nullptr));
        action_DC->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\272\220\346\250\241\345\235\227\346\243\200\346\265\213", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
