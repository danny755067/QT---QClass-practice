#include "widget.h"
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QDebug>



    //signal test
    /*
     *copy
     *paste
     *undo
     *redo
     *setHtml
     *setPlainText
     */
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //可以在成員裡新增func用func call功能
    setupUI();

    //整個視窗大小
    setFixedSize(1000,1000);

}

Widget::~Widget()
{

}

void Widget::setupUI()
{
    QFont labelFont("Times", 10, QFont::Bold);
    QLabel *mLabel = new QLabel("This is my text",this);
    mLabel->setFont(labelFont);
    mLabel->move(100,25);

    QTextEdit *textEdit = new QTextEdit(this);
    textEdit->move(70,55);

    //textChanged
    //text有改動都會發出signal
    connect(textEdit, &QTextEdit::textChanged, [=](){
       qDebug() << "Text changed";
    });


    //Copy, Cut and Paste
    QPushButton *copyButton = new QPushButton("Copy", this);
    copyButton->setMinimumSize(50,25);
    copyButton->move(10,250);
    connect(copyButton, &QPushButton::clicked,[=](){
       textEdit->copy();
    });

    QPushButton *cutButton = new QPushButton("Cut", this);
    cutButton->setMinimumSize(50,25);
    cutButton->move(110,250);
    connect(cutButton, &QPushButton::clicked,[=](){
       textEdit->cut();
    });

    QPushButton *pasteButton = new QPushButton("Paste", this);
    pasteButton->setMinimumSize(50,25);
    pasteButton->move(210,250);
    connect(pasteButton, &QPushButton::clicked, [=](){
       textEdit->paste();
    });

    //Undo Redo
    QPushButton *undoButton = new QPushButton("Undo",this);
    undoButton->setMinimumSize(50,25);
    undoButton->move(10,280);
    connect(undoButton, &QPushButton::clicked, [=](){
        textEdit->undo();
    });


    QPushButton *redoButton = new QPushButton("Redo",this);
    redoButton->setMinimumSize(50,25);
    redoButton->move(110,280);
    connect(redoButton, &QPushButton::clicked, [=](){
        textEdit->redo();
    });

    //Set text and html to the text edit
    QPushButton *plainTextButton = new QPushButton("Plain Text", this);
    plainTextButton->setMinimumSize(100,25);
    plainTextButton->move(10,310);
    connect(plainTextButton, &QPushButton::clicked, [=](){
        textEdit->setPlainText("Hello there");
    });
    //可以顯示HTML類型的字元
    QPushButton *htmlButton = new QPushButton("Html", this);
    htmlButton->setMinimumSize(100,25);
    htmlButton->move(120,310);
    connect(htmlButton, &QPushButton::clicked, [=](){
        textEdit->setHtml("www.google.com");
    });

    //Grab text and html
    //獲取Text介面上的text資訊
    QPushButton *grabTextButton = new QPushButton("Grab Text",this);
    grabTextButton->setMinimumSize(100,25);
    grabTextButton->move(10,340);
    connect(grabTextButton, &QPushButton::clicked, [=](){
        qDebug() << "The plain text inside the text edit is :"<<textEdit->toPlainText();
    });

    QPushButton *grabHtmlButton = new QPushButton("Grab Html",this);
    grabHtmlButton->setMinimumSize(100,25);
    grabHtmlButton->move(120,340);
    connect(grabHtmlButton, &QPushButton::clicked, [=](){
        qDebug() << "The html inside the text edit is :"<<textEdit->toHtml();
    });
}
