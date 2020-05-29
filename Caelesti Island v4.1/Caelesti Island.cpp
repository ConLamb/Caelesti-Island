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
/*
void _music();
thread Music(_music);

void _music() {
	PlaySound("Ben Hur.mp3", NULL, SND_SYNC);
}
*/

	//Rooms
	int main()
	{
		system("color 0b");
		srand(time(NULL));
		//Defs.
		GameData::damage = ((rand() % 5) + GameData::DamMod);
		srand(time(NULL));
		NPC::Rat::RatHealth = (rand() % 4 + 3);
		thread Admin(tAdmin);
		thread start(xp);
		

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
		Beach::SouthBeach();
	}