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





void Actions() {
	srand(time(NULL));

	if (GameData::input == "inventory" || GameData::input == "i") {
		Inventory();
	}
	if ((GameData::input == "use soup" || GameData::input == "drink soup" || GameData::input == "eat soup") && GameData::_inventory[2] == "soup") {
		GameData::souphealth = (GameData::souphealth + (rand() % 5));
		GameData::health = GameData::souphealth + GameData::health;
		GameData::xp = GameData::xp + 5;
		if (GameData::health > GameData::maxhealth) {
			GameData::health = GameData::maxhealth;
		}
		cout << "you now have " << GameData::health << " health\n";
		GameData::_inventory[1] = "";
	}
}



void Inventory() {
	cout << "health: " << GameData::health << endl;
	cout << "experence points: " << GameData::xp << endl;
	cout << "armor: " << GameData::armor << endl;
	cout << endl;
	//Items
	size_t n = sizeof(GameData::_inventory[1]) / sizeof(GameData::_inventory[0]);
	for (size_t i = 0; i < n; i++) {
		cout << GameData::_inventory[i] << ' ';
	}
	cout << "\n" << endl;
}