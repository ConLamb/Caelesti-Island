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
using namespace Cave2;



void Cave2::StorageRoom() {
	srand(time(NULL));
	//Defs.
	input = "";
	GameData::damage = ((rand() % 5) + GameData::DamMod);
	Room StorageRoom;

	//Description
	StorageRoom.SetRoomName("Storage Room");
	StorageRoom.SetRoomDescript("there are large emty boxes in each corner");
	PrintRoomDescript(StorageRoom);

	//Exits
	StorageRoom.SetNorthExits("a door");
	StorageRoom.SetEastExits("a crate");
	StorageRoom.SetSouthExits("a passage");
	StorageRoom.SetWestExits("a dark door");
	PrintExits(StorageRoom);

	while (input != "north" && input != "n" && input != "east" && input != "e" && input != "south" && input != "s" && input != "west" && input != "w") {
		getline(cin, input);
		if (input == "north" || input == "n") {
			GnollRoom();
		}
		if (input == "west" || input == "w") {
			Civilization::MessageRoom();
		}
		if (input == "east" || input == "e") {
			cout << "there is a crate there\n";
		}
		if (input == "south" || input == "s") {
			Cave1::WellRoom();
		}
		if (input == "inspect crates") {
			cout << "they are empty\n";
		}
		Actions(StorageRoom);
	}
}










void Cave2::GnollRoom() {
	srand(time(NULL));
	//Defs.
	input = "";
	GameData::damage = ((rand() % 5) + GameData::DamMod);
	Room GnollRoom;
	//Description
	GnollRoom.SetRoomName("Gnoll Room");
	if (NPC::Gnoll::GnollHealth > 0) {
	GnollRoom.SetRoomDescript("There is a tall Gnoll in the middle of the room with a large battle axe baring your way.");
	}
	else {
		GnollRoom.SetRoomDescript("there is a room. there are a lot of bones on the floor");
	}
	PrintRoomDescript(GnollRoom);
	//Exits
	if (NPC::Gnoll::GnollHealth > 0) {
		GnollRoom.SetNorthExits("a gnoll");
		GnollRoom.SetEastExits("a wall");
		GnollRoom.SetSouthExits("a doorway");
		GnollRoom.SetWestExits("a wall");
	}
	else {
		GnollRoom.SetNorthExits("a wall with a helmet on it");
		GnollRoom.SetEastExits("a wall");
		GnollRoom.SetSouthExits("a door way");
		GnollRoom.SetWestExits("a wall");
	}

	PrintExits(GnollRoom);
	while (input != "north" && input != "n" && input != "east" && input != "e" && input != "south" && input != "s" && input != "west" && input != "w") {
		getline(cin, input);
		if (input == "north" || input == "n") {
			cout << "there is a wall there\n";
		}
		if (input == "west" || input == "w") {
			cout << "there is a wall there\n";
		}
		if (input == "east" || input == "e") {
			cout << "there is a wall there\n";
		}
		if (input == "south" || input == "s") {
			StorageRoom();
		}
		if (input == "fight troll" || "fight troll with dagger") {
			Cave2::GnollFight();
		}
		if (input == "take helmet") {
			
		}
		Actions(GnollRoom);
	}
}
void Cave2::GnollFight() {
	srand(time(NULL));
	GameData::damage = ((rand() % 5) + GameData::DamMod);
	GameData::DaggerDamage = 15 + (rand() % 11);
	NPC::Gnoll::GnollDamage = 3 + (rand() % 4);
	EnemyHealth Gnoll;
	Gnoll.SetEnemyName("gnoll");
	Gnoll.SetMaxHealth(50);
	if (input == "fight gnoll" && NPC::Gnoll::GnollHealth > 0) {
		cout << "you punch and kick the gnoll\n";
		NPC::Gnoll::GnollHealth = NPC::Gnoll::GnollHealth - GameData::damage;
		cout << NPC::Gnoll::GnollHealth << endl;
		Gnoll.SetHealth(NPC::Gnoll::GnollHealth);
		PrintCondision(Gnoll);
	}
	if (input == "fight gnoll with dagger" && Inventory::_inventory[eDagger] == "dagger" && NPC::Gnoll::GnollHealth > 0) {
		cout << "you stab and slash the Gnoll\n";
		NPC::Gnoll::GnollHealth = NPC::Gnoll::GnollHealth - GameData::DaggerDamage;
		cout << NPC::Gnoll::GnollHealth << endl;
		Gnoll.SetHealth(NPC::Gnoll::GnollHealth);
		PrintCondision(Gnoll);
	}
	if (NPC::Gnoll::GnollHealth > 0) {
		cout << "the gnoll hits you with the battle axe\n";
		GameData::health = GameData::health - (NPC::Gnoll::GnollDamage - GameData::armor);
		cout << "you take " << NPC::Gnoll::GnollDamage - GameData::armor << " damage\n";
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
	if (NPC::Gnoll::GnollHealth <= 0) {
		cout << "you beat the Gnoll\n";
		GameData::xp = GameData::xp + 100;
	}
}

