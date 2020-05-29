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
using namespace Civilization;




void Civilization::MessageRoom() {
	srand(time(NULL));
	//Defs.
	input = "";
	GameData::damage = ((rand() % 5) + GameData::DamMod);
	Room MessageRoom;

	//Description
	MessageRoom.SetRoomName("Message Room");
	MessageRoom.SetRoomDescript("you are in a dark room, even with your goggles. the only source of light is a book glowing atop a pedistal");
	PrintRoomDescript(MessageRoom);

	//Exits
	MessageRoom.SetNorthExits("a closed door");
	MessageRoom.SetEastExits("wall");
	MessageRoom.SetSouthExits("a closed door");
	MessageRoom.SetWestExits("beach");
	PrintExits(MessageRoom);

	
	MessageRoom.SetEastRoom(Cave2::StorageRoom);
	MessageRoom.SetWestRoom(CrusherRoom);
	if (GameData::peace == true) {
		MessageRoom.SetOtherFunc(Book);
		string M_OtherWord[] = { "inspect book", "inspect pedistal" };
		MessageRoom.SetOtherWord(M_OtherWord);
	}
	MessageRoom.SetOtherFunc2(WereRatFight);
	string M_OtherWord2[] = { "fight wererat", "fight wererat with dagger", "fight wererat with battleaxe" };
	MessageRoom.SetOtherWord2(M_OtherWord2);
	UseActions(MessageRoom);
}

void Civilization::Book() {
	cout << "you walk over to the pedistal and see a blank book with a quill and ink next to it. As you lookm at the book an invisible hand starts writing\n";
	cout << "who are you?\n\n";
	cout << "1: I am a traveler.\n2: I am an enemy.\n 3: I am a friend\n";
	while (__input != 1 && __input != 2 && __input != 3) {
		cin >> input;
		switch (__input)
		{
		case 1:
			cout << "why are you here\n";
			cout << "1. I stumbnled apo you island and hoped to get some resourses and explore\n";
			cout << "2. I am here to conquer you island\n";
			switch (__input) {
			case 1:
				cout << "you are not welcome on caelesti island. Leave\n";
				GameData::peace = true;
				MessageRoom();
			case 2:
				cout << "we will conquer you\n";
				GameData::peace = false;
				MessageRoom();
			}
		case 2:
			cout << "so be it\n";
			GameData::peace = false;
			MessageRoom();
		case 3:
			cout << "You are not welcome here. Leave\n";
			GameData::peace = true;
			MessageRoom();
		default:
			cout << "the people of Caelesti Island do not understand or do not want to tell you\n";
		}
	}
	
}



void Civilization::WereRatFight() {
	cout << "4 goblins rush out at you\none is broad, one is short, for a goblin, one is tall, for a goblin, and one is skinney\n";
	EnemyHealth Goblin[3];
	//the tall goblin
	Goblin[eTall].SetEnemyName("the tall goblin");
	Goblin[eTall].SetMaxHealth(7);
	//the short goblin
	Goblin[eSmall].SetEnemyName("the short goblin");
	//the broad goblin
	Goblin[eBroad].SetEnemyName("the broad goblin");
	//the skinney goblin
	Goblin[eSkinney].SetEnemyName("the skinney goblin");

	while (NPC::Goblin::GoblinHealth[eTall] > 0 || NPC::Goblin::GoblinHealth[eSmall] > 0 || NPC::Goblin::GoblinHealth[eBroad] > 0 || NPC::Goblin::GoblinHealth[eSkinney] > 0) {
		//if (input == "fight ")
	}
}