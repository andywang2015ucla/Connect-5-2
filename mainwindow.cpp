#include "mainwindow.h"
#include "readme.h"
#include "gameboard.h"

/**
 * @brief MainWindow::MainWindow
 *        Initialize the main window which is the directory
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{

    Welcome = new QLabel("Welcome to Wu Zi Qi!!!! Or say Connect Five.");

    // PushButtons for next step
    Play = new QPushButton("Free Play");
    Play_Advanced_Level = new QPushButton("Restricted Play (Advanced)");
    About = new QPushButton("About");
    Quit = new QPushButton("Quit");

    selection = new QVBoxLayout;
    selection->addWidget(Play);
    selection->addWidget(Play_Advanced_Level);
    selection->addWidget(About);
    selection->addWidget(Quit);

    final_layout = new QVBoxLayout;
    final_layout->addWidget(Welcome);
    final_layout->addLayout(selection);

    central = new QWidget;
    central->setLayout(final_layout);
    this->setCentralWidget(central);

}

MainWindow::~MainWindow()
{

}
/**
 * @brief MainWindow::callAbout
 *        Pop up the instruction window.
 * @param read_me
 */
void MainWindow::callAbout(readMe* read_me){
    rm = read_me;
    QObject::connect(About, SIGNAL(clicked()), rm, SLOT(show()));

}
/**
 * @brief MainWindow::setGameBoard
 *        Let user choose which mode he wants to play
 * @param game_board
 */
void MainWindow::setGameBoard(GameBoard* game_board) {
    board = game_board;
    QObject::connect(Play, SIGNAL(clicked()), board, SLOT(free_play()));
    QObject::connect(Play_Advanced_Level, SIGNAL(clicked()), board, SLOT(setAdvanced()));
}



void MainWindow::closeEvent(QCloseEvent *e) {
    e->accept();
}



