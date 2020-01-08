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



void CaveEntrance() {
	//Defs.
	srand(time(NULL));
	GameData::damage = ((rand() % 5) + 2);
	Descript CaveEntrance;
	GameData::input = "";

	//Description
	CaveEntrance.SetRoomName("Cave Entrance");
	if (GameData::_inventory[4] == "earmuffs") {
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


	while (GameData::input != "north" && GameData::input != "n" && GameData::input != "east" && GameData::input != "e" && GameData::input != "south" && GameData::input != "s") {
		getline(cin, GameData::input);
		if (GameData::input == "north" || GameData::input == "n") {
			WellRoom();
		}
		if (GameData::input == "east" || GameData::input == "e") {
			SupplyRoom();
		}
		if (GameData::input == "south" || GameData::input == "s") {
			CaveClearing();
		}
		if (GameData::input == "west" || GameData::input == "w") {
			cout << "There is rock there" << endl;
		}
		Actions();
	}
}



void SupplyRoom() {
	//Defs.
	srand(time(NULL));
	GameData::damage = ((rand() % 5) + 2);
	Descript SupplyRoom;

	GameData::input = "";

	//Description
	SupplyRoom.SetRoomName("Supply Room");
	if (GameData::RatHealth > 0) {
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
	while (GameData::input != "north" && GameData::input != "n" && GameData::input != "west" && GameData::input != "w") {
		getline(cin, GameData::input);
		if (GameData::input == "north" || GameData::input == "n") {
			if (GameData::RatHealth <= 0) {
				CrateRoom();
			}
		}
		if (GameData::input == "east" || GameData::input == "e") {
			cout << "there is rock there\n";
		}
		if (GameData::input == "south" || GameData::input == "s") {
			cout << "there is rock there\n";
		}
		if (GameData::input == "west" || GameData::input == "w") {
			CaveEntrance();
		}
		if ((GameData::input == "fight" || "fight rat with dagger") && GameData::RatHealth > 0) {
			RatFight();
		}
		Actions();
	}
}
void RatFight() {
	//Defs.
	srand(time(NULL));
	GameData::damage = ((rand() % 5) + GameData::damage);
	//DaggerDamage = 15 + (rand() % 11);
	GameData::DaggerDamage = 15 + (rand() % 11);
	GameData::RatDamage = 2 + (rand() % 5);



	if (GameData::GameData::input == "fight rat" && GameData::RatHealth > 0) {
		cout << "you punch and kick the rat\n";
		GameData::RatHealth = GameData::RatHealth - GameData::damage;
	}
	if (GameData::input == "fight rat with dagger" && GameData::_inventory[1] == "dagger" && GameData::RatHealth > 0) {
		cout << "slash at the rat with your dagger\n";
		GameData::RatHealth = GameData::RatHealth - GameData::DaggerDamage;
	}

	if (GameData::RatHealth >= 14) {
		cout << "the rat is doing well\n";
	}
	if (GameData::RatHealth < 14 && GameData::RatHealth >= 7) {
		cout << "the rat looks hurt\n";
	}
	if (GameData::RatHealth < 7 && GameData::RatHealth >= 1) {
		cout << "the rat is bloodied\n";
	}
	if (GameData::RatHealth <= 0) {
		cout << "the rat is dead\n";
		GameData::xp = GameData::xp + 20;
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

	if (GameData::RatHealth > 0 && GameData::health > 0) {
		cout << "the rat takes a bite at you" << endl;
		cout << "you take " << GameData::RatDamage << " damage\n";
		GameData::health = GameData::health - (GameData::RatDamage - GameData::armor);
	}
}
void CrateRoom() {
	//Defs.

	srand(time(NULL));
	GameData::damage = ((rand() % 5) + 2);
	Descript CaveEntrance;
	GameData::input = "";

	cout << "Crate Room\n";
	cout << "you stand in front of the open crate. Inside are " << GameData::_CrateInventory[0] << " " << GameData::_CrateInventory[1] << "\n";

	//Exits
	CaveEntrance.SetNorthExits("rock");
	CaveEntrance.SetEastExits("rock");
	CaveEntrance.SetSouthExits("tunnel");
	CaveEntrance.SetWestExits("rock");
	PrintExits(CaveEntrance);


	while (GameData::input != "south" && GameData::input != "s") {
		getline(cin, GameData::input);
		if (GameData::input == "north" || GameData::input == "n") {
			cout << "there is rock there\n";
		}
		if (GameData::input == "west" || GameData::input == "w") {
			cout << "there is rock there\n";
		}
		if (GameData::input == "east" || GameData::input == "e") {
			cout << "there is rock there\n";
		}
		if (GameData::input == "south" || GameData::input == "s") {
			SupplyRoom();
		}
		if (GameData::input == "take soup" && GameData::_CrateInventory[1] == "soup") {
			cout << "taken\n";
			GameData::_inventory[2] = "soup";
			GameData::_CrateInventory[1] = "";
		}
		if (GameData::input == "take goggles" && GameData::_CrateInventory[0] == "goggles") {
			cout << "taken" << endl;
			GameData::_inventory[GameData::i] = "goggles";
			GameData::_CrateInventory[0] = "";
			GameData::i++;
		}
		Actions();
	}
}



void WellRoom() {
	//Defs.
	srand(time(NULL));
	GameData::damage = ((rand() % 5) + 2);
	Descript WellRoom;
	GameData::input = "";

	//Description
	WellRoom.SetRoomName("Well Room");
	if (GameData::_inventory[3] == "goggles") {
		WellRoom.SetRoomDescript("There is a well in the middle of the room that miners would use but it is very old, there is a ladder leading down");
	}
	else {
		WellRoom.SetRoomDescript("Very little light is leaching from behind you and you cant make out much");
	}
	PrintRoomDescript(WellRoom);

	//Exits
	if (GameData::_inventory[3] == "goggles") {
		WellRoom.SetNorthExits("a passage");
		WellRoom.SetEastExits("low passage");
		WellRoom.SetSouthExits("dimmly lit passage");
		WellRoom.SetWestExits("rock");
	}
	PrintExits(WellRoom);

	while (GameData::input != "north" && GameData::input != "n" && GameData::input != "east" && GameData::input != "e" && GameData::input != "south" && GameData::input != "s" && GameData::input != "west" && GameData::input != "w") {
		getline(cin, GameData::input);
		if (GameData::input == "north" || GameData::input == "n") {
			StorageRoom();
		}
		if (GameData::input == "west" || GameData::input == "w") {

		}
		if (GameData::input == "east" || GameData::input == "e") {

		}
		if (GameData::input == "south" || GameData::input == "s") {

		}
		if ((GameData::input == "go into well" || GameData::input == "down well") && GameData::_inventory[3] == "goggles") {
			InsideWell();
		}
		Actions();
	}

}
void InsideWell() {
	//Defs.
	srand(time(NULL));
	GameData::damage = ((rand() % 5) + 2);
	string _safeInventory = "hauberk";
	Descript InsideWell;
	GameData::input = "";


	//Description
	InsideWell.SetRoomName("Inside well");
	InsideWell.SetRoomDescript("you stand at the bottom of a well that has gone dry. infront of you is an old safe reading \nLOSE the new code, turn OVER for new code\n");
	PrintRoomDescript(InsideWell);

	//Exits
	InsideWell.SetNorthExits("rocks");
	InsideWell.SetEastExits("rocks");
	InsideWell.SetSouthExits("rocks");
	InsideWell.SetWestExits("rocks");
	PrintExits(InsideWell);

	while (GameData::input != "up" && GameData::input != "up well" && GameData::input != "climb up" && GameData::input != "climb up well") {
		GameData::input = "";
		getline(cin, GameData::input);
		if (GameData::input == "up" || GameData::input == "up well" || GameData::input == "climb up" || GameData::input == "climb up well") {
			WellRoom();
		}
		if ((GameData::input == "enter 3507" || GameData::input == "3507") && GameData::safelock == true) {
			GameData::safelock = false;
			if (_safeInventory == "hauberk") {
				cout << "there is a small hiss as the safe opens and out falls a hauberk\n";
				if (GameData::input == "take hauberk" && _safeInventory == "hauberk") {
					cout << "taken\n";
					_safeInventory = "";
					GameData::_inventory[GameData::i] = "hauberk";
					GameData::armor = GameData::armor + 2;
					GameData::i++;
				}
			}
			if (_safeInventory != "hauberk") {
				cout << "the safe is empty\n";
			}
		}
	}
}