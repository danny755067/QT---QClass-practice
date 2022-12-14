#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include <QObject>



class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    QSize sizeHint() const;
signals:
public slots:
private slots:
    void buttonClicked();
};

#endif // WIDGET_H
