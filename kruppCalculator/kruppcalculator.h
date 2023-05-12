/*
Author: Galilea Garcia
Date: 05/08/2023
Version: 1.0
Purpose: The purpose of this file is to define the functions for the widgets that have
been placed in the kruppcalculator.ui file, this file does that through the KruppCalculator class
and methods.
*/

#ifndef KRUPPCALCULATOR_H
#define KRUPPCALCULATOR_H

#include "log.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class KruppCalculator; }
QT_END_NAMESPACE

class KruppCalculator : public QMainWindow, public log
{
    Q_OBJECT

public:
    KruppCalculator(QWidget *parent = nullptr);
    ~KruppCalculator();

private slots:
    //buttons to convert between imperial and metric measurements
    void on_cal_convert_btn_clicked();

    void on_mass_convert_btn_clicked();

    void on_vel_convert_btn_clicked();

    void on_armor_convert_btn_clicked();

    void on_calculate_btn_clicked();

    void on_clear_btn_clicked();

    void on_clearLog_btn_clicked();

private:
    Ui::KruppCalculator *ui;
    log logUI;
};
#endif // KRUPPCALCULATOR_H
