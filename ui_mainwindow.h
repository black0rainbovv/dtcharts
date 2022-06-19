/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionRefresh;
    QAction *actionReconnect;
    QAction *actionRec;
    QAction *actionOpen_chart;
    QAction *actionSave_chart;
    QAction *actionClear_opened_chart;
    QAction *actionConnect_device;
    QAction *actionDisconnect_device;
    QAction *actionStart;
    QAction *actionStop;
    QAction *actionChart_settings;
    QAction *actionAbout;
    QAction *actionDT_setting;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout_20;
    QCustomPlot *plotwidget;
    QLabel *label_W;
    QLabel *versioLabel;
    QLabel *datetimeLabel;
    QDateTimeEdit *dateTimeEdit;
    QHBoxLayout *horizontalLayout_21;
    QSpacerItem *horizontalSpacer;
    QGroupBox *selectedDeviceLabel;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *nameOfDeviceLabel;
    QLabel *device_label;
    QHBoxLayout *horizontalLayout_2;
    QLabel *statusLavel;
    QLabel *statusNowLabel;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_7;
    QPushButton *actionConnect_device_2;
    QVBoxLayout *verticalLayout_8;
    QPushButton *actionDisconnect_device_2;
    QSpacerItem *horizontalSpacer_6;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_13;
    QHBoxLayout *horizontalLayout_8;
    QTableWidget *tableWidget;
    QVBoxLayout *verticalLayout_14;
    QPushButton *pushButton_Add;
    QPushButton *pushButton_Remove;
    QVBoxLayout *verticalLayout_12;
    QSpacerItem *verticalSpacer_6;
    QHBoxLayout *horizontalLayout_3;
    QSpinBox *cyc_spinBox;
    QLabel *label_30;
    QSpacerItem *verticalSpacer_11;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_6;
    QLineEdit *lineEditCommand;
    QVBoxLayout *verticalLayout_5;
    QPushButton *pushButtonEnter;
    QLineEdit *lineEditCommandRead;
    QSpacerItem *horizontalSpacer_5;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButtonStart;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButtonStop;
    QSpacerItem *horizontalSpacer_4;
    QToolBar *toolBar;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuSettings;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1200, 706);
        MainWindow->setMinimumSize(QSize(600, 400));
        actionRefresh = new QAction(MainWindow);
        actionRefresh->setObjectName(QStringLiteral("actionRefresh"));
        actionReconnect = new QAction(MainWindow);
        actionReconnect->setObjectName(QStringLiteral("actionReconnect"));
        actionRec = new QAction(MainWindow);
        actionRec->setObjectName(QStringLiteral("actionRec"));
        actionOpen_chart = new QAction(MainWindow);
        actionOpen_chart->setObjectName(QStringLiteral("actionOpen_chart"));
        actionSave_chart = new QAction(MainWindow);
        actionSave_chart->setObjectName(QStringLiteral("actionSave_chart"));
        actionClear_opened_chart = new QAction(MainWindow);
        actionClear_opened_chart->setObjectName(QStringLiteral("actionClear_opened_chart"));
        actionConnect_device = new QAction(MainWindow);
        actionConnect_device->setObjectName(QStringLiteral("actionConnect_device"));
        QFont font;
        font.setPointSize(10);
        actionConnect_device->setFont(font);
        actionDisconnect_device = new QAction(MainWindow);
        actionDisconnect_device->setObjectName(QStringLiteral("actionDisconnect_device"));
        actionDisconnect_device->setFont(font);
        actionStart = new QAction(MainWindow);
        actionStart->setObjectName(QStringLiteral("actionStart"));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        actionStart->setFont(font1);
        actionStop = new QAction(MainWindow);
        actionStop->setObjectName(QStringLiteral("actionStop"));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        actionStop->setFont(font2);
        actionChart_settings = new QAction(MainWindow);
        actionChart_settings->setObjectName(QStringLiteral("actionChart_settings"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionDT_setting = new QAction(MainWindow);
        actionDT_setting->setObjectName(QStringLiteral("actionDT_setting"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_5 = new QGridLayout(tab);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        verticalLayout_20 = new QVBoxLayout();
        verticalLayout_20->setSpacing(6);
        verticalLayout_20->setObjectName(QStringLiteral("verticalLayout_20"));
        plotwidget = new QCustomPlot(tab);
        plotwidget->setObjectName(QStringLiteral("plotwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(plotwidget->sizePolicy().hasHeightForWidth());
        plotwidget->setSizePolicy(sizePolicy);
        label_W = new QLabel(plotwidget);
        label_W->setObjectName(QStringLiteral("label_W"));
        label_W->setGeometry(QRect(529, 10, 131, 20));
        QFont font3;
        font3.setPointSize(12);
        label_W->setFont(font3);
        versioLabel = new QLabel(plotwidget);
        versioLabel->setObjectName(QStringLiteral("versioLabel"));
        versioLabel->setGeometry(QRect(990, 40, 101, 16));
        QFont font4;
        font4.setPointSize(9);
        font4.setBold(true);
        font4.setWeight(75);
        versioLabel->setFont(font4);
        datetimeLabel = new QLabel(plotwidget);
        datetimeLabel->setObjectName(QStringLiteral("datetimeLabel"));
        datetimeLabel->setGeometry(QRect(970, 50, 141, 21));
        QFont font5;
        font5.setPointSize(9);
        font5.setBold(false);
        font5.setWeight(50);
        datetimeLabel->setFont(font5);
        dateTimeEdit = new QDateTimeEdit(plotwidget);
        dateTimeEdit->setObjectName(QStringLiteral("dateTimeEdit"));
        dateTimeEdit->setEnabled(false);
        dateTimeEdit->setGeometry(QRect(0, 0, 16, 16));
        dateTimeEdit->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        dateTimeEdit->setReadOnly(true);
        dateTimeEdit->setAccelerated(false);
        dateTimeEdit->setKeyboardTracking(true);

        verticalLayout_20->addWidget(plotwidget);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setSpacing(4);
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_21->addItem(horizontalSpacer);

        selectedDeviceLabel = new QGroupBox(tab);
        selectedDeviceLabel->setObjectName(QStringLiteral("selectedDeviceLabel"));
        selectedDeviceLabel->setFont(font);
        verticalLayout_3 = new QVBoxLayout(selectedDeviceLabel);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        nameOfDeviceLabel = new QLabel(selectedDeviceLabel);
        nameOfDeviceLabel->setObjectName(QStringLiteral("nameOfDeviceLabel"));
        nameOfDeviceLabel->setFont(font);

        horizontalLayout->addWidget(nameOfDeviceLabel, 0, Qt::AlignLeft);

        device_label = new QLabel(selectedDeviceLabel);
        device_label->setObjectName(QStringLiteral("device_label"));
        device_label->setFont(font2);

        horizontalLayout->addWidget(device_label, 0, Qt::AlignRight);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        statusLavel = new QLabel(selectedDeviceLabel);
        statusLavel->setObjectName(QStringLiteral("statusLavel"));
        statusLavel->setMinimumSize(QSize(56, 28));
        statusLavel->setMaximumSize(QSize(56, 28));
        statusLavel->setFont(font);

        horizontalLayout_2->addWidget(statusLavel);

        statusNowLabel = new QLabel(selectedDeviceLabel);
        statusNowLabel->setObjectName(QStringLiteral("statusNowLabel"));
        statusNowLabel->setFont(font2);

        horizontalLayout_2->addWidget(statusNowLabel, 0, Qt::AlignRight);


        verticalLayout_3->addLayout(horizontalLayout_2);


        horizontalLayout_21->addWidget(selectedDeviceLabel, 0, Qt::AlignLeft);

        horizontalSpacer_3 = new QSpacerItem(50, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_21->addItem(horizontalSpacer_3);

        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_9 = new QVBoxLayout(groupBox_3);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        actionConnect_device_2 = new QPushButton(groupBox_3);
        actionConnect_device_2->setObjectName(QStringLiteral("actionConnect_device_2"));
        QFont font6;
        font6.setPointSize(9);
        actionConnect_device_2->setFont(font6);

        verticalLayout_7->addWidget(actionConnect_device_2);


        verticalLayout_9->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        actionDisconnect_device_2 = new QPushButton(groupBox_3);
        actionDisconnect_device_2->setObjectName(QStringLiteral("actionDisconnect_device_2"));
        actionDisconnect_device_2->setFont(font6);

        verticalLayout_8->addWidget(actionDisconnect_device_2);


        verticalLayout_9->addLayout(verticalLayout_8);


        horizontalLayout_21->addWidget(groupBox_3);

        horizontalSpacer_6 = new QSpacerItem(50, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_21->addItem(horizontalSpacer_6);

        groupBox_5 = new QGroupBox(tab);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(groupBox_5->sizePolicy().hasHeightForWidth());
        groupBox_5->setSizePolicy(sizePolicy1);
        groupBox_5->setMinimumSize(QSize(0, 0));
        groupBox_5->setMaximumSize(QSize(500, 110));
        groupBox_5->setFont(font);
        gridLayout_2 = new QGridLayout(groupBox_5);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        tableWidget = new QTableWidget(groupBox_5);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        horizontalLayout_8->addWidget(tableWidget);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        pushButton_Add = new QPushButton(groupBox_5);
        pushButton_Add->setObjectName(QStringLiteral("pushButton_Add"));
        pushButton_Add->setMinimumSize(QSize(30, 30));
        pushButton_Add->setMaximumSize(QSize(30, 30));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Res/Res/plus.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Add->setIcon(icon);
        pushButton_Add->setIconSize(QSize(20, 20));

        verticalLayout_14->addWidget(pushButton_Add);

        pushButton_Remove = new QPushButton(groupBox_5);
        pushButton_Remove->setObjectName(QStringLiteral("pushButton_Remove"));
        pushButton_Remove->setMinimumSize(QSize(30, 30));
        pushButton_Remove->setMaximumSize(QSize(30, 30));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Res/Res/minus.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Remove->setIcon(icon1);
        pushButton_Remove->setIconSize(QSize(20, 20));

        verticalLayout_14->addWidget(pushButton_Remove);


        horizontalLayout_8->addLayout(verticalLayout_14);


        horizontalLayout_13->addLayout(horizontalLayout_8);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_12->addItem(verticalSpacer_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        cyc_spinBox = new QSpinBox(groupBox_5);
        cyc_spinBox->setObjectName(QStringLiteral("cyc_spinBox"));
        cyc_spinBox->setAlignment(Qt::AlignCenter);
        cyc_spinBox->setMinimum(2);
        cyc_spinBox->setValue(3);

        horizontalLayout_3->addWidget(cyc_spinBox);

        label_30 = new QLabel(groupBox_5);
        label_30->setObjectName(QStringLiteral("label_30"));

        horizontalLayout_3->addWidget(label_30);


        verticalLayout_12->addLayout(horizontalLayout_3);

        verticalSpacer_11 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_12->addItem(verticalSpacer_11);


        horizontalLayout_13->addLayout(verticalLayout_12);


        gridLayout_2->addLayout(horizontalLayout_13, 0, 0, 1, 1);


        horizontalLayout_21->addWidget(groupBox_5, 0, Qt::AlignLeft);

        horizontalSpacer_2 = new QSpacerItem(50, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_21->addItem(horizontalSpacer_2);

        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(140, 0));
        verticalLayout_6 = new QVBoxLayout(groupBox_2);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        lineEditCommand = new QLineEdit(groupBox_2);
        lineEditCommand->setObjectName(QStringLiteral("lineEditCommand"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEditCommand->sizePolicy().hasHeightForWidth());
        lineEditCommand->setSizePolicy(sizePolicy2);
        lineEditCommand->setMinimumSize(QSize(165, 0));
        lineEditCommand->setCursorPosition(0);

        verticalLayout_6->addWidget(lineEditCommand, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        pushButtonEnter = new QPushButton(groupBox_2);
        pushButtonEnter->setObjectName(QStringLiteral("pushButtonEnter"));
        pushButtonEnter->setMinimumSize(QSize(165, 0));
        pushButtonEnter->setFont(font6);

        verticalLayout_5->addWidget(pushButtonEnter);


        verticalLayout_6->addLayout(verticalLayout_5);

        lineEditCommandRead = new QLineEdit(groupBox_2);
        lineEditCommandRead->setObjectName(QStringLiteral("lineEditCommandRead"));
        sizePolicy2.setHeightForWidth(lineEditCommandRead->sizePolicy().hasHeightForWidth());
        lineEditCommandRead->setSizePolicy(sizePolicy2);
        lineEditCommandRead->setMinimumSize(QSize(165, 0));
        lineEditCommandRead->setReadOnly(true);

        verticalLayout_6->addWidget(lineEditCommandRead, 0, Qt::AlignLeft|Qt::AlignVCenter);


        horizontalLayout_21->addWidget(groupBox_2, 0, Qt::AlignRight);

        horizontalSpacer_5 = new QSpacerItem(50, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_21->addItem(horizontalSpacer_5);

        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setFlat(false);
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButtonStart = new QPushButton(groupBox);
        pushButtonStart->setObjectName(QStringLiteral("pushButtonStart"));
        pushButtonStart->setFont(font6);

        verticalLayout->addWidget(pushButtonStart);


        verticalLayout_4->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        pushButtonStop = new QPushButton(groupBox);
        pushButtonStop->setObjectName(QStringLiteral("pushButtonStop"));
        pushButtonStop->setFont(font6);

        verticalLayout_2->addWidget(pushButtonStop);


        verticalLayout_4->addLayout(verticalLayout_2);


        horizontalLayout_21->addWidget(groupBox, 0, Qt::AlignRight);

        horizontalSpacer_4 = new QSpacerItem(10, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_21->addItem(horizontalSpacer_4);


        verticalLayout_20->addLayout(horizontalLayout_21);

        verticalLayout_20->setStretch(0, 1);

        gridLayout_5->addLayout(verticalLayout_20, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setFont(font);
        toolBar->setToolTipDuration(0);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1200, 20));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName(QStringLiteral("menuSettings"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(tabWidget, cyc_spinBox);

        toolBar->addAction(actionClear_opened_chart);
        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuSettings->menuAction());
        menuFile->addAction(actionOpen_chart);
        menuFile->addAction(actionSave_chart);
        menuFile->addAction(actionClear_opened_chart);
        menuFile->addAction(actionAbout);
        menuSettings->addAction(actionChart_settings);
        menuSettings->addAction(actionDT_setting);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "ControllerCalib", 0));
        actionRefresh->setText(QApplication::translate("MainWindow", "reconnect", 0));
        actionReconnect->setText(QApplication::translate("MainWindow", "reconnect", 0));
        actionRec->setText(QApplication::translate("MainWindow", "Reconenct", 0));
        actionOpen_chart->setText(QApplication::translate("MainWindow", "Open chart", 0));
#ifndef QT_NO_TOOLTIP
        actionOpen_chart->setToolTip(QApplication::translate("MainWindow", "Opens chart", 0));
#endif // QT_NO_TOOLTIP
        actionOpen_chart->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        actionSave_chart->setText(QApplication::translate("MainWindow", "Save chart", 0));
#ifndef QT_NO_TOOLTIP
        actionSave_chart->setToolTip(QApplication::translate("MainWindow", "Saves chart", 0));
#endif // QT_NO_TOOLTIP
        actionSave_chart->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0));
        actionClear_opened_chart->setText(QApplication::translate("MainWindow", "Clear chart", 0));
#ifndef QT_NO_TOOLTIP
        actionClear_opened_chart->setToolTip(QApplication::translate("MainWindow", "Clears opened chart", 0));
#endif // QT_NO_TOOLTIP
        actionConnect_device->setText(QApplication::translate("MainWindow", "Connect device", 0));
        actionDisconnect_device->setText(QApplication::translate("MainWindow", "Disconnect device", 0));
        actionStart->setText(QApplication::translate("MainWindow", "Start", 0));
#ifndef QT_NO_TOOLTIP
        actionStart->setToolTip(QApplication::translate("MainWindow", "Starts thermal cycling", 0));
#endif // QT_NO_TOOLTIP
        actionStop->setText(QApplication::translate("MainWindow", "Stop", 0));
#ifndef QT_NO_TOOLTIP
        actionStop->setToolTip(QApplication::translate("MainWindow", "Stops thermal cycling", 0));
#endif // QT_NO_TOOLTIP
        actionChart_settings->setText(QApplication::translate("MainWindow", "Chart settings", 0));
#ifndef QT_NO_TOOLTIP
        actionChart_settings->setToolTip(QApplication::translate("MainWindow", "Opens chart settings", 0));
#endif // QT_NO_TOOLTIP
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0));
        actionDT_setting->setText(QApplication::translate("MainWindow", "Opens DT setting", 0));
        label_W->setText(QString());
        versioLabel->setText(QApplication::translate("MainWindow", "Version: 1.4.4", 0));
        datetimeLabel->setText(QString());
        selectedDeviceLabel->setTitle(QApplication::translate("MainWindow", "Selected device", 0));
        nameOfDeviceLabel->setText(QApplication::translate("MainWindow", "Number of device:", 0));
        device_label->setText(QString());
        statusLavel->setText(QApplication::translate("MainWindow", "Status:", 0));
        statusNowLabel->setText(QString());
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Connection status", 0));
        actionConnect_device_2->setText(QApplication::translate("MainWindow", "Connect device", 0));
        actionDisconnect_device_2->setText(QApplication::translate("MainWindow", "Disconnect device", 0));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Thermal cycling program", 0));
        pushButton_Add->setText(QString());
        pushButton_Remove->setText(QString());
        label_30->setText(QApplication::translate("MainWindow", "cycles", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Command line", 0));
        pushButtonEnter->setText(QApplication::translate("MainWindow", "Enter", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Operation", 0));
        pushButtonStart->setText(QApplication::translate("MainWindow", "Start", 0));
        pushButtonStop->setText(QApplication::translate("MainWindow", "Stop", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Chart", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuSettings->setTitle(QApplication::translate("MainWindow", "Settings", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
