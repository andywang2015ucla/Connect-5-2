/*
 *
 * This will be the window where the game will be played.
 */


#include "gameboard.h"

#include <QHBoxlayout>
#include <QVBoxLayout>
/** This is the constructor for gameboard. This will create a 15*15 chess board and
 *  initialize all the required members.
 * @brief GameBoard::GameBoard
 * @param parent
 */

GameBoard::GameBoard(QWidget *parent) :
    QWidget(parent),board_size(15)
{
    muncher_position = new QPoint(0,0);
    Board = new QWidget;
    labels = new QLabel*[board_size*board_size];
    QGridLayout *SquareGrid = new QGridLayout(Board);

    //pig_matrix = new int(15*15);
    //bird_matrix = new int(15*15);

    SquareGrid->setGeometry(QRect());
    SquareGrid->setSpacing(0);
    for(int i=0;i<board_size;i++) {
        for(int j=0;j<board_size;j++) {

            // Random values
            //values[i*board_size+j] = distribution(generator);

            // Create label and set properties.
            labels[i*board_size+j] = new QLabel;
            //labels[i*board_size+j]->setText(QString::number( values[i*board_size+j]));
            labels[i*board_size+j]->setMinimumSize(40,40);
            labels[i*board_size+j]->setMaximumSize(40,40);
            labels[i*board_size+j]->setStyleSheet("QLabel { background-color : #F0F8FF; color : Black; }");
            //labels[i*board_size+j]->setStyleSheet("QPushButton { background-color : green; color : Black; }");
            labels[i*board_size+j]->setFrameStyle(3);
            labels[i*board_size+j]->setAlignment(Qt::AlignCenter);

            //connect(labels[i*board_size+j],SIGNAL(clicked()),Board,SLOT(quit()));

            // Add label to the layout
            SquareGrid -> addWidget(labels[i*board_size+j] ,i,j);

        }
    }

    Board->setFixedSize(600,600);
    setFixedSize(650,650);
    QVBoxLayout *piece_together = new QVBoxLayout;

    //piece_together->addWidget(Top,0,Qt::AlignCenter);
    piece_together->addWidget(Board,0,Qt::AlignCenter);

    this->setLayout(piece_together);
    this->setStyleSheet("QLabel { background-color : red; color : green; }");


    this->setWindowTitle("Connect Five");
}
/**
 * @brief check will check whether there is a 5-connection on the given matrix.
 * @param matrix This is the matrix that will be checked
 * @return true if there is a 5-connection. otherwise return false
 */
bool check(int matrix[15*15])
{
    for(int i= 0;i<15;i++){
        for(int j=0;j<11;j++){
            if(matrix[i*15+j]==1 &&matrix[i*15+j+1]==1 &&matrix[i*15+j+2]==1 &&matrix[i*15+j+3]==1 &&matrix[i*15+j+4]==1 )
            return true;
        }
    }
    for(int i= 0;i<15;i++){
        for(int j=0;j<15;j++){
            if(matrix[i*15+j]==1 &&matrix[(i+1)*15+j]==1 &&matrix[(i+2)*15+j]==1 &&matrix[(i+3)*15+j]==1 &&matrix[(i+4)*15+j]==1 )
            return true;
        }
        for(int j=0;j<15;j++){
            if(matrix[i*15+j]==1 &&matrix[(i+1)*15+j+1]==1 &&matrix[(i+2)*15+j+2]==1 &&matrix[(i+3)*15+j+3]==1 &&matrix[(i+4)*15+j+4]==1 )
            return true;

        }
        for(int j=14;j>3;j--){
            if(matrix[i*15+j]==1 &&matrix[(i+1)*15+j-1]==1 &&matrix[(i+2)*15+j-2]==1 &&matrix[(i+3)*15+j-3]==1 &&matrix[(i+4)*15+j-4]==1 )
            return true;

        }
    }
    return false;

}
/**
 * @brief check_6 will check if there is 6-connection. This is for the advanced mode when pig
 *        does not allow to do a 6-connection
 * @param matrix This is the matrix that will be checked
 * @return true if there is a 6-connection
 */
bool check_6(int matrix[15*15])
{
    for(int i= 0;i<15;i++){
        for(int j=0;j<11;j++){
            if(matrix[i*15+j]==1 &&matrix[i*15+j+1]==1 &&matrix[i*15+j+2]==1 &&matrix[i*15+j+3]==1 &&matrix[i*15+j+4]==1 &&matrix[i*15+j+5]==1 )
            return true;
        }
    }
    for(int i= 0;i<15;i++){
        for(int j=0;j<15;j++){
            if(matrix[i*15+j]==1 &&matrix[(i+1)*15+j]==1 &&matrix[(i+2)*15+j]==1 &&matrix[(i+3)*15+j]==1 &&matrix[(i+4)*15+j]==1 &&matrix[(i+5)*15+j]==1)
            return true;
        }
        for(int j=0;j<15;j++){
            if(matrix[i*15+j]==1 &&matrix[(i+1)*15+j+1]==1 &&matrix[(i+2)*15+j+2]==1 &&matrix[(i+3)*15+j+3]==1 &&matrix[(i+4)*15+j+4]==1  &&matrix[(i+5)*15+j+5]==1)
            return true;

        }
        for(int j=14;j>3;j--){
            if(matrix[i*15+j]==1 &&matrix[(i+1)*15+j-1]==1 &&matrix[(i+2)*15+j-2]==1 &&matrix[(i+3)*15+j-3]==1 &&matrix[(i+4)*15+j-4]==1 &&matrix[(i+5)*15+j-5]==1)
            return true;

        }
    }
    return false;

}

/**
 * @brief GameBoard::keyPressEvent
 *         This will move the red square to indicate where to place the next piece.
 *         Pree Space to place a piece. Will also check the condition after each placement.
 * @param event: take the action on the keyboard
 */
void GameBoard::keyPressEvent(QKeyEvent *event){

    int x = muncher_position->rx();
    int y = muncher_position->ry();

    QString pic(":/new/prefix1/pig head.jpeg");
    QPixmap pig = QPixmap(pic);
    QString pic2(":/new/prefix1/bird.jpg");
    QPixmap bird = QPixmap(pic2);
    int m,n;



    switch (event->key()) {
    case Qt::Key_Left:
        if(muncher_position->rx() != 0){
            //labels[x*board_size+y]->setStyleSheet("QLabel { background-color : #F0F8FF; color : Black; }");
            updateMuncher(x,y,x-1,y);
        }
        break;
    case Qt::Key_Right:
        if(muncher_position->rx() != board_size-1){
            //labels[x*board_size+y]->setStyleSheet("QLabel { background-color : #F0F8FF; color : Black; }");
            updateMuncher(x,y,x+1,y);
        }
        break;
    case Qt::Key_Up:
        if(muncher_position->ry() != 0){
            //labels[x*board_size+y]->setStyleSheet("QLabel { background-color : #F0F8FF; color : Black; }");
            updateMuncher(x,y,x,y-1);
        }
        break;
    case Qt::Key_Down:
        if(muncher_position->ry() != board_size-1){
            //labels[x*board_size+y]->setStyleSheet("QLabel { background-color : #F0F8FF; color : Black; }");
            updateMuncher(x,y,x,y+1);
        }
        break;

    case Qt::Key_Space:
        //munchNumber(x,y);
        //labels[x*board_size+y]->setStyleSheet("QLabel { background-color : Green; color : Black; }");
        m = muncher_position->rx();
        n = muncher_position->ry();
        if(pig_or_bird && bird_matrix[n*board_size+m] != 1){
            //pig_matrix[n][m]=1;
            pig_matrix[n*board_size+m] = 1;
            labels[n*board_size+m]->setPixmap(pig);
            labels[n*board_size+m]->show();
            pig_or_bird = false;
            if(check_6(pig_matrix)  && advanced){
                 bird_win_replay(true);
            }
            else if(check(pig_matrix)){

                pig_win_replay();

            }

        }
        else if(!pig_or_bird && pig_matrix[n*board_size+m] != 1)
        {
            bird_matrix[n*board_size+m] = 1;
            labels[n*board_size+m]->setPixmap(bird);
            labels[n*board_size+m]->show();
            pig_or_bird = true;

            if(check(bird_matrix)){

                bird_win_replay(false);
            }
        }

        break;
    default:
        QWidget::keyPressEvent(event);

    }
    //QCoreApplication::processEvents();
    repaint();
    return;
}

/**
 * @brief GameBoard::updateMuncher
 *        Will update the place of point and indicate where it is right now using red square
 * @param px: previous x
 * @param py: previous x
 * @param nx: new x
 * @param ny: new y
 */
void GameBoard::updateMuncher(int px, int py, int nx, int ny) {

    labels[py*board_size+px]->setStyleSheet("QLabel { background-color : #F0F8FF; color : Black; }");

    //if(values[py*board_size+px])
     //   labels[py*board_size+px]->setText(QString::number( values[py*board_size+px]));

    muncher_position->setX(nx);
    muncher_position->setY(ny);

//    return (px==nx)&&(py==ny);
}

/**
 * @brief GameBoard::paintEvent
 *        Indicate the current position is red.
 * @param e
 */
void GameBoard::paintEvent(QPaintEvent *e) {

    int x = muncher_position->rx();
    int y = muncher_position->ry();

    labels[y*board_size+x]->setStyleSheet("QLabel { background-color : red; color : Black; }");
    labels[y*board_size+x]->setScaledContents(true);

}

GameBoard::~GameBoard() {

   }

void GameBoard::setMainWindow(MainWindow* main_window) {
    mw = main_window;

}
/**
 * @brief GameBoard::pig_win_replay
 *        When one side wins. Pop up a window and let user choose the next step
 */
void GameBoard::pig_win_replay()
{

    QWidget* replay_window=new QWidget;
    QLabel* replay_label=new QLabel("Pig Wins the Game!!!!");
    QPushButton* replay_button1=new QPushButton("Wanna Play Again");
    QPushButton* play_next=new QPushButton("Play Restricted Mode");
    QPushButton* replay_button2=new QPushButton("Quit");

    QHBoxLayout* layout1=new QHBoxLayout;
    QVBoxLayout* layout2=new QVBoxLayout;

    layout1->addWidget(replay_button1);
    layout1->addWidget(play_next);
    layout1->addWidget(replay_button2);
    layout2->addWidget(replay_label);
    layout2->addLayout(layout1);
    replay_window->setLayout(layout2);
    replay_window->show();

    QObject::connect(replay_button1,SIGNAL(clicked()),this,SLOT(close()));
    QObject::connect(replay_button2,SIGNAL(clicked()),this,SLOT(close()));
    QObject::connect(replay_button1,SIGNAL(clicked()),replay_window,SLOT(close()));
    QObject::connect(replay_button2,SIGNAL(clicked()),replay_window,SLOT(close()));

    QObject::connect(play_next,SIGNAL(clicked()),this,SLOT(close()));
    QObject::connect(play_next,SIGNAL(clicked()),replay_window,SLOT(close()));
    QObject::connect(play_next,SIGNAL(clicked()),this,SLOT(play_next_level()));

    QObject::connect(replay_button1,SIGNAL(clicked()),this,SLOT(reset()));

}
/**
 * @brief GameBoard::pig_win_replay
 *        When one side wins. Pop up a window and let user choose the next step
 */
void GameBoard::bird_win_replay(bool temp)
{

    QWidget* replay_window=new QWidget;
    QLabel* replay_label1=new QLabel("Bird Wins the Game!!!!");
    QLabel* replay_label2=new QLabel("Pig get a 6-connection! Too Bad! Bird Wins the Game!!!!");
    QPushButton* replay_button1=new QPushButton("Wanna Play Again");
    QPushButton* replay_button2=new QPushButton("Quit");
    QPushButton* play_next=new QPushButton("Play Restricted Mode");
    QHBoxLayout* layout1=new QHBoxLayout;
    QVBoxLayout* layout2=new QVBoxLayout;

    layout1->addWidget(replay_button1);
    layout1->addWidget(play_next);
    layout1->addWidget(replay_button2);
    if(!temp){
        layout2->addWidget(replay_label1);
    }
    else{
        layout2->addWidget(replay_label2);

    }

    layout2->addLayout(layout1);
    replay_window->setLayout(layout2);
    replay_window->show();

    QObject::connect(play_next,SIGNAL(clicked()),this,SLOT(close()));
    QObject::connect(play_next,SIGNAL(clicked()),replay_window,SLOT(close()));
    QObject::connect(play_next,SIGNAL(clicked()),this,SLOT(play_next_level()));


    QObject::connect(replay_button1,SIGNAL(clicked()),this,SLOT(close()));
    QObject::connect(replay_button2,SIGNAL(clicked()),this,SLOT(close()));
    QObject::connect(replay_button1,SIGNAL(clicked()),replay_window,SLOT(close()));
    QObject::connect(replay_button2,SIGNAL(clicked()),replay_window,SLOT(close()));
    QObject::connect(replay_button1,SIGNAL(clicked()),this,SLOT(reset()));

}
/**
 * @brief GameBoard::reset
 *        If the player want to play again. Reset the chessboard
 */
void GameBoard::reset(){
    for(int i=0;i<board_size;i++) {
        for(int j=0;j<board_size;j++) {

            bird_matrix[i*board_size+j] =0;
            pig_matrix[i*board_size+j]=0;
        }
    }


    GameBoard* g=new GameBoard;
    g->setMainWindow(this->mw);
    MainWindow* temp=new MainWindow; temp->setGameBoard(this);

    this->mw->setGameBoard(g);
    g->show();

    delete temp;

}
/**
 * @brief GameBoard::play_next_level
 *        This will be called when the player want to play next level which is the restricted mode.
 */
void GameBoard::play_next_level(){
    for(int i=0;i<board_size;i++) {
        for(int j=0;j<board_size;j++) {

            bird_matrix[i*board_size+j] =0;
            pig_matrix[i*board_size+j]=0;
        }
    }


    GameBoard* g=new GameBoard;
    g->setAdvanced();
    g->setMainWindow(this->mw);
    MainWindow* temp=new MainWindow; temp->setGameBoard(this);

    this->mw->setGameBoard(g);
    g->show();

    delete temp;



}


