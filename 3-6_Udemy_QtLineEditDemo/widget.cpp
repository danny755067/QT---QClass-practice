#include "widget.h"
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QDebug>
//學lineedit的各種signal和怎麼build lineedit
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //Fisrt Name
    QLabel *firstNameLabel = new QLabel("First Name",this);
    firstNameLabel->setMinimumSize(70,50);
    firstNameLabel->move(10,10);

    QLineEdit *firstNameLineEdit = new QLineEdit(this);
    firstNameLineEdit->setMinimumSize(200,50);
    firstNameLineEdit->move(100,10);

    //Last Name
    QLabel *lastNameLabel = new QLabel("Last Name",this);
    lastNameLabel->setMinimumSize(70,50);
    lastNameLabel->move(10,70);

    QLineEdit *lastNameLineEdit = new QLineEdit(this);
    lastNameLineEdit->setMinimumSize(200,50);
    lastNameLineEdit->move(100,70);

    //City
    QLabel *cityLabel = new QLabel("City",this);
    cityLabel->setMinimumSize(70,50);
    cityLabel->move(10,130);

    QLineEdit *cityLineEdit = new QLineEdit(this);
    cityLineEdit->setMinimumSize(200,50);
    cityLineEdit->move(100,130);

    QFont buttonFont("Times", 20, QFont::Bold);
    QPushButton *button = new QPushButton("Grab data", this);
    button->setFont(buttonFont);
    button->move(80,190);

    connect(button, &QPushButton::clicked,[=](){
       QString firstName = firstNameLineEdit->text();
       QString lastName = lastNameLineEdit->text();
       QString city = cityLineEdit->text();

       if(!firstName.isEmpty()&&!lastName.isEmpty()&&!city.isEmpty()){
            qDebug()<<"First name is : "<< firstName;
            qDebug()<<"Last name is : "<< lastName;
            qDebug()<<"City is : "<< city;
       }
       else{
           qDebug()<<"One field is empty";
       }

    });

    //Respond to signals from QLineEdits

    //cursorPositionChanged 打字時一直閃爍的'|'這個移動會發出signal
    //設定firstNameLineEdit這行的光標signal
    connect(firstNameLineEdit,&QLineEdit::cursorPositionChanged,[=](){
        qDebug() << "The current cursor position is : "<<firstNameLineEdit->cursorPosition();
    });


    //editingFinished : emitted when user clicks enter or when line edit loses focus
    //在firstNameLineEdit這行按enter或是光標從這行消失就會發出signal
    connect(firstNameLineEdit,&QLineEdit::editingFinished,[=](){
        qDebug() << "Editing finished" ;
    });


    //returnPressed
    //在firstNameLineEdit這行按enter就會發出signal
    connect(firstNameLineEdit,&QLineEdit::returnPressed,[=](){
       qDebug() << "Return pressed";
    });

    //selectionChanged
    //光標在firstNameLineEdit這行時，滑鼠左鍵按住只要有移動，就會發出Signal
    connect(firstNameLineEdit,&QLineEdit::selectionChanged,[=](){
       qDebug() << "Selection changed";
    });

    //textChanged
    //firstNameLineEdit這行text有改變就會發出signal
    connect(firstNameLineEdit,&QLineEdit::textChanged,[=](){
       qDebug() << "text changed to : "<<firstNameLineEdit->text();
    });

    //textEdited
    connect(firstNameLineEdit,&QLineEdit::textEdited,[=](){
       qDebug() << "text edited and changed to : "<<firstNameLineEdit->text();

    });

    //Change text in QLineEdit programmatically
    lastNameLineEdit->setText("Say your last name");

    //Hint text
    //可以設定有Hint一旦輸入text就會消失，沒有text則顯示
    firstNameLineEdit->setPlaceholderText("First name");
    lastNameLineEdit->setPlaceholderText("Last name");
    cityLineEdit->setPlaceholderText("City");
}

Widget::~Widget()
{

}

