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




void WestJungle() {
	srand(time(NULL));
	//Defs.
	GameData::input = "";
	GameData::damage = ((rand() % 5) + 2);
	Descript WestJungle;

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
	while (GameData::input != "north" && GameData::input != "n" && GameData::input != "east" && GameData::input != "e" && GameData::input != "south" && GameData::input != "s" && GameData::input != "west" && GameData::input != "w") {
		getline(cin, GameData::input);
		if (GameData::input == "north" || GameData::input == "n") {
			NorthBeach();
		}
		if (GameData::input == "west" || GameData::input == "w") {
			NorthWestBeach();
		}
		if (GameData::input == "east" || GameData::input == "e") {
			CaveClearing();
		}
		if (GameData::input == "south" || GameData::input == "s") {
			WestBeach();
		}
		Actions();
	}
}




void EastJungle() {
	srand(time(NULL));
	//Defs.
	GameData::input = "";
	GameData::damage = ((rand() % 5) + 2);
	Descript EastJungle;

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

	while (GameData::input != "north" && GameData::input != "n" && GameData::input != "east" && GameData::input != "e" && GameData::input != "south" && GameData::input != "s" && GameData::input != "west" && GameData::input != "w") {
		getline(cin, GameData::input);
		if (GameData::input == "north" || GameData::input == "n") {
			NorthBeach();
		}
		if (GameData::input == "west" || GameData::input == "w") {
			CaveClearing();
		}
		if (GameData::input == "east" || GameData::input == "e") {
			NorthEastBeach();
		}
		if (GameData::input == "south" || GameData::input == "s") {
			EastBeach();
		}
		Actions();
	}
}








void CaveClearing() {
	srand(time(NULL));
	//Defs.
	GameData::damage = ((rand() % 5) + 2);
	Descript CaveClearing;
	GameData::input = "";

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

	while (GameData::input != "north" && GameData::input != "n" && GameData::input != "east" && GameData::input != "e" && GameData::input != "south" && GameData::input != "s" && GameData::input != "west" && GameData::input != "w") {
		getline(cin, GameData::input);
		if (GameData::input == "north" || GameData::input == "n") {
			CaveEntrance();
		}
		if (GameData::input == "west" || GameData::input == "w") {
			WestJungle();
		}
		if (GameData::input == "east" || GameData::input == "e") {
			EastJungle();
		}
		if (GameData::input == "south" || GameData::input == "s") {
			SouthBeach();
		}
		Actions();
	}
}
