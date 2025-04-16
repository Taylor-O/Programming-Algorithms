/***************************************
Memory Game
Author: Taylor Reeves-Chavez
Date Completed: 2/21/2025
Description: A program that simulates a game of Memory
***************************************/

#include <iostream>
#include <array>
#include "RandomInt.hpp"
using namespace std;

struct Card {

    string Phrase;

    bool Matched;

};

bool allCardsMatched(array <Card, 4> &cards) {

    if (cards.at(0).Matched != true) {

        return false;

    } else if (cards.at(1).Matched != true) {

        return false;

    } else if (cards.at(2).Matched != true) {

        return false;

    } else if (cards.at(3).Matched != true) {

        return false;

    } else {

        return true;

    }

}

void displayGameBoard(array <Card*, 8> &cardsPrt) {

    if (cardsPrt.at(0)->Matched == true) {

        cout << "Card 1: " << cardsPrt.at(0)->Phrase << "\n";

    } else {

        cout << "Card 1: ?\n";

    }
    
    if (cardsPrt.at(1)->Matched == true) {

        cout << "Card 2: " << cardsPrt.at(1)->Phrase << "\n";

    } else {

        cout << "Card 2: ?\n";

    }

    if (cardsPrt.at(2)->Matched == true) {

        cout << "Card 3: " << cardsPrt.at(2)->Phrase << "\n";

    } else {

        cout << "Card 3: ?\n";

    }

    if (cardsPrt.at(3)->Matched == true) {

        cout << "Card 4: " << cardsPrt.at(3)->Phrase << "\n";

    } else {

        cout << "Card 4: ?\n";

    }

    if (cardsPrt.at(4)->Matched == true) {

        cout << "Card 5: " << cardsPrt.at(4)->Phrase << "\n";

    } else {

        cout << "Card 5: ?\n";

    }

    if (cardsPrt.at(5)->Matched == true) {

        cout << "Card 6: " << cardsPrt.at(5)->Phrase << "\n";

    } else {

        cout << "Card 6: ?\n";

    }

    if (cardsPrt.at(6)->Matched == true) {

        cout << "Card 7: " << cardsPrt.at(6)->Phrase << "\n";

    } else {

        cout << "Card 7: ?\n";

    }

    if (cardsPrt.at(7)->Matched == true) {

        cout << "Card 8: " << cardsPrt.at(7)->Phrase << "\n";

    } else {

        cout << "Card 8: ?\n";

    }

}

void buildRandomCardPointerArray (array <Card, 4> &cards, array <Card*, 8> &cardsPrt) {

    Random::RandomInt randomIntGenerator(0, 3, 2);

    cardsPrt.at(0) = &cards.at(randomIntGenerator.get());
    cardsPrt.at(1) = &cards.at(randomIntGenerator.get());
    cardsPrt.at(2) = &cards.at(randomIntGenerator.get());
    cardsPrt.at(3) = &cards.at(randomIntGenerator.get());

    cardsPrt.at(4) = &cards.at(randomIntGenerator.get());
    cardsPrt.at(5) = &cards.at(randomIntGenerator.get());
    cardsPrt.at(6) = &cards.at(randomIntGenerator.get());
    cardsPrt.at(7) = &cards.at(randomIntGenerator.get());

}

int main() {
   
   array <Card, 4> cards;

   cards.at(0) = {"Flying Monkey", false};
   cards.at(1) = {"Mad Cow", false};
   cards.at(2) = {"Magic Genie", false};
   cards.at(3) = {"Great Pumpkin", false};

   array <Card*, 8> cardsPrt;

   buildRandomCardPointerArray(cards, cardsPrt);

   cout << "Welcome to Memory Game!\n\n";

   int guesses = 0;

   while (allCardsMatched(cards) == false)
   {
 
    cout << "Total Guesses: " << guesses << "\n\n";
 
    displayGameBoard(cardsPrt);
 
    cout << "\nSelect two different cards between 1 and 8:\n";
 
    int guess1, guess2;
    cin >> guess1 >> guess2;
 
    guess1 -= 1;
    guess2 -= 1;
 
    if (cardsPrt.at(guess1)->Phrase == cardsPrt.at(guess2)->Phrase) {
 
     cout << "You found a matching pair!\n";
     cout << "Both cards say \"" << cardsPrt.at(guess1)->Phrase << "\"\n";
     cardsPrt.at(guess1)->Matched = true;
 
    } else {
 
     cout << "The cards don't match\n";
     cout << "First card says \"" << cardsPrt.at(guess1)->Phrase << "\"\n";
     cout << "Second card says \"" << cardsPrt.at(guess2)->Phrase << "\"\n";
 
    }
 
    cout << "PRESS ENTER KEY TO CONTINUE...\n";
    string enter;
    cin.ignore();
    getline(cin, enter);
    system("cls||clear");

    guesses += 1;

   }

   cout << "Total Guesses: " << guesses << "\n\n";

   cout << "Card 1: " << cardsPrt.at(0)->Phrase << "\n";
   cout << "Card 2: " << cardsPrt.at(1)->Phrase << "\n";
   cout << "Card 3: " << cardsPrt.at(2)->Phrase << "\n";
   cout << "Card 4: " << cardsPrt.at(3)->Phrase << "\n";

   cout << "Card 5: " << cardsPrt.at(4)->Phrase << "\n";
   cout << "Card 6: " << cardsPrt.at(5)->Phrase << "\n";
   cout << "Card 7: " << cardsPrt.at(6)->Phrase << "\n";
   cout << "Card 8: " << cardsPrt.at(7)->Phrase << "\n\n";

   cout << "You matched all of the cards! Game over.\n";
   
   return 0;
}