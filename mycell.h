#ifndef MYCELL_H
#define MYCELL_H


class MyCell
{
public:
    MyCell();
    unsigned short int getStateDown();
    unsigned short int getStateUp();
    void setStateDown(unsigned short int);
    void setStateUp(unsigned short int);
    bool isMine();
    bool isFlag();
    bool isClicked();                               //if is click
    void setMine();

private:
    unsigned short int stateDown;               //012345678  9-mine  10-joker 11-mineBoom
    unsigned short int stateUp;                    //0-clear 1-click 2-flag
};

#endif // MYCELL_H
