#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include<QIcon>
#include<QPalette>
#include<QBrush>
#include<QPixmap>
#include<QPushButton>
#include<QMessageBox>
#include<QPaintEvent>
#include<QPainter>
#include<QLabel>
#include<QTimer>
#include<QTime>
#include<ctime>
#include<QButtonGroup>
#include<QKeyEvent>
#include<QSoundEffect>
#include<QApplication>
#include<QString>
#include<QFileDialog>
#include<QDesktopWidget>
#define longnumber 32//宏定义游戏界面方格的多少
#define widthnumber 24


class Gamewidget:public QWidget
{
  Q_OBJECT
public:
    explicit Gamewidget(QWidget *parent = 0);
    void paintEvent(QPaintEvent*);
    void keyPressEvent(QKeyEvent *e);
   // void keyReleaseEvent(QKeyEvent *e);
    QPushButton *upPush;
    QPushButton *downPush;
    QPushButton *leftPush;
    QPushButton *rightPush;
    QPushButton *StartPush;
    QPushButton *ExitPush;
    QPushButton *setPush;
    QPushButton *PhotoPush;
    QPushButton *speedPush;
    QLabel *ScoreLabel;
    QLabel *LevelLabel;
    QLabel *ScoreLabelNumber;
    QLabel *LevelLabelNumber;

    QTimer *Timer;

    QSoundEffect *effect;
    QSoundEffect *effect1;
     int num=0;
    int snake[200][2];//创建了一个蛇的身体坐标的数组
    int snake1[200][2];//这个数组只是上一个坐标的复制，在最后一步（咬到身体或者撞到边缘）需要将它的身体坐标还原
    static  int m_setDiretion;//对方向的更改的存储
    QButtonGroup *buttonGroup;//上下左右四个键构成一个按钮组，根据它们的返回值改变方向的值
    int foodX[74];//食物i的x坐标
    int foodY[74];//食物i的y坐标


   int draw=(rand()*10)%8+11;
    int food1x;//食物1的X坐标
    int food1y;//食物1的Y坐标

    int food2x;//食物2的X坐标
    int food2y;//食物2的Y坐标
    bool isSpeed=false;
    int size[60];
    int music1=0;//音乐标记值



    int bodycount;
    bool Nobite;
    int Score;
    int Difficulty;//难度级别，时间变化
private:
    QPalette *palette;

signals:

public slots:
    void M_timeout();
   // void F_timeout();
    void M_startPush();
    void F_show();
    void M_setDiretion(int index);
    void M_exitPush();
   // void M_pausePush();
    void M_CheckGameOver();
     void photo();
     void setMusic();
    void  M_setSpeed();
};

#endif // GAMEWIDGET_H
