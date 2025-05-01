#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

class Scoreboard {
public:

	Scoreboard();

	template<typename T>
	void streamOut(std::ostream& ostream, const T& value) {
		ostream << value << std::endl;

	}

	void draw();
	void update();

	
	
private:
	std::vector<int> scores;
	std::string scoreString;
};
