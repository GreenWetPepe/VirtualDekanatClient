#include "coursesample.h"
#include "ui_coursesample.h"

#include <QDebug>

CourseSample::CourseSample(QString courseName, std::vector<QString> teachers, int courseId, QWidget *parent) :
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

    this->courseId = courseId;

    ui->courseL->setText(courseName);
    ui->supportL->setText(teachers[0]);

    int x = ui->supportL->geometry().x(), y = ui->supportL->geometry().y();
    for (int i = 1; i < teachers.size(); i++)
    {
        QLabel *label = new QLabel(ui->frame);

        // Копируем текст из существующего QLabel в новый QLabel
        label->setText(teachers[i]);

        // Копируем другие свойства
        label->setAlignment(ui->supportL->alignment());
        label->setStyleSheet(ui->supportL->styleSheet());
        label->setFont(ui->supportL->font());
        label->setGeometry(x, y + 20, 140, 20);
        y += 20;
        label->show();
    }
}

CourseSample::CourseSample(QString testName, int testId, QWidget *parent) :
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

    ui->courseL->setText(testName);
    ui->label->hide();
    ui->supportL->hide();
    courseId = testId;
}

CourseSample::~CourseSample()
{
    delete ui;
}

void CourseSample::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton)
    {
        if (!ui->supportL->isHidden()) emit openTests(courseId, ui->courseL->text());
        else emit openTest(courseId, ui->courseL->text());
    }

    QWidget::mousePressEvent(event);
}
