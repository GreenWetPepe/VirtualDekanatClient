#ifndef TESTSAMPLE_H
#define TESTSAMPLE_H

#include <QMouseEvent>
#include <QWidget>

namespace Ui {
class TestSample;
}

class TestSample : public QWidget
{
    Q_OBJECT

public:
    explicit TestSample(QString testName, int testId, QWidget *parent = nullptr);
    ~TestSample();

signals:
    void openTest(int testId, QString testName);

private:
    Ui::TestSample *ui;

    int courseId;

protected:
    void mousePressEvent(QMouseEvent *event);
};

#endif // TESTSAMPLE_H
