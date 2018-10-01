#include "information.h"
#include "ui_information.h"

information::information(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::information)
{
    ui->setupUi(this);
    ui -> label_3 -> setStyleSheet("QLabel { color : blue; }");
}

information::~information()
{
    delete ui;
}
