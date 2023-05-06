
// Objective: The objective is to create a program that solves for a missing variable in the Krupp Equation:
// B = (V * sqrt(P)) / K * sqrt(D))
// B is the thickness of the armor penetrated in decimeters.
// V is the velocity of the shell on impact.
// P is the mass of the projectile (in kilograms).
// D is the caliber of the projectile.







#include <iostream>
#include <cmath>
#include <string>

int main() {
    double B, V, P, D, K;
    char missingVar;

    // Ask the user for the missing variable in the Krupp equation
    std::cout << "Enter the missing variable (B, V, P, D, or K): ";
    std::cin >> missingVar;

    switch (missingVar) {
        case 'B':
            // Ask for V, P, D, and K, then solve for B
            std::cout << "Enter V, P, D, and K: ";
            std::cin >> V >> P >> D >> K;
            B = (V * std::sqrt(P)) / (K * std::sqrt(D));
            std::cout << "B = " << B << std::endl;
            break;
        case 'V':
            // Ask for B, P, D, and K, then solve for V
            std::cout << "Enter B, P, D, and K: ";
            std::cin >> B >> P >> D >> K;
            V = (B * K * std::sqrt(D)) / std::sqrt(P);
            std::cout << "V = " << V << std::endl;
            break;
        case 'P':
            // Ask for B, V, D, and K, then solve for P
            std::cout << "Enter B, V, D, and K: ";
            std::cin >> B >> V >> D >> K;
            P = std::pow((V * B) / (K * std::sqrt(D)), 2);
            std::cout << "P = " << P << std::endl;
            break;
        case 'D':
            // Ask for B, V, P, and K, then solve for D
            std::cout << "Enter B, V, P, and K: ";
            std::cin >> B >> V >> P >> K;
            D = std::pow((V * std::sqrt(P)) / (B * K), 2);
            std::cout << "D = " << D << std::endl;
            break;
        case 'K':
            // Ask for B, V, P, and D, then solve for K
            std::cout << "Enter B, V, P, and D: ";
            std::cin >> B >> V >> P >> D;
            K = (V * std::sqrt(P)) / (B * std::sqrt(D));
            std::cout << "K = " << K << std::endl;
            break;
        default:
            // If the input is invalid, inform the user
            std::cout << "Invalid input. Please enter B, V, P, D, or K." << std::endl;
            break;
    }

    return 0;
}







