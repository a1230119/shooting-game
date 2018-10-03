#include "bullet.h"
#include "enemy.h"
#include "mainwindow.h"
#include <QDebug>

extern MainWindow *w;

Bullet::Bullet()
{

}

void Bullet::fly()
{
    QList<QGraphicsItem *>colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; ++i){
        if(typeid(*(colliding_items[i])) == typeid(Enemy)){
            w->eHP(1);
            scene()->removeItem(this);
            delete this;
        }
    }
    setPos(x() - qSqrt(0.2), y() - qSqrt(8.8));
    if(y() < 0) {
        this->scene()->removeItem(this);
        delete this;
    }
}

void Bullet::fly1()
{
    QList<QGraphicsItem *>colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; ++i){
        if(typeid(*(colliding_items[i])) == typeid(Enemy)){
            w->eHP(1);
            scene()->removeItem(this);
            delete this;
        }
    }
    setPos(x() - qSqrt(1.7), y() - qSqrt(7.3));
    if(y() < 0) {
        this->scene()->removeItem(this);
        delete this;
    }
}

void Bullet::fly2()
{
    QList<QGraphicsItem *>colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; ++i){
        if(typeid(*(colliding_items[i])) == typeid(Enemy)){
            w->eHP(1);
            scene()->removeItem(this);
            delete this;
        }
    }
    setPos(x() + qSqrt(1.7), y() - qSqrt(7.3));
    if(y() < 0) {
        this->scene()->removeItem(this);
        delete this;
    }
}

void Bullet::fly3()
{
    QList<QGraphicsItem *>colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; ++i){
        if(typeid(*(colliding_items[i])) == typeid(Enemy)){
            w->eHP(1);
            scene()->removeItem(this);
            delete this;
        }
    }
    setPos(x() + qSqrt(0.2), y() - qSqrt(8.8));
    if(y() < 0) {
        this->scene()->removeItem(this);
        delete this;
    }
}

void Bullet::explosion()
{
    QList<QGraphicsItem *>colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; ++i){
        if(typeid(*(colliding_items[i])) == typeid(Enemy)){
            w->eHP(15);
            scene()->removeItem(this);
            delete this;
        }
    }
    if(count == 8)
    {
        scene()->removeItem(this);
        delete this;
    }
    /*
    switch (count % 5) {
    case 0:
        setPixmap(QPixmap(":/01.png").scaled(100, 100));
        break;
    case 1:
        setPixmap(QPixmap(":/02.png").scaled(100, 100));
        break;
    case 2:
        setPixmap(QPixmap(":/03.png").scaled(100, 100));
        break;
    case 3:
        setPixmap(QPixmap(":/04.png").scaled(100, 100));
        break;
    default:
        setPixmap(QPixmap(":/05.png").scaled(100, 100));
        break;
    }
    */
    count++;
}

void Bullet::enemyFly()
{
    QList<QGraphicsItem *>colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; ++i){
        if(typeid(*(colliding_items[i])) == typeid(Player)){
            w->pHP();
            scene()->removeItem(this);
            delete this;
        }
    }
    setPos(x() + qSqrt(2), y() + qSqrt(7));
    if(y() > 600) {
        this->scene()->removeItem(this);
        delete this;
    }
}

void Bullet::enemyFly1()
{
    QList<QGraphicsItem *>colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; ++i){
        if(typeid(*(colliding_items[i])) == typeid(Player)){
            w->pHP();
            scene()->removeItem(this);
            delete this;
        }
    }
    setPos(x() - qSqrt(2), y() + qSqrt(7));
    if(y() > 600) {
        this->scene()->removeItem(this);
        delete this;
    }
}

void Bullet::enemyFly2()
{
    QList<QGraphicsItem *>colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; ++i){
        if(typeid(*(colliding_items[i])) == typeid(Player)){
            w->pHP();
            scene()->removeItem(this);
            delete this;
        }
    }
    setPos(x(), y() + 3);
    if(y() > 600) {
        this->scene()->removeItem(this);
        delete this;
    }
}
