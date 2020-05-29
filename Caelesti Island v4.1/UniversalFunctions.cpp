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








void Inventory() {
	cout << "health: " << GameData::health << endl;
	cout << "experence points: " << GameData::xp << endl;
	cout << "armor: " << GameData::armor << endl;
	cout << endl;
	//Items

	size_t n = sizeof(Inventory::_inventory) / sizeof(Inventory::_inventory[0]);

	for (size_t i = 0; i < n; i++) {
		cout << Inventory::_inventory[i] << ' ';
	}
	cout << "\n" << endl;
}




void xp(){
	while (true) {
		if (GameData::xp >= 300 && GameData::level == 1) {
			GameData::level = 2;
			GameData::DamMod = 2;
			GameData::perception = 4;
			GameData::armor++;
			GameData::maxhealth = 25;
			GameData::health = GameData::maxhealth;
			cout << "you are now level 2\n";
		}
	}
}




void tAdmin() {
	while (true) {
		if (input == "give xp") {
			GameData::xp = 295;    
		}
		if (input == "/inventory") {
			Inventory::_inventory[eHauberk] = "hauberk";
			Inventory::_inventory[eEarmuffs] = "earmuffs";
			Inventory::_inventory[eSoup] = "soup";
			Inventory::_inventory[eGoggles] = "goggles";
			Inventory::_inventory[ekeys] = "keys";
		}
		/*
		input.copy(__input, input.size() + 1);
		__input[input.size()] = '\0';
		if (__input[0] == "\\") {
			if (__input[1] = "x" && __input[2] = "p") {
				GameData::xp = (__input[1] * 10) + __input[2];
			}
		}
		*/
	}
}




void NoGo(){
	input = "";
	cout << "you cannot go there\n";
}