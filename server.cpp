#include "server.h"
#include <QUrl>
#include <QNetworkRequest>
#include <QDebug>
#include <QJsonParseError>

QJsonArray Server::sendRequest(const std::string &req) {
    QEventLoop eventLoop;
    QNetworkAccessManager manager;

    // Временный объект Server для использования слотов и сигналов
    Server tempServer;
    QObject::connect(&manager, &QNetworkAccessManager::finished, &tempServer, &Server::onRequestFinished);

    // Преобразуем std::string в QString
    QString qReq = QString::fromStdString(req);
    QUrl url(qReq);
    QNetworkRequest request(url);

    // Отправляем запрос
    QNetworkReply *reply = manager.get(request);

    // Подключаем завершение запроса к выходу из eventLoop
    QObject::connect(reply, &QNetworkReply::finished, &eventLoop, &QEventLoop::quit);

    // Ожидаем завершения запроса
    eventLoop.exec();

    // Преобразуем ответ в JSON
    QJsonArray jsonResponse;
    if (!tempServer.responseString.isEmpty()) {
        QJsonParseError parseError;
        QJsonDocument jsonDoc = QJsonDocument::fromJson(tempServer.responseString.toUtf8(), &parseError);

        if (parseError.error != QJsonParseError::NoError) {
            qDebug() << "JSON parse error:" << parseError.errorString();
            qDebug() << "Response String:" << tempServer.responseString;
        } else if (jsonDoc.isArray()) {
            jsonResponse = jsonDoc.array();
        } else {
            qDebug() << "JSON document is not an array.";
            qDebug() << "Response String:" << tempServer.responseString;
        }
    } else {
        qDebug() << "Response string is empty.";
    }

    return jsonResponse;
}

void Server::onRequestFinished(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray response = reply->readAll();
        responseString = QString::fromUtf8(response);
    } else {
        qDebug() << "Error:" << reply->errorString();
        responseString = "";
    }
    reply->deleteLater();
}
