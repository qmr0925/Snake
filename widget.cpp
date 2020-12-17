#include "widget.h"
//#include"gamewidget.h"
#include"mainpage.h"
#include<QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    this->resize(1200,730);
    this->setWindowTitle("贪吃蛇");
    //this->setWindowIcon(QIcon(":/Picture/img/WindowPicture.jpg"));
   QPalette palette;
   palette.setBrush(QPalette::Background,QBrush(QPixmap(":/Images/bk1.webp")));
    //this->setStyleSheet("background-image:url(qrc:/new/Gamewindow/img/GameBack.jpg)");
    //this->setPalette(palette);

    startPush=new QPushButton(this);
    exitPush=new QPushButton(this);
    startPush->setIconSize(QSize(920,45));
    startPush->setGeometry(540,375,90,45);
    startPush->setText("Start");
    //startPush->setIcon(QIcon(":/Picture/img/Start.png"));
    startPush->setFlat(1);
    startPush->setStyleSheet("color:white");
    exitPush->setIconSize(QSize(90,45));
    exitPush->setGeometry(540,430,90,45);
    exitPush->setText("Exit");
    exitPush->setStyleSheet("color:white");
   // exitPush->setIcon(QIcon(":/Picture/img/Exit.png"));
    exitPush->setFlat(1);//设置按钮的透明属性

    Label1=new QLabel(this);
    Label1->setParent(this);
    Label1->setText("");
    Label1->setPixmap(QPixmap(":/Images/snake2.png"));
    Label1->setGeometry(470,149,200,200);
    Label1->setScaledContents(true);
    Label1->setStyleSheet("border:none;");
    QPalette pala(this->palette());


    exitBox=new QMessageBox;
    connect(exitPush,SIGNAL(clicked(bool)),this,SLOT(M_exitPush()));
    connect(startPush,SIGNAL(clicked(bool)),this,SLOT(M_startPush()));
}

void Widget::M_startPush()
{

    mainPage1=new MainPage(this);  //创建一个新的界面，任然以原来的界面为父窗口，退出后可以直接回到上一个界面。
    mainPage1->show();



}
void Widget::M_exitPush()
{
    if(QMessageBox::Yes==QMessageBox::question(this,"Tips：","Do you want to leave th ox:⒋gamewidget.h中的代码:No"))
    {

   delete  this;
        exit(0);
    }
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/Images/bk3.jpg");


    //绘图操作
    painter.drawPixmap(0,0,this->width(),this->height(),pix);


}
Widget::~Widget()
{

}
