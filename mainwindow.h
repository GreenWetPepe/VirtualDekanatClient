#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "sidenavigationbar.h"
#include "page.h"

#include <QMainWindow>
#include <QResizeEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void changePageWidget(int pageType);

private:
    Ui::MainWindow *ui;
    SideNavigationBar *sideNavBar;
    Page *pageWidget;

    void resizeEvent(QResizeEvent *event);
};
#endif // MAINWINDOW_H
