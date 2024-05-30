#include "pagecontent.h"
#include "ui_pagecontent.h"

#include "states.cpp"
#include "news.h"
#include "tilenet.h"
#include "coursesample.h"
#include "horizontallayout.h"
#include "schedulesample.h"

#include <QLabel>
#include <QDebug>
#include <QLayoutItem>
#include <QPushButton>

PageContent::PageContent(int userType, int pageType, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageContent)
{
    ui->setupUi(this);

    changeContent(userType, pageType);
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
        delete item;
        qDebug() << "Deleted";
    }

    QWidget *newsWidget = new News(this);

    switch (pageType)
    {
    case NavigationButtons::NEWS:
    {
        ui->horizontalLayout->addWidget(newsWidget);
        newsWidget->show();
//        ui->horizontalLayout->takeAt(0)->widget()->show();
        break;
    }
    case NavigationButtons::ACCOUNT:
        ui->horizontalLayout->addWidget(new QLabel(QString("Личный кабинет"), this));
        ui->horizontalLayout->addWidget(new QPushButton(QString("Выйти"), this));
        break;
    case NavigationButtons::SCHEDULE:
    {
        HorizontalLayout *horLay = new HorizontalLayout(this);
        for (int i = 0; i < 10; i++)
        {
            horLay->addWidget(0, new ScheduleSample(horLay));
        }
        for (int i = 0; i < 3; i++)
        {
            horLay->addWidget(1, new ScheduleSample(horLay));
        }
        for (int i = 0; i < 7; i++)
        {
            horLay->addWidget(2, new ScheduleSample(horLay));
        }
        ui->horizontalLayout->addWidget(horLay);
        horLay->show();
        break;
    }
    case NavigationButtons::COURSES:
        TileNet *tileNet = new TileNet(this);
        for (int i = 0; i < 40; i++)
        {
            tileNet->addTile(new CourseSample(tileNet));
        }
        ui->horizontalLayout->addWidget(tileNet);
        tileNet->show();
        break;
    }
}
