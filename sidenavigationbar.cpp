#include "sidenavigationbar.h"
#include "ui_sidenavigationbar.h"

#include "clientdata.h"
#include "navigationbutton.h"

SideNavigationBar::SideNavigationBar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SideNavigationBar)
{
    ui->setupUi(this);
    updateBar();
}

SideNavigationBar::~SideNavigationBar()
{
    delete ui;
}

void SideNavigationBar::updateBar()
{
    QLayoutItem *item;
    while((item = ui->verticalLayout->takeAt(0)) != nullptr)
    {
        delete item->widget();
    }

    for (auto &btn : USER_NAVIGATION[ClientData::getUserType()])
    {
        ui->verticalLayout->addWidget(new NavigationButton(btn, this));
//        switch (btn)
//        {
//        case NavigationButtons::NEWS:
//            ui->verticalLayout->addWidget(new QPushButton(QString("NEWS"), this));
//            break;
//        case NavigationButtons::ACCOUNT:
//            ui->verticalLayout->addWidget(new QPushButton(QString("ACCOUNT"), this));
//            break;
//        case NavigationButtons::SCHEDULE:
//            ui->verticalLayout->addWidget(new QPushButton(QString("SCHEDULE"), this));
//            break;
//        case NavigationButtons::COURSES:
//            ui->verticalLayout->addWidget(new QPushButton(QString("COURSES"), this));
//            break;
//        case NavigationButtons::STATISTIC:
//            ui->verticalLayout->addWidget(new QPushButton(QString("STATISTIC"), this));
//            break;
//        case NavigationButtons::LOG_OUT:
//            ui->verticalLayout->addWidget(new QPushButton(QString("LOG_OUT"), this));
//            break;
//        case NavigationButtons::USER_OPTIONS:
//            ui->verticalLayout->addWidget(new QPushButton(QString("USER_OPTIONS"), this));
//            break;
//        case NavigationButtons::SERVER_OPTIONS:
//            ui->verticalLayout->addWidget(new QPushButton(QString("SERVER_OPTIONS"), this));
//            break;
//        }
    }
}
