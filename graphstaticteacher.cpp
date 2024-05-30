#include "graphstaticteacher.h"
#include "ui_graphstaticteacher.h"

GraphStaticTeacher::GraphStaticTeacher(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GraphStaticTeacher)
{
    ui->setupUi(this);
}

GraphStaticTeacher::~GraphStaticTeacher()
{
    delete ui;
}
