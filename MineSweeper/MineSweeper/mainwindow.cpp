#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->time->setPixmap(QPixmap(":/other/time.png"));
    Mainui = new mainui(this);
    selfding = new zidingyi2(this);
    jishi = new jishiqi(this);
    jilei = new jileiqi(this);
    xiaolian = new QPushButton(this);
    xiaolian->setFixedSize(50,50);
    QScreen *screen = QGuiApplication::primaryScreen();
    xx = screen->geometry().width();
    yy = screen->geometry().height();
    Choose_mode(ui);
    MainWindow::setStyleSheet(Pifu());
    Chushihuaall();


}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::Choose_mode(Ui::MainWindow *ui)
{
    connect(ui->actionchuji,&QAction::triggered,[=](){
        this->Choosechuji();
        Chushihuaall();
        this->move((xx- this->width())/2,(yy- this->height())/2);
    });
    connect(ui->actionzhongji,&QAction::triggered,[=](){

        this->Choosezhongji();
        Chushihuaall();
        this->move((xx- this->width())/2,(yy- this->height())/2);
    });
    connect(ui->actiongaoji,&QAction::triggered,[=](){
        this->Choosegaoji();
        Chushihuaall();
        this->move((xx- this->width())/2,(yy- this->height())/2);
    });
    connect(ui->actionzidingyi,&QAction::triggered,[=](){
        jishi->time->stop();
        selfding->move((xx- selfding->width())/2,(yy- selfding->height())/2);
        selfding->setModal(true);
        selfding->exec();

        if(selfding->panduan){
            jishi->chushihua();
            Mainui->row = selfding->row;
            Mainui->col = selfding->col;
            Mainui->bombnum = selfding->bomb;
            Chushihuaall();
            this->move((xx- this->width())/2,(yy- this->height())/2);
            selfding->panduan = 0;
        }
    });
    connect(ui->actionquit,&QAction::triggered,[=](){
        this->close();
    });
    connect(ui->actionclassic,&QAction::triggered,[=](){
       Pifuheti(0);
    });
    connect(ui->actionIKUN,&QAction::triggered,[=](){
        Pifuheti(1);
    });
    connect(ui->actionmengnanfen,&QAction::triggered,[=](){
        Pifuheti(2);
    });
    connect(ui->actionlvsexinqing,&QAction::triggered,[=](){
       Pifuheti(3);
    });
    connect(Mainui,&mainui::youxichange,[=](){
        if(Mainui->process == 1){
        xiaolian->setStyleSheet("background-image: url(:/other/xiao2.png);");
        }else if(Mainui->process == 2)
        {
        xiaolian->setStyleSheet("background-image: url(:/other/xiao3.png);");
        }
        jishi->time->stop();
    });
    connect(Mainui,&mainui::jishiqistart,[=](){
        jishi->time->start();
    });
    connect(Mainui,&mainui::genggaileishu,[=](){
        jilei->bombnum = Mainui->remainbomb;
        jilei->gengxinshuju();
    });
    connect(ui->actiontoushi,&QAction::triggered,[=](){
        if(ui->actiontoushi->isChecked() == true)
        {
            Mainui->toushi = 1;
            Mainui->update();
        }else
        {
            Mainui->toushi = 0;
            Mainui->update();
        }
    });
    connect(xiaolian,&QPushButton::clicked,[=](){
        Chushihuaall();
    });

}
QString MainWindow::Pifu()
{
    QString str0 = "background-color: rgb(238,238,238);color: rgb(0, 0, 0);";//classic
    QString str1 = "background-color: rgb(238,238,238);color: rgb(0, 0, 0);";//ikun
    QString str2 = "background-color: rgb(255,239,247);color: rgb(0, 0, 0);";//pink
    QString str3 = "background-color: rgb(216,255,195);color: rgb(0, 0, 0);";//green
    switch(pifu)
    {
    case 0:
        return str0;
    case 1:
        return str1;
    case 2:
        return str2;
    case 3:
        return str3;

    }
}
void MainWindow::Chushihuaall()
{

    jilei->bombnum = Mainui->bombnum;
    jilei->gengxinshuju();
    jishi->time->stop();
    setFixedSize(Mainui->col*32,Mainui->row*32+71);
    Mainui->Chushihua();
    Mainui->setFixedSize(Mainui->col*32,Mainui->row*32);
    ui->bomb->move(this->width()-90-32,21);
    ui->bomb->setPixmap(Mainui->topicture('*'));
    jishi->chushihua();
    jilei->move(this->width()-90,21);
    xiaolian->move((double)(this->width()-50)/2,21);
    xiaolian->setStyleSheet("background-image: url(:/other/xiao1.png);");
}
void MainWindow::Pifuheti(int n)
{
    pifu = n;
    MainWindow::setStyleSheet(Pifu());
    Mainui->Pifu(n);
    ui->bomb->setPixmap(Mainui->topicture('*'));
}
