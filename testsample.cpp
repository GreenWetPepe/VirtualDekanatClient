#include "testsample.h"
#include "ui_testsample.h"

TestSample::TestSample(QString testName, int testId, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestSample)
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

TestSample::~TestSample()
{
    delete ui;
}

void TestSample::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton)
    {
        emit openTest(courseId, ui->courseL->text());
    }

    QWidget::mousePressEvent(event);
}
