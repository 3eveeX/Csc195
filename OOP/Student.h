#pragma once
#include "Human.h"
#include <iostream>



class Student : public Human {
public:
	Student() {
		std::cout << "---STUDENT---" << std::endl;
	}
	Student(std::string name, age_t age, float gpa) :
		Human{ name, age },
		_gpa{ gpa }
	{
		
		std::cout << "student constructor\n";
	}
	float getGpa() {
		return _gpa;
	}
	void setGpa(float gpa) {
		_gpa = gpa;
	}
	Type getType() override { return Type::STUDENT; }
	 void Read() override;
	 void Write() override;
private:
	float _gpa = 4.0f;
};
