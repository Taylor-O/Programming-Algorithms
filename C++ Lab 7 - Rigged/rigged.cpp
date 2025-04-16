/***************************************
Rigged
Author: Taylor Reeves-Chavez
Date Completed: 2/25/2025
Description: A totally fair game that isn't rigged
***************************************/

#include <iostream>
#include "RandomInt.hpp"
using namespace std;

int main() {

    cout << "Welcome to the totally fair game!\n\n";

    cout << "If you get all matching numbers, you win. Otherwise, you lose.\n";
    cout << "Enter the size of the set of numbers to produce (min = 2)\n";

    int userValue = 0;
    cin >> userValue;

    Random::RandomInt randomIntGenerator(1, 7, userValue - 1);

    int i = 0;
    while (i < userValue - 1) {

        cout << randomIntGenerator.get() << " ";
        ++i;

    }

    cout << randomIntGenerator.get();

    cout << "\nNot all numbers match. I can't believe you lost!\n";
   
   return 0;
}
