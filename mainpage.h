#ifndef MAINPAGE_H
#define MAINPAGE_H
#include<QPushButton>
#include"gamewidget.h"
#include"game2widget.h"
#include"game3widget.h"
#include<QPaintEvent>
class MainPage:public QWidget
{
     Q_OBJECT
public:
     explicit MainPage(QWidget *parent = 0);
    MainPage();
    QPushButton *pButton1;
    QPushButton *pButton2;
    QPushButton *pButton3;
    QPushButton *ExitPush1;
    void paintEvent(QPaintEvent*);
    Gamewidget *gamewindow;//声明一个新的界面
    game2widget *game2window;//声明一个新的界面
    game3widget *game3window;//声明一个新的界面

public slots:
    void M_exitPush1();
    void M_startPush();
     void M_startPush2();
     void M_startPush3();
};

#endif // MAINPAGE_H
