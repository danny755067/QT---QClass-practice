#include "widget.h"
#include "ui_widget.h"
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent)

{


    //加label到widget裡
    QLabel *label = new QLabel("Hello There",this);

    //constructor 可以初始化視窗標題
    //這個function是public可以在外部main裡call
    //setWindowTitle("Danny");


    //Add a styled widget and move it around
    QPalette label1Palette;//改字體顏色和字體背景顏色
    label1Palette.setColor(QPalette::Window,Qt::yellow);//會發現這句改不動背景
    label1Palette.setColor(QPalette::WindowText,Qt::blue);



    QFont label1Font("Times", 18, QFont::Bold);//QFont是改字體的Class,可以直接從說明貼過來，數字是字體大小

    QLabel * label1 = new QLabel(this);
    label1->setAutoFillBackground(true);//要改字體背景要加這行
    label1->setFont(label1Font);
    label1->setPalette(label1Palette);
    label1->setText("My colored label");//只寫這句會跟上面Hello There疊在一起
    label1->move(50,50);//(往右,往下)




    //Add a styled widget and move it around
    QPalette label2Palette;
    label2Palette.setColor(QPalette::Window,Qt::green);
    label2Palette.setColor(QPalette::WindowText,Qt::black);



    QFont label2Font("Times", 20, QFont::Bold);

    QLabel * label2 = new QLabel(this);
    label2->setAutoFillBackground(true);
    label2->setFont(label2Font);
    label2->setPalette(label2Palette);
    label2->setText("My colored label 2");
    label2->move(70,170);//(往右,往下)

    QFont buttonFont("Times", 30, QFont::Bold);
    QPushButton *button = new QPushButton(this);
    button->setText("Click Me");
    button->move(100,250);
    button->setFont(buttonFont);
    connect(button, SIGNAL(clicked()),this,SLOT(buttonClicked()));

}

Widget::~Widget()
{

}

QSize Widget::sizeHint() const
{
    return QSize(700,500);
}

void Widget::buttonClicked()
{
    QMessageBox::information(this,"Message","You clicked on my button");
}
