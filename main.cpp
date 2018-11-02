#include "mainwindow.h"
#include <QApplication>
#include <QString>
#include "player.h"


#include <QtDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QCoreApplication::setApplicationName("Black Jack v1.0");
    qApp->setWindowIcon(QIcon(":/resources/diamond.PNG"));
    MainWindow w;
    //w.setFixedSize(w.size());

    w.show();
    return app.exec();
}
