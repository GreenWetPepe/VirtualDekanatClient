#include "pagecontent.h"
#include "ui_pagecontent.h"

#include "server.h"
#include "clientdata.h"

#include "news.h"
#include "tilenet.h"
#include "coursesample.h"
#include "horizontallayout.h"
#include "schedulesample.h"
#include "studentaccount.h"
#include "teacheraccount.h"
#include "page.h"

#include <QLabel>
#include <QDebug>
#include <QLayoutItem>
#include <QPushButton>

PageContent::PageContent(int userType, int pageType, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageContent)
{
    ui->setupUi(this);

    page = parent;

    changeContent(userType, pageType);
}

PageContent::~PageContent()
{
    delete ui;
}

void PageContent::clearContent()
{
    QLayoutItem *item;
    while((item = ui->horizontalLayout->takeAt(0)) != nullptr)
    {
        delete item->widget();
        delete item;
    }
}

void PageContent::changeContent(int userType, int pageType)
{
    clearContent();

    switch (pageType)
    {
    case NavigationButtons::NEWS:
    {
        QWidget *newsWidget = new News(this);
        ui->horizontalLayout->addWidget(newsWidget);
        newsWidget->show();
//        ui->horizontalLayout->takeAt(0)->widget()->show();
        break;
    }
    case NavigationButtons::ACCOUNT:
        if (ClientData::getUserType() == UserTypes::STUDENT)
        {
            QWidget *account = new StudentAccount(ClientData::getUserId(), this);
            ui->horizontalLayout->addWidget(account);
            account->show();
        }
        else if (ClientData::getUserType() == UserTypes::TEACHER)
        {
            QWidget *account = new TeacherAccount(ClientData::getUserId(), this);
            ui->horizontalLayout->addWidget(account);
            account->show();
        }
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
        QJsonArray response;
        if (ClientData::getUserType() == UserTypes::TEACHER)
        {
            response = Server::sendRequest("http://localhost:5000/api/v1/disciplines?user_id" + std::to_string(ClientData::getUserId()));
        }
        else if (ClientData::getUserType() == UserTypes::STUDENT)
        {
            response = Server::sendRequest("http://localhost:5000/api/v1/disciplines");
        }

        std::vector<QString> usedCourses;
        for (int i = 0; i < response.size(); i++)
        {
            bool isUsed = false;
            for (int j = 0; j < usedCourses.size(); j++)
            {
                if (response.at(i).toObject()["discipline_name"].toString() == usedCourses[j])
                {
                    isUsed = true;
                    break;
                }
            }
            if (isUsed) continue;

            std::vector<QString> teachers;
            QString courseName = response.at(i).toObject()["discipline_name"].toString();
            int courseId = response.at(i).toObject()["discipline_id"].toInt();
            for (int j = i; j < response.size(); j++)
            {
                if (courseName == response.at(j).toObject()["discipline_name"].toString())
                {
                    teachers.push_back(response.at(j).toObject()["teacher_full_name"].toString());
                }
            }

            CourseSample *course = new CourseSample(courseName, teachers, courseId, tileNet);
            connect(course, &CourseSample::openTests, qobject_cast<Page*>(parent()), &Page::changeFormToTests);
            tileNet->addTile(course);

            usedCourses.push_back(courseName);
        }

        ui->horizontalLayout->addWidget(tileNet);
        tileNet->show();
        break;
    }
}

void PageContent::changeToTests(int courseId)
{
    clearContent();

    TileNet *tileNet = new TileNet(this);
    QJsonArray response = Server::sendRequest("http://localhost:5000/api/v1/tests?discipline_id=" + std::to_string(courseId));

    qDebug() << response;
    for (int i = 0; i < response.size(); i++)
    {
        QString testName = response.at(i).toObject()["test_name"].toString();
        int testId = response.at(i).toObject()["test_id"].toInt();

        CourseSample *test = new CourseSample(testName, testId, tileNet);
        connect(test, &CourseSample::openTest, qobject_cast<Page*>(parent()), &Page::changeFormToTest);
        tileNet->addTile(test);
    }

    ui->horizontalLayout->addWidget(tileNet);
    tileNet->show();
}

void PageContent::changeToTest(int testId)
{

}


