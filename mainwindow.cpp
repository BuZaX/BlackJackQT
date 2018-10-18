// including all required libraries.
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "player.h"
#include "information.h"
#include <QLabel>
#include <QPixmap>
#include <QDebug>
#include <QMediaPlayer>
#include <QMatrix>
#include <QKeyEvent>

// creating objects
Player p1;
Player dealer;
QMediaPlayer* media = new QMediaPlayer;
QLabel* lables_[24];
QMatrix matrix;

// cleaning card labels.
void MainWindow::cleanLabels()
{
    for (int var = 0; var < 24; ++var)
    {
        lables_[var] -> clear();
    }
    ui -> label_doubleDown -> clear();
}

// allowing user to use keyboard shortcuts.
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event -> key() == Qt::Key_Return && ui -> hitButton -> isEnabled() == true)
    {
        ui -> hitButton -> clicked();
    }

    else if (event -> key() == Qt::Key_S && ui -> stayButton -> isEnabled() == true)
    {
        ui -> stayButton -> clicked();
    }

    else if (event -> key() == Qt::Key_B && ui -> betButton -> isEnabled() == true)
    {
        ui -> betButton -> clicked();
    }

    else if (event -> key() == Qt::Key_D && ui -> doubleDownButton -> isEnabled() == true)
    {
        ui -> doubleDownButton -> clicked();
    }

    else if (event -> key() == Qt::Key_R && ui -> resetButton -> isEnabled() == true)
    {
        ui -> resetButton -> clicked();
    }
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    // initial button set up.
    ui->setupUi(this);
    ui -> betButton -> setEnabled(true);
    ui -> hitButton -> setEnabled(false);
    ui -> stayButton -> setEnabled(false);
    ui -> doubleDownButton -> setEnabled(false);

    ui -> betEdit -> clearFocus();

    // making label array
    lables_[0] = ui -> label1;
    lables_[1] = ui -> label2;
    lables_[2] = ui -> label3;
    lables_[3] = ui -> label4;
    lables_[4] = ui -> label5;
    lables_[5] = ui -> label6;
    lables_[6] = ui -> label7;
    lables_[7] = ui -> label8;
    lables_[8] = ui -> label9;
    lables_[9] = ui -> label10;
    lables_[10] = ui -> label12;
    lables_[11] = ui -> label12_2;

    lables_[12] = ui -> label11;
    lables_[13] = ui -> label22;
    lables_[14] = ui -> label33;
    lables_[15] = ui -> label44;
    lables_[16] = ui -> label55;
    lables_[17] = ui -> label66;
    lables_[18] = ui -> label77;
    lables_[19] = ui -> label88;
    lables_[20] = ui -> label99;
    lables_[21] = ui -> label1010;
    lables_[22] = ui -> label1111;
    lables_[23] = ui -> label1212;

    // creating initial card array.
    QString cards[52] = {"2s", "3s", "4s", "5s", "6s", "7s", "8s", "9s", "10s", "Js", "Qs", "Ks", "As", "2h", "3h", "4h", "5h", "6h", "7h", "8h", "9h", "10h", "Jh", "Qh", "Kh", "Ah","2c", "3c", "4c", "5c", "6c", "7c", "8c", "9c", "10c", "Jc", "Qc", "Kc", "Ac","2d", "3d", "4d", "5d", "6d", "7d", "8d", "9d", "10d", "Jd", "Qd", "Kd", "Ad"};
    ui -> labelBackground -> lower();

    // creating 6 copies of previously stated card array.
    int copies = 6;
    for (int i = 0; i < 52*copies; i++)
    {
        largeDeck[i] = cards[i%52];
    }


    // shuffling cards.
    shuffle(largeDeck, 312);

//  Large deck could be modified here for debug purposes.
            largeDeck[0] = "Jd";
            largeDeck[1] = "7s";
            largeDeck[2] = "Ad";
            largeDeck[3] = "3c";
//            largeDeck[4] = "Ad";
//            largeDeck[5] = "4c";
//            largeDeck[6] = "6d";
//            largeDeck[7] = "2s";
//            largeDeck[8] = "Qs";
//            largeDeck[9] = "Ac";
//            largeDeck[10] = "Ad";
//            largeDeck[11] = "Ad";
//            largeDeck[12] = "Ad";
//            largeDeck[13] = "As";

    // setting media and labels.
    ui -> money_label -> setText("$"+QString::number(p1.getMoney()));
    ui -> stayButton -> setEnabled(false);
    ui -> hitButton -> setEnabled(false);
    media -> setMedia(QUrl("qrc:/resources/resources/cardSound.mp3"));
    media -> setVolume(100);
    media -> play();
}

MainWindow::~MainWindow()
{
    delete media;
    delete ui;
}

// shuffle function for card shuffling.
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

// executes, when the "hit" button is pressed.
void MainWindow::on_hitButton_clicked()
{
    media -> play();
    ui -> resetButton -> setEnabled(false);
    ui -> doubleDownButton -> setEnabled(false);

    // ### drawing card and setting values.
    p1.setCardString(largeDeck[p1.getCardNo()]);\
    if (p1.cardValue(p1.getCardString()).value == 11)
    {
        // check if ace is drawn.
        p1.setAceCount();
    }
    p1.setCardSum(p1.cardValue(p1.getCardString()).value);
    lables_[p1.getCardSlot()] -> setPixmap(p1.cardValue(p1.getCardString()).cardImage);
    // ###

    media -> play();
    p1.setCardNo();
    p1.setCardSlot();

    // if player scores less than 21 during "hit", do nothing.
    if (p1.getCardSum() <= 21)
    {

    }

    // if player scores more than 21 without having an ace, bust him. Also, set labels.
    else if (p1.getCardSum() > 21 && p1.getAceCount() == 0)
    {
        ui -> labelCenter -> clear();
        ui -> labelCenter -> setStyleSheet(QStringLiteral("QLabel{color: rgb(170, 0, 0);}"));
        ui -> labelCenter -> setText("Player busted!");

        ui -> betEdit -> setMaximum(p1.getMoney());
        ui -> stayButton -> setEnabled(false);
        ui -> hitButton -> setEnabled(false);
        ui -> doubleDownButton -> setEnabled(false);
        ui -> betButton -> setEnabled(true);
        ui -> resetButton -> setEnabled(true);

        // make dealer and player ace count to 0 and black jack state to false, since new hame will start.
        dealer.resetAceCount();
        dealer.setBlackJackStateFalse();
        p1.resetAceCount();

        // if player is out of money, end the game.
        if (p1.getMoney() == 0)
        {
            ui -> betButton -> setEnabled(false);
            ui -> labelCenter -> setStyleSheet(QStringLiteral("QLabel{color: rgb(170, 0, 0);}"));
            ui -> labelCenter -> setText("Game over! :(");
        }
    }

    // if player scores more than 21 during "hit" state and he has an ace.
    else if (p1.getCardSum() > 21 && p1.getAceCount() != 0)
    {
        // reduce the score by 10 and do not look at the ace again.
        p1.setCardSum(-10);
        p1.reduceAceCount();

        // if "hit" is pressed and the score more than 21 and ace is drawn.
        if (p1.getCardSum() > 21)
        {
            ui -> labelCenter -> clear();
            ui -> labelCenter -> setText("Player busted!");

            ui -> betEdit -> setMaximum(p1.getMoney());
            ui -> stayButton -> setEnabled(false);
            ui -> hitButton -> setEnabled(false);
            ui -> doubleDownButton -> setEnabled(false);
            ui -> betButton -> setEnabled(true);
            ui -> resetButton -> setEnabled(true);

            // if player runs out of money.
            if (p1.getMoney() == 0)
            {
                ui -> betButton -> setEnabled(false);
                ui -> labelCenter -> setStyleSheet(QStringLiteral("QLabel{color: rgb(170, 0, 0);}"));
                ui -> labelCenter -> setText("Game over! :(");
            }
        }
    }
}

// executes, when the "bet" button is pressed.
void MainWindow::on_betButton_clicked()
{
    // if ~70% of cards are used, bring all cards back to the deck and shuffle them. Continue the game
    if(p1.getCardNo() >= 242)
    {
        MainWindow::shuffle(MainWindow::returnLargeDeck(), 312);
        p1.resetCardNo();
        qDebug() << "Cards shuffled, reset";
    }

    ui -> resetButton -> setEnabled(false);
    ui -> betButton -> setEnabled(false);
    ui -> betEdit -> clearFocus();
    MainWindow::cleanLabels();
    ui -> labelCenter -> setText(" ");
    dealer.resetCardSum();
    dealer.resetAceCount();
    dealer.setBlackJackStateFalse();
    p1.resetCardSum();
    p1.resetCardSlot();
    p1.resetAceCount();
    p1.setBlackJackStateFalse();
    p1.setDoubleDownStateFalse();

    pix.load(":/resources/resources/xx.gif");

    ui -> betEdit -> setMaximum(p1.getMoney());
    p1.placeBet(ui -> betEdit -> text().toInt());

    ui -> money_label -> setText("$"+QString::number(p1.getMoney()));

    if (p1.getCardNo() != 0)
    {
        dealer.delay(1);
    }

    if (p1.getBet() <= (p1.getMoney() + p1.getBet() ))
    {
        ui -> money_label -> setText("$"+QString::number(p1.getMoney()));
        // ### player draws first card.
        p1.setCardString(largeDeck[p1.getCardNo()]);
        if (p1.cardValue(p1.getCardString()).value == 11)
        {
            p1.setAceCount();
        }
        p1.setCardSum(p1.cardValue(p1.getCardString()).value);
        ui -> label1 -> setPixmap(p1.cardValue(p1.getCardString()).cardImage);
        media -> play();
        p1.setCardNo();
        // ### end of player drawing first card.

        // ### dealer draws first card.
        dealer.setCardString(largeDeck[p1.getCardNo()]);
        if(dealer.cardValue(dealer.getCardString()).value == 11)
        {
            dealer.setAceCount();
        }
        dealer.setCardSum(dealer.cardValue(dealer.getCardString()).value);
        ui -> label11 -> setPixmap(dealer.cardValue(dealer.getCardString()).cardImage);
        p1.setCardNo(); // player is counting cards, not the dealer.
        // ### end of dealer drawing first card.

        // ### player draws second card.
        p1.setCardString(largeDeck[p1.getCardNo()]);
        if (p1.cardValue(p1.getCardString()).value == 11)
        {
            p1.setAceCount();
        }
        p1.setCardSum(p1.cardValue(p1.getCardString()).value);
        ui -> label2 -> setPixmap(p1.cardValue(p1.getCardString()).cardImage);
        p1.setCardNo();
        // ### end of player drawing second card.

        // if both cards in hand for player are aces...
        if (p1.getAceCount() == 2)
        {
            p1.setCardSum(-10); // reduces score by 10.
            p1.reduceAceCount();
        }

        // enabling double down is player has the money and hand value is less than 11.
        if (p1.getBet()*2 <= (p1.getMoney() + p1.getBet()) && p1.getCardSum() <= 11 )
        {
            ui -> doubleDownButton -> setEnabled(true);
        }

        // if ace is present in hand, allow double down.
        else if (p1.getBet()*2 <= (p1.getMoney() + p1.getBet()) && p1.getAceCount() != 0)
        {
                ui -> doubleDownButton -> setEnabled(true);
        }

        // place a face fown card for a dealer.
        ui -> label22 -> setPixmap(pix);

        // if 21 is scored directly.
        if (p1.getCardSum() == 21)
        {
            // setting a black jack state which is going to be compared with dealer's state.
            p1.setBlackJackStateTrue();

            // if dealer does not have 10 or 11 valued card, award with black jack directly.
            if (dealer.getCardSum() < 10)
            {
                ui -> labelCenter -> clear();
                ui -> labelCenter -> setText("Player BlackJack!");

                ui -> labelCenter -> setStyleSheet(QStringLiteral("QLabel{color: rgb(0, 0, 170);}"));
                p1.setMoney(p1.getBet(), 2.5, p1.getDoubleDownState());
                ui -> money_label -> setText("$"+QString::number(p1.getMoney()));
                ui -> betEdit -> setMaximum(p1.getMoney());

                ui -> stayButton -> setEnabled(false);
                ui -> hitButton -> setEnabled(false);
                ui -> doubleDownButton -> setEnabled(false);
                ui -> betButton -> setEnabled(true);
                ui -> resetButton -> setEnabled(true);

                p1.setBlackJackStateFalse();
                return;
            }
        }

        // ### dealer draws second card.
        dealer.setCardString(largeDeck[p1.getCardNo()]);
        if(dealer.cardValue(dealer.getCardString()).value == 11)
        {
            dealer.setAceCount();
        }
        dealer.setCardSum(dealer.cardValue(dealer.getCardString()).value);
        p1.setCardNo();
        // ### end of player drawing second card.

        // check if dealer has a black jack.
        if (dealer.getCardSum() == 21)
        {
            dealer.setBlackJackStateTrue();
        }

        qDebug() << "player score: " << p1.getCardSum();
        qDebug() << "dealer score: " << dealer.getCardSum();
        qDebug() << "Card No: " << p1.getCardNo();

        ui -> hitButton -> setEnabled(true);
        ui -> stayButton -> setEnabled(true);
    }
    else
    {

    }
}

// executes, when the "stay" button is pressed.
void MainWindow::on_stayButton_clicked()
{
    ui -> resetButton -> setEnabled(false);
    ui -> hitButton -> setEnabled(false);
    ui -> betButton -> setEnabled(false);
    ui -> doubleDownButton -> setEnabled(false);
    ui -> stayButton -> setEnabled(false);

    ui -> label22 -> clear();
    ui -> label22 -> setPixmap(dealer.cardValue(dealer.getCardString()).cardImage);

    // check the black jack states of player and dealer.
    // if dealer scores 21 and player does not...
    if (dealer.getBlackJackState() == true && p1.getBlackJackState() == false)
    {
        ui -> labelCenter -> setStyleSheet(QStringLiteral("QLabel{color: rgb(170, 0, 0);}"));
        ui -> labelCenter -> setText("Dealer BlackJack!");

        ui -> stayButton -> setEnabled(false);
        ui -> hitButton -> setEnabled(false);
        ui -> doubleDownButton -> setEnabled(false);
        ui -> betButton -> setEnabled(true);
        ui -> resetButton -> setEnabled(true);

        qDebug() << "dealer score: " << dealer.getCardSum();
        qDebug() << "player score: " << p1.getCardSum();


        dealer.setBlackJackStateFalse();

        if (p1.getMoney() == 0)
        {
            ui -> betButton -> setEnabled(false);
            ui -> labelCenter -> setStyleSheet(QStringLiteral("QLabel{color: rgb(170, 0, 0);}"));
            ui -> labelCenter -> setText("Game over! :(");
        }

        return;
    }

    // if both the dealer and the player scores 21...
    else if (dealer.getBlackJackState() == true && p1.getBlackJackState() == true)
    {
        ui -> labelCenter -> clear();
        ui -> labelCenter -> setText("Draw!");

        ui -> labelCenter -> setStyleSheet(QStringLiteral("QLabel{color: rgb(10, 170, 255);}"));
        p1.setMoney(p1.getBet(), 1, p1.getDoubleDownState());
        ui -> money_label -> clear();
        ui -> money_label -> setText("$"+QString::number(p1.getMoney()));
        ui -> betEdit -> setMaximum(p1.getMoney());

        ui -> stayButton -> setEnabled(false);
        ui -> hitButton -> setEnabled(false);
        ui -> doubleDownButton -> setEnabled(false);
        ui -> betButton -> setEnabled(true);
        ui -> resetButton -> setEnabled(true);

        qDebug() << "dealer score: " << dealer.getCardSum();
        qDebug() << "player score: " << p1.getCardSum();

        p1.setBlackJackStateFalse();

        dealer.setBlackJackStateFalse();
        return;
    }

    // if the player scores 21 and the dealer does not.
    else if (p1.getBlackJackState() == true && dealer.getBlackJackState() == false)
    {
        ui -> labelCenter -> clear();
        ui -> labelCenter -> setText("Player BlackJack!");

        ui -> labelCenter -> setStyleSheet(QStringLiteral("QLabel{color: rgb(0, 0, 170);}"));
        p1.setMoney(p1.getBet(), 2.5, p1.getDoubleDownState());
        ui -> money_label -> setText("$"+QString::number(p1.getMoney()));
        ui -> betEdit -> setMaximum(p1.getMoney());

        ui -> stayButton -> setEnabled(false);
        ui -> hitButton -> setEnabled(false);
        ui -> doubleDownButton -> setEnabled(false);
        ui -> betButton -> setEnabled(true);
        ui -> resetButton -> setEnabled(true);

        qDebug() << "dealer score: " << dealer.getCardSum();
        qDebug() << "player score: " << p1.getCardSum();

        p1.setBlackJackStateFalse();
        return;
    }

    // if dealer scores between 17 and 21, he has to stay.
    else if (dealer.getCardSum() >= 17 && dealer.getCardSum() <= 21)
    {
        // check who scores more and if player should be awarded.
        if (p1.getCardSum() > dealer.getCardSum())
        {
            ui -> labelCenter -> clear();
            ui -> labelCenter -> setText("Dealer stays and player won!");

            ui -> labelCenter -> setStyleSheet(QStringLiteral("QLabel{color: rgb(0, 0, 170);}"));
            p1.setMoney(p1.getBet(), 2, p1.getDoubleDownState());
            ui -> money_label -> clear();
            ui -> money_label -> setText("$"+QString::number(p1.getMoney()));
            ui -> betEdit -> setMaximum(p1.getMoney());

            ui -> stayButton -> setEnabled(false);
            ui -> hitButton -> setEnabled(false);
            ui -> doubleDownButton -> setEnabled(false);
            ui -> betButton -> setEnabled(true);
            ui -> resetButton -> setEnabled(true);

            qDebug() << "dealer score: " << dealer.getCardSum();
            qDebug() << "player score: " << p1.getCardSum();

            return;
        }

        // if it is a tie...
        else if (p1.getCardSum() == dealer.getCardSum())
        {
            ui -> labelCenter -> clear();
            ui -> labelCenter -> setText("Draw!");

            ui -> labelCenter -> setStyleSheet(QStringLiteral("QLabel{color: rgb(10, 170, 255);}"));
            p1.setMoney(p1.getBet(), 1, p1.getDoubleDownState());
            ui -> money_label -> clear();
            ui -> money_label -> setText("$"+QString::number(p1.getMoney()));
            ui -> betEdit -> setMaximum(p1.getMoney());

            ui -> stayButton -> setEnabled(false);
            ui -> hitButton -> setEnabled(false);
            ui -> doubleDownButton -> setEnabled(false);
            ui -> betButton -> setEnabled(true);
            ui -> resetButton -> setEnabled(true);

            qDebug() << "dealer score: " << dealer.getCardSum();
            qDebug() << "player score: " << p1.getCardSum();

            return;
        }

        // if the dealer scores more than the player.
        else
        {
            ui -> labelCenter -> setStyleSheet(QStringLiteral("QLabel{color: rgb(170, 0, 0);}"));
            ui -> labelCenter -> setText("Dealer stays and dealer won!");
            ui -> stayButton -> setEnabled(false);
            ui -> hitButton -> setEnabled(false);
            ui -> doubleDownButton -> setEnabled(false);

            ui -> betEdit -> setMaximum(p1.getMoney());
            ui -> betButton -> setEnabled(true);
            ui -> resetButton -> setEnabled(true);

            qDebug() << "dealer score: " << dealer.getCardSum();
            qDebug() << "player score: " << p1.getCardSum();


            if (p1.getMoney() == 0)
            {
                ui -> betButton -> setEnabled(false);
                ui -> labelCenter -> setStyleSheet(QStringLiteral("QLabel{color: rgb(170, 0, 0);}"));
                ui -> labelCenter -> setText("Game over! :(");
            }

            return;
        }
    }

    // making the dealer draw cards until one of the conditions are met.
    for (int var = 14; var < 23; ++var)
    {
        dealer.delay(2);
        // ### dealer draws a card
        dealer.setCardString(largeDeck[p1.getCardNo()]);
        if(dealer.cardValue(dealer.getCardString()).value == 11)
        {
            dealer.setAceCount();
        }
        dealer.setCardSum(dealer.cardValue(dealer.getCardString()).value);
        lables_[var] -> setPixmap(dealer.cardValue(dealer.getCardString()).cardImage);
        // ### end of dealer drawing a card.
        media -> play();
        p1.setCardNo(); // player keeps track on how many cards have passed.

        // if dealer scores more than 21 without having an ace, he busts.
        if(dealer.getCardSum() > 21 && dealer.getAceCount() == 0)
        {
            ui -> labelCenter -> setStyleSheet(QStringLiteral("QLabel{color: rgb(0, 0, 170);}"));
            ui -> labelCenter -> setText("Dealer busted!");
            p1.setMoney(p1.getBet(), 2, p1.getDoubleDownState());
            ui -> money_label -> clear();
            ui -> money_label -> setText("$"+QString::number(p1.getMoney()));
            ui -> betEdit -> setMaximum(p1.getMoney());

            ui -> stayButton -> setEnabled(false);
            ui -> hitButton -> setEnabled(false);
            ui -> doubleDownButton -> setEnabled(false);
            ui -> betButton -> setEnabled(true);
            ui -> resetButton -> setEnabled(true);

            qDebug() << "dealer score: " << dealer.getCardSum();
            qDebug() << "player score: " << p1.getCardSum();

            break;
        }

        // if dealer scores more than 21 and has an ace, reuce the hand sum by 10.
        else if (dealer.getCardSum() > 21 && dealer.getAceCount() != 0)
        {
            dealer.setCardSum(-10);
            dealer.reduceAceCount();
        }

        // if dealer scores between 17 and 21, he stays.
        if (dealer.getCardSum() >= 17 && dealer.getCardSum() <= 21)
        {
            // comparing the score between the player and the dealer.
            if (p1.getCardSum() > dealer.getCardSum())
            {
                ui -> labelCenter -> clear();
                ui -> labelCenter -> setText("Dealer stays and player won!");

                ui -> labelCenter -> setStyleSheet(QStringLiteral("QLabel{color: rgb(0, 0, 170);}"));
                p1.setMoney(p1.getBet(), 2, p1.getDoubleDownState());
                ui -> money_label -> clear();
                ui -> money_label -> setText("$"+QString::number(p1.getMoney()));
                ui -> betEdit -> setMaximum(p1.getMoney());

                ui -> stayButton -> setEnabled(false);
                ui -> hitButton -> setEnabled(false);
                ui -> doubleDownButton -> setEnabled(false);
                ui -> betButton -> setEnabled(true);
                ui -> resetButton -> setEnabled(true);
                qDebug() << "dealer score: " << dealer.getCardSum();
                qDebug() << "player score: " << p1.getCardSum();
                break;
            }

            // if the score is equal.
            else if (p1.getCardSum() == dealer.getCardSum())
            {
                ui -> labelCenter -> clear();
                ui -> labelCenter -> setText("Draw!");

                ui -> labelCenter -> setStyleSheet(QStringLiteral("QLabel{color: rgb(10, 170, 255 );}"));
                p1.setMoney(p1.getBet(), 1, p1.getDoubleDownState());
                ui -> money_label -> clear();
                ui -> money_label -> setText("$"+QString::number(p1.getMoney()));
                ui -> betEdit -> setMaximum(p1.getMoney());

                ui -> stayButton -> setEnabled(false);
                ui -> hitButton -> setEnabled(false);
                ui -> doubleDownButton -> setEnabled(false);
                ui -> betButton -> setEnabled(true);
                ui -> resetButton -> setEnabled(true);

                qDebug() << "dealer score: " << dealer.getCardSum();
                qDebug() << "player score: " << p1.getCardSum();

                return;
            }

            else
            {
                ui -> labelCenter -> setStyleSheet(QStringLiteral("QLabel{color: rgb(170, 0, 0);}"));
                ui -> labelCenter -> setText("Dealer stays and dealer won!");
                ui -> stayButton -> setEnabled(false);
                ui -> hitButton -> setEnabled(false);
                ui -> doubleDownButton -> setEnabled(false);
                ui -> betEdit -> setMaximum(p1.getMoney());
                ui -> betButton -> setEnabled(true);
                ui -> resetButton -> setEnabled(true);

                qDebug() << "dealer score: " << dealer.getCardSum();
                qDebug() << "player score: " << p1.getCardSum();

                if (p1.getMoney() == 0)
                {
                    ui -> betButton -> setEnabled(false);
                    ui -> labelCenter -> setStyleSheet(QStringLiteral("QLabel{color: rgb(170, 0, 0);}"));
                    ui -> labelCenter -> setText("Game over! :(");
                }

                break;
            }
        }
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    media -> setVolume(0);
    QApplication::instance() -> quit();
    qDebug() <<"Exited";
    QCoreApplication::instance() -> quit();
    return;
}

// executes, when the "reset" button is pressed.
void MainWindow::on_resetButton_clicked()
{
    MainWindow::shuffle(MainWindow::returnLargeDeck(), 312);
    p1.resetCardSlot();
    p1.resetCardSum();
    p1.resetMoney();
    p1.resetCardNo();
    p1.resetAceCount();
    dealer.resetAceCount();
    MainWindow::cleanLabels();
    ui -> labelCenter -> setText(" ");
    ui -> betEdit -> setMaximum(p1.getMoney());
    ui -> betEdit -> setValue(100);
    ui -> money_label -> setText("$"+QString::number(p1.getMoney()));
    ui -> betButton -> setEnabled(true);
    dealer.resetCardSum();
}

// executes, when the "information" button is pressed.
void MainWindow::on_infoButton_clicked()
{
    information info;
    info.setFixedSize(info.size());
    info.setModal(true);
    info.exec();
}
// executes, when the "double down" button is pressed.
void MainWindow::on_doubleDownButton_clicked()
{
    p1.setDoubleDownStateTrue();
    p1.placeBet(p1.getBet());
    ui -> money_label -> setText("$"+QString::number(p1.getMoney()));

    // if ace is present and "double down" is pressed.
    if (p1.getAceCount() == 1 && p1.getDoubleDownState() == true )
    {
        p1.setCardSum(-10);
        p1.reduceAceCount();
    }

    // if two aces are present and "double down" is pressed, make the score 2.
    else if (p1.getAceCount() == 2 && p1.getDoubleDownState() == true )
    {
        p1.setCardSum(-p1.getCardSum() + 2);
        p1.reduceAceCount();
        p1.reduceAceCount();
    }

    // ### drawing card for player.
    p1.setCardString(largeDeck[p1.getCardNo()]);
    p1.setCardSum(p1.cardValue(p1.getCardString()).value);
    if (p1.cardValue(p1.getCardString()).value == 11)
    {
        p1.setAceCount();
    }
    if (p1.getCardSum() > 21 && p1.getAceCount() != 0)
    {
        p1.setCardSum(-10);
        p1.reduceAceCount();
    }
    ui -> label_doubleDown -> setPixmap(p1.cardValue(p1.getCardString()).cardImage.transformed(matrix.rotate(90)));
    media -> play();
    p1.setCardNo();
    p1.cardValue(p1.getCardString()).cardImage.transformed(matrix.rotate(90));
    // ### end of drawing card for player.

    ui -> stayButton -> setEnabled(false);
    ui -> hitButton -> setEnabled(false);
    ui -> doubleDownButton -> setEnabled(false);

    // bust player if score is more than 21.
    if (p1.getCardSum() > 21)
    {
        ui -> labelCenter -> clear();
        ui -> labelCenter -> setStyleSheet(QStringLiteral("QLabel{color: rgb(170, 0, 0);}"));
        ui -> labelCenter -> setText("Player busted!");

        ui -> betEdit -> setMaximum(p1.getMoney());
        ui -> stayButton -> setEnabled(false);
        ui -> hitButton -> setEnabled(false);
        ui -> doubleDownButton -> setEnabled(false);
        ui -> betButton -> setEnabled(true);
        ui -> resetButton -> setEnabled(true);

        dealer.resetAceCount();
        dealer.setBlackJackStateFalse();
        p1.resetAceCount();

        if (p1.getMoney() == 0)
        {
            ui -> betButton -> setEnabled(false);
            ui -> labelCenter -> setStyleSheet(QStringLiteral("QLabel{color: rgb(170, 0, 0);}"));
            ui -> labelCenter -> setText("Game over! :(");
        }
    }
    // if ace is draw...
    if (p1.getAceCount() == 1 && p1.getCardSum() > 21)
    {
        p1.setCardSum(-10);
        p1.reduceAceCount();
    }

    else if (p1.getAceCount() == 2 && p1.getCardSum() > 21)
    {
        p1.setCardSum(-20);
        p1.resetAceCount();
    }
    p1.delay(1);
    ui -> stayButton -> clicked();
    p1.setDoubleDownStateFalse();

}
