/***************************************
File Parse
Author: Taylor Reeves-Chavez
Date Completed: 4/6/2025
Description: A program that parses two files for specific information
***************************************/

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main() 
{
   ifstream inFile;
   ifstream inFile2;

   inFile.open("File1.txt");

   string fileLine;
   getline(inFile, fileLine);
   getline(inFile, fileLine);
   getline(inFile, fileLine);

   istringstream scanner(fileLine);
   getline(scanner, fileLine, ';');
   getline(scanner, fileLine, ';');

   inFile.close();
   inFile2.open("File2.txt");

   string fileLine2;
   getline(inFile2, fileLine2);
   getline(inFile2, fileLine2);

   istringstream scanner2(fileLine2);
   getline(scanner2, fileLine2, ';');
   getline(scanner2, fileLine2, ';');
   getline(scanner2, fileLine2, ';');

   inFile2.close();

   cout << fileLine << " and " << fileLine2 << "\n";

   return 0;
}