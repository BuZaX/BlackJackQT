#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QPixmap>
#include "player.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString cards[52] = {"2s", "3s", "4s", "5s", "6s", "7s", "8s", "9s", "10s", "Js", "Qs", "Ks", "As", "2h", "3h", "4h", "5h", "6h", "7h", "8h", "9h", "10h", "Jh", "Qh", "Kh", "Ah","2c", "3c", "4c", "5c", "6c", "7c", "8c", "9c", "10c", "Jc", "Qc", "Kc", "Ac","2d", "3d", "4d", "5d", "6d", "7d", "8d", "9d", "10d", "Jd", "Qd", "Kd", "Ad"};


    for (int i = 0; i < 52; i++)
    {
     largeDeck[i] = cards[i];
    }
    for (int i = 52; i < 104; i++)
    {
        largeDeck[i] = cards[i - 52];
    }
    for (int i = 104; i < 156; i++)
    {
        largeDeck[i] = cards[i - 104];
    }
    for (int i = 156; i < 208; i++)
    {
        largeDeck[i] = cards[i - 156];
    }
    for (int i = 208; i < 260; i++)
    {
        largeDeck[i] = cards[i - 208];
    }
    for(int i = 260; i < 312; i++)
    {
        largeDeck[i] = cards[i - 260];
    }

    shuffle(largeDeck, 312);


    Player p1;
    Player dealer;


    ui -> money_label -> setText(QString::number(p1.getMoney()));

    p1.setCardString(largeDeck[0]);

    p1.setCardSum(p1.cardValue(p1.getCardString()).value);

    //p1.setCardSum(p1.cardValue(p1.getCardString()).value);
    //ui -> label1 -> setPixmap(p1.cardValue(p1.getCardString()).cardImage);




}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::shuffle(QString deck1[], int len)
{
   int randomIndex = 0;
   QString tempStr = "";
   srand(time(NULL));

   for(int i = 0; i < len; i++)
   {
    randomIndex = rand() % len;
    tempStr = deck1[i];
    deck1[i] = deck1[randomIndex];
    deck1[randomIndex] = tempStr;
   }
}

QString* MainWindow::returnLargeDeck()
{
    return largeDeck;
}

void MainWindow::on_hitButton_clicked()
{

}
