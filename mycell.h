#ifndef MYCELL_H
#define MYCELL_H


class MyCell
{
public:
    MyCell();
    unsigned short int getStateBoard();
    unsigned short int getState();
    void setStateBoard(unsigned short int);
    void setState(unsigned short int);
    bool isMine();
    bool isFlag();

private:
    unsigned short int stateBoard;               //012345678  9-mine  10-joker
    unsigned short int state;                    //0-clear 1-click 2-flag
};

#endif // MYCELL_H
