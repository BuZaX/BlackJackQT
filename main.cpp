#include "mainwindow.h"
#include <QApplication>
#include <QString>
#include "player.h"

#include <QtDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;

    w.show();


    return app.exec();
}
