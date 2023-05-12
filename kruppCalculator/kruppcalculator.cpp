/*
Author: Scott Field, Galilea Garcia
Date: 05/08/2023
Version: 1.0
Purpose: The purpose of this file is to add functionality to the widgets that have
been placed in the kruppcalculator.ui file, this file does that through the KruppCalculator class
and methods.
*/


#include "kruppcalculator.h"
#include "ui_kruppcalculator.h"
#include "krupp.h"
#include <QMovie>
#include <QFileInfo>
#include <QDir>
#include <iostream>

//Initialize Program Class and Window and UI
KruppCalculator::KruppCalculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::KruppCalculator)
{
    //setup ui by using the kruppcalculator.ui file
    ui->setupUi(this);
    //initialize empty video container to invisible on startup
    ui->video_container->setVisible(false);
}

//destructor for when the KruppCalculator goes out of scope
KruppCalculator::~KruppCalculator()
{
    delete ui;
}

// class variables to check which system of measurement is being used in the program
// false is metric measurements
// true is imperial measurements
bool calMeasurementBool = false;
bool massMeasurementBool = false;
bool velMeasurementBool = false;
bool armorMeasurementBool = false;

//Function To Determine Which Animation To Play, when the user tests if their entered input is correct according to the krupp equation
QMovie* playAnimation(bool penetrated){
    //Set File Info
    QFileInfo fileInfo;
    //If the shot penetrates set animation equal to that.
    if (penetrated){
        fileInfo = QString("images/Shot_Penetrated.gif");
    //If the shot does not penetrate set the animation equal to that.
    }else{
        fileInfo = QString("images/Shot_Bounced.gif");
    }

    //Get File Name From File Info
    QString fileName = fileInfo.fileName();
    //Get File Path From File Info
    QString path = fileInfo.path();
    //Obtain Relative Path By Getting Directory, Path, and File Name
    QString relativePath = QDir::currentPath() + "/" + path + "/" + fileName;

    /*
     * The Below commented out code is to print out the path (in case the image file is not being found)
    std::cout << relativePath.toStdString() << endl;
    */

    //Set Animated Gif By Using Relative Path
    QMovie *movie = new QMovie(relativePath);

    return movie;
}

// convert caliber measurement when the convert button is cllicked
void KruppCalculator::on_cal_convert_btn_clicked()
{
    // Converting mm to in
    if (ui->cal_measure_label->text() == "mm")
    {
        //set text to in
        ui->cal_measure_label->setText("in");
        //set tracking bool to true (means measurement is in inches)
        calMeasurementBool = true;
        // convert user input if line edit is not empty
        if (!(ui->cal_lineEdit->text().isEmpty()))
        {
            //initialize variables to store results
            double calMM = 0.0;
            double calIN = 0.0;

            // check for double
            if (isNumber(ui->cal_lineEdit->text().toStdString()))
            {
                //clear error message once correct input is entered
                ui->errorMsg_label->clear();
                // get double
                calMM = ui->cal_lineEdit->text().toDouble();
                // convert to inches
                calIN = millimetersToInches(calMM);
                QString calINQString = QString::number(calIN);
                ui->cal_lineEdit->setText(calINQString);
            }
            //if input is incorrect (not a number output an appropriate error message
            else
            {
                //output the error message
                ui->errorMsg_label->setText("Caliber must be a number.");
            }
        }
    }
    // converting in to mm
    else
    {
        //set text to mm
        ui->cal_measure_label->setText("mm");
        //set tracking bool to false (means measurement is in millimeters)
        calMeasurementBool = false;
        // convert user input if line edit is not empty
        if (!(ui->cal_lineEdit->text().isEmpty()))
        {
            //initialize variables to store results
            double calMM = 0.0;
            double calIN = 0.0;

            // check for double
            if (isNumber(ui->cal_lineEdit->text().toStdString()))
            {
                //clear error message once correct input is entered
                ui->errorMsg_label->clear();
                // get double
                calIN = ui->cal_lineEdit->text().toDouble();
                // convert to millimeters
                calMM = inchesToMillimeters(calIN);
                QString calMMQString = QString::number(calMM);
                ui->cal_lineEdit->setText(calMMQString);
            }
            //if input is incorrect (not a number) output an appropriate error message
            else
            {
                //output the error message
                ui->errorMsg_label->setText("Caliber must be a number.");
            }
        }
    }
}

// convert mass measurement when the convert button is clicked
void KruppCalculator::on_mass_convert_btn_clicked()
{
    // converting kg to lb
    if (ui->mass_measure_label->text() == "kg")
    {
        //set text to lb
        ui->mass_measure_label->setText("lb");
        //set tracking bool to true (means measurement is in lb)
        massMeasurementBool = true;
        // convert user input if line edit is not empty
        if (!(ui->mass_lineEdit->text().isEmpty()))
        {
            //initialize variables to store results
            double massKG = 0.0;
            double massLB = 0.0;

            // check for double
            if (isNumber(ui->mass_lineEdit->text().toStdString()))
            {
                //clear error message once correct input is entered
                ui->errorMsg_label->clear();
                // get double
                massKG = ui->mass_lineEdit->text().toDouble();
                // convert to pounds
                massLB = kilogramsToPounds(massKG);
                QString massLBQString = QString::number(massLB);
                ui->mass_lineEdit->setText(massLBQString);
            }
            //if input is incorrect (not a number) output an appropriate error message
            else
            {
                //output the error message
                ui->errorMsg_label->setText("Mass must be a number.");
            }
        }

    }
    // converting lb to kg
    else
    {
        //set text to kg
        ui->mass_measure_label->setText("kg");
        //set tracking bool to false (means measurement is in kg)
        massMeasurementBool = false;
        // convert user input if line edit is not empty
        if (!(ui->mass_lineEdit->text().isEmpty()))
        {
            //initialize variables to store results
            double massKG = 0.0;
            double massLB = 0.0;

            // check for double
            if (isNumber(ui->mass_lineEdit->text().toStdString()))
            {
                //clear error message once correct input is entered
                ui->errorMsg_label->clear();
                // get double
                massLB = ui->mass_lineEdit->text().toDouble();
                // convert to kilograms
                massKG = poundsToKilograms(massLB);
                QString massKGQString = QString::number(massKG);
                ui->mass_lineEdit->setText(massKGQString);
            }
            //if input is incorrect (not a number output an appropriate error message
            else
            {
                //output the error message
                ui->errorMsg_label->setText("Mass must be a number.");
            }
        }
    }
}

// convert velocity measurement
void KruppCalculator::on_vel_convert_btn_clicked()
{
    // converting meters to feet
    if (ui->vel_measure_label->text() == "m/s")
    {
        //set text to ft/s
        ui->vel_measure_label->setText("ft/s");
        //set tracking bool to true (means measurement is in feet per second)
        velMeasurementBool = true;
        // convert user input if line edit is not empty
        if (!(ui->vel_lineEdit->text().isEmpty()))
        {
            //initialize variables to store results
            double velM = 0.0;
            double velFT = 0.0;

            // check for double
            if (isNumber(ui->vel_lineEdit->text().toStdString()))
            {
                //clear error message once correct input is entered
                ui->errorMsg_label->clear();
                // get double
                velM = ui->vel_lineEdit->text().toDouble();
                // convert to feet
                velFT = metersToFeet(velM);
                QString velFTQString = QString::number(velFT);
                ui->vel_lineEdit->setText(velFTQString);
            }
            //if input is incorrect (not a number output an appropriate error message
            else
            {
                //output the error message
                ui->errorMsg_label->setText("Velocity must be a number.");
            }
        }
    }
    // converting feet to meters
    else
    {
        //set text to meters per second
        ui->vel_measure_label->setText("m/s");
        //set tracking bool to false (means measurement is in meters per second)
        velMeasurementBool = false;
        // convert user input if line edit is not empty
        if (!(ui->vel_lineEdit->text().isEmpty()))
        {
            //initialize variables to store results
            double velM = 0.0;
            double velFT = 0.0;

            // check for double
            if (isNumber(ui->vel_lineEdit->text().toStdString()))
            {
                //clear error message once correct input is entered
                ui->errorMsg_label->clear();
                // get double
                velFT = ui->vel_lineEdit->text().toDouble();
                // convert to meters
                velM = feetToMeters(velFT);
                QString velMQString = QString::number(velM);
                ui->vel_lineEdit->setText(velMQString);
            }
            //if input is incorrect (not a number output an appropriate error message
            else
            {
                //output the error message
                ui->errorMsg_label->setText("Velocity must be a number.");
            }
        }
    }
}

// convert armor measurement
void KruppCalculator::on_armor_convert_btn_clicked()
{
    // converting mm to in
    if (ui->armor_measure_label->text() == "mm")
    {
        //set text to in
        ui->armor_measure_label->setText("in");
        //set tracking bool to true (means measurement is in inches)
        armorMeasurementBool = true;
        // convert user input if line edit is not empty
        if (!(ui->armor_lineEdit->text().isEmpty()))
        {
            //initialize variables to store results
            double armorMM = 0.0;
            double armorIN = 0.0;

            // check for double
            if (isNumber(ui->armor_lineEdit->text().toStdString()))
            {
                //clear error message once correct input is entered
                ui->errorMsg_label->clear();
                // get double
                armorMM = ui->armor_lineEdit->text().toDouble();
                // convert to inches
                armorIN = millimetersToInches(armorMM);
                QString armorINQString = QString::number(armorIN);
                ui->armor_lineEdit->setText(armorINQString);
            }
            //if input is incorrect (not a number output an appropriate error message
            else
            {
                //output the error message
                ui->errorMsg_label->setText("Armor must be a number.");
            }
        }
    }
    // converting in to mm
    else
    {
        //set text to mm
        ui->armor_measure_label->setText("mm");
        //set tracking bool to false (means measurement is in millimeters)
        armorMeasurementBool = false;
        // convert user input if line edit is not empty
        if (!(ui->armor_lineEdit->text().isEmpty()))
        {
            //initialize variables to store results
            double armorMM = 0.0;
            double armorIN = 0.0;

            // check for double
            if (isNumber(ui->armor_lineEdit->text().toStdString()))
            {
                //clear error message once correct input is entered
                ui->errorMsg_label->clear();
                // get double
                armorIN = ui->armor_lineEdit->text().toDouble();
                // convert to mm
                armorMM = inchesToMillimeters(armorIN);
                QString armorMMQString = QString::number(armorMM);
                ui->armor_lineEdit->setText(armorMMQString);
            }
            //if input is incorrect (not a number) output an appropriate error message
            else
            {
                //output the error message
                ui->errorMsg_label->setText("Armor must be a number.");
            }
        }
    }
}

// calculate btn
void KruppCalculator::on_calculate_btn_clicked()
{
    //variables for calculating krupp equation (organized by system of measurement)
    double cal, mass, res, vel, armor; //imperial varibles
    double calM, massM, velM, armorM; // metric varibles
    QString calQString, massQString, resQString, velQString, armorQString;

    //Set Video Label To Hidden Until It is Needed Again
    ui->video_container->setVisible(false);
    //Clear the last result before adding the new one
    ui->result_lineEdit->clear();
    // checks if no areas are filled
    if (ui->armor_lineEdit->text().isEmpty() && ui->vel_lineEdit->text().isEmpty()
        && ui->cal_lineEdit->text().isEmpty() && ui->mass_lineEdit->text().isEmpty()
        && ui->res_lineEdit->text().isEmpty())
    {
        //if no areas are filled instruct the user that they must fill in all or at least four areas
        ui->errorMsg_label->setText("Fill in all or at least four areas.");
    }
    // solve for cal (if the calliber field is empty and all other input fields are entered)
    else if (ui->cal_lineEdit->text().isEmpty())
    {
        // check if the rest of the variables are filled
        if (ui->mass_lineEdit->text().isEmpty() || ui->vel_lineEdit->text().isEmpty()
            || ui->armor_lineEdit->text().isEmpty() || ui->res_lineEdit->text().isEmpty())
        {
            //if not enough areas are filled instruct the user that they must fill in at least four areas
            ui->errorMsg_label->setText("Must fill in at least four areas.");
        }
        //Otherwise required fields are filled, move on to validating the input
        else
        {
            //clear previous error message (if any)
            ui->errorMsg_label->clear();
            // check if filled variables are numbers
            if (isNumber(ui->mass_lineEdit->text().toStdString()) && isNumber(ui->vel_lineEdit->text().toStdString())
                && isNumber(ui->armor_lineEdit->text().toStdString()) && isNumber(ui->res_lineEdit->text().toStdString()))
            {
                ui->errorMsg_label->clear();
                // convert entered variables to doubles to be used in the equations
                mass = ui->mass_lineEdit->text().toDouble();
                vel = ui->vel_lineEdit->text().toDouble();
                armor = ui->armor_lineEdit->text().toDouble();
                res = ui->res_lineEdit->text().toDouble();

                // Set all variables to metric if they are not metric already
                if (massMeasurementBool == true)
                {
                    massM = poundsToKilograms(mass);
                    mass = massM;
                }
                if (velMeasurementBool == true)
                {
                    velM = feetToMeters(vel);
                    vel = velM;
                }
                if (armorMeasurementBool == true)
                {
                    armorM = inchesToMillimeters(armor);
                    armor = armorM;
                }

                // solve for cal
                calM = solveForCaliber(vel, mass, res, armor);


                // set cal result (if already in millimeters)
                if (calMeasurementBool == false)
                {
                    calQString = QString::number(calM);
                    ui->cal_lineEdit->setText(calQString);
                }
                //set cal result (after converting it to millimeters)
                else
                {
                    cal = millimetersToInches(calM);
                    calQString = QString::number(cal);
                    ui->cal_lineEdit->setText(calQString);
                }
            }
            //otherwise required fields are filled but not all are numbers
            else
            {
                //output an error message to the user
                ui->errorMsg_label->setText("All fields must be numbers.");
            }
        }
    }
    // solve for mass
    else if (ui->mass_lineEdit->text().isEmpty())
    {
        // check if the rest of the variables are filled
        if (ui->cal_lineEdit->text().isEmpty() || ui->vel_lineEdit->text().isEmpty()
            || ui->armor_lineEdit->text().isEmpty() || ui->res_lineEdit->text().isEmpty())
        {
            //send error message if four areas are not filled
            ui->errorMsg_label->setText("Must fill in at least four areas.");
        }
        //otherwise all input areas are filled move on to input data validation
        else
        {
            //clear previous error message (if any)
            ui->errorMsg_label->clear();
            // check if filled variables are numbers
            if (isNumber(ui->cal_lineEdit->text().toStdString()) && isNumber(ui->vel_lineEdit->text().toStdString())
                && isNumber(ui->armor_lineEdit->text().toStdString()) && isNumber(ui->res_lineEdit->text().toStdString()))
            {
                ui->errorMsg_label->clear();
                // get double variables
                cal = ui->cal_lineEdit->text().toDouble();
                vel = ui->vel_lineEdit->text().toDouble();
                armor = ui->armor_lineEdit->text().toDouble();
                res = ui->res_lineEdit->text().toDouble();

                // Set all varibles to metric (if they are not metric already)
                if (calMeasurementBool == true)
                {
                    calM = inchesToMillimeters(cal);
                    cal = calM;
                }
                if (velMeasurementBool == true)
                {
                    velM = feetToMeters(vel);
                    vel = velM;
                }
                if (armorMeasurementBool == true)
                {
                    armorM = inchesToMillimeters(armor);
                    armor = armorM;
                }

                // solve for mass
                massM = solveForMass(vel, armor, res, cal);


                // set mass result (if mass is already in kilograms)
                if (massMeasurementBool == false)
                {
                    massQString = QString::number(massM);
                    ui->mass_lineEdit->setText(massQString);
                }
                // set mass result (if mass is in pounds and needs to be converted to kilograms)
                else
                {
                    mass = kilogramsToPounds(massM);
                    massQString = QString::number(mass);
                    ui->mass_lineEdit->setText(massQString);
                }
            }
            //otherwise the input is filled but is not a number
            else
            {
                //output an error message to the user that numbers must be entered
                ui->errorMsg_label->setText("All fields must be numbers.");
            }
        }
    }
    // solve for velocity
    else if (ui->vel_lineEdit->text().isEmpty())
    {
        // check if the rest of the variables are filled
        if (ui->mass_lineEdit->text().isEmpty() || ui->cal_lineEdit->text().isEmpty()
            || ui->armor_lineEdit->text().isEmpty() || ui->res_lineEdit->text().isEmpty())
        {
            //if variables are not filled output an error message
            ui->errorMsg_label->setText("Must fill in at least four areas.");
        }
        //input is filled move on to input data validation
        else
        {
            //clear the error message if any is present
            ui->errorMsg_label->clear();
            // check if filled variables are numbers
            if (isNumber(ui->mass_lineEdit->text().toStdString()) && isNumber(ui->cal_lineEdit->text().toStdString())
                && isNumber(ui->armor_lineEdit->text().toStdString()) && isNumber(ui->res_lineEdit->text().toStdString()))
            {
                ui->errorMsg_label->clear();
                // get double variables
                mass = ui->mass_lineEdit->text().toDouble();
                cal = ui->cal_lineEdit->text().toDouble();
                armor = ui->armor_lineEdit->text().toDouble();
                res = ui->res_lineEdit->text().toDouble();

                // Set all variables to metric (if they are not metric already)
                if (calMeasurementBool == true)
                {
                    calM = inchesToMillimeters(cal);
                    cal = calM;
                }
                if (massMeasurementBool == true)
                {
                    massM = poundsToKilograms(mass);
                    mass = massM;
                }
                if (armorMeasurementBool == true)
                {
                    armorM = inchesToMillimeters(armor);
                    armor = armorM;
                }

                // solve for velocity
                velM = solveForVelocity(armor, mass, res, cal);


                // set velocity result (if velocity is in meters per second)
                if (velMeasurementBool == false)
                {
                    velQString = QString::number(velM);
                    ui->vel_lineEdit->setText(calQString);
                }
                // set velocity result (if velocity is in feet per second)
                else
                {
                    vel = metersToFeet(velM);
                    velQString = QString::number(vel);
                    ui->vel_lineEdit->setText(velQString);
                }
            }
            //If any of the entered fields are not numbers
            else
            {
                //output an error message that all field must be numbers
                ui->errorMsg_label->setText("All fields must be numbers.");
            }
        }
    }
    // solve for resistance
    else if (ui->res_lineEdit->text().isEmpty())
    {
        // check if the rest of the variables are filled
        if (ui->mass_lineEdit->text().isEmpty() || ui->cal_lineEdit->text().isEmpty()
            || ui->armor_lineEdit->text().isEmpty() || ui->vel_lineEdit->text().isEmpty())
        {
            //if some of the variables are not filled ouput the error message
            ui->errorMsg_label->setText("Must fill in at least four areas.");
        }
        else
        {
            //clear past error message (if any is present)
            ui->errorMsg_label->clear();
            // check if filled variables are numbers
            if (isNumber(ui->mass_lineEdit->text().toStdString()) && isNumber(ui->cal_lineEdit->text().toStdString())
                && isNumber(ui->armor_lineEdit->text().toStdString()) && isNumber(ui->vel_lineEdit->text().toStdString()))
            {
                ui->errorMsg_label->clear();
                // get double variables
                mass = ui->mass_lineEdit->text().toDouble();
                cal = ui->cal_lineEdit->text().toDouble();
                armor = ui->armor_lineEdit->text().toDouble();
                vel = ui->vel_lineEdit->text().toDouble();

                // Set all varibles to metric (if they are not metric already)
                if (calMeasurementBool == true)
                {
                    calM = inchesToMillimeters(cal);
                    cal = calM;
                }
                if (massMeasurementBool == true)
                {
                    massM = poundsToKilograms(mass);
                    mass = massM;
                }
                if (armorMeasurementBool == true)
                {
                    armorM = inchesToMillimeters(armor);
                    armor = armorM;
                }

                // solve for resistance
                res = solveForResistance(vel, mass, armor, cal);

                // set resistance result
                resQString = QString::number(res);
                ui->res_lineEdit->setText(resQString);
            }
            //if required fields are filled but do not contain numbers output an error message
            else
            {
                //output error message informing user that all fields must be numbers
                ui->errorMsg_label->setText("All fields must be numbers.");
            }
        }
    }
    // solve for armor
    else if (ui->armor_lineEdit->text().isEmpty())
    {
        // check if the rest of the variables are filled
        if (ui->mass_lineEdit->text().isEmpty() || ui->cal_lineEdit->text().isEmpty()
            || ui->vel_lineEdit->text().isEmpty() || ui->res_lineEdit->text().isEmpty())
        {
            //if some of the variables are not filled output an error message
            ui->errorMsg_label->setText("Must fill in at least four areas.");
        }
        //variables are filled move on to input data validation
        else
        {
            //clear the error message (if any)
            ui->errorMsg_label->clear();
            // check if filled variables are numbers
            if (isNumber(ui->mass_lineEdit->text().toStdString()) && isNumber(ui->cal_lineEdit->text().toStdString())
                && isNumber(ui->vel_lineEdit->text().toStdString()) && isNumber(ui->res_lineEdit->text().toStdString()))
            {
                ui->errorMsg_label->clear();
                // get double variables
                mass = ui->mass_lineEdit->text().toDouble();
                cal = ui->cal_lineEdit->text().toDouble();
                vel = ui->vel_lineEdit->text().toDouble();
                res = ui->res_lineEdit->text().toDouble();

                // Set all varibles to metric (if they are not metric already)
                if (calMeasurementBool == true)
                {
                    calM = inchesToMillimeters(cal);
                    cal = calM;
                }
                if (massMeasurementBool == true)
                {
                    massM = poundsToKilograms(mass);
                    mass = massM;
                }
                if (velMeasurementBool == true)
                {
                    velM = feetToMeters(vel);
                    vel = velM;
                }

                // solve for armor
                armorM = solveForArmor(vel, mass, res, cal);


                // set armor result (if armor is in millimeters)
                if (armorMeasurementBool == false)
                {
                    armorQString = QString::number(armorM);
                    ui->armor_lineEdit->setText(armorQString);
                }
                // set armor result (if armor is in inches)
                else
                {
                    armor = millimetersToInches(armorM);
                    armorQString = QString::number(armor);
                    ui->armor_lineEdit->setText(armorQString);
                }
            }
            //if all required fields are full, but are not numbers output an error
            else
            {
                //output the error
                ui->errorMsg_label->setText("All fields must be numbers.");
            }
        }
    }
    //if all fields are filled test if the users inputed data values will cause an armor penetration or shell bounce according to the Krupp Equation
    else
    {
        // all fields are filled
        //clear error message (if any)
        ui->errorMsg_label->clear();
        // check if all fields are numbers
        if (isNumber(ui->mass_lineEdit->text().toStdString()) && isNumber(ui->cal_lineEdit->text().toStdString())
            && isNumber(ui->vel_lineEdit->text().toStdString()) && isNumber(ui->res_lineEdit->text().toStdString())
            && isNumber(ui->armor_lineEdit->text().toStdString()))
        {
            ui->errorMsg_label->clear();

            // get double variables
            mass = ui->mass_lineEdit->text().toDouble();
            cal = ui->cal_lineEdit->text().toDouble();
            vel = ui->vel_lineEdit->text().toDouble();
            res = ui->res_lineEdit->text().toDouble();
            armor = ui->armor_lineEdit->text().toDouble();

            // Set all varibles to metric (if they are not metric already)
            if (calMeasurementBool == true)
            {
                calM = inchesToMillimeters(cal);
                cal = calM;
            }
            if (massMeasurementBool == true)
            {
                massM = poundsToKilograms(mass);
                mass = massM;
            }
            if (velMeasurementBool == true)
            {
                velM = feetToMeters(vel);
                vel = velM;
            }
            if (armorMeasurementBool == true)
            {
                armorM = inchesToMillimeters(armor);
                armor = armorM;
            }

            // solve for krupp (then display the resulting gif image depending on the result)
            // if true display an armor penetration
            if (solveKrupp(armor, vel, mass, res, cal))
            {
                ui->result_lineEdit->setText("Armor will be penetrated.");
                // display gif
                //true means that the animation to penetrate the tank should be played
                QMovie *movie = playAnimation(true);

                //Set Gif Container To Visible
                ui->video_container->setVisible(true);

                //Assign Gif To Label
                ui->video_container->setMovie(movie);

                //Play Movie
                movie->start();

                //Show Label
                ui->video_container->show();
            }
            //if false display an shell bounce
            else
            {
                ui->result_lineEdit->setText("Armor will not be penetrated.");
                // display gif
                //false means that the animation to not penetrate the tank should be played
                QMovie *movie = playAnimation(false);

                //Set Gif Container To Visible
                ui->video_container->setVisible(true);

                //Assign Gif To Label
                ui->video_container->setMovie(movie);

                //Play Movie
                movie->start();

                //Show Label
                ui->video_container->show();
            }
        }
        //if required input is entered but any are not numbers display an error
        else
        {
            //output the error
            ui->errorMsg_label->setText("All fields must be numbers.");
        }
    }
}

// clear line edit fields when the clear button is clicked
void KruppCalculator::on_clear_btn_clicked()
{
    //clear all line edit fields and the result field
    ui->mass_lineEdit->clear();
    ui->cal_lineEdit->clear();
    ui->armor_lineEdit->clear();
    ui->vel_lineEdit->clear();
    ui->res_lineEdit->clear();
}

