#include "readme.h"

/**
 * @brief readMe::readMe
 *        This is the window teaches you how to play the game
 * @param parent
 */
readMe::readMe(QWidget *parent) :
  QWidget(parent)
{
    temp1 = new QLabel("You are given a chess board.\n"
                       "Each side can play their piece on the board.\n"
                       "Whenever a side reaches five pieces in a row, a column or in a diagonal,\n"
                       "that side wins the game.\n\n"
                       "Free Mode: \n    Two sides are both trying to get a 5-connection.\n\n"
                       "Restricted Mode: \n     Pig always move first so that pig has advantages. However, to make it more equal, \n"
                       "    in restricted mode, "
                       "if pig get a 6-connection, Bird will win the game."
                       "\n    Good Luck Bird. Use this advantage wisely!");
    temp2 = new QVBoxLayout;
    temp2->addWidget(temp1);
    this->setLayout(temp2);

}

void readMe::setMainWindow(MainWindow* main_window) {
    mW = main_window;
}

readMe::~readMe(){


}
