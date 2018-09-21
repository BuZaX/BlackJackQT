#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void shuffle(QString deck1[], int len);
    QString* returnLargeDeck();


private slots:


    void on_hitButton_clicked();

private:
    Ui::MainWindow *ui;
    QString largeDeck[312];
};

#endif // MAINWINDOW_H
