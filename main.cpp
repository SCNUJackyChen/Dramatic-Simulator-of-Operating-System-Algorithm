#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //SeeAddress sa;
    w.setWindowTitle("Page Replacement Algorithm");
    w.show();

    return a.exec();
}
