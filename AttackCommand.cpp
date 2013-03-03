////////////////////
/// C++ Advanced
/// Adventure Game
/// Antti-Jussi Juppo
/// anttijussi.juppo@edu.pkamk.fi
////////////////////
#include "AttackCommand.h"
#include "Game.h"
#include "Room.h"
////////////////////////////////////////////////////////////////////////////////
void AttackCommand::Execute()
{
  GetGame()->GetCurrentRoom()->OnAttack(this);
}
////////////////////////////////////////////////////////////////////////////////
//Changes for Module 5 according to Ville-Santeri Peltola
/*void AttackCommand::Execute()
{
	for(auto enemy: GetGame()->GetEnemies())
	{  
		if (enemy->IsAlive() && enemy->Aggro==true)    
		{      
			Player & player = GetGame()->GetPlayer();      
			std::ostringstream s;      
			s << player.GetName() << " attacks " << enemy->GetName() << "\n";      
			GetGame()->GetRenderer()->Render(s.str());      
			player.Attack( enemy );        
		} 
	}
}*/