#include "button.h"
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QApplication>
#include <QGraphicsScene>
#include<mainwidget.h>

button::button()
{
    setAcceptHoverEvents(true);
    setAcceptedMouseButtons(Qt::LeftButton);
}

QRectF button::boundingRect() const
{
    return QRectF(0,0,myButWidth,myButHeight);
}

void button::paint(QPainter *painter, const QStyleOptionGraphicsItem * /*option*/, QWidget */*widget*/)
{
    if(myHover)
    {
        painter->setPen(QColor(0,0,0));
    }
    painter->drawRoundedRect(0,0,myButWidth,myButHeight,5,5);
    painter->drawPixmap(0,0,myButWidth,myButHeight,myPixmap);
}

void button::setGeometry(int myWidht, int myHeight)
{
    myButWidth = myWidht;
    myButHeight = myHeight;
}

void button::mouseMoveEvent(QGraphicsSceneMouseEvent *Event)
{
    if(mIsMovable)
    {
    int distance = (Event->pos() - myStartMovePos).manhattanLength();
    if(distance > QApplication::startDragDistance())
    {
        QPointF newPoint = mapToScene(Event->pos() - myStartMovePos);

        if ((newPoint.x() < 0) || (newPoint.y() < 0))
            return;
        if ((newPoint.x() > 1128) || (newPoint.y() > 628))
            return;

        myButMoving = true;
        this->setPos(newPoint);
        }
    }
}

void button::mouseReleaseEvent(QGraphicsSceneMouseEvent *Event)
{
    if(!myButMoving)
   { emit btnMouseReleaseEvent(Event->button());
    QGraphicsItem::update();
    }
}

void button::mousePressEvent(QGraphicsSceneMouseEvent *Event)
{

    myButMoving = false;
    myStartMovePos = Event->pos();


}

void button::hoverEnterEvent(QGraphicsSceneHoverEvent *)
{
    myHover = true;
    QGraphicsItem::update();
}

void button::hoverLeaveEvent(QGraphicsSceneHoverEvent *)
{
    myHover = false;
    QGraphicsItem::update();
}

void button::setImage(QString adress)
{
    myPixmap.load(adress);
}

void button::enableMouseMoving()
{
  mIsMovable = true;
}

void button::disableMouseMoving()
{
  mIsMovable = false;
}
