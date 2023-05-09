#include "kruppcalculator.h"
#include <QLabel>
#include <QMovie>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    KruppCalculator w;
    w.show();
    return a.exec();
}
