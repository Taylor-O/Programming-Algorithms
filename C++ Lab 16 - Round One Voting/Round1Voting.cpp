/***************************************
Round One Voting
Author: Taylor Reeves-Chavez
Date Completed: 4/20/2025
Description: A program that caluclates votes and displays them to terminal
***************************************/

#include <iostream>
#include "HashTable.hpp"
using namespace std;

// Implement definition of Candidate data type here

class Candidate {

    private:

    string Id;
    string Name;

    public:

    Candidate (string _id, string _name) : Id(_id), Name(_name) {}

    string getId() {

        return Id;

    }

    string getName() {

        return Name;

    }

};

// Implement definition of Ballot data type here

class Ballot {

    private:

    string idOne;
    string idTwo;
    string idThree;

    public:

    Ballot (string first, string second, string last) : idOne(first), idTwo(second), idThree(last) {}

    string getHighestRankedCandidate() {

        return idOne;

    }

};

// Implement body of "tallyRound1Votes" non-member function
HashTable<int> tallyRound1Votes(LinkedList<Ballot> &ballots, HashTable<Candidate> &candidates) {

    HashTable<int> tallyNumber;

    for (HashTable<Candidate>::Iterator iter = candidates.generateIterator(); iter.hasNext(); iter.next()) {

        tallyNumber.add(iter.current()->first, 0);

    }

    for (LinkedList<Ballot>::Iterator iter = ballots.generateIterator(); iter.hasNext(); iter.next()) {

        string first = iter.current()->getHighestRankedCandidate();

        *tallyNumber.get(first) += 1;

    }

    return tallyNumber;

}

// Implement body of "processRound1Results" non-member function
void processRound1Results(HashTable<int> &talliedVotes, HashTable<Candidate> &candidates, float halfOfVotes) {

    cout << "Round 1 Results:\n";

    string winner = "";
    string loser = "";

    for (HashTable<Candidate>::Iterator iter = candidates.generateIterator(); iter.hasNext(); iter.next()) {

        cout << iter.current()->second.getName() << ": " << *talliedVotes.get(iter.current()->first) << " vote(s)\n";

        if (*talliedVotes.get(iter.current()->first) > halfOfVotes) {

            winner = iter.current()->second.getName();

        }

        if (loser == "") {

            loser = iter.current()->first;

        } else {

            if (*talliedVotes.get(loser) > *talliedVotes.get(iter.current()->first)) {

                loser = iter.current()->first;

            }

        }

    }

    if (winner != "") {

        cout << "\n"<< winner << " is the winner!\n";

    } else {

        cout << "\nNo candidate had more than 50% of the votes\n";
        cout << candidates.get(loser)->getName() << " had the least number of votes and will be eliminated\n";

    }

}


// This function is used to test implementation of the "tallyRound1Votes"
// and "processRound1Results" non-member functions.
void test1()
{
    LinkedList<Ballot> ballots;
    ballots.pushFront(Ballot("CC", "CB", "CA"));
    ballots.pushFront(Ballot("CB", "CA", "CC"));
    ballots.pushFront(Ballot("CC", "CB", "CA"));
    ballots.pushFront(Ballot("CC", "CA", "CB"));
    ballots.pushFront(Ballot("CA", "CB", "CC"));
    ballots.pushFront(Ballot("CC", "CA", "CB"));
    ballots.pushFront(Ballot("CB", "CA", "CC"));
    ballots.pushFront(Ballot("CA", "CB", "CC"));
    ballots.pushFront(Ballot("CB", "CC", "CA"));
    ballots.pushFront(Ballot("CA", "CB", "CC"));
    ballots.pushFront(Ballot("CC", "CB", "CA"));
    ballots.pushFront(Ballot("CC", "CA", "CB"));
    ballots.pushFront(Ballot("CB", "CA", "CC"));

  
    HashTable<Candidate> candidates;
    candidates.add("CA", Candidate("CA", "Candidate A"));
    candidates.add("CB", Candidate("CB", "Candidate B"));
    candidates.add("CC", Candidate("CC", "Candidate C"));



    int totalVotes(ballots.size());
    float halfOfVotes = float(totalVotes)/2;
    
    cout<<"Total Votes: "<<totalVotes<<endl<<endl;

    HashTable<int> talliedVotes = tallyRound1Votes(ballots, candidates);
    processRound1Results(talliedVotes, candidates, halfOfVotes);
}


// This function is used to test implementation of the "tallyRound1Votes"
// and "processRound1Results" non-member functions.
void test2()
{
    LinkedList<Ballot> ballots;
    ballots.pushFront(Ballot("3", "4", "2"));
    ballots.pushFront(Ballot("2", "1", "4"));
    ballots.pushFront(Ballot("4", "2", "3"));
    ballots.pushFront(Ballot("3", "1", "2"));
    ballots.pushFront(Ballot("1", "4", "2"));
    ballots.pushFront(Ballot("3", "1", "2"));
    ballots.pushFront(Ballot("3", "2", "1"));
    ballots.pushFront(Ballot("1", "2", "3"));
    ballots.pushFront(Ballot("3", "1", "4"));
    ballots.pushFront(Ballot("4", "2", "3"));
    ballots.pushFront(Ballot("3", "1", "2"));

  
    HashTable<Candidate> candidates;
    candidates.add("1", Candidate("1", "Candidate A"));
    candidates.add("2", Candidate("2", "Candidate B"));
    candidates.add("3", Candidate("3", "Candidate C"));
    candidates.add("4", Candidate("4", "Candidate D"));


    int totalVotes(ballots.size());
    float halfOfVotes = float(totalVotes)/2;
    
    cout<<"Total Votes: "<<totalVotes<<endl<<endl;

    HashTable<int> talliedVotes = tallyRound1Votes(ballots, candidates);
    processRound1Results(talliedVotes, candidates, halfOfVotes);
}



// Driver code calls both tests
int main()
{
    cout<<"Test 1:\n\n";
    test1();

    cout<<"\n\nTest 2:\n\n";
    test2();

    return 0;
}