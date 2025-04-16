/***************************************
Who Would Win?
Author: Taylor Reeves-Chavez
Date Completed: 2/16/2025
Description: A program that pits two animals against each other
***************************************/

#include <iostream>
#include <string>
#include <array>
using namespace std;

struct Animal {

   string Type;

   int Strength;

   int Toughness;

   int Luck;


};

Animal determineWinner(array <Animal, 5> animals, int firstAnimal, int secondAnimal) {

   int strTough1 = animals.at(firstAnimal).Strength + animals.at(firstAnimal).Toughness;

   int strTough2 = animals.at(secondAnimal).Strength + animals.at(secondAnimal).Toughness;

   if (strTough1 > strTough2) {

      strTough2 += animals.at(secondAnimal).Luck;

   } else if (strTough1 < strTough2) {

      strTough1 += animals.at(firstAnimal).Luck;

   } else {

      strTough1 += animals.at(firstAnimal).Luck;
      strTough2 += animals.at(secondAnimal).Luck;

   }

   if (strTough1 > strTough2) {

      return animals.at(firstAnimal);

   } else {

      return animals.at(secondAnimal);

   }
   

}

int main() {  
   
   array <Animal, 5> animals;

   animals.at(0) = {"Bear", 8, 6, 2};
   animals.at(1) = {"Shark", 5, 5, 3};
   animals.at(2) = {"Gorilla", 7, 5, 3};
   animals.at(3) = {"Lion", 5, 6, 4};
   animals.at(4) = {"Crocodile", 3, 9, 4};

   int firstAnimal, secondAnimal;

   cout << "From the following list, pick two different animals to fight:\n";

   cout << "1. " << animals.at(0).Type << "\n";
   cout << "2. " << animals.at(1).Type << "\n";
   cout << "3. " << animals.at(2).Type << "\n";
   cout << "4. " << animals.at(3).Type << "\n";
   cout << "5. " << animals.at(4).Type << "\n";

   cin >> firstAnimal >> secondAnimal;

   firstAnimal -= 1;
   secondAnimal -= 1;

   if (firstAnimal != secondAnimal) {
   
      Animal winner = determineWinner(animals, firstAnimal, secondAnimal);

      cout << "\nThe " << winner.Type << " is the winner!\n";

   } else {

      cout << "\nYou must choose two different animals\n";

   }

   return 0;
}