#ifndef GAME3WIDGET_H
#define GAME3WIDGET_H
#include<QPushButton>
#include <QWidget>
#include<QPaintEvent>
class game3widget:public QWidget
{
  Q_OBJECT

public:
     explicit game3widget(QWidget *parent = 0);
     void paintEvent(QPaintEvent*);
     QPushButton *exitPush3;

signals:

public slots:

    void M_exitPush3();

};

#endif // GAME3WIDGET_H
