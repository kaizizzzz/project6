/********************************************************************************
** Form generated from reading UI file 'brigetestersetting.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BRIGETESTERSETTING_H
#define UI_BRIGETESTERSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_brigetestersetting
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label;
    QComboBox *comboBox_ouPutResister;
    QLabel *label_4;
    QComboBox *comboBox_function;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_7;
    QComboBox *comboBox_frequency;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QComboBox *comboBox_voltage;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_confirm;
    QPushButton *pushButton_cancel;

    void setupUi(QDialog *brigetestersetting)
    {
        if (brigetestersetting->objectName().isEmpty())
            brigetestersetting->setObjectName("brigetestersetting");
        brigetestersetting->resize(392, 342);
        gridLayout = new QGridLayout(brigetestersetting);
        gridLayout->setObjectName("gridLayout");
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 1, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 3, 3, 1, 1);

        label = new QLabel(brigetestersetting);
        label->setObjectName("label");

        gridLayout->addWidget(label, 1, 1, 1, 1);

        comboBox_ouPutResister = new QComboBox(brigetestersetting);
        comboBox_ouPutResister->addItem(QString());
        comboBox_ouPutResister->addItem(QString());
        comboBox_ouPutResister->setObjectName("comboBox_ouPutResister");

        gridLayout->addWidget(comboBox_ouPutResister, 3, 2, 1, 1);

        label_4 = new QLabel(brigetestersetting);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 0, 1, 1, 1);

        comboBox_function = new QComboBox(brigetestersetting);
        comboBox_function->addItem(QString());
        comboBox_function->addItem(QString());
        comboBox_function->addItem(QString());
        comboBox_function->setObjectName("comboBox_function");

        gridLayout->addWidget(comboBox_function, 0, 2, 1, 1);

        label_3 = new QLabel(brigetestersetting);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 3, 1, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 2, 0, 1, 1);

        comboBox_frequency = new QComboBox(brigetestersetting);
        comboBox_frequency->addItem(QString());
        comboBox_frequency->addItem(QString());
        comboBox_frequency->addItem(QString());
        comboBox_frequency->addItem(QString());
        comboBox_frequency->setObjectName("comboBox_frequency");

        gridLayout->addWidget(comboBox_frequency, 1, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 3, 1, 1);

        label_2 = new QLabel(brigetestersetting);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 2, 1, 1, 1);

        comboBox_voltage = new QComboBox(brigetestersetting);
        comboBox_voltage->addItem(QString());
        comboBox_voltage->addItem(QString());
        comboBox_voltage->addItem(QString());
        comboBox_voltage->addItem(QString());
        comboBox_voltage->addItem(QString());
        comboBox_voltage->addItem(QString());
        comboBox_voltage->addItem(QString());
        comboBox_voltage->setObjectName("comboBox_voltage");

        gridLayout->addWidget(comboBox_voltage, 2, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 2, 3, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_8, 3, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 0, 0, 1, 1);

        pushButton_confirm = new QPushButton(brigetestersetting);
        pushButton_confirm->setObjectName("pushButton_confirm");

        gridLayout->addWidget(pushButton_confirm, 4, 1, 1, 1);

        pushButton_cancel = new QPushButton(brigetestersetting);
        pushButton_cancel->setObjectName("pushButton_cancel");

        gridLayout->addWidget(pushButton_cancel, 4, 2, 1, 1);


        retranslateUi(brigetestersetting);

        QMetaObject::connectSlotsByName(brigetestersetting);
    } // setupUi

    void retranslateUi(QDialog *brigetestersetting)
    {
        brigetestersetting->setWindowTitle(QCoreApplication::translate("brigetestersetting", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("brigetestersetting", "\346\265\213\351\207\217\351\242\221\347\216\207:", nullptr));
        comboBox_ouPutResister->setItemText(0, QCoreApplication::translate("brigetestersetting", "10\316\251", nullptr));
        comboBox_ouPutResister->setItemText(1, QCoreApplication::translate("brigetestersetting", "100\316\251", nullptr));

        label_4->setText(QCoreApplication::translate("brigetestersetting", "\345\212\237\350\203\275\346\250\241\345\274\217:", nullptr));
        comboBox_function->setItemText(0, QCoreApplication::translate("brigetestersetting", "R-X", nullptr));
        comboBox_function->setItemText(1, QCoreApplication::translate("brigetestersetting", "Rp-Q", nullptr));
        comboBox_function->setItemText(2, QCoreApplication::translate("brigetestersetting", "Rs-Q", nullptr));

        comboBox_function->setCurrentText(QCoreApplication::translate("brigetestersetting", "R-X", nullptr));
        label_3->setText(QCoreApplication::translate("brigetestersetting", "\350\276\223\345\207\272\345\206\205\351\230\273:", nullptr));
        comboBox_frequency->setItemText(0, QCoreApplication::translate("brigetestersetting", "100Hz", nullptr));
        comboBox_frequency->setItemText(1, QCoreApplication::translate("brigetestersetting", "120Hz", nullptr));
        comboBox_frequency->setItemText(2, QCoreApplication::translate("brigetestersetting", "1kHz", nullptr));
        comboBox_frequency->setItemText(3, QCoreApplication::translate("brigetestersetting", "10kHz", nullptr));

        label_2->setText(QCoreApplication::translate("brigetestersetting", "\346\265\213\351\207\217\347\224\265\345\271\263:", nullptr));
        comboBox_voltage->setItemText(0, QCoreApplication::translate("brigetestersetting", "1V", nullptr));
        comboBox_voltage->setItemText(1, QCoreApplication::translate("brigetestersetting", "500mV", nullptr));
        comboBox_voltage->setItemText(2, QCoreApplication::translate("brigetestersetting", "250mV", nullptr));
        comboBox_voltage->setItemText(3, QCoreApplication::translate("brigetestersetting", "100mV", nullptr));
        comboBox_voltage->setItemText(4, QCoreApplication::translate("brigetestersetting", "50mV", nullptr));
        comboBox_voltage->setItemText(5, QCoreApplication::translate("brigetestersetting", "20mV", nullptr));
        comboBox_voltage->setItemText(6, QCoreApplication::translate("brigetestersetting", "10mV", nullptr));

        pushButton_confirm->setText(QCoreApplication::translate("brigetestersetting", "\347\241\256\350\256\244", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("brigetestersetting", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class brigetestersetting: public Ui_brigetestersetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BRIGETESTERSETTING_H
