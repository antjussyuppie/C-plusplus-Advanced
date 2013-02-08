////////////////////
/// C++ Advanced
/// Adventure Game
/// Antti-Jussi Juppo
/// anttijussi.juppo@edu.pkamk.fi
////////////////////
#ifndef __SaveCommand_h__
#define __SaveCommand_h__
//This code is based on Ville Peltolas code after my miserable attempt to do this myself.
#include "Command.h"
#include "Dungeon.h"
#include <sstream>
class Game;
////////////////////////////////////////////////////////////////////////////////
class SaveCommand : public Command
{
	public: SaveCommand(Game *pGame) : Command(pGame){}
	void Execute();
};
#endif