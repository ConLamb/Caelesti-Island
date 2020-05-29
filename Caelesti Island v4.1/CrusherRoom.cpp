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

int counter = 60;
void foo()
{
	do {
		getline(cin, input);
		if (input == "solve") {
			cout << "you did it\n";
			GameData::time = true;
			exit(0);
		}
		if (input == "time") {
			cout << counter << endl;
		}
	} while (input != "solve");
}

void bar(int x)
{
	for (counter > 0; counter--;) {
		if (GameData::time == true) {
			exit;
		}
		Sleep(1000);
		if (GameData::time == true) {
			exit;
		}
	}
	cout << "you died\n";
	exit(0);

}

void Civilization::CrusherRoom() {
	//Defs.
	input = "";
	srand(time(NULL));
	GameData::damage = ((rand() % 5) + GameData::DamMod);
	Room EastBeach;

	//Description
	EastBeach.SetRoomName("Crusher Room");
	EastBeach.SetRoomDescript("");
	PrintRoomDescript(EastBeach);

	//Exits
	EastBeach.SetNorthExits("beach");
	EastBeach.SetEastExits("beach");
	EastBeach.SetSouthExits("water");
	EastBeach.SetWestExits("water");
	PrintExits(EastBeach);



	thread first(foo);     // spawn new thread that calls foo()
	thread second(bar, 0);  // spawn new thread that calls bar(0)
	// synchronize threads:
	first.join();                // pauses until first finishes
	second.join();               // pauses until second finishes
}