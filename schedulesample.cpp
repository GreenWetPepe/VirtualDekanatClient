#include "schedulesample.h"
#include "ui_schedulesample.h"

ScheduleSample::ScheduleSample(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScheduleSample)
{
    ui->setupUi(this);
}

ScheduleSample::~ScheduleSample()
{
    delete ui;
}
