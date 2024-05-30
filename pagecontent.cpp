#include "pagecontent.h"
#include "ui_pagecontent.h"

#include "states.cpp"

#include <QLabel>
#include <QLayoutItem>
#include <QPushButton>

PageContent::PageContent(int userType, int pageType, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageContent)
{
    ui->setupUi(this);
}

PageContent::~PageContent()
{
    delete ui;
}

void PageContent::changeContent(int userType, int pageType)
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
    }
}
