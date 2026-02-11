/********************************************************************************
** Form generated from reading UI file 'va.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VA_H
#define UI_VA_H

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

class Ui_va
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_6;
    QLineEdit *lineEditLocation;
    QLabel *label;
    QLineEdit *lineEditOrder;
    QLabel *label_2;
    QLineEdit *lineEditName;
    QLabel *label_3;
    QLineEdit *lineEditNumber1;
    QWidget *widget_step;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButtonFirst;
    QRadioButton *radioButtonMiddle;
    QRadioButton *radioButtonFinally;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLabel *label_13;
    QLineEdit *lineEditManufacturer;
    QLabel *label_4;
    QLineEdit *lineEditQualityLevel;
    QComboBox *comboBox;
    QLabel *label_5_2;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_12;
    QLabel *label_11;
    QLineEdit *lineEditBatch;
    QLineEdit *lineEditNumber2;
    QLabel *label_spec;
    QComboBox *comboBox_2;
    QLineEdit *lineEditSpecification;
    QLabel *label_14;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_3;
    QDateEdit *dateEditMin;
    QLabel *label_16;
    QDateEdit *dateEditMax;
    QSpacerItem *horizontalSpacer_5;
    QComboBox *comboBox_3;
    QLabel *label_18;
    QComboBox *comboBox_4;
    QLabel *label_19;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_5;
    QDateEdit *dateEditMin_2;
    QLabel *label_20;
    QDateEdit *dateEditMax_2;
    QSpacerItem *horizontalSpacer_6;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QLabel *label_5;
    QLineEdit *lineEditTemperature;
    QLineEdit *lineEditPressure;
    QLabel *label_10;
    QLabel *label_9;
    QLineEdit *lineEditHumidity;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_5;
    QPushButton *disConnectButton;
    QLabel *label_15;
    QPushButton *connectButton;
    QSpacerItem *horizontalSpacer_2;
    QLabel *connectionLabel;
    QLabel *label_17;
    QLineEdit *ipEdit;
    QLabel *label_21;
    QLineEdit *portEdit;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *connectButton_briget;
    QLabel *connectionLabel_briget;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_4;
    QLineEdit *lineEditResistorStandard;
    QComboBox *comboBoxUnit;
    QLineEdit *lineEditResistorRange;
    QLabel *label_percent;
    QLabel *label_precision;
    QLabel *label_resistor_range;
    QLabel *label_resistor_standard;
    QLineEdit *lineEditPrecision;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_Excel;
    QPushButton *pushButton_selectExcel;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButtonSetting;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *logMessageEdit;

    void setupUi(QWidget *va)
    {
        if (va->objectName().isEmpty())
            va->setObjectName("va");
        va->resize(768, 834);
        verticalLayout = new QVBoxLayout(va);
        verticalLayout->setObjectName("verticalLayout");
        groupBox = new QGroupBox(va);
        groupBox->setObjectName("groupBox");
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        label_6 = new QLabel(groupBox);
        label_6->setObjectName("label_6");

        gridLayout->addWidget(label_6, 0, 0, 1, 1);

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

        widget_step = new QWidget(groupBox);
        widget_step->setObjectName("widget_step");
        horizontalLayout = new QHBoxLayout(widget_step);
        horizontalLayout->setObjectName("horizontalLayout");
        radioButtonFirst = new QRadioButton(widget_step);
        radioButtonFirst->setObjectName("radioButtonFirst");
        radioButtonFirst->setChecked(true);

        horizontalLayout->addWidget(radioButtonFirst);

        radioButtonMiddle = new QRadioButton(widget_step);
        radioButtonMiddle->setObjectName("radioButtonMiddle");

        horizontalLayout->addWidget(radioButtonMiddle);

        radioButtonFinally = new QRadioButton(widget_step);
        radioButtonFinally->setObjectName("radioButtonFinally");

        horizontalLayout->addWidget(radioButtonFinally);


        gridLayout->addWidget(widget_step, 0, 2, 1, 4);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(va);
        groupBox_2->setObjectName("groupBox_2");
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName("gridLayout_2");
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName("label_13");

        gridLayout_2->addWidget(label_13, 1, 5, 1, 1);

        lineEditManufacturer = new QLineEdit(groupBox_2);
        lineEditManufacturer->setObjectName("lineEditManufacturer");

        gridLayout_2->addWidget(lineEditManufacturer, 0, 2, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName("label_4");

        gridLayout_2->addWidget(label_4, 0, 3, 1, 1);

        lineEditQualityLevel = new QLineEdit(groupBox_2);
        lineEditQualityLevel->setObjectName("lineEditQualityLevel");

        gridLayout_2->addWidget(lineEditQualityLevel, 0, 6, 1, 1);

        comboBox = new QComboBox(groupBox_2);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");

        gridLayout_2->addWidget(comboBox, 1, 2, 1, 1);

        label_5_2 = new QLabel(groupBox_2);
        label_5_2->setObjectName("label_5_2");

        gridLayout_2->addWidget(label_5_2, 3, 5, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName("label_7");

        gridLayout_2->addWidget(label_7, 0, 0, 1, 1);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName("label_8");

        gridLayout_2->addWidget(label_8, 0, 5, 1, 1);

        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName("label_12");

        gridLayout_2->addWidget(label_12, 1, 3, 1, 1);

        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName("label_11");

        gridLayout_2->addWidget(label_11, 1, 0, 1, 1);

        lineEditBatch = new QLineEdit(groupBox_2);
        lineEditBatch->setObjectName("lineEditBatch");

        gridLayout_2->addWidget(lineEditBatch, 0, 4, 1, 1);

        lineEditNumber2 = new QLineEdit(groupBox_2);
        lineEditNumber2->setObjectName("lineEditNumber2");

        gridLayout_2->addWidget(lineEditNumber2, 3, 6, 1, 1);

        label_spec = new QLabel(groupBox_2);
        label_spec->setObjectName("label_spec");

        gridLayout_2->addWidget(label_spec, 3, 0, 1, 1);

        comboBox_2 = new QComboBox(groupBox_2);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");

        gridLayout_2->addWidget(comboBox_2, 1, 4, 1, 1);

        lineEditSpecification = new QLineEdit(groupBox_2);
        lineEditSpecification->setObjectName("lineEditSpecification");

        gridLayout_2->addWidget(lineEditSpecification, 3, 2, 1, 3);

        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName("label_14");

        gridLayout_2->addWidget(label_14, 2, 0, 1, 1);

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

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);


        gridLayout_2->addWidget(widget_2, 1, 6, 1, 1);

        comboBox_3 = new QComboBox(groupBox_2);
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName("comboBox_3");

        gridLayout_2->addWidget(comboBox_3, 2, 2, 1, 1);

        label_18 = new QLabel(groupBox_2);
        label_18->setObjectName("label_18");

        gridLayout_2->addWidget(label_18, 2, 3, 1, 1);

        comboBox_4 = new QComboBox(groupBox_2);
        comboBox_4->addItem(QString());
        comboBox_4->setObjectName("comboBox_4");

        gridLayout_2->addWidget(comboBox_4, 2, 4, 1, 1);

        label_19 = new QLabel(groupBox_2);
        label_19->setObjectName("label_19");

        gridLayout_2->addWidget(label_19, 2, 5, 1, 1);

        widget = new QWidget(groupBox_2);
        widget->setObjectName("widget");
        horizontalLayout_5 = new QHBoxLayout(widget);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        dateEditMin_2 = new QDateEdit(widget);
        dateEditMin_2->setObjectName("dateEditMin_2");
        dateEditMin_2->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        dateEditMin_2->setDate(QDate(2025, 1, 1));

        horizontalLayout_5->addWidget(dateEditMin_2);

        label_20 = new QLabel(widget);
        label_20->setObjectName("label_20");

        horizontalLayout_5->addWidget(label_20);

        dateEditMax_2 = new QDateEdit(widget);
        dateEditMax_2->setObjectName("dateEditMax_2");
        dateEditMax_2->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        dateEditMax_2->setDate(QDate(2026, 1, 1));

        horizontalLayout_5->addWidget(dateEditMax_2);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);


        gridLayout_2->addWidget(widget, 2, 6, 1, 1);


        verticalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(va);
        groupBox_3->setObjectName("groupBox_3");
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName("gridLayout_3");
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName("label_5");

        gridLayout_3->addWidget(label_5, 0, 2, 1, 1);

        lineEditTemperature = new QLineEdit(groupBox_3);
        lineEditTemperature->setObjectName("lineEditTemperature");

        gridLayout_3->addWidget(lineEditTemperature, 0, 1, 1, 1);

        lineEditPressure = new QLineEdit(groupBox_3);
        lineEditPressure->setObjectName("lineEditPressure");

        gridLayout_3->addWidget(lineEditPressure, 0, 5, 1, 1);

        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName("label_10");

        gridLayout_3->addWidget(label_10, 0, 4, 1, 1);

        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName("label_9");

        gridLayout_3->addWidget(label_9, 0, 0, 1, 1);

        lineEditHumidity = new QLineEdit(groupBox_3);
        lineEditHumidity->setObjectName("lineEditHumidity");

        gridLayout_3->addWidget(lineEditHumidity, 0, 3, 1, 1);


        verticalLayout->addWidget(groupBox_3);

        groupBox_6 = new QGroupBox(va);
        groupBox_6->setObjectName("groupBox_6");
        gridLayout_5 = new QGridLayout(groupBox_6);
        gridLayout_5->setObjectName("gridLayout_5");
        disConnectButton = new QPushButton(groupBox_6);
        disConnectButton->setObjectName("disConnectButton");

        gridLayout_5->addWidget(disConnectButton, 0, 4, 1, 1);

        label_15 = new QLabel(groupBox_6);
        label_15->setObjectName("label_15");

        gridLayout_5->addWidget(label_15, 0, 0, 1, 1);

        connectButton = new QPushButton(groupBox_6);
        connectButton->setObjectName("connectButton");

        gridLayout_5->addWidget(connectButton, 0, 3, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        connectionLabel = new QLabel(groupBox_6);
        connectionLabel->setObjectName("connectionLabel");
        connectionLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        gridLayout_5->addWidget(connectionLabel, 0, 5, 1, 1);

        label_17 = new QLabel(groupBox_6);
        label_17->setObjectName("label_17");

        gridLayout_5->addWidget(label_17, 0, 6, 1, 1);

        ipEdit = new QLineEdit(groupBox_6);
        ipEdit->setObjectName("ipEdit");

        gridLayout_5->addWidget(ipEdit, 0, 1, 1, 1);

        label_21 = new QLabel(groupBox_6);
        label_21->setObjectName("label_21");

        gridLayout_5->addWidget(label_21, 1, 0, 1, 1);

        portEdit = new QLineEdit(groupBox_6);
        portEdit->setObjectName("portEdit");

        gridLayout_5->addWidget(portEdit, 1, 1, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_8, 1, 2, 1, 1);

        connectButton_briget = new QPushButton(groupBox_6);
        connectButton_briget->setObjectName("connectButton_briget");

        gridLayout_5->addWidget(connectButton_briget, 1, 3, 1, 1);

        connectionLabel_briget = new QLabel(groupBox_6);
        connectionLabel_briget->setObjectName("connectionLabel_briget");
        connectionLabel_briget->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        gridLayout_5->addWidget(connectionLabel_briget, 1, 5, 1, 1);


        verticalLayout->addWidget(groupBox_6);

        groupBox_4 = new QGroupBox(va);
        groupBox_4->setObjectName("groupBox_4");
        gridLayout_4 = new QGridLayout(groupBox_4);
        gridLayout_4->setObjectName("gridLayout_4");
        lineEditResistorStandard = new QLineEdit(groupBox_4);
        lineEditResistorStandard->setObjectName("lineEditResistorStandard");

        gridLayout_4->addWidget(lineEditResistorStandard, 0, 1, 1, 1);

        comboBoxUnit = new QComboBox(groupBox_4);
        comboBoxUnit->addItem(QString());
        comboBoxUnit->addItem(QString());
        comboBoxUnit->addItem(QString());
        comboBoxUnit->addItem(QString());
        comboBoxUnit->setObjectName("comboBoxUnit");

        gridLayout_4->addWidget(comboBoxUnit, 0, 2, 1, 1);

        lineEditResistorRange = new QLineEdit(groupBox_4);
        lineEditResistorRange->setObjectName("lineEditResistorRange");
        lineEditResistorRange->setStyleSheet(QString::fromUtf8(""));
        lineEditResistorRange->setReadOnly(true);

        gridLayout_4->addWidget(lineEditResistorRange, 1, 1, 1, 5);

        label_percent = new QLabel(groupBox_4);
        label_percent->setObjectName("label_percent");

        gridLayout_4->addWidget(label_percent, 0, 5, 1, 1);

        label_precision = new QLabel(groupBox_4);
        label_precision->setObjectName("label_precision");

        gridLayout_4->addWidget(label_precision, 0, 3, 1, 1);

        label_resistor_range = new QLabel(groupBox_4);
        label_resistor_range->setObjectName("label_resistor_range");

        gridLayout_4->addWidget(label_resistor_range, 1, 0, 1, 1);

        label_resistor_standard = new QLabel(groupBox_4);
        label_resistor_standard->setObjectName("label_resistor_standard");

        gridLayout_4->addWidget(label_resistor_standard, 0, 0, 1, 1);

        lineEditPrecision = new QLineEdit(groupBox_4);
        lineEditPrecision->setObjectName("lineEditPrecision");

        gridLayout_4->addWidget(lineEditPrecision, 0, 4, 1, 1);


        verticalLayout->addWidget(groupBox_4);

        widget_3 = new QWidget(va);
        widget_3->setObjectName("widget_3");
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_Excel = new QPushButton(widget_3);
        pushButton_Excel->setObjectName("pushButton_Excel");

        horizontalLayout_2->addWidget(pushButton_Excel);

        pushButton_selectExcel = new QPushButton(widget_3);
        pushButton_selectExcel->setObjectName("pushButton_selectExcel");

        horizontalLayout_2->addWidget(pushButton_selectExcel);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        pushButtonSetting = new QPushButton(widget_3);
        pushButtonSetting->setObjectName("pushButtonSetting");
        pushButtonSetting->setCheckable(false);

        horizontalLayout_2->addWidget(pushButtonSetting);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);

        pushButton = new QPushButton(widget_3);
        pushButton->setObjectName("pushButton");
        pushButton->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(pushButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        verticalLayout->addWidget(widget_3);

        groupBox_5 = new QGroupBox(va);
        groupBox_5->setObjectName("groupBox_5");
        verticalLayout_2 = new QVBoxLayout(groupBox_5);
        verticalLayout_2->setObjectName("verticalLayout_2");
        logMessageEdit = new QTextEdit(groupBox_5);
        logMessageEdit->setObjectName("logMessageEdit");
        logMessageEdit->setReadOnly(true);

        verticalLayout_2->addWidget(logMessageEdit);


        verticalLayout->addWidget(groupBox_5);


        retranslateUi(va);

        QMetaObject::connectSlotsByName(va);
    } // setupUi

    void retranslateUi(QWidget *va)
    {
        va->setWindowTitle(QCoreApplication::translate("va", "\347\224\265\351\230\273\346\265\213\350\257\225\347\263\273\347\273\237", nullptr));
        groupBox->setTitle(QCoreApplication::translate("va", "\345\237\272\347\241\200\344\277\241\346\201\257", nullptr));
        label_6->setText(QCoreApplication::translate("va", "\346\243\200\346\265\213\345\234\260\347\202\271:", nullptr));
        lineEditLocation->setText(QCoreApplication::translate("va", "\347\224\265\346\200\247\350\203\275\344\272\214\345\256\244", nullptr));
        label->setText(QCoreApplication::translate("va", "\346\243\200\346\265\213\345\215\225\345\217\267:", nullptr));
        lineEditOrder->setText(QCoreApplication::translate("va", "\346\243\200\346\265\213\345\215\225\345\217\267", nullptr));
        label_2->setText(QCoreApplication::translate("va", "\346\240\267\344\273\266\345\220\215\347\247\260:", nullptr));
        lineEditName->setText(QCoreApplication::translate("va", "\346\240\267\344\273\266\345\220\215\347\247\260", nullptr));
        label_3->setText(QCoreApplication::translate("va", "\351\200\201\346\240\267\346\225\260\351\207\217:", nullptr));
        lineEditNumber1->setText(QCoreApplication::translate("va", "\351\200\201\346\240\267\346\225\260\351\207\217", nullptr));
        radioButtonFirst->setText(QCoreApplication::translate("va", "\345\210\235\346\254\241\346\243\200\346\265\213", nullptr));
        radioButtonMiddle->setText(QCoreApplication::translate("va", "\344\270\255\351\227\264\346\243\200\346\265\213", nullptr));
        radioButtonFinally->setText(QCoreApplication::translate("va", "\346\234\200\347\273\210\346\243\200\346\265\213", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("va", "\346\240\267\345\223\201\344\277\241\346\201\257", nullptr));
        label_13->setText(QCoreApplication::translate("va", "\346\234\211\346\225\210\346\234\237:", nullptr));
        lineEditManufacturer->setText(QCoreApplication::translate("va", "\347\224\237\344\272\247\345\216\202\345\256\266", nullptr));
        label_4->setText(QCoreApplication::translate("va", "\347\224\237\344\272\247\346\211\271\346\254\241:", nullptr));
        lineEditQualityLevel->setText(QCoreApplication::translate("va", "\345\267\245\344\270\232\347\272\247", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("va", "\346\225\260\345\255\227\344\270\207\347\224\250\350\241\250", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("va", "\347\224\265\346\241\245", nullptr));

        label_5_2->setText(QCoreApplication::translate("va", "\346\243\200\346\265\213\346\225\260\351\207\217:", nullptr));
        label_7->setText(QCoreApplication::translate("va", "\347\224\237\344\272\247\345\216\202\345\256\266:", nullptr));
        label_8->setText(QCoreApplication::translate("va", "\350\264\250\351\207\217\347\255\211\347\272\247:", nullptr));
        label_12->setText(QCoreApplication::translate("va", "\345\236\213\345\217\267:", nullptr));
        label_11->setText(QCoreApplication::translate("va", "\346\243\200\346\265\213\350\256\276\345\244\207\351\200\211\346\213\251:", nullptr));
        lineEditBatch->setText(QCoreApplication::translate("va", "\347\224\237\344\272\247\346\211\271\346\254\241", nullptr));
        lineEditNumber2->setText(QCoreApplication::translate("va", "\346\243\200\346\265\213\346\225\260\351\207\217", nullptr));
        label_spec->setText(QCoreApplication::translate("va", "\350\247\204\346\240\274\345\236\213\345\217\267:", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("va", "DM3068", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("va", "34461A", nullptr));

        lineEditSpecification->setText(QCoreApplication::translate("va", "\350\247\204\346\240\274\345\236\213\345\217\267", nullptr));
        label_14->setText(QCoreApplication::translate("va", "\345\244\226\350\247\202\346\243\200\346\265\213\350\256\276\345\244\207:", nullptr));
        dateEditMin->setDisplayFormat(QCoreApplication::translate("va", "yyyy.M.d", nullptr));
        label_16->setText(QCoreApplication::translate("va", "~", nullptr));
        dateEditMax->setDisplayFormat(QCoreApplication::translate("va", "yyyy.M.d", nullptr));
        comboBox_3->setItemText(0, QCoreApplication::translate("va", "\346\230\276\345\276\256\351\225\234", nullptr));

        label_18->setText(QCoreApplication::translate("va", "\345\236\213\345\217\267:", nullptr));
        comboBox_4->setItemText(0, QCoreApplication::translate("va", "GP-660V", nullptr));

        label_19->setText(QCoreApplication::translate("va", "\346\234\211\346\225\210\346\234\237:", nullptr));
        dateEditMin_2->setDisplayFormat(QCoreApplication::translate("va", "yyyy.M.d", nullptr));
        label_20->setText(QCoreApplication::translate("va", "~", nullptr));
        dateEditMax_2->setDisplayFormat(QCoreApplication::translate("va", "yyyy.M.d", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("va", "\347\216\257\345\242\203\346\235\241\344\273\266", nullptr));
        label_5->setText(QCoreApplication::translate("va", "\347\216\257\345\242\203\346\271\277\345\272\246:", nullptr));
        lineEditTemperature->setText(QCoreApplication::translate("va", "\347\216\257\345\242\203\346\270\251\345\272\246", nullptr));
        lineEditPressure->setText(QCoreApplication::translate("va", "\345\244\247\346\260\224\345\216\213\345\212\233", nullptr));
        label_10->setText(QCoreApplication::translate("va", "\345\244\247\346\260\224\345\216\213\345\212\233:", nullptr));
        label_9->setText(QCoreApplication::translate("va", "\347\216\257\345\242\203\346\270\251\345\272\246:", nullptr));
        lineEditHumidity->setText(QCoreApplication::translate("va", "\347\216\257\345\242\203\346\271\277\345\272\246", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("va", "\350\277\236\346\216\245\350\256\276\347\275\256", nullptr));
        disConnectButton->setText(QCoreApplication::translate("va", "\346\226\255\345\274\200\350\277\236\346\216\245", nullptr));
        label_15->setText(QCoreApplication::translate("va", "\350\256\276\345\244\207IP\345\234\260\345\235\200:", nullptr));
        connectButton->setText(QCoreApplication::translate("va", "\345\274\200\345\247\213\350\277\236\346\216\245", nullptr));
        connectionLabel->setText(QCoreApplication::translate("va", "\347\212\266\346\200\201:\346\234\252\350\277\236\346\216\245", nullptr));
        label_17->setText(QString());
        ipEdit->setText(QCoreApplication::translate("va", "172.22.127.227", nullptr));
        label_21->setText(QCoreApplication::translate("va", "\350\256\276\345\244\207\347\253\257\345\217\243: ", nullptr));
        portEdit->setText(QCoreApplication::translate("va", "17", nullptr));
        connectButton_briget->setText(QCoreApplication::translate("va", "\345\274\200\345\247\213\350\277\236\346\216\245", nullptr));
        connectionLabel_briget->setText(QCoreApplication::translate("va", "\347\212\266\346\200\201:\346\234\252\350\277\236\346\216\245", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("va", "\346\265\213\350\257\225\345\210\244\346\215\256", nullptr));
        lineEditResistorStandard->setText(QCoreApplication::translate("va", "1000", nullptr));
        lineEditResistorStandard->setPlaceholderText(QCoreApplication::translate("va", "\350\276\223\345\205\245\346\240\207\345\207\206\345\200\274", nullptr));
        comboBoxUnit->setItemText(0, QCoreApplication::translate("va", "m\316\251", nullptr));
        comboBoxUnit->setItemText(1, QCoreApplication::translate("va", "\316\251", nullptr));
        comboBoxUnit->setItemText(2, QCoreApplication::translate("va", "k\316\251", nullptr));
        comboBoxUnit->setItemText(3, QCoreApplication::translate("va", "M\316\251", nullptr));

        comboBoxUnit->setCurrentText(QCoreApplication::translate("va", "m\316\251", nullptr));
        lineEditResistorRange->setText(QCoreApplication::translate("va", "950.00 \316\251 ~ 1050.00 \316\251", nullptr));
        label_percent->setText(QCoreApplication::translate("va", "%", nullptr));
        label_precision->setText(QCoreApplication::translate("va", "\347\262\276\347\241\256\345\272\246:", nullptr));
        label_resistor_range->setText(QCoreApplication::translate("va", "\347\224\265\351\230\273\345\220\210\346\240\274\350\214\203\345\233\264:", nullptr));
        label_resistor_standard->setText(QCoreApplication::translate("va", "\347\224\265\351\230\273\346\240\207\345\207\206\345\200\274:", nullptr));
        lineEditPrecision->setText(QCoreApplication::translate("va", "5", nullptr));
        lineEditPrecision->setPlaceholderText(QCoreApplication::translate("va", "\347\231\276\345\210\206\346\257\224", nullptr));
        pushButton_Excel->setText(QCoreApplication::translate("va", "\345\273\272\347\253\213\346\226\260\347\232\204\346\243\200\346\265\213\346\225\260\346\215\256\350\241\250", nullptr));
        pushButton_selectExcel->setText(QCoreApplication::translate("va", "\351\200\211\346\213\251\345\267\245\344\275\234\350\241\250", nullptr));
        pushButtonSetting->setText(QCoreApplication::translate("va", "\346\265\213\351\207\217\350\256\276\347\275\256(\347\224\265\346\241\245)", nullptr));
        pushButton->setText(QCoreApplication::translate("va", "\345\274\200\345\247\213\346\265\213\350\257\225(space)", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("va", "\346\227\245\345\277\227\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class va: public Ui_va {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VA_H
