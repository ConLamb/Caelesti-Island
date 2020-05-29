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
using namespace Cave1;


void Cave1::CaveEntrance() {
	//Defs.
	srand(time(NULL));
	GameData::damage = ((rand() % 5) + GameData::DamMod);
	Room CaveEntrance;
	input = "";


	//Description
	CaveEntrance.SetRoomName("Cave Entrance");
	if (Inventory::_inventory[eEarmuffs] == "earmuffs") {
		CaveEntrance.SetRoomDescript("There is a small boulder with scratch that read \"here lies the heart of our land\"");
	}
	else {
		CaveEntrance.SetRoomDescript("There is a small boulder with scratch that form a language you do not understand");
	}
	PrintRoomDescript(CaveEntrance);

	//Exits
	CaveEntrance.SetNorthExits("a cave");
	CaveEntrance.SetEastExits("a passage leading into a room");
	CaveEntrance.SetSouthExits("jungle");
	CaveEntrance.SetWestExits("rock");
	PrintExits(CaveEntrance);


	while (input != "north" && input != "n" && input != "east" && input != "e" && input != "south" && input != "s") {
		getline(cin, input);
		if (input == "north" || input == "n") {
			WellRoom();
		}
		if (input == "east" || input == "e") {
			SupplyRoom();
		}
		if (input == "south" || input == "s") {
			Jungle::CaveClearing();
		}
		if (input == "west" || input == "w") {
			cout << "There is rock there" << endl;
		}
		Actions(CaveEntrance);
	}
}



void Cave1::SupplyRoom() {
	//Defs.
	srand(time(NULL));
	GameData::damage = ((rand() % 5) + GameData::DamMod);
	Room SupplyRoom;

	input = "";

	//Description
	SupplyRoom.SetRoomName("Supply Room");
	if (NPC::Rat::RatHealth > 0) {
		SupplyRoom.SetRoomDescript("There is a dead end. at the end lies an open crate and a very large rat stands between you and the crate spitting");
		SupplyRoom.SetNorthExits("a rat");
	}
	else {
		SupplyRoom.SetRoomDescript("There is a dead end. at the end lies an open crate");
		SupplyRoom.SetNorthExits("a crate");
	}
	PrintRoomDescript(SupplyRoom);

	//Exits
	SupplyRoom.SetEastExits("rock");
	SupplyRoom.SetSouthExits("rock");
	SupplyRoom.SetWestExits("the mouth of the cave");
	PrintExits(SupplyRoom);


	//Actions
	while (input != "north" && input != "n" && input != "west" && input != "w") {
		getline(cin, input);
		if (input == "north" || input == "n") {
			if (NPC::Rat::RatHealth <= 0) {
				CrateRoom();
			}
		}
		if (input == "east" || input == "e") {
			cout << "there is rock there\n";
		}
		if (input == "south" || input == "s") {
			cout << "there is rock there\n";
		}
		if (input == "west" || input == "w") {
			CaveEntrance();
		}
		if ((input == "fight" || "fight rat with dagger") && NPC::Rat::RatHealth > 0) {
			RatFight();
		}
		Actions(SupplyRoom);
	}
}
void Cave1::RatFight() {
	//Defs.
	srand(time(NULL));
	GameData::damage = ((rand() % 5) + GameData::DamMod);
	GameData::DaggerDamage = 15 + (rand() % 11);
	NPC::Rat::RatDamage = 2 + (rand() % 5);
	EnemyHealth Rat;
	Rat.SetEnemyName("Rat");
	Rat.SetMaxHealth(50);


	if (input == "fight rat" && NPC::Rat::RatHealth > 0) {
		cout << "you punch and kick the rat\n";
		NPC::Rat::RatHealth = NPC::Rat::RatHealth - GameData::damage;
	}
	if (input == "fight rat with dagger" && Inventory::_inventory[eDagger] == "dagger" && NPC::Rat::RatHealth > 0) {
		cout << "slash at the rat with your dagger\n";
		NPC::Rat::RatHealth = NPC::Rat::RatHealth - GameData::DaggerDamage;
	}
	PrintCondision(Rat);
	if (NPC::Rat::RatHealth <= 0) {
		cout << "the rat is dead\n";
		GameData::xp = GameData::xp + 25;
	}
	if (GameData::health <= 0) {
		cout << "Game: over\n";
		cout << "  _______\n";
		cout << " /        \\\n";
		cout << " | R.I.P. |\n";
		cout << " | Markeo |\n";
		cout << " |        |\n";
		cout << " |        |\n";
		cout << "^^^^^^^^^^^^^\n";
		exit;
	}

	if (NPC::Rat::RatHealth > 0 && GameData::health > 0) {
		cout << "the rat takes a bite at you" << endl;
		cout << "you take " << NPC::Rat::RatDamage << " damage\n";
		GameData::health = GameData::health - (NPC::Rat::RatDamage - GameData::armor);
	}
	cout << '\n';
}
void Cave1::CrateRoom() {
	//Defs.

	srand(time(NULL));
	GameData::damage = ((rand() % 5) + GameData::DamMod);
	Room CaveEntrance;
	input = "";

	cout << "Crate Room\n";
	cout << "you stand in front of the open crate. Inside are " << Inventory::_CrateInventory[e_Goggles] << " " << Inventory::_CrateInventory[e_Soup] << "\n";

	//Exits
	CaveEntrance.SetNorthExits("rock");
	CaveEntrance.SetEastExits("rock");
	CaveEntrance.SetSouthExits("tunnel");
	CaveEntrance.SetWestExits("rock");
	PrintExits(CaveEntrance);


	while (input != "south" && input != "s") {
		getline(cin, input);
		if (input == "north" || input == "n") {
			cout << "there is rock there\n";
		}
		if (input == "west" || input == "w") {
			cout << "there is rock there\n";
		}
		if (input == "east" || input == "e") {
			cout << "there is rock there\n";
		}
		if (input == "south" || input == "s") {
			SupplyRoom();
		}
		if (input == "take soup" && Inventory::_CrateInventory[e_Soup] == "soup") {
			cout << "taken\n";
			Inventory::_inventory[eSoup] = "soup";
			Inventory::_CrateInventory[e_Soup] = "";
		}
		if (input == "take goggles" && Inventory::_CrateInventory[e_Goggles] == "goggles") {
			cout << "taken" << endl;
			Inventory::_inventory[eGoggles] = "goggles";
			Inventory::_CrateInventory[e_Goggles] = "";
		}
		Actions(CaveEntrance);
	}
}



void Cave1::WellRoom() {
	//Defs.
	srand(time(NULL));
	GameData::damage = ((rand() % 5) + GameData::DamMod);
	Room WellRoom;
	input = "";

	//Description
	WellRoom.SetRoomName("Well Room");
	if (Inventory::_inventory[eGoggles] == "goggles") {
		WellRoom.SetRoomDescript("There is a well in the middle of the room that miners would use but it is very old, there is a ladder leading down");
	}
	else {
		WellRoom.SetRoomDescript("Very little light is leaching from behind you and you cant make out much");
	}
	PrintRoomDescript(WellRoom);

	//Exits
	if (Inventory::_inventory[eGoggles] == "goggles") {
		WellRoom.SetNorthExits("a passage");
		WellRoom.SetEastExits("low passage");
		WellRoom.SetSouthExits("dimmly lit passage");
		WellRoom.SetWestExits("rock");
	}
	PrintExits(WellRoom);

	while (input != "north" && input != "n" && input != "south" && input != "s") {
		getline(cin, input);
		if ((input == "north" || input == "n") && Inventory::_inventory[eGoggles] == "goggles") {
			Cave2::StorageRoom();
		}
		if (input == "west" || input == "w") {
			cout << "there is rock there\n";
		}
		if (input == "east" || input == "e") {
			cout << "there is rock there\n";
		}
		if (input == "south" || input == "s") {
			CaveEntrance();
		}
		if ((input == "go into well" || input == "down well") && Inventory::_inventory[eGoggles] == "goggles") {
			InsideWell();
		}
		Actions(WellRoom);
	}

}
void Cave1::InsideWell() {
	//Defs.
	srand(time(NULL));
	GameData::damage = ((rand() % 5) + GameData::DamMod);
	string _safeInventory = "hauberk";
	Room InsideWell;
	input = "";


	//Description
	InsideWell.SetRoomName("Inside well");
	InsideWell.SetRoomDescript("you stand at the bottom of a well that has gone dry. infront of you is an old safe reading \n    3   8_____9   3   ?_____6   0\n   /4\\   \\   /   /?\\   \\   /   / \\\n  /___\\   \\4/   /___\\   \\8/   /_10\\\n 2     1   ?   1     4   5   1     ?\n");
	PrintRoomDescript(InsideWell);

	//Exits
	InsideWell.SetNorthExits("rocks");
	InsideWell.SetEastExits("rocks");
	InsideWell.SetSouthExits("rocks");
	InsideWell.SetWestExits("rocks");
	PrintExits(InsideWell);

	while (input != "up" && input != "up well" && input != "climb up" && input != "climb up well") {
		input = "";
		getline(cin, input);
		if (input == "up" || input == "up well" || input == "climb up" || input == "climb up well") {
			WellRoom();
		}
		if ((input == "enter 7625" || input == "7625") && GameData::safelock == true) {
			GameData::safelock = false;
		}
		if (_safeInventory == "hauberk" && GameData::safelock == false) {
			cout << "there is a small hiss as the safe opens and out falls a hauberk\n";
			GameData::xp = GameData::xp + 20;
		}
		if (input == "take hauberk" && _safeInventory == "hauberk") {
			cout << "taken\n";
			_safeInventory = "";
			Inventory::_inventory[eHauberk] = "hauberk";
			GameData::armor = GameData::armor + 2;
			GameData::xp = GameData::xp + 5;
		}
		if (_safeInventory != "hauberk") {
			cout << "the safe is empty\n";
		}
		Actions(InsideWell);
	}
}