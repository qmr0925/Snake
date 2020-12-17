#ifndef GAME2WIDGET_H
#define GAME2WIDGET_H

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

#include<QMediaPlayer>
#include<QMediaPlaylist>
#define longnumber3 21//宏定义游戏界面方格的多少
#define widthnumber3 20

class game2widget:public QWidget
{
  Q_OBJECT
public:
    explicit game2widget(QWidget *parent = 0);
    void paintEvent(QPaintEvent*);
    void keyPressEvent(QKeyEvent *e);
    QMediaPlaylist *playList  ;
    QMediaPlayer* player  ;
    QPushButton *upPush3;
    QPushButton *downPush3;
    QPushButton *leftPush3;
    QPushButton *rightPush3;
    QPushButton *StartPush3;
    QPushButton *ExitPush3;
    QLabel *ScoreLabel3;
    QLabel *LevelLabel3;
    QLabel *ScoreLabelNumber3;
    QLabel *LevelLabelNumber3;
    QLabel *BloodLabel3;

    QLabel *BloodLabelNumber3;

    QLabel *weap11;
    QLabel *weap12;
    int x11;
    int y11;
    int mashX;
    int mashY;

    QTimer *Timer3;
    QTimer *Timer5;
    bool hasMove=true;
    int snake3[200][2];//创建了一个蛇的身体坐标的数组
    int snake4[200][2];//这个数组只是上一个坐标的复制，在最后一步（咬到身体或者撞到边缘）需要将它的身体坐标还原
    //第二条蛇
    int snake5[200][2];//创建了一个蛇的身体坐标的数组
    int snake6[200][2];//这个数组只是上一个坐标的复制，在最后一步（咬到身体或者撞到边缘）需要将它的身体坐标还原
    static  int m_setDiretion3;//对方向的更改的存储
    static  int m_setDiretion4;//第二条蛇对方向的更改的存储
    QButtonGroup *buttonGroup3;//上下左右四个键构成一个按钮组，根据它们的返回值改变方向的值
    int foodX3[82];//食物i的x坐标
    int foodY3[82];//食物i的y坐标
    int planX[4];
    int planY[4];
    //  the weapon of the first plan

    int weapY[4];
    int weap1X[32];
    int weap1Y[32];

    bool start1=false;
    int m;//飞机的动向
    int draw=(rand()*10)%8+6;
    int size[50];
    double blood=100;//the blood of the snake
    int weapon=20;
   // int draw=1;


    int bodycount3;
    int bodycount4;
    bool Nobite;
    int Score3;
    int number=0;
    bool showmash1=false;
    bool isShots=false;
    int Difficulty3=1;//难度级别，时间变化
private:
    QPalette *palette;

signals:

public slots:
    void M_timeout3();
    void M_startPush3();
    void F_show3();
    void M_setDiretion3(int index);
   // void M_setDiretion4();
    void M_setDiretion5();
    void M_exitPush3();
   // void M_pausePush();
    void M_CheckGameOver3();
    void M_shots();
    void M_changeIndex();
    void M_changStone();
};

#endif // GAME2WIDGET_H
