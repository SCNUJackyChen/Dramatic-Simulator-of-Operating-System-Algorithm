#ifndef SEEPAGE_H
#define SEEPAGE_H

#include <QWidget>
#include<vector>
using namespace std;
namespace Ui {
class seepage;
}

class seepage : public QWidget
{
    Q_OBJECT

public:
    explicit seepage(QWidget *parent = 0);
    void getPageCache(vector<int> input);
    ~seepage();

private:
    Ui::seepage *ui;
};

#endif // SEEPAGE_H
