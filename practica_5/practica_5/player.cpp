#include "player.h"
#include "qgraphicsscene.h"


Player::Player(QGraphicsScene* scene_): scene(scene_) {

    //cargar sprites del personaje

    // 0°
    faceLow = QPixmap(":/Resources/pacman_face_low.png");
    faceMedium = QPixmap(":Resources/pacman_face_medium.png");
    faceTotal = QPixmap(":/Resources/pacman_face_total.png");

    //-90°
    faceLowLees90 = QPixmap(":/Resources/pacman_face_low_-90.png");
    faceMediunLees90 = QPixmap(":Resources/pacman_face_medium_-90.png");

    //90°
    faceLowMore90 = QPixmap(":/Resources/pacman_face_low_+90.png");
    faceMediumMore90 = QPixmap(":/Resources/pacman_face_medium_+90.png");

    //180°
    faceLow180 = QPixmap(":/Resources/pacman_face_low_180.png");
    faceMedium180 = QPixmap(":/Resources/pacman_face_medium_180.png");


    if (faceLow.isNull() ||
        faceMedium.isNull() ||
        faceTotal.isNull() ||
        faceLowLees90.isNull() ||
        faceMediunLees90.isNull() ||
        faceLowMore90.isNull() ||
        faceMediumMore90.isNull() ||
        faceLow180.isNull() ||
        faceMedium180.isNull()
        ){
        qDebug() << "No se pudo cargar pac man";
    }


    faceMedium = faceMedium.scaled(22, 22, Qt::KeepAspectRatio);
    faceLow = faceLow.scaled(22, 22, Qt::KeepAspectRatio);
    faceTotal = faceTotal.scaled(22, 22, Qt::KeepAspectRatio);
    faceLowLees90 = faceLowLees90.scaled(22, 22, Qt::KeepAspectRatio);
    faceMediunLees90 = faceMediunLees90.scaled(22, 22, Qt::KeepAspectRatio);
    faceLowMore90 = faceLowMore90.scaled(22, 22, Qt::KeepAspectRatio);
    faceMediumMore90 = faceMediumMore90.scaled(22, 22, Qt::KeepAspectRatio);
    faceLow180 = faceLow180.scaled(22, 22, Qt::KeepAspectRatio);
    faceMedium180 = faceMedium180.scaled(22, 22, Qt::KeepAspectRatio);

    isFaceLow = true, isFaceTotal = false, isFaceMedium = false;

    player = new QGraphicsPixmapItem(faceLow);
    player->setPos(15, 55);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    scene->addItem(player);
    player->setFocus();

    scoreText = new QGraphicsTextItem();
    scoreText->setDefaultTextColor(Qt::white);
    scoreText->setFont(QFont("Arial", 12));
    scoreText->setPlainText(QString("Score: %1").arg(0));

    scene->addItem(scoreText);

    direction = 0;
    velocity = 3;
    itemNextValue = 7;
    score = 0;
    lifes = 3;
}

void Player::updateSprite(){
    if (isFaceLow){
        if (direction == 4) player->setPixmap(faceMediunLees90);
        else if (direction == 3) player->setPixmap(faceMedium180);
        else if (direction == 2) player->setPixmap(faceMedium);
        else if (direction == 1) player->setPixmap(faceMediumMore90);

        isFaceLow = false;
        isFaceMedium = true;
    }
    else if (isFaceMedium){
        player->setPixmap(faceTotal);

        isFaceMedium = false;
        isFaceTotal = true;
    }
    else if (isFaceTotal){
        if (direction == 4) player->setPixmap(faceLowLees90);
        else if (direction == 3) player->setPixmap(faceLow180);
        else if (direction == 2) player->setPixmap(faceLow);
        else if (direction == 1) player->setPixmap(faceLowMore90);

        isFaceTotal = false;
        isFaceLow = true;
    }
}


void Player::keyPress(QKeyEvent *event) {

    switch (event->key()) {
    case 87:

        if (!checkNexPosition(player->x(), player->y() - itemNextValue)) return;
        direction = 1; // w
        break;
    case 68:

        if (!checkNexPosition(player->x() + itemNextValue, player->y())) return;
        direction = 2; //d
        break;
    case 65:

        if (!checkNexPosition(player->x() - itemNextValue, player->y())) return;
        direction = 3; // a
        break;
    case 83:

        if (!checkNexPosition(player->x(), player->y() + itemNextValue)) return;
        direction = 4; // s

        break;
    }
}

bool Player::checkNexPosition(int x, int y){

    QRectF playerRect(x, y, player->boundingRect().width(), player->boundingRect().height());

    QList<QGraphicsItem*> items = scene->items(playerRect);

    if (items.isEmpty()) return true;

    for (QGraphicsItem* item : items){
        if (item->data(0).toString() == "Wall"){
            return false;
        }
        else if (item->data(0).toString() == "coins"){
            score += 1;
            scene->removeItem(item);
            updateScore();
        }
        else if (item->data(0).toString() == "potentiator"){
            score += 5;
            scene->removeItem(item);
            updateScore();
        }
    }

    return true;
}

void Player::continueMove(){

    switch (direction) {
    case 1:

        if (!checkNexPosition(player->x(), player->y() - itemNextValue)) return;
        player->setPos(player->x(), player->y() - velocity); // w

        break;
    case 2:

        if (!checkNexPosition(player->x() + itemNextValue, player->y())) return;
        player->setPos(player->x() + velocity, player->y()); //d

        break;
    case 3:

        if (!checkNexPosition(player->x() - itemNextValue, player->y())) return;
        player->setPos(player->x() - velocity, player->y()); // a

        break;
    case 4:

        if (!checkNexPosition(player->x(), player->y() + itemNextValue)) return;
        player->setPos(player->x(), player->y() + velocity); // s

        break;
    }

    //verificar cuando sale de la pantalla
    if (player->x() <= 0)player->setPos(556, player->y());
    else if (player->x() > 556) player->setPos(0, player->y());
}

void Player::updateScore(int score_){
    if (score_ == 0) scoreText->setPlainText(QString("Score: %1").arg(score)); //monedas que atrapa el jugador
    else {  // cuando se come un fantasma
        score = score + score_;
        scoreText->setPlainText(QString("Score: %1").arg(score));
    }
}

QGraphicsPixmapItem* Player::getPlayer() const{
    return player;
}

void Player::gameOver(){
    if (lifes > 0){

    }

    lifes--;
}


Player::~Player(){
 delete scoreText;
}
