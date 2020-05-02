#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::setStyleSheet("background-color: lightgray;");
    // generate board
    QFont myButtonFont;
    myButtonFont.setPixelSize(14);
    myButtonFont.setFamily("Arial");
    myButtonFont.setBold(1);
    for (uint8_t y=0 ; y<14 ; y++)
    {
        for (uint8_t x=0 ; x<10 ; x++)
        {
            myButton[y][x] = new QPushButton();
            myButton[y][x]->setObjectName(QVariant(y*10+x).toString());
            myButton[y][x]->size().setWidth(20);
            myButton[y][x]->size().setHeight(40);
            myButton[y][x]->setFont(myButtonFont);

            myButton[y][x]->setIcon(QIcon(":/res/01mine.png"));
//            myButton[y][x]->setDown(true);
            myButton[y][x]->setIconSize(QSize(20, 20));
            ui->gridLayout->addWidget(myButton[y][x],y,x);
            connect(myButton[y][x],SIGNAL(clicked()),this,SLOT(myButtonClick()));
            connect(myButton[y][x],SIGNAL(released()), this, SLOT(myButtonClickRight()));
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::myButtonClick()
{
    ui->menuNowa_Gra->setTitle(((QPushButton*)sender())->objectName());
}

void MainWindow::myButtonClickRight()
{
    ui->menuNowa_Gra->setTitle("ok");
}
