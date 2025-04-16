/***********************************************************
Program Name: Stargaze Simulator
Program Author: Kyle NoCompile
Date Completed: 9/4/18
Program Description:
    This program allows the user to simulate stargazing
    by allowing them to choose a location to point a
    "telescope" into the "sky" and see different planets.

    Just as in reality, not all locations reveal a planet,
    so the user must explore through trial and error.
    
    Planetary data source: 
    https://nssdc.gsfc.nasa.gov/planetary/factsheet/

Modified Date: 3/4/2025
Modified Description:
***********************************************************/

#include <iostream>
#include <array>
using namespace std;

// Definition of Planet custom data type
class Planet
{
    // Member variables (shouldn't be modified from outside of object)
    string name_; 
    float distanceFromSum_; // in kilometers * 10^6
    int diameter_; // in kilometers
    float averageTemperature_; // in celsius
    int moonCount_;
    
    public:

    // Planet constructor with initializer list to initialize member variables
    Planet (string name, float distFromSun, int diameter, float averageTemp, int moons)
        : name_(name), distanceFromSum_(distFromSun), diameter_(diameter), averageTemperature_(averageTemp), moonCount_(moons)
    {}

    // Name getter member function
    string getName()
    {
        return name_;
    }

    // Distance from sun getter member function
    float getDistanceFromSun()
    {
        return distanceFromSum_;
    }

    // Diameter getter member function
    int getDiameter()
    {
        return diameter_;
    }

    // Average temperator getter member function
    float getAverageTemperature()
    {
        return averageTemperature_;
    }

    // Moon count getter member function
    int getMoonCount()
    {
        return moonCount_;
    }
};

// Definition of Telescope custom data type
class Telescope
{

    // Member variable used to point to a Planet object
    Planet *targetPlanet_;

    
    public:

    // Telescope constructor with initializer list that initializes the target planet to nullptr
    Telescope() : targetPlanet_(nullptr){}

    // Target planet setter member function
    void setTargetPlanet(Planet* newTarget)
    {
        targetPlanet_ = newTarget;
    }

    // Member function to print target planet details to Stdout 
    void targetPlanetToStdout()
    {
        // Only print planet details if telescope is actually pointing to a Planet object
        if (targetPlanet_ != nullptr)
        {
            cout<<"Planet Name: "<<targetPlanet_->getName()<<endl;
            cout<<"Distance From Sun: "<<targetPlanet_->getDistanceFromSun()<<" * 10^6 kilometers\n";
            cout<<"Diameter: "<<targetPlanet_->getDiameter()<<" kilometers\n";
            cout<<"Average Temperature: "<<targetPlanet_->getAverageTemperature()<<" degrees (C)\n";
            cout<<"Number Of Moons: "<<targetPlanet_->getMoonCount()<<endl;
        }
        else
        {
            cout<<"No planet found!\n";
        }
    }

};


int main()
{
    // Instantiate array of pointer to Planet objects and
    // use brace-initialization to initialize array.

    // All Planet objects use dynamic memory (i.e., heap memory)

    // Adding several nullptr values in the array to signify
    // distance between planets in solar system.

    array<Planet*, 40> planets
    {{
        new Planet("Mercury", 57.9, 4879, 167, 0),
        nullptr,
        new Planet("Venus", 108.2, 12104, 464, 0),
        new Planet("Mars", 227.9, 6792, -65, 2),
        nullptr,
        nullptr,
        new Planet("Jupiter", 778.6, 142984, -110, 79),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        new Planet("Saturn", 1433.5, 120536, -140, 82),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        new Planet("Uranus", 2872.5, 51118, -195, 27),
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        new Planet("Neptune", 4495.1, 49528, -200, 14),
        nullptr,
        nullptr,
        nullptr,
        new Planet("Pluto", 5906.4, 2370, -225, 5)
    }};


    // Instantiate Telescope object that will be used to 
    // target (i.e., look at) Planet objects
    Telescope telescope;

    cout<<"Welcome to Stargaze Simulator!\n";

    // Use simple single character variable to indicate
    // if the user wants to keep running the program
    char keepGazing = 'y';
    while (keepGazing == 'y')
    {

        // Prompt user for telescope location number to use and collect user input
        int location;
        cout<<"\nChoose a location to point the telescope. Select a location number between 1-40.\n";
        cin>>location;

        // Validate that the user entered a valid location number (i.e., between 1-40 inclusive)
        if (location < 1 || location > 40)
        {
            cout<<"You must select a location number between 1-40\n";
        }
        else
        {
            // Set the telescope's target planet to the corresponding Planet object in the array.
            // Since array's use zero-based indexes, be sure to translate user input to actual array index
            telescope.setTargetPlanet(planets.at(location - 1));

            // Display the target information to the CLI
            telescope.targetPlanetToStdout();
        }

        // Prompt user to keep going and collect user input
        cout<<"\nWould you like to keep stargazing? (y = yes, n = no)\n";
        cin>>keepGazing;
    }


    // Delete dynamic memory before closing program...
    for (int i = 0; i < planets.size(); ++i)
    {
        // Check to see if pointer at array index actually points to a Planet object
        if (planets.at(i) != nullptr)
        {
            delete planets.at(i);
            planets.at(i) = nullptr; // don't leave dangling pointer
        }
    }

    return 0;
}