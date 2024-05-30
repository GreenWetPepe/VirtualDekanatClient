#ifndef GRAPHSTATICTEACHER_H
#define GRAPHSTATICTEACHER_H

#include <QWidget>

namespace Ui {
class GraphStaticTeacher;
}

class GraphStaticTeacher : public QWidget
{
    Q_OBJECT

public:
    explicit GraphStaticTeacher(QWidget *parent = nullptr);
    ~GraphStaticTeacher();

private:
    Ui::GraphStaticTeacher *ui;
};

#endif // GRAPHSTATICTEACHER_H
