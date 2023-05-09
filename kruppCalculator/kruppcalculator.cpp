#include "kruppcalculator.h"
#include "ui_kruppcalculator.h"
#include "krupp.h"
#include <QMovie>
#include <QFileInfo>
#include <QDir>
#include <iostream>

KruppCalculator::KruppCalculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::KruppCalculator)
{
    ui->setupUi(this);
}

KruppCalculator::~KruppCalculator()
{
    delete ui;
}

// class variables
// false is metric measurements
// true is imperial measurements
bool calMeasurementBool = false;
bool massMeasurementBool = false;
bool velMeasurementBool = false;
bool armorMeasurementBool = false;

//Function To Determine Which Animation Is Played
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
     * The Below code is to print out the path
    std::cout << relativePath.toStdString() << endl;
    */
    //Set Animated Gif By Using Relative Path
    QMovie *movie = new QMovie(relativePath);
    movie->loopCount();

    return movie;
}

// convert caliber measurement
void KruppCalculator::on_cal_convert_btn_clicked()
{
    // Converting mm to in
    if (ui->cal_measure_label->text() == "mm")
    {
        ui->cal_measure_label->setText("in");
        calMeasurementBool = true;
        // convert user input if line edit is not empty
        if (!(ui->cal_lineEdit->text().isEmpty()))
        {
            double calMM = 0.0;
            double calIN = 0.0;

            // check for double
            if (isNumber(ui->cal_lineEdit->text().toStdString()))
            {
                ui->errorMsg_label->clear();
                // get double
                calMM = ui->cal_lineEdit->text().toDouble();
                // convert to inches
                calIN = millimetersToInches(calMM);
                QString calINQString = QString::number(calIN);
                ui->cal_lineEdit->setText(calINQString);
            }
            else
            {
                ui->errorMsg_label->setText("Caliber must be a number.");
            }
        }
    }
    else
        // converting in to mm
    {
        ui->cal_measure_label->setText("mm");
        calMeasurementBool = false;
        // convert user input if line edit is not empty
        if (!(ui->cal_lineEdit->text().isEmpty()))
        {
            double calMM = 0.0;
            double calIN = 0.0;

            // check for double
            if (isNumber(ui->cal_lineEdit->text().toStdString()))
            {
                ui->errorMsg_label->clear();
                // get double
                calIN = ui->cal_lineEdit->text().toDouble();
                // convert to millimeters
                calMM = inchesToMillimeters(calIN);
                QString calMMQString = QString::number(calMM);
                ui->cal_lineEdit->setText(calMMQString);
            }
            else
            {
                ui->errorMsg_label->setText("Caliber must be a number.");
            }
        }
    }
}

// convert mass measurement
void KruppCalculator::on_mass_convert_btn_clicked()
{
    // converting kg to lb
    if (ui->mass_measure_label->text() == "kg")
    {
        ui->mass_measure_label->setText("lb");
        massMeasurementBool = true;
        // convert user input if line edit is not empty
        if (!(ui->mass_lineEdit->text().isEmpty()))
        {
            double massKG = 0.0;
            double massLB = 0.0;

            // check for double
            if (isNumber(ui->mass_lineEdit->text().toStdString()))
            {
                ui->errorMsg_label->clear();
                // get double
                massKG = ui->mass_lineEdit->text().toDouble();
                // convert to pounds
                massLB = kilogramsToPounds(massKG);
                QString massLBQString = QString::number(massLB);
                ui->mass_lineEdit->setText(massLBQString);
            }
            else
            {
                ui->errorMsg_label->setText("Mass must be a number.");
            }
        }

    }
    else
        // converting lb to kg
    {
        ui->mass_measure_label->setText("kg");
        massMeasurementBool = false;
        // convert user input if line edit is not empty
        if (!(ui->mass_lineEdit->text().isEmpty()))
        {
            double massKG = 0.0;
            double massLB = 0.0;

            // check for double
            if (isNumber(ui->mass_lineEdit->text().toStdString()))
            {
                ui->errorMsg_label->clear();
                // get double
                massLB = ui->mass_lineEdit->text().toDouble();
                // convert to kilograms
                massKG = poundsToKilograms(massLB);
                QString massKGQString = QString::number(massKG);
                ui->mass_lineEdit->setText(massKGQString);
            }
            else
            {
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
        ui->vel_measure_label->setText("ft/s");
        velMeasurementBool = true;
        // convert user input if line edit is not empty
        if (!(ui->vel_lineEdit->text().isEmpty()))
        {
            double velM = 0.0;
            double velFT = 0.0;

            // check for double
            if (isNumber(ui->vel_lineEdit->text().toStdString()))
            {
                ui->errorMsg_label->clear();
                // get double
                velM = ui->vel_lineEdit->text().toDouble();
                // convert to feet
                velFT = metersToFeet(velM);
                QString velFTQString = QString::number(velFT);
                ui->vel_lineEdit->setText(velFTQString);
            }
            else
            {
                ui->errorMsg_label->setText("Velocity must be a number.");
            }
        }
    }
    else
        // converting feet to meters
    {
        ui->vel_measure_label->setText("m/s");
        velMeasurementBool = false;
        // convert user input if line edit is not empty
        if (!(ui->vel_lineEdit->text().isEmpty()))
        {
            double velM = 0.0;
            double velFT = 0.0;

            // check for double
            if (isNumber(ui->vel_lineEdit->text().toStdString()))
            {
                ui->errorMsg_label->clear();
                // get double
                velFT = ui->vel_lineEdit->text().toDouble();
                // convert to meters
                velM = feetToMeters(velFT);
                QString velMQString = QString::number(velM);
                ui->vel_lineEdit->setText(velMQString);
            }
            else
            {
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
        ui->armor_measure_label->setText("in");
        armorMeasurementBool = true;
        // convert user input if line edit is not empty
        if (!(ui->armor_lineEdit->text().isEmpty()))
        {
            double armorMM = 0.0;
            double armorIN = 0.0;

            // check for double
            if (isNumber(ui->armor_lineEdit->text().toStdString()))
            {
                ui->errorMsg_label->clear();
                // get double
                armorMM = ui->armor_lineEdit->text().toDouble();
                // convert to inches
                armorIN = millimetersToInches(armorMM);
                QString armorINQString = QString::number(armorIN);
                ui->armor_lineEdit->setText(armorINQString);
            }
            else
            {
                ui->errorMsg_label->setText("Armor must be a number.");
            }
        }
    }
    else
        // converting in to mm
    {
        ui->armor_measure_label->setText("mm");
        armorMeasurementBool = true;
        // convert user input if line edit is not empty
        if (!(ui->armor_lineEdit->text().isEmpty()))
        {
            double armorMM = 0.0;
            double armorIN = 0.0;

            // check for double
            if (isNumber(ui->armor_lineEdit->text().toStdString()))
            {
                ui->errorMsg_label->clear();
                // get double
                armorIN = ui->armor_lineEdit->text().toDouble();
                // convert to mm
                armorMM = inchesToMillimeters(armorIN);
                QString armorMMQString = QString::number(armorMM);
                ui->armor_lineEdit->setText(armorMMQString);
            }
            else
            {
                ui->errorMsg_label->setText("Armor must be a number.");
            }
        }
    }
}

// calculate btn
void KruppCalculator::on_calculate_btn_clicked()
{
    // variables
    double cal, mass, res, vel, armor;
    double calM, massM, velM, armorM; // metric varibles
    QString calQString, massQString, resQString, velQString, armorQString;

    ui->result_lineEdit->clear();
    // checks if no areas are filled
    if (ui->armor_lineEdit->text().isEmpty() && ui->vel_lineEdit->text().isEmpty()
        && ui->cal_lineEdit->text().isEmpty() && ui->mass_lineEdit->text().isEmpty()
        && ui->res_lineEdit->text().isEmpty())
    {
        ui->errorMsg_label->setText("Fill in all or at least four areas.");
    }
    // solve for cal
    else if (ui->cal_lineEdit->text().isEmpty())
    {
        // check if the rest of the variables are filled
        if (ui->mass_lineEdit->text().isEmpty() || ui->vel_lineEdit->text().isEmpty()
            || ui->armor_lineEdit->text().isEmpty() || ui->res_lineEdit->text().isEmpty())
        {
            ui->errorMsg_label->setText("Must fill in at least four areas.");
        }
        else
        {
            ui->errorMsg_label->clear();
            // check if filled variables are numbers
            if (isNumber(ui->mass_lineEdit->text().toStdString()) && isNumber(ui->vel_lineEdit->text().toStdString())
                && isNumber(ui->armor_lineEdit->text().toStdString()) && isNumber(ui->res_lineEdit->text().toStdString()))
            {
                ui->errorMsg_label->clear();
                // get double variables
                mass = ui->mass_lineEdit->text().toDouble();
                vel = ui->vel_lineEdit->text().toDouble();
                armor = ui->armor_lineEdit->text().toDouble();
                res = ui->res_lineEdit->text().toDouble();

                // Set all varibles to metric
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


                // set cal result
                if (calMeasurementBool == false)
                {
                    calQString = QString::number(calM);
                    ui->cal_lineEdit->setText(calQString);
                }
                else
                {
                    cal = millimetersToInches(calM);
                    calQString = QString::number(cal);
                    ui->cal_lineEdit->setText(calQString);
                }
            }
            else
            {
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
            ui->errorMsg_label->setText("Must fill in at least four areas.");
        }
        else
        {
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

                // Set all varibles to metric
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


                // set mass result
                if (massMeasurementBool == false)
                {
                    massQString = QString::number(massM);
                    ui->mass_lineEdit->setText(massQString);
                }
                else
                {
                    mass = kilogramsToPounds(massM);
                    massQString = QString::number(mass);
                    ui->mass_lineEdit->setText(massQString);
                }
            }
            else
            {
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
            ui->errorMsg_label->setText("Must fill in at least four areas.");
        }
        else
        {
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

                // Set all varibles to metric
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


                // set velocity result
                if (velMeasurementBool == false)
                {
                    velQString = QString::number(velM);
                    ui->vel_lineEdit->setText(calQString);
                }
                else
                {
                    vel = metersToFeet(velM);
                    velQString = QString::number(vel);
                    ui->vel_lineEdit->setText(velQString);
                }
            }
            else
            {
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
            ui->errorMsg_label->setText("Must fill in at least four areas.");
        }
        else
        {
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

                // Set all varibles to metric
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
            else
            {
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
            ui->errorMsg_label->setText("Must fill in at least four areas.");
        }
        else
        {
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

                // Set all varibles to metric
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


                // set armor result
                if (armorMeasurementBool == false)
                {
                    armorQString = QString::number(armorM);
                    ui->armor_lineEdit->setText(armorQString);
                }
                else
                {
                    armor = millimetersToInches(armorM);
                    armorQString = QString::number(armor);
                    ui->armor_lineEdit->setText(armorQString);
                }
            }
            else
            {
                ui->errorMsg_label->setText("All fields must be numbers.");
            }
        }
    }
    else
    {
        // all fields are filled
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

            // Set all varibles to metric
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

            // solve for krupp
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
        else
        {
            ui->errorMsg_label->setText("All fields must be numbers.");
        }
    }
}

// clear line edit fields
void KruppCalculator::on_clear_btn_clicked()
{
    ui->mass_lineEdit->clear();
    ui->cal_lineEdit->clear();
    ui->armor_lineEdit->clear();
    ui->vel_lineEdit->clear();
    ui->res_lineEdit->clear();
}

