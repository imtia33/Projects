#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qtcpsocket.h"
#include "ClientChatWidget.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupServer();
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::newClientConnected(QTcpSocket *client)
{
    auto id = client->property("id").toInt();
     ui->lstClients->addItem(QString("New Client Added: %1").arg(id));
    auto chatWidget = new ClientChatWidget(client);
     ui->tbChats->addTab(chatWidget,QString("Client (%1)").arg(id));

}
void MainWindow::clientDisconnected(QTcpSocket *client)//tells if the client is disconencted
{
    auto id = client->property("id").toInt();
    ui->lstClients->addItem(QString("Client Disconnected: %1").arg(id));
}
void MainWindow::setupServer()//connects to the client
{
    _server = new ServerManager();
    connect(_server, &ServerManager:: newClientConnected,this,&MainWindow::newClientConnected);
    connect(_server, &ServerManager:: clientDisconnected,this,&MainWindow::clientDisconnected);
}

void MainWindow::on_btnDisconnectAll_clicked()//button action for Disconnect All
{
    _server->disconnectAllClients();

}

