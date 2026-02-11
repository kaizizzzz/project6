/********************************************************************************
** Form generated from reading UI file 'r.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_R_H
#define UI_R_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_R
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *labelLocation;
    QLineEdit *lineEditLocation;
    QLabel *label;
    QLineEdit *lineEditOrder;
    QLabel *label_2;
    QLineEdit *lineEditName;
    QLabel *label_3;
    QLineEdit *lineEditNumber1;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButtonFirst;
    QRadioButton *radioButtonMiddle;
    QRadioButton *radioButtonFinally;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QComboBox *comboBox;
    QLabel *label_7;
    QLabel *label_4;
    QLineEdit *lineEditManufacturer;
    QComboBox *comboBox_2;
    QLineEdit *lineEditBatch;
    QLabel *label_8;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_3;
    QDateEdit *dateEditMin;
    QLabel *label_16;
    QDateEdit *dateEditMax;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_11;
    QLineEdit *lineEditQualityLevel;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_5;
    QLineEdit *lineEditSpecification;
    QLabel *label_5_2;
    QLineEdit *lineEditNumber2;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QLabel *label_10;
    QLabel *label_6;
    QLineEdit *lineEditPressure;
    QLineEdit *lineEditTemperature;
    QLabel *label_9;
    QLineEdit *lineEditHumidity;
    QGroupBox *groupBox_6;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_15;
    QLineEdit *ipEdit;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *connectButton;
    QPushButton *disConnectButton;
    QLabel *connectionLabel;
    QLabel *label_17;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_14;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_Excel;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_4;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *logMessageEdit;

    void setupUi(QWidget *R)
    {
        if (R->objectName().isEmpty())
            R->setObjectName("R");
        R->resize(883, 722);
        verticalLayout = new QVBoxLayout(R);
        verticalLayout->setObjectName("verticalLayout");
        groupBox = new QGroupBox(R);
        groupBox->setObjectName("groupBox");
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        labelLocation = new QLabel(groupBox);
        labelLocation->setObjectName("labelLocation");

        gridLayout->addWidget(labelLocation, 0, 0, 1, 1);

        lineEditLocation = new QLineEdit(groupBox);
        lineEditLocation->setObjectName("lineEditLocation");

        gridLayout->addWidget(lineEditLocation, 0, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName("label");

        gridLayout->addWidget(label, 1, 0, 1, 1);

        lineEditOrder = new QLineEdit(groupBox);
        lineEditOrder->setObjectName("lineEditOrder");

        gridLayout->addWidget(lineEditOrder, 1, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 2, 1, 1);

        lineEditName = new QLineEdit(groupBox);
        lineEditName->setObjectName("lineEditName");

        gridLayout->addWidget(lineEditName, 1, 3, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 1, 4, 1, 1);

        lineEditNumber1 = new QLineEdit(groupBox);
        lineEditNumber1->setObjectName("lineEditNumber1");

        gridLayout->addWidget(lineEditNumber1, 1, 5, 1, 1);

        widget = new QWidget(groupBox);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        radioButtonFirst = new QRadioButton(widget);
        radioButtonFirst->setObjectName("radioButtonFirst");
        radioButtonFirst->setChecked(true);

        horizontalLayout->addWidget(radioButtonFirst);

        radioButtonMiddle = new QRadioButton(widget);
        radioButtonMiddle->setObjectName("radioButtonMiddle");

        horizontalLayout->addWidget(radioButtonMiddle);

        radioButtonFinally = new QRadioButton(widget);
        radioButtonFinally->setObjectName("radioButtonFinally");

        horizontalLayout->addWidget(radioButtonFinally);


        gridLayout->addWidget(widget, 0, 2, 1, 4);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(R);
        groupBox_2->setObjectName("groupBox_2");
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName("gridLayout_2");
        comboBox = new QComboBox(groupBox_2);
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");

        gridLayout_2->addWidget(comboBox, 1, 1, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName("label_7");

        gridLayout_2->addWidget(label_7, 0, 0, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName("label_4");

        gridLayout_2->addWidget(label_4, 0, 2, 1, 1);

        lineEditManufacturer = new QLineEdit(groupBox_2);
        lineEditManufacturer->setObjectName("lineEditManufacturer");

        gridLayout_2->addWidget(lineEditManufacturer, 0, 1, 1, 1);

        comboBox_2 = new QComboBox(groupBox_2);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");

        gridLayout_2->addWidget(comboBox_2, 1, 3, 1, 1);

        lineEditBatch = new QLineEdit(groupBox_2);
        lineEditBatch->setObjectName("lineEditBatch");

        gridLayout_2->addWidget(lineEditBatch, 0, 3, 1, 1);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName("label_8");

        gridLayout_2->addWidget(label_8, 0, 4, 1, 1);

        widget_2 = new QWidget(groupBox_2);
        widget_2->setObjectName("widget_2");
        horizontalLayout_3 = new QHBoxLayout(widget_2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        dateEditMin = new QDateEdit(widget_2);
        dateEditMin->setObjectName("dateEditMin");
        dateEditMin->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        dateEditMin->setDate(QDate(2025, 1, 1));

        horizontalLayout_3->addWidget(dateEditMin);

        label_16 = new QLabel(widget_2);
        label_16->setObjectName("label_16");

        horizontalLayout_3->addWidget(label_16);

        dateEditMax = new QDateEdit(widget_2);
        dateEditMax->setObjectName("dateEditMax");
        dateEditMax->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        dateEditMax->setDate(QDate(2026, 1, 1));

        horizontalLayout_3->addWidget(dateEditMax);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        gridLayout_2->addWidget(widget_2, 1, 5, 1, 1);

        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName("label_11");

        gridLayout_2->addWidget(label_11, 1, 0, 1, 1);

        lineEditQualityLevel = new QLineEdit(groupBox_2);
        lineEditQualityLevel->setObjectName("lineEditQualityLevel");

        gridLayout_2->addWidget(lineEditQualityLevel, 0, 5, 1, 1);

        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName("label_12");

        gridLayout_2->addWidget(label_12, 1, 2, 1, 1);

        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName("label_13");

        gridLayout_2->addWidget(label_13, 1, 4, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName("label_5");

        gridLayout_2->addWidget(label_5, 2, 0, 1, 1);

        lineEditSpecification = new QLineEdit(groupBox_2);
        lineEditSpecification->setObjectName("lineEditSpecification");

        gridLayout_2->addWidget(lineEditSpecification, 2, 1, 1, 1);

        label_5_2 = new QLabel(groupBox_2);
        label_5_2->setObjectName("label_5_2");

        gridLayout_2->addWidget(label_5_2, 2, 2, 1, 1);

        lineEditNumber2 = new QLineEdit(groupBox_2);
        lineEditNumber2->setObjectName("lineEditNumber2");

        gridLayout_2->addWidget(lineEditNumber2, 2, 3, 1, 1);


        verticalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(R);
        groupBox_3->setObjectName("groupBox_3");
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName("gridLayout_3");
        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName("label_10");

        gridLayout_3->addWidget(label_10, 0, 4, 1, 1);

        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName("label_6");

        gridLayout_3->addWidget(label_6, 0, 2, 1, 1);

        lineEditPressure = new QLineEdit(groupBox_3);
        lineEditPressure->setObjectName("lineEditPressure");

        gridLayout_3->addWidget(lineEditPressure, 0, 5, 1, 1);

        lineEditTemperature = new QLineEdit(groupBox_3);
        lineEditTemperature->setObjectName("lineEditTemperature");

        gridLayout_3->addWidget(lineEditTemperature, 0, 1, 1, 1);

        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName("label_9");

        gridLayout_3->addWidget(label_9, 0, 0, 1, 1);

        lineEditHumidity = new QLineEdit(groupBox_3);
        lineEditHumidity->setObjectName("lineEditHumidity");

        gridLayout_3->addWidget(lineEditHumidity, 0, 3, 1, 1);


        verticalLayout->addWidget(groupBox_3);

        groupBox_6 = new QGroupBox(R);
        groupBox_6->setObjectName("groupBox_6");
        horizontalLayout_4 = new QHBoxLayout(groupBox_6);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_15 = new QLabel(groupBox_6);
        label_15->setObjectName("label_15");

        horizontalLayout_4->addWidget(label_15);

        ipEdit = new QLineEdit(groupBox_6);
        ipEdit->setObjectName("ipEdit");

        horizontalLayout_4->addWidget(ipEdit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        connectButton = new QPushButton(groupBox_6);
        connectButton->setObjectName("connectButton");

        horizontalLayout_4->addWidget(connectButton);

        disConnectButton = new QPushButton(groupBox_6);
        disConnectButton->setObjectName("disConnectButton");

        horizontalLayout_4->addWidget(disConnectButton);

        connectionLabel = new QLabel(groupBox_6);
        connectionLabel->setObjectName("connectionLabel");
        connectionLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        connectionLabel->setTextFormat(Qt::TextFormat::AutoText);

        horizontalLayout_4->addWidget(connectionLabel);

        label_17 = new QLabel(groupBox_6);
        label_17->setObjectName("label_17");

        horizontalLayout_4->addWidget(label_17);


        verticalLayout->addWidget(groupBox_6);

        groupBox_4 = new QGroupBox(R);
        groupBox_4->setObjectName("groupBox_4");
        horizontalLayout_2 = new QHBoxLayout(groupBox_4);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_14 = new QLabel(groupBox_4);
        label_14->setObjectName("label_14");

        horizontalLayout_2->addWidget(label_14);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addWidget(groupBox_4);

        widget_3 = new QWidget(R);
        widget_3->setObjectName("widget_3");
        horizontalLayout_5 = new QHBoxLayout(widget_3);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        pushButton_Excel = new QPushButton(widget_3);
        pushButton_Excel->setObjectName("pushButton_Excel");

        horizontalLayout_5->addWidget(pushButton_Excel);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        pushButton = new QPushButton(widget_3);
        pushButton->setObjectName("pushButton");

        horizontalLayout_5->addWidget(pushButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);


        verticalLayout->addWidget(widget_3);

        groupBox_5 = new QGroupBox(R);
        groupBox_5->setObjectName("groupBox_5");
        verticalLayout_2 = new QVBoxLayout(groupBox_5);
        verticalLayout_2->setObjectName("verticalLayout_2");
        logMessageEdit = new QTextEdit(groupBox_5);
        logMessageEdit->setObjectName("logMessageEdit");

        verticalLayout_2->addWidget(logMessageEdit);


        verticalLayout->addWidget(groupBox_5);


        retranslateUi(R);

        QMetaObject::connectSlotsByName(R);
    } // setupUi

    void retranslateUi(QWidget *R)
    {
        R->setWindowTitle(QCoreApplication::translate("R", "\346\243\200\346\265\213\344\277\241\346\201\257\345\275\225\345\205\245", nullptr));
        groupBox->setTitle(QCoreApplication::translate("R", "\345\237\272\347\241\200\344\277\241\346\201\257", nullptr));
        labelLocation->setText(QCoreApplication::translate("R", "\346\243\200\346\265\213\345\234\260\347\202\271:", nullptr));
        lineEditLocation->setText(QCoreApplication::translate("R", "\347\224\265\346\200\247\350\203\275\344\272\214\345\256\244", nullptr));
        label->setText(QCoreApplication::translate("R", "\346\243\200\346\265\213\345\215\225\345\217\267:", nullptr));
        lineEditOrder->setText(QCoreApplication::translate("R", "\346\243\200\346\265\213\345\215\225\345\217\267", nullptr));
        label_2->setText(QCoreApplication::translate("R", "\346\240\267\344\273\266\345\220\215\347\247\260:", nullptr));
        lineEditName->setText(QCoreApplication::translate("R", "\346\240\267\344\273\266\345\220\215\347\247\260", nullptr));
        label_3->setText(QCoreApplication::translate("R", "\351\200\201\346\240\267\346\225\260\351\207\217:", nullptr));
        lineEditNumber1->setText(QCoreApplication::translate("R", "\351\200\201\346\240\267\346\225\260\351\207\217", nullptr));
        radioButtonFirst->setText(QCoreApplication::translate("R", "\345\210\235\346\254\241\346\243\200\346\265\213", nullptr));
        radioButtonMiddle->setText(QCoreApplication::translate("R", "\344\270\255\351\227\264\346\243\200\346\265\213", nullptr));
        radioButtonFinally->setText(QCoreApplication::translate("R", "\346\234\200\347\273\210\346\243\200\346\265\213", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("R", "\346\240\267\345\223\201\344\277\241\346\201\257", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("R", "\346\225\260\345\255\227\344\270\207\347\224\250\350\241\250", nullptr));

        label_7->setText(QCoreApplication::translate("R", "\347\224\237\344\272\247\345\216\202\345\256\266:", nullptr));
        label_4->setText(QCoreApplication::translate("R", "\347\224\237\344\272\247\346\211\271\346\254\241:", nullptr));
        lineEditManufacturer->setText(QCoreApplication::translate("R", "\347\224\237\344\272\247\345\216\202\345\256\266", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("R", "DM3068", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("R", "34461A", nullptr));

        lineEditBatch->setText(QCoreApplication::translate("R", "\347\224\237\344\272\247\346\211\271\346\254\241", nullptr));
        label_8->setText(QCoreApplication::translate("R", "\350\264\250\351\207\217\347\255\211\347\272\247:", nullptr));
        dateEditMin->setDisplayFormat(QCoreApplication::translate("R", "yyyy.M.d", nullptr));
        label_16->setText(QCoreApplication::translate("R", "~", nullptr));
        dateEditMax->setDisplayFormat(QCoreApplication::translate("R", "yyyy.M.d", nullptr));
        label_11->setText(QCoreApplication::translate("R", "\350\256\276\345\244\207\351\200\211\346\213\251:", nullptr));
        lineEditQualityLevel->setText(QCoreApplication::translate("R", "\345\267\245\344\270\232\347\272\247", nullptr));
        label_12->setText(QCoreApplication::translate("R", "\345\236\213\345\217\267:", nullptr));
        label_13->setText(QCoreApplication::translate("R", "\346\234\211\346\225\210\346\234\237:", nullptr));
        label_5->setText(QCoreApplication::translate("R", "\350\247\204\346\240\274\345\236\213\345\217\267:", nullptr));
        lineEditSpecification->setText(QCoreApplication::translate("R", "\350\247\204\346\240\274\345\236\213\345\217\267", nullptr));
        label_5_2->setText(QCoreApplication::translate("R", "\346\243\200\346\265\213\346\225\260\351\207\217:", nullptr));
        lineEditNumber2->setText(QCoreApplication::translate("R", "\346\243\200\346\265\213\346\225\260\351\207\217", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("R", "\347\216\257\345\242\203\346\235\241\344\273\266", nullptr));
        label_10->setText(QCoreApplication::translate("R", "\345\244\247\346\260\224\345\216\213\345\212\233:", nullptr));
        label_6->setText(QCoreApplication::translate("R", "\347\216\257\345\242\203\346\271\277\345\272\246:", nullptr));
        lineEditPressure->setText(QCoreApplication::translate("R", "\345\244\247\346\260\224\345\216\213\345\212\233", nullptr));
        lineEditTemperature->setText(QCoreApplication::translate("R", "\347\216\257\345\242\203\346\270\251\345\272\246", nullptr));
        label_9->setText(QCoreApplication::translate("R", "\347\216\257\345\242\203\346\270\251\345\272\246:", nullptr));
        lineEditHumidity->setText(QCoreApplication::translate("R", "\347\216\257\345\242\203\346\271\277\345\272\246", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("R", "\350\277\236\346\216\245\350\256\276\347\275\256", nullptr));
        label_15->setText(QCoreApplication::translate("R", "\350\256\276\345\244\207IP\345\234\260\345\235\200:", nullptr));
        ipEdit->setText(QCoreApplication::translate("R", "172.22.127.227", nullptr));
        connectButton->setText(QCoreApplication::translate("R", "\345\274\200\345\247\213\350\277\236\346\216\245", nullptr));
        disConnectButton->setText(QCoreApplication::translate("R", "\346\226\255\345\274\200\350\277\236\346\216\245", nullptr));
        connectionLabel->setText(QCoreApplication::translate("R", "\347\212\266\346\200\201:\346\234\252\350\277\236\346\216\245", nullptr));
        label_17->setText(QString());
        groupBox_4->setTitle(QCoreApplication::translate("R", "\346\255\245\345\210\227", nullptr));
        label_14->setText(QCoreApplication::translate("R", "\346\214\211\346\227\266\351\227\264\350\246\201\346\261\202\351\207\207\346\240\267", nullptr));
        pushButton_Excel->setText(QCoreApplication::translate("R", "\345\273\272\347\253\213\346\226\260\347\232\204\346\243\200\346\265\213\346\225\260\346\215\256\350\241\250", nullptr));
        pushButton->setText(QCoreApplication::translate("R", "\345\274\200\345\247\213\346\265\213\350\257\225", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("R", "\346\227\245\345\277\227\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class R: public Ui_R {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_R_H
