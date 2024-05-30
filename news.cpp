#include "news.h"

#include "ui_news.h"



News::News(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::News)
{
    ui->setupUi(this);
}

News::~News()
{
    delete ui;
}

