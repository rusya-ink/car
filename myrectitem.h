#ifndef MYRECTITEM_H
#define MYRECTITEM_H
#include <QGraphicsRectItem>


class MyRectItem: public QGraphicsRectItem
{
public:
    MyRectItem(QGraphicsItem * parent = 0);
    void rotateAroundCenter(double angleDegr);
    QPointF center();
};

#endif // MYRECTITEM_H
