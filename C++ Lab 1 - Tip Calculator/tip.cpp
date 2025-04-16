/***************************************
Tip Calculator
Author: Taylor Reeves-Chavez
Date Completed: 1/28/2025
Description: A program helps calculates how much of a tip to leave for service recived.
***************************************/

#include <iostream>
#include <iomanip>
using namespace std;

int main() 
{
   float change = 0;
   int service = 0;
   float tip = 0;
   float total = 0;

   cout << "Welcome to the tip calculator tool!\n\n";
   cout << "How much were you charged? (in dollars)\n";

   cin >> change;

   cout << "\nHow was the service?\n";
   cout << "1. Very Good (20%)\n";
   cout << "2. Good (15%)\n";
   cout << "3. Poor (10%)\n";
   cout << "4. Very Poor (5%)\n";

   cin >> service;

   if (service == 1) {
      tip = change * 0.2;
      total = change + tip;
      cout << setprecision(2) << fixed << "\nTip Amount: $" << tip;
      cout << setprecision(2) << fixed << "\nTotal: $" << total;
   } else if (service == 2) {
      tip = change * 0.15;
      total = change + tip;
      cout << setprecision(2) << fixed << "\nTip Amount: $" << tip;
      cout << setprecision(2) << fixed << "\nTotal: $" << total;
   } else if (service == 3) {
      tip = change * 0.1;
      total = change + tip;
      cout << setprecision(2) << fixed << "\nTip Amount: $" << tip;
      cout << setprecision(2) << fixed << "\nTotal: $" << total;
   } else if (service == 4) {
      tip = change * 0.05;
      total = change + tip;
      cout << setprecision(2) << fixed << "\nTip Amount: $" << tip;
      cout << setprecision(2) << fixed << "\nTotal: $" << total;
   } else {
      cout << "\nNot a valid service rating number";
   }

   return 0;
}