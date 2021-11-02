#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>
#include <QDoubleSpinBox>
#include <QtMath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//  Pythagoras

    QPixmap pythagoras(":/Pictures/Pictures/pythagoras.png");
    ui->Pythagoras_3->setPixmap(pythagoras.scaled(322,257));

//  Trigonometry

    QPixmap sine(":/Pictures/Pictures/Sine.jpg");
    ui->sine->setPixmap(sine.scaled(379,133));

    QPixmap cosine(":/Pictures/Pictures/Cosine.jpg");
    ui->cosine->setPixmap(cosine.scaled(375,134));

    QPixmap tangent(":/Pictures/Pictures/Tangent.jpg");
    ui->tangent->setPixmap(tangent.scaled(284,177));

    QPixmap cotangent(":/Pictures/Pictures/Cotangent.jpg");
    ui->cotangent->setPixmap(cotangent.scaled(285,177));

//  R/I/U

    QPixmap electro(":/Pictures/Pictures/ohm2.png");
    ui->electro->setPixmap(electro.scaled(1111,445));

}
// Pythagoras

void MainWindow::on_firstBox_valueChanged(double value)
{
    double mult1 = value * value;
    double mult2 = (ui->secondBox->value() * ui->secondBox->value());
    double result1 = mult1 + mult2;
    qreal result = result1;
    qreal final = qSqrt(result);
    ui->label->setText(QString::number(final));
}

void MainWindow::on_thirdBox_valueChanged(double value)
{
    double mult1 = value * value;
    double mult2 = (ui->fourthBox->value() * ui->fourthBox->value());
    double result1 = mult2 - mult1;
    qreal result = result1;
    qreal final = qSqrt(result);
    ui->label_4->setText(QString::number(final));
}

void MainWindow::on_fifthBox_valueChanged(double value)
{
    double mult1 = value * value;
    double mult2 = (ui->sixthBox->value() * ui->sixthBox->value());
    double result1 = mult2 - mult1;
    qreal result = result1;
    qreal final = qSqrt(result);
    ui->label_3->setText(QString::number(final));
}

// Trigonometry

void MainWindow::on_Degrees_valueChanged(double value)
{
    double deg = value;
    double rad = qDegreesToRadians(deg);

// Sine
    if (value == 0 || value == 180 || value == 360)
    {
        ui->sineRes->setText("0");
    }
    else
    {
        qreal sine = rad;
        qreal sineRes = qSin(sine);
        ui->sineRes->setText(QString::number(sineRes));
    }

// Cosine
    if (value == 90 || value == 270 || value == 450)
    {
        ui->cosRes->setText("0");
    }
    else
    {
        qreal cosine = rad;
        qreal cosineRes = qCos(cosine);
        ui->cosRes->setText(QString::number(cosineRes));
    }

// Tangent
    if (value == 90 || value == 270 || value == 450)
    {
        ui->tanRes->setText("Tangent doesn't exist.");
    }
    else if (value == 0 || value == 180 || value == 360)
    {
        ui->tanRes->setText("0");
    }
    else
    {
        qreal tan = rad;
        qreal tanRes = qTan(tan);
        ui->tanRes->setText(QString::number(tanRes));
    }

// Cotangent
    if (value == 0 || value == 180 || value == 360)
    {
        ui->cotanRes->setText("Cotangent doesn't exist.");
    }
    else if (value == 90 || value == 270 || value == 450)
    {
        ui->cotanRes->setText("0");
    }
    else
    {
        qreal cotan = rad;
        qreal cotanRes = (1 / qTan(cotan));
        ui->cotanRes->setText(QString::number(cotanRes));
    }
}

// R/I/U

void MainWindow::on_tension_valueChanged(double value)
{
    double res = value / ui->doubleSpinBox_2->value();
    ui->label_5->setText(QString::number(res));
}
void MainWindow::on_intensity_valueChanged(double value)
{
    double res = value * ui->doubleSpinBox_8->value();
    ui->label_6->setText(QString::number(res));
}
void MainWindow::on_tension2_valueChanged(double value)
{
    double res = value / ui->doubleSpinBox_5->value();
    ui->label_7->setText(QString::number(res));
}

MainWindow::~MainWindow()
{
    delete ui;
}


