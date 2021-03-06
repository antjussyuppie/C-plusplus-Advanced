////////////////////
/// C++ Advanced
/// Adventure Game
/// Antti-Jussi Juppo
/// anttijussi.juppo@edu.pkamk.fi
////////////////////
#ifndef __MonsterRoom_h__
#define __MonsterRoom_h__
#include "Room.h"
#include "Enemy.h"
#include <sstream>
#include "MoveCommand.h"
//Module 5 mods
//#include <vector>
//#include "Scene.h"
////////////////////////////////////////////////////////////////////////////////
class MonsterRoom : public Room
{
private:
  Enemy e;
  bool noticedPlayer;
  //Module 5 modifications
  //bool noticedPlayer;  
  //int ID;
public:
  MonsterRoom()
  {
	  //Module 5 modifications
    noticedPlayer = false;
    e.SetName( "Orc");
    SetDescription("You are in the monster room. There is an orc here!");//...to have this one
	//New addition under Ville's guidance 
	SetRoomID(1);//...and this one on.
  }
  ////////////////////
  /// Makes enemy attack player once on every turn.
  void Update()
  {
	  //Module 5 modifications
    if ( e.IsAlive() && noticedPlayer )
    {
      std::ostringstream s;
      Player & player = GetGame()->GetPlayer();
      s << e.GetName() << " attacks " << player.GetName() << "\n";
      GetGame()->GetRenderer()->Render(s.str());

      e.Attack(&player);
	  //Needed some help with this one as well.
	  if(player.GetHitpoints() <= 0)
	  {throw GameOverException("You died!\n");}
    }
    noticedPlayer = true;
  }
  ////////////////////
  /// Restricts movement until enemy is killed.
  /// \param pCommand Move command.
  /// \return Room pointer to next available room, NULL if none available.

  //EVEN MORE MODULE 5 MODIFICATIONS
  
  Room * OnMoveCommand( MoveCommand *pCommand )
  {
    if ( e.IsAlive())
    {
      return NULL;
    }
    else
      return GetNextRoom( pCommand->GetDirection() );
  }
  
  void OnAttack( AttackCommand *pCommand )
  {
    if ( e.IsAlive() && noticedPlayer)
    {
      Player & player = GetGame()->GetPlayer();
      std::ostringstream s;
      s << player.GetName() << " attacks " << e.GetName() << "\n";
      GetGame()->GetRenderer()->Render(s.str());
      player.Attack( &e );
      // Change room description a bit
      if ( e.IsAlive() == false )
      {
	SetDescription("You are in the monster room. There is a pretty dead orc here.");
      }
    } 
    else 
    {
      // to encourage player to stop beating it further
      GetGame()->GetRenderer()->Render("Whoa! You already got your pound of flesh out of that one. Literally.\n");
    }

  }

};
////////////////////////////////////////////////////////////////////////////////
#endif



