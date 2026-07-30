#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#define Max_PLAYERS 3 
#define Max_Monsters 1

struct Player {
	string Name;
	string Role;
	int health;
	int maxHealth;
	int damage;
};

struct Monster {
	string Name;
	int health;
	int damage;
};

void Info();
void printInfo(Player* players, int count);
void printMonsterInfo(Monster monsters[], int count);

int main() {
	Player players[Max_PLAYERS];
	int playerCount = 0;
	int choice;

	Monster monsters[Max_Monsters];
	int monsterCount = 0;

	players[0] = { "Mega Knight Main", "Knight", 600, 1700, 583 };
	players[1] = { "Dark Zenith", "Dark Wizard", 800, 1750, 950 };
	players[2] = { "Guider of Sun", "Healer", 1690, 1700, 10 };
	playerCount = 3;

	monsters[0] = { "Ahuizotl", 49000, 1000 };
	monsterCount = 1;

	do {
		Info();
		cout << "\n" << "Whose Info Would You Like to See? ";
		cin >> choice;

		if (choice == 1) {
			printInfo(players, playerCount);
		}
		else if (choice == 2) {
			printMonsterInfo(monsters, monsterCount);
		}
		else if (choice == 3) {
			cout << "--> Returning <--\n" << endl;
		}
		else {
			cout << "--> Quit <--\n" << endl;
		}
	} while (choice != 3);

	return 0;
}

void Info() {
	cout << "\n" << "---MENU---" << "\n";
	cout << "1. Player Info ";
	cout << "\n2. Opponents Info ";
	cout << "\n3. Resume Game\n";
}

void printInfo(Player* players, int count) {
	for (int i = 0; i < count; i++) {
		Player& currentPlayer = players[i];
		cout << "\n" << "Player: " << currentPlayer.Name
			<< "\n" << "Role: " << currentPlayer.Role 
			<< "\n" << "Max Health: " << currentPlayer.maxHealth 
			<< "\n" << "Current Health: " << currentPlayer.health 
			<< "\n" << "Damage Done: " << currentPlayer.damage << "\n";

		if (currentPlayer.health < 700) {
			cout << "WARNING!! IN NEED OF AID!\n";
		}
		else {
			cout << "HEALTH STATUS: Healthy\n";
		}
	}
}
 
void printMonsterInfo(Monster monsters[], int count) {
	for (int i = 0; i < count; i++) {
		cout << "\n" << "Monster: " << monsters[i].Name << "\nCurrent Health: " << monsters[i].health << "\nDamage Taken: " << monsters[i].damage << "\n";
	}
}