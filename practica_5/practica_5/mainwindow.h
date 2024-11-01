#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "player.h"
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void renderScene();
    QGraphicsScene* scene;
    Player* player;
    int IdtimerPlayer; // frecuencia de cambio en movimiento
    int idTimerSptritePlayer; //frecuencia de cambio sprite player

    QPixmap coins;
    QPixmap potentiator;

protected:
    void keyPressEvent(QKeyEvent * event) override;
    void timerEvent(QTimerEvent *event) override;


};
#endif // MAINWINDOW_H
