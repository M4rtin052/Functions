#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    double firstClick_math(double a, double b);
    double firstClick_4_math(double a, double c);
    double firstClick_3_math(double b, double c);

    double sine_math(double value);
    double cosine_math(double value);
    double tang_math(double value);
    double cotang_math(double value);

    double circle_field(double a);
    double circle_obw(double b);

    double R_math(double u, double r);
    double I_math(double i, double r);
    double U_math(double u, double i);
    // Pythagoras
    void firstClick();
    void resetP();
    void firstClick_4();
    void resetP_4();
    void firstClick_3();
    void resetP_3();

    // Trigonometry
    double on_Degrees_valueChanged(double value);

    // Circle
    void pushButton_7();
    void pushButton_8();

    // R/I/U
    void pushButton();
    void pushButton_2();
    void pushButton_5();
    void pushButton_6();
    void pushButton_3();
    void pushButton_4();


private:
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
