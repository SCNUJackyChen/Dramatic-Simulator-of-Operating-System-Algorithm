#include "seepage.h"
#include "ui_seepage.h"

seepage::seepage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::seepage)
{
    ui->setupUi(this);
}
void seepage::getPageCache(vector<int> input)
{
     //PageOrder = input;
     ui->tableWidget->setColumnCount(1);
     int n = input.size();
     ui->tableWidget->setRowCount(n);
     ui->tableWidget->setColumnWidth(0,ui->tableWidget->width());
     int i;
     vector<int>::iterator it;
     for(it = input.begin(),i=0;it != input.end();it++,i++)
     {

         int num =  *it;
         //qDebug()<<num;
         ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString("%1").arg(num)));
     }
     QStringList headers;
     headers << "Pages List";
     ui->tableWidget->setHorizontalHeaderLabels(headers);
     ui->tableWidget->show();
     /*
     QStringList::iterator it;
     for(it = PageOrder.begin();it != PageOrder.end();it++){
         qDebug()<<*it;
     }
    */
}
seepage::~seepage()
{
    delete ui;
}
