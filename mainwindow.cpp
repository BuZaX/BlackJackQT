#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "player.h"
#include "information.h"
#include <QLabel>
#include <QPixmap>
#include <QDebug>
#include <QMediaPlayer>
#include <QKeyEvent>

Player p1;
Player dealer;
QMediaPlayer* media = new QMediaPlayer;
QLabel* lables_[24];


void MainWindow::cleanLabels()
{
    for (int var = 0; var < 24; ++var)
    {
        lables_[var] -> clear();
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event -> key() == Qt::Key_Return && ui -> hitButton -> isEnabled() == true)
    {
        qDebug() << "Enter clicked";
        ui -> hitButton -> clicked();
    }

    else if (event -> key() == Qt::Key_S && ui -> stayButton -> isEnabled() == true)
    {
        qDebug() << "s clicked";
        ui -> stayButton -> clicked();
    }

    else if (event -> key() == Qt::Key_B && ui -> betButton -> isEnabled() == true)
    {
        ui -> betButton -> clicked();
        qDebug() << "b clicked";
    }
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui -> betButton -> setEnabled(true);
    ui -> hitButton -> setEnabled(false);
    ui -> stayButton -> setEnabled(false);

    ui -> betEdit -> clearFocus();

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

    QString cards[52] = {"2s", "3s", "4s", "5s", "6s", "7s", "8s", "9s", "10s", "Js", "Qs", "Ks", "As", "2h", "3h", "4h", "5h", "6h", "7h", "8h", "9h", "10h", "Jh", "Qh", "Kh", "Ah","2c", "3c", "4c", "5c", "6c", "7c", "8c", "9c", "10c", "Jc", "Qc", "Kc", "Ac","2d", "3d", "4d", "5d", "6d", "7d", "8d", "9d", "10d", "Jd", "Qd", "Kd", "Ad"};
    ui -> labelBackground -> lower();


    int copies = 6;
        for (int i = 0; i < 52*copies; i++)
        {
         largeDeck[i] = cards[i%52];
        }

    shuffle(largeDeck, 312);

//        largeDeck[0] = "2d";
//        largeDeck[1] = "Ks";
//        largeDeck[2] = "2s";
//        largeDeck[3] = "4d";
//        largeDeck[4] = "2s";
//        largeDeck[5] = "2c";
//        largeDeck[6] = "2c";
//        largeDeck[7] = "2c";
//        largeDeck[8] = "Ac";
//        largeDeck[9] = "Ac";
//        largeDeck[10] = "Ad";
//        largeDeck[11] = "Ad";
//        largeDeck[12] = "Ad";
//        largeDeck[13] = "As";

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
    media -> play();
    ui -> resetButton -> setEnabled(false);

    p1.setCardString(largeDeck[p1.getCardNo()]);
    p1.setCardSum(p1.cardValue(p1.getCardString()).value);
    lables_[p1.getCardSlot()] -> setPixmap(p1.cardValue(p1.getCardString()).cardImage);
    media -> play();
    p1.setCardNo();
    p1.setCardSlot();

    if (p1.getCardSum() <= 21)
    {

    }

    else if (p1.getCardSum() > 21 && p1.cardValue(p1.getCardString()).value != 11)
    {
        ui -> labelCenter -> clear();
        ui -> labelCenter -> setStyleSheet(QStringLiteral("QLabel{color: rgb(170, 0, 0);}"));
        ui -> labelCenter -> setText("Player busted!");

        ui -> betEdit -> setMaximum(p1.getMoney());
        ui -> stayButton -> setEnabled(false);
        ui -> hitButton -> setEnabled(false);
        ui -> betButton -> setEnabled(true);
        ui -> resetButton -> setEnabled(true);

        if (p1.getMoney() == 0)
        {
            ui -> betButton -> setEnabled(false);
            ui -> labelCenter -> setStyleSheet(QStringLiteral("QLabel{color: rgb(170, 0, 0);}"));
            ui -> labelCenter -> setText("Game over! :(");
        }

    }

    else
    {
        p1.setCardSum(-10);

        if (p1.getCardSum() > 21)
        {
            ui -> labelCenter -> clear();
            ui -> labelCenter -> setText("Player busted!");

            ui -> betEdit -> setMaximum(p1.getMoney());
            ui -> stayButton -> setEnabled(false);
            ui -> hitButton -> setEnabled(false);
            ui -> betButton -> setEnabled(true);
            ui -> resetButton -> setEnabled(true);

            if (p1.getMoney() == 0)
            {
                ui -> betButton -> setEnabled(false);
                ui -> labelCenter -> setStyleSheet(QStringLiteral("QLabel{color: rgb(170, 0, 0);}"));
                ui -> labelCenter -> setText("Game over! :(");
            }


        }
    }

}

void MainWindow::on_betButton_clicked()
{

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
    p1.resetCardSum();
    p1.resetCardSlot();

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

        p1.setCardString(largeDeck[p1.getCardNo()]);
        p1.setCardSum(p1.cardValue(p1.getCardString()).value);
        ui -> label1 -> setPixmap(p1.cardValue(p1.getCardString()).cardImage);
        media -> play();
        p1.setCardNo();

        dealer.setCardString(largeDeck[p1.getCardNo()]);
        dealer.setCardSum(dealer.cardValue(dealer.getCardString()).value);
        ui -> label11 -> setPixmap(dealer.cardValue(dealer.getCardString()).cardImage);
        p1.setCardNo();

        p1.setCardString(largeDeck[p1.getCardNo()]);
        p1.setCardSum(p1.cardValue(p1.getCardString()).value);
        ui -> label2 -> setPixmap(p1.cardValue(p1.getCardString()).cardImage);
        p1.setCardNo();

        dealer.setCardString(largeDeck[p1.getCardNo()]);
        dealer.setCardSum(dealer.cardValue(dealer.getCardString()).value);
        ui -> label22 -> setPixmap(pix);
        p1.setCardNo();

        if (p1.getCardSum() == 21)
        {
            ui -> labelCenter -> clear();
            ui -> labelCenter -> setText("Player BlackJack!");

            ui -> labelCenter -> setStyleSheet(QStringLiteral("QLabel{color: rgb(0, 0, 170);}"));
            p1.setMoney(p1.getBet(), 2.5);
            ui -> money_label -> setText("$"+QString::number(p1.getMoney()));
            ui -> betEdit -> setMaximum(p1.getMoney());

            ui -> stayButton -> setEnabled(false);
            ui -> hitButton -> setEnabled(false);
            ui -> betButton -> setEnabled(true);
            ui -> resetButton -> setEnabled(true);
            return;
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

void MainWindow::on_stayButton_clicked()
{

    ui -> resetButton -> setEnabled(false);
    ui -> hitButton -> setEnabled(false);
    ui -> betButton -> setEnabled(false);
    ui -> stayButton -> setEnabled(false);

    ui -> label22 -> clear();
    ui -> label22 -> setPixmap(dealer.cardValue(dealer.getCardString()).cardImage);

    if (dealer.getCardSum() == 21)
    {
        ui -> labelCenter -> setStyleSheet(QStringLiteral("QLabel{color: rgb(170, 0, 0);}"));
        ui -> labelCenter -> setText("Dealer BlackJack!");

        ui -> stayButton -> setEnabled(false);
        ui -> hitButton -> setEnabled(false);
        ui -> betButton -> setEnabled(true);
        ui -> resetButton -> setEnabled(true);

        if (p1.getMoney() == 0)
        {
            ui -> betButton -> setEnabled(false);
            ui -> labelCenter -> setStyleSheet(QStringLiteral("QLabel{color: rgb(170, 0, 0);}"));
            ui -> labelCenter -> setText("Game over! :(");
        }

        return;
    }

    else if (dealer.getCardSum() >= 17 && dealer.getCardSum() <= 21)
    {
        if (p1.getCardSum() > dealer.getCardSum())
        {
            ui -> labelCenter -> clear();
            ui -> labelCenter -> setText("Dealer stays and player won!");

            ui -> labelCenter -> setStyleSheet(QStringLiteral("QLabel{color: rgb(0, 0, 170);}"));
            p1.setMoney(p1.getBet(), 2);
            ui -> money_label -> clear();
            ui -> money_label -> setText("$"+QString::number(p1.getMoney()));
            ui -> betEdit -> setMaximum(p1.getMoney());

            ui -> stayButton -> setEnabled(false);
            ui -> hitButton -> setEnabled(false);
            ui -> betButton -> setEnabled(true);
            ui -> resetButton -> setEnabled(true);
            return;
        }

        else
        {
            ui -> labelCenter -> setStyleSheet(QStringLiteral("QLabel{color: rgb(170, 0, 0);}"));
            ui -> labelCenter -> setText("Dealer stays and dealer won!");
            ui -> stayButton -> setEnabled(false);
            ui -> hitButton -> setEnabled(false);

            ui -> betEdit -> setMaximum(p1.getMoney());
            ui -> betButton -> setEnabled(true);
            ui -> resetButton -> setEnabled(true);

            if (p1.getMoney() == 0)
            {
                ui -> betButton -> setEnabled(false);
                ui -> labelCenter -> setStyleSheet(QStringLiteral("QLabel{color: rgb(170, 0, 0);}"));
                ui -> labelCenter -> setText("Game over! :(");
            }


            return;
        }

    }

    for (int var = 14; var < 23; ++var)
    {
        dealer.delay(2);

        dealer.setCardString(largeDeck[p1.getCardNo()]);
        dealer.setCardSum(dealer.cardValue(dealer.getCardString()).value);
        lables_[var] -> setPixmap(dealer.cardValue(dealer.getCardString()).cardImage);
        media -> play();
        p1.setCardNo();

        if(dealer.getCardSum() > 21 && dealer.cardValue(dealer.getCardString()).value != 11)
        {
            ui -> labelCenter -> setStyleSheet(QStringLiteral("QLabel{color: rgb(0, 0, 170);}"));
            ui -> labelCenter -> setText("Dealer busted!");
            p1.setMoney(p1.getBet(), 2);
            ui -> money_label -> clear();
            ui -> money_label -> setText("$"+QString::number(p1.getMoney()));
            ui -> betEdit -> setMaximum(p1.getMoney());

            ui -> stayButton -> setEnabled(false);
            ui -> hitButton -> setEnabled(false);
            ui -> betButton -> setEnabled(true);
            ui -> resetButton -> setEnabled(true);
            break;
        }

        else if (dealer.getCardSum() > 21 && dealer.cardValue(dealer.getCardString()).value == 11)
        {
            dealer.setCardSum(-10);
        }

        if (dealer.getCardSum() >= 17 && dealer.getCardSum() <= 21)
        {
            if (p1.getCardSum() > dealer.getCardSum())
            {
                ui -> labelCenter -> clear();
                ui -> labelCenter -> setText("Dealer stays and player won!");

                ui -> labelCenter -> setStyleSheet(QStringLiteral("QLabel{color: rgb(0, 0, 170);}"));
                p1.setMoney(p1.getBet(), 2);
                ui -> money_label -> clear();
                ui -> money_label -> setText("$"+QString::number(p1.getMoney()));
                ui -> betEdit -> setMaximum(p1.getMoney());

                ui -> stayButton -> setEnabled(false);
                ui -> hitButton -> setEnabled(false);
                ui -> betButton -> setEnabled(true);
                ui -> resetButton -> setEnabled(true);
                break;
            }

            else
            {
                ui -> labelCenter -> setStyleSheet(QStringLiteral("QLabel{color: rgb(170, 0, 0);}"));
                ui -> labelCenter -> setText("Dealer stays and dealer won!");
                ui -> stayButton -> setEnabled(false);
                ui -> hitButton -> setEnabled(false);
                ui -> betEdit -> setMaximum(p1.getMoney());
                ui -> betButton -> setEnabled(true);
                ui -> resetButton -> setEnabled(true);

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

void MainWindow::on_resetButton_clicked()
{
    MainWindow::shuffle(MainWindow::returnLargeDeck(), 312);
    p1.resetCardSlot();
    p1.resetCardSum();
    p1.resetMoney();
    p1.resetCardNo();
    MainWindow::cleanLabels();
    ui -> labelCenter -> setText(" ");
    ui -> betEdit -> setMaximum(p1.getMoney());
    ui -> betEdit -> setValue(100);
    ui -> money_label -> setText("$"+QString::number(p1.getMoney()));
    ui -> betButton -> setEnabled(true);
    dealer.resetCardSum();
}

void MainWindow::on_infoButton_clicked()
{
    information info;
    info.setFixedSize(info.size());
    info.setModal(true);
    info.exec();
}
