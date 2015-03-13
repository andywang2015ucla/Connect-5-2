#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QWidget>
#include "mainwindow.h"
#include <QMainWindow>
#include <QKeyEvent>
#include <QLabel>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <iostream>


class GameBoard : public QWidget
{
    Q_OBJECT

public slots:
    void reset();
    void play_next_level();
    /**
     * @brief free_play
     *        Will show the free mode chess board
     */
    void free_play(){show();}
    /**
     * @brief setAdvanced
     *        Will show the restricted mode chess board and tell him the correponding rules
     */
    void setAdvanced(){advanced = true; show();}
public:
    explicit GameBoard(QWidget *parent = 0);
    ~GameBoard();

    void setMainWindow(MainWindow* main_window);
    void updateMuncher(int px, int py, int nx, int ny);
    void keyPressEvent(QKeyEvent *event);
    void paintEvent(QPaintEvent *e);
    void pig_win_replay();
    void bird_win_replay(bool temp);


private:

   MainWindow* mw;

   QWidget *Board;
   int board_size;
   QLabel** labels;



   int pig_matrix[15*15];
   int bird_matrix[15*15];

   QPoint *muncher_position;
   bool pig_or_bird = true;

   bool advanced=false;

};

#endif // GAMEBOARD_H
