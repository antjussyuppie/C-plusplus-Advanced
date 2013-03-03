////////////////////
/// C++ Advanced
/// Adventure Game
/// Antti-Jussi Juppo
/// anttijussi.juppo@edu.pkamk.fi
////////////////////
#include "MoveCommand.h"
#include "Room.h"
#include "Game.h"
#include "IRenderer.h"
#include <cstdlib>
//Adding vector
//#include <vector>
////////////////////////////////////////////////////////////////////////////////
Room::Room()
{
  rooms[0] = NULL;
  rooms[1] = NULL;
  rooms[2] = NULL;
  rooms[3] = NULL;
}
////////////////////////////////////////////////////////////////////////////////
Room::~Room()
{
  
}
////////////////////////////////////////////////////////////////////////////////
void
Room::SetNextRoom( Direction d, Room * pRoom )
{
  rooms[d] = pRoom;
}
////////////////////////////////////////////////////////////////////////////////
Room * 
Room::GetNextRoom( Direction d )
{
  return rooms[d];
}
////////////////////////////////////////////////////////////////////////////////
void 
Room::SetDescription( const std::string & desc )
{
  description = desc;
}
////////////////////////////////////////////////////////////////////////////////
const std::string & 
Room::GetDescription() const
{
  return description;
}
////////////////////////////////////////////////////////////////////////////////
Room * 
Room::OnMoveCommand( MoveCommand *pCommand )
{
  return GetNextRoom( pCommand->GetDirection() );
}
////////////////////////////////////////////////////////////////////////////////
void
Room::OnAttack( AttackCommand *pCommand )
{
  // NO enemy , NO attack possibility
  GetGame()->GetRenderer()->Render("Attack what? There's nothing there!\n");
}
////////////////////////////////////////////////////////////////////////////////
void 
Room::SetGame( Game * pGame )
{
  game = pGame;
}
////////////////////////////////////////////////////////////////////////////////
Game * 
Room::GetGame() const
{
  return game;
}
////////////////////////////////////////////////////////////////////////////////
int Room::GetRoomID()
{
	return ID;
}
////////////////////////////////////////////////////////////////////////////////
void Room::SetRoomID(int iD)
{
	ID = iD;
}