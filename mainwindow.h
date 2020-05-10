#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <qmyclickbutton.h>
#include "myboard.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void showBoard();
    void createBoard();

private:
    Ui::MainWindow *ui;
    QMyClickButton * myButton[14][10];
    MyBoard saperBoard;
    bool endGame; // if is true - end and block board,
    unsigned short int getNumButtonX(unsigned short int numberObjectButton);
    unsigned short int getNumButtonY(unsigned short int numberObjectButton);

private slots:
    void myButtonClick();
    void myButtonClickRight();
    void newGameClick();
    void infoClick();
};
#endif // MAINWINDOW_H
