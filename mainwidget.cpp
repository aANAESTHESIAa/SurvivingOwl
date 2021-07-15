#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QKeyEvent>
#include<QBrush>
#include <QMessageBox>





MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    this->resize(800, 500);
    this->setFixedSize(800, 500);

    scene = new QGraphicsScene(0, 0, windowWidth, windowHeight);
    scene->setStickyFocus(true);
    QPixmap bkg (":/bkg.png");

    scene->setBackgroundBrush(bkg.scaled(windowWidth, windowHeight,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

    ui->graphicsView->setScene(scene);

    scene->addRect(scene->sceneRect());



    animationTimer = new QTimer(this);
    connect(animationTimer,SIGNAL(timeout()),scene,SLOT(advance()));

    animationTimer->start(1000/60);

    generatorTimer = new QTimer(this);
    connect(generatorTimer,SIGNAL(timeout()),this,SLOT(onGenerate()));

    generatorTimer->start(1000);

    music();
    musB.setPos(650,15);
    musB.setGeometry(101,101);
    musB.setImage(":/but/ON1.png");


    H1B.setPos(25,10);
    H1B.setGeometry(50,50);
    H1B.setImage(":/but/heart.png");
   H2B.setPos(75,10);
   H2B.setGeometry(50,50);
   H2B.setImage(":/but/heart.png");
H2B.setVisible(f);

    H3B.setPos(125,10);
H3B.setGeometry(50,50);
  H3B.setImage(":/but/heart.png");

  owl = new Sprite();
  scene->addItem(owl);

  scene->addItem(&musB);
  scene->addItem(&H1B);
  scene->addItem(&H2B);
  scene->addItem(&H3B);


  connect(&musB, &button::btnMouseReleaseEvent,
          this, &MainWidget::myButB_clicked);
 startTimer(25);

    }

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::onGenerate()
{
    scene->addItem(new stone(scene->sceneRect().width()));


    //нарастающая
    int a;

    a=generatorTimer->interval();
//    qDebug()<<"interval"<<a;
    if (a>1010) {generatorTimer->setInterval(1000);}


    else{
    a=a-10;
    generatorTimer->setInterval(a);}


    int temp=owl->getHit();
    qDebug()<<"hitcounter"<<temp;
    if (temp==3)
    {
        generatorTimer->setInterval(5000);
}
}

void MainWidget::myButB_clicked(Qt::MouseButton)
{
    if(myMusic)
        {
            musB.setImage(":/but/OFF1.png");
            media_player->setVolume(0);
            myMusic = false;
            update();
        }else{
            musB.setImage(":/but/ON1.png");
            media_player->setVolume(100);
            myMusic = true;
             update();
        }

}

void MainWidget::health()
{

}

stone::stone(int xspread): QGraphicsPixmapItem(0)
{
    setPixmap(QPixmap(":/stone2.png"));
  setPos(rand()%(xspread- pixmap().width()),0);
}

void stone::advance(int phase)
{
    if(phase){
      moveBy(0,yspeed);
      if (data(0).toBool()==true)
          delete this;
    }

    }
void MainWidget::music()
{
    media_player = new QMediaPlayer(this);
    media_playlist = new QMediaPlaylist(media_player);

    media_player->setPlaylist(media_playlist);
    media_playlist->addMedia(QUrl("qrc:/music.mp3"));

    media_player->setVolume(100);
    media_playlist->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);

    media_player->play();
}


int stone::type() const
{
    return Type;
}
void MainWidget::keyPressEvent(QKeyEvent *event)
{
    this->keyboardKeys[event->key()] = true;
}

void MainWidget::keyReleaseEvent(QKeyEvent *event)
{
    this->keyboardKeys[event->key()] = false;
}

void MainWidget::timerEvent(QTimerEvent *)
{

    if(keyboardKeys[Qt::Key_A])
    {
        owl->frameLeft();

    }
    if(keyboardKeys[Qt::Key_D])
    {
        owl->frameRight();

    }
    if(keyboardKeys[Qt::Key_W])
    {
        owl->frameUp();
    }
    if(keyboardKeys[Qt::Key_S])
    {
        owl->frameDown();
    }
//....................................................
    int r=owl->getHit();
    if(r==0){H1B.setVisible(true);
        H2B.setVisible(true);
        H3B.setVisible(true);}
    if(r==1) H3B.setVisible(false);

    if(r==2) H2B.setVisible(false);
    if (r==3){ H1B.setVisible(false);

    }

    update();

}
