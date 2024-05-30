#include "studentaccount.h"
#include "ui_studentaccount.h"

StudentAccount::StudentAccount(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentAccount)
{
    ui->setupUi(this);

}

StudentAccount::~StudentAccount()
{
    delete ui;
}
