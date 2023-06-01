#ifndef MAINUI_H
#define MAINUI_H

#include <QGraphicsView>
#include <QPainter>
#include <QMouseEvent>
#include <QtGlobal>
#include <QTime>
#include <QScreen>
#include <QDebug>
#include <QWidget>
class my_chart
{
public:
    char dian;
    char sign;
    char bomb;
};
class mainui : public QWidget
{
public:
    explicit mainui(QWidget *parent = nullptr);
    my_chart chart[24][30];
    int process = 0;
    int firstclick = 0;
    int fenleicishu = 0;
    int row = 9;
    int col = 9;
    int bombnum = 10;
    int remainbomb = bombnum;
    int pifu = 0;
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *ev);
    QPixmap topicture(char ch);
    void Print_chart(QPainter &paint);
    void Left_click(int &x,int &y);
    void Right_click(int &x,int &y);
    int Calculate_bombnum(int &x, int &y);
    void L_and_R_click(int &x,int &y);
    void Double_click(int &x,int &y);
    void Chushihua();
    void Avoidfirstfail(int &xx,int &yy);
    void Puanduanshengli();

signals:

};

#endif // MAINUI_H
