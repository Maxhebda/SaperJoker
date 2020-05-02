#ifndef QMYCLICKBUTTON_H
#define QMYCLICKBUTTON_H

#include <QPushButton>
#include <QMouseEvent>

class  QMyClickButton : public QPushButton
{
    Q_OBJECT

public:
    explicit  QMyClickButton(QWidget *parent = 0);

private slots:
    void mousePressEvent(QMouseEvent *e);

signals:
    void rightClicked();
    void leftClicked();
};

#endif // QMYCLICKBUTTON_H
