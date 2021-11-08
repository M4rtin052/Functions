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

    connect(ui->CalculateP, SIGNAL(clicked()), this, SLOT(firstClick()));
    connect(ui->ResetP, SIGNAL(clicked()), this, SLOT(resetP()));

    connect(ui->CalculateP_4, SIGNAL(clicked()), this, SLOT(firstClick_4()));
    connect(ui->ResetP_4, SIGNAL(clicked()), this, SLOT(resetP_4()));

    connect(ui->CalculateP_3, SIGNAL(clicked()), this, SLOT(firstClick_3()));
    connect(ui->ResetP_3, SIGNAL(clicked()), this, SLOT(resetP_3()));
//  Trigonometry

    QPixmap sine(":/Pictures/Pictures/Sine.jpg");
    ui->sine->setPixmap(sine.scaled(379,133));

    QPixmap cosine(":/Pictures/Pictures/Cosine.jpg");
    ui->cosine->setPixmap(cosine.scaled(375,134));

    QPixmap tangent(":/Pictures/Pictures/Tangent.jpg");
    ui->tangent->setPixmap(tangent.scaled(284,177));

    QPixmap cotangent(":/Pictures/Pictures/Cotangent.jpg");
    ui->cotangent->setPixmap(cotangent.scaled(285,177));

// Circle

    QPixmap label_2(":/Pictures/Pictures/Circle_obw.png");
    ui->label_2->setPixmap(label_2.scaled(233,126));

    QPixmap label_8(":/Pictures/Pictures/Circle_pol.png");
    ui->label_8->setPixmap(label_8.scaled(258,127));

    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(pushButton_7()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(pushButton_8()));

//  R/I/U

    QPixmap electro(":/Pictures/Pictures/ohm2.png");
    ui->electro->setPixmap(electro.scaled(1111,445));

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(pushButton()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(pushButton_2()));

    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(pushButton_5()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(pushButton_6()));

    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(pushButton_3()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(pushButton_4()));

}

// Pythagoras
void MainWindow::firstClick()
{
    double mult1 = (ui->firstBox->value() * ui->firstBox->value());
    double mult2 = (ui->secondBox->value() * ui->secondBox->value());
    double result1 = mult1 + mult2;
    qreal result = result1;
    qreal final = qSqrt(result);
    ui->label->setText(QString::number(final));
}

void MainWindow::resetP()
{
    ui->firstBox->setValue(0);
    ui->secondBox->setValue(0);
    ui->label->setText(QString::number(0));
}

void MainWindow::firstClick_4()
{
    double mult1 = (ui->thirdBox->value() * ui->thirdBox->value());
    double mult2 = (ui->fourthBox->value() * ui->fourthBox->value());
    double result1 = mult2 - mult1;
    qreal result = result1;
    qreal final = qSqrt(result);
    ui->label_4->setText(QString::number(final));
}

void MainWindow::resetP_4()
{
    ui->thirdBox->setValue(0);
    ui->fourthBox->setValue(0);
    ui->label_4->setText(QString::number(0));
}
void MainWindow::firstClick_3()
{
    double mult1 = (ui->fifthBox->value() * ui->fifthBox->value());
    double mult2 = (ui->sixthBox->value() * ui->sixthBox->value());
    double result1 = mult2 - mult1;
    qreal result = result1;
    qreal final = qSqrt(result);
    ui->label_3->setText(QString::number(final));
}

void MainWindow::resetP_3()
{
    ui->fifthBox->setValue(0);
    ui->sixthBox->setValue(0);
    ui->label_3->setText(QString::number(0));
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

// Circle

void MainWindow::pushButton_7()
{
    double field = M_PI * ui->doubleSpinBox->value() * ui->doubleSpinBox->value();
    double obw = 2 * M_PI * ui->doubleSpinBox->value();
    ui->label_9->setText(QString::number(obw));
    ui->label_10->setText(QString::number(field));
}

void MainWindow::pushButton_8()
{
    ui->doubleSpinBox->setValue(0);
    ui->label_9->setText(QString::number(0));
    ui->label_10->setText(QString::number(0));
}

// R/I/U

void MainWindow::pushButton()
{
    if (ui->doubleSpinBox_2->value() == 0)
    {
        ui->label_5->setText("! ! ! Nie dziel przez 0 ! ! !");
    }
    else
    {
        double res = ui->tension->value() / ui->doubleSpinBox_2->value();
        ui->label_5->setText(QString::number(res));
    }
}

void MainWindow:: pushButton_2()
{
    ui->tension->setValue(0);
    ui->doubleSpinBox_2->setValue(0);
    ui->label_5->setText(QString::number(0));
}

void MainWindow::pushButton_5()
{
    double res = ui->intensity->value() * ui->doubleSpinBox_8->value();
    ui->label_6->setText(QString::number(res));
}

void MainWindow::pushButton_6()
{
    ui->intensity->setValue(0);
    ui->doubleSpinBox_8->setValue(0);
    ui->label_6->setText(QString::number(0));
}

void MainWindow::pushButton_3()
{
    if (ui->doubleSpinBox_5->value() == 0)
    {
        ui->label_7->setText("! ! ! Nie dziel przez 0 ! ! !");
    }
    else
    {
        double res = ui->tension2->value() / ui->doubleSpinBox_5->value();
        ui->label_7->setText(QString::number(res));
    }
}
void MainWindow::pushButton_4()
{
    ui->tension2->setValue(0);
    ui->doubleSpinBox_5->setValue(0);
    ui->label_7->setText(QString::number(0));
}

MainWindow::~MainWindow()
{
    delete ui;
}


