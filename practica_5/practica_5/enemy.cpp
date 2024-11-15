#include "enemy.h"
#include "qdebug.h"
#include <QRandomGenerator>
#include "qgraphicsscene.h"
#include <cmath>


Enemy::Enemy(QString name_, int x, int y, QGraphicsScene *scene_) : name(name_), scene(scene_)  {

    QString urlFirst = ":/Resources/ghost_";
    QString urlSecond = urlFirst + name;

    faceRigth = QPixmap(urlSecond + "_rigth.png");
    faceRigth1 = QPixmap(urlSecond + "_rigth1.png");
    faceLeft = QPixmap(urlSecond + "_left.png");
    faceLeft1 = QPixmap(urlSecond + "_left1.png");
    faceUp = QPixmap(urlSecond + "_up.png");
    faceUp1 = QPixmap(urlSecond + "_up1.png");
    faceDown = QPixmap(urlSecond + "_down.png");
    faceDown1 = QPixmap(urlSecond + "_down1.png");

    if (faceRigth.isNull() ||
        faceLeft.isNull() ||
        faceUp.isNull() ||
        faceDown.isNull() ||
        faceDown1.isNull() ||
        faceLeft1.isNull() ||
        faceRigth1.isNull() ||
        faceUp1.isNull()
        ){
        qDebug() << "No se cargaron los fantasmas " << name;
    }

    faceRigth = faceRigth.scaled(27, 27, Qt::KeepAspectRatio);
    faceRigth1 = faceRigth1.scaled(27, 27, Qt::KeepAspectRatio);
    faceLeft = faceLeft.scaled(27, 27, Qt::KeepAspectRatio);
    faceLeft1 = faceLeft1.scaled(27, 27, Qt::KeepAspectRatio);
    faceDown = faceDown.scaled(27, 27, Qt::KeepAspectRatio);
    faceDown1 = faceDown1.scaled(27, 27, Qt::KeepAspectRatio);
    faceUp = faceUp.scaled(27, 27, Qt::KeepAspectRatio);
    faceUp1 = faceUp1.scaled(27, 27, Qt::KeepAspectRatio);

    ghost = new QGraphicsPixmapItem(faceRigth);
    scene->addItem(ghost);
    ghost->setPos(x, y);

    speedEnemy = 3;
    directionEnemy = 1;
    colliderNumber = 7.8;
    isHunting = false; // saber si pac-man va a cazar a los

    isFaceDown = false;
    isFaceLeft = false;
    isFaceRigth = true;
    isFaceUp = false;
    stateSprite = false;
    haunted = false;
}


void Enemy::updateSpriteGhost(){

    if (haunted) return;

    if (isFaceRigth) changeFace(faceRigth, faceRigth1); // cara a la derecha
    else if (isFaceLeft) changeFace(faceLeft, faceLeft1);
    else if (isFaceDown) changeFace(faceDown, faceDown1);
    else if (isFaceUp) changeFace(faceUp, faceUp1);

}

void Enemy::changeFace(QPixmap face, QPixmap face1){
    if (haunted) return;

    if (!stateSprite){
        ghost->setPixmap(face1);
        stateSprite = true;
    }
    else{
        ghost->setPixmap(face);
        stateSprite = false;
    }
}

void Enemy::direction(Player* player){
    if (haunted) return;

    vector<short> validWays;
    float x_ghost = ghost->x();
    float y_ghost = ghost->y();
    float x_player = player->getPlayer()->x();
    float y_player = player->getPlayer()->y();
    short target;

    // Verificar los caminos abiertos
    if (checkIfCollider(x_ghost + colliderNumber, y_ghost)) validWays.push_back(1); // Derecha
    if (checkIfCollider(x_ghost - colliderNumber, y_ghost)) validWays.push_back(2); // Izquierda
    if (checkIfCollider(x_ghost, y_ghost - colliderNumber)) validWays.push_back(3); // Arriba
    if (checkIfCollider(x_ghost, y_ghost + colliderNumber)) validWays.push_back(4); // Abajo

    if (abs(x_ghost - x_player) > abs(y_player - y_ghost)){
        target = (x_player > x_ghost) ? 1 : 2;
    }
    else target = (y_player > x_ghost) ? 4 : 3;

    if (find(validWays.begin(), validWays.end(), target) != validWays.end()){
        directionEnemy = target;
    }
    else{

        short sizeVector = validWays.size();
        short directionTemporay = 0;

        if (sizeVector > 0){
            int randomWay = QRandomGenerator::global()->bounded(0, sizeVector);
            directionTemporay = validWays[randomWay];
        }else{
            directionEnemy = 1;
        }

        for (short value: validWays){

            if (directionTemporay == 1){
                if (value != 1 && value != 2) directionEnemy = value;
            }
            else if (directionTemporay == 2){
                if (value != 2 && value != 1) directionEnemy = value;
            }
            else if (directionTemporay == 3){
                if (value != 3 && value != 4) directionEnemy = value;
            }
            else if (directionTemporay == 4){
                if (value != 4 && value != 3) directionEnemy = value;
            }
        }
    }

    if (ghost->x() <= 0) ghost->setPos(556, 305);
    else if (ghost->x()> 556) ghost->setPos(0, 305);


    colliderWithPlayer(player);
}

bool Enemy::checkIfCollider(int x, int y){

    QRectF enemyRectR(x, y, 27, 27);

    QList<QGraphicsItem*> items = scene->items(enemyRectR);

    if (items.isEmpty()) return true;

    for (QGraphicsItem* item: items){
        if (item->data(0).toString() == "Wall"){
            return false;
        }
    }

    return true;
}


void Enemy::colliderWithPlayer(Player* player){ // verificar colisiones con el player
    if (haunted) return;

    if (ghost->collidesWithItem(player->getPlayer())){

        qDebug() << "fantasma colisiono con player";
    //ghost->setOpacity(0);



        haunted = true;

        if (!isHunting){ // gameOver

        }else{ // pierde el fantasma y el usuario aumeta su score
            player->updateScore(5);
        }
    }
}

void Enemy::moveEnemy(){
    if (haunted) return;

    isFaceDown = false;
    isFaceLeft = false;
    isFaceRigth = false;
    isFaceUp = false;

    switch (directionEnemy) {
    case 1:
        isFaceRigth = true;
        ghost->setPixmap(faceRigth);
        ghost->setPos(ghost->x() + speedEnemy, ghost->y());
        break;
    case 2:
        isFaceLeft = true;
        ghost->setPixmap(faceLeft);
        ghost->setPos(ghost->x() - speedEnemy, ghost->y());
        break;
    case 3:
        isFaceUp = true;
        ghost->setPixmap(faceUp);
        ghost->setPos(ghost->x(), ghost->y() - speedEnemy);
        break;
    case 4:
        isFaceDown = true;
        ghost->setPixmap(faceDown);
        ghost->setPos(ghost->x(), ghost->y() + speedEnemy);
        break;
    default:
        break;
    }
}

Enemy::~Enemy(){

}
