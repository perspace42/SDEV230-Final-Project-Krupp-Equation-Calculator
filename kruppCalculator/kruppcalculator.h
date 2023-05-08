#ifndef KRUPPCALCULATOR_H
#define KRUPPCALCULATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class KruppCalculator; }
QT_END_NAMESPACE

class KruppCalculator : public QMainWindow
{
    Q_OBJECT

public:
    KruppCalculator(QWidget *parent = nullptr);
    ~KruppCalculator();

private slots:
    void on_cal_convert_btn_clicked();

    void on_mass_convert_btn_clicked();

    void on_vel_convert_btn_clicked();

    void on_armor_convert_btn_clicked();

    void on_calculate_btn_clicked();

    void on_clear_btn_clicked();

private:
    Ui::KruppCalculator *ui;
};
#endif // KRUPPCALCULATOR_H
