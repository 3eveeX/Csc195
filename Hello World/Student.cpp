#include <iostream>
#include "../OOP/Student.h"

using namespace std;

void Student::Read()
{
	Human::Read();
	cout << "GPA: " << endl;
	cin >> _gpa;
}

void Student::Write() {
	Human::Write();
	cout << "GPA: " << _gpa << endl;

}