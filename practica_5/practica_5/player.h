#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsItem>
#include <QKeyEvent>
#include <QGraphicsRectItem>


class Player
{

public:
    Player(QGraphicsScene* scene_);
    void keyPress(QKeyEvent *event);
     void continueMove();

private:
    QGraphicsRectItem *rectItem; // Puntero al rectángulo
    QGraphicsScene* scene;
    QTimer* moveTimer;

    unsigned short direction;


    void verifyCollisions();


};

#endif // PLAYER_H
