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

    void clearContent();

    void changeContent(int userType, int pageType);

    void changeToTests(int courseId);

    void changeToTest(int testId);

private:
    Ui::PageContent *ui;

    QWidget *page;
};

#endif // PAGECONTENT_H
