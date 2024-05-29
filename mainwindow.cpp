#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "clientdata.h"

#include <QHBoxLayout>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QHBoxLayout *layout = new QHBoxLayout(ui->centralwidget);
    sideNavBar = new SideNavigationBar(this);
    pageWidget = new Page(ClientData::getUserType(), NavigationButtons::NEWS, this);

    sideNavBar->setMaximumWidth(100);


    layout->addWidget(sideNavBar);
    layout->addWidget(pageWidget);
    setCentralWidget(ui->centralwidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    qDebug() << event->size();
}

void MainWindow::changePageWidget(int pageType)
{
    qDebug() << "Меняем страницу на " << pageType;
    pageWidget->changeForm(ClientData::getUserType(), pageType);
}

