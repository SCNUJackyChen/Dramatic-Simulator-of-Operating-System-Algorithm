#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"pagereplace.h"
#include"seeaddress.h"
#include"seepage.h"
#include<QComboBox>
#include<QDebug>
#include<QMessageBox>
#define random(x) (rand()%x)
#define random(x,y) (rand()%(y-x)+x)


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}
PageReplace* MainWindow::getObj()
{
    return page_info;
}

void MainWindow::init()
{
    //setPage_32();


    QString c = ui->comboBox->currentText();
    //qDebug()<<c;
    if(c == "1K") setPage_32();
    else if(c == "2K") setPage_16();
    else if(c == "4K") setPage_8();
    else if(c == "8K") setPage_4();
    else setPage_2();
}
void MainWindow::creatTable()
{
    QString row = ui->comboBox_2->currentText();
    int r = row.toInt();
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(1);
    ui->tableWidget->setRowCount(r);
    if(r>12)
        ui->tableWidget->setColumnWidth(0,135);
    else
        ui->tableWidget->setColumnWidth(0,ui->tableWidget->width());
    QStringList headers;
    headers << "Cache Pages";
    ui->tableWidget->setHorizontalHeaderLabels(headers);
}

void MainWindow::setPage_32()
{
    ui->comboBox_2->clear();
    for(int i=1;i<=32;i++)
    {
        int input = i;
        QString str = QString::number(input);
        ui->comboBox_2->addItem(str);
    }


}
void MainWindow::setPage_16()
{
    ui->comboBox_2->clear();
    for(int i=1;i<=16;i++)
    {
        int input = i;
        QString str = QString::number(input);
        ui->comboBox_2->addItem(str);
    }


}
void MainWindow::setPage_8()
{
    ui->comboBox_2->clear();
    for(int i=1;i<=8;i++)
    {
        int input = i;
        QString str = QString::number(input);
        ui->comboBox_2->addItem(str);
    }


}
void MainWindow::setPage_4()
{
    ui->comboBox_2->clear();
    for(int i=1;i<=4;i++)
    {
        int input = i;
        QString str = QString::number(input);
        ui->comboBox_2->addItem(str);
    }


}
void MainWindow::setPage_2()
{
    ui->comboBox_2->clear();
    for(int i=1;i<=2;i++)
    {
        int input = i;
        QString str = QString::number(input);
        ui->comboBox_2->addItem(str);
    }



}
void MainWindow::FIFO()
{
    qDebug()<<"***********FIFO*************";
    int num;
    vector<int>::iterator p;
    p = PageCache.begin()+currrent_pos;
    p--;
    ui->PassedPage->display(*p);
    p++;
    ui->CurrentPage->display(*p);
    p++;
    ui->ComingPage->display(*p);
    p--;


        bool flag = 0;
        for(vector<int>::iterator it = BlockCache.begin();it!=BlockCache.end();it++){
            if(*it == *p) {
                flag = 1;
                break;
            }
        }

        if(!flag){
            //qDebug()<<1;
            interrupt_page++;
            ui->tableWidget->clear();
            if(BlockCache.size() < ui->tableWidget->rowCount())
            {
                vector<int>::iterator head = BlockCache.begin();
                BlockCache.insert(head,*p);
                //qDebug()<<1;

            }
            else{
                vector<int>::iterator tail = BlockCache.end()-1;
                vector<int>::iterator head = BlockCache.begin();
                BlockCache.erase(tail);
                BlockCache.insert(head,*p);

            }
            int k=0;
            for(vector<int>::iterator i = BlockCache.begin();i!=BlockCache.end();i++){
                num = *i;
                ui->tableWidget->setItem(k++,0,new QTableWidgetItem(QString("%1").arg(num)));

            }
            QStringList headers;
            headers << "Cache Pages";
            ui->tableWidget->setHorizontalHeaderLabels(headers);
            ui->tableWidget->show();

        }else{
            return;
        }



}
void MainWindow::LRU()
{
    qDebug()<<"***********LRU*************";
    int num;
    vector<int>::iterator p;
    p = PageCache.begin()+currrent_pos;
    p--;
    ui->PassedPage->display(*p);
    p++;
    ui->CurrentPage->display(*p);
    p++;
    ui->ComingPage->display(*p);
    p--;

    bool flag = 0;
    vector<int>::iterator it;
    for(it = BlockCache.begin();it!=BlockCache.end();it++){
        if(*it == *p) {
            flag = 1;
            break;
        }
    }
    if(!flag){
        //qDebug()<<1;
        interrupt_page++;
        ui->tableWidget->clear();
        if(BlockCache.size() < ui->tableWidget->rowCount())
        {
            vector<int>::iterator head = BlockCache.begin();
            BlockCache.insert(head,*p);
            //qDebug()<<1;

        }
        else{
            vector<int>::iterator tail = BlockCache.end()-1;
            vector<int>::iterator head = BlockCache.begin();
            BlockCache.erase(tail);
            BlockCache.insert(head,*p);

        }
        int k=0;
        for(vector<int>::iterator i = BlockCache.begin();i!=BlockCache.end();i++){
            num = *i;
            ui->tableWidget->setItem(k++,0,new QTableWidgetItem(QString("%1").arg(num)));

        }
        QStringList headers;
        headers << "Cache Pages";
        ui->tableWidget->setHorizontalHeaderLabels(headers);
        ui->tableWidget->show();

    }else{
        ui->tableWidget->clear();
        int top = *it;
        BlockCache.erase(it);
        BlockCache.insert(BlockCache.begin(),top);
        int k=0;
        for(vector<int>::iterator i = BlockCache.begin();i!=BlockCache.end();i++){
            num = *i;
            ui->tableWidget->setItem(k++,0,new QTableWidgetItem(QString("%1").arg(num)));

        }
        QStringList headers;
        headers << "Cache Pages";
        ui->tableWidget->setHorizontalHeaderLabels(headers);
        ui->tableWidget->show();
    }

}
void MainWindow::OPT()
{
    qDebug()<<"***********OPT*************";
    int num;
    vector<int>::iterator p;
    p = PageCache.begin()+currrent_pos;
    p--;
    ui->PassedPage->display(*p);
    p++;
    ui->CurrentPage->display(*p);
    p++;
    ui->ComingPage->display(*p);
    p--;

    bool flag = 0;
    vector<int>::iterator it;
    for(it = BlockCache.begin();it!=BlockCache.end();it++){
        if(*it == *p) {
            flag = 1;
            break;
        }
    }
    if(!flag){
        //qDebug()<<1;
        interrupt_page++;
        ui->tableWidget->clear();
        if(BlockCache.size() < ui->tableWidget->rowCount())
        {
            vector<int>::iterator head = BlockCache.begin();
            BlockCache.insert(head,*p);
            //qDebug()<<1;

        }
        else{
            vector<int>::iterator i,j,pos;
            int dis,max=0;

            for(i = BlockCache.begin();i!=BlockCache.end();i++)
            {
                dis = 0;
                for(j = p;j!=PageCache.end();j++)
                {
                    if(*j!=*i) dis++;
                    else break;
                }
                if(j==PageCache.end()){
                    pos = i;
                    break;
                }

                if(dis>max){
                    max = dis;
                    pos = i;
                }
            }
            BlockCache.erase(pos);
            BlockCache.insert(BlockCache.begin(),*p);

        }
        int k=0;
        for(vector<int>::iterator i = BlockCache.begin();i!=BlockCache.end();i++){
            num = *i;
            ui->tableWidget->setItem(k++,0,new QTableWidgetItem(QString("%1").arg(num)));

        }
        QStringList headers;
        headers << "Cache Pages";
        ui->tableWidget->setHorizontalHeaderLabels(headers);
        ui->tableWidget->show();

    }else{
        return;
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_comboBox_activated(const QString &arg1)
{
    init();
}

void MainWindow::on_comboBox_2_activated(const QString &arg1)
{
    creatTable();
}

void MainWindow::on_Generate_clicked()
{

    currrent_pos = 1;
    interrupt_page = 1;
    PageOrder.clear();
    PageCache.clear();
    BlockCache.clear();
    ui->tableWidget->clear();
    ui->ComingPage->display(0);
    ui->PassedPage->display(0);
    //delete page_info;
    //qDebug()<<"***********************succussful******************";
    QString pagesize = ui->comboBox->currentText();
    QString blocksize = ui->comboBox_2->currentText();
    int ps,bs;
    if(pagesize == "1K") ps=1024;
    else if(pagesize == "2K") ps=1024*2;
    else if(pagesize == "4K") ps=1024*4;
    else if(pagesize == "8K") ps=1024*8;
    else if(pagesize == "16K") ps=1024*16;
    bs = blocksize.toInt();
    page_info = new PageReplace(ps,bs);
    qDebug()<<"***********************succussful******************";
    page_info->init();


    order* sequence = page_info->getAddress();
    PageCache.push_back(sequence[1].pageNum);
    PageOrder.push_back(sequence[1].addr);
    for(int i=2;i<=256;i++)
    {

        PageOrder.push_back(sequence[i].addr);
        if(sequence[i].pageNum == sequence[i-1].pageNum)
            continue;
        else PageCache.push_back(sequence[i].pageNum);
    }
    vector<int>::iterator it = PageCache.begin();
    BlockCache.push_back(*it);
    int num = *it;
    ui->tableWidget->setItem(0,0,new QTableWidgetItem(QString("%1").arg(num)));
    QStringList headers;
    headers << "Cache Pages";
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->CurrentPage->display(*it);
    ui->interruptRate->setText(QString("100"));
    /*while(it!=PageCache.end())
    {
        qDebug()<<*it;
        it++;
    }
    */

    /*
    for(int i=0;i<bs;i++)
    {
        int num = *it;
        qDebug()<<num;
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString("%1").arg(num)));
        it++;i
    }
    ui->tableWidget->show();
    */


}
void MainWindow::on_Run_clicked()
{
    if(currrent_pos == PageCache.size()){
        QString str = "Sorry! All pages have been scheduled and the replacing process is over!";
        QMessageBox::warning(NULL, "No page!", str,QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        return;
    }
    if(ui->FIFO->isChecked()) FIFO();
    else if(ui->LRU->isChecked()) LRU();
    else if(ui->OPT->isChecked()) OPT();
    currrent_pos++;
    qDebug()<<"!!!!!!!!!!!!!!!!!"<<interrupt_page;
    double rate = interrupt_page*100/currrent_pos;
    ui->interruptRate->setText(QString::number(rate,10,2));
}


void MainWindow::on_SeeAddress_clicked()
{
    SeeAddress* sa;
    sa = new SeeAddress;

    //SeeAddress sa;
    sa->getPageOrder(PageOrder);
    sa->show();

}

void MainWindow::on_SeePages_clicked()
{
    seepage* sp;
    sp = new seepage;
    sp->getPageCache(PageCache);
    sp->show();
}
