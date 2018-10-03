#ifndef PLAYER_H
#define PLAYER_H

#include "bullet.h"

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player();
    void attack(Bullet *b1, Bullet *b2, Bullet *b3, Bullet *b4);
    void skill(Bullet *b1, Bullet *b2, Bullet *b3);
};

#endif // PLAYER_H
