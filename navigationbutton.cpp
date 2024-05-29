#include "mainwindow.h"
#include "navigationbutton.h"
#include "states.cpp"

#include <QDebug>

NavigationButton::NavigationButton(int type, QWidget *parent) : QPushButton(parent)
{
    switch (type)
    {
    case NavigationButtons::NEWS:
        setText(QString("NEWS"));
        break;
    case NavigationButtons::ACCOUNT:
        setText(QString("ACCOUNT"));
        break;
    case NavigationButtons::SCHEDULE:
        setText(QString("SCHEDULE"));
        break;
    case NavigationButtons::COURSES:
        setText(QString("COURSES"));
        break;
    case NavigationButtons::STATISTIC:
        setText(QString("STATISTIC"));
        break;
    case NavigationButtons::LOG_OUT:
        setText(QString("LOG_OUT"));
        break;
    case NavigationButtons::USER_OPTIONS:
        setText(QString("USER_OPTIONS"));
        break;
    case NavigationButtons::SERVER_OPTIONS:
        setText(QString("SERVER_OPTIONS"));
        break;
    }

    if (!parent || !parent->parent())
    {
        qDebug() << "Кнопка навигации не привязана";
    }

    this->type = type;

    MainWindow *mainWindow = qobject_cast<MainWindow*>(parent->parent());
    connect(this, &NavigationButton::changePageWidget, mainWindow, &MainWindow::changePageWidget);
}

void NavigationButton::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        emit changePageWidget(type);
    }
}
