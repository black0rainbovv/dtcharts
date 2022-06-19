/********************************************************************************
** Form generated from reading UI file 'alarmwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALARMWINDOW_H
#define UI_ALARMWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_alarmwindow
{
public:
    QPushButton *pushButton;
    QFrame *frame;
    QLabel *label;

    void setupUi(QDialog *alarmwindow)
    {
        if (alarmwindow->objectName().isEmpty())
            alarmwindow->setObjectName(QStringLiteral("alarmwindow"));
        alarmwindow->resize(425, 205);
        pushButton = new QPushButton(alarmwindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(314, 150, 81, 31));
        frame = new QFrame(alarmwindow);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(-10, -10, 441, 221));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButton->raise();
        label = new QLabel(alarmwindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(16, 20, 391, 141));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(alarmwindow);

        QMetaObject::connectSlotsByName(alarmwindow);
    } // setupUi

    void retranslateUi(QDialog *alarmwindow)
    {
        alarmwindow->setWindowTitle(QApplication::translate("alarmwindow", "Dialog", 0));
        pushButton->setText(QApplication::translate("alarmwindow", "\320\236\320\272", 0));
        label->setText(QApplication::translate("alarmwindow", "\320\242\320\265\320\274\320\277\320\265\321\200\320\260\321\202\321\203\321\200\320\260 \320\274\320\260\321\202\321\200\320\270\321\206\321\213 \320\277\321\200\320\265\320\262\321\213\321\210\320\260\320\265\321\202 105\302\260C !!!", 0));
    } // retranslateUi

};

namespace Ui {
    class alarmwindow: public Ui_alarmwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALARMWINDOW_H
