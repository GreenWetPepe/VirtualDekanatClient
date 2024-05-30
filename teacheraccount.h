#ifndef TEACHERACCOUNT_H
#define TEACHERACCOUNT_H

#include <QWidget>

namespace Ui {
class TeacherAccount;
}

class TeacherAccount : public QWidget
{
    Q_OBJECT

public:
    explicit TeacherAccount(QWidget *parent = nullptr);
    ~TeacherAccount();

private:
    Ui::TeacherAccount *ui;
};

#endif // TEACHERACCOUNT_H
