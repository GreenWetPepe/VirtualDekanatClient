#ifndef COURSESAMPLE_H
#define COURSESAMPLE_H

#include <QWidget>

namespace Ui {
class CourseSample;
}

class CourseSample : public QWidget
{
    Q_OBJECT

public:
    explicit CourseSample(QWidget *parent = nullptr);
    ~CourseSample();

private:
    Ui::CourseSample *ui;
};

#endif // COURSESAMPLE_H
