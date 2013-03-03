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
#include "Gold.h"
class Game;
////////////////////////////////////////////////////////////////////////////////
class Player : public GameObject
{
	//Affected by Ville-Santeri Peltola
	friend class InventoryCommand;
	friend class SearchCommand;
	friend class SaveCommand;
private:
  Game *game;
  int WhereID;
  //Inspired by Ville-Santeri
  //Something's strange here...
  //...not anymore
  Gold gold;
  //I have no idea if this is needed or not
  string roomdesc;

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

  //Module 5 modifications
  //void SetDesc(string s);  
  //string GetDesc();
};
////////////////////////////////////////////////////////////////////////////////
#endif
