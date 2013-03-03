////////////////////
/// C++ Advanced
/// Adventure Game
/// Antti-Jussi Juppo
/// anttijussi.juppo@edu.pkamk.fi
////////////////////
#ifndef __Enemy_h__
#define __Enemy_h__
#include "GameObject.h"
#include <iostream>
#include <cstdlib>
const int ENEMY_DEFAULT_HITPOINTS = 3;

//New additions for Module 5 according to Ville-Santeri Peltola
//#include "Game.h"
//#include "Room.h"
//#include "Player.h"
//#include "globals.h"
//#include <vector>
//#include "IRenderer.h"

using namespace std;

class Enemy : public GameObject
{
public:

  Enemy() 
  {
    SetHitpoints(ENEMY_DEFAULT_HITPOINTS) ;
  }
  
  bool IsAlive() const { return GetHitpoints() > 0; }

  void Attack( GameObject *pObject )
  {
    int hp = pObject->GetHitpoints();
    if ( (rand() % 10) < 3 )
    {
      // TODO: convert this into weapon 
      // with damage property. Can you do it? Is so, explain in your learning diary how.
      pObject->SetHitpoints(hp-1); 
      cout << GetName() << " hits!\n";
    }
    else
      cout << GetName() << " misses!\n";
  }

  //Module 5 modifications
  /*friend class AttackCommand;
  friend class Game;
protected:  
  
  bool CanAct;  
  bool Inactive;  
  Game *m_pGame;  
  Room * mRoom;  
  bool Aggro;  
  bool CanMove;  

  public:  
	Enemy();  ~Enemy();  
	bool IsAlive();    
	void Attack( GameObject *pObject ); 
	void Update();
	void CheckRoom();
	Room* GetRoom();
	void SetRoom(Room* MRoom);
	void Move(Direction direction);
	void SetGame( Game * pGame );
	Game * GetGame();*/
};

#endif
