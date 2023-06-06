#ifndef JISHIQI_H
#define JISHIQI_H

#include <QWidget>
#include <QLabel>
#include <QTimer>
#include <QPixmap>
class jishiqi : public QWidget
{
public:
    explicit jishiqi(QWidget *parent = nullptr);
    QLabel *gewei = new QLabel(this);
    QLabel *shiwei = new QLabel(this);
    QLabel *baiwei = new QLabel(this);
    QPixmap getnum(int n);
    int process = 0;
    int num = 1;
    void chushihua();
    void getprocess(int &num){process = num;}
    QTimer *time = new QTimer(this);


};

#endif // JISHIQI_H
