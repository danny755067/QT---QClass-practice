#include "widget.h"
#include "ui_widget.h"
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */
#include <QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //Initialize
    srand (time(NULL));

    //Generate
    secretNumber = rand() % 10 + 1;
    qDebug()<<"Secret Number generate : "<<QString::number(secretNumber);

    ui->startOverButton->setDisabled(true);

    //Clear the message label
    ui->messageLabel->setText("");

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_guessButton_clicked()
{
    guessNumber = ui->spinBox->value();
    qDebug() << "The guess number is : "<< QString::number(guessNumber);

    if(guessNumber >secretNumber){
        //qDebug()<<"The answer is smaller than what you guess!";
        //顯示在compiler
        ui->messageLabel->setText("The answer is smaller than what you guess!");
    }
    else if(guessNumber < secretNumber){
        //qDebug()<<"The answer is bigger than what you guess!";
        ui->messageLabel->setText("The answer is bigger than what you guess!");
    }
    else{
        //qDebug()<<"That's the answer!";
        ui->messageLabel->setText("Congratuations, the answer is :"+QString::number(secretNumber));

        //Disable the guess button
        ui->guessButton->setDisabled(true);
        ui->startOverButton->setDisabled(false);
    }
}

void Widget::on_startOverButton_clicked()
{
    //Enable the Guess Button
    ui->guessButton->setDisabled(false);

    //Disable the Start Over Button
    ui->startOverButton->setDisabled(true);

    //Put the spinBox(選數字的) back to 1;
    ui->spinBox->setValue(1);

    //Regenerate the random number
    secretNumber = rand() % 10 + 1;

    //Clear the message label
    ui->messageLabel->setText("");


}
