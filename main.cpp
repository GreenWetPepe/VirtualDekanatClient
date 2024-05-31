#include "mainwindow.h"
#include "qsqlerror.h"
 #include "server.h"

#include <QApplication>
#include <QSqlDatabase>
#include <QDebug>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();
    return a.exec();
}

// /var/lib/postgresql/data/pgdata/pg_hba.conf
//     /var/lib/postgresql/data/pg_hba.conf
