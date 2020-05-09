#ifndef MYBOARD_H
#define MYBOARD_H
#include "mycell.h"
#include <QString>

class MyBoard
{
public:
    MyBoard();
    void clear();
    MyCell get(unsigned short int, unsigned short int);
    void setClick(unsigned short int, unsigned short int);
    void setFlag(unsigned short int y, unsigned short int x);
    void setMineBoom(unsigned short int y, unsigned short int x);
    void unSetFlag(unsigned short int y, unsigned short int x);
    bool isMine(unsigned short int, unsigned short int);
    QString getColorNumber(unsigned short int, unsigned short int);
    void generateNew();
    void clickAllMines();                                                   //if gameover - click (show) ann mines
    bool isWin();
    void clickNeigbors(unsigned short int y, unsigned short int x);

private:
    MyCell allBoard[14][10];                //y=14 x=10
    unsigned short int numberOfMin(unsigned short int, unsigned short int);       //number of the nearest min
};

#endif // MYBOARD_H
