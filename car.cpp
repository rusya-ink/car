#include "car.h"
#include <QTimer>
#include <QBrush>
#include <QDebug>
#include <qmath.h>
#include <QGraphicsScene>


Car::Car(QGraphicsItem * parent): MyRectItem (parent)
{
    setRect(0, 0, 50, 100);
    setBrush(QBrush(QColor(Qt::black)));
    engine=0;
    wheelAngle=0;
    RF = new MyRectItem(this);
    RB = new MyRectItem(this);
    LF = new MyRectItem(this);
    LB = new MyRectItem(this);
    RF->setBrush(QBrush(QColor("pink")));
    LF->setBrush(QBrush(QColor("pink")));
    LB->setBrush(QBrush(QColor("pink")));
    RB->setBrush(QBrush(QColor("pink")));
}

double Car::moveDist()
{
    return engine;
}

void Car::move(bool w, bool a, bool s, bool d)
{
    qDebug()<<w<<a<<s<<d;
    if(w||s){
        if(w){
            engine+=engineConst;
        }
        if(s){
            engine-=engineConst;
        }
    }
    if(engine>engineConst/3){
        engine-=engineConst/3;
    }else if(engine<-engineConst/3){
        engine+=engineConst/3;
    }else{
        engine=0;
    }
    if(a||d){
        if(d){
            wheelAngle+=wheelConst;
        }
        if(a){
            wheelAngle-=wheelConst;
        }
    }
    if(wheelAngle>wheelConst/3){
        wheelAngle-=wheelConst/3;
    }else if(wheelAngle<-wheelConst/3){
        wheelAngle+=wheelConst/3;
    }else{
        wheelAngle=0;
    }
    if(wheelAngle>maxWheelAngle){
        wheelAngle=maxWheelAngle;
    }else if(wheelAngle<-maxWheelAngle){
        wheelAngle=-maxWheelAngle;
    }
    if(engine>maxSpeed){
        engine=maxSpeed;
    }else if(engine<-maxSpeed){
        engine=-maxSpeed;
    }
    actualMove();
}


QPointF Car::topRight_()
{
    double gip =boundingRect().right();
    return QPointF(gip*qCos(qDegreesToRadians(rotation())), gip*qSin(qDegreesToRadians(rotation())));
}

QPointF Car::bottomLeft_()
{
    double gip=boundingRect().bottom();
    return QPointF(gip*qSin(qDegreesToRadians(rotation())), gip*qCos(qDegreesToRadians(rotation())));
}





void Car::initialize()
{
    angleOfRect_=qRadiansToDegrees(qAtan(boundingRect().bottom()/boundingRect().right()));
    lenghtToCenter_=qSqrt(qPow(boundingRect().bottom()/2, 2) + qPow(boundingRect().right()/2, 2));
    RF->setRect(0, 0, wheelWidth, wheelLenght);
    RF->setPos(topRight_()+bottomLeft_()*deltaWheel_-RF->boundingRect().bottomRight()/2);
    RB->setRect(0, 0, wheelWidth, wheelLenght);
    RB->setPos(topRight_()+bottomLeft_()*(1-deltaWheel_)-RB->boundingRect().bottomRight()/2);
    LF->setRect(0, 0, wheelWidth, wheelLenght);
    LF->setPos(bottomLeft_()*deltaWheel_-LF->boundingRect().bottomRight()/2);
    LB->setRect(0, 0, wheelWidth, wheelLenght);
    LB->setPos(bottomLeft_()*(1-deltaWheel_)-LF->boundingRect().bottomRight()/2);
    scene()->addItem(RF);
    scene()->addItem(RB);
    scene()->addItem(LF);
    scene()->addItem(LB);
}



void Car::actualMove()
{
    if(scene()!=nullptr){
        if(wheelAngle!=0.0){
            qDebug()<<"engine "<<engine;
            qDebug()<<"wheelAngle "<<wheelAngle;
            //qDebug()<<"1: "<<qSqrt(qPow(bottomLeft_().x(), 2) + qPow(bottomLeft_().y(), 2));
            double radius = (1-2*deltaWheel_)*boundingRect().bottom()/qSin(qDegreesToRadians(wheelAngle));
            qDebug()<<"radius "<<radius;
            double angleRad = 2*qAsin(moveDist()/(2*radius));
            qDebug()<<"angleRad "<<angleRad;
            double wheelAngleRad=qDegreesToRadians(wheelAngle);
            qDebug()<<"wheelAngleRad "<<wheelAngleRad;
            double horda = 2*radius*qSin(moveDist()/(2*radius));
            qDebug()<<"horda "<<horda;
            setPos(pos()+QPointF(horda*qSin(wheelAngleRad+qDegreesToRadians(rotation())+angleRad),
                                 -horda*qCos(wheelAngleRad+qDegreesToRadians(rotation())+angleRad)));

            rotateAroundCenter(qRadiansToDegrees(angleRad));

            RF->rotateAroundCenter(wheelAngle-RF->rotation());
            LF->rotateAroundCenter(wheelAngle-LF->rotation());
        }else{
            setPos(pos()+QPointF(moveDist()*qSin(qDegreesToRadians(rotation())), -moveDist()*qCos(qDegreesToRadians(rotation()))));
        }

    }

}

