#include "myboard.h"
#include <QVector>

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
            AllBoard[y][x].setStateUp(0);
            AllBoard[y][x].setStateDown(0);
        }
    }
}

void MyBoard::generateNew()
{
    // -------------------------------------- random 10 mines ---------------------------------------
    struct Wsp
    {
        unsigned short int y=0;
        unsigned short int x=0;
    };
    Wsp temp;
    bool isTemp;
    QVector<Wsp> mineCounter;
    while (mineCounter.size()<20)
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
            AllBoard[temp.y][temp.x].setMine();
            AllBoard[temp.y][temp.x].setStateUp(1);//set click down
        }
    }

    // ----------------------------------- add Digits and Jokers ---------------------------------------

}

MyCell MyBoard::get(unsigned short y, unsigned short x)
{
    return AllBoard[y][x];
}
