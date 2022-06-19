#include <QClipboard>
#include <QDebug>
#include "termcycledialog.h"
#include "ui_termcycledialog.h"

termcycledialog::termcycledialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::termcycledialog)
{
    ui->setupUi(this);
}

termcycledialog::~termcycledialog()
{
    delete ui;
}

void termcycledialog::SetTable(QStringList params)
{
    this->setWindowTitle("Данные Энергоемкости");
    if(params.size() > 12)
        this->setFixedSize(330, 12*25+30);
    else
        this->setFixedSize(330, (params.size()+2)*25+30);
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setRowCount(params.size()+1);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    QTableWidgetItem *q1 = new QTableWidgetItem();
    q1->setText("Цикл №");
    q1->setTextAlignment(Qt::AlignCenter);
    q1->setBackground(Qt::gray);
    q1->setFont(QFont("MS Shell", 10));
    ui->tableWidget->setItem(0, 0, q1);
    QTableWidgetItem *q2 = new QTableWidgetItem();
    q2->setText("+");
    q2->setTextAlignment(Qt::AlignCenter);
    q2->setBackground(Qt::red);
    q2->setFont(QFont("MS Shell", 12));
    ui->tableWidget->setItem(0, 1, q2);
    QTableWidgetItem *q3 = new QTableWidgetItem();
    q3->setText("-");
    q3->setTextAlignment(Qt::AlignCenter);
    q3->setBackground(Qt::blue);
    q3->setFont(QFont("MS Shell", 12));
    ui->tableWidget->setItem(0, 2, q3);
    QTableWidgetItem *q4 = new QTableWidgetItem();
    q4->setText("Дельта");
    q4->setTextAlignment(Qt::AlignCenter);
    q4->setBackground(Qt::lightGray);
    q4->setFont(QFont("MS Shell", 10));
    ui->tableWidget->setItem(0, 3, q4);

    QHeaderView *hheaderView = new QHeaderView(Qt::Horizontal, ui->tableWidget);
    QHeaderView *vheaderView = new QHeaderView(Qt::Vertical, ui->tableWidget);
    ui->tableWidget->setVerticalHeader(vheaderView);
    ui->tableWidget->setHorizontalHeader(hheaderView);
    ui->tableWidget->horizontalHeader()->hide();
    ui->tableWidget->verticalHeader()->hide();
    vheaderView->resizeSection(0, 25);
    for(int i=1; i<params.size()+1; i++)
    {
        vheaderView->setSectionResizeMode(i, QHeaderView::Stretch);
    }
    hheaderView->resizeSection(0, 80);
    hheaderView->setSectionResizeMode(1, QHeaderView::Stretch);
    hheaderView->setSectionResizeMode(2, QHeaderView::Stretch);;
    hheaderView->setSectionResizeMode(3, QHeaderView::Stretch);;
    for(int i=0; i<params.size(); i++)
    {
        QTableWidgetItem *qc = new QTableWidgetItem();
        QTableWidgetItem *qp = new QTableWidgetItem();
        QTableWidgetItem *qm = new QTableWidgetItem();
        QTableWidgetItem *qd = new QTableWidgetItem();
        qc->setTextAlignment(Qt::AlignCenter);
        qp->setTextAlignment(Qt::AlignCenter);
        qm->setTextAlignment(Qt::AlignCenter);
        qd->setTextAlignment(Qt::AlignCenter);
        qc->setText(params[i].split(" ")[0]);
        qp->setText(params[i].split(" ")[1]);
        qm->setText(params[i].split(" ")[2]);
        qd->setText(params[i].split(" ")[3]);
        qc->setBackground(Qt::lightGray);
        ui->tableWidget->setItem(i+1, 0, qc);
        ui->tableWidget->setItem(i+1, 1, qp);
        ui->tableWidget->setItem(i+1, 2, qm);
        ui->tableWidget->setItem(i+1, 3, qd);
    }

    ui->tableWidget->setContextMenuPolicy(Qt::ActionsContextMenu);
    QAction *a1 = new QAction("Копировать", this);
    ui->tableWidget->addAction(a1);
    ui->tableWidget->connect(a1, SIGNAL(triggered()), this, SLOT(CopySelected()));
}

void termcycledialog::CopySelected()
{
    QString cbStr;
    QClipboard *cb = QApplication::clipboard();
    QModelIndexList list =  ui->tableWidget->selectionModel()->selectedIndexes();
    int i, j, firstRow, lastRow, firstCol, lastCol, rowCount, colCount;

    if( list.isEmpty() ) return;

    firstRow = list.first().row();  lastRow = list.last().row();
    rowCount = lastRow - firstRow + 1;
    firstCol = list.first().column(); lastCol = list.last().column();
    colCount = lastCol - firstCol + 1;

    for(i = 0; i < rowCount; i++, cbStr += '\n')
    {
        for(j = i*colCount; j < (i+1)*colCount; j ++, cbStr += '\t')
        {
            cbStr += ui->tableWidget->model()->data(list[ j ], Qt::EditRole).toString().replace(".", ",");
        }
    }
    cb->setText(cbStr);
    qDebug() << " ";
}









