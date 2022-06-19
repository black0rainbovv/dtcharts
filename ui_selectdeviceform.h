/********************************************************************************
** Form generated from reading UI file 'selectdeviceform.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTDEVICEFORM_H
#define UI_SELECTDEVICEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_selectdeviceform
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *listLabel;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *deviceListWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *connectButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *selectdeviceform)
    {
        if (selectdeviceform->objectName().isEmpty())
            selectdeviceform->setObjectName(QStringLiteral("selectdeviceform"));
        selectdeviceform->setWindowModality(Qt::ApplicationModal);
        selectdeviceform->resize(279, 200);
        selectdeviceform->setMinimumSize(QSize(260, 190));
        selectdeviceform->setMaximumSize(QSize(16777215, 16777215));
        selectdeviceform->setSizeGripEnabled(false);
        selectdeviceform->setModal(true);
        verticalLayoutWidget = new QWidget(selectdeviceform);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 261, 181));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        listLabel = new QLabel(verticalLayoutWidget);
        listLabel->setObjectName(QStringLiteral("listLabel"));
        QFont font;
        font.setPointSize(10);
        listLabel->setFont(font);

        verticalLayout->addWidget(listLabel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        deviceListWidget = new QListWidget(verticalLayoutWidget);
        deviceListWidget->setObjectName(QStringLiteral("deviceListWidget"));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        QBrush brush2(QColor(127, 127, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush2);
        QBrush brush3(QColor(170, 170, 170, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        QBrush brush4(QColor(255, 255, 220, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        deviceListWidget->setPalette(palette);
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        font1.setStrikeOut(false);
        deviceListWidget->setFont(font1);
        deviceListWidget->setLineWidth(100);
        deviceListWidget->setMidLineWidth(0);
        deviceListWidget->setTextElideMode(Qt::ElideMiddle);
        deviceListWidget->setMovement(QListView::Static);
        deviceListWidget->setLayoutMode(QListView::SinglePass);
        deviceListWidget->setSpacing(3);
        deviceListWidget->setGridSize(QSize(20, 20));
        deviceListWidget->setModelColumn(0);
        deviceListWidget->setBatchSize(100);

        horizontalLayout_2->addWidget(deviceListWidget);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        connectButton = new QPushButton(verticalLayoutWidget);
        connectButton->setObjectName(QStringLiteral("connectButton"));
        connectButton->setFont(font);

        horizontalLayout->addWidget(connectButton);

        cancelButton = new QPushButton(verticalLayoutWidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setFont(font);

        horizontalLayout->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(selectdeviceform);

        QMetaObject::connectSlotsByName(selectdeviceform);
    } // setupUi

    void retranslateUi(QDialog *selectdeviceform)
    {
        selectdeviceform->setWindowTitle(QApplication::translate("selectdeviceform", "Dialog", 0));
        listLabel->setText(QApplication::translate("selectdeviceform", "List of devices:", 0));
        connectButton->setText(QApplication::translate("selectdeviceform", "Connect", 0));
        cancelButton->setText(QApplication::translate("selectdeviceform", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class selectdeviceform: public Ui_selectdeviceform {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTDEVICEFORM_H
