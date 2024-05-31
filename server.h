#ifndef SERVER_H
#define SERVER_H

#include <iostream>

#include <QObject>
#include <QString>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QEventLoop>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

class Server : public QObject {
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr) : QObject(parent) {}
    static QJsonArray sendRequest(const std::string &req);

private slots:
    void onRequestFinished(QNetworkReply *reply);

private:
    QString responseString;
};
#endif // SERVER_H
