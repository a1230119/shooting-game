#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QTimer>
#include "player.h"
#include "enemy.h"
#include "ghost.h"
#include "bullet.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void eHP(int i);
    void pHP();

public slots:
    virtual void keyPressEvent(QKeyEvent *e);
    void updateProgressbar();

private slots:
    void on_restartButton_clicked();

    void on_pauseButton_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Player *player;
    Enemy *enemy, *ghost1, *ghost2;
    QTimer *timer1, *timer2, *timer3;
    void finish();
    void game();
    bool play, win;
    int score, counter, enemyHP , playerHP;
};

#endif // MAINWINDOW_H
