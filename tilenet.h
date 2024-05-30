#ifndef TILENET_H
#define TILENET_H

#include <QWidget>

namespace Ui {
class TileNet;
}

class TileNet : public QWidget
{
    Q_OBJECT

public:
    explicit TileNet(QWidget *parent = nullptr);
    ~TileNet();

    void addTile(QWidget *widget);

private:
    Ui::TileNet *ui;
    int lastRow = 0, lastColumn = 0;
};

#endif // TILENET_H
