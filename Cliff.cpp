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



void Bluff() {
	srand(time(NULL));
	//Defs.
	GameData::input = "";
	GameData::damage = ((rand() % 5) + 2);
	Descript Bluff;

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

	while (GameData::input != "north" && GameData::input != "n" && GameData::input != "south" && GameData::input != "s") {
		getline(cin, GameData::input);
		if (GameData::input == "north" || GameData::input == "n") {
			NorthBeach();
		}
		if (GameData::input == "west" || GameData::input == "w") {
			cout << "there is a cliff there\n";
		}
		if (GameData::input == "east" || GameData::input == "e") {
			cout << "there is a cliff there\n";
		}
		if (GameData::input == "south" || GameData::input == "s") {
			MainStreet();
		}
		Actions();
	}
}




void MainStreet() {
	srand(time(NULL));
	//Defs.
	GameData::input = "";
	int keysdc = 15;
	GameData::check = ((rand() % 21 + 1) + GameData::perception);
	Descript MainStreet;
	auto keyvision = false;

	//Description
	if (GameData::check >= keysdc) {
		MainStreet.SetRoomName("you are at the end of th village. there is a set of keys on the ground");
		keyvision = true;
	}
	else {
		MainStreet.SetRoomName("you are at the end of th village");
	}

	PrintRoomDescript(MainStreet);

	//Exits
	MainStreet.SetNorthExits("sheer cliffs");
	MainStreet.SetEastExits("tipis");
	MainStreet.SetSouthExits("the main street");
	MainStreet.SetWestExits("tipis");
	PrintExits(MainStreet);


	//Actions
	while (GameData::input != "north" && GameData::input != "n" && GameData::input != "east" && GameData::input != "e" && GameData::input != "south" && GameData::input != "s" && GameData::input != "west" && GameData::input != "w") {
		getline(cin, GameData::input);
		if (GameData::input == "north" || GameData::input == "n") {

		}
		if (GameData::input == "west" || GameData::input == "w") {

		}
		if (GameData::input == "east" || GameData::input == "e") {

		}
		if (GameData::input == "south" || GameData::input == "s") {

		}
		if (GameData::input == "take keys" && keyvision == true && GameData::_mainstreetinventory == "keys") {
			cout << "taken\n";
			GameData::_inventory[GameData::i] = "keys";
			GameData::_mainstreetinventory = "";
			GameData::i++;
		}
		Actions();
	}
}