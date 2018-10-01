#ifndef PLAYER_H
#define PLAYER_H

#include <QString>
#include <QPixmap>

struct CardStruct
{
  QPixmap cardImage;
  int value;
};

class Player
{

private:
    int money = 500;
    QString cardString;
    int cardSum = 0;
    int bet = 0;
    int cardNo = 0;
    int slot = 2;

public:
    void setCardString (QString c);
    void setCardSum (int sum);
    void setMoney (int bet, double coef);
    void setCardNo();
    void placeBet(int b);
    void resetCardSum();
    void resetMoney();
    void delay(int n);
    void setCardSlot();
    void resetCardSlot();
    void resetCardNo();
    QString getCardString();
    int getCardSum ();
    int getMoney();
    int getBet();
    int getCardNo();
    int getCardSlot();
    CardStruct cardValue (QString card);




};

#endif // PLAYER_H
