/********************************************************************************
** Form generated from reading UI file 'termcycledialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TERMCYCLEDIALOG_H
#define UI_TERMCYCLEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_termcycledialog
{
public:
    QGridLayout *gridLayout;
    QTableWidget *tableWidget;

    void setupUi(QDialog *termcycledialog)
    {
        if (termcycledialog->objectName().isEmpty())
            termcycledialog->setObjectName(QStringLiteral("termcycledialog"));
        termcycledialog->resize(336, 262);
        gridLayout = new QGridLayout(termcycledialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tableWidget = new QTableWidget(termcycledialog);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        gridLayout->addWidget(tableWidget, 0, 0, 1, 1);


        retranslateUi(termcycledialog);

        QMetaObject::connectSlotsByName(termcycledialog);
    } // setupUi

    void retranslateUi(QDialog *termcycledialog)
    {
        termcycledialog->setWindowTitle(QApplication::translate("termcycledialog", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class termcycledialog: public Ui_termcycledialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TERMCYCLEDIALOG_H
