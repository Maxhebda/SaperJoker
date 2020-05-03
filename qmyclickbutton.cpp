#include "qmyclickbutton.h"

QMyClickButton:: QMyClickButton(QWidget *parent) :  QPushButton(parent)
{
}

void  QMyClickButton::mousePressEvent(QMouseEvent *e)
{
    if(e->button()==Qt::RightButton)
        emit rightClicked();
    if(e->button()==Qt::LeftButton)
        emit leftClicked();
}
