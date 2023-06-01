#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Mainui = new mainui;
    selfding = new zidingyi2;
    setFixedSize(Mainui->col*32,Mainui->row*32+72);
    QScreen *screen = QGuiApplication::primaryScreen();
    this->move((screen->geometry().width()- this->width())/2,(screen->geometry().height()- this->height())/2);
    Choose_mode(ui,screen);
    MainWindow::setStyleSheet("background-color: rgb(255,239,247);");
    Mainui->move(0,72);
    Mainui->setParent(this);

}

MainWindow::~MainWindow()
{
    delete selfding;
    delete Mainui;
    delete ui;
}
void MainWindow::Choose_mode(Ui::MainWindow *ui,QScreen *screen)
{
    connect(ui->actionchuji,&QAction::triggered,[=](){

        this->Choosechuji();
        setFixedSize(Mainui->col*32,Mainui->row*32+72);
        this->move((screen->geometry().width()- this->width())/2,(screen->geometry().height()- this->height())/2);
        Mainui->Chushihua();
        Mainui->setFixedSize(Mainui->col*32,Mainui->row*32);

    });
    connect(ui->actionzhongji,&QAction::triggered,[=](){
        this->Choosezhongji();
        setFixedSize(Mainui->col*32,Mainui->row*32+72);
        this->move((screen->geometry().width()- this->width())/2,(screen->geometry().height()- this->height())/2);
        Mainui->Chushihua();
        Mainui->setFixedSize(Mainui->col*32,Mainui->row*32);
    });
    connect(ui->actiongaoji,&QAction::triggered,[=](){
        this->Choosegaoji();
        setFixedSize(Mainui->col*32,Mainui->row*32+72);
        this->move((screen->geometry().width()- this->width())/2,(screen->geometry().height()- this->height())/2);
        Mainui->Chushihua();
        Mainui->setFixedSize(Mainui->col*32,Mainui->row*32);
    });
    connect(ui->actionzidingyi,&QAction::triggered,[=](){
        selfding->move((screen->geometry().width()- selfding->width())/2,(screen->geometry().height()- selfding->height())/2);
        selfding->setModal(true);
        selfding->exec();

        if(selfding->panduan){

            Mainui->row = selfding->row;
            Mainui->col = selfding->col;
            Mainui->bombnum = selfding->bomb;
            Mainui->Chushihua();
            Mainui->setFixedSize(Mainui->col*32,Mainui->row*32);
            this->setFixedSize(Mainui->col*32,Mainui->row*32+72);
            this->move((screen->geometry().width()- this->width())/2,(screen->geometry().height()- this->height())/2);
            selfding->panduan = 0;
        }
        qDebug()<<"no";
    });
    connect(ui->actionquit,&QAction::triggered,[=](){
        this->close();
    });
}

