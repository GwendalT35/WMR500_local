#include "tcpclient.h"

#include <QTcpSocket>
#include <QDebug>
#include <QObject>
#include <QMessageBox>
QString format(QString str);

TcpClient::TcpClient(QString ssid, QString psswd)
{
  if (ssid != "" && psswd != "")
    {
      this->ssid = ssid;
      this->psswd = psswd;
      this->isConnected = connect();
      if(getConnection())
        {
          QMessageBox infoBox;
          infoBox.setText("La station météo a bien été appairée !");
          infoBox.exec();
        }
    }
}

bool TcpClient::getConnection()
{
  return this->isConnected;
}

bool TcpClient::connect()
{
  bool confirm = false;
  this->socket = new QTcpSocket(NULL);
  this->socket->connectToHost(this->ip, this->port);
  if(this->socket->isOpen())
    {
      QString cmdTosend = "";
      cmdTosend.append("WMR500C("+ format(this->ssid)+","+format(this->psswd)+")");
      const char * cmdStr = cmdTosend.toStdString().c_str();
      qDebug()<<cmdStr;
      socket->write(cmdStr);
      if(socket->waitForBytesWritten(2000))
        {
          if(socket->write("CONFIRM")>0)
            {
              confirm = true;
            }
        }
    }
  return confirm;
}

bool TcpClient::disconnect()
{
  socket->disconnectFromHost();
  this->isConnected = socket->isOpen();
  return this->isConnected;
}


QString format(QString str) {
  QString sizeofStr = "";
  if(str.length() < 10)
    {
      sizeofStr.append("0");
      sizeofStr.append(QString::number(str.length()));
      sizeofStr.append(str);
    }
  else
    {
      sizeofStr.append(QString::number(str.length()));
      sizeofStr.append(str);
    }
  return sizeofStr;
}
