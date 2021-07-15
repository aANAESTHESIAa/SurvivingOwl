#include "sprite.h"
#include "mainwidget.h"


Sprite::Sprite(QObject *parent) : QObject(parent)
{
    frameWidth = 150  ;
    frameHeight = 150;

    pointCenter.setX(startX);
    pointCenter.setY(startY);

    currentStepLeft = 0;
    currentStepRight = 0;

    vectorStepLeft = loadVector(pathToFileStepLeft);
    vectorStepRight = loadVector(pathToFileStepRight);

    countStepLeft = vectorStepLeft.count();
    countStepRight = vectorStepRight.count();

    outputSprite = vectorStepRight.at(0);
}

void Sprite::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(pointCenter.x(),
                        pointCenter.y(),
                        *outputSprite);




    Q_UNUSED(option);
    Q_UNUSED(widget);
}
int check=0;
void Sprite::frameLeft()
{if(hitcounter==3)return;
    else
    if (currentStepLeft == countStepLeft - 1)
        currentStepLeft = 0;
    else currentStepLeft ++;
//qDebug()<<"pointcenter"<<pointCenter.x();
    if (pointCenter.x() > windowBorderLeft) {
        pointCenter.setX(pointCenter.x() - speed);  //передвижение
    check++;
    if(check==5) {
        check=0;
        outputSprite = vectorStepLeft.at(currentStepLeft);//смена кадра

    }
    }


    this->update(gameRectangle);
}

void Sprite::frameRight()

    {if(hitcounter==3)return;
    else
        if (currentStepRight == countStepRight - 1)
            currentStepRight = 0;
        else currentStepRight ++;

        if (pointCenter.x() < windowBorderRight)
        {
            pointCenter.setX(pointCenter.x() + speed);
        check++;
        if(check==5) {
            check=0;
            outputSprite = vectorStepRight.at(currentStepRight);

        }
        }


        this->update(gameRectangle);
    }


void Sprite::frameUp()

    {if(hitcounter==3)return;
    else
        if (currentStepLeft == countStepLeft - 1)
            currentStepLeft = 0;
        else currentStepLeft ++;


    if (pointCenter.y() > windowBorderTop)
    {pointCenter.setY(pointCenter.y() - speed);
     check++;
        if(check==5)
        {check=0;
         outputSprite = vectorStepLeft.at(currentStepLeft);}
        this->update(gameRectangle);
    }
    }


void Sprite::frameDown()
{
    {if(hitcounter==3)return;
        else
        if (currentStepLeft == countStepLeft - 1)
            currentStepLeft = 0;
        else currentStepLeft ++;
    if (pointCenter.y() < windowVorderBottom - frameHeight)
    {
        pointCenter.setY(pointCenter.y() + speed);
        check++;
        if(check==5){
            check=0;
         outputSprite = vectorStepLeft.at(currentStepLeft);}

        this->update(gameRectangle);
    }

    }
}

void Sprite::checkCollision()
{

}
QVector<QPixmap *> Sprite::loadVector(QString path)
{
    tempSpriteImage = new QPixmap(path);
    QVector<QPixmap *> vector;

    for (int x = 0; x < tempSpriteImage->width(); x += frameWidth)
    {
        QPixmap tempPix = tempSpriteImage->copy(x, 0, frameWidth, frameHeight);
        vector.append(new QPixmap(tempPix));
    }

    return vector;
}



int Sprite::getX()
{
    return pointCenter.x() + frameWidth/2;
}

int Sprite::getY()
{
    return pointCenter.y() + frameHeight/2 - 10;
}

int Sprite::getLeftBorder()
{
    return pointCenter.x();
}

int Sprite::getRightBorder()
{
    return pointCenter.x() + frameWidth;
}

int Sprite::getTopBorder()
{
    return pointCenter.y();
}

int Sprite::getBottomBorder()
{
    return pointCenter.y() + frameHeight;
}

int Sprite::getHit()
{
    return hitcounter;
}

void Sprite::setHit(int value)
{
 hitcounter=value;
}

QRectF Sprite::boundingRect() const
{
    return QRectF(gameRectangle);
}


void Sprite::advance(int phase)
{
    if(!phase)
    {
        foreach(QGraphicsItem* item, collidingItems()) {
                  if(item->type()==stone::Type)
                  {
                      if(item->pos().x()>pointCenter.x()-45&&item->pos().x()<pointCenter.x()+110)
                     if(item->pos().y()>pointCenter.y()-45&&item->pos().y()<pointCenter.y()+100)

                      {
                         item->setData(0,true);
                        hitcounter++;
                        {if (hitcounter==3)
                            {
                                QMessageBox::warning(nullptr,"Attention!","You are dead!","Try again(");


                                hitcounter=0;


                     }
    }
}
}}}}
