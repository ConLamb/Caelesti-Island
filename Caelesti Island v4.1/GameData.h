
#pragma once

#include <string>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <thread>
#include <chrono>
#include <ctime>
#include <map>
#include <vector>
#include <ctime>
#include <omp.h>
#include "FunctionList.h"
#include "GameData.h"
typedef void (*func)();
//typedef Room (*Qroom)();
using namespace std;

extern string input;
extern int __input;
//extern map<string, string> north{ "north", "n" };





extern enum Einventory {
	eCompass,
	eDagger,
	eSoup,
	eGoggles,
	eEarmuffs,
	eHauberk,
	ekeys,
	eHelmet,
};
enum EcrateInventory {
	e_Soup,
	e_Goggles,
};
enum Egoblin {
	eTall,
	eSmall,
	eBroad,
	eSkinney,
};





class GameData
{
public:
	static int health;
	static int maxhealth;
	static int armor;
	static int damage;
	static int xp;
	static int DaggerDamage;
	static int souphealth;
	static bool safelock;
	static int perception;
	static int check;
	static bool coconut;
	static bool time;
	static int DamMod;
	static int level;
	static bool peace;
	static int dumb;
	static bool message;
};

class Inventory {
public:
	static string _mainstreetinventory;
	static string _inventory[50];
	static string _CrateInventory[3];
	static string _Coconutinventory;
	static string _NorthBechInventory;
	static string _GnollRoomInventory[2];
};

class NPC {
public:
	class Gnoll {
	public:
		static int GnollHealth;
		static int GnollDamage;
	};
	class Rat {
	public:
		static int RatDamage;
		static int RatHealth;
	};
	class Goblin {
	public:
		static int GoblinHealth[4];
	};
};





/*
class FightDamage {
public:
	void SetYourDamage(int Damage);
	void SetEHealth(int Health);
	void SetEDamage(int Damage);
	void SetEnemyArmor(int Armor);
	void DoDamage();
private:
	int _damage;
	int _EnemyHealth;
	int _EnemyDamage;
	int _EnemyArmor;
};
inline void FightDamage::SetYourDamage(int Damage) {
	_damage = Damage;
}
inline void FightDamage::SetEHealth(int Health) {
	_EnemyHealth = Health;
}
inline void FightDamage::SetEDamage(int Damage) {
	_EnemyDamage = Damage;
}
inline void FightDamage::SetEnemyArmor(int Armor) {
	_EnemyArmor = Armor;
}
*/



class Room
{
public:
	Room() {}

	//Description
	void SetRoomName(string room);
	void SetRoomDescript(string room);
	void PrintRoomDescript();



	//Exits
	void SetNorthExits(string exit);
	void SetEastExits(string exit);
	void SetSouthExits(string exit);
	void SetWestExits(string exit);
	void PrintExits();

	//Actions
	void UseActions();
	void SetNorthRoom(func north);
	void SetEastRoom(func east);
	void SetSouthRoom(func south);
	void SetWestRoom(func west);
	void SetUpRoom(func up);
	void SetDownRoom(func down);
	void SetUpWord(string up[3]);
	void SetDownWord(string down[3]);
	void SetOtherFunc(func other);
	void SetOtherWord(string other[3]);
	void SetOtherWord2(string other[3]);
	void SetOtherFunc2(func other);
	//void Actions();



private:
	//Description
	string _RoomName;
	string _RoomDescript;



	//Exits
	string _NorthExits;
	string _EastExits;
	string _SouthExits;
	string _WestExits;


	//Actions
	func NorthRoom;
	func EastRoom;
	func SouthRoom;
	func WestRoom;
	func UpRoom;
	func DownRoom;
	string UpWord[3];
	string DownWord[3];
	func OtherRoom;
	string OtherWord[3];
	func OtherRoom2;
	string OtherWord2[3];
};
// Description
inline void Room::SetRoomName(string room) {
	_RoomName = room;
}
inline void Room::SetRoomDescript(string room) {
	_RoomDescript = room;
}
inline void Room::PrintRoomDescript() {
	std::cout << "\n" << _RoomName << endl << _RoomDescript << endl;
}
inline void PrintRoomDescript(Room aroom) {
	aroom.PrintRoomDescript();
}


//Exits
inline void Room::SetNorthExits(string exit) {
	_NorthExits = exit;
}
inline void Room::SetEastExits(string exit) {
	_EastExits = exit;
}
inline void Room::SetSouthExits(string exit) {
	_SouthExits = exit;
}
inline void Room::SetWestExits(string exit) {
	_WestExits = exit;
}
inline void Room::PrintExits() {
	if (_NorthExits != "") {
		std::cout << "north is " << _NorthExits;
	}if (_EastExits != "") {
		std::cout << ", east is " << _EastExits;
	}if (_SouthExits != "") {
		std::cout << ", south is " << _SouthExits;
	}if (_WestExits != "") {
		std::cout << ", west is " << _WestExits << endl;
	}
	GameData::xp++;

	NorthRoom = NoGo; EastRoom = NoGo; SouthRoom = NoGo; WestRoom = NoGo;
}
inline void PrintExits(Room anExit) {
	anExit.PrintExits();
}


//Actions
inline void Room::UseActions() {
	do {
		getline(cin, input);
		if (input == "north" || input == "n") {
			NorthRoom();
		}
		if (input == "west" || input == "w") {
			WestRoom();
		}
		if (input == "east" || input == "e") {
			EastRoom();
		}
		if (input == "south" || input == "s") {
			SouthRoom();
		}
		if (input == UpWord[0] || input == UpWord[1] || input == UpWord[2] || input == UpWord[3]) {
			UpRoom();
		}
		if (input == DownWord[0] || input == DownWord[1] || input == DownWord[2] || input == DownWord[3]) {
			DownRoom();
		}
		if (input == OtherWord[0] || input == OtherWord[1] || input == OtherWord[2] || input == OtherWord[3]) {
			OtherRoom();
		}
		if (input == OtherWord2[0] || input == OtherWord2[1] || input == OtherWord2[2] || input == OtherWord2[3]) {
			OtherRoom2();
		}
		srand(time(NULL));

		if (input == "inventory" || input == "i") {
			Inventory();
		}
		if ((input == "use soup" || input == "drink soup" || input == "eat soup") && Inventory::_inventory[eSoup] == "soup") {
			GameData::souphealth = (GameData::souphealth + (rand() % 5));
			GameData::health = GameData::souphealth + GameData::health;
			GameData::xp = GameData::xp + 5;
			if (GameData::health > GameData::maxhealth) {
				GameData::health = GameData::maxhealth;
			}
			cout << "you now have " << GameData::health << " health\n";
			Inventory::_inventory[eSoup] = "";
		}
		if (input == "look") {
			cout << _RoomName << endl;
			cout << _RoomDescript << endl;
			cout << "north is " << _NorthExits;
			cout << ", east is " << _EastExits;
			cout << ", south is " << _SouthExits;
			cout << ", west is " << _WestExits << endl;
		}
		
	} while (input != "north" && input != "n" && input != "east" && input != "e" && input != "south" && input != "s" && input != "west" && input != "w");
}

inline void Room::SetNorthRoom(func north) {
	NorthRoom = north;
}
inline void Room::SetEastRoom(func east) {
	EastRoom = east;
}
inline void Room::SetSouthRoom(func south) {
	SouthRoom = south;
}
inline void Room::SetWestRoom(func west) {
	WestRoom = west;
}
inline void Room::SetUpRoom(func up) {
	UpRoom = up;
}
inline void Room::SetUpWord(string up[3]) {
	for (int q = 4; q > 0; q--) {
		UpWord[q] = up[q];
	}
}
inline void Room::SetDownRoom(func down) {
	DownRoom = down;
}
inline void Room::SetDownWord(string down[3]) {
	for (int q = 4; q > 0; q--) {
		DownWord[q] = down[q];
	}
}
inline void Room::SetOtherFunc(func other) {
	OtherRoom = other;
}
inline void Room::SetOtherWord(string other[3]) {
	for (int q = 4; q > 0; q--) {
		OtherWord[q] = other[q];
	}
}
inline void Room::SetOtherFunc2(func other) {
	OtherRoom2 = other;
}
inline void Room::SetOtherWord2(string other[3]) {
	for (int q = 4; q > 0; q--) {
		OtherWord2[q] = other[q];
	}
}
inline void UseActions(Room aRoom) {
	aRoom.UseActions();
}
inline void Actions(Room anRoom) {
	srand(time(NULL));

	if (input == "inventory" || input == "i") {
		Inventory();
	}
	if ((input == "use soup" || input == "drink soup" || input == "eat soup") && Inventory::_inventory[eSoup] == "soup") {
		GameData::souphealth = (GameData::souphealth + (rand() % 5));
		GameData::health = GameData::souphealth + GameData::health;
		GameData::xp = GameData::xp + 5;
		if (GameData::health > GameData::maxhealth) {
			GameData::health = GameData::maxhealth;
		}
		cout << "you now have " << GameData::health << " health\n";
		Inventory::_inventory[eSoup] = "";
	}
	if (input == "look") {
		PrintRoomDescript(anRoom);
		PrintExits(anRoom);
	}
}





//Enemy Health
class EnemyHealth {
public:
	void SetHealth(int health);
	void SetEnemyName(string name);
	void SetMaxHealth(int health);
	void PrintCondision();
private:
	int _health;
	int _maxhealth;
	string _name;
};

inline void EnemyHealth::SetHealth(int health) {
	_health = health;
}
inline void EnemyHealth::SetMaxHealth(int health) {
	_maxhealth = health;
}
inline void EnemyHealth::SetEnemyName(string name) {
	_name = name;
}
inline void EnemyHealth::PrintCondision() {
	if (_health > ((2.0 / 3.0) * _maxhealth)) {
		cout << "the " << _name << " is doing well\n";
	}
	if (_health > ((1.0 / 3.0) * _maxhealth) && _health < ((2.0 / 3.0) * _maxhealth)) {
		cout << "the " << _name << " is doing well\n";
	}
	if (_health > 0.0 && _health < ((1.0 / 3.0) * _maxhealth)) {
		cout << "the " << _name << " is bloodied\n";
	}
}
inline void PrintCondision(EnemyHealth anEnemy) {
	anEnemy.PrintCondision();
}






