#include "mycell.h"

MyCell::MyCell()
{
    state = 0;
    stateBoard = 0;
}

unsigned short int MyCell::getState()
{
    return state;
}

unsigned short int MyCell::getStateBoard()
{
    return stateBoard;
}

void MyCell::setState(unsigned short int s)
{
    state = s;
}

void MyCell::setStateBoard(unsigned short s)
{
    stateBoard = s;
}

bool MyCell::isMine()
{
    if (stateBoard==9)
        return true;
    else
        return false;
}

bool MyCell::isFlag()
{
    if (state==2)
        return true;
    else
        return false;
}
