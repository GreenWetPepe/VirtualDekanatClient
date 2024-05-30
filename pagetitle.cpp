#include "pagetitle.h"
#include "ui_pagetitle.h"

#include "states.cpp"

#include <QLabel>
#include <QPushButton>

PageTitle::PageTitle(int userType, int pageType, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageTitle)
{
    ui->setupUi(this);
    setStyleSheet("background-color: #3498db;");


    changeTitle(userType, pageType);
}

PageTitle::~PageTitle()
{
    delete ui;
}

void PageTitle::changeTitle(int userType, int pageType)
{
    QLayoutItem *item;
    while((item = ui->horizontalLayout->takeAt(0)) != nullptr)
    {
        delete item->widget();
    }

    switch (pageType)
    {
    case NavigationButtons::NEWS:
        ui->horizontalLayout->addWidget(new QLabel(QString("Новости"), this));
        ui->horizontalLayout->addWidget(new QLabel(QString("Все новости"), this));
        break;
    case NavigationButtons::ACCOUNT:
        ui->horizontalLayout->addWidget(new QLabel(QString("Личный кабинет"), this));
        ui->horizontalLayout->addWidget(new QPushButton(QString("Выйти"), this));
        break;
    case NavigationButtons::SCHEDULE:
        if (userType == UserTypes::STUDENT || userType == UserTypes::TEACHER)
        {
            ui->horizontalLayout->addWidget(new QLabel(QString("Расписание занятий"), this));
            ui->horizontalLayout->addWidget(new QPushButton(QString("Календарь"), this));
        }
//    case NavigationButtons::COURSES:

//    case NavigationButtons::STATISTIC:

//    case NavigationButtons::LOG_OUT:

//    case NavigationButtons::USER_OPTIONS:

//    case NavigationButtons::SERVER_OPTIONS:
    }

//    if (pageType == NavigationButtons::)
//    {
//        ui->horizontalLayout->addWidget(QLabel(QString("Новости")));
//        ui->horizontalLayout->addWidget(QLabel(QString("Все новости")));
//    }
//    if ()
}
