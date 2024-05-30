#include "server.h"

#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QDebug>


Server::~Server()
{

    qDebug() << "Connection close";
}

void Server::sendRequest(std::string req)
{
    QNetworkAccessManager *manager = new QNetworkAccessManager();
    QUrl url(QString::fromStdString(req));
    QNetworkRequest request(url);

    // Отправляем запрос
    QNetworkReply *reply = manager->get(request);

    // Подключаем слот для обработки ответа
    QObject::connect(reply, &QNetworkReply::finished, [reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            // Читаем данные из ответа
            QByteArray response = reply->readAll();
            QString responseString = QString::fromUtf8(response);
            qDebug() << "Response:" << responseString;
        } else {
            // Обрабатываем ошибку
            qDebug() << "Error:" << reply->errorString();
        }
        reply->deleteLater(); // Удаляем объект после завершения
    });
}
