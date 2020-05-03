#include "myboard.h"

MyBoard::MyBoard()
{
    clear();
}

void MyBoard::clear()
{
    for (unsigned short int y=0 ; y<14 ; y++)
    {
        for (unsigned short int x=0 ; x<10 ; x++)
        {
            AllBoard[y][x].setState(0);
            AllBoard[y][x].setStateBoard(0);
        }
    }
}
