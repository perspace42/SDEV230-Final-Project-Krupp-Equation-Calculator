


// valueList:input



ofstream valueList("valueList.txt");

cout << "Enter the armor thickness: ";
getline(cin, armorStr);
valueList << "Armor Thickness: " << armorStr << endl;

cout << "Enter the velocity: ";
getline(cin, velocityStr);
valueList << "Velocity: " << velocityStr << endl;

cout << "Enter the mass: ";
getline(cin, massStr);
valueList << "Mass: " << massStr << endl;

cout << "Enter the resistance: ";
getline(cin, resistanceStr);
valueList << "Resistance: " << resistanceStr << endl;

cout << "Enter the caliber: ";
getline(cin, caliberStr);
valueList << "Caliber: " << caliberStr << endl;

valueList.close();








