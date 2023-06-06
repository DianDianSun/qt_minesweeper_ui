#include "jileiqi.h"

jileiqi::jileiqi(QWidget *parent)
    : QWidget{parent}
{
    chushihua();
    setFixedSize(90,50);
    gewei->setFixedSize(30,50);
    gewei->move(60,0);
    shiwei->setFixedSize(30,50);
    shiwei->move(30,0);
    baiwei->setFixedSize(30,50);
    baiwei->move(0,0);

}
QPixmap jileiqi::getnum(int n)
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
void jileiqi::chushihua()
{
    baiwei->setPixmap(getnum(0));
    shiwei->setPixmap(getnum(0));
    gewei->setPixmap(getnum(0));
}
void jileiqi::gengxinshuju()
{
    int bai = bombnum / 100;
    int shi = (bombnum / 10) % 10;
    int ge = bombnum % 10;
    baiwei->setPixmap(getnum(bai));
    shiwei->setPixmap(getnum(shi));
    gewei->setPixmap(getnum(ge));
}
