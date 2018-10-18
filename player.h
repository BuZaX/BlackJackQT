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
    int aceCount = 0;
    bool blackJackState = false;
    bool doubleDownState = false;

public:
    void setCardString (QString c);
    void setCardSum (int sum);
    void setMoney (int bet, double coef, bool extraBetState);
    void setCardNo();
    void placeBet(int b);
    void resetCardSum();
    void resetMoney();
    void delay(int n);
    void setCardSlot();
    void resetCardSlot();
    void resetCardNo();
    void setAceCount();
    void reduceAceCount();
    void resetAceCount();
    void setBlackJackStateTrue();
    void setBlackJackStateFalse();
    void setDoubleDownStateTrue();
    void setDoubleDownStateFalse();
    QString getCardString();
    int getCardSum ();
    int getMoney();
    int getBet();
    int getCardNo();
    int getCardSlot();
    int getAceCount();
    bool getBlackJackState();
    bool getDoubleDownState();
    CardStruct cardValue (QString card);
};

#endif // PLAYER_H
