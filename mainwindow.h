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
    // Pythagoras
    void on_firstBox_valueChanged(double value);
    void on_thirdBox_valueChanged(double value);
    void on_fifthBox_valueChanged(double value);
    // Trigonometry
    void on_Degrees_valueChanged(double value);
    // R/I/U
    void on_intensity_valueChanged(double value);
    void on_tension_valueChanged(double value);
    void on_tension2_valueChanged(double value);
private:
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
