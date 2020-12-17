#include "mainpage.h"
#include  <QPalette>
#include"gamewidget.h"
#include"game2widget.h"
#include<QPixmap>
MainPage::MainPage(QWidget *parent) : QWidget(parent)
{

    this->setAutoFillBackground(true);//设置父窗口背景可被覆盖填充
    this->resize(1200,730);
    this->setWindowTitle("贪吃蛇");
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/Images/bg2.jpg").scaled(this->size())));
    this->setPalette(palette);
    pButton1=new QPushButton(this);
    pButton1->setParent(this);
    //pButton1->setStyleSheet("QPushButton{background-color:yellow;border-style:outset;}");
    //pButton1->setText("无尽模式");
    pButton1->setGeometry(340,170,200,300);
    pButton1->setStyleSheet("border:none;");
    QPalette pal8(this->palette());
    pButton1->setIcon(QIcon(":/Images/wujin.png"));
    pButton1->setIconSize(QSize(190,170));
    connect(pButton1,SIGNAL(clicked(bool)),this,SLOT(M_startPush()));

    pButton2=new QPushButton(this);
    pButton2->setParent(this);
    //pButton1->setStyleSheet("QPushButton{background-color:yellow;border-style:outset;}");
   // pButton2->setText("");
    pButton2->setGeometry(550,240,120,160);
    pButton2->setStyleSheet("border:none;");
    //pButton2->setStyleSheet("QPushButton{background-image：url(/Images/taikong.png)}");
    QPalette pal9(this->palette());
    pButton2->setIcon(QIcon(":/Images/taikong.png"));
    pButton2->setAutoFillBackground(true);
    pButton2->setIconSize(QSize(250,120));

    connect(pButton2,SIGNAL(clicked(bool)),this,SLOT(M_startPush2()));

    pButton3=new QPushButton(this);
    pButton3->setParent(this);
    //pButton1->setStyleSheet("QPushButton{background-color:yellow;border-style:outset;}");
    //pButton1->setText("无尽模式");
    pButton3->setGeometry(700,185,200,300);
    pButton3->setStyleSheet("border:none;");
   // QPalette pal10(this->palette());
    pButton3->setIcon(QIcon(":/Images/xianshi.png"));
    pButton3->setIconSize(QSize(230,240));
     connect(pButton3,SIGNAL(clicked(bool)),this,SLOT(M_startPush3()));
    //connect(pButton1,SIGNAL(clicked(bool)),this,SLOT(M_startPush()));


    ExitPush1=new QPushButton(this);
    ExitPush1->setParent(this);
    //pButton1->setStyleSheet("QPushButton{background-color:yellow;border-style:outset;}");
   // ExitPush1->setText("返回");
    ExitPush1->setGeometry(1000,500,60,60);
    QPalette pal11(this->palette());
    ExitPush1->setStyleSheet("border:none;");
    ExitPush1->setIcon(QIcon(":/Images/return.png"));
    ExitPush1->setIconSize(QSize(60,60));
     connect(ExitPush1,SIGNAL(clicked(bool)),this,SLOT(M_exitPush1()));

   // pButton1->setStyleSheet("border:none;");
   // QPalette pal1(this->palette());
   // pButton1->setIcon(QIcon(":/myImages/Images/my35.PNG"));
   // pButton1->setIconSize(QSize(60,60));
}
void MainPage::M_exitPush1()
{
    this->close();
    delete this;
}
void MainPage::M_startPush()
{
    gamewindow=new Gamewidget(this);  //创建一个新的界面，任然以原来的界面为父窗口，退出后可以直接回到上一个界面。
    gamewindow->show();
}

void MainPage::M_startPush2()
{
    game2window=new game2widget(this);  //创建一个新的界面，任然以原来的界面为父窗口，退出后可以直接回到上一个界面。
    game2window->show();
}

void MainPage::M_startPush3()
{
    game3window=new game3widget(this);  //创建一个新的界面，任然以原来的界面为父窗口，退出后可以直接回到上一个界面。
    game3window->show();
}
void MainPage::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/Images/bk4.jpg");


    //绘图操作
    painter.drawPixmap(0,0,this->width(),this->height(),pix);


}
