/***********************************************************
Program Name: Vehicle Searcher
Program Author: Kyle NoCompile
Date Completed: 3/17/19
Program Description:
    This program allows the user to search for a vehicle
    from the data supplied in a "VehiclesForSale.xml"
    file and filter based on vehicle year and price.

Modified Date: 4/15/2025
Modified Description: A fixed program that uses xml to find a vehicle
***********************************************************/

#include <iostream>
#include <vector>
#include <string>
#include "pugixml.hpp" // Using pugixml library to parse XML
using namespace std;

// Definition of Vehicle custom data type
class Vehicle
{
    private:

    string make_;

    string model_;

    int year_;

    float price_;

    
    public:
    
    // Constructor with initializer list
    Vehicle(string make, string model, int year, float price)
        : make_(make), model_(model), year_(year), price_(price) {}

    // Vehicle make getter
    string getMake() {

        return make_;

    }

    // Vehicle model getter
    string getModel() {

        return model_;

    }

    // Vehicle year getter
    int getYear() {

        return year_;

    }

    // Vehicle year getter
    float getPrice() {

        return price_;

    }
};


int main() {

    // Instantiate vector to hold all vehicle objects parsed from XML
    vector<Vehicle> vehicles;

    // Instantiate xml document variable and load "VehiclesForSale.xml" file
    pugi::xml_document doc;
    if (!doc.load_file("VehiclesForSale.xml")) {

        cerr<<"Problem opening xml file \"VehiclesForSale.xml\"\n";
        return 0;

    }

    // Get the root node in the XML file
    pugi::xml_node root = doc.first_child();

    // Loop through all "vehicle" elements in the XML file
    for (pugi::xml_node xmlVehicle : root.children("vehicle"))
    {
        // Get make, model, year, and price from current vehicle element 
        string make = xmlVehicle.child_value("make");
        string model = xmlVehicle.child_value("model");
        string year = xmlVehicle.child_value("year");
        string price = xmlVehicle.child_value("price"); 

        // Instantiate Vehicle object using values from XML
        // Use stoi function to convert year from string to integer
        // Use stof function to convert price from string to float
        Vehicle vehicle(make, model, stoi(year), stof(price));

        // Push vehicle object to back of vector
        vehicles.push_back(vehicle);
    }

    // Variables to hold user input
    int minYear(0);
    float maxPrice(0);
    
    // Prompt and get user minimum vehicle year for filtering
    cout << "Enter the minimum vehicle year to show: ";
    cin >> minYear;

    // Prompt and get user minimum vehicle price for filtering
    cout << "Enter the maximum price to show: ";
    cin >> maxPrice;

    cout << "\nResults:\n";

    // Loop through vector of vehicle objects
    for (Vehicle &v : vehicles)
    {
        // Only show vehicles that have a year greater than or equal to the minimum 
        // year and a price less than or equal to the maximum year specified by the user
        if (v.getYear() >= minYear && v.getPrice() <= maxPrice)
        {
            cout << endl << v.getYear() << " " << v.getMake() << " " << v.getModel() << endl;
            cout << "$" << v.getPrice() << endl;
        }
    }

    return 0;
}