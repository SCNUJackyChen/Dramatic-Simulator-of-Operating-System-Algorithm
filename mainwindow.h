#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<vector>
#include"pagereplace.h"
#include"seeaddress.h"
using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    PageReplace* getObj();
    void init();
    void creatTable();
    void setPage_32();
    void setPage_16();
    void setPage_8();
    void setPage_4();
    void setPage_2();
    void FIFO();
    void LRU();
    void OPT();
    //friend class SeeAddress;
    ~MainWindow();




private slots:
    void on_comboBox_activated(const QString &arg1);

    void on_comboBox_2_activated(const QString &arg1);

    void on_Generate_clicked();

    void on_Run_clicked();


    void on_SeeAddress_clicked();

    void on_SeePages_clicked();

private:
    Ui::MainWindow *ui;
    PageReplace* page_info;
    vector<int> PageOrder;
    vector<int> PageCache;
    vector<int> BlockCache;
    int currrent_pos;
    int interrupt_page;

};
#endif // MAINWINDOW_H

