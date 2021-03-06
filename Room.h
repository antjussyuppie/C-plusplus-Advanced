////////////////////
/// C++ Advanced
/// Adventure Game
/// Antti-Jussi Juppo
/// anttijussi.juppo@edu.pkamk.fi
////////////////////
#ifndef __Room_h__
#define __Room_h__
////////////////////////////////////////////////////////////////////////////////
#include <string>
#include "Updateable.h"
#include "globals.h"
//Adding a vector
//#include <vector>
////////////////////////////////////////////////////////////////////////////////
class MoveCommand;
class AttackCommand;
class Game;
////////////////////////////////////////////////////////////////////////////////
class Room : public Updateable 
{
private:
  Room *        rooms[kNumDirs];
  std::string   description;
  Game *        game;
  //Something new
  int ID;
  //Adding a vector
  //vector<Room *> rooms;
public:

  Room();
  virtual ~Room();
  void SetGame( Game * pGame );
  Game * GetGame() const;
  void SetDescription( const std::string & desc );
  const std::string & GetDescription() const;
  void   SetNextRoom( Direction d, Room * pRoom );
  Room * GetNextRoom( Direction d );

  virtual Room * OnMoveCommand( MoveCommand *pCommand );
  virtual void   OnAttack( AttackCommand *pCommand );
  //again something new...
  int GetRoomID();
  void SetRoomID(int iD);
};
////////////////////////////////////////////////////////////////////////////////
#endif
