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
using namespace Jungle;



void Jungle::WestJungle() {
	srand(time(NULL));
	//Defs.
	input = "";
	GameData::damage = ((rand() % 5) + GameData::DamMod);
	Room WestJungle;

	//Description
	WestJungle.SetRoomName("West Jungle");
	WestJungle.SetRoomDescript("You are is a small parting in the trees");
	PrintRoomDescript(WestJungle);

	//Exits
	WestJungle.SetNorthExits("thining trees");
	WestJungle.SetEastExits("dense jungle");
	WestJungle.SetSouthExits("trees");
	WestJungle.SetWestExits("thining trees");
	PrintExits(WestJungle);

	//Actions
	while (input != "north" && input != "n" && input != "east" && input != "e" && input != "south" && input != "s" && input != "west" && input != "w") {
		getline(cin, input);
		if (input == "north" || input == "n") {
			Beach::NorthBeach();
		}
		if (input == "west" || input == "w") {
			Beach::NorthWestBeach();
		}
		if (input == "east" || input == "e") {
			CaveClearing();
		}
		if (input == "south" || input == "s") {
			Beach::WestBeach();
		}
		Actions(WestJungle);
	}
}




void Jungle::EastJungle() {
	srand(time(NULL));
	//Defs.
	input = "";
	GameData::damage = ((rand() % 5) + GameData::DamMod);
	Room EastJungle;

	//Description
	EastJungle.SetRoomName("East Jungle");
	EastJungle.SetRoomDescript("Among the trees there is a recently snuffed fire smoking gently");
	PrintRoomDescript(EastJungle);

	//Exits
	EastJungle.SetNorthExits("thining trees");
	EastJungle.SetEastExits("trees");
	EastJungle.SetSouthExits("thinning trees");
	EastJungle.SetWestExits("trees");
	PrintExits(EastJungle);

	while (input != "north" && input != "n" && input != "east" && input != "e" && input != "south" && input != "s" && input != "west" && input != "w") {
		getline(cin, input);
		if (input == "north" || input == "n") {
			Beach::NorthBeach();
		}
		if (input == "west" || input == "w") {
			Jungle::CaveClearing();
		}
		if (input == "east" || input == "e") {
			Beach::NorthEastBeach();
		}
		if (input == "south" || input == "s") {
			Beach::EastBeach();
		}
		Actions(EastJungle);
	}
}








void Jungle::CaveClearing() {
	srand(time(NULL));
	//Defs.
	GameData::damage = ((rand() % 5) + GameData::DamMod);
	Room CaveClearing;
	input = "";

	//Description
	CaveClearing.SetRoomName("Cave Clearing");
	CaveClearing.SetRoomDescript("You stand in a clearing");
	PrintRoomDescript(CaveClearing);
	//Exits
	CaveClearing.SetNorthExits("the mouth of a cave");
	CaveClearing.SetEastExits("jungle");
	CaveClearing.SetSouthExits("thin jungle with beach beyond");
	CaveClearing.SetWestExits("jungle");
	PrintExits(CaveClearing);

	while (input != "north" && input != "n" && input != "east" && input != "e" && input != "south" && input != "s" && input != "west" && input != "w") {
		getline(cin, input);
		if (input == "north" || input == "n") {
			Cave1::CaveEntrance();
		}
		if (input == "west" || input == "w") {
			WestJungle();
		}
		if (input == "east" || input == "e") {
			EastJungle();
		}
		if (input == "south" || input == "s") {
			Beach::SouthBeach();
		}
		Actions(CaveClearing);
	}
}
