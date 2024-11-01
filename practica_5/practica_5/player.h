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
    void updateSprite();

private:
    QGraphicsScene* scene;
    QTimer* moveTimer;
    float velocity;

    unsigned short direction;

    //original
    QPixmap faceMedium;
    QPixmap faceLow;
    QPixmap faceTotal;

    //sentido del reloj
    //rotates -90°
    QPixmap faceMediunLees90;
    QPixmap faceLowLees90;

    //rotate +90°
    QPixmap faceMediumMore90;
    QPixmap faceLowMore90;

    //180°
    QPixmap faceMedium180;
    QPixmap faceLow180;


    QGraphicsPixmapItem* player;

    bool isFaceMedium;
    bool isFaceLow;
    bool isFaceTotal;

    //sizeErro
    int itemNextValue;

    //score
    int score;
    QGraphicsTextItem* scoreText;


    void verifyCollisions();
    bool checkNexPosition(int x, int y);

    void updateScore();


};

#endif // PLAYER_H
