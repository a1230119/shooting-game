#include "enemy.h"
#include "mainwindow.h"
#include <QTime>

extern MainWindow *w;

Enemy::Enemy()
{
    setPixmap(QPixmap(":/enemy.png").scaled(80, 80));
    timer = new QTimer;
    timer->start(10);
}

void Enemy::move()
{
    QList<QGraphicsItem *>colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; ++i){
        if(typeid(*(colliding_items[i])) == typeid(Player)){
            w->pHP();
        }
    }
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    if(bl == false)
    {
        //target position
        tx = qrand() % 520;
        ty = qrand() % 180 + 20;
        //direction vector
        dx = (tx - pos().x())/20;
        dy = (ty - pos().y())/20;
        count = 0;
        bl = true;
    }
    else
    {
        setPos(pos().x() + dx, pos().y() + dy);
        count++;
        if(count == 20)
            bl = false;
    }
}

void Enemy::attack()
{
    Bullet *b = new Bullet;
    b->setPixmap(QPixmap(":/bomb.png").scaled(25, 25));
    b->setPos(x() + pixmap().width()/2 - b->pixmap().width()/2, y() + pixmap().height());
    this->scene()->addItem(b);
    Bullet *b1 = new Bullet;
    b1->setPixmap(QPixmap(":/bomb.png").scaled(25, 25));
    b1->setPos(x() + pixmap().width()/2 - b1->pixmap().width()/2, y() + pixmap().height());
    this->scene()->addItem(b1);
    Bullet *b2 = new Bullet;
    b2->setPixmap(QPixmap(":/bomb.png").scaled(25, 25));
    b2->setPos(x() + pixmap().width()/2 - b2->pixmap().width()/2, y() + pixmap().height());
    this->scene()->addItem(b2);
    b->connect(timer, SIGNAL(timeout()), b, SLOT(enemyFly()));
    b1->connect(timer, SIGNAL(timeout()), b1, SLOT(enemyFly1()));
    b2->connect(timer, SIGNAL(timeout()), b2, SLOT(enemyFly2()));
}
