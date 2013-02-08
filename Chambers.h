////////////////////
/// C++ Advanced
/// Adventure Game
/// Antti-Jussi Juppo
/// anttijussi.juppo@edu.pkamk.fi
////////////////////
#ifndef __Chambers_h__
#define __Chambers_h__
#include "Room.h"
#include "Enemy.h"
#include <sstream>
////////////////////////////////////////////////////////////////////////////////
class Chambers : public Room
{
private:
  bool waitForIt;
public:
  Chambers()
  {
    SetDescription("You are in princess' chambers.");
    waitForIt = true;
	//New addition under guidance of Ville
	SetRoomID(4);
  }
  void Update()
  {
    if ( waitForIt )
    {
      waitForIt = false;
    }
    else 
    {
      GetGame()->GetRenderer()->Render("Princess kisses you. You turn into a frog\n");
      GetGame()->GetRenderer()->Render("Congratulations, you've completed the game!");
      GetGame()->SetRunning(false);
    }
  }
};
////////////////////////////////////////////////////////////////////////////////
#endif
