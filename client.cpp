#include "client.h"

Client::Client(QObject *parent) : QObject(parent)
{
    qInfo() << "Client::Client";
}

Client::~Client()
{
    qInfo() << "Client::~Client";
    socket->disconnectFromHost();
    socket->close();
    socket->deleteLater();
}

void Client::connectToServer(QUrl url, int port)
{
    qInfo() << "Client::connectToServer -> " << url << ":"<< port;
    socket = new QTcpSocket(this);
    socket->connectToHost(url.toString(), port);
    waitForConnection();
    connect(socket, &QTcpSocket::readyRead, this, &Client::readFromServer);
}

void Client::connectToLocalServer(int port)
{
    qInfo() << "Client::connectToLocalServer ->  "<< "0.0.0.0:"<< port;
    socket = new QTcpSocket(this);
    socket->connectToHost("localhost", port);
    waitForConnection();
    connect(socket, &QTcpSocket::readyRead, this, &Client::readFromServer);
}

void Client::waitForConnection()
{
    qInfo() << "Client::waitForConnection";
    if (socket->waitForConnected(-1)) qDebug("connected");
}

void Client::writeToServer(QString msg, QString type) //type can be "msg","snc","usr","url"
{
    qInfo() << "Client::writeToServer -> msg: " << msg << ", type: " << type;
    QByteArray buffer = type.toUtf8() + msg.toUtf8() + "\n";
    socket->write(buffer);
    socket->flush();// flush() 用于强制立即将缓冲区中的数据发送出去，而不是等待更多的数据进入缓冲区后一起发送。这样可以确保消息及时发送。
}

void Client::disconnect()
{
    qInfo() << "Client::disconnect";
    socket->disconnect();
}

void Client::readFromServer()
{
    while (socket->canReadLine())
    {
        QByteArray buffer = socket->readLine();
        QString header = buffer.mid(0, 3);
        QString content = buffer.mid(3).trimmed();
        qInfo() << "Client::readFromServer -- header: " << header << ", content: " << content;
        if (header == "snc")
        {
            qInfo() << "Sync info from Server: " << content;
            QString syncType = content.mid(0, 4);
            qint64 position = content.mid(4).toLongLong();
            if (syncType == "play")
            {
                emit remotePlay(position);
            }
            else if (syncType == "paus")
            {
                emit remotePause(position);
            }
            else if (syncType == "stop")
            {
                emit remoteStop();
            }
            else if (syncType == "seek")
            {
                emit remoteSeek(position);
            }
            else if (syncType == "sync")
            {
                emit remoteSync(position);
            }
        }
        else if (header == "msg")
        {
            qInfo() << "Message from Server: " << content;
            emit newChatMsg(content);
        }
        else if (header == "src")
        {
            QString srcType = content.mid(0, 3);
            content = content.mid(3);
            if (srcType == "net")
            {
                emit remoteSetVideoSource(content);
            }
            if (srcType == "lcl")
            {
                emit remoteSetLocalVideoSource(content);
            }
            emit newChatMsg("Souce set:" + content);

        }
        else if (header == "usr")
        {
            QString usrType = content.mid(0, 3);
            QString usrName = content.mid(3);
            if (usrType == "con")
            {
                emit userConnected(usrName);
                emit newChatMsg(QString(usrName + " connected."));
            }
            else if (usrType == "dis")
            {
                emit userDisconnected(usrName);
                emit newChatMsg(QString(usrName + " disconnected."));
            }
            else if (usrType == "lst")
            {
                QStringList userList = usrName.split("&&");
                for (auto& s : userList)
                {
                    emit userConnected(s);
                }
            }
        }
    }
}

void Client::setUdpPort(quint16 udpPort)
{
    qInfo() << "Client::setUdpPort Sending udp port";
    writeToServer(QString::number(udpPort), "prt");
}
