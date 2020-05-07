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
    bool isMine(unsigned short int, unsigned short int);
    QString getColorNumber(unsigned short int, unsigned short int);
    void generateNew();

private:
    MyCell allBoard[14][10];                //y=14 x=10
    unsigned short int numberOfMin(unsigned short int, unsigned short int);       //number of the nearest min
};

#endif // MYBOARD_H
