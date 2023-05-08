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
bool isNumber(const string& inputString){
    //for each character in the inputString

    int index = 0;
    int length = inputString.length();
    //ensure that only one decimal point is in any given inputted number
    bool decimalFound = false;

    //if string is empty return false
    if (length == 0){
        return false;
    }

    //Check if the last character is invalid(not: 0 1 2 3 4 5 6 7 8 9 )
    //Eliminates the possibility of a trailing decimal point (ex: 3.)
    if ((inputString[length-1] > '9')){
        return false;
    }

    //Iterate accross string and determine if all other characters are valid (last character has already been checked at this point)
    for (index = 0; index < length-1; index++){
        //Check if 1st character is invalid (not: . 0 1 2 3 4 5 6 7 8 9)
        if (inputString[index] != '.' && inputString[index] > '9'){
            return false;
        }

        //Ensure that any number can only have one decimal point
        if (inputString[index] == '.'){
            //If a second decimal point is found, input is not valid
            if (decimalFound){
                return false;
                //Otherwise flag that the decimal has been found
            }else{
                decimalFound = true;
            }
        }
    }
    //Otherwise if no invalid input return true
    return true;
};


//Solve For Missing Variables In The Krupp Equation (Krupp Equation Assumes Metric Values)
double solveForArmor(double velocity, double mass, int resistance, double caliber){
    return (  1000 *  (  (velocity * sqrt(mass)) / (resistance * sqrt(caliber))  )   );
}

double solveForVelocity(double armor, double mass, int resistance,double caliber){
    return (    (   ((armor * resistance) * (sqrt(mass) * sqrt(caliber))) / mass   ) / 1000   );
}

double solveForResistance(double velocity, double mass, double armor, double caliber){
    return (    1000 * ((velocity * (sqrt(caliber) * sqrt(mass))) / (armor * caliber))   );
}

double solveForMass(double velocity, double armor, int resistance, double caliber){
    return (  (  (((armor * armor) * (resistance * resistance) * caliber)) / (velocity * velocity)  ) / 1'000'000 );
}

double solveForCaliber(double velocity, double mass, int resistance, double armor){
    return (  (  ((velocity * velocity) * mass) / ((armor * armor) * (resistance * resistance))  ) * 1'000'000);
}

//Convert variables from imperial to metric

//(For converting meters per second into feet per second) (Velocity)
double feetToMeters(double feet){
    return feet / 3.281;
}

double metersToFeet(double meters) {
    return meters * 3.281;
}

//(For converting pounds into Kilograms) (Projectile Mass)
double poundsToKilograms(double pound){
    return pound / 2.2;
}

double kilogramsToPounds(double kilograms) {
    return kilograms * 2.2;
}

//(For converting inches into Millimeters) (Armor Thickness, Projectile Caliber)
double  inchesToMillimeters(double inch){
    return inch * 25.4;
}

double millimetersToInches(double millimeters) {
    return millimeters / 25.4;
}

//If all 5 fields are filled out
//Check using the Krupp Equation, if a given shell will penetrate a given armor plate
bool solveKrupp(double armor, double velocity, double mass, int resistance, double caliber){
    if (solveForArmor(velocity,mass,resistance,caliber) >= armor){
        return true;
    }else{
        return false;
    }
}
