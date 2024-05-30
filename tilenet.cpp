#include "tilenet.h"
#include "ui_tilenet.h"

TileNet::TileNet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TileNet)
{
    ui->setupUi(this);
}

TileNet::~TileNet()
{
    delete ui;
//    for (int i = 0; i < ui->gridLayout_2->rowCount(); i++)
//    {
//        for (int j = 0; j < ui->gridLayout_2->columnCount(); j++)
//        {
//            if (ui->scrollAreaWidgetContents->item)
//        }
//    }
}

void TileNet::addTile(QWidget *widget)
{
    ui->gridLayout->addWidget(widget, lastRow, lastColumn);
    widget->show();
    lastColumn++;
    if (lastColumn == 3)
    {
        lastRow++;
        lastColumn = 0;
    }
}
