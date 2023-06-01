#ifndef ZIDINGYI2_H
#define ZIDINGYI2_H

#include <QDialog>

namespace Ui {
class zidingyi2;
}

class zidingyi2 : public QDialog
{
    Q_OBJECT

public:
    explicit zidingyi2(QWidget *parent = nullptr);
    ~zidingyi2();
    int row;
    int col;
    int bomb;
    int panduan = 0;
private:
    Ui::zidingyi2 *ui;
};

#endif // ZIDINGYI2_H
