#include "about.h"
#include "ui_about.h"

about::about(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::about)
{
    ui->setupUi(this);
    this->setWindowTitle("About DTCharts");
    this->setWindowFlags(Qt::Popup);
    this->setAttribute(Qt::WA_ShowModal);
    this->move(700,400);

    ui->closeButton->hide();
    ui->linkLabel->setText("<a href=\"https://www.dna-technology.com/\">www.dna-technology.com</a>");
    ui->linkLabel->setTextFormat(Qt::RichText);
    ui->linkLabel->setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui->linkLabel->setOpenExternalLinks(true);
}

about::~about()
{
    delete ui;
}

void about::closeEvent(QCloseEvent *e)
{
    on_closeButton_clicked();
    e->accept();
}

void about::on_closeButton_clicked()
{
    this->close();
}
