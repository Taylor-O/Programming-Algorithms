/***************************************
Automated Introspection
Author: Taylor Reeves-Chavez
Date Completed: 2/8/2025
Description: A program that helps the user think of a thought
***************************************/

#include <iostream>
using namespace std;

string* MakePhilosophical (string &importantWords) {

    string *importantWordsPrt = &importantWords;
    
    importantWordsPrt ->append (", right?");

    return importantWordsPrt;

}

int main() {

   cout << "Enter a simple belief:\n";

   string words;
   getline(cin, words);
   cout << "\n";


   cout << "Re-examined Belief:\n";
   string* speicalWords = MakePhilosophical(words);
   cout << *speicalWords;
   cout << "\n\n";

   cout << "Analysis: ";

   if ((&words)->length() < 25){
    
    cout << "Pithy and profound!";

   } else {

    cout << "Best not to think about it";

   }

   cout << "\n";
   
   return 0;
}