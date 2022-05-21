#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>//播放器
#include <QVideoFrame>//显示窗口


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_uploadBtn_clicked();

    void on_playBtn_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

signals:
    void itemRemove();

private:
    Ui::MainWindow *ui;
    QMediaPlayer* pPlayer;
    QStringList* myPlayList;
};
#endif // MAINWINDOW_H
