#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmyclickbutton.h"                                   //  my add right click mouse

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    std::srand(std::time(nullptr));
    MainWindow::setStyleSheet("background-color: lightgray;");

    // ------------------------------  generate and show botton  -------------------------------
    createBoard();
    saperBoard.generateNew();
    showBoard();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createBoard()
{
    QFont myButtonFont;
    myButtonFont.setPixelSize(16);
    myButtonFont.setFamily("Arial");
    myButtonFont.setBold(1);
    for (uint8_t y=0 ; y<14 ; y++)
    {
        for (uint8_t x=0 ; x<10 ; x++)
        {
            myButton[y][x] = new QMyClickButton();
            myButton[y][x]->setObjectName(QVariant(y*10+x).toString());
//            myButton[y][x]->size().setWidth(20);
//            myButton[y][x]->size().setHeight(40);
            myButton[y][x]->setFont(myButtonFont);
            myButton[y][x]->setStyleSheet("background-color: #b1b8b7;");
//            myButton[y][x]->setIcon(QIcon(":/res/01mine.png"));
            myButton[y][x]->setIconSize(QSize(20, 20));
            ui->gridLayout->addWidget(myButton[y][x],y,x);
            connect(myButton[y][x],SIGNAL(leftClicked()),this,SLOT(myButtonClick()));
            connect(myButton[y][x],SIGNAL(rightClicked()),this,SLOT(myButtonClickRight()));
        }
    }
}

void MainWindow::showBoard()
{
    for (uint8_t y=0 ; y<14 ; y++)
    {
        for (uint8_t x=0 ; x<10 ; x++)
        {
            if (saperBoard.get(y,x).isClicked())
                myButton[y][x]->setFlat(1);
            else
                myButton[y][x]->setFlat(0);
            if (saperBoard.get(y,x).isMine())
                myButton[y][x]->setIcon(QIcon(":/res/01mine.png"));
            if (saperBoard.get(y,x).isFlag())
                myButton[y][x]->setIcon(QIcon(":/res/03flag.png"));
            if (saperBoard.get(y,x).getStateDown()==10)
                myButton[y][x]->setIcon(QIcon(":/res/04joker.png"));
            if (saperBoard.get(y,x).getStateDown()>0 && saperBoard.get(y,x).getStateDown()<9)
                {
                    myButton[y][x]->setText(QVariant(saperBoard.get(y,x).getStateDown()).toString());
                    myButton[y][x]->setStyleSheet("color: "+saperBoard.getColorNumber(y,x)+";");
                }
        }
    }
}

void MainWindow::myButtonClick()
{
    ui->menuNowa_Gra->setTitle(((QPushButton*)sender())->objectName());
//    ((QPushButton*)sender())->blockSignals(1);
//    ((QPushButton*)sender())->setDown(0);
    ((QPushButton*)sender())->setFlat(1);
//    ((QPushButton*)sender())->setIcon(QIcon(":/res/02mine.png"));
}

void MainWindow::myButtonClickRight()
{
    ui->menuNowa_Gra->setTitle("ok");
    ((QPushButton*)sender())->setIcon(QIcon(":/res/03flag.png"));
}
