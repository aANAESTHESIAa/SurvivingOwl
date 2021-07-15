#ifndef SPRITE_H
#define SPRITE_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QDebug>
#include <QMessageBox>


class Sprite : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Sprite(QObject *parent = nullptr);

private:
     void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

public:
    QRectF boundingRect() const override;
    QVector<QPixmap *> loadVector(QString path);

public:
//     bool getBulletColor();

//     void death();

//    void takeDamage();
//    int getHealth();
    void frameLeft();
    void frameRight();
    void frameUp();
    void frameDown();
    void checkCollision();
    int getX();
    int getY();
    int getLeftBorder();
    int getRightBorder();
    int getTopBorder();
    int getBottomBorder();
int hitcounter=0;
 int getHit();
 void setHit(int);
protected:
    int startY = 350;
    int speed = 4;
 const int startX = 50;
    int spriteCurrent;

    int frameHeight;
    int frameWidth;

    // параметры вектора спрайтов
    int countStepLeft;
    int countStepRight;

    int currentStepLeft;
    int currentStepRight;

    // границы экрана
    const int windowBorderLeft = 0;
    const int windowBorderRight = 650;
    const int windowBorderTop = 0;
    const int windowVorderBottom = 500;

    QPixmap *tempSpriteImage;
    QPoint pointCenter;
    QRectF gameRectangle {0, 0, 800, 500};
    QVector<QPixmap *> spriteVector;

    QPixmap *outputSprite;
    QVector<QPixmap *> vectorStepLeft;
    QVector<QPixmap *> vectorStepRight;
    QString pathToFileStepLeft = ":/fly.png";
    QString pathToFileStepRight = ":/fly.png";



public:
    void advance(int phase);
};

#endif // PG_SPRITE_H
