#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include <QtGlobal>
#include <QTime>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Chushihua();


}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter paint(this);
    Choose_mode(ui);
    setFixedSize(col*32,(row+1)*32);
    Print_chart(paint);
}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    int xx = (ev->y()-32)/32;
    int yy = ev->x()/32;
    if(firstclick++ == 0)
    {
        Avoidfirstfail(xx,yy);
    }
    if(ev->button() == Qt::LeftButton&&ev->button() != Qt::RightButton&&process == 0)
    {
        L_and_R_click(xx,yy);
        Left_click(xx,yy);
        repaint();
    }
    else if(ev->button() == Qt::RightButton&&ev->button() != Qt::LeftButton&&process == 0)
    {
        Right_click(xx,yy);
        repaint();
    }
    else if(ev->button() == Qt::RightButton&&ev->button() == Qt::LeftButton&&process == 0)
    {
        L_and_R_click(xx,yy);
        repaint();
    }

}
QPixmap MainWindow::topicture(char ch)
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
void MainWindow::Print_chart(QPainter &paint)
{
    int x = 0,y = 32;
    switch(process)
    {
        case 0:
        x = 0;y = 32;
            for(int i = 0;i < row;i++,y+=32)
            {
                for(int j = 0;j < col;j++,x+=32)
                {
                    if(chart[i][j].sign != '0'&&chart[i][j].dian == '.')
                    {
                        paint.drawPixmap(x,y,MainWindow::topicture(chart[i][j].sign));

                    }
                    else
                    {
                        paint.drawPixmap(x,y,MainWindow::topicture(chart[i][j].dian));


                    }
                }
                x=0;
            }
            break;
        default:
        x = 0;y = 32;
            for(int i = 0;i < row;i++,x = 0,y+=32)
            {
                for(int j = 0;j < col;j++,x+=32)
                {
                    if(chart[i][j].bomb == '*')
                    {
                        paint.drawPixmap(x,y,MainWindow::topicture(chart[i][j].bomb));
                    }
                    else if(chart[i][j].sign != '0'&&chart[i][j].dian == '0')
                    {
                        paint.drawPixmap(x,y,MainWindow::topicture(chart[i][j].sign));
                    }
                    else
                    {
                        paint.drawPixmap(x,y,MainWindow::topicture(chart[i][j].dian));
                    }
                }
            }
            break;
    }
}
void MainWindow::Left_click(int &x,int &y)
{
    qDebug()<<"jinqu";

    if(x < 0||x >= row||y < 0||y >= col)
    {
        return;
    }
    qDebug()<<"guodiyiguan";
    if(chart[x][y].dian != '.'||chart[x][y].sign == '!')
    {
        return;
    }
    qDebug()<<"guoditwoguan";
    if(chart[x][y].bomb == '*')
    {
        process = 1;
        return;
    }
    qDebug()<<"guoditherrguan";
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
                MainWindow::Left_click(i, j);
            }
        }
    }

}
int MainWindow::Calculate_bombnum(int &x,int &y)
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
void MainWindow::Right_click(int &x,int &y)
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
void MainWindow::Chushihua()
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
void MainWindow::Avoidfirstfail(int &xx,int &yy)
{
    qsrand(QTime::currentTime().msec());
    for(int k = 0;k < bombnum;){
        int x = qrand()%row;
        int y = qrand()%col;
        if(chart[x][y].bomb != '*'&&(x!=xx||x!=yy)){
            chart[x][y].bomb = '*';
            k++;
        }

    }
}

void MainWindow::Choose_mode(Ui::MainWindow *ui)
{
    connect(ui->actionchuji,&QAction::triggered,[=](){
        this->Choosechuji();
        Chushihua();
    });
    connect(ui->actionzhongji,&QAction::triggered,[=](){
        this->Choosezhongji();
        Chushihua();
    });
    connect(ui->actiongaoji,&QAction::triggered,[=](){
        this->Choosegaoji();
        Chushihua();
    });
}
void MainWindow::L_and_R_click(int &x,int &y)
{
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




