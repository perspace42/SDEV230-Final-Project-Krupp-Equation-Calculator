#include "log.h"
#include <string>
#include <QMainWindow>
#include <iostream>

using namespace std;

// constructor
log::log()
{
    logLength = 0;
    logLengthQString = 0;
    counter = 0;
}

// gets user input
void log::setUserInput(double mass, double velocity, double resistance, double caliber, double armor, double result)
{
    updateLog(mass);
    updateLog(velocity);
    updateLog(resistance);
    updateLog(caliber);
    updateLog(armor);
    updateLog(result);
}

// logs for each result
void log::updateLog(double userInput)
{
    // Update log
    if (logLength < 48)
    {
        logArray[logLength] = userInput;
        logLength++;
    }
    else
    {
        // display error
    }

    // set log array to string
    if (logLengthQString < 48)
    {
        for (int i = 0; i < logLength; i++)
        {
            // temp QString variable
            QString temp;

            // sets if result penetrates or not
            if (logArray[i] == -1)
            {
                temp = "Does Penetrate.";
            }
            else if (logArray[i] == -2)
            {
                temp = "Does Not Penetrate.";
            }
            else
            {
                temp = QString::number(logArray[i]);
            }

            // updates log array QString
            if (i == logLengthQString)
            {
                logArrayQString[logLengthQString] = temp;
                logLengthQString++;
            }
        }
    }
    else
    {
        // error message
    }
}

// gets log array QString
QString log::getLog()
{
    // local variable
    QString string = "";

    // return empty string if array is empty
    if (logLengthQString == 0)
    {
        return string;
    }
    else
    {
        int j = 0;
        // loop through logArrayQString
        for (int i = 0; i < logLengthQString; i++)
        {
            // returns lastest log
            if (i == counter)
            {
                // adds to string depending on int j
                switch (j)
                {
                    // adds mass
                case 0:
                {
                    string += "\nMass: " + logArrayQString[i];
                    j++;
                    break;
                }
                    // adds velocity
                case 1:
                {
                    string += "  Velocity: " + logArrayQString[i];
                    j++;
                    break;
                }
                    // adds resistance
                case 2:
                {
                    string += "  Resistance: " + logArrayQString[i];
                    j++;
                    break;
                }
                    // adds caliber
                case 3:
                {
                    string += "  Caliber: " + logArrayQString[i];
                    j++;
                    break;
                }
                    // adds armor
                case 4:
                {
                    string += "  Armor: " + logArrayQString[i];
                    j++;
                    break;
                }
                    // adds result
                case 5:
                {
                    string += "  Result: " + logArrayQString[i];
                    j++;
                    break;
                }
                }
                counter++;
            }
        }

        return string;
    }
}

//get array length
int log::getArrayLength()
{
    return logLength;
}

// clear array
void log::clearArray()
{
    logLength = 0;
    logLengthQString = 0;
    counter = 0;
}



