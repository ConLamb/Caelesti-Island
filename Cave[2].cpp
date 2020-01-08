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




void StorageRoom() {
	srand(time(NULL));
	//Defs.
	GameData::input = "";
	GameData::damage = ((rand() % 5) + 2);
	Descript StorageRoom;

	//Description
	StorageRoom.SetRoomName("Storage Room");
	StorageRoom.SetRoomDescript("there are large emty boxes in each corner");
	PrintRoomDescript(StorageRoom);

	//Exits
	StorageRoom.SetNorthExits("a door");
	StorageRoom.SetEastExits("a doorway reading Dungeon \ndo not enter");
	StorageRoom.SetSouthExits("passage");
	StorageRoom.SetWestExits("-west");
	PrintExits(StorageRoom);

	while (GameData::input != "north" && GameData::input != "n" && GameData::input != "east" && GameData::input != "e" && GameData::input != "south" && GameData::input != "s" && GameData::input != "west" && GameData::input != "w") {
		getline(cin, GameData::input);
		if (GameData::input == "north" || GameData::input == "n") {
			TrollRoom();
		}
		if (GameData::input == "west" || GameData::input == "w") {

		}
		if (GameData::input == "east" || GameData::input == "e") {
			Dungeon();
		}
		if (GameData::input == "south" || GameData::input == "s") {

		}
		Actions();
	}
}




void Dungeon() {
	cout << "it said dont go this way\n";
	cout << "the door slams behind you and you are stuck\n";
	cout << "there is a solid gold vein in the center of the room beating";
	exit;
}





void TrollRoom() {
	srand(time(NULL));
	//Defs.
	GameData::input = "";
	GameData::damage = ((rand() % 5) + 2);
	Descript TrollRoom;
	//Description
	TrollRoom.SetRoomName("Troll Room");
	TrollRoom.SetRoomDescript("There is a tall troll in the middle of the roomwith a large battle axe baring your way. Behing is a flaming red chicker with its head on fire");
	PrintRoomDescript(TrollRoom);
	//Exits
	if (GameData::TrollHealth > 0) {
		TrollRoom.SetNorthExits("-north");
		TrollRoom.SetEastExits("-east");
		TrollRoom.SetSouthExits("-south");
		TrollRoom.SetWestExits("-west");
	}
	else {
		TrollRoom.SetNorthExits("-north");
		TrollRoom.SetEastExits("-east");
		TrollRoom.SetSouthExits("-south");
		TrollRoom.SetWestExits("-west");
	}

	PrintExits(TrollRoom);
	while (GameData::input != "north" && GameData::input != "n" && GameData::input != "east" && GameData::input != "e" && GameData::input != "south" && GameData::input != "s" && GameData::input != "west" && GameData::input != "w") {
		getline(cin, GameData::input);
		if (GameData::input == "north" || GameData::input == "n") {
		}
		if (GameData::input == "west" || GameData::input == "w") {
		}
		if (GameData::input == "east" || GameData::input == "e") {
		}
		if (GameData::input == "south" || GameData::input == "s") {
			StorageRoom();
		}
		if (GameData::input == "fight troll" || "fight troll with dagger") {
			TrollFight();
		}
		Actions();
	}
}
void TrollFight() {
	if (GameData::input == "fight troll") {
		cout << "you punch and kick the troll\n";

	}
}