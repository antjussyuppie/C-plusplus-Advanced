////////////////////
/// C++ Advanced
/// Adventure Game
/// Antti-Jussi Juppo
/// anttijussi.juppo@edu.pkamk.fi
////////////////////
//This is a new file for Module 5 according to Ville-Santeri
/*#include "Scene.h"
#include <algorithm>

Scene::Scene(){}

Scene::~Scene(){}

struct UpdateOp
{	
	inline void operator()(Updateable * Obj)	
	{		
		Obj->Update();	
	}
};

void Scene::Update()
{	
	EnemyList & lst = GetUpdateables();	
	
	for_each(lst.begin(), lst.end(), UpdateOp());
}

void Scene::SetGame(Game*pGame)
{	
	game = pGame;
}

Game*Scene::GetGame() const
{	
	return game;
}*/