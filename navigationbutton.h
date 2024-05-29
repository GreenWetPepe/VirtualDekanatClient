#ifndef NAVIGATIONBUTTON_H
#define NAVIGATIONBUTTON_H

#include <QMouseEvent>
#include <QPushButton>



class NavigationButton : public QPushButton
{
    Q_OBJECT

public:
    explicit NavigationButton(int type, QWidget *parent = nullptr);

signals:
    void changePageWidget(int pageType);

private:
    int type;

protected:
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // NAVIGATIONBUTTON_H
