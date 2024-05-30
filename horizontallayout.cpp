#include "horizontallayout.h"
#include "ui_horizontallayout.h"

HorizontalLayout::HorizontalLayout(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HorizontalLayout)
{
    ui->setupUi(this);
}

HorizontalLayout::~HorizontalLayout()
{
    delete ui;
}

void HorizontalLayout::addWidget(int row, QWidget *widget)
{
    switch (row)
    {
    case 0:
        ui->vL1->addWidget(widget);
        break;
    case 1:
        ui->vL2->addWidget(widget);
        break;
    case 2:
        ui->vL3->addWidget(widget);
        break;
    }
}
