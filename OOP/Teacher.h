#pragma once
#include "Human.h"

using classroom_t = unsigned short;

class Teacher : public Human {
public:
	Teacher(){
		std::cout << "---TEACHER---" << std::endl;
	}
	Teacher(std::string name, age_t age, std::string className, classroom_t classroom) :
		Human{ name, age },
		m_className{className},
		_classroom{classroom}

	{
	 //
	}

	void setClassName(std::string className) {
		m_className = className;
	}

	std::string getClassName() {
		return m_className;
	}

	void setClassroom(classroom_t classroom) {
		if (classroom >= 300 && classroom <= 400) return;

		_classroom = classroom;
	}
	Type getType() override { return Type::TEACHER; }
	void Read() override;
	void Write() override;
private:
	std::string m_className;
	classroom_t _classroom;
};

