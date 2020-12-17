#include "Gamewidget.h"
#include"widget.h"
#include<QDebug>
#include <QColor>
#include <QPen>
#include<QPalette>
#include<QFont>
int Gamewidget::m_setDiretion=4;

Gamewidget::Gamewidget(QWidget *parent) : QWidget(parent)
{
    qsrand(time(NULL));//随机数的种子

    QFont font1(" Curlz MT",55,63);
    Score=0;
    Difficulty=1;
    this->setAutoFillBackground(true);//设置父窗口背景可被覆盖填充
    this->resize(1200,730);
    this->setWindowTitle("贪吃蛇");

   size[0]=draw; size[1]=draw; size[2]=draw; size[3]=draw; size[4]=draw; size[5]=draw; size[6]=draw; size[7]=draw; size[8]=draw; size[9]=draw;
    size[10]=draw; size[11]=draw; size[12]=draw; size[13]=draw; size[15]=draw; size[16]=draw; size[17]=draw; size[18]=draw; size[14]=draw; size[19]=draw;
    size[20]=draw; size[21]=draw; size[22]=draw; size[23]=draw; size[24]=draw; size[25]=draw; size[26]=draw; size[27]=draw; size[28]=draw; size[29]=draw;
     size[30]=draw; size[31]=draw; size[32]=draw; size[33]=draw; size[34]=draw; size[35]=draw; size[36]=draw; size[37]=draw; size[38]=draw; size[39]=draw;
     size[40]=draw; size[41]=draw; size[42]=draw; size[43]=draw; size[44]=draw; size[45]=draw; size[46]=draw; size[47]=draw; size[48]=draw; size[49]=draw;
      size[50]=draw; size[51]=draw; size[52]=draw; size[53]=draw; size[54]=draw; size[55]=draw; size[56]=draw; size[57]=draw; size[58]=draw; size[59]=draw;
    // this->setWindowIcon(QIcon(":/Picture/img/WindowPicture.jpg"));


    //设置背景音乐
      effect=new QSoundEffect(this);
      effect->setSource(QUrl::fromLocalFile("../snake1/meet2.wav"));
      effect->setVolume(0.4f);
      effect->play();

      effect1=new QSoundEffect(this);
      effect1->setSource(QUrl::fromLocalFile("../snake1/bsound.wav"));
      effect1->setVolume(0.5f);

    //设置按钮
   setPush=new QPushButton(this);
   setPush->setParent(this);
   setPush->setGeometry(1120,160,50,50);
   setPush->setStyleSheet("border:none;");

   setPush->setIcon(QIcon(":/Images/setting.png"));
   setPush->setIconSize(QSize(50,50));
    connect(setPush,&QPushButton::released,this,&Gamewidget::setMusic);
   //相机按钮
  PhotoPush=new QPushButton(this);
  PhotoPush->setParent(this);
  PhotoPush->setGeometry(1120,250,50,50);
  PhotoPush->setStyleSheet("border:none;");
 // QPalette pal12(this->palette());
  PhotoPush->setIcon(QIcon(":/Images/my20.png"));
  PhotoPush->setIconSize(QSize(50,50));
  connect(PhotoPush,&QPushButton::released,this,&Gamewidget::photo);
  //speed
  speedPush=new QPushButton(this);
  speedPush->setParent(this);
  speedPush->setGeometry(1120,335,50,50);
  speedPush->setStyleSheet("border:none;");
 // QPalette pal12(this->palette());
  speedPush->setIcon(QIcon(":/Images/speed.png"));
  speedPush->setIconSize(QSize(50,50));
  connect(speedPush,SIGNAL(buttonClicked(int)),this,SLOT(M_setSpeed()));
    upPush =new QPushButton(this);
    downPush=new QPushButton(this);
    leftPush=new QPushButton(this);
    rightPush=new QPushButton(this);
    StartPush=new QPushButton(this);
    ExitPush=new QPushButton(this);

    buttonGroup=new QButtonGroup(this);
    buttonGroup->addButton(upPush,1);
    buttonGroup->addButton(downPush,2);
    buttonGroup->addButton(leftPush,3);
    buttonGroup->addButton(rightPush,4);
    connect(buttonGroup,SIGNAL(buttonClicked(int)),this,SLOT(M_setDiretion(int)));


    upPush->setIconSize(QSize(45,90));
    upPush->setGeometry(750,160,45,90);
    upPush->setText("上");

    upPush->setFlat(1);
    upPush->hide();
    downPush->setIconSize(QSize(45,90));
    downPush->setGeometry(750,260,45,90);
    downPush->setText("下");

    downPush->setFlat(1);
    downPush->hide();
    leftPush->setIconSize(QSize(90,45));
    leftPush->setGeometry(650,230,90,45);
    leftPush->setText("左");

    leftPush->setFlat(1);
    leftPush->hide();
    rightPush->setIconSize(QSize(90,45));
    rightPush->setGeometry(800,230,90,45);
    rightPush->setText("右");

    rightPush->setFlat(1);
    rightPush->hide();

    StartPush->setIconSize(QSize(50,50));
    StartPush->setGeometry(1120,425,50,50);
    StartPush->setFlat(1);
    StartPush->setIcon(QIcon(":/Images/start2.png"));


    ExitPush->setIconSize(QSize(50,50));
    ExitPush->setGeometry(1125,510,50,50);
    ExitPush->setIcon(QIcon(":/Images/exit2.png"));
    ExitPush->setFlat(1);


    ScoreLabel=new QLabel(this);
    LevelLabel=new QLabel(this);
    ScoreLabel->setText("Score:");
    ScoreLabel->setStyleSheet(QString("color:gray;"));
    ScoreLabel->setGeometry(850,10,120,90);
    LevelLabel->setText("Level:");
    LevelLabel->setStyleSheet(QString("color:gray;"));
    LevelLabel->setGeometry(850,50,120,90);

    ScoreLabelNumber=new QLabel(this);
    LevelLabelNumber=new QLabel(this);
    ScoreLabelNumber->setText(QString::number(Score)+"分");
    ScoreLabelNumber->setStyleSheet(QString("color:gray;"));
    ScoreLabelNumber->setGeometry(895,10,120,90);
    LevelLabelNumber->setText(QString::number(Difficulty)+"级");
    LevelLabelNumber->setStyleSheet(QString("color:gray;"));
    LevelLabelNumber->setGeometry(895,50,120,90);


    Timer=new QTimer(this);

    connect(Timer,SIGNAL(timeout()),this,SLOT(M_timeout()));



    connect(StartPush,SIGNAL(clicked(bool)),this,SLOT(M_startPush()));

    QTimer *Timer1=new QTimer(this);
    Timer1->setSingleShot(true);
    connect(Timer1,SIGNAL(timeout()),SLOT(F_show()));
     Timer1->start(20);

    connect(ExitPush,SIGNAL(clicked(bool)),this,SLOT(M_exitPush()));

    snake[0][0]=(rand()%18+1)*30+30;
    snake[0][1]=(rand()%15+1)*30+30;
    m_setDiretion=(rand()%4)+1;

    bodycount=1;  //包含蛇的头和尾巴
    Nobite=true;
    this->repaint();

}

void Gamewidget::keyPressEvent(QKeyEvent *e)//按键处理
{
    switch(e->key())
    {
    case Qt::Key_Up:if(m_setDiretion!=2)m_setDiretion=1;  break;
    case Qt::Key_W:if(m_setDiretion!=2)m_setDiretion=1;  break;
    case Qt::Key_Down:if(m_setDiretion!=1)m_setDiretion=2;  break;
    case Qt::Key_S:if(m_setDiretion!=1)m_setDiretion=2;  break;
    case Qt::Key_Left:if(m_setDiretion!=4)m_setDiretion=3;  break;
    case Qt::Key_A:if(m_setDiretion!=4)m_setDiretion=3;  break;
    case Qt::Key_Right:if(m_setDiretion!=3)m_setDiretion=4;  break;
    case Qt::Key_D:if(m_setDiretion!=3)m_setDiretion=4;  break;
    case Qt::Key_K:  //Timer->start(300-Difficulty>0? 300-Difficulty*150:150/(Difficulty-5)) ;
        isSpeed=true;break;
    case Qt::Key_L: // Timer->start(500-Difficulty>0? 500-Difficulty*90:90/(Difficulty-5)) ;
        isSpeed=false;break;

    default:                   break;

    }
}
void Gamewidget::paintEvent(QPaintEvent*)//绘图事件
{
   QPainter painter(this);
    QPixmap pix;
    pix.load(":/Images/bk5.jpg");


    //绘图操作
    painter.drawPixmap(0,0,1080,690,pix);
    if(0<=snake[0][0]&&snake[0][0]<=1050&&0<=snake[0][1]&&snake[0][1]<=690&&Nobite)
    {

        for(int i=bodycount;i>0;i--)
        {
            if(i==bodycount)//画出尾巴部分
            {
                if(snake[i][0]==snake[i-1][0]&&snake[i][1]<snake[i-1][1])
                {
                    painter.drawImage(QRect(snake[i][0],snake[i][1],30,30),QImage(":/Images/taildown.png"));
                }
                else  if(snake[i][0]==snake[i-1][0]&&snake[i][1]>snake[i-1][1])
                {
                    painter.drawImage(QRect(snake[i][0],snake[i][1],30,30),QImage(":/Images/tailup.png"));
                }
                else  if(snake[i][0]<snake[i-1][0]&&snake[i][1]==snake[i-1][1])
                {
                    painter.drawImage(QRect(snake[i][0],snake[i][1],30,30),QImage(":/Images/tailright.png"));
                }
                else  if(snake[i][0]>snake[i-1][0]&&snake[i][1]==snake[i-1][1])
                {
                    painter.drawImage(QRect(snake[i][0],snake[i][1],30,30),QImage(":/Images/tailleft.png"));
                }
            }
            else
            {
                if((snake[i][0]==snake[i-1][0]&& snake[i][1]<snake[i-1][1]&&snake[i+1][0]<snake[i][0]&&snake[i+1][1]==snake[i][1])||
                        ((snake[i][0]>snake[i-1][0])&& snake[i][1]==snake[i-1][1]&&snake[i+1][0]==snake[i][0]&&snake[i+1][1]>snake[i][1]))
                {
                    painter.drawImage(QRect(snake[i][0],snake[i][1],30,30),QImage(":/Images/leftdown.png"));
                }
                else if((snake[i][0]<snake[i-1][0]&& snake[i][1]==snake[i-1][1]&&snake[i+1][0]==snake[i][0]&&snake[i+1][1]>snake[i][1])||
                        (snake[i][0]==snake[i-1][0]&& snake[i][1]<snake[i-1][1]&&snake[i+1][0]>snake[i][0]&&snake[i+1][1]==snake[i][1]))
                {
                    painter.drawImage(QRect(snake[i][0],snake[i][1],30,30),QImage(":/Images/rightdown.png"));
                }
                else if((snake[i][0]>snake[i-1][0]&& snake[i][1]==snake[i-1][1]&&snake[i+1][0]==snake[i][0]&&snake[i+1][1]<snake[i][1])||
                        (snake[i][0]==snake[i-1][0]&& snake[i][1]>snake[i-1][1]&&snake[i+1][0]<snake[i][0]&&snake[i+1][1]==snake[i][1]))
                {
                    painter.drawImage(QRect(snake[i][0],snake[i][1],30,30),QImage(":/Images/leftup.png"));
                }
                else if(((snake[i][0]==snake[i-1][0])&& snake[i][1]>snake[i-1][1]&&snake[i+1][0]>snake[i][0]&&snake[i+1][1]==snake[i][1])||
                        (snake[i][0]<snake[i-1][0]&& snake[i][1]==snake[i-1][1]&&snake[i+1][0]==snake[i][0]&&snake[i+1][1]<snake[i][1]))
                {
                    painter.drawImage(QRect(snake[i][0],snake[i][1],30,30),QImage(":/Images/rightup.png"));
                }

                else if((snake[i][0]==snake[i-1][0]&&snake[i][0]==snake[i+1][0])&&((snake[i][1]<snake[i-1][1]&&snake[i+1][1]<snake[i][1])||
                                                                                   (snake[i][1]>snake[i-1][1]&&snake[i+1][1]>snake[i][1])))
                {
                    painter.drawImage(QRect(snake[i][0],snake[i][1],30,30),QImage(":/Images/downup.png"));

                }
                else if ((snake[i][1]==snake[i-1][1]&&snake[i][1]==snake[i+1][1])&&((snake[i][0]<snake[i-1][0]&&snake[i+1][0]<snake[i][0])||
                                                                                    (snake[i][0]>snake[i-1][0]&&snake[i+1][0]>snake[i][0])))
                {
                    painter.drawImage(QRect(snake[i][0],snake[i][1],30,30),QImage(":/Images/leftright.png"));

                }
            }
        }
    }



    for(int i=0;i<74;i++)
    {
    if(i<20)
    {
     painter.drawImage(QRect(foodX[i],foodY[i],size[i],size[i]),QImage(":/Images/yellow.png"));
    }

    if(i>=20&&i<40)
    {
     painter.drawImage(QRect(foodX[i],foodY[i],size[i],size[i]),QImage(":/Images/blue.png"));

     }
   if(i>=40&&i<60)
   {
     painter.drawImage(QRect(foodX[i],foodY[i],size[i],size[i]),QImage(":/Images/pink.png"));

   }
   if(i>=60&&i<64)
   {
    // painter.drawImage(QRect(foodX[i],foodY[i],40,45),QImage(":/Images/Apple.png"));

   }
  if(i>=64&&i<68)
   {
     painter.drawImage(QRect(foodX[i],foodY[i],42,40),QImage(":/Images/sweet1.png"));

   }
  if(i>=68&&i<72)
   {
     painter.drawImage(QRect(foodX[i],foodY[i],42,40),QImage(":/Images/sweet3.png"));

   }
  if(i>=72&&i<74)
   {
     painter.drawImage(QRect(foodX[i],foodY[i],40,40),QImage(":/Images/sweet4.png"));

   }
    }


    switch (m_setDiretion)
    {
    case 1: painter.drawImage(QRect(snake[0][0],snake[0][1],30,30),QImage(":/Images/headup.png"));
        if(bodycount==1)  painter.drawImage(QRect(snake[0][0],snake[0][1]+30,30,30),QImage(":/Images/tailup.png"));
        break;
    case 2: painter.drawImage(QRect(snake[0][0],snake[0][1],30,30),QImage(":/Images/headdown.png"));
        if(bodycount==1) painter.drawImage(QRect(snake[0][0],snake[0][1]-30,30,30),QImage(":/Images/taildown.png"));
        break;
    case 3: painter.drawImage(QRect(snake[0][0],snake[0][1],30,30),QImage(":/Images/headleft.png"));
        if(bodycount==1) painter.drawImage(QRect(snake[0][0]+30,snake[0][1],30,30),QImage(":/Images/tailleft.png"));
        break;
    case 4: painter.drawImage(QRect(snake[0][0],snake[0][1],30,30),QImage(":/Images/headright.png"));
        if(bodycount==1)  painter.drawImage(QRect(snake[0][0]-30,snake[0][1],30,30),QImage(":/Images/tailright.png"));
        break;
    default:
        break;
  }
}


void Gamewidget::M_timeout()

{
    for(int i=0;i<74;i++)
    {
    if(snake[0][0]==foodX[i]&&snake[0][1]==foodY[i])//当蛇头的坐标与食物坐标重合的时候，重新布置食物的位置
    {
        if(i>=60)
        {
//         effect->setVolume(0);
//         effect1->play();

//         effect->setVolume(0.4f);
        }
        foodX[i]=(rand()%36)*30;
        foodY[i]=(rand()%21)*30;
        size[i]=(rand()*10)%8+8;
        //bodycount++;  //蛇的身体加一

        if(i>=60&&i<74)
        {
            bodycount=bodycount+2;  //蛇的身体加一
             Score=Score+Difficulty*3;
             Difficulty=bodycount/20+1;
        }
        else
        {
        bodycount++;  //蛇的身体加一
        Score=Score+Difficulty;
        Difficulty=bodycount/20+1;
        }

        ScoreLabelNumber->setText(QString::number(Score)+"分");
        LevelLabelNumber->setText(QString::number(Difficulty)+"级");
        if(!isSpeed)
        {
         Timer->start(500-Difficulty>0? 500-Difficulty*90:90/(Difficulty-5));
        }
        else
        {

             Timer->start(300-Difficulty>0? 300-Difficulty*150:150/(Difficulty-5));
        }

    }
   }




    memcpy(snake1,snake,sizeof(snake));
    for(int i=bodycount;i>0;i--)//将蛇身体的前一个坐标赋值给后一个坐标，实现蛇身体的连续出现
    {

        snake[i][0]=snake[i-1][0];
        snake[i][1]=snake[i-1][1];
    }
    QPainter painter(this);

     for(int i=bodycount;i>3;i--)
  {
       if(snake[0][0]==snake[i][0]&&snake[0][1]==snake[i][1])
        {
            Nobite=false;
        }
    }


    switch (m_setDiretion)
    {
    case 1: snake[0][1]=snake[0][1]-30,painter.drawImage(QRect(snake[0][0],snake[0][1],30,30),QImage(":/Images/headup.png"))
                ;break;
    case 2: snake[0][1]=snake[0][1]+30,painter.drawImage(QRect(snake[0][0],snake[0][1],30,30),QImage(":/Images/headdown.png"))
                ; break;
    case 3: snake[0][0]=snake[0][0]-30,painter.drawImage(QRect(snake[0][0],snake[0][1],30,30),QImage(":/Images/headleft.png"))
                ; break;
    case 4: snake[0][0]=snake[0][0]+30,painter.drawImage(QRect(snake[0][0],snake[0][1],30,30),QImage(":/Images/headright.png"))
                ;break;
    default:
        break;
    }
    if(0>snake[0][0]||snake[0][0]>1050||0>snake[0][1]||snake[0][1]>690)
    {
        memcpy(snake,snake1,sizeof(snake));
        Nobite=false;
    }

    this->update();
    connect(Timer,SIGNAL(timeout()),this,SLOT(M_CheckGameOver()));
}

void Gamewidget::M_startPush()//时间函数开始计时
{


    Timer->start(500);
    effect->play();



}


void Gamewidget::M_setDiretion(int index)//接收按钮组的整数，确定方向
{
    switch (index)
    {
    case 1:if(m_setDiretion!=2)m_setDiretion=1;  break;
    case 2:if(m_setDiretion!=1)m_setDiretion=2;  break;
    case 3:if(m_setDiretion!=4)m_setDiretion=3;  break;
    case 4:if(m_setDiretion!=3)m_setDiretion=4;  break;
    default:                   break;
    }
}

void Gamewidget::M_exitPush()
{
    this->close();
    delete this;
}
void Gamewidget::F_show()
{

      for(int i=0;i<74;i++)
      {
      foodX[i]=(rand()%36)*30;
      foodY[i]=(rand()%21)*30;
      }

}

void Gamewidget::M_CheckGameOver()//该部分原本在绘图事件函数中，但是由于在其中的时候程序总是意外关闭，故将其提出
{


    if(0>snake[0][0]||snake[0][0]>1050||0>snake[0][1]||snake[0][1]>690||(!Nobite))
    {
        Nobite=true;//将其设置为真,进入绘图函数画出蛇的身体
        this->update();//调用绘图事件函数
        Timer->stop();
        effect->stop();
        effect1->stop();

        if(QMessageBox::Yes==QMessageBox::information(this,"Tips：","Game Over!",QMessageBox::Yes))
        {
            this ->hide();
            delete this;
            return;
        }

   }
}
//照相功能
void Gamewidget::photo()
{
    QPixmap fullScreen=QPixmap::grabWindow(QApplication::desktop()->winId(),0,0,730,700);
    QString fileName=QFileDialog::getSaveFileName(this,"文件另存为","",tr("ConfigFiles(*.jpg)"));
    fullScreen.save(fileName,"jpg");
}
void Gamewidget::setMusic()
{
    if(music1%2==0)
    {
        effect->stop();
        music1++;
    }
    else if(music1%2==1)
    {
        effect->play();
        music1++;
    }
}
void Gamewidget::M_setSpeed()
{

    if(num%2==0)
{
    Timer->start(300-Difficulty>0? 300-Difficulty*150:150/(Difficulty-5));
    num++;
    }
    else
    {
     Timer->start(500-Difficulty>0? 500-Difficulty*90:90/(Difficulty-5));
     num++;
    }
}
