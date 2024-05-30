#ifndef GRAPHSTATISTICSTUDENT_H
#define GRAPHSTATISTICSTUDENT_H

#include <QWidget>

namespace Ui {
class GraphStatisticStudent;
}

class GraphStatisticStudent : public QWidget
{
    Q_OBJECT

public:
    explicit GraphStatisticStudent(QWidget *parent = nullptr);
    ~GraphStatisticStudent();

private:
    Ui::GraphStatisticStudent *ui;
};

#endif // GRAPHSTATISTICSTUDENT_H
