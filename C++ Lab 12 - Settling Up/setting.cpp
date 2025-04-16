/***************************************
Settling Up
Author: Taylor Reeves-Chavez
Date Completed: 3/23/2025
Description: A program that prints an itemized receipt
***************************************/

#include <iostream>
#include <iomanip>
#include "LinkedList.hpp"
using namespace std;

class InvoiceItem {

   private:

   string name;
   float price;

   public:

   InvoiceItem(string n, float p) : name(n), price(p) {}

   string getName() {

      return name;

   }

   float getPrice() {

      return price;

   }

};

int main() {

   InvoiceItem eggBacon ("Two egg, Two bacon breakfast", 10.99);
   InvoiceItem friedSteak ("Country fried steak and eggs breakfast", 16.49);
   InvoiceItem denver ("Denver omelet", 15.99);
   InvoiceItem shortStack ("Short stack and eggs breakfast", 12.99);
   InvoiceItem coffee ("Pot of coffee", 3.29);

   LinkedList<InvoiceItem> list;

   list.pushFront(eggBacon);
   list.pushBack(friedSteak);
   list.pushBack(denver);
   list.pushBack(shortStack);
   list.pushBack(coffee);

   cout << "Itemized Receipt:\n\n";

   float sub = 0;

   for (LinkedList<InvoiceItem>::Iterator iter = list.generateIterator(); iter.hasNext(); iter.next()) {

      sub = sub + iter.current()->getPrice();
      cout << "$" << iter.current()->getPrice() << " - " << iter.current()->getName() << "\n";

   }

   cout << setprecision(2) << fixed << "\nSub Total: $"<< sub << "\n";
   cout << setprecision(2) << fixed << "Total: $"<< sub * 1.0725 << "\n";

   return 0;
}