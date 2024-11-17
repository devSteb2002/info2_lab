#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsItem>
#include <QKeyEvent>
#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>

class Player
{

public:
    Player(QGraphicsScene* scene_);
    void keyPress(QKeyEvent *event);
    void continueMove();
    void updateSprite();

    void updateScore(int score = 0);
    QGraphicsPixmapItem* getPlayer() const;
    void resLife();
    void gameOver();
    bool getDead() const;
    void setDead(bool dead_);
    void setGameOver(bool over);
    bool getGameOver() const;
    void setPosition(float x, float y);
    void setHunted(bool hunted);
    bool getHunted() const;

    ~Player();
private:
    QGraphicsScene* scene;
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

    short lifes;
    QGraphicsPixmapItem* livesImg;

    bool dead;
    bool isGameOver;

    bool hunted;

    bool checkNexPosition(int x, int y);
};

#endif // PLAYER_H
