////////////////////
/// C++ Advanced
/// Adventure Game
/// Antti-Jussi Juppo
/// anttijussi.juppo@edu.pkamk.fi
////////////////////
#ifndef __Hallway_h__
#define __Hallway_h__
#include "Room.h"
#include <sstream>
////////////////////////////////////////////////////////////////////////////////
class Hallway : public Room
{
public:
  Hallway()
  {
    SetDescription("You are standing in a pretty damp hallway.");
	//New addition under guidance of Ville
	SetRoomID(2);
  }
  
  void Update()
  {
    
  }
};
////////////////////////////////////////////////////////////////////////////////
#endif
