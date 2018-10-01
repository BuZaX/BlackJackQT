#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void cleanLabels();

    void shuffle(QString deck1[], int len);
    QString* returnLargeDeck();
    void closeEvent(QCloseEvent *event);
    QPixmap pix;
    void keyPressEvent(QKeyEvent *event);



private slots:


    void on_hitButton_clicked();

    void on_betButton_clicked();

    void on_stayButton_clicked();

    void on_resetButton_clicked();

    void on_infoButton_clicked();

private:
    Ui::MainWindow *ui;
    QString largeDeck[312];
};

#endif // MAINWINDOW_H
