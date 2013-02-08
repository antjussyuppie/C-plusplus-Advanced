////////////////////
/// C++ Advanced
/// Adventure Game
/// Antti-Jussi Juppo
/// anttijussi.juppo@edu.pkamk.fi
////////////////////
#ifndef __QuitCommand_h__
#define __QuitCommand_h__
#include "Command.h"
#include "Game.h"
////////////////////////////////////////////////////////////////////////////////
class QuitCommand : public Command 
{
public:
  QuitCommand( Game *pGame ) : Command(pGame){}
  void Execute()
  {
    GetGame()->SetRunning(false);
  }
};
////////////////////////////////////////////////////////////////////////////////
#endif
