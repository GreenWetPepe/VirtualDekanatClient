#include "mainwindow.h"
#include "qsqlerror.h"
// #include "server.h"

#include <QApplication>
#include <QSqlDatabase>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QStringList drivers = QSqlDatabase::drivers();
    // qDebug() << "Available drivers:" << drivers;

    QSqlDatabase *db = new QSqlDatabase(QSqlDatabase::addDatabase("QPSQL"));
    db->setHostName("127.0.0.1");
    db->setPort(5433);
    db->setDatabaseName("dean_office");
    db->setUserName("postgres");
    db->setPassword("s20g;_2-r505t8");
    db->open();
    if (db->isOpen()) qDebug() << "COEFEF";
    qDebug() << "Error: " << db->lastError().text();


    w.show();
    return a.exec();
}

// /var/lib/postgresql/data/pgdata/pg_hba.conf
//     /var/lib/postgresql/data/pg_hba.conf
