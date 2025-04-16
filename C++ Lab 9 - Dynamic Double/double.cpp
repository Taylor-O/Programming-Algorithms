/***************************************
Dynamic Double
Author: Taylor Reeves-Chavez
Date Completed: 3/1/2025
Description: A program that doubles the amount that the user inputs
***************************************/

#include <iostream>
using namespace std;

int* DoubleIt(int x) {

    return new int(x*2);

}

int main() {

    int x;
    
    cout << "Enter the starting integer value: ";
    cin >> x;
    cout << "\n";

    cout << "The current value is " << x << "\n";

    cout << "\nWould you like to double the value? (y = yes, n = no)\n";
    char doubleNum = 'n';
    cin >> doubleNum;

    int* y;

    while (doubleNum == 'y') {

        y = DoubleIt(x);

        cout << "\nThe current value is " << *y << "\n";

        x = *y;

        delete y;
        y = nullptr;

        cout << "\nWould you like to double the value? (y = yes, n = no)\n";
        cin >> doubleNum;
    }

return 0;
}