#ifndef STUDENTACCOUNT_H
#define STUDENTACCOUNT_H

#include <QWidget>

namespace Ui {
class StudentAccount;
}

class StudentAccount : public QWidget
{
    Q_OBJECT

public:
    explicit StudentAccount(QWidget *parent = nullptr);
    ~StudentAccount();

private:
    Ui::StudentAccount *ui;
};

#endif // STUDENTACCOUNT_H
