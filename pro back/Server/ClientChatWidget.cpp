#include "ClientChatWidget.h"
#include "ui_ClientChatWidget.h"

ClientChatWidget::ClientChatWidget(QTcpSocket *client,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ClientChatWidget),
    _client(client)
{
    ui->setupUi(this);
    connect(_client,&QTcpSocket::readyRead,this, &ClientChatWidget::dataReceived);
    connect(_client,&QTcpSocket::disconnected,this, &ClientChatWidget::clientDisconnected);

}

ClientChatWidget::~ClientChatWidget()
{
    delete ui;
}
void ClientChatWidget::dataReceived()
{
    auto data = _client->readAll();
    ui->lstMessages->addItem(data);

}

void ClientChatWidget::on_btnSend_clicked()
{
    QString message = ui->lnMessage->text().trimmed();
    _client->write(message.toUtf8());
    ui->lnMessage->setText("");
    ui->lstMessages->addItem("Server : " + message);
}
void ClientChatWidget::clientDisconnected()//when client is disconnected then it deactivates the send button
{
    ui->wdgSend->setEnabled(false);
}
