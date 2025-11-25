#include "Weapon.h"
#include <cmath>
#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;

void Weapon::SetDamage(int damage) {
	this->damage = damage;
}

void Weapon::SetName(string name) {
	this->name = name;
}

void Weapon::SetWeapon(string name, int damage) {
	this->name = name;
	this->damage = damage;
}

int Weapon::GetDamage() const {
	return damage;
}

string Weapon::GetName() const {
	return name;
}

void Weapon::PrintWeapon() const {
	cout << name << " (" << damage << " dmg)";
}