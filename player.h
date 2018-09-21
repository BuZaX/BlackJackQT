#ifndef PLAYER_H
#define PLAYER_H

#include <QString>
#include <QPixmap>

class Player
{

private:
    int money = 500;
    QString cardString;
    int cardSum = 0;
    int bet = 0;

public:
    void setCardString (QString c);
    void setCardSum (int sum);
    void setMoney (int bet, double coef);
    void placeBet(int b);
    void resetCardSum();
    void resetMoney();
    QString getCardString();
    int getCardSum ();
    int getMoney();
    int getBet();

    struct CardStruct
    {
      QPixmap cardImage;
      int value;
    };

    CardStruct cardValue (QString card);




};

#endif // PLAYER_H
