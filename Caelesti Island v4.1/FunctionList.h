#pragma once
#include <string>
using namespace std;

void NoGo();
void tAdmin();
void Actions();
void xp();
void Inventory();
//Room Delclarations

namespace Cave1 {

	extern void CaveEntrance();
	extern void SupplyRoom();
	extern void WellRoom();
	extern void RatFight();
	extern void CrateRoom();
	extern void InsideWell();
}

namespace Jungle {
	extern void WestJungle();
	extern void EastJungle();
	extern void CaveClearing();
}

namespace Cave2 {
	extern void StorageRoom();
	extern void GnollRoom();
	extern void GnollFight();
}


namespace Cliff {
	extern void Bluff();
	extern void MainStreet();
}


namespace Beach {
extern void NorthBeach();
extern void EastBeach();
extern void WestBeach();
extern void UpPalmTree();
extern void SouthBeach();
extern void NorthWestBeach();
extern void NorthEastBeach();
}

namespace Civilization {
	extern void CrusherRoom();
	extern void MessageRoom();
	extern void Book();
	extern void WereRatFight();
}


