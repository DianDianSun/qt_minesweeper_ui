#include "jishiqi.h"
#include <QDebug>
jishiqi::jishiqi(QWidget *parent)
    : QWidget{parent}
{
    chushihua();
    this->move(0,21);
    setFixedSize(90,50);
    gewei->setFixedSize(30,50);
    gewei->move(60,0);
    shiwei->setFixedSize(30,50);
    shiwei->move(30,0);
    baiwei->setFixedSize(30,50);
    baiwei->move(0,0);
    time->setInterval(1000);
    connect(time, &QTimer::timeout, [=]() {
        int bai = num / 100;
        int shi = (num / 10) % 10;
        int ge = num % 10;
        baiwei->setPixmap(getnum(bai));
        shiwei->setPixmap(getnum(shi));
        gewei->setPixmap(getnum(ge));

        num++;
    });
}
void jishiqi::chushihua()
{
    num = 1;
    gewei->setPixmap(getnum(0));
    baiwei->setPixmap(getnum(0));
    shiwei->setPixmap(getnum(0));

}
QPixmap jishiqi::getnum(int n)
{
    switch(n)
    {
    case 1:
        return QPixmap(":/num/num1.png");
    case 2:
        return  QPixmap(":/num/num2.png");
    case 3:
        return  QPixmap(":/num/num3.png");
    case 4:
        return  QPixmap(":/num/num4.png");
    case 5:
        return  QPixmap(":/num/num5.png");
    case 6:
        return  QPixmap(":/num/num6.png");
    case 7:
        return  QPixmap(":/num/num7.png");
    case 8:
        return QPixmap(":/num/num8.png");
    case 9:
        return QPixmap(":/num/num9.png");
    case 0:
        return QPixmap(":/num/num0.png");

    }
}

