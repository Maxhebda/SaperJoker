#include "myboard.h"
#include <QVector>

MyBoard::MyBoard()
{
    clear();
}

QString MyBoard::getColorNumber(unsigned short int y, unsigned short int x)
{
    switch (allBoard[y][x].getStateDown()) {
        case  1 : { return "#da24ea";break;}
        case  2 : { return "#8eaf74";break;}
        case  3 : { return "#52942f";break;}
        case  4 : { return "#08007e";break;}
        case  5 : { return "#3527ff";break;}
        case  6 : { return "#ff1717";break;}
        case  7 : { return "#990000";break;}
        case  8 : { return "#2d4a08";break;}
        default : { return "#452828";break;}
    }
}

void MyBoard::clear()
{
    for (unsigned short int y=0 ; y<14 ; y++)
    {
        for (unsigned short int x=0 ; x<10 ; x++)
        {
            allBoard[y][x].setStateUp(0);
            allBoard[y][x].setStateDown(0);
        }
    }
}

void MyBoard::generateNew()
{
    // -------------------------------------- random 25 mines ---------------------------------------
    struct Wsp
    {
        unsigned short int y=0;
        unsigned short int x=0;
    };
    Wsp temp;
    bool isTemp;
    QVector<Wsp> mineCounter;
    while (mineCounter.size()<25)
    {
        temp.y = rand()%14;                                     // random value 0-13
        temp.x = rand()%10;
        isTemp=false;
        for (auto iter=mineCounter.begin() ; iter != mineCounter.end() ; iter++)
        {
            if (iter->x==temp.x && iter->y==temp.y)
            {
                isTemp = true;
                break;
            }
        }
        if (!isTemp)
        {
            mineCounter.push_back(temp);
            allBoard[temp.y][temp.x].setMine();
            allBoard[temp.y][temp.x].setStateUp(1);//set click down
        }
    }

    // ----------------------------------- add Digits and Jokers ---------------------------------------
    for (unsigned short int y=0; y<14 ; y++)
    {
        for (unsigned short int x=0; x<10 ; x++)
        {
            if (!allBoard[y][x].isMine())
            {
                allBoard[y][x].setStateDown(numberOfMin(y,x));
            }
        }
    }

}

MyCell MyBoard::get(unsigned short y, unsigned short x)
{
    return allBoard[y][x];
}

unsigned short int MyBoard::numberOfMin(unsigned short int y, unsigned short int x)
{
    unsigned short int temp=0;
    if (y>0 && x>0) if (allBoard[y-1][x-1].isMine()) temp++;
    if (y>0)        if (allBoard[y-1][x].isMine()) temp++;
    if (y>0 && x<9)if (allBoard[y-1][x+1].isMine()) temp++;

    if (x>0)        if (allBoard[y][x-1].isMine()) temp++;
    if (x<9)       if (allBoard[y][x+1].isMine()) temp++;

    if (y<13&& x>0) if (allBoard[y+1][x-1].isMine()) temp++;
    if (y<13)       if (allBoard[y+1][x].isMine()) temp++;
    if (y<13&& x<9)if (allBoard[y+1][x+1].isMine()) temp++;
    return temp;
}
