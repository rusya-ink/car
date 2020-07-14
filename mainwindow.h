#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QSystemTrayIcon>
#include "windows.h"
#include <car.h>


class MainWindow: public QGraphicsView
{
    Q_OBJECT
public:
    MainWindow();
    QGraphicsScene * scene;
    QTimer* timer;
    Car * car;

public slots:
    void press();
};

#endif // MAINWINDOW_H
