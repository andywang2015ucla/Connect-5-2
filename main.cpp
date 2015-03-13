/**
 * @brief This is hw4 where I set up user interface for a chess game called Wu Zi Qi, or say connect 5.
 * @Author: Xiangyu Wang
 * @Date:   01/30/2015
 *
 */

#include "mainwindow.h"
#include "readme.h"
#include "gameboard.h"
#include <QWidget>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLabel>
#include <QGridLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);



    MainWindow* w = new MainWindow;
    GameBoard* b = new GameBoard;
    readMe* r = new readMe;

    w->setGameBoard(b);
    w->callAbout(r);
    b->setMainWindow(w);
    r->setMainWindow(w);

    w->show();

    QObject::connect(w->Quit, SIGNAL(clicked()), &a, SLOT(quit()));

    return a.exec();
}
