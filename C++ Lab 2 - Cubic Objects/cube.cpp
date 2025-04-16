/***************************************
 Cubic Objects
 Author: Taylor Reeves-Chavez
 Date Completed: 2/1/2025
 Description: Creates cubioids from user input
 ***************************************/
#include <iostream>
using namespace std;

struct Cuboid {

   int length;
   int width;
   int height;

   int volume () {

       return length * width * height;

   }
};

Cuboid buildCuboidFromUserInput (int cuboidNum) {

  Cuboid cuboidBuild;

  cout << "Cuboid " << cuboidNum << ":\n";
  cout << "Enter the length:\n";
  cin >> cuboidBuild.length;

  cout << "Enter the width:\n";
  cin >> cuboidBuild.width;

  cout << "Enter the height:\n";
  cin >> cuboidBuild.height;
  cout <<"\n";

  return cuboidBuild;

}
int main() {

  Cuboid cuboid1 = buildCuboidFromUserInput(1);
  Cuboid cuboid2 = buildCuboidFromUserInput(2);

  cout << "Cuboid 1 Volume: " << cuboid1.volume() << "\n";
  cout << "Cuboid 2 Volume: " << cuboid2.volume() << "\n";

  return 0;

}