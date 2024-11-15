#ifndef ENEMY_H
#define ENEMY_H

#include "player.h"
#include <QGraphicsItem>
#include <iostream>

using namespace std;

class Enemy
{
public:
    Enemy(QString name_, int x_, int y_, QGraphicsScene* scene_);
    void updateSpriteGhost();
    void direction(Player* player);
    void moveEnemy();
    void colliderWithPlayer(Player* palyer);


    ~Enemy();

private:
    const QString name;

    QGraphicsPixmapItem* ghost;
    QGraphicsScene* scene;

    QPixmap faceRigth;
    QPixmap faceRigth1;
    QPixmap faceLeft;
    QPixmap faceLeft1;
    QPixmap faceDown;
    QPixmap faceDown1;
    QPixmap faceUp;
    QPixmap faceUp1;

    bool isFaceUp;
    bool isFaceRigth;
    bool isFaceLeft;
    bool isFaceDown;
    bool stateSprite;

    float speedEnemy;
    int directionEnemy;
    float colliderNumber;
    bool isHunting;
    bool haunted;

    short dyTenta;
    short dxTenta;

    void changeFace(QPixmap face, QPixmap face1);
    bool checkIfCollider(int x, int y);




};

#endif // ENEMY_H
