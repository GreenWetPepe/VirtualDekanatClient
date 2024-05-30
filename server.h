#ifndef SERVER_H
#define SERVER_H

#include <QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>


class Server
{
public:
    ~Server();

    static void initConnection();

private:
    // static QSqlDatabase db;
    static bool isCreated;
};

#endif // SERVER_H
