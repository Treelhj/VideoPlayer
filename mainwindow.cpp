#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QFileDialog>
#include <QItemSelectionModel>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("播放器");

    pPlayer=new QMediaPlayer;
    myPlayList=new QStringList();

    ui->listWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
    connect(this,&MainWindow::itemRemove,ui->listWidget,[=](){
        int count=ui->listWidget->count();
        if (count > 0)
        {
           for(int i=0;i<count;i++)
            {
                 QString text=QString::number(i+1)+"."+ui->listWidget->item(i)->text().split('.').at(1);
                  qDebug()<<text;
                 ui->listWidget->item(i)->setText(text);
            }
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

//上传视频
void MainWindow::on_uploadBtn_clicked()
{

}


void MainWindow::on_playBtn_clicked()
{

}


void MainWindow::on_pushButton_6_clicked()
{
    qDebug()<<"我被点击了";
    QStringList filenames= QFileDialog::getOpenFileNames(this,"电影列表?","C:/Users/15535/Desktop","allfiles(*.*);;""MP3(*.mp3");

    foreach(QString const&str,filenames){
        qDebug()<<str;
        myPlayList->append(str);

        QFileInfo   fileInfo(str);
        int index=ui->listWidget->count();
        QString text=QString::number(index+1)+"."+fileInfo.fileName();
        ui->listWidget->addItem(text);//添加到文件列表

    }
     qDebug()<<"..................";
 //    foreach(QString const&str,myPlayList){
 //         qDebug()<<str;
 //    }
//     for(int i=0;i<myPlayList->count();i++)
//         {
//             QString aFile=myPlayList->at(i);
//             qDebug()<<aFile;
//     }
}


void MainWindow::on_pushButton_7_clicked()
{
     QList<QListWidgetItem*> items = ui->listWidget->selectedItems();
     if (items.count() > 0)
      {
             foreach(QListWidgetItem* var, items)
             {
                  int index=ui->listWidget->row(var);
                  myPlayList->removeAt(index);
                  ui->listWidget->removeItemWidget(var);
                  items.removeOne(var);
                  delete var;
             }
//             for(int i=0;i<myPlayList->count();i++)
//                 {
//                     QString aFile=myPlayList->at(i);
//                     qDebug()<<aFile;
//             }
       }
     emit itemRemove();


}

