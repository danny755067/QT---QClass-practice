#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QMessageBox>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPushButton *button = new QPushButton(this);
    button->setText("Click Me");
    button->move(200,200);
    connect(button, &QPushButton::clicked,[=](){

        /*
        //The Hard Way
        QMessageBox message;
        message.setMinimumSize(300,200);//設定訊息大小
        message.setWindowTitle("Message Title");
        message.setText("Something happened");
        message.setInformativeText("Do you want to do something about it ?");
        message.setIcon(QMessageBox::Critical);//會顯示錯誤的圖
        message.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel| QMessageBox::Save );//設定按鈕
        message.setDefaultButton(QMessageBox::Cancel);


        int ret = message.exec();
        */



        //以下可以做到類似效果，還能改messagebox種類
        /*
        //critical message圖案是紅X
        int ret = QMessageBox::critical(this,"Message Title","Something happened. Do you want to do something about it ?",QMessageBox::Ok | QMessageBox::Cancel);
        */
        /*
        //information message圖案是藍!
        int ret = QMessageBox::information(this,"Message Title","Something happened. Do you want to do something about it ?",QMessageBox::Ok | QMessageBox::Cancel);
        */
        /*
        //question message圖案是藍?
        int ret = QMessageBox::question(this,"Message Title","Something happened. Do you want to do something about it ?",QMessageBox::Ok | QMessageBox::Cancel);
        */

        //warning message圖案是黃!
        int ret = QMessageBox::warning(this,"Message Title","Something happened. Do you want to do something about it ?",QMessageBox::Ok | QMessageBox::Cancel);

        if(ret == QMessageBox::Ok){
            qDebug()<<"User clicked on OK";
        }
        else if (ret == QMessageBox::Cancel){
            qDebug()<<"User clicked on Cancel";
        }
    });
}

Widget::~Widget()
{
    delete ui;
}
