#ifndef HORIZONTALLAYOUT_H
#define HORIZONTALLAYOUT_H

#include <QWidget>

namespace Ui {
class HorizontalLayout;
}

class HorizontalLayout : public QWidget
{
    Q_OBJECT

public:
    explicit HorizontalLayout(QWidget *parent = nullptr);
    ~HorizontalLayout();

    void addWidget(int row, QWidget *widget);

private:
    Ui::HorizontalLayout *ui;
};

#endif // HORIZONTALLAYOUT_H
