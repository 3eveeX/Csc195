#include "Teacher.h"

using namespace std;

void Teacher::Read()
{
	Human::Read();
	cout << "Class Name: ";
	cin >> m_className;
	cout << "Classroom: ";
	cin >> _classroom;
}

void Teacher::Write()
{
	Human::Write();
	cout << "Class Name: " << m_className << endl << "Classroom: " << _classroom << endl;
}
