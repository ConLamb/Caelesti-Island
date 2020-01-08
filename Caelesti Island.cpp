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
using namespace std;



	





	

	/*
		srand(time(NULL));
		//Defs.
		GameData::input = "";
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
		Actions();
	}
	*/






	//Rooms
	int main()
	{

		system("color 0b");
		srand(time(NULL));
		//Defs.
		GameData::damage = ((rand() % 5) + 2);

		cout << "Ready: Player1" << endl;
		cout << "[Enter]\n";
		getline(cin, GameData::input);

		cout << "Markeo is an explorer and captain of the \"Thandal Pacidicus\". He has been at sea for the last four months and hasn't seen land since he left." << endl;
		cout << "[Enter]";
		getline(cin, GameData::input);
		cout << "Today, Markeo was again thinking that the voyage might be pointless and how it would be better to turn back when the ship's boy's voice was carried back to him on the wind" << endl;
		cout << "[Enter]";
		getline(cin, GameData::input);
		cout << "\"Land Ho!!!!\"" << endl;
		cout << "[Enter]";
		getline(cin, GameData::input);
		cout << "Markeo jumped with relif, the twinkle of adventure aglean in his eye once more." << endl;
		cout << "[Enter]";
		getline(cin, GameData::input);
		cout << "As they approached the island, everybody was bustling around, preparing for their first steps on land in four months." << endl;
		cout << "[Enter]";
		getline(cin, GameData::input);
		cout << "After 20 minutes that seemed an hour, they arrived at the island and dropped anchor." << endl;
		cout << "[Enter]";
		getline(cin, GameData::input);
		cout << "They all eagerly climbed into the small skiffs with their equipment and started to row for the island." << endl;
		cout << "[Enter]";
		getline(cin, GameData::input);
		cout << "Markeo, steps out of the boat first and stumbles as his feet touch the first solid ground in four months. " << endl;
		cout << "[Enter]";
		getline(cin, GameData::input);
		cout << "as Markeo regains his stance, he staggers again, and collapses along with the rest of his crew" << endl;
		cout << "[Enter]";
		getline(cin, GameData::input);
		system("CLS");
		cout << "you \"Markeo\" wake up and recount what happened" << endl << "as you look around you find that your crew and supplies have vanished and you have been stripped of everything but your compass" << endl;

		SouthBeach();
	}