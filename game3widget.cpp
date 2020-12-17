#include "game3widget.h"
#include<QPainter>
#include<QPixmap>
game3widget::game3widget(QWidget *parent) : QWidget(parent)
{
    this->setAutoFillBackground(true);//设置父窗口背景可被覆盖填充
    this->resize(1200,730);
    this->setWindowTitle("贪吃蛇");

      exitPush3=new QPushButton(this);
      exitPush3->setIconSize(QSize(90,45));
      exitPush3->setGeometry(1070,400,90,45);
     // ExitPush->setIcon(QIcon(":/Picture/img/Exit.png"));
      exitPush3->setFlat(1);
     exitPush3->setIcon(QIcon(":/Images/exit2.png"));
      connect(exitPush3,SIGNAL(clicked(bool)),this,SLOT(M_exitPush3()));
}
void game3widget::M_exitPush3()
{
    this->close();
    delete this;
}
void game3widget::paintEvent(QPaintEvent *)
{

    QPainter painter(this);

     QPixmap pix;
     pix.load(":/Images/looking.jpg");
     painter.drawPixmap(0,0,1000,720,pix);

}
