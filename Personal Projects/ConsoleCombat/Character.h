#pragma once

#include <cmath>
#include <cstring>
#include <iostream>
#include "Weapon.h"

using namespace std;

class Character {
public:
	void SetHealth(int health);
	void SetName(string name);
	void SetWeapon(Weapon weapon);
	void SetCharacter(string name, int health, Weapon weapon);

	int GetHealth() const;
	string GetName() const;
	Weapon GetWeapon() const;
	void PrintCharacter() const;
protected:
	int health = -1;
	string name = "NoName";
	Weapon weapon;
};