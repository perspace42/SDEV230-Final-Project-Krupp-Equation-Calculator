#ifndef LOG_H
#define LOG_H

#include <string>
#include <QMainWindow>
#include <iostream>

using namespace std;


class log
{
public:
    // constructor
    log();

    // gets user input
    void setUserInput(double mass, double velocity, double resistance, double caliber, double armor, double result);

    // logs for each result
    void updateLog(double userInput);

    // gets log array QString
    QString getLog();

    //get array length
    int getArrayLength();

    // clear array
    void clearArray();

private:
    double logArray[48];
    QString logArrayQString[48];
    int logLength;
    int logLengthQString;
    int counter;

};

#endif // LOG_H
