#include "page.h"
#include "pagecontent.h"
#include "pagetitle.h"
#include "ui_page.h"

#include <QDebug>

Page::Page(int userType, int pageType, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Page)
{
    ui->setupUi(this);

    title = new PageTitle(userType, pageType, this);
    content = new PageContent(userType, pageType, this);

    title->setMinimumHeight(70);
    title->setMaximumHeight(70);

    ui->verticalLayout->addWidget(title);
    ui->verticalLayout->addWidget(content);
}

Page::~Page()
{
    delete ui;
}

void Page::changeForm(int userType, int pageType)
{
    title->changeTitle(userType, pageType);
    content->changeContent(userType, pageType);
}

void Page::changeFormToTests(int courseId, QString courseName)
{
    title->changeToTests(courseName);
    content->changeToTests(courseId);
}

void Page::changeFormToTest(int testId, QString testName)
{
    title->changeToTests(testName);
    content->changeToTest(testId);
}
