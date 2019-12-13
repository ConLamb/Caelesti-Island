#include <string>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <thread>
#include <chrono>
#include <ctime>
#include <vector>
#include <map>
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
void InsideWell();
void WestJungle();
void NorthWestBeach();
void NorthEastBeach();
void EastJungle();
void StorageRoom();
void Dungeon();
void TrollRoom();
void Bluff();
void MainStreet();


//Varibles
int health = 20;
int maxhealth = 20;
int armor = 0;
int damage = 8;
int xp = 0;
string input;
string _inventory[20] = { "compass" };
int RatHealth = 21;
int DaggerDamage;
int RatDamage;
string _Coconutinventory = "dagger";
int souphealth = 5;
string _CrateInventory[3] = { "goggles", "soup", "hammer" };
bool safelock = true;
map<string, string> north{"north", "n"};
int perception = 3;
int check;
int i = 1;







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
	cout << "\n" << _RoomName << endl << _RoomDescript << endl;
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
	if (_NorthExits != "") {
		cout << "north is " << _NorthExits;
	}if (_EastExits != "") {
		cout << ", east is " << _EastExits;
	}if (_SouthExits != "") {
		cout << ", south is " << _SouthExits;
	}if (_WestExits != "") {
		cout << ", west is " << _WestExits << endl;
	}
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
		xp = xp + 5;
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
	cout << "armor: " << armor << endl;
	cout << endl;
	//Items
	size_t n = sizeof(_inventory) / sizeof(_inventory[0]);
	for (size_t i = 0; i < n; i++) {
		cout << _inventory[i] << ' ';
	}
	cout << "\n" << endl;
}







/*
	srand(time(NULL));
	//Defs.
	input = "";
	damage = ((rand() % 5) + 2);
	Descript anRoom;

	//Description
	anRoom.SetRoomName("Room Name");
	anRoom.SetRoomDescript("Room description");
	PrintRoomDescript(anRoom);

	//Exits
	anRoom.SetNorthExits("-north");
	anRoom.SetEastExits("-east");
	anRoom.SetSouthExits("-south");
	anRoom.SetWestExits("-west");
	PrintExits(anRoom);

while (input != "north" && input != "n" && input != "east" && input != "e" && input != "south" && input != "s" && input != "west" && input != "w") {
	getline(cin, input);
	if (input == "north" || input == "n") {

	}
	if (input == "west" || input == "w") {

	}
	if (input == "east" || input == "e") {

	}
	if (input == "south" || input == "s") {

	}
	Actions();
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

	cout << "Markeo is an explorer and captain of the \"Thandal Pacidicus\". He has been at sea for the last four months and hasn't seen land since he left." << endl;
	cout << "[Enter]";
	getline(cin, input);
	cout << "Today, Markeo was again thinking that the voyage might be pointless and how it would be better to turn back when the ship's boy's voice was carried back to him on the wind" << endl;
	cout << "[Enter]";
	getline(cin, input);
	cout << "\"Land Ho!!!!\"" << endl;
	cout << "[Enter]";
	getline(cin, input);
	cout << "Markeo jumped with relif, the twinkle of adventure aglean in his eye once more." << endl;
	cout << "[Enter]";
	getline(cin, input);
	cout << "As they approached the island, everybody was bustling around, preparing for their first steps on land in four months." << endl;
	cout << "[Enter]";
	getline(cin, input);
	cout << "After 20 minutes that seemed an hour, they arrived at the island and dropped anchor." << endl;
	cout << "[Enter]";
	getline(cin, input);
	cout << "They all eagerly climbed into the small skiffs with their equipment and started to row for the island." << endl;
	cout << "[Enter]";
	getline(cin, input);
	cout << "Markeo, steps out of the boat first and stumbles as his feet touch the first solid ground in four months. " << endl;
	cout << "[Enter]";
	getline(cin, input);
	cout << "as Markeo regains his stance, he staggers again, and collapses along with the rest of his crew" << endl;
	cout << "[Enter]";
	getline(cin, input);
	system("CLS");
	cout << "you \"Markeo\" wake up and recount what happened" << endl << "as you look around you find that your crew and supplies have vanished and you have been stripped of everything but your compass" << endl;

	SouthBeach();
}




void SouthBeach() {
	srand(time(NULL));
	//Defs.
	input = "";
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


	while (input != "north" && input != "n" && input != "east" && input != "e" && "west" && input != "w") {
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




void WestJungle() {
	srand(time(NULL));
	//Defs.
	input = "";
	damage = ((rand() % 5) + 2);
	Descript WestJungle;

	//Description
	WestJungle.SetRoomName("South Beach");
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
			NorthBeach();
		}
		if (input == "west" || input == "w") {

		}
		if (input == "east" || input == "e") {
			CaveClearing();
		}
		if (input == "south" || input == "s") {
			WestBeach();
		}
		Actions();
	}
}




void EastJungle() {
	srand(time(NULL));
	//Defs.
	input = "";
	damage = ((rand() % 5) + 2);
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

	while (input != "north" && input != "n" && input != "east" && input != "e" && input != "south" && input != "s" && input != "west" && input != "w") {
		getline(cin, input);
		if (input == "north" || input == "n") {
			NorthBeach();
		}
		if (input == "west" || input == "w") {
			CaveClearing();
		}
		if (input == "east" || input == "e") {
			NorthEastBeach();
		}
		if (input == "south" || input == "s") {
			EastBeach();
		}
		Actions();
	}
}





void NorthEastBeach() {
	srand(time(NULL));
	//Defs.
	input = "";
	damage = ((rand() % 5) + 2);
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
	while (input != "north" && input != "n" && input != "east" && input != "e" && input != "south" && input != "s" && input != "west" && input != "w") {
		getline(cin, input);
		if (input == "north" || input == "n") {
			NorthBeach();
		}
		if (input == "west" || input == "w") {
			EastJungle();
		}
		if (input == "east" || input == "e") {
			cout << "there is water there\n";
		}
		if (input == "south" || input == "s") {
			EastBeach();
		}
		Actions();
	}
}





void NorthWestBeach() {
	srand(time(NULL));
	//Defs.
	input = "";
	damage = ((rand() % 5) + 2);
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
	while (input != "north" && input != "n" && input != "east" && input != "e" && input != "south" && input != "s" && input != "west" && input != "w") {
		getline(cin, input);
		if (input == "north" || input == "n") {
			NorthBeach();
		}
		if (input == "west" || input == "w") {
			cout << "there is water there\n";
		}
		if (input == "east" || input == "e") {
			WestJungle();
		}
		if (input == "south" || input == "s") {
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
	input = "";
	damage = ((rand() % 5) + 2);
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
	while (input != "south" && input != "s" && input != "south east" && input != "south west") {
		getline(cin, input);
		if (input == "north" || input == "n") {
			cout << "there is water there" << endl;
		}
		if (input == "east" || input == "e") {
			cout << "there is water there" << endl;
		}
		if (input == "south" || input == "s") {

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
		if (input == "take earmuffs" && _NorthBechInventory == "earmuffs") {
			cout << "taken\n";
			_inventory[i] = "earmuffs";
			_NorthBechInventory = "";
			i++;

		}
		Actions();
	}
}




void EastBeach() {
	//Defs.
	input = "";
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




	while (input != "north" && input != "n" && "west" && input != "w" && input != "climb tree" && input != "climb palm tree") {
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
		Actions();
	}
}
void UpPalmTree() {
	input = "";

	cout << "Up Palm tree\n";
	cout << "there are few branches and after finding the best branch you manage to pull your self up and into the tree" << endl;
	if (_Coconutinventory == "dagger") {
		cout << "you see a coconut with a fine seem/crack running down the center wedged between two branches\n";
	}


	while (input != "climb down" && input != "down") {
		getline(cin, input);
		Actions();
		if (input == "climb down" || input == "down") {
			EastBeach();
		}
		if ((input == "open coconut" || input == "take coconut") && _Coconutinventory == "dagger") {
			cout << "you take the coconut and manage to wedge your fingers in the seem and it fall open in your lap\n";
			cout << "inside is a black, shiny dagger with a jewl incrusted hilt\n";
			while (input != "take dagger") {
				getline(cin, input);
				Actions();
				if (input == "take dagger") {
					_inventory[i] = "dagger";
					_Coconutinventory = "";
					cout << "taken\n";
					i++;
				}
			}

		}
	}
}






void WestBeach() {
	//Defs.
	srand(time(NULL));
	damage = ((rand() % 5) + 2);
	Descript WestBeach;
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
		Actions();
	}
}



void Bluff() {
	srand(time(NULL));
	//Defs.
	input = "";
	damage = ((rand() % 5) + 2);
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

	while (input != "north" && input != "n"  && input != "south" && input != "s") {
		getline(cin, input);
		if (input == "north" || input == "n") {
			NorthBeach();
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
		Actions();
	}
}




void MainStreet() {
	srand(time(NULL));
	//Defs.
	input = "";
	int keysdc = 15;
	check = ((rand() % 21 + 1) + perception);
	Descript MainStreet;
	auto keyvision = false;

	//Description
	if (check >= keysdc) {
		MainStreet.SetRoomName("you are at the end of th village. there is a set of keys on the ground");
		keyvision = true;
	}
	else {
	MainStreet.SetRoomName("you are at the end of th village");
	}

	PrintRoomDescript(MainStreet);

	//Exits
	MainStreet.SetNorthExits("sheer cliffs");
	MainStreet.SetEastExits("tepis");
	MainStreet.SetSouthExits("the main street");
	MainStreet.SetWestExits("tepis");
	PrintExits(MainStreet);


	//Actions
	while (input != "north" && input != "n" && input != "east" && input != "e" && input != "south" && input != "s" && input != "west" && input != "w") {
		getline(cin, input);
		if (input == "north" || input == "n") {

		}
		if (input == "west" || input == "w") {

		}
		if (input == "east" || input == "e") {

		}
		if (input == "south" || input == "s") {

		}
		if (input == "take keys" && keyvision == true) {
			cout << "taken\n";
		}
		Actions();
	}
}





void CaveEntrance() {
	//Defs.
	srand(time(NULL));
	damage = ((rand() % 5) + 2);
	Descript CaveEntrance;
	input = "";

	//Description
	CaveEntrance.SetRoomName("Cave Entrance");
	if (_inventory[4] == "earmuffs") {
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


	while (input != "north" && input != "n" && input != "east" && input != "e" && input != "south" && input != "s") {
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
	input = "";

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
	SupplyRoom.SetSouthExits("rock");
	SupplyRoom.SetWestExits("the mouth of the cave");
	PrintExits(SupplyRoom);

	//Actions
	while (input != "north" && input != "n" && input != "west" && input != "w") {
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
			cout << "there is rock there\n";
		}
		if (input == "west" || input == "w") {
			CaveEntrance();
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
	damage = ((rand() % 5) + damage);
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
		xp = xp + 20;
	}
	if (health <= 0) {
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

	if (RatHealth > 0 && health > 0) {
		cout << "the rat takes a bite at you" << endl;
		cout << "you take " << RatDamage << " damage\n";
		health = health - (RatDamage - armor);
	}
}
void CrateRoom() {
	//Defs.

	srand(time(NULL));
	damage = ((rand() % 5) + 2);
	Descript CaveEntrance;
	input = "";

	cout << "Crate Room\n";
	cout << "you stand in front of the open crate. Inside are " << _CrateInventory[0] << " " << _CrateInventory[1] << "\n";

	//Exits
	CaveEntrance.SetNorthExits("rock");
	CaveEntrance.SetEastExits("rock");
	CaveEntrance.SetSouthExits("tunnel");
	CaveEntrance.SetWestExits("rock");
	PrintExits(CaveEntrance);


	while (input != "south" && input != "s") {
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
			cout << "taken\n";
			_inventory[2] = "soup";
			_CrateInventory[1] = "";
		}
		if (input == "take goggles" && _CrateInventory[0] == "goggles") {
			cout << "taken" << endl;
			_inventory[i] = "goggles";
			_CrateInventory[0] = "";
			i++;
		}
		Actions();
	}
}



void WellRoom() {
	//Defs.
	srand(time(NULL));
	damage = ((rand() % 5) + 2);
	Descript WellRoom;
	input = "";

	//Description
	WellRoom.SetRoomName("Well Room");
	if (_inventory[3] == "goggles") {
		WellRoom.SetRoomDescript("There is a well in the middle of the room that miners would use but it is very old, there is a ladder leading down");
	}
	else {
		WellRoom.SetRoomDescript("Very little light is leaching from behind you and you cant make out much");
	}
	PrintRoomDescript(WellRoom);

	//Exits
	if (_inventory[3] == "goggles") {
		WellRoom.SetNorthExits("a passage");
		WellRoom.SetEastExits("low passage");
		WellRoom.SetSouthExits("dimmly lit passage");
		WellRoom.SetWestExits("rock");
	}
	PrintExits(WellRoom);

	while (input != "north" && input != "n" && input != "east" && input != "e" && input != "south" && input != "s" && input != "west" && input != "w") {
		getline(cin, input);
		if (input == "north" || input == "n") {
			StorageRoom();
		}
		if (input == "west" || input == "w") {

		}
		if (input == "east" || input == "e") {

		}
		if (input == "south" || input == "s") {

		}
		if ((input == "go into well" || input == "down well") && _inventory[3] == "goggles") {
			InsideWell();
		}
		Actions();
	}

}
void InsideWell() {
	//Defs.
	srand(time(NULL));
	damage = ((rand() % 5) + 2);
	string _safeInventory = "hauberk";
	Descript InsideWell;
	input = "";
	

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

	while (input != "up" && input != "up well" && input != "climb up" && input != "climb up well") {
		input = "";
		getline(cin, input);
		if (input == "up" || input == "up well" || input == "climb up" || input == "climb up well") {
			WellRoom();
		}
		if ((input == "enter 3507" || input == "3507") && safelock == true) {
			safelock = false;
			if (_safeInventory == "hauberk") {
				cout << "there is a small hiss as the safe opens and out falls a hauberk\n";
				if (input == "take hauberk" && _safeInventory == "hauberk") {
					cout << "taken\n";
					_safeInventory = "";
					_inventory[i] = "hauberk";
					armor = armor + 2;
					i++;
				}
			}
			if (_safeInventory != "hauberk") {
				cout << "the safe is empty\n";
			}
		}
	}
}






void StorageRoom() {
	srand(time(NULL));
	//Defs.
	input = "";
	damage = ((rand() % 5) + 2);
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

	while (input != "north" && input != "n" && input != "east" && input != "e" && input != "south" && input != "s" && input != "west" && input != "w") {
		getline(cin, input);
		if (input == "north" || input == "n") {
			//TrollRoom();
		}
		if (input == "west" || input == "w") {

		}
		if (input == "east" || input == "e") {
			Dungeon();
		}
		if (input == "south" || input == "s") {

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






//void TrollRoom() {

//}