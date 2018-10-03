#include "ghost.h"
#include "mainwindow.h"

extern MainWindow *w;

Ghost::Ghost()
{
    setPixmap(QPixmap(":/ghost.png").scaled(60, 48));
}

void Ghost::move()
{
    QList<QGraphicsItem *>colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; ++i){
        if(typeid(*(colliding_items[i])) == typeid(Player)){
            w->pHP();
        }
    }
    if(direction)
    {
        setPos(x() + 10, y());
        if(x() >= 500)
            direction = false;
    }
    else
    {
        setPos(x() - 10, y());
        if(x() <= 20)
            direction = true;
    }
}
