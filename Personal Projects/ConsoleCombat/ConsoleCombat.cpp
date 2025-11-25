#include "Character.h"
#include "EnemyCharacter.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <thread>

using namespace std;

bool ChooseCharacter(Character& playerChar, Weapon& playerWeapon, string playerName);

bool ContinueGame();

void PlayerHitEnemy(Character& playerCharacter, EnemyCharacter& currEnemy);

void EnemyHitPlayer(EnemyCharacter& currEnemy, Character& playerCharacter);

void PlayerUpgrade(Character& playerCharacter);

void UpdateGold(int totalLoot);

int main() {
    string playerChoice;
    Weapon playerWeapon;
    Character playerCharacter;
    EnemyCharacter currEnemy;
    int level = 0;
    int totalLoot = 0;

    srand(time(0));

    ifstream inputFile;
    inputFile.open("Gold.txt");
    if (!inputFile.is_open()) {
        cout << "File not found\n";
        return 1;
    }

    inputFile >> totalLoot;

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

        this_thread::sleep_for(chrono::seconds(1));

        while (playerCharacter.GetHealth() > 0 && currEnemy.GetHealth() > 0) {
            PlayerHitEnemy(playerCharacter, currEnemy);

            if (currEnemy.GetHealth() <= 0) {
                totalLoot += currEnemy.GetLoot();
                cout << "You Won! Total Loot: " << totalLoot << " gold\n\n";
                break;
            }

            EnemyHitPlayer(currEnemy, playerCharacter);

            if (playerCharacter.GetHealth() <= 0) {
                totalLoot = 0;
                cout << "You Died! Total Loot: " << totalLoot << " gold\n";
                UpdateGold(totalLoot);
                inputFile.close();
                return 0;
            }
        }

        PlayerUpgrade(playerCharacter);
    }
    cout << "You ran away! Total Loot: " << totalLoot << " gold\n";

    UpdateGold(totalLoot);
    inputFile.close();

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
        << " with " << playerCharacter.GetWeapon().GetName() << " for "
        << playerCharacter.GetWeapon().GetDamage() << " damage! \n";

    this_thread::sleep_for(chrono::seconds(1));

    currEnemy.SetHealth(currEnemy.GetHealth() - playerCharacter.GetWeapon().GetDamage());

    cout << currEnemy.GetName() << " is now at " << currEnemy.GetHealth()
        << " health.\n\n";

    this_thread::sleep_for(chrono::seconds(1));
}

void EnemyHitPlayer(EnemyCharacter& currEnemy, Character& playerCharacter) {
    cout << currEnemy.GetName() << " hit " << playerCharacter.GetName()
        << " with " << currEnemy.GetWeapon().GetName() << " for "
        << currEnemy.GetWeapon().GetDamage() << " damage! \n";

    this_thread::sleep_for(chrono::seconds(1));

    playerCharacter.SetHealth(playerCharacter.GetHealth() - currEnemy.GetWeapon().GetDamage());

    cout << playerCharacter.GetName() << " is now at " << playerCharacter.GetHealth()
        << " health.\n\n";

    this_thread::sleep_for(chrono::seconds(1));
}

void PlayerUpgrade(Character& playerCharacter) {
    string upgradeChoice;
    bool retry = true;

    cout << "Choose an Upgrade to get!\n"
        << "(1) +20% Damage to " << playerCharacter.GetWeapon().GetName() << " (+"
        << playerCharacter.GetWeapon().GetDamage() / 5 << ")\n"
        << "(2) Restore 20% of your max health (" << playerCharacter.GetHealth()
        << "/" << playerCharacter.GetMaxHealth() << ")\n"
        << "(3) Increase your max health by 20% (+" << playerCharacter.GetMaxHealth() / 10
        << ")\n" << "What do you choose? ";
    
    while (retry) {
        retry = false;
        cin >> upgradeChoice;
        cout << "\n";

        if (upgradeChoice == "1") {
            Weapon tempWeapon;
            int tempDamage = playerCharacter.GetWeapon().GetDamage() * 6 / 5;
            tempWeapon.SetWeapon(playerCharacter.GetWeapon().GetName(), tempDamage);
            playerCharacter.SetWeapon(tempWeapon);
            cout << "Damage increased to " << playerCharacter.GetWeapon().GetDamage() << "!\n\n";
        }
        else if (upgradeChoice == "2") {
            playerCharacter.SetHealth(playerCharacter.GetHealth() + playerCharacter.GetMaxHealth() / 5);
            if (playerCharacter.GetHealth() > playerCharacter.GetMaxHealth()) {
                playerCharacter.SetHealth(playerCharacter.GetMaxHealth());
            }
            cout << "Healed up to " << playerCharacter.GetHealth() << "!\n\n";
        }
        else if (upgradeChoice == "3") {
            playerCharacter.SetMaxHealth(playerCharacter.GetMaxHealth() * 6 / 5);
            cout << "Max health set to " << playerCharacter.GetMaxHealth() << "!\n\n";
        }
        else {
            cout << "Please input an upgrade: ";
            retry = true;
        }
    }
}

void UpdateGold(int totalLoot) {
    ofstream outputFile;
    outputFile.open("Gold.txt");
    if (!outputFile.is_open()) {
        cout << "File not found\n";
        exit(1);
    }

    outputFile << totalLoot;

    outputFile.close();
}