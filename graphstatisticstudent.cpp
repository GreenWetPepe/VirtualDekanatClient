#include "graphstatisticstudent.h"
#include "ui_graphstatisticstudent.h"

GraphStatisticStudent::GraphStatisticStudent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GraphStatisticStudent)
{
    ui->setupUi(this);
}

GraphStatisticStudent::~GraphStatisticStudent()
{
    delete ui;
}
