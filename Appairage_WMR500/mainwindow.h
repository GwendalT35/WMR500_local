#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tcpclient.h"

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

    void on_Disconnectbtn_clicked();
    void on_Btn_connect_clicked();

private:
    Ui::MainWindow *ui;
    TcpClient *client;
};
#endif // MAINWINDOW_H
