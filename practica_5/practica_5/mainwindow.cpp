#include "mainwindow.h"
#include "player.h"
#include "ui_mainwindow.h"
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QColor backgroundColor(0, 0, 0);

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 556, 660);
    scene->setBackgroundBrush(QBrush(backgroundColor));

    QPixmap spriteBK = QPixmap(":/Resources/pacman.png");
    QGraphicsPixmapItem* bK = new QGraphicsPixmapItem(spriteBK);

    //monedas
    coins = QPixmap(":/Resources/potent.png").scaled(5,5, Qt::KeepAspectRatio);
    potentiator = QPixmap(":/Resources/potentiator.png").scaled(20, 20, Qt::KeepAspectRatio);

    if (spriteBK.isNull())
        qDebug() << "No se cargo";

    bK->setZValue(-1);
    bK->setPos(0,38);
    scene->addItem(bK);

    renderScene();

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setFrameShape(QFrame::NoFrame);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setFocusPolicy(Qt::StrongFocus);
    ui->graphicsView->setFixedSize(556, 660);


    this->setWindowTitle("Pac man");

    player = new Player(scene);
    ui->graphicsView->setFocus();

    IdtimerPlayer = startTimer(30);
    idTimerSptritePlayer = startTimer(80);

}

void MainWindow::keyPressEvent(QKeyEvent * event) {
    player->keyPress(event);
}

void MainWindow::timerEvent(QTimerEvent *event){

    if (event->timerId() == IdtimerPlayer) player->continueMove();
    else if (event->timerId() == idTimerSptritePlayer) player->updateSprite();
}

void MainWindow::renderScene(){

    QPen pen(Qt::red);
    pen.setWidth(2);

    const int HEIGTHMAP = 40;
    const int WIDHTMAP = 37;
    const int SIZETILE = 15;

    int map[HEIGTHMAP][WIDHTMAP] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 1, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1},
        {1, 0, 2, 1, 1, 1, 1, 1, 0, 2, 1, 1, 1, 1, 1, 0, 2, 0, 1, 0, 2, 0, 1, 1, 1, 1, 1, 0, 2, 1, 1, 1, 1, 1, 0, 2, 1},
        {1, 0, 2, 1, 1, 1, 1, 1, 0, 2, 1, 1, 1, 1, 1, 0, 3, 0, 1, 0, 2, 0, 1, 1, 1, 1, 1, 0, 2, 1, 1, 1, 1, 1, 0, 2, 1},
        {1, 0, 2, 1, 1, 1, 1, 1, 0, 2, 1, 1, 1, 1, 1, 0, 2, 0, 1, 0, 2, 0, 1, 1, 1, 1, 1, 0, 2, 1, 1, 1, 1, 1, 0, 2, 1},
        {1, 0, 2, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 2, 1},
        {1, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1},
        {1, 0, 2, 1, 1, 1, 1, 1, 0, 2, 1, 0, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 2, 2, 1, 0, 2, 1, 1, 1, 1 ,1 ,0 ,2, 1},
        {1, 0, 2, 1, 1, 1, 1, 1, 0, 2, 1, 0, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 2, 2, 1, 0, 2, 1, 1, 1, 1 ,1 ,0 ,2, 1},
        {1, 0, 2, 0, 0, 0, 0, 0, 0, 2, 1, 0, 2, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 2, 2, 1, 0, 2, 0, 0, 0, 0, 0, 0, 2, 1},
        {1, 0, 2, 2, 2, 2, 2, 2, 2, 2, 1, 0, 2, 2, 2, 2, 2, 2, 1, 0, 2, 2, 2, 2, 2, 2, 1, 0, 2, 2, 2, 2, 2, 2, 2, 2, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 0, 2, 1, 1, 1, 1, 1, 0, 2, 2, 1, 0, 2, 2, 1, 1, 1, 1, 1, 0, 2, 0, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 0, 2, 1, 1, 1, 1, 1, 0, 2, 2, 1, 0, 2, 2, 1, 1, 1, 1, 1, 0, 2, 0, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 0, 2, 1, 0, 0, 0, 0, 0, 2, 2, 0, 0, 2, 2, 0, 0, 0, 0, 1, 0, 2, 0, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 0, 2, 1, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 0, 2, 0, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 0, 2, 1, 0, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 2, 2, 1, 0, 2, 0, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 2, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0},
        {2, 2, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
        {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
        {1, 1, 1, 1, 1, 1, 1, 1, 0, 2, 1, 0, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 2, 2, 1, 0, 2, 0, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 0, 2, 1, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 1, 0, 2, 0, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 0, 2, 1, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 0, 2, 0, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 0, 2, 1, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 0, 2, 0, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 0, 2, 1, 0, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 2, 2, 1, 0, 2, 0, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 2, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1},
        {1, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1},
        {1, 0, 2, 0, 1, 1, 1, 1, 0, 2, 1, 1, 1, 1, 1, 0, 2, 2, 1, 0, 2, 2, 1, 1, 1, 1, 1, 0, 2, 1, 1, 1, 1, 0, 2, 2, 1},
        {1, 0, 3, 0, 0, 0, 1, 1, 0, 2, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 2, 0, 1, 0, 0 ,0 ,2 ,2, 1},
        {1, 0, 2, 2, 2, 2, 1, 1, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 1, 0, 2 ,2 ,2 ,2, 1},
        {1, 0, 0, 0, 0, 2, 1, 1, 0, 2, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 2, 0, 1, 0, 2 ,0 ,0 ,0, 1},
        {1, 1, 1, 1, 0, 2, 1, 0, 0, 2, 1, 0, 2, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 2, 0, 1, 0, 2, 0, 1, 0, 2, 0, 1, 1, 1},
        {1, 0, 0, 0, 0, 2, 0, 0, 0, 2, 1, 0, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0 ,0 ,0 ,2 ,0, 1, 0, 2, 0, 0, 0, 2, 0, 0, 0, 1},
        {1, 0, 2, 2, 2, 2, 2, 2, 2, 2, 1, 0, 2, 2, 2, 2, 2, 0, 1, 0, 2, 2 ,2 ,2 ,2 ,0, 1, 0, 2, 2, 2, 2, 2, 2, 2, 2, 1},
        {1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 2, 0, 1, 0, 2, 0 ,0 ,0 ,0 ,0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1},
        {1, 0, 2, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 2, 0, 1, 0, 2, 0 ,1 ,1 ,1 ,1, 1, 1, 1, 1, 1, 1, 1, 0, 3, 0, 1},
        {1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    };


    for (int row = 0; row < HEIGTHMAP; row++){
        for (int col = 0; col < WIDHTMAP; col++){
            if (map[row][col] == 1){ // muros invisibles
                QGraphicsRectItem *tile = new QGraphicsRectItem(col * SIZETILE, (row * SIZETILE) + 39, SIZETILE, SIZETILE);
                tile->setBrush(Qt::transparent);
                tile->setPen(pen);
                tile->setData(0, "Wall");
                scene->addItem(tile);
            }
            else if (map[row][col] == 2){ // monedas
                QGraphicsPixmapItem* pix = new QGraphicsPixmapItem(coins);
                pix->setPos(col * SIZETILE, (row * SIZETILE) + 39);
                pix->setData(0, "coins");
                scene->addItem(pix);
            }
            else if (map[row][col] == 3){
                QGraphicsPixmapItem* pix = new QGraphicsPixmapItem(potentiator);
                pix->setPos(col * SIZETILE, (row * SIZETILE) + 39);
                pix->setData(0, "potentiator");
                pix->setZValue(1);
                scene->addItem(pix);
            }
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    killTimer(IdtimerPlayer);
    killTimer(idTimerSptritePlayer);
}
