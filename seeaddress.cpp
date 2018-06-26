#include "seeaddress.h"
#include "ui_seeaddress.h"
#include"pagereplace.h"
#include"mainwindow.h"
#include<QDebug>
SeeAddress::SeeAddress(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SeeAddress)
{
    ui->setupUi(this);


}
void SeeAddress::getPageOrder(vector<int> input)
{
     //PageOrder = input;
     ui->tableWidget->setColumnCount(1);
     ui->tableWidget->setRowCount(256);
     ui->tableWidget->setColumnWidth(0,ui->tableWidget->width());
     int i;
     vector<int>::iterator it;
     for(it = input.begin(),i=0;it != input.end();it++,i++)
     {

         int num =  *it;
         qDebug()<<num;
         ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString("%1").arg(num)));
     }
     QStringList headers;
     headers << "Address List";
     ui->tableWidget->setHorizontalHeaderLabels(headers);
     ui->tableWidget->show();
     /*
     QStringList::iterator it;
     for(it = PageOrder.begin();it != PageOrder.end();it++){
         qDebug()<<*it;
     }
    */
}

SeeAddress::~SeeAddress()
{
    delete ui;
}
