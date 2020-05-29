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
using namespace Beach;


void Beach::SouthBeach() {
	srand(time(NULL));
	//Defs.
	input = "";
	GameData::damage = ((rand() % 5) + GameData::DamMod);
	Room SouthBeach;

	//Description
	SouthBeach.SetRoomName("South Beach");
	SouthBeach.SetRoomDescript("You are standing on a sandy beach.");
	PrintRoomDescript(SouthBeach);

	//Exits
	SouthBeach.SetNorthExits("jungle and a mountain with sheer cliffs");
	SouthBeach.SetEastExits("beach");
	SouthBeach.SetSouthExits("water");
	SouthBeach.SetWestExits("beach");
	PrintExits(SouthBeach);


	while (input != "north" && input != "n" && input != "east" && input != "e" && "west" && input != "w") {
		getline(cin, input);
		if (input == "north" || input == "n") {
			Jungle::CaveClearing();
		}
		if (input == "east" || input == "e") {
			EastBeach();
		}
		if (input == "south" || input == "s") {
			cout << "There is water there" << endl;
		}
		if (input == "west" || input == "w") {
			WestBeach();
		}
		Actions(SouthBeach);
	}
}



void Beach::NorthEastBeach() {
	srand(time(NULL));
	//Defs.
	input = "";
	GameData::damage = ((rand() % 5) + GameData::DamMod);
	Room NorthEastBeach;

	//Description
	NorthEastBeach.SetRoomName("NorthEast Beach");
	NorthEastBeach.SetRoomDescript("You are on a beach");
	PrintRoomDescript(NorthEastBeach);

	//Exits
	NorthEastBeach.SetNorthExits("beach");
	NorthEastBeach.SetEastExits("water");
	NorthEastBeach.SetSouthExits("beach");
	NorthEastBeach.SetWestExits("jungle");
	PrintExits(NorthEastBeach);

	//Actions
	while (input != "north" && input != "n" && input != "east" && input != "e" && input != "south" && input != "s" && input != "west" && input != "w") {
		getline(cin, input);
		if (input == "north" || input == "n") {
			NorthBeach();
		}
		if (input == "west" || input == "w") {
			Jungle::EastJungle();
		}
		if (input == "east" || input == "e") {
			cout << "there is water there\n";
		}
		if (input == "south" || input == "s") {
			EastBeach();
		}
		Actions(NorthEastBeach);
	}
}





void Beach::NorthWestBeach() {
	srand(time(NULL));
	//Defs.
	input = "";
	GameData::damage = ((rand() % 5) + GameData::DamMod);
	Room NorthWestBeach;

	//Description
	NorthWestBeach.SetRoomName("NorthWest Beach");
	NorthWestBeach.SetRoomDescript("There is a giant symbol in the sand \n    ____\n   |\n___|___\n   |\n   |____");
	PrintRoomDescript(NorthWestBeach);

	//Exits
	NorthWestBeach.SetNorthExits("beach");
	NorthWestBeach.SetEastExits("jungle");
	NorthWestBeach.SetSouthExits("beach");
	NorthWestBeach.SetWestExits("water");
	PrintExits(NorthWestBeach);

	//Actions
	while (input != "north" && input != "n" && input != "east" && input != "e" && input != "south" && input != "s" && input != "west" && input != "w") {
		getline(cin, input);
		if (input == "north" || input == "n") {
			NorthBeach();
		}
		if (input == "west" || input == "w") {
			cout << "there is water there\n";
		}
		if (input == "east" || input == "e") {
			Jungle::WestJungle();
		}
		if (input == "south" || input == "s") {
			WestBeach();
		}
		Actions(NorthWestBeach);
	}
}




void Beach::NorthBeach() {
	srand(time(NULL));
	//Defs.
	input = "";
	GameData::damage = ((rand() % 5) + GameData::DamMod);
	Room NorthBeach;


	//Description
	NorthBeach.SetRoomName("North Beach");
	if (Inventory::_NorthBechInventory == "earmuffs") {
		NorthBeach.SetRoomDescript("there is an old crate lying on the beach, inside are earmuffs");
	}
	if (Inventory::_NorthBechInventory != "earmuffs") {
		NorthBeach.SetRoomDescript("there is an old crate lying on the beach");
	}
	PrintRoomDescript(NorthBeach);

	//Exits
	NorthBeach.SetNorthExits("water");
	NorthBeach.SetEastExits("water");
	NorthBeach.SetSouthExits("jungle and a sloping hill");
	NorthBeach.SetWestExits("water");
	PrintExits(NorthBeach);
	cout << "you can go south east and south west just for this room, there is beach in each of those directions\n";

	//Actions
	while (input != "south" && input != "s" && input != "south east" && input != "south west") {
		getline(cin, input);
		if (input == "north" || input == "n") {
			cout << "there is water there" << endl;
		}
		if (input == "east" || input == "e") {
			cout << "there is water there" << endl;
		}
		if (input == "south" || input == "s") {
			Cliff::Bluff();
		}
		if (input == "south east") {
			NorthEastBeach();
		}
		if (input == "south west") {
			NorthWestBeach();
		}
		if (input == "west" || input == "w") {
			cout << "There is water there" << endl;
		}
		if (input == "take earmuffs" && Inventory::_NorthBechInventory == "earmuffs") {
			cout << "taken\n";
			Inventory::_inventory[eEarmuffs] = "earmuffs";
			Inventory::_NorthBechInventory = "";
			GameData::xp = GameData::xp + 5;
		}
		Actions(NorthBeach);
	}
}




void Beach::EastBeach() {
	//Defs.
	input = "";
	srand(time(NULL));
	GameData::damage = ((rand() % 5) + GameData::DamMod);
	Room EastBeach;

	//Description
	EastBeach.SetRoomName("East Beach");
	EastBeach.SetRoomDescript("There is a single palm tree with a slice in the bark.");
	PrintRoomDescript(EastBeach);

	//Exits
	EastBeach.SetNorthExits("beach");
	EastBeach.SetEastExits("water");
	EastBeach.SetSouthExits("beach");
	EastBeach.SetWestExits("water");
	PrintExits(EastBeach);


	do {
		input = "";
		getline(cin, input);
		if (input == "north" || input == "n") {
			NorthEastBeach();
		}
		if (input == "west" || input == "w") {
			SouthBeach();
		}
		if (input == "east" || input == "e") {
			cout << "there is water there" << endl;
		}
		if (input == "south" || input == "s") {
			cout << "There is water there" << endl;
		}
		if (input == "climb tree" || input == "climb palm tree") {
			UpPalmTree();
		}
		Actions(EastBeach);
	} while (input != "north" && input != "n" && "west" && input != "w" && input != "climb tree" && input != "climb palm tree");
}
void Beach::UpPalmTree() {
	//Defs.
	input = "";
	srand(time(NULL));
	GameData::damage = ((rand() % 5) + GameData::DamMod);
	Room UpPalmTree;

	//Description
	UpPalmTree.SetRoomName("Up Palm tree");
	if (Inventory::_Coconutinventory == "dagger") {
		UpPalmTree.SetRoomDescript("there are few branches and after finding the best branch you manage to pull your self up and into the tree, you see a coconut with a fine seem/crack running down the center wedged between two branches");
	}
	else {
		UpPalmTree.SetRoomDescript("there are few branches and after finding the best branch you manage to pull your self up and into the tree");
	}
	PrintRoomDescript(UpPalmTree);

	//Exits
	UpPalmTree.SetNorthExits("beach");
	UpPalmTree.SetEastExits("beach");
	UpPalmTree.SetSouthExits("water");
	UpPalmTree.SetWestExits("water");
	PrintExits(UpPalmTree);


	do {
		getline(cin, input);
		if (input == "climb down" || input == "down") {
			EastBeach();
		}
		if ((input == "open coconut" || input == "take coconut") && Inventory::_Coconutinventory == "dagger") {
			cout << "you take the coconut and manage to wedge your fingers in the seem and it fall open in your lap\n";
			cout << "inside is a black, shiny dagger with a jewl incrusted hilt\n";
			GameData::xp = GameData::xp + 5;
			GameData::coconut = true;
		}
		if (input == "take dagger" && GameData::coconut == true) {
			Inventory::_inventory[eDagger] = "dagger";
			Inventory::_Coconutinventory = "";
			cout << "taken\n";
			GameData::xp = GameData::xp + 5;
		}
		Actions(UpPalmTree);
	} while (input != "climb down" && input != "down");
}






void Beach::WestBeach() {
	//Defs.
	srand(time(NULL));
	GameData::damage = ((rand() % 5) + GameData::DamMod);
	Room WestBeach;
	input = "";

	//Description
	WestBeach.SetRoomName("West Beach");
	WestBeach.SetRoomDescript("There is and old sign hammered into the ground reading \"You are not welcome on Caelesti Island\"");
	PrintRoomDescript(WestBeach);

	//Exits
	WestBeach.SetNorthExits("beach");
	WestBeach.SetEastExits("jungle");
	WestBeach.SetSouthExits("water");
	WestBeach.SetWestExits("water");
	PrintExits(WestBeach);

	//Actions
	while (input != "north" && input != "n" && input != "east" && input != "e") {
		getline(cin, input);
		if (input == "north" || input == "n") {
			NorthWestBeach();
		}
		if (input == "east" || input == "e") {
			SouthBeach();
		}
		if (input == "south" || input == "s") {
			cout << "There is water there" << endl;
		}
		if (input == "west" || input == "w") {
			cout << "There is water there" << endl;
		}
		Actions(WestBeach);
	}
}