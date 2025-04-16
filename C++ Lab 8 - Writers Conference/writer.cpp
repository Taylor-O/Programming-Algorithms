/***************************************
Writers Conference
Author: Taylor Reeves-Chavez
Date Completed: 3/1/2025
Description: A program that lets a writer go into a conference
***************************************/

#include <iostream>
#include <string>
using namespace std;

class ConferenceSession {

    private:

    string Title;

    string Description;

    int Room;

    public:

    ConferenceSession (string t, string d, int r)
    : Title(t), Description(d), Room(r) {}

    string getTitle() {

        return Title;

    }

    string getDescription() {

        return Description;

    }

    int getRoom() {

        return Room;

    }

};

int main() {

    cout << "Welcome to the story writers conference!\n";

    ConferenceSession meeting ("Meet Your Characters", "Creating authentic characters is a challenge for every writer. "
    "This is an opportunity to meet your characters in the flesh. "
    "Come learn techniques to turn any actor into one of your characters within a few minutes.", 3);

    ConferenceSession power ("The Power Of Staging", "How we feel is revealed through our body language, "
    "our physical relationship to others, and to the environment. "
    "Conversely, we can trigger genuine emotional reactions in the actors and in the audience through "
    "the staging of each and every moment in a scene. Come learn techniques that can enhance every "
    "scene and every character in every moment.", 4);

    ConferenceSession acting ("Action Scenes", "In this action-packed session, you'll learn how to write an effective plot twist, "
    "create unbearable suspense, and design exciting action sequences using reversals, diversion, "
    "and anticipation. Don't miss this session with dozens of techniques that can be used in any genre.", 2);

    ConferenceSession building  ("Building The Board", "Walk into a writers' room in Hollywood and what do you see? Boards. "
    "Boards are all over the walls! After you've done your beat sheet, "
    "the Board is the best way to take things to the next level. "
    "Learn how to turn your beat sheet into 40 cards that lay out your entire story, "
    "and how to track conflict and emotional changes in every scene.", 1);
    
    bool conferenceBool = true;
    int conferenceInt = 0;

    while (conferenceBool == true) {

        cout << "\nWhich session would you like to view?\n";

        cout << "1. Meet Your Characters\n";
        cout << "2. The Power Of Staging\n";
        cout << "3. Action Scenes\n";
        cout << "4. Building The Board\n";
        cout << "5. Exit\n";
        cin >> conferenceInt;

        switch (conferenceInt)  {

            case 1:

            cout << "\n" << meeting.getTitle() << ", Room " << meeting.getRoom() << "\nDescription: " << meeting.getDescription() << "\n";
            break;

            case 2:

            cout << "\n" << power.getTitle() << ", Room " << power.getRoom() << "\nDescription: " << power.getDescription() << "\n";
            break;

            case 3:

            cout << "\n" << acting.getTitle() << ", Room " << acting.getRoom() << "\nDescription: " << acting.getDescription() << "\n";
            break;

            case 4:

            cout << "\n" << building.getTitle() << ", Room " << building.getRoom() << "\nDescription: " << building.getDescription() << "\n";
            break;

            default:

            conferenceBool = false;

        }

    }

   return 0;
}