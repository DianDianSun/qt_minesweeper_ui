#ifndef JILEIQI_H
#define JILEIQI_H

#include <QWidget>
#include <QLabel>
class jileiqi : public QWidget
{
public:
    explicit jileiqi(QWidget *parent = nullptr);
    QLabel *gewei = new QLabel(this);
    QLabel *shiwei = new QLabel(this);
    QLabel *baiwei = new QLabel(this);
    QPixmap getnum(int n);
    int bombnum = 0;
    void chushihua();
    void getbombnum(int &num){bombnum = num;}
    void gengxinshuju();
signals:

};

#endif // JILEIQI_H
