/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_about
{
public:
    QLabel *imageLabel;
    QLabel *nameLabel;
    QLabel *dnatchLabel;
    QLabel *linkLabel;
    QLabel *label;
    QLabel *label_2;
    QPushButton *closeButton;

    void setupUi(QDialog *about)
    {
        if (about->objectName().isEmpty())
            about->setObjectName(QStringLiteral("about"));
        about->resize(386, 173);
        about->setModal(true);
        imageLabel = new QLabel(about);
        imageLabel->setObjectName(QStringLiteral("imageLabel"));
        imageLabel->setGeometry(QRect(20, 10, 70, 70));
        imageLabel->setText(QStringLiteral(""));
        imageLabel->setTextFormat(Qt::AutoText);
        imageLabel->setPixmap(QPixmap(QString::fromUtf8(":/Res/Res/image.ico")));
        imageLabel->setScaledContents(true);
        nameLabel = new QLabel(about);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setGeometry(QRect(147, 10, 201, 41));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        nameLabel->setFont(font);
        dnatchLabel = new QLabel(about);
        dnatchLabel->setObjectName(QStringLiteral("dnatchLabel"));
        dnatchLabel->setGeometry(QRect(140, 50, 221, 31));
        QFont font1;
        font1.setPointSize(10);
        dnatchLabel->setFont(font1);
        linkLabel = new QLabel(about);
        linkLabel->setObjectName(QStringLiteral("linkLabel"));
        linkLabel->setGeometry(QRect(165, 77, 161, 21));
        linkLabel->setFont(font1);
        label = new QLabel(about);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(145, 105, 211, 31));
        QFont font2;
        font2.setPointSize(9);
        label->setFont(font2);
        label_2 = new QLabel(about);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(142, 127, 221, 21));
        label_2->setFont(font1);
        closeButton = new QPushButton(about);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setEnabled(false);
        closeButton->setGeometry(QRect(20, 110, 16, 16));

        retranslateUi(about);

        QMetaObject::connectSlotsByName(about);
    } // setupUi

    void retranslateUi(QDialog *about)
    {
        about->setWindowTitle(QApplication::translate("about", "Dialog", 0));
        nameLabel->setText(QApplication::translate("about", "DT Charts v1.4.4", 0));
        dnatchLabel->setText(QApplication::translate("about", "\302\251 2005-2022, \"DNA-Technology LLC\"", 0));
        linkLabel->setText(QApplication::translate("about", "www.dna-technology.com", 0));
        label->setText(QApplication::translate("about", "If you have any questions, contact us by", 0));
        label_2->setText(QApplication::translate("about", "by e-mail: service@dna-technology.ru", 0));
        closeButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class about: public Ui_about {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
