#ifndef PAGECONTENT_H
#define PAGECONTENT_H

#include <QWidget>

namespace Ui {
class PageContent;
}

class PageContent : public QWidget
{
    Q_OBJECT

public:
    explicit PageContent(int userType, int pageType, QWidget *parent = nullptr);
    ~PageContent();

    void changeContent();

private:
    Ui::PageContent *ui;
};

#endif // PAGECONTENT_H
