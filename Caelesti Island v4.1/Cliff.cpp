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
using namespace Cliff;


void Cliff::Bluff() {
	srand(time(NULL));
	//Defs.
	input = "";
	GameData::damage = ((rand() % 5) + GameData::DamMod);
	Room Bluff;

	//Description
	Bluff.SetRoomName("Bluff");
	Bluff.SetRoomDescript("After climbing up the hill, you stand on top of the mountain. There are tipies going down what seems to be a main street");
	PrintRoomDescript(Bluff);

	//Exits
	Bluff.SetNorthExits("sloping hill that goes to a beach");
	Bluff.SetEastExits("sheer cliffs");
	Bluff.SetSouthExits("the main street");
	Bluff.SetWestExits("sheer cliffs");
	PrintExits(Bluff);

	while (input != "north" && input != "n" && input != "south" && input != "s") {
		getline(cin, input);
		if (input == "north" || input == "n") {
			Beach::NorthBeach();
		}
		if (input == "west" || input == "w") {
			cout << "there is a cliff there\n";
		}
		if (input == "east" || input == "e") {
			cout << "there is a cliff there\n";
		}
		if (input == "south" || input == "s") {
			MainStreet();
		}
		Actions(Bluff);
	}
}




void Cliff::MainStreet() {
	srand(time(NULL));
	//Defs.
	input = "";
	int keysdc = 7;
	GameData::check = ((rand() % 21 + 1) + GameData::perception);
	Room _MainStreet;
	auto keyvision = false;

	//Description
	if (GameData::check >= keysdc) {
		_MainStreet.SetRoomName("you are at the end of th village. You just catch a glimmer out of the corner of you eye and see a small set of keys near you");
		keyvision = true;
	}
	else {
		_MainStreet.SetRoomName("you are at the end of th village");
	}

	PrintRoomDescript(_MainStreet);

	//Exits
	_MainStreet.SetNorthExits("sheer cliffs");
	_MainStreet.SetEastExits("tipis");
	_MainStreet.SetSouthExits("the main street");
	_MainStreet.SetWestExits("tipis");
	PrintExits(_MainStreet);


	//Actions
	while (input != "north" && input != "n") {
		getline(cin, input);
		if (input == "north" || input == "n") {
			MainStreet();
		}
		if (input == "west" || input == "w") {
			cout << "there is a force that is pushing you away from the tipis\n";
		}
		if (input == "east" || input == "e") {
			cout << "there is a force that is pushing you away from the tipis\n";
		}
		if (input == "south" || input == "s") {
			cout << "thats a cliff dumb, dumb\n";

		}
		if (input == "take keys" && keyvision == true && Inventory::_mainstreetinventory == "keys") {
			cout << "taken\n";
			GameData::xp = GameData::xp + 20;
			Inventory::_inventory[ekeys] = "keys";
			Inventory::_mainstreetinventory = "";
		}
		Actions(_MainStreet);
	}
}