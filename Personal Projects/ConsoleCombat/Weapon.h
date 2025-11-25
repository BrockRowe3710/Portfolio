#pragma once

#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

class Weapon {
public:
	void SetDamage(int damage);
	void SetName(string name);
	void SetWeapon(string name, int damage);

	int GetDamage() const;
	string GetName() const;
	void PrintWeapon() const;
private:
	int damage = -1;
	string name = "NoName";
};