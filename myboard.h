#ifndef MYBOARD_H
#define MYBOARD_H
#include "mycell.h"

class MyBoard
{
public:
    MyBoard();
    void clear();
    MyCell get(unsigned short int, unsigned short int);
    void generateNew();


private:
    MyCell AllBoard[14][10];                //y=14 x=10

};

#endif // MYBOARD_H
