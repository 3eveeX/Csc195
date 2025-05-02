#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

class Scoreboard {
public:

	Scoreboard();

	template<typename T1/*, typename T2*/ >
	void streamOut(std::ostream& ostream, const T1& name/*, T2& score*/) {
		ostream << name << /*": " << score <<*/ std::endl;

	}

	void draw();
	void update();
	void erase();
	
	
private:
	std::vector<int> scores;
	std::string scoreString;
};
