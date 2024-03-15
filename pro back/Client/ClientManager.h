#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H

#include <QObject>
#include <QTcpSocket>
class ClientManager : public QObject
{
    Q_OBJECT
public:
    explicit ClientManager(QString ip = "Server IP here", ushort port = 4500, QObject *parent = nullptr);
    void connectToServer();
    void sendMessage(QString message);
    void disconnectFromServer();
signals:
    void connected();
    void disconnected();
    void dataReceived(QByteArray data);
private slots:
    void readyRead();

private:
    QTcpSocket *_socket;
    QString _ip;
    ushort _port;
};

#endif // CLIENTMANAGER_H
