////////////////////
/// C++ Advanced
/// Adventure Game
/// Antti-Jussi Juppo
/// anttijussi.juppo@edu.pkamk.fi
////////////////////
#ifndef __Player_h__
#define __Player_h__
#include <string>
#include "GameObject.h"
class Game;
////////////////////////////////////////////////////////////////////////////////
class Player : public GameObject
{
private:
  Game *game;
  int WhereID;

public:
  Player();

  virtual ~Player();
  void SetGame( Game * game );
  void Attack( GameObject *pObject);

  void PrintSummary();
  static void AskInfo( Player & p );
  //More borrowing from Ville
  static void LoadGame(Player &p);
  int GetWhereID();
  void SetWhereID(int id);
};
////////////////////////////////////////////////////////////////////////////////
#endif
