#include"pagereplace.h"
#include<QDebug>
#define random(a,b) (rand()%(b-a+1)+a)
PageReplace::PageReplace()
{
    ad = new order[256];
    pageSize=0;
    blockSize=0;
}
PageReplace::PageReplace(int ps, int bs)
{
    ad = new order[260];
    qDebug()<<"***********************generate******************";
    pageSize=ps;
   // qDebug()<<ps;
    blockSize=bs;
}
void PageReplace::init()
{
    //ad = new order[260];
    srand((unsigned)time(NULL));
    ad[0].addr = 10000;
    for(int i=1;i<=256;i++){
        int r=random(1,1025);
        if(r<=512 && ad[i-1].addr<=32767)
            ad[i].addr=ad[i-1].addr+1;
        else if(r>512 && r <=768)
            ad[i].addr=random(1,ad[i-1].addr);
        else{
            if(ad[i-1].addr>=32767){
                i--;
                continue;
            }
            ad[i].addr=random(ad[i-1].addr+2,32767);
        }
            ad[i].pageNum=ad[i].addr/pageSize;
       // qDebug()<<ad[i].addr;
    }
   qDebug()<<"**********************init******************";
}
void PageReplace::clear()
{
    delete ad;
    ad = new order[260];
    pageSize = 0;
    blockSize = 0;
}

order*& PageReplace::getAddress()
{
    return ad;
}
int PageReplace::getPageSize()
{
    return pageSize;
}
int PageReplace::getblockSize()
{
    return  blockSize;
}
