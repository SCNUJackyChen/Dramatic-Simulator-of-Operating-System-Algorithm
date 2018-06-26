#ifndef SEEADDRESS_H
#define SEEADDRESS_H

#include <QWidget>
#include<vector>
using namespace std;
namespace Ui {
class SeeAddress;
}

class SeeAddress : public QWidget
{
    Q_OBJECT

public:
    explicit SeeAddress(QWidget *parent = 0);
    void getPageOrder(vector<int> input);
    ~SeeAddress();

private:
    Ui::SeeAddress *ui;

};

#endif // SEEADDRESS_H
