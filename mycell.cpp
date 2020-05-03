#include "mycell.h"

MyCell::MyCell()
{
    stateUp = 0;
    stateDown = 0;
}

unsigned short int MyCell::getStateUp()
{
    return stateUp;
}

void MyCell::setMine()
{
    stateDown = 9;
}

unsigned short int MyCell::getStateDown()
{
    return stateDown;
}

void MyCell::setStateUp(unsigned short int s)
{
    stateUp = s;
}

void MyCell::setStateDown(unsigned short s)
{
    stateDown = s;
}

bool MyCell::isMine()
{
    if (stateDown==9)
        return true;
    else
        return false;
}

bool MyCell::isFlag()
{
    if (stateUp==2)
        return true;
    else
        return false;
}

bool MyCell::isClicked()
{
    if (stateUp==1)
        return true;
    else
        return false;
}
