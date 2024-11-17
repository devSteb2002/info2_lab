#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("Pac man");

    QColor backgroundColor(0, 0, 0);

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 556, 660);
    scene->setBackgroundBrush(QBrush(backgroundColor));

    //monedas
    coins = QPixmap(":/Resources/potent.png").scaled(5,5, Qt::KeepAspectRatio);
    potentiator = QPixmap(":/Resources/potentiator.png").scaled(21, 21, Qt::KeepAspectRatio);

    renderScene();

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setFrameShape(QFrame::NoFrame);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setFocusPolicy(Qt::StrongFocus);
    ui->graphicsView->setFixedSize(556, 660);


    player = new Player(scene);
    ui->graphicsView->setFocus();

    IdtimerPlayer = startTimer(30);
    idTimerSptritePlayer = startTimer(80);
    idTimerGhost = startTimer(150);
    idTimerMoveGhots = startTimer(35);
    idTimerGhostCheckPosition = startTimer(16);

    //crear enemigos
    enemies.emplace_back("blue", 183, 249, scene);
    enemies.emplace_back("red", 450,  55, scene);
    enemies.emplace_back("yellow", 40, 540, scene);
    enemies.emplace_back("pink",450, 540, scene);

    textInit = new QGraphicsTextItem();
    textInit->setDefaultTextColor(Qt::white);
    textInit->setFont(QFont("Arial", 30));
    textInit->setPos(180, 290);
    textInit->setZValue(10);
    scene->addItem(textInit);

    initGame();

}

void MainWindow::keyPressEvent(QKeyEvent * event) {
    player->keyPress(event);

    if (!isInit) {
        textInit->setPlainText(QString(""));
        isInit = true;
        for (auto& enemy : enemies) enemy.restartPosition();
        player->setGameOver(false);
        player->setPosition(15, 55);
        initGame();
    }
}

void MainWindow::timerEvent(QTimerEvent *event){
    if (isInit){ // iniciar cuando se pise una tecla

        if (event->timerId() == IdtimerPlayer) {
            player->continueMove();
            for (auto& enemy : enemies) enemy.colliderWithPlayer(player);
            if (player->getGameOver()) {
                isInit = false;
                messageGameOver();
                renderScene();
            }
        }
        else if (event->timerId() == idTimerSptritePlayer) {
            player->updateSprite();
        }
        else if (event->timerId() == idTimerGhost){
            for (auto& enemy : enemies) enemy.updateSpriteGhost();
        }
        else if (event->timerId() == idTimerMoveGhots){
            for (auto& enemy : enemies) enemy.moveEnemy();
        }
        else if (event->timerId() == idTimerGhostCheckPosition){
            for (auto& enemy : enemies) enemy.direction(player);
        }
    }
}

void MainWindow::renderScene(){

    QPen pen(Qt::NoPen);

    const int HEIGTHMAP = 40;
    const int WIDHTMAP = 37;
    const int SIZETILE = 15;

    short map[HEIGTHMAP][WIDHTMAP] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1},
        {1, 0, 2, 1, 1, 1, 1, 1, 0, 2, 1, 1, 1, 1, 1, 1, 0, 2, 1, 1, 0, 2, 1, 1, 1, 1, 1, 0, 2, 1, 1, 1, 1, 1, 0, 2, 1},
        {1, 0, 2, 1, 1, 1, 1, 1, 0, 2, 1, 1, 1, 1, 1, 1, 0, 2, 1, 1, 0, 2, 1, 1, 1, 1, 1, 0, 2, 1, 1, 1, 1, 1, 0, 2, 1},
        {1, 0, 2, 1, 1, 1, 1, 1, 0, 2, 1, 1, 1, 1, 1, 1, 0, 2, 1, 1, 0, 2, 1, 1, 1, 1, 1, 0, 2, 1, 1, 1, 1, 1, 0, 2, 1},
        {1, 0, 2, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 2, 1},
        {1, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1},
        {1, 0, 2, 1, 1, 1, 1, 1, 0, 2, 1, 1, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 2, 1, 1, 0, 2, 1, 1, 1, 1 ,1 ,0 ,2, 1},
        {1, 0, 2, 1, 1, 1, 1, 1, 0, 2, 1, 1, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 2, 1, 1, 0, 2, 1, 1, 1, 1 ,1 ,0 ,2, 1},
        {1, 0, 2, 0, 0, 0, 0, 0, 0, 2, 1, 1, 0, 2, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 2, 1, 1, 0, 2, 0, 0, 0, 0, 0, 0, 2, 1},
        {1, 0, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 0, 2, 2, 2, 2, 2, 1, 1, 0, 2, 2, 2, 2, 1, 1, 0, 2, 2, 2, 2, 2, 2, 2, 2, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 0, 2, 1, 1, 1, 1, 1, 1, 0, 2, 1, 1, 0, 2, 1, 1, 1, 1, 1, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 0, 2, 1, 1, 1, 1, 1, 1, 0, 2, 1, 1, 0, 2, 1, 1, 1, 1, 1, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 0, 2, 1, 1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 1, 1, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 0, 2, 1, 1, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 0, 2, 1, 1, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 2, 1, 1, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 0, 2, 1, 1, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 2, 1, 1, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0},
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
        {1, 1, 1, 1, 1, 1, 1, 1, 0, 2, 1, 1, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 2, 1, 1, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 0, 2, 1, 1, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 2, 1, 1, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 0, 2, 1, 1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 0, 2, 1, 1, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 0, 2, 1, 1, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 2, 1, 1, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1},
        {1, 0, 2, 1, 1, 1, 1, 1, 0, 2, 1, 1, 1, 1, 1, 0, 2, 1, 1, 1, 0, 2, 1, 1, 1, 1, 1, 0, 2, 1, 1, 1, 1, 1, 0, 2, 1},
        {1, 0, 2, 1, 1, 1, 1, 1, 0, 2, 1, 1, 1, 1, 1, 0, 2, 1, 1, 1, 0, 2, 1, 1, 1, 1, 1, 0, 2, 1, 1, 1, 1, 1, 0, 2, 1},
        {1, 0, 2, 0, 0, 0, 1, 1, 0, 2, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 2, 1, 1, 0, 0 ,0 ,0 ,2, 1},
        {1, 0, 2, 2, 2, 2, 1, 1, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 0, 2 ,2 ,2 ,2, 1},
        {1, 1, 1, 1, 0, 2, 1, 1, 0, 2, 1, 1, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 2, 1, 1, 0, 2, 1, 1, 0, 2 ,1 ,1 ,1, 1},
        {1, 1, 1, 1, 0, 2, 1, 1, 0, 2, 1, 1, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 2, 1, 1, 0, 2, 1, 1, 0, 2, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 2, 0, 0, 0, 2, 1, 1, 0, 2, 0, 0, 0, 0, 1, 1, 0, 0 ,0 ,0 ,2 ,1, 1, 0, 2, 0, 0, 0, 2, 0, 0, 0, 1},
        {1, 0, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 0, 2, 2, 2, 2, 2, 1, 1, 0, 2 ,2 ,2 ,2 ,1, 1, 0, 2, 2, 2, 2, 2, 2, 2, 2, 1},
        {1, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 2, 1, 1, 0, 2 ,1 ,1 ,1 ,1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 2, 1},
        {1, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 2, 1, 1, 0, 2 ,1 ,1 ,1 ,1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 2, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
        {1, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    };


    for (int row = 0; row < HEIGTHMAP; row++){
        for (int col = 0; col < WIDHTMAP; col++){
            if (map[row][col] == 1){ // muros invisibles
                QGraphicsRectItem *tile = new QGraphicsRectItem(col * SIZETILE, (row * SIZETILE) + 39, SIZETILE, SIZETILE);
                tile->setBrush(Qt::blue);
                tile->setData(0, "Wall");
                tile->setPen(pen);
                scene->addItem(tile);
            }
            else if (map[row][col] == 2){ // monedas

                QGraphicsRectItem *tile = new QGraphicsRectItem(col * SIZETILE, (row * 15) + 39, 30, 30);
                // tile->setBrush(Qt::white);;
                tile->setData(0, "other");
                tile->setPen(pen);
                scene->addItem(tile);

                QGraphicsPixmapItem* pix = new QGraphicsPixmapItem(coins);
                pix->setPos(col * SIZETILE, (row * SIZETILE) + 39);
                pix->setData(0, "coins");
                scene->addItem(pix);
            }
            else if (map[row][col] == 3){
                QGraphicsPixmapItem* pix = new QGraphicsPixmapItem(potentiator);
                pix->setPos(col * SIZETILE, (row * SIZETILE) + 39);
                pix->setData(0, "potentiator");
                pix->setZValue(4);
                scene->addItem(pix);
            }
        }
    }
}

void MainWindow::initGame(){

    // if (!isInit){
    //    textInit->setPlainText(QString("Inicar juego"));
    // }else{
    //     // if (textInit && scene->items().contains(textInit)){
    //     //     scene->removeItem(textInit);
    //     // }
    //         textInit->setPlainText(QString(""));
    // }
}

void MainWindow::messageGameOver(){
    if (textInit){
        textInit->setPlainText(QString("GAME OVER"));
    }
}


MainWindow::~MainWindow()
{
    delete ui;
    delete player;
    delete scene;
    delete textInit;
    killTimer(IdtimerPlayer);
    killTimer(idTimerSptritePlayer);
    killTimer(idTimerGhostCheckPosition);
    killTimer(idTimerGhost);
}
