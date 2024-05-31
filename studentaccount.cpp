#include "studentaccount.h"
#include "ui_studentaccount.h"

#include "server.h"

StudentAccount::StudentAccount(int userId, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentAccount)
{
    ui->setupUi(this);

    QJsonArray request = Server::sendRequest("http://localhost:5000/api/v1/students?user_id=" + std::to_string(userId));
    QJsonObject obj = request.at(0).toObject();

    for (auto it = obj.constBegin(); it != obj.constEnd(); ++it) {
        qDebug() << it.key() << it.value();
        QLabel *label = findChild<QLabel*>(it.key());
        if (it.value().isDouble()) label->setText(QString::number(it.value().toDouble()));
        else label->setText(it.value().toString());
    }
}

StudentAccount::~StudentAccount()
{
    delete ui;
}
