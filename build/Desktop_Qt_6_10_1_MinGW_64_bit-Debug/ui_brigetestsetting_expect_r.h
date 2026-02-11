/********************************************************************************
** Form generated from reading UI file 'brigetestsetting_expect_r.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BRIGETESTSETTING_EXPECT_R_H
#define UI_BRIGETESTSETTING_EXPECT_R_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_brigetestsetting_expect_R
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QComboBox *comboBox_voltage;
    QLabel *label_4;
    QComboBox *comboBox_frequency;
    QLabel *label_3;
    QLabel *label_5;
    QComboBox *comboBox_function;
    QComboBox *comboBox_ouPutResister;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QCheckBox *checkBox_Q;
    QCheckBox *checkBox_Rs;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *pushButton_confirm;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *pushButton_cancel;
    QSpacerItem *horizontalSpacer_10;

    void setupUi(QWidget *brigetestsetting_expect_R)
    {
        if (brigetestsetting_expect_R->objectName().isEmpty())
            brigetestsetting_expect_R->setObjectName("brigetestsetting_expect_R");
        brigetestsetting_expect_R->resize(353, 283);
        verticalLayout = new QVBoxLayout(brigetestsetting_expect_R);
        verticalLayout->setObjectName("verticalLayout");
        widget = new QWidget(brigetestsetting_expect_R);
        widget->setObjectName("widget");
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        comboBox_voltage = new QComboBox(widget);
        comboBox_voltage->addItem(QString());
        comboBox_voltage->addItem(QString());
        comboBox_voltage->addItem(QString());
        comboBox_voltage->addItem(QString());
        comboBox_voltage->addItem(QString());
        comboBox_voltage->addItem(QString());
        comboBox_voltage->addItem(QString());
        comboBox_voltage->setObjectName("comboBox_voltage");

        gridLayout->addWidget(comboBox_voltage, 2, 1, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        comboBox_frequency = new QComboBox(widget);
        comboBox_frequency->addItem(QString());
        comboBox_frequency->addItem(QString());
        comboBox_frequency->addItem(QString());
        comboBox_frequency->addItem(QString());
        comboBox_frequency->setObjectName("comboBox_frequency");

        gridLayout->addWidget(comboBox_frequency, 1, 1, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        comboBox_function = new QComboBox(widget);
        comboBox_function->setObjectName("comboBox_function");

        gridLayout->addWidget(comboBox_function, 0, 1, 1, 1);

        comboBox_ouPutResister = new QComboBox(widget);
        comboBox_ouPutResister->addItem(QString());
        comboBox_ouPutResister->addItem(QString());
        comboBox_ouPutResister->setObjectName("comboBox_ouPutResister");

        gridLayout->addWidget(comboBox_ouPutResister, 3, 1, 1, 1);


        verticalLayout->addWidget(widget);

        widget_3 = new QWidget(brigetestsetting_expect_R);
        widget_3->setObjectName("widget_3");
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        checkBox_Q = new QCheckBox(widget_3);
        checkBox_Q->setObjectName("checkBox_Q");

        horizontalLayout_2->addWidget(checkBox_Q);

        checkBox_Rs = new QCheckBox(widget_3);
        checkBox_Rs->setObjectName("checkBox_Rs");

        horizontalLayout_2->addWidget(checkBox_Rs);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget_3);

        widget_2 = new QWidget(brigetestsetting_expect_R);
        widget_2->setObjectName("widget_2");
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_9);

        pushButton_confirm = new QPushButton(widget_2);
        pushButton_confirm->setObjectName("pushButton_confirm");

        horizontalLayout->addWidget(pushButton_confirm);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_11);

        pushButton_cancel = new QPushButton(widget_2);
        pushButton_cancel->setObjectName("pushButton_cancel");

        horizontalLayout->addWidget(pushButton_cancel);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_10);


        verticalLayout->addWidget(widget_2);


        retranslateUi(brigetestsetting_expect_R);

        QMetaObject::connectSlotsByName(brigetestsetting_expect_R);
    } // setupUi

    void retranslateUi(QWidget *brigetestsetting_expect_R)
    {
        brigetestsetting_expect_R->setWindowTitle(QCoreApplication::translate("brigetestsetting_expect_R", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("brigetestsetting_expect_R", "\346\265\213\351\207\217\347\224\265\345\271\263:", nullptr));
        comboBox_voltage->setItemText(0, QCoreApplication::translate("brigetestsetting_expect_R", "1V", nullptr));
        comboBox_voltage->setItemText(1, QCoreApplication::translate("brigetestsetting_expect_R", "500mV", nullptr));
        comboBox_voltage->setItemText(2, QCoreApplication::translate("brigetestsetting_expect_R", "250mV", nullptr));
        comboBox_voltage->setItemText(3, QCoreApplication::translate("brigetestsetting_expect_R", "100mV", nullptr));
        comboBox_voltage->setItemText(4, QCoreApplication::translate("brigetestsetting_expect_R", "50mV", nullptr));
        comboBox_voltage->setItemText(5, QCoreApplication::translate("brigetestsetting_expect_R", "20mV", nullptr));
        comboBox_voltage->setItemText(6, QCoreApplication::translate("brigetestsetting_expect_R", "10mV", nullptr));

        label_4->setText(QCoreApplication::translate("brigetestsetting_expect_R", "\346\265\213\351\207\217\351\242\221\347\216\207:", nullptr));
        comboBox_frequency->setItemText(0, QCoreApplication::translate("brigetestsetting_expect_R", "100Hz", nullptr));
        comboBox_frequency->setItemText(1, QCoreApplication::translate("brigetestsetting_expect_R", "120Hz", nullptr));
        comboBox_frequency->setItemText(2, QCoreApplication::translate("brigetestsetting_expect_R", "1kHz", nullptr));
        comboBox_frequency->setItemText(3, QCoreApplication::translate("brigetestsetting_expect_R", "10kHz", nullptr));

        label_3->setText(QCoreApplication::translate("brigetestsetting_expect_R", "\350\276\223\345\207\272\345\206\205\351\230\273:", nullptr));
        label_5->setText(QCoreApplication::translate("brigetestsetting_expect_R", "\345\212\237\350\203\275\346\250\241\345\274\217:", nullptr));
        comboBox_function->setCurrentText(QString());
        comboBox_ouPutResister->setItemText(0, QCoreApplication::translate("brigetestsetting_expect_R", "10\316\251", nullptr));
        comboBox_ouPutResister->setItemText(1, QCoreApplication::translate("brigetestsetting_expect_R", "100\316\251", nullptr));

        checkBox_Q->setText(QCoreApplication::translate("brigetestsetting_expect_R", "\346\265\213\351\207\217Q\345\200\274", nullptr));
        checkBox_Rs->setText(QCoreApplication::translate("brigetestsetting_expect_R", "\346\265\213\351\207\217Rs\345\200\274", nullptr));
        pushButton_confirm->setText(QCoreApplication::translate("brigetestsetting_expect_R", "\347\241\256\350\256\244", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("brigetestsetting_expect_R", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class brigetestsetting_expect_R: public Ui_brigetestsetting_expect_R {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BRIGETESTSETTING_EXPECT_R_H
