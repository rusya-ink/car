#ifndef CAR_H
#define CAR_H
#include <myrectitem.h>

class Car: public MyRectItem
{
public:
    Car(QGraphicsItem * parent=nullptr);
    MyRectItem * RF, * RB, * LF, *LB;
    double engine;
    double wheelWidth=5;
    double wheelLenght=20;
    double moveDist();
    double wheelAngle;
    double engineConst=0.05;
    double wheelConst=1;
    double maxSpeed=3;
    double maxWheelAngle=40;
    void move(bool w, bool a, bool s, bool d);
    void actualMove();
    void initialize();

private:
    double deltaWheel_=0.2;
    QPointF topRight_();
    QPointF bottomLeft_();
    double lenghtToCenter_;
    double angleOfRect_;

};

#endif // CAR_H
