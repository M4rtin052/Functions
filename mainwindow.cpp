#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>
#include <QDoubleSpinBox>
#include <QtMath>
#include <QFile>
#include <QTextStream>
#include <cmath>

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
double MainWindow::firstClick_math(double a, double b)
{
    double lengthC = (a*a) + (b*b);
    qreal result = lengthC;
    qreal final = qSqrt(result);
    return final;
}
void MainWindow::firstClick()
{
    double c = firstClick_math(ui->firstBox->value(), ui->secondBox->value());
    double b = firstClick_4_math(ui->thirdBox->value(), ui->fourthBox->value());
    double a = firstClick_3_math(ui->fifthBox->value(), ui->sixthBox->value());
    ui->label->setText(QString::number(c)); // wyświetlenie w tabelce z wynikiem wartości obliczonej z funkcji "firstClick_math"
    // Dalej w dół jest zapis do pliku, więc tego już nie musisz sprawdzać
    QFile::remove("Results.txt");
    QFile file("Results.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
    {
        QTextStream results(&file);
        results << "c = " << c << "\n" << "b = " << b << "\n" << "a = " << a << "\n";

        file.close();
        qDebug() << "Writing finished";
    }
}

void MainWindow::resetP()
{
    ui->firstBox->setValue(0);
    ui->secondBox->setValue(0);
    ui->label->setText(QString::number(0));
}

double MainWindow::firstClick_4_math(double a, double c)
{
    double lengthB = (c*c) - (a*a);
    qreal result = lengthB;
    qreal final = qSqrt(result);
    return final;
}

void MainWindow::firstClick_4()
{
    double c = firstClick_math(ui->firstBox->value(), ui->secondBox->value());
    double b = firstClick_4_math(ui->thirdBox->value(), ui->fourthBox->value());
    double a = firstClick_3_math(ui->fifthBox->value(), ui->sixthBox->value());
    ui->label_4->setText(QString::number(b));
    QFile::remove("Results.txt");
    QFile file("Results.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
    {
        QTextStream results(&file);
        results << "c = " << c << "\n" << "b = " << b << "\n" << "a = " << a << "\n";

        file.close();
        qDebug() << "Writing finished";
    }
}

void MainWindow::resetP_4()
{
    ui->thirdBox->setValue(0);
    ui->fourthBox->setValue(0);
    ui->label_4->setText(QString::number(0));
}

double MainWindow::firstClick_3_math(double b, double c)
{
    double lengthC = (c*c) - (b*b);
    qreal result = lengthC;
    qreal final = qSqrt(result);
    return final;
}

void MainWindow::firstClick_3()
{
    double c = firstClick_math(ui->firstBox->value(), ui->secondBox->value());
    double b = firstClick_4_math(ui->thirdBox->value(), ui->fourthBox->value());
    double a = firstClick_3_math(ui->fifthBox->value(), ui->sixthBox->value());
    ui->label_3->setText(QString::number(a));
    QFile::remove("Results.txt");
    QFile file("Results.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
    {
        QTextStream results(&file);
        results << "c = " << c << "\n" << "b = " << b << "\n" << "a = " << a << "\n";

        file.close();
        qDebug() << "Writing finished";
    }
}

void MainWindow::resetP_3()
{
    ui->fifthBox->setValue(0);
    ui->sixthBox->setValue(0);
    ui->label_3->setText(QString::number(0));
}


// Trigonometry
double MainWindow::sine_math(double value)
{
    double deg = value;
    double rad = qDegreesToRadians(deg);
    qreal sine = rad;
    qreal sineRes = qSin(sine);
    sineRes *= 100;
    sineRes = qRound(sineRes);
    sineRes /= 100;
    return sineRes;
}
double MainWindow::cosine_math(double value)
{
    double deg = value;
    double rad = qDegreesToRadians(deg);
    qreal cosine = rad;
    qreal cosineRes = qCos(cosine);
    cosineRes *= 100;
    cosineRes = qRound(cosineRes);
    cosineRes /= 100;
    return cosineRes;
}
double MainWindow::tang_math(double value)
{
    double deg = value;
    double rad = qDegreesToRadians(deg);
    qreal tan = rad;
    qreal tanRes = qTan(tan);
    return tanRes;
}
double MainWindow::cotang_math(double value)
{
    double deg = value;
    double rad = qDegreesToRadians(deg);
    qreal cotan = rad;
    qreal cotanRes = (1 / qTan(cotan));
    return cotanRes;
}
double MainWindow::on_Degrees_valueChanged(double value)
{
    double x = sine_math(value);
    double c = cosine_math(value);
    double b = tang_math(value);
    double a = cotang_math(value);

    // Sine
        ui->sineRes->setText(QString::number(x));
        QFile::remove("Results.txt");
        QFile sine("Results.txt");
        if (sine.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
        {
            QTextStream results(&sine);
            results << "sine = " << x << "\n" << "cosine = " << c << "\n" << "tangen = " << b << "\n" << "cotangen = " << a << "\n";

            sine.close();
            qDebug() << "Writing finished";
        }


    // Cosine
        ui->cosRes->setText(QString::number(c));
        QFile::remove("Results.txt");
        QFile cosine("Results.txt");
        if (cosine.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
        {
            QTextStream results(&cosine);
            results << "sine = " << x << "\n" << "cosine = " << c << "\n" << "tangen = " << b << "\n" << "cotangen = " << a << "\n";

            cosine.close();
            qDebug() << "Writing finished";
        }

    // Tangent
        double reszta = fmod(value, 90);
        double reszta1 = fmod ((value / 90), 2);
        if (reszta == 0)
        {
            if (reszta1 == 0)
            {
                ui->tanRes->setText(QString::number(0));
                ui->cotanRes->setText("Cotangent doesn't exist");
                return 0;
            }
            else
            {
                ui->tanRes->setText("Tangent doesn't exist");
                ui->cotanRes->setText(QString::number(0));
                return 0;
            }
        }
        else
        {
            ui->tanRes->setText(QString::number(b, 'f', 2));
            ui->cotanRes->setText(QString::number(a, 'f', 2));
            return 0;
        }
        QFile::remove("Results.txt");
        QFile tang("Results.txt");
        if (tang.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
        {
            QTextStream results(&tang);
            results << "sine = " << x << "\n" << "cosine = " << c << "\n" << "tangen = " << b << "\n" << "cotangen = " << a << "\n";

            tang.close();
            qDebug() << "Writing finished";
        }

    // Cotangent
        QFile::remove("Results.txt");
        QFile file("Results.txt");
        if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
        {
            QTextStream results(&file);
            results << "sine = " << x << "\n" << "cosine = " << c << "\n" << "tangen = " << b << "\n" << "cotangen = " << a << "\n";

            file.close();
            qDebug() << "Writing finished";
        }
}


// Circle
double MainWindow::circle_field(double a)
{
    double field = M_PI * a * a;
    return field;
}
double MainWindow::circle_obw(double b)
{
    double obw = 2 * M_PI * b;
    return obw;
}
void MainWindow::pushButton_7()
{
    double field = circle_field(ui->doubleSpinBox->value());
    double obw = circle_obw(ui->doubleSpinBox->value());
    ui->label_9->setText(QString::number(obw));
    ui->label_10->setText(QString::number(field));
    QFile::remove("Results.txt");
    QFile file("Results.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
    {
        QTextStream results(&file);
        results << "Field = " << field << "\n" << "Obw = " << obw << "\n";

        file.close();
        qDebug() << "Writing finished";
    }
}

void MainWindow::pushButton_8()
{
    ui->doubleSpinBox->setValue(0);
    ui->label_9->setText(QString::number(0));
    ui->label_10->setText(QString::number(0));
}

// R/I/U
double MainWindow::R_math(double u, double r)
{
    double res = u / r;
    return res;
}
void MainWindow::pushButton()
{
    if (ui->doubleSpinBox_2->value() == 0)
    {
        ui->label_5->setText("! ! ! Nie dziel przez 0 ! ! !");
    }
    else
    {
        double res = R_math(ui->tension->value(), ui->doubleSpinBox_2->value());
        double inten = I_math(ui->intensity->value(), ui->doubleSpinBox_8->value());
        double elect = U_math(ui->tension2->value(), ui->doubleSpinBox_5->value());
        ui->label_5->setText(QString::number(res));
        QFile::remove("Results.txt");
        QFile file("Results.txt");
        if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
        {
            QTextStream results(&file);
            results << "R = " << res << "\n" << "I = " << inten << "\n" << "U = " << elect << "\n";

            file.close();
            qDebug() << "Writing finished";
        }
    }
}
void MainWindow:: pushButton_2()
{
    ui->tension->setValue(0);
    ui->doubleSpinBox_2->setValue(0);
    ui->label_5->setText(QString::number(0));
}


double MainWindow::I_math(double i, double r)
{
    double res = i * r;
    return res;
}
void MainWindow::pushButton_5()
{
    double res = R_math(ui->tension->value(), ui->doubleSpinBox_2->value());
    double inten = I_math(ui->intensity->value(), ui->doubleSpinBox_8->value());
    double elect = U_math(ui->tension2->value(), ui->doubleSpinBox_5->value());
    ui->label_6->setText(QString::number(inten));
    QFile::remove("Results.txt");
    QFile file("Results.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
    {
        QTextStream results(&file);
        results << "R = " << res << "\n" << "I = " << inten << "\n" << "U = " << elect << "\n";

        file.close();
        qDebug() << "Writing finished";
    }
}

void MainWindow::pushButton_6()
{
    ui->intensity->setValue(0);
    ui->doubleSpinBox_8->setValue(0);
    ui->label_6->setText(QString::number(0));
}


double MainWindow::U_math(double u, double i)
{
    double res = u / i;
    return res;
}
void MainWindow::pushButton_3()
{
    if (ui->doubleSpinBox_5->value() == 0)
    {
        ui->label_7->setText("! ! ! Nie dziel przez 0 ! ! !");
    }
    else
    {
        double res = R_math(ui->tension->value(), ui->doubleSpinBox_2->value());
        double inten = I_math(ui->intensity->value(), ui->doubleSpinBox_8->value());
        double elect = U_math(ui->tension2->value(), ui->doubleSpinBox_5->value());
        ui->label_7->setText(QString::number(elect));
        QFile::remove("Results.txt");
        QFile file("Results.txt");
        if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
        {
            QTextStream results(&file);
            results << "R = " << res << "\n" << "I = " << inten << "\n" << "U = " << elect << "\n";

            file.close();
            qDebug() << "Writing finished";
        }

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
