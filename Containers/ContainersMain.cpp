#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <stack>
#include <map>

using namespace std;


void week() {
	array<string, 7> daysOfWeek = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	//prints out the length of the array (7)
	cout << daysOfWeek.size() << endl;
	//iterates through the array and prints out the data
	for (int i = 0; i < daysOfWeek.size(); i++) {
		cout << daysOfWeek[i] << endl;
	}
}

void vectorNumbers() {
	vector<int> purpleNumbers = { 2, 7, 11, 15, 23 };
	//adds 2 numbers to the end
	purpleNumbers.push_back(25);
	purpleNumbers.push_back(32);
	//deletes the end
	purpleNumbers.pop_back();
	//iterates through the vector and prints out data
	for (int i = 0; i < purpleNumbers.size(); i++) {
		cout << purpleNumbers[i] << endl;
	}
}

void fruitList() {
	list<string> fruits = { "pear", "apple", "cucumber" };
	//adds things to the front and back of the list
	fruits.push_back("tomato");
	fruits.push_front("pumpkin");
	//iterates through list and prints out the data
	for (auto const& i : fruits) {
		cout << i << endl;
	}
}

void groceryStock() {
	map <string, int> stock = { make_pair("Chicken Broth", 3), make_pair("Green Onion", 27), make_pair("Potato", 8) };
	stock["Chicken Broth"] = 30;
	for (auto food = stock.begin(); food != stock.end(); ++food) {
		cout << food->first << ": " << food->second << endl;
	}
}

int main() {
	week();
	vectorNumbers();
	fruitList();
	groceryStock();
	

	

	



	return 0;
}