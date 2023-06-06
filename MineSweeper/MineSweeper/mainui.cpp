#include "mainui.h"
#include <QDebug>
#include <QPixmap>
#include <QRect>
mainui::mainui(QWidget *parent)
    : QWidget{parent}
{
    Chushihua();
    this->move(0,71);
}
void mainui::paintEvent(QPaintEvent *)
{

    QPainter paint(this);
    setFixedSize(col*32,row*32);
    Print_chart(paint);
}
void mainui::timerEvent(QTimerEvent *ev)
{
    if(timebegin == 1)
    {
        update();
        killTimer(Timer);

    }
}
void mainui::mousePressEvent(QMouseEvent *ev)
{
    int xxx = ev->y()/32;
    int yyy = ev->x()/32;
    if(firstclick++ == 0)
    {
        emit jishiqistart();
        Avoidfirstfail(xxx,yyy);
    }
    if(ev->button() == Qt::LeftButton&&ev->button() != Qt::RightButton&&process == 0)
    {
        L_and_R_click(xxx,yyy);
        Left_click(xxx,yyy);
        Puanduanshengli();
        update();
    }
    else if(ev->button() == Qt::RightButton&&ev->button() != Qt::LeftButton&&process == 0)
    {
        Right_click(xxx,yyy);
        update();
        Puanduanshengli();
    }
    else if(ev->button() == Qt::RightButton&&ev->button() == Qt::LeftButton&&process == 0)
    {
        L_and_R_click(xxx,yyy);
        update();
        Puanduanshengli();
    }

}
QPixmap mainui::topicture(char ch)
{
    switch(pifu)
    {
    case 0:
        switch (ch)
        {
        case '0':
            return QPixmap(":/classictheme/zero.png");
        case '1':
            return QPixmap(":/classictheme/one.png");
        case '2':
            return QPixmap(":/classictheme/two.png");
        case '3':
            return QPixmap(":/classictheme/three.png");
        case '4':
            return QPixmap(":/classictheme/four.png");
        case '5':
            return QPixmap(":/classictheme/five.png");
        case '6':
            return QPixmap(":/classictheme/six.png");
        case '7':
            return QPixmap(":/classictheme/seven.png");
        case '8':
            return QPixmap(":/classictheme/eight.png");
        case '.':
            return QPixmap(":/classictheme/kong.png");
        case '*':
            return QPixmap(":/classictheme/bomb.png");
        case '!':
            return QPixmap(":/classictheme/biaolei.png");
        case '?':
            return QPixmap(":/classictheme/biaowen.png");
        case 'n':
            return QPixmap(":/classictheme/biaocuo.png");
        case 't':
            return QPixmap(":/classictheme/toushi.png");
        case 'b':
            return QPixmap(":/classictheme/baozha.png");
        case 'x':
            return QPixmap(":/classictheme/ximie.png");
        default:
            return QPixmap(":/classictheme/baozha.png");
        }
    case 1:
        switch (ch)
        {
        case '0':
            return QPixmap(":/ikuntheme/zero.png");
        case '1':
            return QPixmap(":/ikuntheme/one.png");
        case '2':
            return QPixmap(":/ikuntheme/two.png");
        case '3':
            return QPixmap(":/ikuntheme/three.png");
        case '4':
            return QPixmap(":/ikuntheme/four.png");
        case '5':
            return QPixmap(":/ikuntheme/five.png");
        case '6':
            return QPixmap(":/ikuntheme/six.png");
        case '7':
            return QPixmap(":/ikuntheme/seven.png");
        case '8':
            return QPixmap(":/ikuntheme/eight.png");
        case '.':
            return QPixmap(":/ikuntheme/kong.png");
        case '*':
            return QPixmap(":/ikuntheme/baozha.png");
        case '!':
            return QPixmap(":/ikuntheme/biaolei.png");
        case '?':
            return QPixmap(":/ikuntheme/biaowen.png");
        case 't':
            return QPixmap(":/ikuntheme/toushi.png");
        case 'b':
            return QPixmap(":/classictheme/baozha.png");
        case 'x':
            return QPixmap(":/classictheme/bomb.png");
        default:
            return QPixmap(":/ikuntheme/baozha.png");
        }
    case 2:
        switch (ch)
        {
        case '0':
            return QPixmap(":/pinktheme/zero.png");
        case '1':
            return QPixmap(":/pinktheme/one.png");
        case '2':
            return QPixmap(":/pinktheme/two.png");
        case '3':
            return QPixmap(":/pinktheme/three.png");
        case '4':
            return QPixmap(":/pinktheme/four.png");
        case '5':
            return QPixmap(":/pinktheme/five.png");
        case '6':
            return QPixmap(":/pinktheme/six.png");
        case '7':
            return QPixmap(":/pinktheme/seven.png");
        case '8':
            return QPixmap(":/pinktheme/eight.png");
        case '.':
            return QPixmap(":/pinktheme/kong.png");
        case '*':
            return QPixmap(":/pinktheme/bomb.png");
        case '!':
            return QPixmap(":/pinktheme/biaolei.png");
        case '?':
            return QPixmap(":/pinktheme/biaowen.png");
        case 'n':
            return QPixmap(":/pinktheme/biaocuo.png");
        case 't':
            return QPixmap(":/pinktheme/toushi.png");
        case 'B':
            return QPixmap(":/pinktheme/baozha.png");
        case 'b':
            return QPixmap(":/pinktheme/baozha1.png");
        case 'N':
            return QPixmap(":/pinktheme/baozha2.png");
        case 'x':
            return QPixmap(":/pinktheme/ximie.png");
        case 'z':
            return QPixmap(":/pinktheme/ximie1.png");
        case 'X':
            return QPixmap(":/pinktheme/ximie2.png");
        default:
            return QPixmap(":/pinktheme/baozha.png");
        }
    case 3:
        switch (ch)
        {
        case '0':
            return QPixmap(":/greentheme/zero.png");
        case '1':
            return QPixmap(":/greentheme/one.png");
        case '2':
            return QPixmap(":/greentheme/two.png");
        case '3':
            return QPixmap(":/greentheme/three.png");
        case '4':
            return QPixmap(":/greentheme/four.png");
        case '5':
            return QPixmap(":/greentheme/five.png");
        case '6':
            return QPixmap(":/greentheme/six.png");
        case '7':
            return QPixmap(":/greentheme/seven.png");
        case '8':
            return QPixmap(":/greentheme/eight.png");
        case '.':
            return QPixmap(":/greentheme/kong.png");
        case '*':
            return QPixmap(":/greentheme/bomb.png");
        case '!':
            return QPixmap(":/greentheme/biaolei.png");
        case '?':
            return QPixmap(":/greentheme/biaowen.png");
        case 'n':
            return QPixmap(":/greentheme/biaocuo.png");
        case 't':
            return QPixmap(":/greentheme/toushi.png");
        case 'b':
            return QPixmap(":/greentheme/baozha.png");
        case 'x':
            return QPixmap(":/greentheme/ximie.png");
        default:
            return QPixmap(":/greentheme/baozha.png");
        }
    }
}
void mainui::Print_chart(QPainter &paint)
{
    int x = 0,y = 0;
    switch(process)
    {
    case 0:
        for(int i = 0;i < row;i++,y+=32)
        {
            for(int j = 0;j < col;j++,x+=32)
            {
                if(toushi == 1&&chart[i][j].bomb == '*'){
                    paint.drawPixmap(x,y,mainui::topicture('t'));
                    continue;
                }
                if(chart[i][j].sign != '0'&&chart[i][j].dian == '.')
                {
                    paint.drawPixmap(x,y,mainui::topicture(chart[i][j].sign));

                }
                else
                {
                    paint.drawPixmap(x,y,mainui::topicture(chart[i][j].dian));
                }
            }
            x=0;
        }
        break;
    default:
        emit youxichange();
        for(int i = 0;i < row;i++,x = 0,y+=32)
        {
            for(int j = 0;j < col;j++,x+=32)
            {
                if(chart[i][j].bomb == '*'&&timebegin == 0)
                {
                    paint.drawPixmap(x,y,mainui::topicture(chart[i][j].bomb));
                }else if(timebegin == 1&&chart[i][j].bomb == '*'&&process == 1){
                    paint.drawPixmap(x,y,mainui::topicture('B'));

            }else if(timebegin == 1&&chart[i][j].bomb == '*'&&process == 2){
                    paint.drawPixmap(x,y,mainui::topicture('x'));
                }
                else if(chart[i][j].sign != '0')
                {
                    if(chart[i][j].sign == '!'&&chart[i][j].bomb == '0')
                    {
                        paint.drawPixmap(x,y,mainui::topicture('n'));
                    }else
                    paint.drawPixmap(x,y,mainui::topicture(chart[i][j].sign));
                }else
                {
                    paint.drawPixmap(x,y,mainui::topicture(chart[i][j].dian));
                }
            }
        }
        Timer = startTimer(1000);
        timebegin = 1;
    }
}
void mainui::Left_click(int &x,int &y)
{
    if(x < 0||x >= row||y < 0||y >= col)
    {
        return;
    }
    if(chart[x][y].dian != '.'||chart[x][y].sign == '!')
    {
        return;
    }
    if(chart[x][y].bomb == '*')
    {
        process = 1;
        return;
    }
    int around_minesnum = Calculate_bombnum(x, y);
    if(around_minesnum != 0)
    {
        chart[x][y].dian ='0' + around_minesnum ;
        chart[x][y].sign ='0';
    }else if(around_minesnum == 0)
    {
        chart[x][y].dian ='0';
        for(int i = x - 1;i <= x + 1;i++)
        {
            for(int j = y - 1;j <= y + 1;j++)
            {
                if(i< 0||i >= row||j < 0||j >= col)
                {
                    continue;
                }
                mainui::Left_click(i, j);
            }
        }
    }

}
int mainui::Calculate_bombnum(int &x,int &y)
{
    int num = 0;
    for(int i = x - 1;i <= x + 1;i++)
    {
        for(int j = y - 1;j <= y + 1;j++)
        {
            if(i< 0||i >= row||j < 0||j >= col)
            {
                continue;
            }
            if(chart[i][j].bomb == '*')
            {
                num++;
            }
        }
    }
    return num;
}
void mainui::Right_click(int &x,int &y)
{
    if(chart[x][y].dian == '.'&&chart[x][y].sign == '0')
    {
        if(remainbomb == 0)
            return;
        chart[x][y].sign = '!';
        remainbomb--;
        emit genggaileishu();
    }
    else if(chart[x][y].dian == '.'&&chart[x][y].sign == '!')
    {
        chart[x][y].sign = '?';
        remainbomb++;
        emit genggaileishu();
    }
    else if(chart[x][y].dian == '.'&&chart[x][y].sign == '?')
    {
        chart[x][y].sign = '0';
    }
}
void mainui::Chushihua()
{
    process = 0;
    firstclick = 0;
    xx = 0;
    yy = 0;
    timebegin = 0;
    killTimer(Timer);
    remainbomb = bombnum;
    for(int i = 0;i<row;i++){
        for(int j = 0;j < col;j++){
            chart[i][j].dian = '.';
            chart[i][j].sign = '0';
            chart[i][j].bomb = '0';
        }
    }
    update();

}
void mainui::Avoidfirstfail(int &xx,int &yy)
{
    int nums = 0;
    for(int i = xx - 1;i <= xx + 1;i++)
    {
        for(int j = yy - 1;j <= yy + 1;j++)
        {

            if(i< 0||i >= row||j < 0||j >= col)
            {
                continue;
            }
            chart[i][j].bomb = '}';
            nums++;
        }
    }
    srand(QTime::currentTime().msec());
    for(int k = 0;k < bombnum;){
        int x = rand()%row;
        int y = rand()%col;
        if(chart[x][y].bomb == '0'){
            chart[x][y].bomb = '*';
            k++;
        }
    }
}
void mainui::L_and_R_click(int &x,int &y)
{
    if(chart[x][y].dian == '.')
        return;
    int signbomb = 0;
    for(int i = x - 1;i <= x + 1;i++)
    {
        for(int j = y - 1;j <= y + 1;j++)
        {
            if(i< 0||i >= row||j < 0||j >= col)
            {
                continue;
            }
            if(chart[i][j].sign == '!')
            {
                signbomb++;
            }
        }
    }
    if(signbomb == Calculate_bombnum(x,y))
    {
        for(int i = x - 1;i <= x + 1;i++)
        {
            for(int j = y - 1;j <= y + 1;j++)
            {
                if(i< 0||i >= row||j < 0||j >= col)
                {
                    continue;
                }
                if(chart[i][j].sign == '!'&&chart[i][j].bomb != '*')
                {
                    process = 1;
                    return;
                }
            }
        }
        for(int i = x - 1;i <= x + 1;i++)
        {
            for(int j = y - 1;j <= y + 1;j++)
            {
                if(i< 0||i >= row||j < 0||j >= col)
                {
                    continue;
                }
                if(chart[i][j].dian == '.'&&chart[i][j].sign == '0')
                {
                    Left_click(i,j);
                }
            }
        }

    }
}
void mainui::Puanduanshengli()
{
    int k = 0;
    for(int i = 0;i< row;i++)
    {
        for(int j = 0;j< col;j++)
        {
            if(chart[i][j].dian == '.'&& chart[i][j].bomb == '0')
            {
                k++;
            }
        }
    }
    if(k == 0)
    {

        this->process = 2;
    }
}
void mainui::Pifu(int n)
{
    switch (n) {
    case 0:
        pifu = 0;
        update();
        break;
    case 1:
        pifu = 1;
        update();
        break;
    case 2:
        pifu = 2;
        update();
        break;
    case 3:
        pifu = 3;
        update();
        break;
    default:
        pifu = 0;
        update();
        break;
    }
}
