#ifndef WIDGET_H
#define WIDGET_H
#include<QLabel>
#include <QWidget>
#include<QWidget>
#include<QIcon>
#include<QPalette>
#include<QBrush>
#include<QPixmap>
#include<QPushButton>
#include<QMessageBox>
#include<QPalette>
#include<QPixmap>
//#include"gamewidget.h"
#include"mainpage.h"
#include<QPaintEvent>
class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void paintEvent(QPaintEvent*);
    QPushButton *startPush;
    QPushButton *exitPush;
    QMessageBox *exitBox;
    QLabel *Label1;

    MainPage *mainPage1;




public slots: void M_startPush();
              void M_exitPush();
};


#endif // WIDGET_H
