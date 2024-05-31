#ifndef COURSESAMPLE_H
#define COURSESAMPLE_H


#include <QMouseEvent>
#include <QWidget>

namespace Ui {
class CourseSample;
}

class CourseSample : public QWidget
{
    Q_OBJECT

public:
    explicit CourseSample(QString courseName, std::vector<QString> teachers, int courseId, QWidget *parent = nullptr);
    ~CourseSample();

signals:
    void openTests(int courseId, QString courseName);

private:
    Ui::CourseSample *ui;

    int courseId;

protected:
    void mousePressEvent(QMouseEvent *event);
};

#endif // COURSESAMPLE_H
