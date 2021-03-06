#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmyclickbutton.h"                                   //  my add right click mouse
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    std::srand(std::time(nullptr));
    MainWindow::setStyleSheet("background-color: lightgray;");

    connect(ui->actionNew_Game,SIGNAL(triggered()),this,SLOT(newGameClick()));
    connect(ui->actionInformacje,SIGNAL(triggered()),this,SLOT(infoClick()));
    connect(ui->actionZamknij,SIGNAL(triggered()),this,SLOT(close()));
    // ------------------------------  generate and show botton  -------------------------------
    endGame = false;
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
            myButton[y][x]->setFont(myButtonFont);
            myButton[y][x]->setStyleSheet("background-color: #b1b8b7;");
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
                {
                    myButton[y][x]->setFlat(1);
                    myButton[y][x]->setIcon(QIcon(""));
                    if (saperBoard.get(y,x).isMine())
                        {
                            if (saperBoard.get(y,x).getStateDown()==11)
                                myButton[y][x]->setIcon(QIcon(":/res/02mine.png"));     //mineBoom
                            else
                            {
                                if (saperBoard.get(y,x).getStateUp()==3)
                                {
                                    myButton[y][x]->setIcon(QIcon(":/res/05mine.png"));     //mine and OK
                                }
                                else
                                {
                                    myButton[y][x]->setIcon(QIcon(":/res/01mine.png"));     //regular mine
                                }
                            }

                        }
                    else
                    if (saperBoard.get(y,x).getStateDown()==10)
                        myButton[y][x]->setIcon(QIcon(":/res/04joker.png"));
                    else
                        myButton[y][x]->setIcon(QIcon(""));

                    if (saperBoard.get(y,x).getStateDown()>0 && saperBoard.get(y,x).getStateDown()<9)
                        {
                            myButton[y][x]->setText(QVariant(saperBoard.get(y,x).getStateDown()).toString());
                            myButton[y][x]->setStyleSheet("color: "+saperBoard.getColorNumber(y,x)+";");
                        }
                }
            else
                {
                    myButton[y][x]->setFlat(0);
                    myButton[y][x]->setText("");
                    myButton[y][x]->setStyleSheet("background-color: #b1b8b7;");
                    if (saperBoard.get(y,x).isFlag())
                        {
                            if (endGame && saperBoard.get(y,x).isMine()==false)
                                myButton[y][x]->setIcon(QIcon(":/res/06flag.png"));
                            else
                                myButton[y][x]->setIcon(QIcon(":/res/03flag.png"));
                        }
                    else
                        myButton[y][x]->setIcon(QIcon(""));
                }
        }
    }
}

unsigned short int MainWindow::getNumButtonX(unsigned short int numberObjectButton)
{
    unsigned short int temp = numberObjectButton / 10;
    return numberObjectButton - 10 * temp;
}

unsigned short int MainWindow::getNumButtonY(unsigned short int numberObjectButton)
{
    return numberObjectButton / 10;
}

void MainWindow::myButtonClick()
{
    if (!endGame)
        {
            unsigned short int y = getNumButtonY(QVariant(((QPushButton*)sender())->objectName()).toInt());
            unsigned short int x = getNumButtonX(QVariant(((QPushButton*)sender())->objectName()).toInt());

            saperBoard.setClick(y,x);

            if (saperBoard.get(y,x).getStateDown()==0)          //if you click on empty, looking for empty neighbors
            {
                saperBoard.clickNeigbors(y,x);
            }
            else
            if (saperBoard.isMine(y,x))
            {
                endGame = true;
                saperBoard.clickAllMines();
                saperBoard.setMineBoom(y,x);
                ui->menuNowa_Gra->setTitle("Przegrana :)");
            }
            showBoard();
        }
}

void MainWindow::myButtonClickRight()
{
    if (!endGame)
        {
            unsigned short int y = getNumButtonY(QVariant(((QPushButton*)sender())->objectName()).toInt());
            unsigned short int x = getNumButtonX(QVariant(((QPushButton*)sender())->objectName()).toInt());

            if (!saperBoard.get(y,x).isClicked())
                {
                    if (saperBoard.get(y,x).isFlag())
                        {
                            saperBoard.unSetFlag(y,x);
                        }
                    else
                        {
                            saperBoard.setFlag(y,x);
                            if (saperBoard.isWin())
                            {
                                endGame=true;
                                saperBoard.clickAllMines();
                                ui->menuNowa_Gra->setTitle("Wygrana :)");
                            }
                        }
                }
            showBoard();
        }
}

void MainWindow::newGameClick()
{
    endGame = false;
    saperBoard.clear();
    saperBoard.generateNew();
    ui->menuNowa_Gra->setTitle("Gra");
    showBoard();
}

void MainWindow::infoClick()
{
    QMessageBox::information(this, "Informacje o grze", "Gra SaperJoker jest podobna do windowsowskiego Sapera. Dodano jednak utrudnienie w postaci przykrycia ok 5% liczb. Joker oznacza, że obok znajduje się przynajmniej jedna mina - dokładnej liczby min nie znamy.\n\nRozmiar planszy - 10x14,\nLiczba min - 15,\nLiczba Jokerów - 5%\n\nAutor : Maksymilian Hebda\n[mini projekt napisany w QT Creator / C++ 10.05.2020]" );
}
