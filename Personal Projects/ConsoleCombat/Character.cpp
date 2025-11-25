#include "Character.h"
#include <cmath>
#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;

void Character::SetHealth(int health) {
	this->health = health;
}

void Character::SetName(string name) {
	this->name = name;
}

void Character::SetWeapon(Weapon weapon) {
	this->weapon = weapon;
}

void Character::SetCharacter(string name, int health, Weapon weapon) {
	this->name = name;
	this->health = health;
	this->weapon = weapon;
}

int Character::GetHealth() const {
	return health;
}

string Character::GetName() const {
	return name;
}

Weapon Character::GetWeapon() const {
	return weapon;
}

void Character::PrintCharacter() const {
	cout << name << " (" << health << " health) is holding: ";
	weapon.PrintWeapon();
}