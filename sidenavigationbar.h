#ifndef SIDENAVIGATIONBAR_H
#define SIDENAVIGATIONBAR_H

#include <QWidget>

namespace Ui {
class SideNavigationBar;
}

class SideNavigationBar : public QWidget
{
    Q_OBJECT

public:
    explicit SideNavigationBar(QWidget *parent = nullptr);
    ~SideNavigationBar();

    void updateBar();

private:
    Ui::SideNavigationBar *ui;
};

#endif // SIDENAVIGATIONBAR_H
