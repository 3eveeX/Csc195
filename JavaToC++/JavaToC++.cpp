#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	int guessAmount;
	int numericalGuess;
	int randomNumber;
	bool won;
	string input;
	srand(time(0));
guessNumber:
	do {
		won = false;
		cout << "Enter a number of guesses. (between 1 and 12)" << endl;
		try {
			cin >> input;
			guessAmount = stoi(input);
		}
		catch (invalid_argument) {
			cout << "Please enter a number." << endl;
			continue;
		}
		if (guessAmount > 12 || guessAmount < 1) {
			cout << "please enter a number between 1 and 12." << endl;
			continue;
		}
		else {
			randomNumber = rand() % 50 + 1;
			break;
		}
	} while (true);

	for (int i = 0; i < guessAmount; i++) {
		cout << "Guesses left: ";
		cout << (guessAmount - i) << endl;
		cout << "Enter a number to guess between 1 and 50." << endl;
		try {
			cin >> input;
			numericalGuess = stoi(input);
		}
		catch (invalid_argument) {
			cout << "Please enter a number." << endl;
			continue;
		}
		if (numericalGuess < randomNumber) {
			cout << "Higher" << endl;
		}
		else if (numericalGuess > randomNumber) {
			cout << "Lower" << endl;
		}
		else {
			cout << "You win." << endl;
			won = true;
			break;
		}

	}

	if (won == false) {
		cout << "You lost. The number was " << randomNumber << endl;
	}

	do {
		cout << "Play again?" << endl;
		cout << "1) yes" << endl;
		cout << "2) no" << endl;
		cin >> input;
		if (input == "1") {
			goto guessNumber;
		}
		else if (input == "2") {
			break;
		}
		else {
			cout << "Please enter a 1 or a 2." << endl;
		}
	} while (true);

	return 0;
}

