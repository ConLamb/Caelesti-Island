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


//GameData
int GameData::health = 15;
int GameData::maxhealth = 15;
int GameData::armor = 0;
int GameData::damage;
int GameData::xp = 0;
int __input;
bool GameData::peace = true;
int GameData::DaggerDamage;
string input;
int GameData::souphealth = 5;
bool::GameData::safelock = true;
int GameData::perception = 3;
int GameData::check;
int GameData::DamMod = 1;
bool GameData::coconut = false;
bool GameData::time = false;
int GameData::level = 1;
int GameData::dumb = 0;
bool GameData::message = false;
//Invnetory
string Inventory::_mainstreetinventory = "keys";
string Inventory::_CrateInventory[3] = { "soup", "goggles" };
string Inventory::_Coconutinventory = "dagger";
string Inventory::_inventory[50] = { "compass" };
string Inventory::_NorthBechInventory = "earmuffs";
string Inventory::_GnollRoomInventory[2] = { "helmet", "battleaxe" };
//NPCs
int NPC::Gnoll::GnollHealth = 50;
int NPC::Gnoll::GnollDamage;
int NPC::Rat::RatDamage;
int NPC::Rat::RatHealth;
int NPC::Goblin::GoblinHealth[4] = { 7, 7, 7, 7 };



