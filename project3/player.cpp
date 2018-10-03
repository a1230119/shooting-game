#include "player.h"

Player::Player()
{
    setPixmap(QPixmap(":/airplane.png").scaled(80, 80));
}

void Player::attack(Bullet *b1, Bullet *b2, Bullet *b3, Bullet *b4)
{
    b1->setPixmap(QPixmap(":/bullet.png").scaled(15, 15));
    b1->setPos(x() + pixmap().width()/2 - b1->pixmap().width()/2, y() - b1->pixmap().height());
    this->scene()->addItem(b1);

    b2->setPixmap(QPixmap(":/bullet.png").scaled(15, 15));
    b2->setPos(x() + pixmap().width()/2 - b2->pixmap().width()/2, y() - b2->pixmap().height());
    this->scene()->addItem(b2);

    b3->setPixmap(QPixmap(":/bullet.png").scaled(15, 15));
    b3->setPos(x() + pixmap().width()/2 - b3->pixmap().width()/2, y() - b3->pixmap().height());
    this->scene()->addItem(b3);

    b4->setPixmap(QPixmap(":/bullet.png").scaled(15, 15));
    b4->setPos(x() + pixmap().width()/2 - b3->pixmap().width()/2, y() - b3->pixmap().height());
    this->scene()->addItem(b4);
}

void Player::skill(Bullet *b1, Bullet *b2, Bullet *b3)
{
    b1->setPixmap(QPixmap(":/fireworks.png").scaled(100, 100));
    b1->setPos(x() - 10, y() - 140);
    this->scene()->addItem(b1);

    b2->setPixmap(QPixmap(":/fireworks.png").scaled(100, 100));
    b2->setPos(x() - 136, y() + 116);
    this->scene()->addItem(b2);

    b3->setPixmap(QPixmap(":/fireworks.png").scaled(100, 100));
    b3->setPos(x() + 116, y() + 116);
    this->scene()->addItem(b3);
}
