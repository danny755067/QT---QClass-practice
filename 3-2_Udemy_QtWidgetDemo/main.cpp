#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    //初始化視窗標題可以在這裡進行
    w.setWindowTitle("Danny");
    w.show();

    return a.exec();
}
