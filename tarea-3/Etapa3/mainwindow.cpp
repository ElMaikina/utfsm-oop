#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix (":/resource/img/goldie.png");
    QPixmap j1(":/resource/img/bone.jpg");
    QPixmap j2(":/resource/img/ball.jpg");
    QIcon HuesoBoton(j1);
    QIcon BolaBoton(j2);
    ui->Hueso->setIcon(HuesoBoton);
    ui->Bola->setIcon(BolaBoton);
    ui->Hueso->setIconSize(QSize(50,50));
    ui->Bola->setIconSize(QSize(50,50));
    int w=ui->Mascota->width();
    int h=ui->Mascota->height();
    ui->Mascota->setPixmap(pix.scaled(h,w,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}

