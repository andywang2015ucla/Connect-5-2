#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QLabel>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QRadioButton>

class GameBoard;
class readMe;

class MainWindow : public QMainWindow
{
    Q_OBJECT

 public slots:

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

    void setGameBoard(GameBoard* game_board);
    void callAbout(readMe* read_me);
    void closeEvent(QCloseEvent *e);

    QPushButton* Quit;
private:

    GameBoard* board;
    readMe* rm;
    QLabel* Welcome;
    QPushButton* Play;
    QPushButton* Play_Advanced_Level;
    QPushButton* About;


    QVBoxLayout* selection;
    QVBoxLayout* final_layout;
    QWidget* central;

};

#endif // MAINWINDOW_H
