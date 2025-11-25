#include "EnemyCharacter.h"
#include <cmath>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void EnemyCharacter::SetLoot(int level) {
	this->loot = level;
}

int EnemyCharacter::GetLoot() const {
	return loot;
}

void EnemyCharacter::CreateEnemy(int level) {
    int enemyTypeRand = rand() % 5;
    string enemyName;
    int enemyHealth = level * 5;
    int enemyDamage = level * 2;
    Weapon enemyWeapon;
    int enemyLoot = level;

    switch (enemyTypeRand) {
    case 0:
        enemyName = "Angel";
        enemyWeapon.SetWeapon("Holy Light", enemyDamage);
        break;
    case 1:
        enemyName = "Merfolk";
        enemyWeapon.SetWeapon("Aqua Spear", enemyDamage);
        break;
    case 2:
        enemyName = "Zombie";
        enemyWeapon.SetWeapon("Death Bite", enemyDamage);
        break;
    case 3:
        enemyName = "Goblin";
        enemyWeapon.SetWeapon("Quick Fire", enemyDamage);
        break;
    case 4:
        enemyName = "Elf";
        enemyWeapon.SetWeapon("Sap Dagger", enemyDamage);
        break;
    }

    this->name = enemyName;
    this->health = enemyHealth;
    this->weapon = enemyWeapon;
    this->loot = enemyLoot;
}

void EnemyCharacter::PrintEnemy() const {
    cout << left;
    cout << "+" << setfill('-') << setw(18) << "" << "+\n";
    cout << "|" << setfill(' ') << setw(18) << "" << "|\n";
    cout << "| " << setw(16) << this->name << " |\n";
    cout << "| Health: " << setw(8) << this->health << " |\n";
    cout << "| Damage: " << setw(8) << this->weapon.GetDamage() << " |\n";
    cout << "|" << setfill(' ') << setw(18) << "" << "|\n";
    cout << "+" << setfill('-') << setw(18) << "" << "+\n\n";
}