/*
Author: Galilea Garcia, Scott Field
Date: 05/08/2023
Version: 1.0
Purpose: The purpose of this file is to initialize the program loop
using QApplication and KruppCalculator
*/


#include "kruppcalculator.h"
#include <QLabel>
#include <QMovie>
#include <QApplication>

//call the main window with the KruppCalculator
int main(int argc, char *argv[])
{
    //initialize the application
    QApplication app(argc, argv);
    //intialize the application widgets
    KruppCalculator window;
    //show the widgets
    window.show();
    //return the results of the app
    return app.exec();
}
