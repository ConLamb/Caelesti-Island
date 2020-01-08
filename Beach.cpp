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



void SouthBeach() {
	srand(time(NULL));
	//Defs.
	GameData::input = "";
	GameData::damage = ((rand() % 5) + 2);
	Descript SouthBeach;

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


	while (GameData::input != "north" && GameData::input != "n" && GameData::input != "east" && GameData::input != "e" && "west" && GameData::input != "w") {
		getline(cin, GameData::input);
		if (GameData::input == "north" || GameData::input == "n") {
			CaveClearing();
		}
		if (GameData::input == "east" || GameData::input == "e") {
			EastBeach();
		}
		if (GameData::input == "south" || GameData::input == "s") {
			cout << "There is water there" << endl;
		}
		if (GameData::input == "west" || GameData::input == "w") {
			WestBeach();
		}
		Actions();
	}
}



void NorthEastBeach() {
	srand(time(NULL));
	//Defs.
	GameData::input = "";
	GameData::damage = ((rand() % 5) + 2);
	Descript NorthEastBeach;

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
	while (GameData::input != "north" && GameData::input != "n" && GameData::input != "east" && GameData::input != "e" && GameData::input != "south" && GameData::input != "s" && GameData::input != "west" && GameData::input != "w") {
		getline(cin, GameData::input);
		if (GameData::input == "north" || GameData::input == "n") {
			NorthBeach();
		}
		if (GameData::input == "west" || GameData::input == "w") {
			EastJungle();
		}
		if (GameData::input == "east" || GameData::input == "e") {
			cout << "there is water there\n";
		}
		if (GameData::input == "south" || GameData::input == "s") {
			EastBeach();
		}
		Actions();
	}
}





void NorthWestBeach() {
	srand(time(NULL));
	//Defs.
	GameData::input = "";
	GameData::damage = ((rand() % 5) + 2);
	Descript NorthWestBeach;

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
	while (GameData::input != "north" && GameData::input != "n" && GameData::input != "east" && GameData::input != "e" && GameData::input != "south" && GameData::input != "s" && GameData::input != "west" && GameData::input != "w") {
		getline(cin, GameData::input);
		if (GameData::input == "north" || GameData::input == "n") {
			NorthBeach();
		}
		if (GameData::input == "west" || GameData::input == "w") {
			cout << "there is water there\n";
		}
		if (GameData::input == "east" || GameData::input == "e") {
			WestJungle();
		}
		if (GameData::input == "south" || GameData::input == "s") {
			WestBeach();
		}
		Actions();
	}
}




void NorthBeach() {
	srand(time(NULL));
	//Defs.
	GameData::input = "";
	GameData::damage = ((rand() % 5) + 2);
	Descript NorthBeach;
	string _NorthBechInventory = "earmuffs";

	//Description
	NorthBeach.SetRoomName("North Beach");
	if (_NorthBechInventory == "earmuffs") {
		NorthBeach.SetRoomDescript("there is an old crate lying on the beach, inside are earmuffs");
	}
	if (_NorthBechInventory != "earmuffs") {
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
	while (GameData::input != "south" && GameData::input != "s" && GameData::input != "south east" && GameData::input != "south west") {
		getline(cin, GameData::input);
		if (GameData::input == "north" || GameData::input == "n") {
			cout << "there is water there" << endl;
		}
		if (GameData::input == "east" || GameData::input == "e") {
			cout << "there is water there" << endl;
		}
		if (GameData::input == "south" || GameData::input == "s") {
			Bluff();
		}
		if (GameData::input == "south east") {
			NorthEastBeach();
		}
		if (GameData::input == "south west") {
			NorthWestBeach();
		}
		if (GameData::input == "west" || GameData::input == "w") {
			cout << "There is water there" << endl;
		}
		if (GameData::input == "take earmuffs" && _NorthBechInventory == "earmuffs") {
			cout << "taken\n";
			GameData::_inventory[GameData::i] = "earmuffs";
			_NorthBechInventory = "";
			GameData::i++;

		}
		Actions();
	}
}




void EastBeach() {
	//Defs.
	GameData::input = "";
	srand(time(NULL));
	GameData::damage = ((rand() % 5) + 2);
	Descript EastBeach;

	//Description
	EastBeach.SetRoomName("East Beach");
	EastBeach.SetRoomDescript("There is a single palm tree with a slice in the bark.");
	PrintRoomDescript(EastBeach);

	//Exits
	EastBeach.SetNorthExits("beach");
	EastBeach.SetEastExits("beach");
	EastBeach.SetSouthExits("water");
	EastBeach.SetWestExits("water");
	PrintExits(EastBeach);




	while (GameData::input != "north" && GameData::input != "n" && "west" && GameData::input != "w" && GameData::input != "climb tree" && GameData::input != "climb palm tree") {
		GameData::input = "";
		getline(cin, GameData::input);
		if (GameData::input == "north" || GameData::input == "n") {
			NorthEastBeach();
		}
		if (GameData::input == "west" || GameData::input == "w") {
			SouthBeach();
		}
		if (GameData::input == "east" || GameData::input == "e") {
			cout << "there is water there" << endl;
		}
		if (GameData::input == "south" || GameData::input == "s") {
			cout << "There is water there" << endl;
		}
		if (GameData::input == "climb tree" || GameData::input == "climb palm tree") {
			UpPalmTree();
		}
		Actions();
	}
}
void UpPalmTree() {
	GameData::input = "";

	cout << "Up Palm tree\n";
	cout << "there are few branches and after finding the best branch you manage to pull your self up and into the tree" << endl;
	if (GameData::_Coconutinventory == "dagger") {
		cout << "you see a coconut with a fine seem/crack running down the center wedged between two branches\n";
	}


	while (GameData::input != "climb down" && GameData::input != "down") {
		getline(cin, GameData::input);
		Actions();
		if (GameData::input == "climb down" || GameData::input == "down") {
			EastBeach();
		}
		if ((GameData::input == "open coconut" || GameData::input == "take coconut") && GameData::_Coconutinventory == "dagger") {
			cout << "you take the coconut and manage to wedge your fingers in the seem and it fall open in your lap\n";
			cout << "inside is a black, shiny dagger with a jewl incrusted hilt\n";
			while (GameData::input != "take dagger") {
				getline(cin, GameData::input);
				Actions();
				if (GameData::input == "take dagger") {
					GameData::_inventory[GameData::i] = "dagger";
					GameData::_Coconutinventory = "";
					cout << "taken\n";
					GameData::i++;
				}
			}

		}
	}
}






void WestBeach() {
	//Defs.
	srand(time(NULL));
	GameData::damage = ((rand() % 5) + 2);
	Descript WestBeach;
	GameData::input = "";

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
	while (GameData::input != "north" && GameData::input != "n" && GameData::input != "east" && GameData::input != "e") {
		getline(cin, GameData::input);
		if (GameData::input == "north" || GameData::input == "n") {
			NorthWestBeach();
		}
		if (GameData::input == "east" || GameData::input == "e") {
			SouthBeach();
		}
		if (GameData::input == "south" || GameData::input == "s") {
			cout << "There is water there" << endl;
		}
		if (GameData::input == "west" || GameData::input == "w") {
			cout << "There is water there" << endl;
		}
		Actions();
	}
}