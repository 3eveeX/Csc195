#pragma once
#include <string>
void f();

class Student
{
public: 
	Student() {}
	Student(std::string name) {
		this->name = name;
	}
	void Write();
	std::string getName() { return name; }
	void setName(std::string name) { this->name = name; }
	std::string name;
};