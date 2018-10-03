#ifndef GHOST_H
#define GHOST_H

#include "enemy.h"

class Ghost : public Enemy
{
    Q_OBJECT
public:
    Ghost();

public slots:
    void move();

private:
    bool direction = true;//true=>right
};

#endif // GHOST_H
