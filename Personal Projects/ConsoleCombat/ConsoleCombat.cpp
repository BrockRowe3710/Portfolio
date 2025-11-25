#include "Character.h"
#include "EnemyCharacter.h"

#include <algorithm>
#include <iostream>

using namespace std;

bool ChooseCharacter(Character& playerChar, Weapon& playerWeapon, string playerName);

bool ContinueGame();

void PlayerHitEnemy(Character& playerCharacter, EnemyCharacter& currEnemy);

void EnemyHitPlayer(EnemyCharacter& currEnemy, Character& playerCharacter);

int main() {
    string playerChoice;
    Weapon playerWeapon;
    Character playerCharacter;
    EnemyCharacter currEnemy;
    int level = 0;
    int totalLoot = 0;

    srand(time(0));

    cout << "Choose your Character (enter their name):\n" <<
        "Gideon (60 health, 8 damage)\n" <<
        "Nissa (55 health, 9 damage)\n" <<
        "Jace (50 health, 10 damage)\n" <<
        "Liliana (45 health, 11 damage)\n" <<
        "Chandra (40 health, 12 damage)\n"
        << "\n";

    while (true) {
        cin >> playerChoice;
        cout << "\n";
        transform(playerChoice.begin(), playerChoice.end(), playerChoice.begin(), ::tolower);

        if (ChooseCharacter(playerCharacter, playerWeapon, playerChoice)) {
            break;
        }

        cout << "Please enter a valid character: ";
    }

    while (ContinueGame()) {
        ++level;

        currEnemy.CreateEnemy(level);

        currEnemy.PrintEnemy();

        while (playerCharacter.GetHealth() > 0 && currEnemy.GetHealth() > 0) {
            PlayerHitEnemy(playerCharacter, currEnemy);

            if (currEnemy.GetHealth() <= 0) {
                totalLoot += currEnemy.GetLoot();
                cout << "You Won! Total Loot: " << totalLoot << " gold\n\n";
                break;
            }

            EnemyHitPlayer(currEnemy, playerCharacter);

            if (playerCharacter.GetHealth() <= 0) {
                cout << "You Died! Final Loot: " << totalLoot << " gold\n\n";
                return 0;
            }
        }
    }
    cout << "You ran away! Final Loot: " << totalLoot << " gold\n\n";
    return 0;
}

bool ChooseCharacter(Character& playerCharacter, Weapon& playerWeapon, string playerName) {
    if (playerName == "gideon") {
        playerWeapon.SetWeapon("The Sural", 8);
        playerCharacter.SetCharacter("Gideon", 60, playerWeapon);
    }
    else if (playerName == "nissa") {
        playerWeapon.SetWeapon("Bitterthorn", 9);
        playerCharacter.SetCharacter("Nissa", 55, playerWeapon);
    }
    else if (playerName == "jace") {
        playerWeapon.SetWeapon("Mental Magic", 10);
        playerCharacter.SetCharacter("Jace", 50, playerWeapon);
    }
    else if (playerName == "liliana") {
        playerWeapon.SetWeapon("The Chain Veil", 11);
        playerCharacter.SetCharacter("Liliana", 45, playerWeapon);
    }
    else if (playerName == "chandra") {
        playerWeapon.SetWeapon("Pyromancy", 12);
        playerCharacter.SetCharacter("Chandra", 40, playerWeapon);
    }
    else { return false; }

    return true;
}

bool ContinueGame() {
    string userInput;

    while (true) {
        cout << "Continue onward? (y/n) ";
        cin >> userInput;
        cout << "\n";

        if (userInput == "Y" || userInput == "y") {
            return true;
        }
        else if (userInput == "N" || userInput == "n") {
            return false;
        }
    }
}

void PlayerHitEnemy(Character& playerCharacter, EnemyCharacter& currEnemy) {
    cout << playerCharacter.GetName() << " hit " << currEnemy.GetName()
        << " for " << playerCharacter.GetWeapon().GetDamage() << " damage! \n";

    currEnemy.SetHealth(currEnemy.GetHealth() - playerCharacter.GetWeapon().GetDamage());

    cout << currEnemy.GetName() << " is now at " << currEnemy.GetHealth()
        << " health.\n\n";
}

void EnemyHitPlayer(EnemyCharacter& currEnemy, Character& playerCharacter) {
    cout << currEnemy.GetName() << " hit " << playerCharacter.GetName()
        << " for " << currEnemy.GetWeapon().GetDamage() << " damage! \n";

    playerCharacter.SetHealth(playerCharacter.GetHealth() - currEnemy.GetWeapon().GetDamage());

    cout << playerCharacter.GetName() << " is now at " << playerCharacter.GetHealth()
        << " health.\n\n";
}