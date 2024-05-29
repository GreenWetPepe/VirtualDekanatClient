#ifndef PAGE_H
#define PAGE_H

#include <QWidget>

#include "pagecontent.h"
#include "pagetitle.h"

namespace Ui {
class Page;
}

class Page : public QWidget
{
    Q_OBJECT

public:
    explicit Page(int userType, int pageType, QWidget *parent = nullptr);
    ~Page();

    void changeForm(int userType, int pageType);

private:
    Ui::Page *ui;

    PageTitle *title;
    PageContent *content;
};

#endif // PAGE_H
