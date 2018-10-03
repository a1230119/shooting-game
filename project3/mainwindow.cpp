#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QList>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    scene(new QGraphicsScene(0, 0, 600, 570)),
    timer1(new QTimer),timer2(new QTimer),timer3(new QTimer)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
    ui->progressBar->setStyleSheet("QProgressBar{ background-color: white; border-radius: 2px; } QProgressBar:chunk{ background-color: rgb(251, 233, 0);}");
    ui->progressBarEnemy->setStyleSheet("QProgressBar{ background-color: white; border-radius: 2px; } QProgressBar:chunk{ background-color: red;}");   
    ui->progressBarPlayer->setStyleSheet("QProgressBarPlayer{ background-color: white; border-radius: 2px;} QProgressBar:chunk{ background-color: rgb(87, 219, 64);}");
    game();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::game()
{
    player = new Player;
    scene->addItem(player);
    player->setPos(260, 480);

    enemy = new Enemy;
    scene->addItem(enemy);
    enemy->setPos(260, 0);
    timer1->start(10);
    timer2->start(60);
    timer3->start(400);
    enemy->connect(timer2, SIGNAL(timeout()), enemy, SLOT(move()));
    enemy->connect(timer3, SIGNAL(timeout()), enemy, SLOT(attack()));

    ghost1 = new Ghost;
    scene->addItem(ghost1);
    ghost1->setPos(20, 200);
    ghost1->connect(timer2, SIGNAL(timeout()), ghost1, SLOT(move()));

    ghost2 = new Ghost;
    scene->addItem(ghost2);
    ghost2->setPos(460, 100);
    ghost2->connect(timer2, SIGNAL(timeout()), ghost2, SLOT(move()));

    counter = 0;
    enemyHP = 300;
    playerHP = 100;
    score = 0;
    play = true;
    win = false;

    connect(timer2, SIGNAL(timeout()), this, SLOT(updateProgressbar()));
    ui->label_4->setText("Score : " + QString::number(score));
    ui->label_5->setText(" ");
    ui->progressBarEnemy->setValue(enemyHP);
    ui->progressBarPlayer->setValue(playerHP);
    ui->progressBarEnemy->setFormat("300/300");
    ui->progressBarPlayer->setFormat("100/100");
    ui->restartButton->setEnabled(false);
    ui->pauseButton->setEnabled(true);
}

void MainWindow::eHP(int i)
{
    if(enemyHP > 0)
    {
        enemyHP -= i;
        score += 12 + i;
        ui->label_4->setText("Score : " + QString::number(score));
        ui->progressBarEnemy->setValue(enemyHP);
        ui->progressBarEnemy->setFormat(QString::number(enemyHP) + "/300");
    }
    if(enemyHP <= 0)
    {
        ui->progressBarEnemy->setValue(0);
        ui->progressBarEnemy->setFormat("0/300");
        score += 500;
        ui->label_4->setText("Score : " + QString::number(score));
        win = true;
        finish();
    }
}

void MainWindow::pHP()
{
    if(playerHP > 0)
    {
        playerHP--;
        if(score < 3)
            score = 0;
        else
            score -= 3;
        ui->label_4->setText("Score : " + QString::number(score));
        ui->progressBarPlayer->setValue(playerHP);
        ui->progressBarPlayer->setFormat(QString::number(playerHP) + "/100");
    }
    else
    {
        if(score < 300)
            score = 0;
        else
            score -= 300;
        ui->label_4->setText("Score : " + QString::number(score));
        ui->progressBarPlayer->setValue(0);
        ui->progressBarPlayer->setFormat("0/100");
        win = false;
        finish();
    }
}

void MainWindow::updateProgressbar()
{
    if(counter < 100){
        counter++;
        ui->progressBar->setValue(counter);
    }
    else
        ui->progressBar->setValue(100);
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if(play){
        switch(e->key()) {
        case Qt::Key_W:
            if(player->y() > 0)
                player->setPos(player->x(), player->y() - 10);
            break;
        case Qt::Key_S:
            if(player->y() < 480)
                player->setPos(player->x(), player->y() + 10);
            break;
        case Qt::Key_A:
            if(player->x() > 0)
                player->setPos(player->x() - 10, player->y());
            break;
        case Qt::Key_D:
            if(player->x() < 520)
                player->setPos(player->x() + 10, player->y());
            break;

        case Qt::Key_C:
            if(counter == 100)
            {
                Bullet *sb1 = new Bullet;
                Bullet *sb2 = new Bullet;
                Bullet *sb3 = new Bullet;
                player->skill(sb1, sb2, sb3);
                sb1->connect(timer3, SIGNAL(timeout()), sb1, SLOT(explosion()));
                sb2->connect(timer3, SIGNAL(timeout()), sb2, SLOT(explosion()));
                sb3->connect(timer3, SIGNAL(timeout()), sb3, SLOT(explosion()));
                counter = 0;
                score += 300;
                ui->label_4->setText("Score : " + QString::number(score));
            }
            break;
        case Qt::Key_Space:
        {
            Bullet *b1 = new Bullet;
            Bullet *b2 = new Bullet;
            Bullet *b3 = new Bullet;
            Bullet *b4 = new Bullet;
            player->attack(b1, b2, b3, b4);
            b1->connect(timer1, SIGNAL(timeout()), b1, SLOT(fly()));
            b2->connect(timer1, SIGNAL(timeout()), b2, SLOT(fly1()));
            b3->connect(timer1, SIGNAL(timeout()), b3, SLOT(fly2()));
            b4->connect(timer1, SIGNAL(timeout()), b4, SLOT(fly3()));
            break;
        }
        }
    }
}

void MainWindow::finish()
{
    play = false;

    timer1->stop();
    timer2->stop();
    timer3->stop();
    enemy->timer->stop();

    if(win)
    {
        scene->removeItem(enemy);
        delete enemy;
        scene->removeItem(ghost1);
        delete ghost1;
        scene->removeItem(ghost2);
        delete ghost2;
        ui->label_5->setText("You Win !");
    }
    else
    {
        scene->removeItem(player);
        delete player;
        ui->label_5->setText("You Lose !");
    }
    ui->pauseButton->setEnabled(false);
    ui->restartButton->setEnabled(true);

}

void MainWindow::on_restartButton_clicked()
{
    scene->clear();
    game();
    play = true;
}

void MainWindow::on_pauseButton_clicked()
{
    if(play)
    {
        timer1->stop();
        timer2->stop();
        timer3->stop();
        enemy->timer->stop();
        play = false;
    }
    else
    {
        timer1->start(10);
        timer2->start(60);
        timer3->start(400);
        enemy->timer->start(10);
        play = true;
    }

}
