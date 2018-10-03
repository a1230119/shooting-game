#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QtMath>
#include <QList>
#include <typeinfo>

class Bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
        Bullet();
        int count = 0;

public slots:
        void fly();
        void fly1();
        void fly2();
        void fly3();
        void explosion();
        void enemyFly();
        void enemyFly1();
        void enemyFly2();
private:
        //int count = 0;
};

#endif // BULLET_H
