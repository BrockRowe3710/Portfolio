#pragma once

#include <string>

using namespace std;

class wall {
public:
	wall(string playerName); // Constructor, sets position = 0 and name
	int getposition() const; // Get climber's position
	string getname() const; // Get climber's name
	void climb(); // Increase climber's position by 1-3
	void drop(); // Decrease position by 1-3, not less than 0
private:
	int position;
	string name;
};