#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <qmyclickbutton.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QMyClickButton * myButton[14][10];
    uint8_t myBoard[14][10];                    // 012345678-down  10-clear 9-mine 10-flag 11-joker 12-boom

private slots:
    void myButtonClick();
    void myButtonClickRight();
};
#endif // MAINWINDOW_H
