#ifndef KRUPP_H
#define KRUPP_H


/*
Author: Scott Field, Galilea Garcia
Date: 05/06/2023
Version: 1.0
Purpose: The purpose of this file is to store a functions that produces a
solution for every missing variable in the Krupp Equation.

In addition the program will also
store functions to convert From Imperial to the Metric system so that either data value can
be used for the Krupp Equation

Krupp Equation:
The Krupp Equation determines how much armor a given shell will penetrate (roughly)
although it was designed in the era of battleships it is still fairly accurate with
more modern equipment

The equation is as follows:
                                            (   (Velocity of Shell On Impact) ( Velocity ) [Meters Per Second] {V} * Square Root(Mass Of The Projectile) (Projectile) [ Kilograms ] {P}  )
Armor Thickness (Armor) [Millimeters] {B} =                                                                    /
                                            (   (    Resistance Constant    ) (Resistance) [     Integer     ] {K} * Square Root(  Projectile Caliber  ) (  Caliber ) [Millimeters] {D}  )
*/
#include <string>
#include <cmath>
#include <iostream>
using namespace std;


//Validate Input Function
//This function checks if provided input can be converted to a positive number
bool isNumber(const string& inputString);


//Solve For Missing Variables In The Krupp Equation (Krupp Equation Assumes Metric Values)

//return the missing armor variable
double solveForArmor(double velocity, double mass, int resistance, double caliber);

//return the missing velocity variable
double solveForVelocity(double armor, double mass, int resistance,double caliber);

//return the missing resistance variable
double solveForResistance(double velocity, double mass, double armor, double caliber);

//return the missing mass variable
double solveForMass(double velocity, double armor, int resistance, double caliber);

//return the missing caliber variable
double solveForCaliber(double velocity, double mass, int resistance, double armor);

//Convert variables from imperial to metric

//(For converting meters per second into feet per second) (Velocity)
double feetToMeters(double feet);

//(For converting feet per second into meters per second) (Velocity)
double metersToFeet(double meters);

//(For converting pounds into Kilograms) (Projectile Mass)
double poundsToKilograms(double pound);

//(For converting Kilograms into pounds) (Projectile Mass)
double kilogramsToPounds(double kilograms);

//(For converting inches into Millimeters) (Armor Thickness, Projectile Caliber)
double  inchesToMillimeters(double inch);

//(For converting Millimeters into inches) (Armor Thickness, Projectile Caliber)
double millimetersToInches(double millimeters);

//If all 5 fields are filled out
//Check using the Krupp Equation, if a given shell will penetrate a given armor plate
bool solveKrupp(double armor, double velocity, double mass, int resistance, double caliber);


#endif // KRUPP_H
