/********************************************************************************
** Form generated from reading UI file 'dtsettings.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DTSETTINGS_H
#define UI_DTSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dtsettings
{
public:
    QGroupBox *groupBox_3;
    QLabel *label_7;
    QLabel *label_23;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_12;
    QLineEdit *spinBox_r4;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_14;
    QLineEdit *spinBox_r3;
    QWidget *layoutWidget_4;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_15;
    QLineEdit *spinBox_r1;
    QWidget *layoutWidget_5;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_16;
    QLineEdit *spinBox_r0;
    QWidget *layoutWidget_6;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_13;
    QLineEdit *spinBox_r2;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_6;
    QHBoxLayout *horizontalLayout_22;
    QVBoxLayout *verticalLayout_51;
    QLabel *label_51;
    QVBoxLayout *verticalLayout_23;
    QDateEdit *dateEdit;
    QTimeEdit *timeEdit;
    QVBoxLayout *verticalLayout_21;
    QSpacerItem *verticalSpacer_18;
    QPushButton *pushButton_sync;
    QSpacerItem *verticalSpacer_19;
    QVBoxLayout *verticalLayout_52;
    QLabel *label_52;
    QVBoxLayout *verticalLayout_50;
    QDateEdit *dateEdit_2;
    QTimeEdit *timeEdit_2;
    QPushButton *pushButton_3;
    QGroupBox *groupBox_4;
    QLabel *label_8;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_17;
    QLineEdit *maxlineEdit_4;
    QWidget *layoutWidget_9;
    QVBoxLayout *verticalLayout_14;
    QLabel *label_18;
    QLineEdit *maxlineEdit_3;
    QWidget *layoutWidget_10;
    QVBoxLayout *verticalLayout_15;
    QLabel *label_19;
    QLineEdit *lineEdit;
    QWidget *layoutWidget_14;
    QVBoxLayout *verticalLayout_16;
    QLabel *label_10;
    QLineEdit *maxlineEdit_0;
    QWidget *layoutWidget_15;
    QVBoxLayout *verticalLayout_17;
    QLabel *label_21;
    QLineEdit *maxlineEdit_2;

    void setupUi(QDialog *dtsettings)
    {
        if (dtsettings->objectName().isEmpty())
            dtsettings->setObjectName(QStringLiteral("dtsettings"));
        dtsettings->resize(478, 352);
        groupBox_3 = new QGroupBox(dtsettings);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 10, 451, 91));
        QFont font;
        font.setPointSize(10);
        groupBox_3->setFont(font);
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 35, 101, 21));
        QFont font1;
        font1.setPointSize(9);
        label_7->setFont(font1);
        label_7->setTextFormat(Qt::AutoText);
        label_23 = new QLabel(groupBox_3);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(10, 55, 101, 20));
        label_23->setFont(font1);
        layoutWidget = new QWidget(groupBox_3);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(360, 30, 61, 51));
        verticalLayout_11 = new QVBoxLayout(layoutWidget);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setAlignment(Qt::AlignCenter);

        verticalLayout_11->addWidget(label_12);

        spinBox_r4 = new QLineEdit(layoutWidget);
        spinBox_r4->setObjectName(QStringLiteral("spinBox_r4"));
        spinBox_r4->setEnabled(false);

        verticalLayout_11->addWidget(spinBox_r4);

        layoutWidget_2 = new QWidget(groupBox_3);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(300, 30, 61, 51));
        verticalLayout_10 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        label_14 = new QLabel(layoutWidget_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setAlignment(Qt::AlignCenter);

        verticalLayout_10->addWidget(label_14);

        spinBox_r3 = new QLineEdit(layoutWidget_2);
        spinBox_r3->setObjectName(QStringLiteral("spinBox_r3"));
        spinBox_r3->setEnabled(false);

        verticalLayout_10->addWidget(spinBox_r3);

        layoutWidget_4 = new QWidget(groupBox_3);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(180, 30, 61, 51));
        verticalLayout_8 = new QVBoxLayout(layoutWidget_4);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        label_15 = new QLabel(layoutWidget_4);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(label_15);

        spinBox_r1 = new QLineEdit(layoutWidget_4);
        spinBox_r1->setObjectName(QStringLiteral("spinBox_r1"));
        spinBox_r1->setEnabled(false);

        verticalLayout_8->addWidget(spinBox_r1);

        layoutWidget_5 = new QWidget(groupBox_3);
        layoutWidget_5->setObjectName(QStringLiteral("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(120, 30, 61, 51));
        verticalLayout_7 = new QVBoxLayout(layoutWidget_5);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_16 = new QLabel(layoutWidget_5);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_16);

        spinBox_r0 = new QLineEdit(layoutWidget_5);
        spinBox_r0->setObjectName(QStringLiteral("spinBox_r0"));
        spinBox_r0->setEnabled(false);

        verticalLayout_7->addWidget(spinBox_r0);

        verticalLayout_7->setStretch(0, 1);
        layoutWidget_6 = new QWidget(groupBox_3);
        layoutWidget_6->setObjectName(QStringLiteral("layoutWidget_6"));
        layoutWidget_6->setGeometry(QRect(240, 30, 61, 51));
        verticalLayout_9 = new QVBoxLayout(layoutWidget_6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(layoutWidget_6);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(label_13);

        spinBox_r2 = new QLineEdit(layoutWidget_6);
        spinBox_r2->setObjectName(QStringLiteral("spinBox_r2"));
        spinBox_r2->setEnabled(false);

        verticalLayout_9->addWidget(spinBox_r2);

        groupBox_7 = new QGroupBox(dtsettings);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(20, 220, 211, 119));
        gridLayout_6 = new QGridLayout(groupBox_7);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        verticalLayout_51 = new QVBoxLayout();
        verticalLayout_51->setObjectName(QStringLiteral("verticalLayout_51"));
        label_51 = new QLabel(groupBox_7);
        label_51->setObjectName(QStringLiteral("label_51"));
        label_51->setAlignment(Qt::AlignCenter);

        verticalLayout_51->addWidget(label_51);

        verticalLayout_23 = new QVBoxLayout();
        verticalLayout_23->setObjectName(QStringLiteral("verticalLayout_23"));
        dateEdit = new QDateEdit(groupBox_7);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setMaximumSize(QSize(80, 16777215));
        dateEdit->setAlignment(Qt::AlignCenter);
        dateEdit->setReadOnly(true);
        dateEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);

        verticalLayout_23->addWidget(dateEdit);

        timeEdit = new QTimeEdit(groupBox_7);
        timeEdit->setObjectName(QStringLiteral("timeEdit"));
        timeEdit->setMaximumSize(QSize(80, 16777215));
        timeEdit->setAlignment(Qt::AlignCenter);
        timeEdit->setReadOnly(true);
        timeEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);

        verticalLayout_23->addWidget(timeEdit);


        verticalLayout_51->addLayout(verticalLayout_23);


        horizontalLayout_22->addLayout(verticalLayout_51);

        verticalLayout_21 = new QVBoxLayout();
        verticalLayout_21->setObjectName(QStringLiteral("verticalLayout_21"));
        verticalSpacer_18 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_21->addItem(verticalSpacer_18);

        pushButton_sync = new QPushButton(groupBox_7);
        pushButton_sync->setObjectName(QStringLiteral("pushButton_sync"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Res/Res/sync.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_sync->setIcon(icon);
        pushButton_sync->setIconSize(QSize(25, 25));

        verticalLayout_21->addWidget(pushButton_sync);

        verticalSpacer_19 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_21->addItem(verticalSpacer_19);


        horizontalLayout_22->addLayout(verticalLayout_21);

        verticalLayout_52 = new QVBoxLayout();
        verticalLayout_52->setObjectName(QStringLiteral("verticalLayout_52"));
        label_52 = new QLabel(groupBox_7);
        label_52->setObjectName(QStringLiteral("label_52"));
        label_52->setAlignment(Qt::AlignCenter);

        verticalLayout_52->addWidget(label_52);

        verticalLayout_50 = new QVBoxLayout();
        verticalLayout_50->setObjectName(QStringLiteral("verticalLayout_50"));
        dateEdit_2 = new QDateEdit(groupBox_7);
        dateEdit_2->setObjectName(QStringLiteral("dateEdit_2"));
        dateEdit_2->setMaximumSize(QSize(80, 16777215));
        dateEdit_2->setAlignment(Qt::AlignCenter);
        dateEdit_2->setReadOnly(true);
        dateEdit_2->setButtonSymbols(QAbstractSpinBox::NoButtons);

        verticalLayout_50->addWidget(dateEdit_2);

        timeEdit_2 = new QTimeEdit(groupBox_7);
        timeEdit_2->setObjectName(QStringLiteral("timeEdit_2"));
        timeEdit_2->setMaximumSize(QSize(80, 16777215));
        timeEdit_2->setAlignment(Qt::AlignCenter);
        timeEdit_2->setReadOnly(true);
        timeEdit_2->setButtonSymbols(QAbstractSpinBox::NoButtons);

        verticalLayout_50->addWidget(timeEdit_2);


        verticalLayout_52->addLayout(verticalLayout_50);


        horizontalLayout_22->addLayout(verticalLayout_52);


        gridLayout_6->addLayout(horizontalLayout_22, 0, 0, 1, 1);

        pushButton_3 = new QPushButton(dtsettings);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(390, 300, 80, 40));
        groupBox_4 = new QGroupBox(dtsettings);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(20, 110, 451, 91));
        groupBox_4->setFont(font);
        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 40, 101, 21));
        label_8->setFont(font1);
        label_8->setTextFormat(Qt::AutoText);
        layoutWidget_3 = new QWidget(groupBox_4);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(360, 30, 61, 51));
        verticalLayout_12 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        verticalLayout_12->setContentsMargins(0, 0, 0, 0);
        label_17 = new QLabel(layoutWidget_3);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setAlignment(Qt::AlignCenter);

        verticalLayout_12->addWidget(label_17);

        maxlineEdit_4 = new QLineEdit(layoutWidget_3);
        maxlineEdit_4->setObjectName(QStringLiteral("maxlineEdit_4"));
        maxlineEdit_4->setEnabled(false);

        verticalLayout_12->addWidget(maxlineEdit_4);

        layoutWidget_9 = new QWidget(groupBox_4);
        layoutWidget_9->setObjectName(QStringLiteral("layoutWidget_9"));
        layoutWidget_9->setGeometry(QRect(300, 30, 61, 51));
        verticalLayout_14 = new QVBoxLayout(layoutWidget_9);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        verticalLayout_14->setContentsMargins(0, 0, 0, 0);
        label_18 = new QLabel(layoutWidget_9);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setAlignment(Qt::AlignCenter);

        verticalLayout_14->addWidget(label_18);

        maxlineEdit_3 = new QLineEdit(layoutWidget_9);
        maxlineEdit_3->setObjectName(QStringLiteral("maxlineEdit_3"));
        maxlineEdit_3->setEnabled(false);

        verticalLayout_14->addWidget(maxlineEdit_3);

        layoutWidget_10 = new QWidget(groupBox_4);
        layoutWidget_10->setObjectName(QStringLiteral("layoutWidget_10"));
        layoutWidget_10->setGeometry(QRect(180, 30, 61, 51));
        verticalLayout_15 = new QVBoxLayout(layoutWidget_10);
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        verticalLayout_15->setContentsMargins(0, 0, 0, 0);
        label_19 = new QLabel(layoutWidget_10);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setAlignment(Qt::AlignCenter);

        verticalLayout_15->addWidget(label_19);

        lineEdit = new QLineEdit(layoutWidget_10);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setEnabled(false);

        verticalLayout_15->addWidget(lineEdit);

        layoutWidget_14 = new QWidget(groupBox_4);
        layoutWidget_14->setObjectName(QStringLiteral("layoutWidget_14"));
        layoutWidget_14->setGeometry(QRect(120, 30, 61, 51));
        verticalLayout_16 = new QVBoxLayout(layoutWidget_14);
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        verticalLayout_16->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(layoutWidget_14);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setAlignment(Qt::AlignCenter);

        verticalLayout_16->addWidget(label_10);

        maxlineEdit_0 = new QLineEdit(layoutWidget_14);
        maxlineEdit_0->setObjectName(QStringLiteral("maxlineEdit_0"));
        maxlineEdit_0->setEnabled(false);

        verticalLayout_16->addWidget(maxlineEdit_0);

        verticalLayout_16->setStretch(0, 1);
        layoutWidget_15 = new QWidget(groupBox_4);
        layoutWidget_15->setObjectName(QStringLiteral("layoutWidget_15"));
        layoutWidget_15->setGeometry(QRect(240, 30, 61, 51));
        verticalLayout_17 = new QVBoxLayout(layoutWidget_15);
        verticalLayout_17->setObjectName(QStringLiteral("verticalLayout_17"));
        verticalLayout_17->setContentsMargins(0, 0, 0, 0);
        label_21 = new QLabel(layoutWidget_15);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setAlignment(Qt::AlignCenter);

        verticalLayout_17->addWidget(label_21);

        maxlineEdit_2 = new QLineEdit(layoutWidget_15);
        maxlineEdit_2->setObjectName(QStringLiteral("maxlineEdit_2"));
        maxlineEdit_2->setEnabled(false);

        verticalLayout_17->addWidget(maxlineEdit_2);


        retranslateUi(dtsettings);

        QMetaObject::connectSlotsByName(dtsettings);
    } // setupUi

    void retranslateUi(QDialog *dtsettings)
    {
        dtsettings->setWindowTitle(QApplication::translate("dtsettings", "Dialog", 0));
        groupBox_3->setTitle(QApplication::translate("dtsettings", "Position of light filters", 0));
        label_7->setText(QApplication::translate("dtsettings", "<html><head/><body><p>Angle of rotation</p><p><br/></p></body></html>", 0));
        label_23->setText(QApplication::translate("dtsettings", "of light filters", 0));
        label_12->setText(QApplication::translate("dtsettings", "5 ", 0));
        label_14->setText(QApplication::translate("dtsettings", "4 ", 0));
        label_15->setText(QApplication::translate("dtsettings", "2 ", 0));
        label_16->setText(QApplication::translate("dtsettings", "1 ", 0));
        label_13->setText(QApplication::translate("dtsettings", "3 ", 0));
        groupBox_7->setTitle(QApplication::translate("dtsettings", "Date and time", 0));
        label_51->setText(QApplication::translate("dtsettings", "DT", 0));
        dateEdit->setDisplayFormat(QApplication::translate("dtsettings", "dd.MM.yy", 0));
        timeEdit->setDisplayFormat(QApplication::translate("dtsettings", "hh:mm:ss", 0));
#ifndef QT_NO_TOOLTIP
        pushButton_sync->setToolTip(QApplication::translate("dtsettings", "\320\241\320\270\320\275\321\205\321\200\320\276\320\275\320\270\320\267\320\270\321\200\320\276\320\262\320\260\321\202\321\214", 0));
#endif // QT_NO_TOOLTIP
        pushButton_sync->setText(QString());
        label_52->setText(QApplication::translate("dtsettings", "Computer", 0));
        dateEdit_2->setDisplayFormat(QApplication::translate("dtsettings", "dd.MM.yy", 0));
        timeEdit_2->setDisplayFormat(QApplication::translate("dtsettings", "hh:mm:ss", 0));
        pushButton_3->setText(QApplication::translate("dtsettings", "Close", 0));
        groupBox_4->setTitle(QApplication::translate("dtsettings", "Floodlight current, (c.u.) ", 0));
        label_8->setText(QApplication::translate("dtsettings", "Maximum current\n"
"", 0));
        label_17->setText(QApplication::translate("dtsettings", "5 ", 0));
        label_18->setText(QApplication::translate("dtsettings", "4 ", 0));
        label_19->setText(QApplication::translate("dtsettings", "2 ", 0));
        label_10->setText(QApplication::translate("dtsettings", "1 ", 0));
        label_21->setText(QApplication::translate("dtsettings", "3 ", 0));
    } // retranslateUi

};

namespace Ui {
    class dtsettings: public Ui_dtsettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DTSETTINGS_H
