#ifndef PAGEREPLACE_H
#define PAGEREPLACE_H
#include<iostream>
#include<stdio.h>
#include<time.h>
using namespace std;
struct order{
    int addr;
    int pageNum;
    order(int a,int p){addr=a;pageNum=p;}
    order(){addr=0;pageNum=0;}
};
class PageReplace{
protected:
    order* ad;
    int pageSize;
    int blockSize;
public:
    PageReplace();
    PageReplace(int ps, int bs);
    void init();
    void clear();
    order*& getAddress();
    int getPageSize();
    int getblockSize();
    //friend class MainWindow;
};
#endif // PAGEREPLACE_H
