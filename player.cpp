#include "player.h"
#include <QString>
#include <QPixmap>
#include <mainwindow.h>

void Player::setCardString (QString c)
{
    cardString = c;
}

void Player::setCardSum (int sum)
{
    cardSum = cardSum + sum;
}

void Player::setMoney (int bet, double coef)
{
    money = money + coef*bet;
}

void Player::placeBet(int b)
{
    bet = b;
    money = money - bet;
}

void Player::resetCardSum()
{
    cardSum = 0;
}

void Player::resetMoney()
{
    money = 500;
}

QString Player::getCardString()
{
    return cardString;
}
int Player::getCardSum ()
{
   return cardSum;
}

int Player::getMoney()
{
    return money;
}

int Player::getBet()
{
    return bet;
}



Player::CardStruct cardValue (QString card)
{

Player::CardStruct cs;

if (card == "2s" || card == "2c" || card == "2h" || card == "2d")
{
    cs.value = 2;
    cs.cardImage.load(":/resources/resources/2s.gif");
}
else if (card == "3s" || card == "3c" || card == "3h" || card == "3d")
{
    cs.value = 3;
    cs.cardImage.load(":/resources/resources/3s.gif");
}
else if (card == "4s" || card == "4c" || card == "4h" || card == "4d")
{
    cs.value = 4;
    cs.cardImage.load(":/resources/resources/4s.gif");
}
else if (card == "5s" || card == "5c" || card == "5h" || card == "5d")
{
    cs.value = 5;
    cs.cardImage.load(":/resources/resources/5s.gif");
}
else if (card == "6s" || card == "6c" || card == "6h" || card == "6d")
{
    cs.value = 6;
    cs.cardImage.load(":/resources/resources/6s.gif");
}
else if (card == "7s" || card == "7c" || card == "7h" || card == "7d")
{
    cs.value = 7;
    cs.cardImage.load(":/resources/resources/7s.gif");
}
else if (card == "8s" || card == "8c" || card == "8h" || card == "8d")
{
    cs.value = 8;
    cs.cardImage.load(":/resources/resources/8s.gif");
}
else if (card == "9s" || card == "9c" || card == "9h" || card == "9d")
{
    cs.value = 9;
    cs.cardImage.load(":/resources/resources/9s.gif");
}
else if (card == "10s" || card == "10c" || card == "10h" || card == "10d")
{
    cs.value = 10;
    cs.cardImage.load(":/resources/resources/10s.gif");
}
else if (card == "Js" || card == "Jc" || card == "Jh" || card == "Jd")
{
    cs.value = 10;
    cs.cardImage.load(":/resources/resources/Js.gif");
}
else if (card == "Qs" || card == "Qc" || card == "Qh" || card == "Qd")
{
    cs.value = 10;
    cs.cardImage.load(":/resources/resources/Qs.gif");
}
else if (card == "Ks" || card == "Kc" || card == "Kh" || card == "Kd")
{
    cs.value = 10;
    cs.cardImage.load(":/resources/resources/Ks.gif");
}
else if (card == "As" || card == "Ac" || card == "Ah" || card == "Ad")
{
    cs.value = 3;
    cs.cardImage.load(":/resources/resources/As.gif");
}



return cs;
}

