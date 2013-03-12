////////////////////
/// C++ Advanced
/// Adventure Game
/// Antti-Jussi Juppo
/// anttijussi.juppo@edu.pkamk.fi
////////////////////
//This is a new file for Module 5 according to Ville-Santeri
/*
#ifndef __Scene_h__
#define __Scene_h__

#include "Updateable.h"
#include <list>
#include "Enemy.h"

using namespace std;
typedef list<Enemy*> EnemyList;

class Scene : public Updateable
{
	private:	
		EnemyList e_vec;	
		Game* game;
	public:	
		Scene();	
		~Scene();	

		EnemyList & GetUpdateables()
		{ 
			return e_vec; 
		}	
		
		virtual void Update();	
		void SetGame(Game*pGame);	
		Game*GetGame ()const;
};
#endif*/