#ifndef SCHEDULESAMPLE_H
#define SCHEDULESAMPLE_H

#include <QWidget>

namespace Ui {
class ScheduleSample;
}

class ScheduleSample : public QWidget
{
    Q_OBJECT

public:
    explicit ScheduleSample(QWidget *parent = nullptr);
    ~ScheduleSample();

private:
    Ui::ScheduleSample *ui;
};

#endif // SCHEDULESAMPLE_H
