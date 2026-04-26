#include "wall.h"
#include <string>

using namespace std;

wall::wall(string playerName) { // sets position to 0 and climber's name
	name = playerName;
	position = 0;
}

int wall::getposition() const { // gets climber's height on the wall
	return position;
}

string wall::getname() const { // gets climber's name
	return name;
}

void wall::climb() { // increases climber's height on the wall
	int heightClimbed = (rand() % 3) + 1;
	position += heightClimbed;
}

void wall::drop() { // decreases climber's height on the wall
	int heightDropped = (rand() % 3) + 1;
	position -= heightDropped;
	if (this->getposition() < 0) {
		position = 0;
	}
}