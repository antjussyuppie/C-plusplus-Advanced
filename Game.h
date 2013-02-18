////////////////////
/// C++ Advanced
/// Adventure Game
/// Antti-Jussi Juppo
/// anttijussi.juppo@edu.pkamk.fi
////////////////////
#ifndef __Game_h__
#define __Game_h__
////////////////////////////////////////////////////////////////////////////////
class IRenderer;
class Room;
////////////////////////////////////////////////////////////////////////////////
enum RoomId { kDungeon, kHallway, kMonster, kChambers, kNumRooms };
#include "Player.h"
#include "Enemy.h"
//This code was taken from Taneli Peltolas group
#include "Gold.h"

#include <stdexcept>
////////////////////////////////////////////////////////////////////////////////
class Game 
{
private:
  bool running;
  Player player;
  IRenderer *renderer;
  Room      *rooms[kNumRooms]; ///< Map.
  Room      *currentRoom;
  //This code was taken from Taneli Peltolas group
  //Gold gold;
public:
  Game();
  virtual ~Game();
  void Play();
  void SetRenderer( IRenderer *pRenderer );
  IRenderer * GetRenderer() const;
  bool IsRunning() const;
  void SetRunning(bool bFlag ) ;
  Player & GetPlayer();
  Room * GetCurrentRoom();
  void SetCurrentRoom( Room *pRoom );
  //At least I knew how to do these and why it had to be done.
  //void SaveGame();
  //int LoadGame();

  //This code was taken from Taneli Peltolas group
  //Gold & GetGold();
};

//I needed some help with these
struct GameOverException : public std::runtime_error
{
	//I definitely did not knew this one beforehand.
	GameOverException(std::string error) : std::runtime_error(error.c_str()){}};

struct InvalidCommandException : public std::runtime_error
{InvalidCommandException() : std::runtime_error("Invalid input!\n") {}};
////////////////////////////////////////////////////////////////////////////////
#endif
