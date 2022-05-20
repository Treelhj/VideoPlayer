#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //播放按钮22
//    ui->PlayButton->setIcon(QIcon(":/images/play.png"));
//    ui->PlayButton->setIconSize(QSize(30,30));
}

MainWindow::~MainWindow()
{
    delete ui;
}

