/********************************************************************************
** Form generated from reading UI file 'plotdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOTDIALOG_H
#define UI_PLOTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include "colorswidget.h"

QT_BEGIN_NAMESPACE

class Ui_PlotDialog
{
public:
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    ColorsWidget *color_widget;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *checkBox_topC;
    QCheckBox *checkBox_midC;
    QCheckBox *checkBox_botC;
    QCheckBox *checkBox_Attach;
    QPushButton *pushButton;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_23;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox_AllTemp;
    QHBoxLayout *horizontalLayout_16;
    QCheckBox *checkBox_1Temp;
    QPushButton *t1color_pushButton;
    QHBoxLayout *horizontalLayout_15;
    QCheckBox *checkBox_2Temp;
    QPushButton *t2color_pushButton;
    QHBoxLayout *horizontalLayout_14;
    QCheckBox *checkBox_3Temp;
    QPushButton *t3color_pushButton;
    QHBoxLayout *horizontalLayout_13;
    QCheckBox *checkBox_4Temp;
    QPushButton *t4color_pushButton;
    QHBoxLayout *horizontalLayout_12;
    QCheckBox *checkBox_5Temp;
    QPushButton *t5color_pushButton;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox_6Temp;
    QPushButton *t6color_pushButton;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *checkBox_AllTok;
    QHBoxLayout *horizontalLayout_22;
    QCheckBox *checkBox_1Tok;
    QPushButton *c1color_pushButton;
    QHBoxLayout *horizontalLayout_21;
    QCheckBox *checkBox_2Tok;
    QPushButton *c2color_pushButton;
    QHBoxLayout *horizontalLayout_20;
    QCheckBox *checkBox_3Tok;
    QPushButton *c3color_pushButton;
    QHBoxLayout *horizontalLayout_19;
    QCheckBox *checkBox_4Tok;
    QPushButton *c4color_pushButton;
    QHBoxLayout *horizontalLayout_18;
    QCheckBox *checkBox_5Tok;
    QPushButton *c5color_pushButton;
    QHBoxLayout *horizontalLayout_17;
    QCheckBox *checkBox_6Tok;
    QPushButton *c6color_pushButton;
    QGroupBox *groupBox_4;
    QCheckBox *checkBox_oldscale;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_8;
    QCheckBox *checkBox_Cap;
    QPushButton *lidcolor_pushButton;
    QHBoxLayout *horizontalLayout_9;
    QCheckBox *checkBox_Rad;
    QPushButton *radcolor_pushButton;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *rad_checkBox;
    QCheckBox *rad_checkBox_1;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_6;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *checkBox_FADC0;
    QPushButton *fadc0color_pushButton;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *checkBox_FADC1;
    QPushButton *fadc1color_pushButton;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *checkBox_FADC2;
    QPushButton *fadc2color_pushButton;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *checkBox_FADC3;
    QPushButton *fadc3color_pushButton;
    QCheckBox *checkBox_Set;
    QCheckBox *checkBox_Delta;
    QPushButton *pushButton_2;

    void setupUi(QDialog *PlotDialog)
    {
        if (PlotDialog->objectName().isEmpty())
            PlotDialog->setObjectName(QStringLiteral("PlotDialog"));
        PlotDialog->resize(390, 240);
        PlotDialog->setMinimumSize(QSize(0, 0));
        PlotDialog->setMouseTracking(true);
        PlotDialog->setModal(true);
        groupBox = new QGroupBox(PlotDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(230, 130, 151, 61));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        color_widget = new ColorsWidget(groupBox);
        color_widget->setObjectName(QStringLiteral("color_widget"));

        gridLayout_3->addWidget(color_widget, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(PlotDialog);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 0, 31, 51));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        checkBox_topC = new QCheckBox(groupBox_2);
        checkBox_topC->setObjectName(QStringLiteral("checkBox_topC"));
        checkBox_topC->setFocusPolicy(Qt::NoFocus);

        verticalLayout_4->addWidget(checkBox_topC);

        checkBox_midC = new QCheckBox(groupBox_2);
        checkBox_midC->setObjectName(QStringLiteral("checkBox_midC"));
        checkBox_midC->setFocusPolicy(Qt::NoFocus);

        verticalLayout_4->addWidget(checkBox_midC);

        checkBox_botC = new QCheckBox(groupBox_2);
        checkBox_botC->setObjectName(QStringLiteral("checkBox_botC"));
        checkBox_botC->setFocusPolicy(Qt::NoFocus);

        verticalLayout_4->addWidget(checkBox_botC);

        checkBox_Attach = new QCheckBox(groupBox_2);
        checkBox_Attach->setObjectName(QStringLiteral("checkBox_Attach"));

        verticalLayout_4->addWidget(checkBox_Attach);


        horizontalLayout_2->addLayout(verticalLayout_4);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        pushButton = new QPushButton(PlotDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 200, 101, 30));
        pushButton->setFocusPolicy(Qt::NoFocus);
        groupBox_3 = new QGroupBox(PlotDialog);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 10, 211, 181));
        gridLayout = new QGridLayout(groupBox_3);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setObjectName(QStringLiteral("horizontalLayout_23"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        checkBox_AllTemp = new QCheckBox(groupBox_3);
        checkBox_AllTemp->setObjectName(QStringLiteral("checkBox_AllTemp"));
        QFont font;
        font.setPointSize(10);
        checkBox_AllTemp->setFont(font);
        checkBox_AllTemp->setFocusPolicy(Qt::NoFocus);

        verticalLayout->addWidget(checkBox_AllTemp);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        checkBox_1Temp = new QCheckBox(groupBox_3);
        checkBox_1Temp->setObjectName(QStringLiteral("checkBox_1Temp"));
        checkBox_1Temp->setFont(font);
        checkBox_1Temp->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_16->addWidget(checkBox_1Temp);

        t1color_pushButton = new QPushButton(groupBox_3);
        t1color_pushButton->setObjectName(QStringLiteral("t1color_pushButton"));
        t1color_pushButton->setMinimumSize(QSize(18, 18));
        t1color_pushButton->setMaximumSize(QSize(18, 18));
        t1color_pushButton->setFlat(true);

        horizontalLayout_16->addWidget(t1color_pushButton);


        verticalLayout->addLayout(horizontalLayout_16);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        checkBox_2Temp = new QCheckBox(groupBox_3);
        checkBox_2Temp->setObjectName(QStringLiteral("checkBox_2Temp"));
        checkBox_2Temp->setFont(font);
        checkBox_2Temp->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_15->addWidget(checkBox_2Temp);

        t2color_pushButton = new QPushButton(groupBox_3);
        t2color_pushButton->setObjectName(QStringLiteral("t2color_pushButton"));
        t2color_pushButton->setMinimumSize(QSize(18, 18));
        t2color_pushButton->setMaximumSize(QSize(18, 18));
        t2color_pushButton->setFlat(true);

        horizontalLayout_15->addWidget(t2color_pushButton);


        verticalLayout->addLayout(horizontalLayout_15);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        checkBox_3Temp = new QCheckBox(groupBox_3);
        checkBox_3Temp->setObjectName(QStringLiteral("checkBox_3Temp"));
        checkBox_3Temp->setFont(font);
        checkBox_3Temp->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_14->addWidget(checkBox_3Temp);

        t3color_pushButton = new QPushButton(groupBox_3);
        t3color_pushButton->setObjectName(QStringLiteral("t3color_pushButton"));
        t3color_pushButton->setMinimumSize(QSize(18, 18));
        t3color_pushButton->setMaximumSize(QSize(18, 18));
        t3color_pushButton->setFlat(true);

        horizontalLayout_14->addWidget(t3color_pushButton);


        verticalLayout->addLayout(horizontalLayout_14);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        checkBox_4Temp = new QCheckBox(groupBox_3);
        checkBox_4Temp->setObjectName(QStringLiteral("checkBox_4Temp"));
        checkBox_4Temp->setFont(font);
        checkBox_4Temp->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_13->addWidget(checkBox_4Temp);

        t4color_pushButton = new QPushButton(groupBox_3);
        t4color_pushButton->setObjectName(QStringLiteral("t4color_pushButton"));
        t4color_pushButton->setMinimumSize(QSize(18, 18));
        t4color_pushButton->setMaximumSize(QSize(18, 18));
        t4color_pushButton->setFlat(true);

        horizontalLayout_13->addWidget(t4color_pushButton);


        verticalLayout->addLayout(horizontalLayout_13);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        checkBox_5Temp = new QCheckBox(groupBox_3);
        checkBox_5Temp->setObjectName(QStringLiteral("checkBox_5Temp"));
        checkBox_5Temp->setFont(font);
        checkBox_5Temp->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_12->addWidget(checkBox_5Temp);

        t5color_pushButton = new QPushButton(groupBox_3);
        t5color_pushButton->setObjectName(QStringLiteral("t5color_pushButton"));
        t5color_pushButton->setMinimumSize(QSize(18, 18));
        t5color_pushButton->setMaximumSize(QSize(18, 18));
        t5color_pushButton->setFlat(true);

        horizontalLayout_12->addWidget(t5color_pushButton);


        verticalLayout->addLayout(horizontalLayout_12);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        checkBox_6Temp = new QCheckBox(groupBox_3);
        checkBox_6Temp->setObjectName(QStringLiteral("checkBox_6Temp"));
        checkBox_6Temp->setFont(font);
        checkBox_6Temp->setFocusPolicy(Qt::NoFocus);

        horizontalLayout->addWidget(checkBox_6Temp);

        t6color_pushButton = new QPushButton(groupBox_3);
        t6color_pushButton->setObjectName(QStringLiteral("t6color_pushButton"));
        t6color_pushButton->setMinimumSize(QSize(18, 18));
        t6color_pushButton->setMaximumSize(QSize(18, 18));
        t6color_pushButton->setFlat(true);

        horizontalLayout->addWidget(t6color_pushButton);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_23->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        checkBox_AllTok = new QCheckBox(groupBox_3);
        checkBox_AllTok->setObjectName(QStringLiteral("checkBox_AllTok"));
        checkBox_AllTok->setFont(font);
        checkBox_AllTok->setFocusPolicy(Qt::NoFocus);

        verticalLayout_2->addWidget(checkBox_AllTok);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        checkBox_1Tok = new QCheckBox(groupBox_3);
        checkBox_1Tok->setObjectName(QStringLiteral("checkBox_1Tok"));
        checkBox_1Tok->setFont(font);
        checkBox_1Tok->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_22->addWidget(checkBox_1Tok);

        c1color_pushButton = new QPushButton(groupBox_3);
        c1color_pushButton->setObjectName(QStringLiteral("c1color_pushButton"));
        c1color_pushButton->setMinimumSize(QSize(18, 18));
        c1color_pushButton->setMaximumSize(QSize(18, 18));
        c1color_pushButton->setFlat(true);

        horizontalLayout_22->addWidget(c1color_pushButton);


        verticalLayout_2->addLayout(horizontalLayout_22);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        checkBox_2Tok = new QCheckBox(groupBox_3);
        checkBox_2Tok->setObjectName(QStringLiteral("checkBox_2Tok"));
        checkBox_2Tok->setFont(font);
        checkBox_2Tok->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_21->addWidget(checkBox_2Tok);

        c2color_pushButton = new QPushButton(groupBox_3);
        c2color_pushButton->setObjectName(QStringLiteral("c2color_pushButton"));
        c2color_pushButton->setMinimumSize(QSize(18, 18));
        c2color_pushButton->setMaximumSize(QSize(18, 18));
        c2color_pushButton->setFlat(true);

        horizontalLayout_21->addWidget(c2color_pushButton);


        verticalLayout_2->addLayout(horizontalLayout_21);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        checkBox_3Tok = new QCheckBox(groupBox_3);
        checkBox_3Tok->setObjectName(QStringLiteral("checkBox_3Tok"));
        checkBox_3Tok->setFont(font);
        checkBox_3Tok->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_20->addWidget(checkBox_3Tok);

        c3color_pushButton = new QPushButton(groupBox_3);
        c3color_pushButton->setObjectName(QStringLiteral("c3color_pushButton"));
        c3color_pushButton->setMinimumSize(QSize(18, 18));
        c3color_pushButton->setMaximumSize(QSize(18, 18));
        c3color_pushButton->setFlat(true);

        horizontalLayout_20->addWidget(c3color_pushButton);


        verticalLayout_2->addLayout(horizontalLayout_20);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        checkBox_4Tok = new QCheckBox(groupBox_3);
        checkBox_4Tok->setObjectName(QStringLiteral("checkBox_4Tok"));
        checkBox_4Tok->setFont(font);
        checkBox_4Tok->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_19->addWidget(checkBox_4Tok);

        c4color_pushButton = new QPushButton(groupBox_3);
        c4color_pushButton->setObjectName(QStringLiteral("c4color_pushButton"));
        c4color_pushButton->setMinimumSize(QSize(18, 18));
        c4color_pushButton->setMaximumSize(QSize(18, 18));
        c4color_pushButton->setFlat(true);

        horizontalLayout_19->addWidget(c4color_pushButton);


        verticalLayout_2->addLayout(horizontalLayout_19);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        checkBox_5Tok = new QCheckBox(groupBox_3);
        checkBox_5Tok->setObjectName(QStringLiteral("checkBox_5Tok"));
        checkBox_5Tok->setFont(font);
        checkBox_5Tok->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_18->addWidget(checkBox_5Tok);

        c5color_pushButton = new QPushButton(groupBox_3);
        c5color_pushButton->setObjectName(QStringLiteral("c5color_pushButton"));
        c5color_pushButton->setMinimumSize(QSize(18, 18));
        c5color_pushButton->setMaximumSize(QSize(18, 18));
        c5color_pushButton->setFlat(true);

        horizontalLayout_18->addWidget(c5color_pushButton);


        verticalLayout_2->addLayout(horizontalLayout_18);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        checkBox_6Tok = new QCheckBox(groupBox_3);
        checkBox_6Tok->setObjectName(QStringLiteral("checkBox_6Tok"));
        checkBox_6Tok->setFont(font);
        checkBox_6Tok->setFocusPolicy(Qt::NoFocus);

        horizontalLayout_17->addWidget(checkBox_6Tok);

        c6color_pushButton = new QPushButton(groupBox_3);
        c6color_pushButton->setObjectName(QStringLiteral("c6color_pushButton"));
        c6color_pushButton->setMinimumSize(QSize(18, 18));
        c6color_pushButton->setMaximumSize(QSize(18, 18));
        c6color_pushButton->setFlat(true);

        horizontalLayout_17->addWidget(c6color_pushButton);


        verticalLayout_2->addLayout(horizontalLayout_17);


        horizontalLayout_23->addLayout(verticalLayout_2);


        gridLayout->addLayout(horizontalLayout_23, 0, 0, 1, 1);

        groupBox_4 = new QGroupBox(PlotDialog);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(0, 0, 21, 21));
        checkBox_oldscale = new QCheckBox(groupBox_4);
        checkBox_oldscale->setObjectName(QStringLiteral("checkBox_oldscale"));
        checkBox_oldscale->setGeometry(QRect(10, 20, 131, 17));
        checkBox_oldscale->setMouseTracking(true);
        checkBox_oldscale->setFocusPolicy(Qt::NoFocus);
        groupBox_5 = new QGroupBox(PlotDialog);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(250, 10, 117, 111));
        gridLayout_4 = new QGridLayout(groupBox_5);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        checkBox_Cap = new QCheckBox(groupBox_5);
        checkBox_Cap->setObjectName(QStringLiteral("checkBox_Cap"));

        horizontalLayout_8->addWidget(checkBox_Cap);

        lidcolor_pushButton = new QPushButton(groupBox_5);
        lidcolor_pushButton->setObjectName(QStringLiteral("lidcolor_pushButton"));
        lidcolor_pushButton->setMinimumSize(QSize(18, 18));
        lidcolor_pushButton->setMaximumSize(QSize(18, 18));
        lidcolor_pushButton->setFlat(true);

        horizontalLayout_8->addWidget(lidcolor_pushButton);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        checkBox_Rad = new QCheckBox(groupBox_5);
        checkBox_Rad->setObjectName(QStringLiteral("checkBox_Rad"));

        horizontalLayout_9->addWidget(checkBox_Rad);

        radcolor_pushButton = new QPushButton(groupBox_5);
        radcolor_pushButton->setObjectName(QStringLiteral("radcolor_pushButton"));
        radcolor_pushButton->setMinimumSize(QSize(18, 18));
        radcolor_pushButton->setMaximumSize(QSize(18, 18));
        radcolor_pushButton->setFlat(true);

        horizontalLayout_9->addWidget(radcolor_pushButton);


        verticalLayout_3->addLayout(horizontalLayout_9);


        gridLayout_4->addLayout(verticalLayout_3, 0, 0, 1, 1);

        groupBox_6 = new QGroupBox(PlotDialog);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(0, 0, 16, 16));
        gridLayout_5 = new QGridLayout(groupBox_6);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        rad_checkBox = new QCheckBox(groupBox_6);
        rad_checkBox->setObjectName(QStringLiteral("rad_checkBox"));

        horizontalLayout_3->addWidget(rad_checkBox);

        rad_checkBox_1 = new QCheckBox(groupBox_6);
        rad_checkBox_1->setObjectName(QStringLiteral("rad_checkBox_1"));
        rad_checkBox_1->setChecked(true);

        horizontalLayout_3->addWidget(rad_checkBox_1);


        gridLayout_5->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        groupBox_7 = new QGroupBox(PlotDialog);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(0, 0, 16, 16));
        gridLayout_6 = new QGridLayout(groupBox_7);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(2);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        checkBox_FADC0 = new QCheckBox(groupBox_7);
        checkBox_FADC0->setObjectName(QStringLiteral("checkBox_FADC0"));

        horizontalLayout_4->addWidget(checkBox_FADC0);

        fadc0color_pushButton = new QPushButton(groupBox_7);
        fadc0color_pushButton->setObjectName(QStringLiteral("fadc0color_pushButton"));
        fadc0color_pushButton->setMinimumSize(QSize(18, 18));
        fadc0color_pushButton->setMaximumSize(QSize(18, 18));
        fadc0color_pushButton->setFlat(true);

        horizontalLayout_4->addWidget(fadc0color_pushButton);


        verticalLayout_7->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        checkBox_FADC1 = new QCheckBox(groupBox_7);
        checkBox_FADC1->setObjectName(QStringLiteral("checkBox_FADC1"));

        horizontalLayout_5->addWidget(checkBox_FADC1);

        fadc1color_pushButton = new QPushButton(groupBox_7);
        fadc1color_pushButton->setObjectName(QStringLiteral("fadc1color_pushButton"));
        fadc1color_pushButton->setMinimumSize(QSize(18, 18));
        fadc1color_pushButton->setMaximumSize(QSize(18, 18));
        fadc1color_pushButton->setFlat(true);

        horizontalLayout_5->addWidget(fadc1color_pushButton);


        verticalLayout_7->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        checkBox_FADC2 = new QCheckBox(groupBox_7);
        checkBox_FADC2->setObjectName(QStringLiteral("checkBox_FADC2"));

        horizontalLayout_6->addWidget(checkBox_FADC2);

        fadc2color_pushButton = new QPushButton(groupBox_7);
        fadc2color_pushButton->setObjectName(QStringLiteral("fadc2color_pushButton"));
        fadc2color_pushButton->setMinimumSize(QSize(18, 18));
        fadc2color_pushButton->setMaximumSize(QSize(18, 18));
        fadc2color_pushButton->setFlat(true);

        horizontalLayout_6->addWidget(fadc2color_pushButton);


        verticalLayout_7->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        checkBox_FADC3 = new QCheckBox(groupBox_7);
        checkBox_FADC3->setObjectName(QStringLiteral("checkBox_FADC3"));

        horizontalLayout_7->addWidget(checkBox_FADC3);

        fadc3color_pushButton = new QPushButton(groupBox_7);
        fadc3color_pushButton->setObjectName(QStringLiteral("fadc3color_pushButton"));
        fadc3color_pushButton->setMinimumSize(QSize(18, 18));
        fadc3color_pushButton->setMaximumSize(QSize(18, 18));
        fadc3color_pushButton->setFlat(true);

        horizontalLayout_7->addWidget(fadc3color_pushButton);


        verticalLayout_7->addLayout(horizontalLayout_7);


        gridLayout_6->addLayout(verticalLayout_7, 0, 0, 1, 1);

        checkBox_Set = new QCheckBox(PlotDialog);
        checkBox_Set->setObjectName(QStringLiteral("checkBox_Set"));
        checkBox_Set->setGeometry(QRect(0, 0, 16, 16));
        checkBox_Delta = new QCheckBox(PlotDialog);
        checkBox_Delta->setObjectName(QStringLiteral("checkBox_Delta"));
        checkBox_Delta->setGeometry(QRect(0, 0, 89, 13));
        pushButton_2 = new QPushButton(PlotDialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(270, 200, 100, 30));

        retranslateUi(PlotDialog);

        QMetaObject::connectSlotsByName(PlotDialog);
    } // setupUi

    void retranslateUi(QDialog *PlotDialog)
    {
        PlotDialog->setWindowTitle(QApplication::translate("PlotDialog", "Dialog", 0));
        groupBox->setTitle(QApplication::translate("PlotDialog", "Chart background ", 0));
        groupBox_2->setTitle(QApplication::translate("PlotDialog", "\320\232\321\203\321\200\321\201\320\276\321\200\321\213", 0));
        checkBox_topC->setText(QApplication::translate("PlotDialog", "\320\222\320\265\321\200\321\205\320\275\320\270\320\271", 0));
        checkBox_midC->setText(QApplication::translate("PlotDialog", "\320\241\321\200\320\265\320\264\320\275\320\270\320\271", 0));
        checkBox_botC->setText(QApplication::translate("PlotDialog", "\320\235\320\270\320\266\320\275\320\270\320\271", 0));
        checkBox_Attach->setText(QApplication::translate("PlotDialog", "\320\237\321\200\320\270\320\262\321\217\320\267\320\272\320\260 \320\272 \321\202\320\276\320\272\321\203", 0));
        pushButton->setText(QApplication::translate("PlotDialog", "OK", 0));
        groupBox_3->setTitle(QApplication::translate("PlotDialog", "Channels and temperature", 0));
        checkBox_AllTemp->setText(QApplication::translate("PlotDialog", "\302\260C", 0));
        checkBox_1Temp->setText(QApplication::translate("PlotDialog", "1 \302\260C", 0));
        t1color_pushButton->setText(QString());
        checkBox_2Temp->setText(QApplication::translate("PlotDialog", "2 \302\260C", 0));
        t2color_pushButton->setText(QString());
        checkBox_3Temp->setText(QApplication::translate("PlotDialog", "3 \302\260C", 0));
        t3color_pushButton->setText(QString());
        checkBox_4Temp->setText(QApplication::translate("PlotDialog", "4 \302\260C", 0));
        t4color_pushButton->setText(QString());
        checkBox_5Temp->setText(QApplication::translate("PlotDialog", "5 \302\260C", 0));
        t5color_pushButton->setText(QString());
        checkBox_6Temp->setText(QApplication::translate("PlotDialog", "6 \302\260C", 0));
        t6color_pushButton->setText(QString());
        checkBox_AllTok->setText(QApplication::translate("PlotDialog", "Current", 0));
        checkBox_1Tok->setText(QApplication::translate("PlotDialog", "1 current", 0));
        c1color_pushButton->setText(QString());
        checkBox_2Tok->setText(QApplication::translate("PlotDialog", "2 current", 0));
        c2color_pushButton->setText(QString());
        checkBox_3Tok->setText(QApplication::translate("PlotDialog", "3 current", 0));
        c3color_pushButton->setText(QString());
        checkBox_4Tok->setText(QApplication::translate("PlotDialog", "4 current", 0));
        c4color_pushButton->setText(QString());
        checkBox_5Tok->setText(QApplication::translate("PlotDialog", "5 current", 0));
        c5color_pushButton->setText(QString());
        checkBox_6Tok->setText(QApplication::translate("PlotDialog", "6 current", 0));
        c6color_pushButton->setText(QString());
        groupBox_4->setTitle(QApplication::translate("PlotDialog", "\320\243\321\201\321\202\320\260\320\262\320\272\320\260", 0));
        checkBox_oldscale->setText(QApplication::translate("PlotDialog", "  \320\241\321\202\320\260\321\200\320\260\321\217 \321\210\320\272\320\260\320\273\320\260 \321\202\320\276\320\272\320\260", 0));
        groupBox_5->setTitle(QApplication::translate("PlotDialog", "Lid and radiator", 0));
        checkBox_Cap->setText(QApplication::translate("PlotDialog", "Lid", 0));
        lidcolor_pushButton->setText(QString());
        checkBox_Rad->setText(QApplication::translate("PlotDialog", "Radiator", 0));
        radcolor_pushButton->setText(QString());
        groupBox_6->setTitle(QApplication::translate("PlotDialog", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\321\217 \321\200\320\260\320\264\320\270\320\260\321\202\320\276\321\200\320\260", 0));
        rad_checkBox->setText(QApplication::translate("PlotDialog", "\320\246\320\265\320\273\321\213\320\265", 0));
        rad_checkBox_1->setText(QApplication::translate("PlotDialog", "\320\224\321\200\320\276\320\261\320\275\321\213\320\265", 0));
        groupBox_7->setTitle(QApplication::translate("PlotDialog", "FADC", 0));
        checkBox_FADC0->setText(QApplication::translate("PlotDialog", "0", 0));
        fadc0color_pushButton->setText(QString());
        checkBox_FADC1->setText(QApplication::translate("PlotDialog", "1", 0));
        fadc1color_pushButton->setText(QString());
        checkBox_FADC2->setText(QApplication::translate("PlotDialog", "2", 0));
        fadc2color_pushButton->setText(QString());
        checkBox_FADC3->setText(QApplication::translate("PlotDialog", "3", 0));
        fadc3color_pushButton->setText(QString());
        checkBox_Set->setText(QApplication::translate("PlotDialog", "\320\227\320\260\320\264\320\260\320\275\320\275\320\260\321\217", 0));
        checkBox_Delta->setText(QApplication::translate("PlotDialog", "\320\224\320\265\320\273\321\214\321\202\320\260", 0));
        pushButton_2->setText(QApplication::translate("PlotDialog", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class PlotDialog: public Ui_PlotDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOTDIALOG_H
