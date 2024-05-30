#include "server.h"

#include <QDebug>

bool Server::isCreated = false;
// QSqlDatabase Server::db = QSqlDatabase::addDatabase("QPSQL");

Server::~Server()
{
    // db.close();
    isCreated = false;

    qDebug() << "Connection close";
}

void Server::initConnection()
{
    // if (isCreated) return;

    // db.setHostName("localhost");
    // db.setDatabaseName("dean_office");
    // db.setUserName("postgres");
    // db.setPassword("s20g;_2-r505t8");

    // if (db.open()) qDebug() << "Connection open";
    // isCreated = true;
}
