



ofstream stringList("stringList.txt");


if (solveKrupp(armor, velocity, mass, resistance, caliber)) {
  cout << "The armor is penetrable by the Krupp formula." << endl;
  stringList << "Armor is penetrable by Krupp formula." << endl;
} else {
  cout << "The armor is not penetrable by the Krupp formula." << endl;
  stringList << "Armor is not penetrable by Krupp formula." << endl;
}

if (solveKrupp(armor, velocity, mass, resistance, caliber)) {
  cout << "The velocity is penetrable by the Krupp formula." << endl;
  stringList << "Velocity is penetrable by Krupp formula." << endl;
} else {
  cout << "The velocity is not penetrable by the Krupp formula." << endl;
  stringList << "Velocity is not penetrable by Krupp formula." << endl;
}

if (solveKrupp(armor, velocity, mass, resistance, caliber)) {
  cout << "The mass is penetrable by the Krupp formula." << endl;
  stringList << "Mass is penetrable by Krupp formula." << endl;
} else {
  cout << "The mass is not penetrable by the Krupp formula." << endl;
  stringList << "Mass is not penetrable by Krupp formula." << endl;
}

if (solveKrupp(armor, velocity, mass, resistance, caliber)) {
  cout << "The resistance is penetrable by the Krupp formula." << endl;
  stringList << "Resistance is penetrable by Krupp formula." << endl;
} else {
  cout << "The resistance is not penetrable by the Krupp formula." << endl;
  stringList << "Resistance is not penetrable by Krupp formula." << endl;
}

if (solveKrupp(armor, velocity, mass, resistance, caliber)) {
  cout << "The caliber is penetrable by the Krupp formula." << endl;
  stringList << "Caliber is penetrable by Krupp formula." << endl;
} else {
  cout << "The caliber is not penetrable by the Krupp formula." << endl;
  stringList << "Caliber is not penetrable by Krupp formula." << endl;
}


stringList.close();
















