#include "School.h"

School::~School()
{
	for (Human* human : m_humans) {
		delete human;
	}
	m_humans.clear();
}

void School::Add(Human::Type type)
{
	Human* human = nullptr;
	switch (type)
	{
	case Human::Type::STUDENT:
		human = new Student;
		break;
	case Human::Type::TEACHER:
		human = new Teacher;
		break;
	default:
		break;
	}
	human->Read();
	m_humans.push_back(human);
}

void School::DisplayAll()
{
	for (Human* human : m_humans) {
		human->Write();
	}
}

void School::DisplayByType(Human::Type type)
{
}

void School::DisplayByName(std::string name)
{
}
