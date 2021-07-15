#ifndef BUTTON_H
#define BUTTON_H
#include <QObject>
#include <QGraphicsItem>
#include <QPointF>
#include <QPixmap>

class button : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    button();

    QRectF boundingRect() const override;


    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
    void setGeometry(int myWidht, int myHeight);

    void mouseMoveEvent(QGraphicsSceneMouseEvent *Event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *Event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *Event) override;

    void hoverEnterEvent(QGraphicsSceneHoverEvent *) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *) override;

    void setImage(QString adress);

    void enableMouseMoving();
    void disableMouseMoving();

signals:
    void btnMouseReleaseEvent(Qt::MouseButton);

private:
    int myButWidth{0};
    int myButHeight{0};

    bool mIsMovable{false};
    bool myButMoving{false};
    bool myHover{false};
    QPointF myStartMovePos;
    QPixmap myPixmap;


};


#endif // BUTTON_H
