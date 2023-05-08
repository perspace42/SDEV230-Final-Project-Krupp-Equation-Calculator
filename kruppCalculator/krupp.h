#ifndef KRUPP_H
#define KRUPP_H


/*
Author: Scott Field
Date: 04/24/2023
Version: 1.0
Date: 04/24/2023
Purpose: The purpose of this file is to store a functions that produces a
solution for every missing variable in the Krupp Equation.

In addition the program will also
store a function to convert From Imperial to the Metric system so that either data value can
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

//Functions



#include <string>
#include <cmath>
#include <iostream>
using namespace std;


//Validate Input Function
//This function checks if provided input can be converted to a positive number
bool isNumber(const string& inputString);


//Solve For Missing Variables In The Krupp Equation (Krupp Equation Assumes Metric Values)
double solveForArmor(double velocity, double mass, int resistance, double caliber);

double solveForVelocity(double armor, double mass, int resistance,double caliber);

double solveForResistance(double velocity, double mass, double armor, double caliber);

double solveForMass(double velocity, double armor, int resistance, double caliber);

double solveForCaliber(double velocity, double mass, int resistance, double armor);

//Convert variables from imperial to metric

//(For converting meters per second into feet per second) (Velocity)
double feetToMeters(double feet);

double metersToFeet(double meters);

//(For converting pounds into Kilograms) (Projectile Mass)
double poundsToKilograms(double pound);

double kilogramsToPounds(double kilograms);

//(For converting inches into Millimeters) (Armor Thickness, Projectile Caliber)
double  inchesToMillimeters(double inch);

double millimetersToInches(double millimeters);

//If all 5 fields are filled out
//Check using the Krupp Equation, if a given shell will penetrate a given armor plate
bool solveKrupp(double armor, double velocity, double mass, int resistance, double caliber);


#endif // KRUPP_H
