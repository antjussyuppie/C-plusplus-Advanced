////////////////////
/// C++ Advanced
/// Adventure Game
/// Antti-Jussi Juppo
/// anttijussi.juppo@edu.pkamk.fi
////////////////////
#ifndef __SaveCommand_h__
#define __SaveCommand_h__
////////////////////////////////////////////////////////////////////////////////
/*#include "Command.h"
class Game;
#include "Dungeon.h"
#include <sstream>*/
#include "Command.h"
#include "Gold.h"
#include "Game.h"
#include "TextRenderer.h"
class Game;
////////////////////////////////////////////////////////////////////////////////
class InventoryCommand  : public Command
{
public:  InventoryCommand( Game *pGame ) : Command(pGame) { }  
		 void Execute();
};
//////////////////////////////////////////////////////////////////////////////// 
#endif