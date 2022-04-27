#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QTextStream>

#include <QTcpSocket>
class TcpClient
{
public:
    TcpClient(QString ssid, QString psswd);
    bool getConnection();
    bool connect();
    bool disconnect();
private:
    QString ip = "192.168.10.1";
    int port = 50007;
    QString ssid = "";
    QString psswd = "";
    bool isConnected;
    QTcpSocket *socket;

};

#endif // TCPCLIENT_H
