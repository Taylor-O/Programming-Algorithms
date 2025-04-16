/***************************************
The Strongest Link
Author: Taylor Reeves-Chavez
Date Completed: 4/7/2025
Description: A program that has the player answer questions and counts their streak
***************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <array>
#include "LinkedList.hpp"
using namespace std;

class Question {

   private:

   string questionPrompt;
   string firstAnswer;
   string secondAnswer;
   string thirdAnswer;
   string fourthAnswer;
   int correctAnswer;

   public:

   Question(string quest, string one, string two, string three, string four, int correct) :
   questionPrompt(quest), firstAnswer(one), secondAnswer(two), thirdAnswer(three), 
   fourthAnswer(four), correctAnswer(correct) {}

   string getPrompt() {

      return questionPrompt;

   }

   string getAnswerOptionByIndex(int index) {

      if (index == 0) {

         return firstAnswer;

      } else if (index == 1) {

         return secondAnswer;

      } else if (index == 2) {

         return thirdAnswer;

      } else {

         return fourthAnswer;

      }

   }

   int getCorrectAnswerIndex() {

      return correctAnswer;

   }

};

bool populateQuestionListFromFile(LinkedList <Question> &questions) {

   ifstream sampleFile;
   sampleFile.open("SampleQuestions.txt");

   if (sampleFile.is_open()){

      string fileLine;

      while (getline(sampleFile, fileLine)) {
   
         istringstream ss(fileLine);
   
         string question, correct, first, second, third, fourth;
         getline(ss, question, ';');
         getline(ss, correct, ';');
         getline(ss, first, ';');
         getline(ss, second, ';');
         getline(ss, third, ';');
         getline(ss, fourth, ';');
   
         int convertedCorrect;
         istringstream convert(correct);
         convert>>convertedCorrect;
   
         Question quiz (question, first, second, third, fourth, convertedCorrect - 1);
   
         questions.pushBack(quiz);
   
      }

      sampleFile.close();
      return true;

   } else {

      return false;

   }

}

int main() {

   LinkedList <Question> linkQuestions;
   populateQuestionListFromFile(linkQuestions);

   int questionNum = 1;
   int playerAnswer = 0;
   int currentCombo = 0;
   int strongLink = 0;

   cout << "Welcome to The Strongest Link!\n";

   while (!linkQuestions.empty()) {
      
      cout << "\nQuestion " << questionNum << ":\n";

      Question currentQuestion (linkQuestions.popFront());

      cout << currentQuestion.getPrompt() << "\n\n";

      cout << "1. "<< currentQuestion.getAnswerOptionByIndex(0) << "\n";
      cout << "2. "<< currentQuestion.getAnswerOptionByIndex(1) << "\n";
      cout << "3. "<< currentQuestion.getAnswerOptionByIndex(2) << "\n";
      cout << "4. "<< currentQuestion.getAnswerOptionByIndex(3) << "\n\n";

      cout << "Enter answer number: ";
      cin >> playerAnswer;
      playerAnswer -= 1;

      if (playerAnswer != currentQuestion.getCorrectAnswerIndex()) {

         cout << "Incorrect!\n";

         currentCombo = 0;

      } else {

         ++currentCombo;
         cout << "Correct!\n";

         if (currentCombo > strongLink) {

            strongLink = currentCombo;

         }

      }

      ++questionNum;

   } cout << "\nYour strongest link was " << strongLink << " correctly answered question(s) in a row. Thanks for playing!\n";

   return 0;

}