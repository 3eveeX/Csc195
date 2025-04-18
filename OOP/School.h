#pragma once
#include "Human.h"
#include <vector>

class School {
public:
	~School();

	void Add(Human::Type type);

	void DisplayAll();

	void DisplayByType(Human::Type type);
	void DisplayByName(std::string name);




private:
	std::vector<Human*> m_humans;

};
