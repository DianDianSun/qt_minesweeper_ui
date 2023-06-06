#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "mainui.h"
#include "zidingyi2.h"
#include "jishiqi.h"
#include "jileiqi.h"
#include <QMainWindow>
#include <QString>
#include <QLabel>
#include <QTimer>
#include <QPixmap>
#include <QObject>
#include <QPushButton>
#include <QThread>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int pifu = 0;
    int xx;
    int yy;
    zidingyi2 *selfding = NULL;
    mainui *Mainui = NULL;
    jishiqi *jishi;
    jileiqi *jilei;
    void Choose_mode(Ui::MainWindow *ui);
    void Choosechuji(){Mainui->row = 9;Mainui->col = 9;Mainui->bombnum = 10;Mainui->remainbomb=Mainui->bombnum;}
    void Choosezhongji(){Mainui->row = 16;Mainui->col = 16;Mainui->bombnum = 40;Mainui->remainbomb=Mainui->bombnum ;}
    void Choosegaoji(){Mainui->row = 16;Mainui->col = 30;Mainui->bombnum = 99;Mainui->remainbomb = Mainui->bombnum;}
    QString Pifu();
    void Pifuheti(int n);
    QPushButton *xiaolian;
    void Chushihuaall();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
