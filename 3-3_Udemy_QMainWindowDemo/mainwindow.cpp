#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QMenuBar>
#include <QDebug>
#include <QStatusBar>
#include <QAction>
#include <QApplication>
#include <QObject>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //Add central widget
    QPushButton *button = new QPushButton("Hello",this);
    setCentralWidget(button);//button放在widget正中央

    //Declare Quit Action
    QAction * quitAction = new QAction("Quit",this);
    connect(quitAction, &QAction::triggered,[=](){
        QApplication::quit();
    });

    //Add menus
    QMenu *fileMenu = menuBar()->addMenu("File");
    fileMenu->addAction(quitAction);
    menuBar()->addMenu("Edit");
    menuBar()->addMenu("Window");
    menuBar()->addMenu("Settings");
    menuBar()->addMenu("Help");

    //Add status bar message
    statusBar()->showMessage("Uploading file...",3000);//3000ms
    //statusBar()->clearMessage();//可以把statusbar清掉
}

MainWindow::~MainWindow()
{
    delete ui;
}

QSize MainWindow::sizeHint() const
{
    return QSize(800,500);
}
