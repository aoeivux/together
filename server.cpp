#include "server.h"

Server::Server(QObject *parent) : QObject(parent)
{
    qInfo() << "Server::Server";
}

Server::~Server()
{
    qInfo() << "Server::~Server on port " << port << " closed.";
    //cleanup sockets
    for (auto client : clients)
    {
        client->close();
        client->deleteLater();
    }
    tcpServer->close();
    tcpServer->deleteLater();
}

void Server::initServer(int port)
{
    qInfo() << "Server::initServer listen: " << port;
    tcpServer = new QTcpServer(this);
    connect(tcpServer, &QTcpServer::newConnection, this, &Server::newConnection);
    this->port = port;
    listen();
}

void Server::newConnection()
{
    qInfo() << "Server::newConnection ";
    while (tcpServer->hasPendingConnections())
    {
        appendNewConnection(tcpServer->nextPendingConnection());
    }
}

void Server::appendNewConnection(QTcpSocket* client)
{
    qInfo() << "Server::appendNewConnection : " << client;
    clients.append(client);
    connect(client, &QTcpSocket::disconnected, this, &Server::clientDisconnected);  //绑定客户端端口事件
    connect(client, &QTcpSocket::readyRead, this, &Server::readFromClient); // 绑定接收端读取数据的响应函数
//    listClients();
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    if (isSourceSet)
    {
        QString type = "src";
        client->write(type.toUtf8() + source.toUtf8() + QString("\n").toUtf8());
        client->flush();
    }
    //send client list to client
    QString clientList = "";
    for (auto c : clients)
    {
        if (c->objectName() != "")
        {
            clientList.append(c->objectName() + "&&");// send client list with delimiter &&
        }
    }
    clientList.chop(2);//remove last delimiter &&
    if (clientList != QString(""))
    {
        client->write(QString("usrlst").toUtf8() + clientList.toUtf8() + QString("\n").toUtf8());
        client->flush();
    }
}

//write to all clients
void Server::writeToClients(QString msg, QString type)
{
    qInfo() << "Server::writeToClients all, type: " << type << ", msg: " << msg;
    for (auto client: clients)
    {
        QByteArray buffer = type.toUtf8() + msg.toUtf8() + "\n";
        client->write(buffer);
        client->flush();
    }
}

//write to all except currentClient
//发送给所有的client
void Server::writeToClients(QString msg, QString type, QTcpSocket* currentClient)
{
    qInfo() << "Server::writeToClients no cur, type: " << type << ", msg: " << msg;
    for (auto client: clients)
    {
        if (client != currentClient)
        {
            QByteArray buffer = type.toUtf8() + msg.toUtf8() + "\n";
            client->write(buffer);
            client->flush();
        }
    }
}
//从clients队列删除断开的client
void Server::clientDisconnected()
{
    QTcpSocket* client = qobject_cast<QTcpSocket*>(sender());
    qInfo() << "Server::clientDisconnected, remove client :" << client << "with address:" << client->peerAddress() << " = " << clients.removeOne(client);
    writeToClients("dis" + client->objectName(), "usr", client);
    emit removeUdpClient(client);
    clients.squeeze();
    client->deleteLater();
}
//响应客户端的处理
void Server::readFromClient()
{
//    qInfo() << "Server::readFromClient";
     QTcpSocket* client = reinterpret_cast<QTcpSocket*>(sender());
     while (client->canReadLine())
     {
        QByteArray buffer = client->readLine();
        QString header = buffer.mid(0, 3);
        QString content = buffer.mid(3).trimmed();
        qInfo() << "Server::readFromClient, header: << " << header << ", content: " << content;
        if (header == "snc")
        {
                    qInfo() << "Sync info from " << client->objectName() << " : " << content;
            writeToClients(content, "snc");
        }
        else if (header == "msg")
        {
            //        qInfo() << "Message from " << client->objectName() << " : " << content;
            writeToClients(client->objectName() + ": " + content, "msg");
        }
        else if (header == "usr")
        {
            client->setObjectName(content);
            writeToClients("con" + client->objectName(), "usr");
        }
        else if (header == "src")
        {
            source = content;
            isSourceSet = true;
            QString srcType = content.mid(0, 3);
            content = content.mid(3);
            if (srcType == "net")
            {
                writeToClients(content, "srcnet");
            }
            if (srcType == "lcl")
            {
               writeToClients(content, "srclcl");
            }
            //        writeToClients("New source: " + content, "msg");
            qInfo() << "New source: " << content;
        }
        else if (header == "prt")
        {
            qInfo() << "udpAddress:" << client->peerAddress() << "udp port:" << content << "tcp port:" << client->peerPort() << "udp name:" << client->objectName();
            emit addUdpClient(client, client->peerAddress(), content.toUShort());
        }
    }
}

void Server::listen()
{
    tcpServer->listen(QHostAddress::Any, port);
    qInfo() << "Server::listen, Started listening on port: " << port;
}

void Server::listClients()
{
    //列出所有client，目前没有被调用，打印太多了
    for(auto client : clients)
    {
        qInfo() << client;
    }
}
