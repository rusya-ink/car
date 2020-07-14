#include "myrectitem.h"
#include <qmath.h>

MyRectItem::MyRectItem(QGraphicsItem * parent): QGraphicsRectItem(parent){}

void MyRectItem::rotateAroundCenter(double angleDegr)
{
    QPointF oldCenter = center();
    setRotation(rotation()+angleDegr);

    QPointF newCenter = center();
    setPos(pos()-newCenter+oldCenter);
}
QPointF MyRectItem::center()
{
    double angleOfRect_ = qRadiansToDegrees(qAtan(boundingRect().bottom()/boundingRect().right()));
    double lenghtToCenter_=qSqrt(qPow(boundingRect().bottom()/2, 2) + qPow(boundingRect().right()/2, 2));
    double gip=lenghtToCenter_;
    return QPointF(gip*qCos(qDegreesToRadians(rotation()+angleOfRect_)), gip*qSin(qDegreesToRadians(rotation()+angleOfRect_)));
}
