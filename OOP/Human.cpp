#include "Human.h"

using namespace std;

int Human::_count = 0;
const float Human::m_tax = 0.0835f;
void func() {
	cout << "funcy\n";	
}
void Human::setAge(age_t age) {
	_age = age;
}

void Human::Read()
{
	cout << "Name: ";
	cin >> m_name;
	cout << "Age: ";
	cin >> _age;

}

void Human::Write()
{
	cout << "Name: " << m_name << endl << "Age: " << _age << endl;
}
