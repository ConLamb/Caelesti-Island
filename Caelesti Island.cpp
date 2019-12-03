#include <string>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <thread>
#include <chrono>
using namespace std;

void Inventory();
//Room Delclarations
void SouthBeach();
void CaveClearing();
void NorthBeach();
void EastBeach();
void WestBeach();
void UpPalmTree();
void CaveEntrance();
void SupplyRoom();
void WellRoom();
void RatFight();
void CrateRoom();

//Varibles
int health = 20;
int maxhealth = 20;
int damage;
int xp = 0;
string input;
string _inventory[20] = { "compass" };
int RatHealth = 21;
int DaggerDamage;
int RatDamage;
string _Coconutinventory = "dagger";
int souphealth = 5;
string _CrateInventory[3] = { "goggles", "soup", "hammer" };





class Descript
{
public:
	Descript() {}

	//Description
	void SetRoomName(string room);
	void SetRoomDescript(string room);
	void PrintRoomDescript();



	//Exits
	void SetNorthExits(string exit);
	void SetEastExits(string exit);
	void SetSouthExits(string exit);
	void SetWestExits(string exit);
	void PrintExits();



private:
	//Description
	string _RoomName;
	string _RoomDescript;



	//Exits
	string _NorthExits;
	string _EastExits;
	string _SouthExits;
	string _WestExits;
};

//Description
void Descript::SetRoomName(string room) {
	_RoomName = room;
}
void Descript::SetRoomDescript(string room) {
	_RoomDescript = room;
}
void Descript::PrintRoomDescript() {
	cout << _RoomName << endl << _RoomDescript << endl;
}
void PrintRoomDescript(Descript aroom) {
	aroom.PrintRoomDescript();
}


//Exits
void Descript::SetNorthExits(string exit) {
	_NorthExits = exit;
}
void Descript::SetEastExits(string exit) {
	_EastExits = exit;
}
void Descript::SetSouthExits(string exit) {
	_SouthExits = exit;
}
void Descript::SetWestExits(string exit) {
	_WestExits = exit;
}
void Descript::PrintExits() {
	cout << "north is " << _NorthExits << ", east is " << _EastExits << ", south is " << _SouthExits << ", west is " << _WestExits << endl;
}
void PrintExits(Descript anExit) {
	anExit.PrintExits();
}



void Actions() {
	srand(time(NULL));

	if (input == "inventory" || input == "i") {
		Inventory();
	}
	if ((input == "use soup" || input == "drink soup" || input == "eat soup") && _inventory[2] == "soup") {
		souphealth = (souphealth + (rand() % 5));
		health = souphealth + health;
		if (health > maxhealth) {
			health = maxhealth;
		}
		cout << "you now have " << health << " health\n";
		_inventory[1] = "";
	}
}



void Inventory() {
	cout << "health: " << health << endl;
	cout << "experence points: " << xp << endl;
	//Items
	size_t n = sizeof(_inventory) / sizeof(_inventory[0]);
	for (size_t i = 0; i < n; i++) {
		cout << _inventory[i] << ' ';
	}
	cout << "\n" << endl;
}







/*
while (input != "north", "n", "east", "e", "south", "s","west", "w") {
	getline(cin, input);
	if (input == "north" || input == "n") {

	}
	if (input == "west" || input == "w") {
		WestBeach();
	}
	if (input == "east" || input == "e") {
		EastBeach();
	}
	if (input == "south" || input == "s") {

	}

}
	*/






	//Rooms
int main()
{

	//EnterRoom(southBeach); 
	//return 0;

	srand(time(NULL));
	//Defs.
	damage = ((rand() % 5) + 2);

	cout << "Ready: Player1" << endl;
	cout << "[Enter]\n";
	getline(cin, input);

	cout << "Markeo is an explorer and captain of the \"Thandal Pacidicus\". He has been at sea for the last four months and hasent seen land since he left." << endl;
	cout << "[Enter]";
	getline(cin, input);
	cout << "Today, Markeo was again thinking that the voyage might be pointless and how it would be better to turn back when the ship's boy's voise was carried back to him on the wind" << endl;
	cout << "[Enter]";
	getline(cin, input);
	cout << "\"Land Ho!!!!\"" << endl;
	cout << "[Enter]";
	getline(cin, input);
	cout << "Markeo jumped with relif, the twinkle of adventure aglean in his eye once more." << endl;
	cout << "[Enter]";
	getline(cin, input);
	cout << "As they approached the island, everybody was bustling around, preparing for for their first stepps on land in four months." << endl;
	cout << "[Enter]";
	getline(cin, input);
	cout << "After 20 minutes that seemed an hour, they arrived at the island and dropped anchor." << endl;
	cout << "[Enter]";
	getline(cin, input);
	cout << "They all eagerly climed into the small skiffs with their equipment and started to row for the island." << endl;
	cout << "[Enter]";
	getline(cin, input);
	cout << "Markeo, steps out of the boat first and stumble as his feet touch the first solid ground in four months. " << endl;
	cout << "[Enter]";
	getline(cin, input);
	cout << "as Markeo regains his stance, he stagers again, and colapses along with the rest of his crew" << endl;
	system("CLS");
	cout << "you \"Markeo\" wake up and recount what happened" << endl << "as you look around you find that your crew and supplies have vanished and you have been striped of everything but your compass" << endl;

	SouthBeach();
}




void SouthBeach() {
	srand(time(NULL));
	//Defs.
	damage = ((rand() % 5) + 2);
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


	while (input != "north", "n", "east", "e", "south", "s", "west", "w") {
		getline(cin, input);
		if (input == "north" || input == "n") {
			CaveClearing();
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
		Actions();
	}
}






void CaveClearing() {
	srand(time(NULL));
	//Defs.
	damage = ((rand() % 5) + 2);
	Descript CaveClearing;

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





	while (input != "north", "n", "east", "e", "south", "s", "west", "w") {
		getline(cin, input);
		if (input == "north" || input == "n") {
			CaveEntrance();
		}
		if (input == "west" || input == "w") {

		}
		if (input == "east" || input == "e") {

		}
		if (input == "south" || input == "s") {
			SouthBeach();
		}
		Actions();
	}
}






void NorthBeach() {
	srand(time(NULL));
	//Defs.
	damage = ((rand() % 5) + 2);
	Descript NorthBeach;

	//Description
	NorthBeach.SetRoomName("North Beach");
	NorthBeach.SetRoomDescript("there is an old crate lying on the beach");
	PrintRoomDescript(NorthBeach);

	//Exits
	NorthBeach.SetNorthExits("water");
	NorthBeach.SetEastExits("water");
	NorthBeach.SetSouthExits("jungle and a sloping hill");
	NorthBeach.SetWestExits("water");
	PrintExits(NorthBeach);

	//Actions
	while (input != "north", "n", "east", "e", "south", "s", "west", "w") {
		getline(cin, input);
		if (input == "north" || input == "n") {
			cout << "there is water there" << endl;
		}
		if (input == "east" || input == "e") {
			cout << "there is water there" << endl;
		}
		if (input == "south" || input == "s") {

		}
		if (input == "west" || input == "w") {
			cout << "There is water there" << endl;
		}
		Actions();
	}
}




void EastBeach() {
	//Defs.
	srand(time(NULL));
	damage = ((rand() % 5) + 2);
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




	while (input != "north", "n", "east", "e", "south", "s", "west", "w") {
		getline(cin, input);
		if (input == "north" || input == "n") {
			NorthBeach();
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
		if (input == "climb tree") {
			UpPalmTree();
		}
		Actions();
	}
}
void UpPalmTree() {


	cout << "Up Palm tree\n";
	cout << "there are few branches and after finding the best branch you manage to pull your self up and into the tree" << endl;
	if (_Coconutinventory == "dagger") {
		cout << "you see a coconut with a fine seem/crack running down the center wedged between two branches\n";
	}


	while (input != "climb down", "down") {
		getline(cin, input);
		Actions();
		if (input == "climb down" || input == "down") {
			EastBeach();
		}
		if (input == "open coconut" || input == "take coconut" && _Coconutinventory == "dagger") {
			cout << "you take the coconut and manage to wedge your fingers in the seem and it fall open in your lap\n";
			cout << "inside is a black, shiny dagger with a jewl incrusted hilt\n";
			getline(cin, input);
			Actions();
			if (input == "take dagger") {
				_inventory[1] = "dagger";
				_Coconutinventory = "";
				cout << "taken\n";
			}
		}
	}
}






void WestBeach() {
	//Defs.
	srand(time(NULL));
	damage = ((rand() % 5) + 2);
	Descript WestBeach;

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
	while (input != "north", "n", "east", "e", "south", "s", "west", "w") {
		getline(cin, input);
		if (input == "north" || input == "n") {
			NorthBeach();
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
		Actions();
	}
}



void CaveEntrance() {
	//Defs.
	srand(time(NULL));
	damage = ((rand() % 5) + 2);
	Descript CaveEntrance;

	//Description
	CaveEntrance.SetRoomName("Cave Entrance");
	CaveEntrance.SetRoomDescript("There is a small bolder with scratch that form a language you do not understand");
	PrintRoomDescript(CaveEntrance);

	//Exits
	CaveEntrance.SetNorthExits("a cave");
	CaveEntrance.SetEastExits("a passage leading into a room");
	CaveEntrance.SetSouthExits("jungle");
	CaveEntrance.SetWestExits("rock");
	PrintExits(CaveEntrance);


	while (input != "north", "n", "east", "e", "south", "s", "west", "w") {
		getline(cin, input);
		if (input == "north" || input == "n") {
			WellRoom();
		}
		if (input == "east" || input == "e") {
			SupplyRoom();
		}
		if (input == "south" || input == "s") {
			CaveClearing();
		}
		if (input == "west" || input == "w") {
			cout << "There is rock there" << endl;
		}
		Actions();
	}
}



void SupplyRoom() {
	//Defs.
	srand(time(NULL));
	damage = ((rand() % 5) + 2);
	Descript SupplyRoom;

	//Description
	SupplyRoom.SetRoomName("Supply Room");
	if (RatHealth > 0) {
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
	SupplyRoom.SetSouthExits("the mouth of the cave");
	SupplyRoom.SetWestExits("rock");
	PrintExits(SupplyRoom);

	//Actions
	while (input != "north", "n", "east", "e", "south", "s", "west", "w") {
		getline(cin, input);
		if (input == "north" || input == "n") {
			if (RatHealth <= 0) {
				CrateRoom();
			}
		}
		if (input == "east" || input == "e") {
			cout << "there is rock there\n";
		}
		if (input == "south" || input == "s") {
			CaveEntrance();
		}
		if (input == "west" || input == "w") {
			cout << "There is rock there" << endl;
		}
		if (input == "fight rat" || "fight rat with dagger" && RatHealth > 0) {
			RatFight();
		}
		Actions();
	}
}
void RatFight() {
	//Defs.
	srand(time(NULL));
	damage = ((rand() % 5) + 8);
	DaggerDamage = 15 + (rand() % 11);
	RatDamage = 2 + (rand() % 5);


	if (input == "fight rat" && RatHealth > 0) {
		cout << "you punch and kick the rat\n";
		RatHealth = RatHealth - damage;
	}
	if (input == "fight rat with dagger" && _inventory[1] == "dagger" && RatHealth > 0) {
		cout << "slash at the rat with your dagger\n";
		RatHealth = RatHealth - DaggerDamage;
	}

	if (RatHealth >= 14) {
		cout << "the rat is doing well\n";
	}
	if (RatHealth < 14 && RatHealth >= 7) {
		cout << "the rat looks hurt\n";
	}
	if (RatHealth < 7 && RatHealth >= 1) {
		cout << "the rat is bloodied\n";
	}
	if (RatHealth <= 0) {
		cout << "the rat is dead\n";
	}
	if (health <= 0) {
		cout << "you died\n";
		cout << "  _______\n";
		cout << " /        \\\n";
		cout << " | R.I.P. |\n";
		cout << " | Markeo |\n";
		cout << " |        |\n";
		cout << " |        |\n";
		cout << "^^^^^^^^^^^^^\n";
		exit;
	}

	if (RatHealth > 0 && health > 0) {
		cout << "the rat takes a bite at you" << endl;
		cout << "you take " << RatDamage << " damage\n";
		health = health - RatDamage;
	}
}
void CrateRoom() {
	//Defs.

	srand(time(NULL));
	damage = ((rand() % 5) + 2);
	Descript CaveEntrance;

	cout << "Crate Room\n";
	cout << "you stand in front of the open crate. Inside are " << _CrateInventory[1] << " " << _CrateInventory[0] << "\n";

	//Exits
	CaveEntrance.SetNorthExits("rock");
	CaveEntrance.SetEastExits("rock");
	CaveEntrance.SetSouthExits("tunnel");
	CaveEntrance.SetWestExits("rock");
	PrintExits(CaveEntrance);


	getline(cin, input);
	while (input != "north", "n", "east", "e", "south", "s", "west", "w") {
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
		if (input == "take soup" && _CrateInventory[1] == "soup") {
			_inventory[2] = "soup";
			_CrateInventory[1] = "";
			cout << "taken" << endl;
		}
		if (input == "take goggles" && _CrateInventory[0] == "goggles") {
			_inventory[3] = "goggles";
			_CrateInventory[0] = "";
			cout << "taken\n";
		}
		Actions();
	}
}



void WellRoom() {
	//Defs.
	srand(time(NULL));
	damage = ((rand() % 5) + 2);
	Descript WellRoom;

	//Description
	WellRoom.SetRoomName("Well Room");
	if (_inventory[3] == "goggles") {
		WellRoom.SetRoomDescript("There is a well");
	}
	WellRoom.SetRoomDescript("");
	PrintRoomDescript(WellRoom);

	//Exits
	WellRoom.SetNorthExits("");
	WellRoom.SetEastExits("");
	WellRoom.SetSouthExits("");
	WellRoom.SetWestExits("");
	PrintExits(WellRoom);
}








//What has a head, a tail, is brown, and has no legs?
//penny