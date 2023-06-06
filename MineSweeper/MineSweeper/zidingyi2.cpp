#include "zidingyi2.h"
#include "ui_zidingyi2.h"

zidingyi2::zidingyi2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::zidingyi2)
{
    ui->setupUi(this);
    ui->setupUi(this);
    ui->bombnum->setMaximum(ui->wdith->value() * ui->col->value()*9/10);
    connect(ui->yes,&QPushButton::clicked,[=](){
        this->row = ui->wdith->value();
        this->col = ui->col->value();
        this->bomb = ui->bombnum->value();
        this->panduan = 1;

        this->close();
    });
    connect(ui->no,&QPushButton::clicked,[=](){

        this->close();
    });
    connect(ui->bombnum,&QSpinBox::valueChanged,[=](){
        ui->bombnum->setMaximum(ui->wdith->value() * ui->col->value()*9/10);
    });
}

zidingyi2::~zidingyi2()
{
    delete ui;
}
