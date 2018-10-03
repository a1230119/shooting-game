#ifndef ENEMY_H
#define ENEMY_H

#include "bullet.h"

class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy();
    QTimer *timer;

public slots:
    void attack();
    void move();

private:
    bool bl = false;
    int tx, ty, dx, dy, count;

};

#endif // ENEMY_H
