/********************************************************************************
** Form generated from reading UI file 'device_dm3068.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVICE_DM3068_H
#define UI_DEVICE_DM3068_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_device_dm3068
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_interval;
    QSpinBox *spinBox_count;
    QLabel *label_count;
    QTimeEdit *internalTimeEdit;
    QLabel *label;
    QComboBox *comboBox;
    QWidget *widget_buttons;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_confirm;
    QPushButton *pushButton_cancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *device_dm3068)
    {
        if (device_dm3068->objectName().isEmpty())
            device_dm3068->setObjectName("device_dm3068");
        device_dm3068->resize(331, 309);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(device_dm3068->sizePolicy().hasHeightForWidth());
        device_dm3068->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(device_dm3068);
        verticalLayout->setObjectName("verticalLayout");
        groupBox = new QGroupBox(device_dm3068);
        groupBox->setObjectName("groupBox");
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        label_interval = new QLabel(groupBox);
        label_interval->setObjectName("label_interval");

        gridLayout->addWidget(label_interval, 1, 0, 1, 1);

        spinBox_count = new QSpinBox(groupBox);
        spinBox_count->setObjectName("spinBox_count");
        spinBox_count->setMinimum(1);
        spinBox_count->setMaximum(1000);
        spinBox_count->setValue(3);

        gridLayout->addWidget(spinBox_count, 2, 1, 1, 1);

        label_count = new QLabel(groupBox);
        label_count->setObjectName("label_count");

        gridLayout->addWidget(label_count, 2, 0, 1, 1);

        internalTimeEdit = new QTimeEdit(groupBox);
        internalTimeEdit->setObjectName("internalTimeEdit");
        internalTimeEdit->setTime(QTime(0, 0, 15));

        gridLayout->addWidget(internalTimeEdit, 1, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        comboBox = new QComboBox(groupBox);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");

        gridLayout->addWidget(comboBox, 0, 1, 1, 1);


        verticalLayout->addWidget(groupBox);

        widget_buttons = new QWidget(device_dm3068);
        widget_buttons->setObjectName("widget_buttons");
        horizontalLayout = new QHBoxLayout(widget_buttons);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_confirm = new QPushButton(widget_buttons);
        pushButton_confirm->setObjectName("pushButton_confirm");
        pushButton_confirm->setMinimumSize(QSize(80, 35));

        horizontalLayout->addWidget(pushButton_confirm);

        pushButton_cancel = new QPushButton(widget_buttons);
        pushButton_cancel->setObjectName("pushButton_cancel");
        pushButton_cancel->setMinimumSize(QSize(80, 35));

        horizontalLayout->addWidget(pushButton_cancel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget_buttons);


        retranslateUi(device_dm3068);

        pushButton_confirm->setDefault(true);


        QMetaObject::connectSlotsByName(device_dm3068);
    } // setupUi

    void retranslateUi(QDialog *device_dm3068)
    {
        device_dm3068->setWindowTitle(QCoreApplication::translate("device_dm3068", "DM3068\350\256\276\345\244\207\350\256\276\347\275\256", nullptr));
        groupBox->setTitle(QCoreApplication::translate("device_dm3068", "\346\265\213\350\257\225\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        label_interval->setText(QCoreApplication::translate("device_dm3068", "\346\265\213\350\257\225\346\227\266\351\227\264\351\227\264\351\232\224:", nullptr));
        label_count->setText(QCoreApplication::translate("device_dm3068", "\346\265\213\350\257\225\346\254\241\346\225\260:", nullptr));
        internalTimeEdit->setDisplayFormat(QCoreApplication::translate("device_dm3068", "H:mm:ss", nullptr));
        label->setText(QCoreApplication::translate("device_dm3068", "\346\243\200\346\265\213\345\257\271\350\261\241:", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("device_dm3068", "\347\233\264\346\265\201\347\224\265\345\216\213", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("device_dm3068", "\344\272\244\346\265\201\347\224\265\345\216\213", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("device_dm3068", "\347\233\264\346\265\201\347\224\265\346\265\201", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("device_dm3068", "\344\272\244\346\265\201\347\224\265\346\265\201", nullptr));

        pushButton_confirm->setText(QCoreApplication::translate("device_dm3068", "\347\241\256\350\256\244", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("device_dm3068", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class device_dm3068: public Ui_device_dm3068 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICE_DM3068_H
