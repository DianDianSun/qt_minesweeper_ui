#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QDebug>
namespace Ui {
class MainWindow;
}
class my_chart
{
public:
    char dian;
    char sign;
    char bomb;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    my_chart chart[24][30];
    int row = 9;
    int col = 9;
    int bombnum = 10;
    int remainbomb = bombnum;
    int process = 0;
    int firstclick = 0;
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *ev);
    QPixmap topicture(char ch);
    void Choose_mode(Ui::MainWindow *ui);
    void Print_chart(QPainter &paint);
    void Left_click(int &x,int &y);
    void Right_click(int &x,int &y);
    int Calculate_bombnum(int &x, int &y);
    void L_and_R_click(int &x,int &y);
    void Double_click(int &x,int &y);
    void Chushihua();
    void Avoidfirstfail(int &xx,int &yy);
    void Choosechuji(){row = 9;col = 9;bombnum = 10;remainbomb = bombnum;}
    void Choosezhongji(){row = 16;col = 16;bombnum = 40;remainbomb = bombnum;}
    void Choosegaoji(){row = 16;col = 30;bombnum = 99;remainbomb = bombnum;}


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
