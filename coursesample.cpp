#include "coursesample.h"
#include "ui_coursesample.h"

CourseSample::CourseSample(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CourseSample)
{
    ui->setupUi(this);
    ui->frame->setStyleSheet(
        "QFrame {"
        "border-radius: 15px;" // Радиус скругления углов
        "background-color: #e250f1;" // Цвет фона
        "}"
        );
}

CourseSample::~CourseSample()
{
    delete ui;
}
