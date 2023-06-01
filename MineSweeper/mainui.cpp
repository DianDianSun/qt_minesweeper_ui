#include "mainui.h"
#include <QDebug>
#include <QPainter>
#include <QPixmap>
mainui::mainui(QWidget *parent)
    : QWidget{parent}
{
    Chushihua();

}
void mainui::paintEvent(QPaintEvent *)
{
    QPainter paint(this);

    setFixedSize(col*32,row*32);
    Print_chart(paint);
}

void mainui::mousePressEvent(QMouseEvent *ev)
{
    int xx = ev->y()/32;
    int yy = ev->x()/32;
    if(firstclick++ == 0)
    {
        Avoidfirstfail(xx,yy);
    }
    if(ev->button() == Qt::LeftButton&&ev->button() != Qt::RightButton&&process == 0)
    {
        L_and_R_click(xx,yy);
        Left_click(xx,yy);
        Puanduanshengli();
        repaint();
    }
    else if(ev->button() == Qt::RightButton&&ev->button() != Qt::LeftButton&&process == 0)
    {
        Right_click(xx,yy);
        repaint();
        Puanduanshengli();
    }
    else if(ev->button() == Qt::RightButton&&ev->button() == Qt::LeftButton&&process == 0)
    {
        L_and_R_click(xx,yy);
        repaint();
        Puanduanshengli();
    }

}
QPixmap mainui::topicture(char ch)
{
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
    default:
        return QPixmap(":/pinktheme/kong.png");
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
        for(int i = 0;i < row;i++,x = 0,y+=32)
        {
            for(int j = 0;j < col;j++,x+=32)
            {
                if(chart[i][j].bomb == '*')
                {
                    paint.drawPixmap(x,y,mainui::topicture(chart[i][j].bomb));
                }
                else if(chart[i][j].sign != '0'&&chart[i][j].dian == '0')
                {
                    paint.drawPixmap(x,y,mainui::topicture(chart[i][j].sign));
                }
                else
                {
                    paint.drawPixmap(x,y,mainui::topicture(chart[i][j].dian));
                }
            }
        }
        break;
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
        qDebug()<<x<<" "<< y;
        chart[x][y].sign = '!';
        remainbomb--;
    }
    else if(chart[x][y].dian == '.'&&chart[x][y].sign == '!')
    {
        chart[x][y].sign = '?';
        remainbomb++;
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
    for(int i = 0;i<row;i++){
        for(int j = 0;j < col;j++){
            chart[i][j].dian = '.';
            chart[i][j].sign = '0';
            chart[i][j].bomb = '0';
        }
    }
    repaint();

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
    qDebug()<<nums;
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

