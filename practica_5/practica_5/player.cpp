#include "player.h"
#include "qgraphicsscene.h"


Player::Player(QGraphicsScene* scene_): scene(scene_) {

    rectItem = new QGraphicsRectItem(15, 15, 15, 15);
    rectItem->setBrush(Qt::blue);
    rectItem->setFlag(QGraphicsItem::ItemIsFocusable);

    scene->addItem(rectItem);
    rectItem->setFocus();

    direction = 0;
}


void Player::keyPress(QKeyEvent *event) {

    switch (event->key()) {
    case 87:
        rectItem->setY(rectItem->y() - 3);
        direction = 1;
        break;
    case 68:
        rectItem->setX(rectItem->x() + 3);
        direction = 2;
        break;
    case 65:
        rectItem->setX(rectItem->x() - 3);
        direction = 3;
        break;
    case 83:
        direction = 4;
        rectItem->setY(rectItem->y() + 3);
        break;
    }

     verifyCollisions();
}

void Player::continueMove(){

    if (direction == 1){
        rectItem->setY(rectItem->y() - 3);
    }
    else if (direction == 2){
        rectItem->setX(rectItem->x() + 3);
    }
    else if (direction == 3){
        rectItem->setX(rectItem->x() - 3);
    }
    else if (direction == 4){
       rectItem->setY(rectItem->y() + 3);
    }

    verifyCollisions();


}

void Player::verifyCollisions(){
    QList<QGraphicsItem*> collisions = rectItem->collidingItems();

    for (QGraphicsItem* item: collisions){
        if (item->data(0).toString() == "Wall"){
            direction = 0;
        }
    }
}
