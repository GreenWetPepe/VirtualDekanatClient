#ifndef PAGETITLE_H
#define PAGETITLE_H

#include <QWidget>

namespace Ui {
class PageTitle;
}

class PageTitle : public QWidget
{
    Q_OBJECT

public:
    explicit PageTitle(int userType, int pageType, QWidget *parent = nullptr);
    ~PageTitle();

    void clearContent();

    void changeTitle(int userType, int pageType);

    void changeToTests(QString courseName);

private:
    Ui::PageTitle *ui;

    int userType;
    int pageType;
};

#endif // PAGETITLE_H
