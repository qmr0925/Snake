//#include "snake.h"
//#include<QPaintEvent>
//#include<QPainter>
//snake::snake()
//{

//}
//void snake::paintEvent(QPaintEvent*)//绘图事件
//{
//    QPainter painter(this);
//    if(0<=snake2[0][0]&&snake2[0][0]<=600&&0<=snake2[0][1]&&snake2[0][1]<=480&&Nobite)
//    {
//        //qDebug()<<snake[0][0];
//        for(int i=bodycount;i>0;i--)
//        {
//            if(i==bodycount)//画出尾巴部分
//            {
//                if(snake2[i][0]==snake2[i-1][0]&&snake2[i][1]<snake2[i-1][1])
//                {
//                    painter.drawImage(QRect(snake2[i][0],snake2[i][1],30,30),QImage(":/Images/taildown.png"));
//                }
//                else  if(snake2[i][0]==snake2[i-1][0]&&snake2[i][1]>snake2[i-1][1])
//                {
//                    painter.drawImage(QRect(snake2[i][0],snake2[i][1],30,30),QImage(":/Images/tailup.png"));
//                }
//                else  if(snake2[i][0]<snake2[i-1][0]&&snake2[i][1]==snake2[i-1][1])
//                {
//                    painter.drawImage(QRect(snake2[i][0],snake2[i][1],30,30),QImage(":/Images/tailright.png"));
//                }
//                else  if(snake2[i][0]>snake2[i-1][0]&&snake2[i][1]==snake2[i-1][1])
//                {
//                    painter.drawImage(QRect(snake2[i][0],snake2[i][1],30,30),QImage(":/Images/tailleft.png"));
//                }
//            }
//            else
//            {
//                if((snake2[i][0]==snake2[i-1][0]&& snake2[i][1]<snake2[i-1][1]&&snake2[i+1][0]<snake2[i][0]&&snake2[i+1][1]==snake2[i][1])||
//                        ((snake2[i][0]>snake2[i-1][0])&& snake2[i][1]==snake2[i-1][1]&&snake2[i+1][0]==snake2[i][0]&&snake2[i+1][1]>snake2[i][1]))
//                {
//                    painter.drawImage(QRect(snake2[i][0],snake2[i][1],30,30),QImage(":/Images/leftdown.png"));
//                }
//                else if((snake2[i][0]<snake2[i-1][0]&& snake2[i][1]==snake2[i-1][1]&&snake2[i+1][0]==snake2[i][0]&&snake2[i+1][1]>snake2[i][1])||
//                        (snake2[i][0]==snake2[i-1][0]&& snake2[i][1]<snake2[i-1][1]&&snake2[i+1][0]>snake2[i][0]&&snake2[i+1][1]==snake2[i][1]))
//                {
//                    painter.drawImage(QRect(snake2[i][0],snake2[i][1],30,30),QImage(":/Images/rightdown.png"));
//                }
//                else if((snake2[i][0]>snake2[i-1][0]&& snake2[i][1]==snake2[i-1][1]&&snake2[i+1][0]==snake2[i][0]&&snake2[i+1][1]<snake2[i][1])||
//                        (snake2[i][0]==snake2[i-1][0]&& snake2[i][1]>snake2[i-1][1]&&snake2[i+1][0]<snake2[i][0]&&snake2[i+1][1]==snake2[i][1]))
//                {
//                    painter.drawImage(QRect(snake2[i][0],snake2[i][1],30,30),QImage(":/Images/leftup.png"));
//                }
//                else if(((snake2[i][0]==snake2[i-1][0])&& snake2[i][1]>snake2[i-1][1]&&snake2[i+1][0]>snake2[i][0]&&snake2[i+1][1]==snake2[i][1])||
//                        (snake2[i][0]<snake2[i-1][0]&& snake2[i][1]==snake2[i-1][1]&&snake2[i+1][0]==snake2[i][0]&&snake2[i+1][1]<snake2[i][1]))
//                {
//                    painter.drawImage(QRect(snake2[i][0],snake2[i][1],30,30),QImage(":/Images/rightup.png"));
//                }

//                else if((snake2[i][0]==snake2[i-1][0]&&snake2[i][0]==snake2[i+1][0])&&((snake2[i][1]<snake2[i-1][1]&&snake2[i+1][1]<snake2[i][1])||
//                                                                                   (snake2[i][1]>snake2[i-1][1]&&snake2[i+1][1]>snake2[i][1])))
//                {
//                    painter.drawImage(QRect(snake2[i][0],snake2[i][1],30,30),QImage(":/Images/downup.png"));

//                }
//                else if ((snake2[i][1]==snake2[i-1][1]&&snake2[i][1]==snake2[i+1][1])&&((snake2[i][0]<snake2[i-1][0]&&snake2[i+1][0]<snake2[i][0])||
//                                                                                    (snake2[i][0]>snake2[i-1][0]&&snake2[i+1][0]>snake2[i][0])))
//                {
//                    painter.drawImage(QRect(snake2[i][0],snake2[i][1],30,30),QImage(":/Images/leftright.png"));

//                }
//            }
//        }
//    }

//    for(int i=0;i<20;i++)
//    {

//    painter.drawImage(QRect(foodX1[i],foodY1[i],30,30),QImage(":/Images/Apple.png"));

//    //painter.drawImage(QRect(200,200,30,30),QImage(":/Images/Apple.png"));
//    // this->repaint();

//    //qDebug()<<snake[0][0];
//    }

////    painter.drawImage(QRect(food1x,food1y,30,30),QImage(":/Images/Apple.png"));
////    painter.drawImage(QRect(food2x,food2y,30,30),QImage(":/Images/Apple.png"));

////    painter.setPen(Qt::green);

////    for(int i=0;i<=widthnumber;i++)
////    {
////        for(int j=0;j<=longnumber;j++)
////        {
////            painter.drawRect(QRect(30*j,30*i,30,30));
////        }
////    }
//    switch (m_setDiretion1)
//    {
//    case 1: painter.drawImage(QRect(snake2[0][0],snake2[0][1],30,30),QImage(":/Images/headup.png"));
//        if(bodycount==1)  painter.drawImage(QRect(snake2[0][0],snake2[0][1]+30,30,30),QImage(":/Images/tailup.png"));
//        break;
//    case 2: painter.drawImage(QRect(snake2[0][0],snake2[0][1],30,30),QImage(":/Images/headdown.png"));
//        if(bodycount==1) painter.drawImage(QRect(snake2[0][0],snake2[0][1]-30,30,30),QImage(":/Images/taildown.png"));
//        break;
//    case 3: painter.drawImage(QRect(snake2[0][0],snake2[0][1],30,30),QImage(":/Images/headleft.png"));
//        if(bodycount==1) painter.drawImage(QRect(snake2[0][0]+30,snake2[0][1],30,30),QImage(":/Images/tailleft.png"));
//        break;
//    case 4: painter.drawImage(QRect(snake2[0][0],snake2[0][1],30,30),QImage(":/Images/headright.png"));
//        if(bodycount==1)  painter.drawImage(QRect(snake2[0][0]-30,snake2[0][1],30,30),QImage(":/Images/tailright.png"));
//        break;
//    default:
//        break;
//    }
//}
