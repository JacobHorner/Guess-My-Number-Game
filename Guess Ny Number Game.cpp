//Number Guessing Game
//Jacob R. Horner
//17 November 2014

#include "iostream"
#include "time.h"
using namespace std;

void main()
{

//Declare Variables
	int numGuess = 10;				//number of guesses allowed (can be changed in game)
	int range = 100;				//range of numbers for guesses (can be changed in game)
	char newRules;					//selection for a new rule set
	char newGame;					//selection for a new game possibly with new rules
	char newRound;					//selection for a new round with the same rule set
	
//begin game
	do{
		cout << "Welcome to the Guess My Number game!" << endl;
		cout << "Would you like to change the rules (y/n)" << endl;
		cin >> newRules;
		cout << " " << endl;

		if (newRules == 'y' || newRules == 'Y')
		{
			cout << "How many guesses are allowed?" << endl;
			cin >> numGuess;
			cout << " " << endl;

			cout << "How many numbers would you like to include?" << endl;
			cin >> range;
			cout << " " << endl;
		}

		int wins = 0;
		int losses = 0;

		do 
		{
			int myNumber = (rand()*clock())%range;   //tied the psuedo random number generator to the clock
			int yourGuess = 0;
			int error = 0;
			bool winner = false;
			
			cout << "I have guessed a number! Can you figure it out?" << endl;
			cout << "You have " << numGuess << " guesses to figure out a number between 0 and " << range << "." << endl;
			cout << " " << endl;

			for (int i = 1; i <= numGuess && winner == false; i++)
			{
				cout << "Guess Number " << i << ":" << endl;
				cin >> yourGuess;
				cout << " " << endl;

				if (yourGuess > myNumber)
				{
					cout << "Sorry, but " << yourGuess << " is too high" << endl;
					cout << " " << endl;
					winner = false;
				}

				if (yourGuess < myNumber)
				{
					cout << "Sorry, but " << yourGuess << " is too low" << endl;
					cout << " " << endl;
					winner = false;
				}

				if (yourGuess == myNumber)
				{
					cout << "Congratulations!! You guessed the Number :)" << endl;
					cout << " " << endl;
					winner = true;
				}
			}

			if (winner == false)
			{
				cout << "Sorry, you didn't win this time. My number was " << myNumber << "." << endl;
				losses++;
			}
			else
			{
				wins++;
			}

			cout << "Your current score is " << wins << " win(s), and " << losses << " losse(s)." << endl;
			cout << "Would you like to play another round? (y/n)" << endl;
			cin >> newRound;
			cout << " " << endl;

		} while (newRound == 'y' || newRound == 'Y');

		cout << "Would you like to start a new game? (y/n)" << endl;
		cin >> newGame;

	} while (newGame == 'y' || newGame == 'Y');
};