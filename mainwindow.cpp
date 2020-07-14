#include "mainwindow.h"
#include <QScrollBar>
#include <car.h>
#include <QTimer>
#include <QDebug>

MainWindow::MainWindow()
{
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0, 800, 600);
    setScene(scene);
    setFixedSize(800, 600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    verticalScrollBar()->blockSignals(true);
    horizontalScrollBar()->blockSignals(true);

    //Timer
    timer = new QTimer();
    timer->setInterval(10);
    connect(timer, SIGNAL(timeout()), this, SLOT(press()));

    car = new Car();
    scene->addItem(car);
    car->setPos(50, 50);
    car->initialize();
    timer->start();
}

void MainWindow::press(){

    //working with pressing
    timer->stop();
    bool w=false, a=false, s=false, d=false;

    qDebug()<<"tick";
    if(GetAsyncKeyState(VK_NUMPAD8)<=-32767){
        w=true;
    }

    if(GetAsyncKeyState(VK_NUMPAD4)<=-32767){
        a=true;
    }

    if(GetAsyncKeyState(VK_NUMPAD6)<=-32767){
        d=true;
    }

    if(GetAsyncKeyState(VK_NUMPAD5)<=-32767){
        s=true;
    }
    car->move(w, a, s, d);

    timer->start();

}
