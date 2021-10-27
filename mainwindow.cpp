#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//  Pythagoras

    QPixmap pythagoras(":/Pictures/Pictures/pythagoras.png");
    ui->Pythagoras_3->setPixmap(pythagoras.scaled(322,257,Qt::KeepAspectRatio));

//  Trigonometry

    QPixmap sine(":/Pictures/Pictures/Sine.jpg");
    ui->sine->setPixmap(sine.scaled(379,133,Qt::KeepAspectRatio));

    QPixmap cosine(":/Pictures/Pictures/Cosine.jpg");
    ui->cosine->setPixmap(cosine.scaled(375,134,Qt::KeepAspectRatio));

    QPixmap tangent(":/Pictures/Pictures/Tangent.jpg");
    ui->tangent->setPixmap(tangent.scaled(284,177,Qt::KeepAspectRatio));

    QPixmap cotangent(":/Pictures/Pictures/Cotangent.jpg");
    ui->cotangent->setPixmap(cotangent.scaled(285,177,Qt::KeepAspectRatio));

//  R/I/U
    ui->comboBox->addItem("U");
    ui->comboBox->addItem("I");
    ui->comboBox->addItem("R");

    QPixmap electro(":/Pictures/Pictures/ohm2.png");
    ui->electro->setPixmap(electro.scaled(1111,445,Qt::KeepAspectRatio));


}

MainWindow::~MainWindow()
{
    delete ui;
}


