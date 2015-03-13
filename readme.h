#ifndef README_H
#define README_H
#include <QWidget>

#include "mainwindow.h"
#include <QMainWindow>
#include <QKeyEvent>
#include <QLabel>
#include <QMainWindow>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextBrowser>
#include <iostream>

class readMe: public QWidget
{
    Q_OBJECT

public:
    explicit readMe(QWidget *parent = 0);
    ~readMe();
    void setMainWindow(MainWindow* main_window);

private:
    QLabel* temp1;
    QVBoxLayout* temp2;
    MainWindow* mW;
};

#endif // README_H
