#include <iostream>
#include "Student.h"
#include "Teacher.h"
#include <vector>
#include "School.h"

using namespace std;

int main() {
	School school;
	bool quit = false;
	while (!quit) {
	 //display menu
		cout << "1) Add Human\n";
		cout << "2) Display all Humans\n";
		cout << "3) Display Human of type\n";
		cout << "4) Quit\n";

		unsigned short selection;
		cin >> selection;

		switch (selection)
		{
		case 1:
			cout << "1) Student\n";
			cout << "2) Teacher\n";
			unsigned short type;
			cin >> type;

			school.Add(static_cast<Human::Type>(type - 1));
			break;
		case 2:
			school.DisplayAll();
			break;
		case 3:
			break;
		case 4:
			quit = true;
			break;
		default:
			break;
		}

	}


}

