/***************************************
Comic Book Collector
Author: Taylor Reeves-Chavez
Date Completed: 2/2/2025
Description: A comic book data entry system
***************************************/

#include <iostream>
#include <string>
using namespace std;

struct Comic {

   int issue;
   
   string title;

   int year;

   int ranking;

   string author;

};


Comic comicInput(int comicNumber) {

   Comic comic;

   cout << "Comic Book " << comicNumber << ":\n";
   cout << "Full Comic Book Title: ";
   getline(cin, comic.title);

   cout << "Issue Number: ";
   cin >> comic.issue;

   cout << "Year Published: ";
   cin >> comic.year;
   cin.ignore();

   cout << "Full Author Name: ";
   getline(cin, comic.author);

   cout << "Comic Ranking: ";
   cin >> comic.ranking;
   cout << "\n";
   cin.ignore();

   return comic;

}

void comicOutput(int comicNumber, Comic comic) {

   cout << "Comic Book " << comicNumber << ":\n";

   cout << comic.title << ", issue " << comic.issue << "\n";

   cout << "Published " << comic.year << "\n";

   cout << "Written by " << comic.author << "\n";

   cout << "Ranking: " << comic.ranking << "\n";

}

int main() {

   Comic comicBook1 = comicInput(1);
   Comic comicBook2 = comicInput(2);
   Comic comicBook3 = comicInput(3);

   system("cls||clear");

   comicOutput(1, comicBook1);
   cout << "\n";
   comicOutput(2, comicBook2);
   cout << "\n";
   comicOutput(3, comicBook3);

   return 0;

}