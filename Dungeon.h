////////////////////
/// C++ Advanced
/// Adventure Game
/// Antti-Jussi Juppo
/// anttijussi.juppo@edu.pkamk.fi
////////////////////
#ifndef __Dungeon_h__
#define __Dungeon_h__
#include "Room.h"
#include "Enemy.h"
#include "Player.h"
#include "IRenderer.h"
#include "Game.h"
#include <sstream>
////////////////////////////////////////////////////////////////////////////////

class Dungeon : public Room
{
private:

public:
  Dungeon()
  {
    SetDescription("You are locked up in a dungeon.");
	//New addition under guidance of Ville
	SetRoomID(3);
  }
  void Update()
  {
    
  }
};
////////////////////////////////////////////////////////////////////////////////
#endif
