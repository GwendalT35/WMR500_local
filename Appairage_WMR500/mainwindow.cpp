#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tcpclient.h"
#include <QNetworkConfigurationManager>
#include <QNetworkSession>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Password->setEchoMode(QLineEdit::Password);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Disconnectbtn_clicked()
{
    client->disconnect();
}

void MainWindow::on_Btn_connect_clicked()
{
  qDebug()<<"Boutton appairage clicker !";
    client = new TcpClient(ui->SSID->text(), ui->Password->text());
}
