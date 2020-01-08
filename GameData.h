#pragma once

#include <string>
#include <iostream>
using namespace std;



class GameData
{
public:

	static int health;
	static int maxhealth;
	static int armor;
	static int damage;
	static int xp;
	static std::string _inventory[];
	static int RatHealth;
	static int DaggerDamage;
	static int RatDamage;
	static std::string _Coconutinventory;
	static int souphealth;
	static std::string _CrateInventory[3];
	static bool safelock;
	static int perception;
	static int check;
	static int i;
	static std::string _mainstreetinventory;
	static std::string input;
	static int TrollHealth;
};







class FightDamage {
public:
	void SetYourDamage(int Damage);
	void SetEHealth(int Health);
	void SetEDamage(int Damage);
	void SetEnemyArmor(int Armor);
	//void DoDamage();
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




class Descript
{
public:
	Descript() {}

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



private:
	//Description
	string _RoomName;
	string _RoomDescript;



	//Exits
	string _NorthExits;
	string _EastExits;
	string _SouthExits;
	string _WestExits;
};
// Description
inline void Descript::SetRoomName(string room) {
	_RoomName = room;
}
inline void Descript::SetRoomDescript(string room) {
	_RoomDescript = room;
}
inline void Descript::PrintRoomDescript() {
	std::cout << "\n" << _RoomName << endl << _RoomDescript << endl;
}
inline void PrintRoomDescript(Descript aroom) {
	aroom.PrintRoomDescript();
}


//Exits
inline void Descript::SetNorthExits(string exit) {
	_NorthExits = exit;
}
inline void Descript::SetEastExits(string exit) {
	_EastExits = exit;
}
inline void Descript::SetSouthExits(string exit) {
	_SouthExits = exit;
}
inline void Descript::SetWestExits(string exit) {
	_WestExits = exit;
}
inline void Descript::PrintExits() {
	if (_NorthExits != "") {
		std::cout << "north is: " << _NorthExits;
	}if (_EastExits != "") {
		std::cout << ", east is: " << _EastExits;
	}if (_SouthExits != "") {
		std::cout << ", south is: " << _SouthExits;
	}if (_WestExits != "") {
		std::cout << ", west is: " << _WestExits << endl;
	}
}
inline void PrintExits(Descript anExit) {
	anExit.PrintExits();
}


