#include "teacheraccount.h"
#include "ui_teacheraccount.h"

TeacherAccount::TeacherAccount(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TeacherAccount)
{
    ui->setupUi(this);
}

TeacherAccount::~TeacherAccount()
{
    delete ui;
}
