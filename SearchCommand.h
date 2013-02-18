////////////////////
/// C++ Advanced
/// Adventure Game
/// Antti-Jussi Juppo
/// anttijussi.juppo@edu.pkamk.fi
////////////////////
#ifndef __SearchCommand_h__
#define __SearchCommand_h__
#include <cstdlib>
#include "GoldFactory.h"
#include "Gold.h"
#include "Game.h"
#include <sstream>
#include "IRenderer.h"
////////////////////////////////////////////////////////////////////////////////
class SearchCommand : public Command
{
	//Inpired by Ville-Santeri Peltola
	friend class CommandFactory;
public:
  SearchCommand( Game *pGame ) : Command(pGame) {}
  void Execute()
  {
    if ( rand()%1000 < 436 )
    {
      GoldFactory f;
	  //inspired by Ville-Santeri
	  //int ngold;
      Gold *g = f.Create( 1+rand()%100 );
      std::ostringstream s;
      s << "You found " << g->GetAmount() << " gold!\n";

	  //Here are additions from Taneli Peltolas example.
	  //GetGame()->GetGold() += g;
	  //s << "You now have " << GetGame()->GetGold().GetCountAmount() << " pieces of gold!\n";

      GetGame()->GetRenderer()->Render(s.str());
	  //GetGame()->GetPlayer().gold+=g;
      delete g;
    }
    else {
      GetGame()->GetRenderer()->Render( "You found nothing.\n");
    }
  }
};
////////////////////////////////////////////////////////////////////////////////
#endif
