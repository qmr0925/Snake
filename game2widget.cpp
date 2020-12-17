#include "game2widget.h"
#include"widget.h"
#include<QDebug>
int game2widget::m_setDiretion3=4;
int game2widget::m_setDiretion4=4;

game2widget::game2widget(QWidget *parent) : QWidget(parent)
{
    qsrand(time(NULL));//随机数的种子
    Score3=0;
    Difficulty3=1;
    this->setAutoFillBackground(true);//设置父窗口背景可被覆盖填充
    this->resize(1200,730);
    this->setWindowTitle("贪吃蛇");

    /* 初始化场景，播放背景音乐 */
    playList = new QMediaPlaylist;
    playList->addMedia(QUrl("qrc:/Images/bksound2.mp3"));
    playList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop); //单曲循环
    player = new QMediaPlayer(this);
    player->setPlaylist(playList);
    player->play();
   // this->setWindowIcon(QIcon(":/Picture/img/WindowPicture.jpg"));
    size[0]=draw; size[1]=draw; size[2]=draw; size[3]=draw; size[4]=draw; size[5]=draw; size[6]=draw; size[7]=draw; size[8]=draw; size[9]=draw;
     size[10]=draw; size[11]=draw; size[12]=draw; size[13]=draw; size[15]=draw; size[16]=draw; size[17]=draw; size[18]=draw; size[14]=draw; size[19]=draw;
     size[20]=draw; size[21]=draw; size[22]=draw; size[23]=draw; size[24]=draw; size[25]=draw; size[26]=draw; size[27]=draw; size[28]=draw; size[29]=draw;
      size[30]=draw; size[31]=draw; size[32]=draw; size[33]=draw; size[34]=draw; size[35]=draw; size[36]=draw; size[37]=draw; size[38]=draw; size[39]=draw;
        size[40]=draw; size[41]=draw; size[42]=draw; size[43]=draw; size[44]=draw; size[45]=draw; size[46]=draw; size[47]=draw; size[48]=draw; size[49]=draw;

      planX[0]=380;planY[0]=400;
      planX[1]=290;planY[1]=500;
      planX[2]=570;planY[2]=300;
      planX[3]=670;planY[3]=580;


      x11=planX[0];
      y11=planY[0];

      upPush3 =new QPushButton(this);
      downPush3=new QPushButton(this);
      leftPush3=new QPushButton(this);
      rightPush3=new QPushButton(this);
      StartPush3=new QPushButton(this);
      ExitPush3=new QPushButton(this);

      buttonGroup3=new QButtonGroup(this);
      buttonGroup3->addButton(upPush3,1);
      buttonGroup3->addButton(downPush3,2);
      buttonGroup3->addButton(leftPush3,3);
      buttonGroup3->addButton(rightPush3,4);
      connect(buttonGroup3,SIGNAL(buttonClicked(int)),this,SLOT(M_setDiretion3(int)));



    upPush3->setIconSize(QSize(45,90));
    upPush3->setGeometry(850,160,45,90);
    upPush3->setText("上");

    upPush3->setFlat(1);
    upPush3->hide();
    downPush3->setIconSize(QSize(45,90));
    downPush3->setGeometry(850,260,45,90);
    downPush3->setText("下");
    downPush3->hide();

    downPush3->setFlat(1);
    leftPush3->setIconSize(QSize(90,45));
    leftPush3->setGeometry(820,230,90,45);
    leftPush3->setText("左");
    leftPush3->hide();

    leftPush3->setFlat(1);
    rightPush3->setIconSize(QSize(90,45));
    rightPush3->setGeometry(870,230,90,45);
    rightPush3->setText("右");

    rightPush3->setFlat(1);
    rightPush3->hide();

    StartPush3->setIconSize(QSize(90,45));
    StartPush3->setGeometry(1070,200,90,45);
    StartPush3->setFlat(1);
    StartPush3->setIcon(QIcon(":/Images/start2.png"));

    ExitPush3->setIconSize(QSize(90,45));
    ExitPush3->setGeometry(1070,400,90,45);

    ExitPush3->setFlat(1);
   ExitPush3->setIcon(QIcon(":/Images/exit2.png"));
    connect(ExitPush3,SIGNAL(clicked(bool)),this,SLOT(M_exitPush3()));

    ScoreLabel3=new QLabel(this);
    LevelLabel3=new QLabel(this);
    ScoreLabel3->setText("Score:");
    ScoreLabel3->setGeometry(1080,10,120,90);
    LevelLabel3->setText("Level:");
    LevelLabel3->setGeometry(1080,50,120,90);

    ScoreLabelNumber3=new QLabel(this);
    LevelLabelNumber3=new QLabel(this);
    ScoreLabelNumber3->setText(QString::number(Score3)+"分");
    ScoreLabelNumber3->setGeometry(1130,10,120,90);
    LevelLabelNumber3->setText(QString::number(Difficulty3)+"级");
    LevelLabelNumber3->setGeometry(1130,50,120,90);

    BloodLabel3=new QLabel(this);

    BloodLabel3->setText("Blood:");
    BloodLabel3->setGeometry(1080,100,120,90);

    BloodLabelNumber3=new QLabel(this);

    BloodLabelNumber3->setText(QString::number(blood));
    BloodLabelNumber3->setGeometry(1130,100,120,90);

    weap11=new QLabel(this);
    weap11->setParent(this);
    weap11->setText("");
    weap11->setPixmap(QPixmap(":/Images/red.png"));
    weap11->setGeometry(x11,y11,10,10);
    weap11->setScaledContents(true);
    weap11->setStyleSheet("border:none;");
    //QPalette palm(this->palette());
    weap11->hide();


    Timer3=new QTimer(this);
    connect(Timer3,SIGNAL(timeout()),this,SLOT(M_timeout3()));
    connect(StartPush3,SIGNAL(clicked(bool)),this,SLOT(M_startPush3()));


    QTimer *Timer4=new QTimer(this);
    Timer4->setSingleShot(true);
    connect(Timer4,SIGNAL(timeout()),SLOT(F_show3()));
    Timer4->start(10);

    //敌机的移动
     QTimer *Timer6=new QTimer(this);
     Timer6->start(5000);
     connect(Timer6,SIGNAL(timeout()),SLOT(M_setDiretion5()));
     //子弹的发射
      QTimer *Timer7=new QTimer(this);
      Timer7->start(800);
      connect(Timer7,SIGNAL(timeout()),SLOT(M_shots()));
      //在子弹没有发出时，让子弹与飞船的坐标保持一致
      QTimer *Timer8=new QTimer(this);
      Timer8->start(10);
      connect(Timer8,SIGNAL(timeout()),SLOT(M_changeIndex()));

      QTimer *Timer5=new QTimer(this);
      Timer5->start(100);
      connect(Timer8,SIGNAL(timeout()),SLOT(M_changStone()));


      snake3[0][0]=(rand()%18+1)*30+30;
      snake3[0][1]=(rand()%15+1)*30+30;
      m_setDiretion3=(rand()%4)+1;
      bodycount3=1;  //包含蛇的头和尾巴
      Nobite=true;
       this->repaint();

}
void game2widget::keyPressEvent(QKeyEvent *e)//按键处理
{

    switch(e->key())
    {
    case Qt::Key_Up:if(m_setDiretion3!=2)m_setDiretion3=1;  break;
    case Qt::Key_W:if(m_setDiretion3!=2)m_setDiretion3=1;  break;
    case Qt::Key_Down:if(m_setDiretion3!=1)m_setDiretion3=2;  break;
    case Qt::Key_S:if(m_setDiretion3!=1)m_setDiretion3=2;  break;
    case Qt::Key_Left:if(m_setDiretion3!=4)m_setDiretion3=3;  break;
    case Qt::Key_A:if(m_setDiretion3!=4)m_setDiretion3=3;  break;
    case Qt::Key_Right:if(m_setDiretion3!=3)m_setDiretion3=4;  break;
    case Qt::Key_D:if(m_setDiretion3!=3)m_setDiretion3=4;  break;
    default:                   break;

    }
}
void game2widget::paintEvent(QPaintEvent*)//绘图事件
{
    QPainter painter(this);

     QPixmap pix;
     pix.load(":/Images/bk12.jpg");
     painter.drawPixmap(0,0,1050,720,pix);


     //绘图操作

         painter.drawImage(QRect(planX[0],planY[0],100,40),QImage(":/Images/plan.png"));
         painter.drawImage(QRect(planX[1],planY[1],100,40),QImage(":/Images/plan.png"));
         painter.drawImage(QRect(planX[2],planY[2],100,40),QImage(":/Images/plan.png"));
         painter.drawImage(QRect(planX[3],planY[3],100,40),QImage(":/Images/plan.png"));



         if(isShots)
         {


             painter.drawImage(QRect(foodX3[50],foodY3[50],30,30),QImage(":/Images/mybullet.png"));
             painter.drawImage(QRect(foodX3[51],foodY3[51],30,30),QImage(":/Images/mybullet.png"));
             painter.drawImage(QRect(foodX3[52],foodY3[52],30,30),QImage(":/Images/mybullet.png"));

             painter.drawImage(QRect(foodX3[53],foodY3[53],30,30),QImage(":/Images/mybullet.png"));

             painter.drawImage(QRect(foodX3[54],foodY3[54],30,30),QImage(":/Images/mybullet.png"));
             painter.drawImage(QRect(foodX3[55],foodY3[55],30,30),QImage(":/Images/mybullet.png"));
             painter.drawImage(QRect(foodX3[56],foodY3[56],30,30),QImage(":/Images/mybullet.png"));

             painter.drawImage(QRect(foodX3[57],foodY3[57],30,30),QImage(":/Images/mybullet.png"));

             painter.drawImage(QRect(foodX3[58],foodY3[58],30,30),QImage(":/Images/mybullet.png"));
             painter.drawImage(QRect(foodX3[59],foodY3[59],30,30),QImage(":/Images/mybullet.png"));
             painter.drawImage(QRect(foodX3[60],foodY3[60],30,30),QImage(":/Images/mybullet.png"));

             painter.drawImage(QRect(foodX3[61],foodY3[61],30,30),QImage(":/Images/mybullet.png"));

             painter.drawImage(QRect(foodX3[62],foodY3[62],30,30),QImage(":/Images/mybullet.png"));
             painter.drawImage(QRect(foodX3[63],foodY3[63],30,30),QImage(":/Images/mybullet.png"));
             painter.drawImage(QRect(foodX3[64],foodY3[64],30,30),QImage(":/Images/mybullet.png"));

             painter.drawImage(QRect(foodX3[65],foodY3[65],30,30),QImage(":/Images/mybullet.png"));

             painter.drawImage(QRect(foodX3[66],foodY3[66],30,30),QImage(":/Images/mybullet.png"));
             painter.drawImage(QRect(foodX3[67],foodY3[67],30,30),QImage(":/Images/mybullet.png"));
             painter.drawImage(QRect(foodX3[68],foodY3[68],30,30),QImage(":/Images/mybullet.png"));

             painter.drawImage(QRect(foodX3[69],foodY3[69],30,30),QImage(":/Images/mybullet.png"));

             painter.drawImage(QRect(foodX3[70],foodY3[70],30,30),QImage(":/Images/mybullet.png"));
             painter.drawImage(QRect(foodX3[71],foodY3[71],30,30),QImage(":/Images/mybullet.png"));
             painter.drawImage(QRect(foodX3[72],foodY3[72],30,30),QImage(":/Images/mybullet.png"));

             painter.drawImage(QRect(foodX3[73],foodY3[73],30,30),QImage(":/Images/mybullet.png"));

             painter.drawImage(QRect(foodX3[74],foodY3[74],30,30),QImage(":/Images/mybullet.png"));
              painter.drawImage(QRect(foodX3[75],foodY3[75],30,30),QImage(":/Images/mybullet.png"));
             painter.drawImage(QRect(foodX3[76],foodY3[76],30,30),QImage(":/Images/mybullet.png"));

             painter.drawImage(QRect(foodX3[77],foodY3[77],30,30),QImage(":/Images/mybullet.png"));

             painter.drawImage(QRect(foodX3[78],foodY3[78],30,30),QImage(":/Images/mybullet.png"));
             painter.drawImage(QRect(foodX3[79],foodY3[79],30,30),QImage(":/Images/mybullet.png"));
             painter.drawImage(QRect(foodX3[80],foodY3[80],30,30),QImage(":/Images/mybullet.png"));

             painter.drawImage(QRect(foodX3[81],foodY3[81],30,30),QImage(":/Images/mybullet.png"));
         }






    if(0<=snake3[0][0]&&snake3[0][0]<=1050&&snake3[0][1]<=690&&Nobite)
    {
        //qDebug()<<snake3[0][0];
        for(int i=bodycount3;i>0;i--)
        {
            if(i==bodycount3)//画出尾巴部分
            {
                if(snake3[i][0]==snake3[i-1][0]&&snake3[i][1]<snake3[i-1][1])
                {
                    painter.drawImage(QRect(snake3[i][0],snake3[i][1],30,30),QImage(":/Images/taildown.png"));
                }
                else  if(snake3[i][0]==snake3[i-1][0]&&snake3[i][1]>snake3[i-1][1])
                {
                    painter.drawImage(QRect(snake3[i][0],snake3[i][1],30,30),QImage(":/Images/tailup.png"));
                }
                else  if(snake3[i][0]<snake3[i-1][0]&&snake3[i][1]==snake3[i-1][1])
                {
                    painter.drawImage(QRect(snake3[i][0],snake3[i][1],30,30),QImage(":/Images/tailright.png"));
                }
                else  if(snake3[i][0]>snake3[i-1][0]&&snake3[i][1]==snake3[i-1][1])
                {
                    painter.drawImage(QRect(snake3[i][0],snake3[i][1],30,30),QImage(":/Images/tailleft.png"));
                }
            }
            else
            {
                if((snake3[i][0]==snake3[i-1][0]&& snake3[i][1]<snake3[i-1][1]&&snake3[i+1][0]<snake3[i][0]&&snake3[i+1][1]==snake3[i][1])||
                        ((snake3[i][0]>snake3[i-1][0])&& snake3[i][1]==snake3[i-1][1]&&snake3[i+1][0]==snake3[i][0]&&snake3[i+1][1]>snake3[i][1]))
                {
                    painter.drawImage(QRect(snake3[i][0],snake3[i][1],30,30),QImage(":/Images/leftdown.png"));
                }
                else if((snake3[i][0]<snake3[i-1][0]&& snake3[i][1]==snake3[i-1][1]&&snake3[i+1][0]==snake3[i][0]&&snake3[i+1][1]>snake3[i][1])||
                        (snake3[i][0]==snake3[i-1][0]&& snake3[i][1]<snake3[i-1][1]&&snake3[i+1][0]>snake3[i][0]&&snake3[i+1][1]==snake3[i][1]))
                {
                    painter.drawImage(QRect(snake3[i][0],snake3[i][1],30,30),QImage(":/Images/rightdown.png"));
                }
                else if((snake3[i][0]>snake3[i-1][0]&& snake3[i][1]==snake3[i-1][1]&&snake3[i+1][0]==snake3[i][0]&&snake3[i+1][1]<snake3[i][1])||
                        (snake3[i][0]==snake3[i-1][0]&& snake3[i][1]>snake3[i-1][1]&&snake3[i+1][0]<snake3[i][0]&&snake3[i+1][1]==snake3[i][1]))
                {
                    painter.drawImage(QRect(snake3[i][0],snake3[i][1],30,30),QImage(":/Images/leftup.png"));
                }
                else if(((snake3[i][0]==snake3[i-1][0])&& snake3[i][1]>snake3[i-1][1]&&snake3[i+1][0]>snake3[i][0]&&snake3[i+1][1]==snake3[i][1])||
                        (snake3[i][0]<snake3[i-1][0]&& snake3[i][1]==snake3[i-1][1]&&snake3[i+1][0]==snake3[i][0]&&snake3[i+1][1]<snake3[i][1]))
                {
                    painter.drawImage(QRect(snake3[i][0],snake3[i][1],30,30),QImage(":/Images/rightup.png"));
                }

                else if((snake3[i][0]==snake3[i-1][0]&&snake3[i][0]==snake3[i+1][0])&&((snake3[i][1]<snake3[i-1][1]&&snake3[i+1][1]<snake3[i][1])||
                                                                                   (snake3[i][1]>snake3[i-1][1]&&snake3[i+1][1]>snake3[i][1])))
                {
                    painter.drawImage(QRect(snake3[i][0],snake3[i][1],30,30),QImage(":/Images/downup.png"));

                }
                else if ((snake3[i][1]==snake3[i-1][1]&&snake3[i][1]==snake3[i+1][1])&&((snake3[i][0]<snake3[i-1][0]&&snake3[i+1][0]<snake3[i][0])||
                                                                                    (snake3[i][0]>snake3[i-1][0]&&snake3[i+1][0]>snake3[i][0])))
                {
                    painter.drawImage(QRect(snake3[i][0],snake3[i][1],30,30),QImage(":/Images/leftright.png"));

                }
            }
        }
    }


    switch (m_setDiretion3)
    {
    case 1: painter.drawImage(QRect(snake3[0][0],snake3[0][1],30,30),QImage(":/Images/headup.png"));
        if(bodycount3==1)  painter.drawImage(QRect(snake3[0][0],snake3[0][1]+30,30,30),QImage(":/Images/tailup.png"));
        break;
    case 2: painter.drawImage(QRect(snake3[0][0],snake3[0][1],30,30),QImage(":/Images/headdown.png"));
        if(bodycount3==1) painter.drawImage(QRect(snake3[0][0],snake3[0][1]-30,30,30),QImage(":/Images/taildown.png"));
        break;
    case 3: painter.drawImage(QRect(snake3[0][0],snake3[0][1],30,30),QImage(":/Images/headleft.png"));
        if(bodycount3==1) painter.drawImage(QRect(snake3[0][0]+30,snake3[0][1],30,30),QImage(":/Images/tailleft.png"));
        break;
    case 4: painter.drawImage(QRect(snake3[0][0],snake3[0][1],30,30),QImage(":/Images/headright.png"));
        if(bodycount3==1)  painter.drawImage(QRect(snake3[0][0]-30,snake3[0][1],30,30),QImage(":/Images/tailright.png"));
        break;
    default:
        break;
    }









        for(int i=0;i<50;i++)
        {
        if(i<15)
        {
         painter.drawImage(QRect(foodX3[i],foodY3[i],6,6),QImage(":/Images/yellow.png"));
        }

        if(i>=15&&i<30)
        {
         painter.drawImage(QRect(foodX3[i],foodY3[i],size[i],size[i]),QImage(":/Images/blue.png"));

         }
       if(i>=30&&i<45)
       {
         painter.drawImage(QRect(foodX3[i],foodY3[i],size[i],size[i]),QImage(":/Images/pink.png"));

       }
       if(i>=45&&i<50)
       {
        painter.drawImage(QRect(foodX3[i],foodY3[i],25,25),QImage(":/Images/mashroom.png"));

       }


    }





}

void game2widget::M_timeout3()

{

    for(int i=0;i<82;i++)
    {
    if(snake3[0][0]==foodX3[i]&&snake3[0][1]==foodY3[i])//当蛇头的坐标与食物坐标重合的时候，重新布置食物的位置
    {
   if(i>=0&&i<50)
   {
        if(i>=45&&i<50)
        {
            if(blood<=90&&blood>0)
            {
                blood=blood+10;
                BloodLabelNumber3->setText(QString::number(blood));
            }
            else if(blood>90)
            {
                blood=100;
                BloodLabelNumber3->setText(QString::number(blood));
            }
             }
        if(i>=0&&i<45)
        {
            if(blood<=98&&blood>0)
            {
                blood=blood+2;
                BloodLabelNumber3->setText(QString::number(blood));
            }
            else if(blood>98)
            {
                blood=100;
                BloodLabelNumber3->setText(QString::number(blood));
            }
        }
        foodX3[i]=(rand()%33)*30;
        foodY3[i]=(rand()%22)*30;
        bodycount3++;  //蛇的身体加一
         size[i]=(rand()*8)%8+6;
        Difficulty3=bodycount3/20+1;

        Score3=Score3+Difficulty3;
        ScoreLabelNumber3->setText(QString::number(Score3)+"分");
        LevelLabelNumber3->setText(QString::number(Difficulty3)+"级");
        Timer3->start(500-Difficulty3>0? 500-Difficulty3*120:120/(Difficulty3-8));
    }



 }
    }



    memcpy(snake4,snake3,sizeof(snake3));

    for(int i=bodycount3;i>0;i--)//将蛇身体的前一个坐标赋值给后一个坐标，实现蛇身体的连续出现
    {

        snake3[i][0]=snake3[i-1][0];
        snake3[i][1]=snake3[i-1][1];
    }


    QPainter painter(this);


    switch (m_setDiretion3)
    {
    case 1: snake3[0][1]=snake3[0][1]-30,painter.drawImage(QRect(snake3[0][0],snake3[0][1],30,30),QImage(":/Images/headup.png"))
                ;break;
    case 2: snake3[0][1]=snake3[0][1]+30,painter.drawImage(QRect(snake3[0][0],snake3[0][1],30,30),QImage(":/Images/headdown.png"))
                ; break;
    case 3: snake3[0][0]=snake3[0][0]-30,painter.drawImage(QRect(snake3[0][0],snake3[0][1],30,30),QImage(":/Images/headleft.png"))
                ; break;
    case 4: snake3[0][0]=snake3[0][0]+30,painter.drawImage(QRect(snake3[0][0],snake3[0][1],30,30),QImage(":/Images/headright.png"))
                ;break;
    default:
        break;
    }

    if(0>snake3[0][0]||snake3[0][0]>1050||snake3[0][1]>690||snake3[0][1]<0)
    {
        memcpy(snake3,snake4,sizeof(snake3));
        Nobite=false;
    }

    this->update();
    connect(Timer3,SIGNAL(timeout()),this,SLOT(M_CheckGameOver3()));
}

void game2widget::M_startPush3()//时间函数开始计时
{

    Timer3->start(800);
    start1=true;
}


void game2widget::M_setDiretion3(int index)//接收按钮组的整数，确定方向
{
    switch (index)
    {
    case 1:if(m_setDiretion3!=2)m_setDiretion3=1;  break;
    case 2:if(m_setDiretion3!=1)m_setDiretion3=2;  break;
    case 3:if(m_setDiretion3!=4)m_setDiretion3=3;  break;
    case 4:if(m_setDiretion3!=3)m_setDiretion3=4;  break;
    default:                   break;
    }
}


void game2widget::M_exitPush3()
{
    this->close();
    delete this;
}

void game2widget::F_show3()//初始化食物的位置
{
      for(int i=0;i<50;i++)
      {
      foodX3[i]=(rand()%33)*30;
      foodY3[i]=(rand()%22)*30;
      }

}

void game2widget::M_CheckGameOver3()//该部分原本在绘图事件函数中，但是由于在其中的时候程序总是意外关闭，故将其提出
{


    if(0>snake3[0][0]||snake3[0][0]>1050||snake3[0][1]>690||snake3[0][1]<0||(!Nobite)||blood<=0)
    {
        Nobite=true;//将其设置为真,进入绘图函数画出蛇的身体
        this->update();//调用绘图事件函数
        start1=false;
        Timer3->stop();
        Timer5->stop();



        if(QMessageBox::Yes==QMessageBox::information(this,"Tips：","Game Over!",QMessageBox::Yes))
        {
            this ->hide();
            delete this;
            return;
        }

    }
}
void game2widget::M_setDiretion5(){
    if(start1)
    {
    blood=blood-Difficulty3*5;

    }
     BloodLabelNumber3->setText(QString::number(blood));

    for(int i=0;i<4;i++)
    {

        m=(rand()%4)+1;
        switch (m) {
        case 1: if(planY[i]>0&&planY[i]<700)
            {
                planY[i]=planY[i]-20;
            }
            else{
                planY[i]=planY[i];
            }
            this->update();
            if(planY[i]>0&&planY[i]<700)
                        {
                            planY[i]=planY[i]-20;
                        }
                        else{
                          planY[i]=planY[i];
                        }
                        this->update();
            if(planY[i]>0&&planY[i]<700)
                        {
                            planY[i]=planY[i]-20;
                        }
                        else{
                         planY[i]=planY[i];
                        }
                        this->update();
            break;

        case 2: if(planY[i]>0&&planY[i]<680)
            {
                planY[i]=planY[i]+20;
            }
            else{
                planY[i]=planY[i];

            }
            this->update();
            if(planY[i]>0&&planY[i]<680)
                        {
                            planY[i]=planY[i]+20;
                        }
                        else{
                    planY[i]=planY[i];

                        }
                        this->update();
            if(planY[i]>0&&planY[i]<680)
                        {
                            planY[i]=planY[i]+20;
                        }
                        else{
                       planY[i]=planY[i];

                        }
                        this->update();

            break;
        case 3: if(planX[i]>0&&planX[i]<1000)
            {
                planX[i]=planX[i]-20;
            }
            else{
                planX[i]=planX[i];

            }
            this->update();
            if(planX[i]>0&&planX[i]<1000)
                        {
                            planX[i]=planX[i]-20;
                        }
                        else{
                 planX[i]=planX[i];

                        }
                        this->update();
            if(planX[i]>0&&planX[i]<1000)
                        {
                            planX[i]=planX[i]-20;
                        }
                        else{
                 planX[i]=planX[i];

                        }
                        this->update();

            break;
        case 4: if(planX[i]>0&&planX[i]<1000)
            {
                planX[i]=planX[i]+20;
            }
            else{
                 planX[i]=planX[i];

            }
            this->update();
            if(planX[i]>0&&planX[i]<1000)
                        {
                            planX[i]=planX[i]+20;
                        }
                        else{
                 planX[i]=planX[i];

                        }
                        this->update();
            if(planX[i]>0&&planX[i]<1000)
                        {
                            planX[i]=planX[i]+20;
                        }
                        else{
                 planX[i]=planX[i];

                        }
                        this->update();


            break;
        default:
            break;
        }



}

     hasMove=true;

}
void game2widget::M_shots()
{


           isShots=true;

           foodY3[50]=foodY3[50]-20;
           foodY3[51]=foodY3[51]+20;
           foodX3[52]=foodX3[52]-20;
           foodX3[53]=foodX3[53]+20;
           foodX3[54]=foodX3[54]-20;
           foodY3[54]=foodY3[54]-20;
           foodX3[55]=foodX3[55]+20;
           foodY3[55]=foodY3[55]-20;
           foodX3[56]=foodX3[56]-20;
           foodY3[56]=foodY3[56]+20;
           foodX3[57]=foodX3[57]+20;
           foodY3[57]=foodY3[57]+20;

           foodY3[58]=foodY3[58]+20;
           foodY3[59]=foodY3[59]+20;
           foodX3[60]=foodX3[60]-20;
           foodX3[61]=foodX3[61]+20;
           foodX3[62]=foodX3[62]-20;
           foodY3[62]=foodY3[62]-20;
           foodX3[63]=foodX3[63]+20;
           foodY3[63]=foodY3[63]-20;
           foodX3[64]=foodX3[64]-20;
           foodY3[64]=foodY3[64]+20;
           foodX3[65]=foodX3[65]+20;
           foodY3[65]=foodY3[65]+20;

           foodY3[66]=foodY3[66]+20;
           foodY3[67]=foodY3[67]+20;
           foodX3[68]=foodX3[68]-20;
           foodX3[69]=foodX3[69]+20;
           foodX3[70]=foodX3[70]-20;
           foodY3[70]=foodY3[70]-20;
           foodX3[71]=foodX3[71]+20;
           foodY3[71]=foodY3[71]-20;
           foodX3[72]=foodX3[72]-20;
           foodY3[72]=foodY3[72]+20;
           foodX3[73]=foodX3[73]+20;
           foodY3[73]=foodY3[73]+20;

           foodY3[74]=foodY3[74]+20;
           foodY3[75]=foodY3[75]+20;
           foodX3[76]=foodX3[76]-20;
           foodX3[77]=foodX3[77]+20;
           foodX3[78]=foodX3[78]-20;
           foodY3[78]=foodY3[78]-20;
           foodX3[79]=foodX3[79]+20;
           foodY3[79]=foodY3[79]-20;
           foodX3[80]=foodX3[80]-20;
           foodY3[80]=foodY3[80]+20;
           foodX3[81]=foodX3[81]+20;
           foodY3[81]=foodY3[81]+20;


        for(int i=50;i<82;i++)
        {
            if(foodX3[i]<0||foodX3[i]>1000||foodY3[i]<0||foodY3[i]>720)
            {
                isShots=false;
            }
        }

}
void game2widget::M_changeIndex()
{
    for(int i=50;i<82;i++)
    {
        if(snake3[0][0]==foodX3[i]&&snake3[0][1]==foodY3[i])
        {
            blood=blood-10;
            BloodLabelNumber3->setText(QString::number(blood));
        }
    }


     this->update();

    if(!isShots){
    foodX3[50]=planX[0]+45;
    foodY3[50]=planY[0]-8;
    foodX3[51]=planX[0]+45;
    foodY3[51]=planY[0]+10;
    foodX3[52]=planX[0]+45;
    foodY3[52]=planY[0];
    foodX3[53]=planX[0]+45;
    foodY3[53]=planY[0];
    foodX3[54]=planX[0];
    foodY3[54]=planY[0];
    foodX3[55]=planX[0];
    foodY3[55]=planY[0];
    foodX3[56]=planX[0];
    foodY3[56]=planY[0];
    foodX3[57]=planX[0];
    foodY3[57]=planY[0];

    foodX3[58]=planX[1]+45;
    foodY3[58]=planY[1]-8;
    foodX3[59]=planX[1]+45;
    foodY3[59]=planY[1]+10;
    foodX3[60]=planX[1]+45;
    foodY3[60]=planY[1];
    foodX3[61]=planX[1]+45;
    foodY3[61]=planY[1];
    foodX3[62]=planX[1];
    foodY3[62]=planY[1];
    foodX3[63]=planX[1];
    foodY3[63]=planY[1];
    foodX3[64]=planX[1];
    foodY3[64]=planY[1];
    foodX3[65]=planX[1];
    foodY3[65]=planY[1];

    foodX3[66]=planX[2]+45;
    foodY3[66]=planY[2]-8;
    foodX3[67]=planX[2]+45;
    foodY3[67]=planY[2]+10;
    foodX3[68]=planX[2]+45;
    foodY3[68]=planY[2];
    foodX3[69]=planX[2]+45;
    foodY3[69]=planY[2];
    foodX3[70]=planX[2];
    foodY3[70]=planY[2];
    foodX3[71]=planX[2];
    foodY3[71]=planY[2];
    foodX3[72]=planX[2];
    foodY3[72]=planY[2];
    foodX3[73]=planX[2];
    foodY3[73]=planY[2];

    foodX3[74]=planX[3]+45;
    foodY3[74]=planY[3]-8;
    foodX3[75]=planX[3]+45;
    foodY3[75]=planY[3]+10;
    foodX3[76]=planX[3]+45;
    foodY3[76]=planY[3];
    foodX3[77]=planX[3]+45;
    foodY3[77]=planY[3];
    foodX3[78]=planX[3];
    foodY3[78]=planY[3];
    foodX3[79]=planX[3];
    foodY3[79]=planY[3];
    foodX3[80]=planX[3];
    foodY3[80]=planY[3];
    foodX3[81]=planX[3];
    foodY3[81]=planY[3];

    this->update();

    }

}
void game2widget::M_changStone()
{


}
