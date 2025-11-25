#pragma once

#include <cmath>
#include <cstring>
#include <iostream>
#include "Weapon.h"
#include "Character.h"

using namespace std;

class EnemyCharacter : public Character {
public:
	void SetLoot(int level);
	void CreateEnemy(int level);

	int GetLoot() const;
	void PrintEnemy() const;
private:
	int loot = 0;
};