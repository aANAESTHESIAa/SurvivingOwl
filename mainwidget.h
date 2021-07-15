#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

#include<QGraphicsView>
#include<QGraphicsScene>
#include<QGraphicsItem>
#include<QGraphicsLineItem>
#include<QGraphicsRectItem>
#include<QGraphicsPixmapItem>
#include <QGraphicsEllipseItem>
#include<QTimer>
#include<QBrush>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "button.h"
#include"sprite.h"
#include <QKeyEvent>
#include <QDebug>
namespace Ui {
class MainWidget;

}

class stone : public QGraphicsPixmapItem{
public:
  stone(int xspread);
enum { Type = UserType +1};

public:

  void advance(int phase);

private:
  int yspeed=2;

public:
  int type() const;
};



class MainWidget : public QWidget
{
    Q_OBJECT

public:
     bool f=true;
    button H1B;
    button H2B;
    button H3B;
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void timerEvent(QTimerEvent *);


    void music();
private slots:
 void onGenerate();
 void myButB_clicked(Qt::MouseButton);
 void health();
private:
 button musB;

QMap <int, bool> keyboardKeys;
 bool myMusic;
 QMediaPlayer *media_player;
 QMediaPlaylist *media_playlist;
    Ui::MainWidget *ui;
    QGraphicsScene* scene;
    QTimer* animationTimer;
    QTimer* generatorTimer;

     Sprite *owl;
    const int windowWidth = 800;
    const int windowHeight = 500;

};


#endif // MAINWIDGET_H
