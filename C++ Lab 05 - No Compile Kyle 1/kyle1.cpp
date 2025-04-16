/***********************************************************
Simple Math Calculator
Author: Kyle NoCompile
Date Completed: 9/12/18
Description:
This program performs simple arithmetic calculations.
The user enters numbers and the math operation to
perform on those numbers. The program will then display
the result of the operation.
Modified Date:
Modified Description:
***********************************************************/
#include <iostream>
using namespace std;
// Definition of Calculator custom data type
struct Calculator
{
// Member variables
int FirstNum;
int SecondNum;
char* MathOperator;
// Member function "calculate" used to calcualte the result
// based on the values currently stored on the object.
// Will return false if no valid math operator is stored or if
// the math operator is not a '+' or a '-'
// Assuming no validation problems, will update the result
// parameter with the result of the calculation.
bool calculate(int &result)
{
if (MathOperator != nullptr)
{
if (*MathOperator == '+')
{
result = FirstNum + SecondNum;
return true;
}
else if (*MathOperator == '-')
{
result = FirstNum - SecondNum;
return true;
}
else
{
return false;
}
}
return false;
}
};
// This function shows a nice welcome message
void showWelcome()
{
cout<<"******************************************"<<endl;
cout<<"Welcome to the simple calculator program!"<<endl;
cout<<"This program will do simple addition and"<<endl;
cout<<"subtraction. Math is fun, so enjoy!"<<endl;
cout<<"******************************************"<<endl;
}
// This function builds a default Calculator object with
// initialized member variables and returns it
Calculator buildCalculator()
{
Calculator c;
c.FirstNum = 0;
c.SecondNum == 0;
c.MathOperator = nullptr;
return c;
}
// this function asks the user for either the first integer
// or the second and returns the user's input
int getInteger(bool firstNumber)
{
cout<<endl<<"Please enter the ";
// if the "firstNumber" variable is true, then this
// is the first number being collected
if (firstNumber)
{
cout<<"first ";
}
// Otherwise, it's the second number being collected
else
{
cout<<"second ";
}
cout<<"integer: ";
int input;
cin>>input;
return input;
}
// This is the main function (where the program begins)
int main()
{
//Instantiate Calculator object by calling the buildCalculator function
Calculator calculator = buildCalculator();
// Call the showWelcome() function
showWelcome();
// Call the getInteger() function (for the first integer)
// and store the result in the "FirstNum" member variable of the calculator
// object
calculator.FirstNum = getInteger(true);
// Ask the user to enter a math operator and store the value
char mathOperator;
cout<<endl<<"Please select a math operator to perform (\"+\" = Addition, \"-\"";
cout<<" = Subtraction): ";
cin>>mathOperator;
// If the math operator entered by the user is a '+' or '-',
// set the calculator object's MathOperator member variable to point to the
// entered data
if (mathOperator == '+' || mathOperator == '-')
{
calculator.MathOperator = &mathOperator;
}
// Call the getInteger() function (for the second integer)
// and store the result in the "SecondNum" member variable of the calculator
// object
calculator.SecondNum = getInteger(false);
// Run the "calculate" member function on the calculator object and display
// appropriate message to user
int result;
if (calculator.calculate(result))
{
cout<<endl<<"The result is "<<result<<endl;
}
else
{
cout<<endl<<"Not a valid math operator"<<endl;
}
return 0;
}