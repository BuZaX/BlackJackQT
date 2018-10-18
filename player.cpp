#include "player.h"
#include <QString>
#include <QPixmap>
#include <QTime>
#include <QCoreApplication>
#include <mainwindow.h>

// set card name like "As", "2d", "Jh" etc...
void Player::setCardString (QString c)
{
    cardString = c;
}

void Player::setCardSum (int sum)
{
    cardSum = cardSum + sum;
}

// set money depending if "double down" was pressed or not.
void Player::setMoney (int bet, double coef, bool extraBetState)
{
    if (extraBetState == false)
    {
        money = money + coef*bet;
    }

    else if (extraBetState == true)
    {
        money = money + 2*coef*bet;
    }
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

void Player::setCardNo()
{
    cardNo = cardNo + 1;
}

void Player::setCardSlot()
{
    slot = slot + 1;
}

void Player::resetCardSlot()
{
    slot = 2;
}

void Player::resetCardNo()
{
    cardNo = 0;
}

void Player::setAceCount()
{
    aceCount = aceCount + 1;
}

void Player::reduceAceCount()
{
    aceCount = aceCount - 1;
}

void Player::resetAceCount()
{
    aceCount = 0;
}

void Player::setBlackJackStateTrue()
{
    blackJackState = true;
}

void Player::setBlackJackStateFalse()
{
    blackJackState = false;
}

void Player::setDoubleDownStateTrue()
{
    doubleDownState = true;
}

void Player::setDoubleDownStateFalse()
{
    doubleDownState = false;
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

int Player::getCardNo()
{
    return cardNo;
}

// delay time function. Not to draw all of the cards directly.
void Player::delay(int n)
{
    QTime dieTime = QTime::currentTime().addSecs(n);
    while (QTime::currentTime() < dieTime)
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

int Player::getCardSlot()
{
    return slot;
}

int Player::getAceCount()
{
    return aceCount;
}

bool Player::getBlackJackState()
{
    return blackJackState;
}

bool Player::getDoubleDownState()
{
    return doubleDownState;
}

// assesing card value and getting card image based on the string like "Js", "3d" etc.
CardStruct Player::cardValue (QString card)
{

CardStruct cs;

if (card == "2s" )
{
    cs.value = 2;
    cs.cardImage.load(":/resources/resources/2s.gif");
}
else if (card == "3s" )
{
    cs.value = 3;
    cs.cardImage.load(":/resources/resources/3s.gif");
}
else if (card == "4s" )
{
    cs.value = 4;
    cs.cardImage.load(":/resources/resources/4s.gif");
}
else if (card == "5s")
{
    cs.value = 5;
    cs.cardImage.load(":/resources/resources/5s.gif");
}
else if (card == "6s" )
{
    cs.value = 6;
    cs.cardImage.load(":/resources/resources/6s.gif");
}
else if (card == "7s" )
{
    cs.value = 7;
    cs.cardImage.load(":/resources/resources/7s.gif");
}
else if (card == "8s" )
{
    cs.value = 8;
    cs.cardImage.load(":/resources/resources/8s.gif");
}
else if (card == "9s" )
{
    cs.value = 9;
    cs.cardImage.load(":/resources/resources/9s.gif");
}
else if (card == "10s" )
{
    cs.value = 10;
    cs.cardImage.load(":/resources/resources/10s.gif");
}
else if (card == "Js" )
{
    cs.value = 10;
    cs.cardImage.load(":/resources/resources/Js.gif");
}
else if (card == "Qs" )
{
    cs.value = 10;
    cs.cardImage.load(":/resources/resources/Qs.gif");
}
else if (card == "Ks" )
{
    cs.value = 10;
    cs.cardImage.load(":/resources/resources/Ks.gif");
}
else if (card == "As" )
{
    cs.value = 11;
    cs.cardImage.load(":/resources/resources/As.gif");
}



else if ( card == "2c" )
{
    cs.value = 2;
    cs.cardImage.load(":/resources/resources/2c.gif");
}
else if (card == "3c" )
{
    cs.value = 3;
    cs.cardImage.load(":/resources/resources/3c.gif");
}
else if (card == "4c" )
{
    cs.value = 4;
    cs.cardImage.load(":/resources/resources/4c.gif");
}
else if (card == "5c" )
{
    cs.value = 5;
    cs.cardImage.load(":/resources/resources/5c.gif");
}
else if ( card == "6c")
{
    cs.value = 6;
    cs.cardImage.load(":/resources/resources/6c.gif");
}
else if ( card == "7c" )
{
    cs.value = 7;
    cs.cardImage.load(":/resources/resources/7c.gif");
}
else if (card == "8c" )
{
    cs.value = 8;
    cs.cardImage.load(":/resources/resources/8c.gif");
}
else if ( card == "9c" )
{
    cs.value = 9;
    cs.cardImage.load(":/resources/resources/9c.gif");
}
else if (card == "10c")
{
    cs.value = 10;
    cs.cardImage.load(":/resources/resources/10c.gif");
}
else if (card == "Jc" )
{
    cs.value = 10;
    cs.cardImage.load(":/resources/resources/Jc.gif");
}
else if (card == "Qc")
{
    cs.value = 10;
    cs.cardImage.load(":/resources/resources/Qc.gif");
}
else if (card == "Kc")
{
    cs.value = 10;
    cs.cardImage.load(":/resources/resources/Kc.gif");
}
else if (card == "Ac")
{
    cs.value = 11;
    cs.cardImage.load(":/resources/resources/Ac.gif");
}


else if ( card == "2d" )
{
    cs.value = 2;
    cs.cardImage.load(":/resources/resources/2d.gif");
}
else if (card == "3d" )
{
    cs.value = 3;
    cs.cardImage.load(":/resources/resources/3d.gif");
}
else if (card == "4d" )
{
    cs.value = 4;
    cs.cardImage.load(":/resources/resources/4d.gif");
}
else if (card == "5d" )
{
    cs.value = 5;
    cs.cardImage.load(":/resources/resources/5d.gif");
}
else if ( card == "6d")
{
    cs.value = 6;
    cs.cardImage.load(":/resources/resources/6d.gif");
}
else if ( card == "7d" )
{
    cs.value = 7;
    cs.cardImage.load(":/resources/resources/7d.gif");
}
else if (card == "8d" )
{
    cs.value = 8;
    cs.cardImage.load(":/resources/resources/8d.gif");
}
else if ( card == "9d" )
{
    cs.value = 9;
    cs.cardImage.load(":/resources/resources/9d.gif");
}
else if (card == "10d")
{
    cs.value = 10;
    cs.cardImage.load(":/resources/resources/10d.gif");
}
else if (card == "Jd" )
{
    cs.value = 10;
    cs.cardImage.load(":/resources/resources/Jd.gif");
}
else if (card == "Qd")
{
    cs.value = 10;
    cs.cardImage.load(":/resources/resources/Qd.gif");
}
else if (card == "Kd")
{
    cs.value = 10;
    cs.cardImage.load(":/resources/resources/Kd.gif");
}
else if (card == "Ad")
{
    cs.value = 11;
    cs.cardImage.load(":/resources/resources/Ad.gif");
}



else if ( card == "2h" )
{
    cs.value = 2;
    cs.cardImage.load(":/resources/resources/2h.gif");
}
else if (card == "3h" )
{
    cs.value = 3;
    cs.cardImage.load(":/resources/resources/3h.gif");
}
else if (card == "4h" )
{
    cs.value = 4;
    cs.cardImage.load(":/resources/resources/4h.gif");
}
else if (card == "5h" )
{
    cs.value = 5;
    cs.cardImage.load(":/resources/resources/5h.gif");
}
else if ( card == "6h")
{
    cs.value = 6;
    cs.cardImage.load(":/resources/resources/6h.gif");
}
else if ( card == "7h" )
{
    cs.value = 7;
    cs.cardImage.load(":/resources/resources/7h.gif");
}
else if (card == "8h" )
{
    cs.value = 8;
    cs.cardImage.load(":/resources/resources/8h.gif");
}
else if ( card == "9h" )
{
    cs.value = 9;
    cs.cardImage.load(":/resources/resources/9h.gif");
}
else if (card == "10h")
{
    cs.value = 10;
    cs.cardImage.load(":/resources/resources/10h.gif");
}
else if (card == "Jh" )
{
    cs.value = 10;
    cs.cardImage.load(":/resources/resources/Jh.gif");
}
else if (card == "Qh")
{
    cs.value = 10;
    cs.cardImage.load(":/resources/resources/Qh.gif");
}
else if (card == "Kh")
{
    cs.value = 10;
    cs.cardImage.load(":/resources/resources/Kh.gif");
}
else if (card == "Ah")
{
    cs.value = 11;
    cs.cardImage.load(":/resources/resources/Ah.gif");
}

return cs;
}

