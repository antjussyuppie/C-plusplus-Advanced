////////////////////
/// C++ Advanced
/// Adventure Game
/// Antti-Jussi Juppo
/// anttijussi.juppo@edu.pkamk.fi
////////////////////
#ifndef __CommandFactory_h__
#define __CommandFactory_h__
#include <string>
class Game;
class ICommand;
////////////////////////////////////////////////////////////////////////////////
class CommandFactory 
{
private:
  Game * m_pGame;
public:
  CommandFactory( Game *pGame ) : m_pGame(pGame) {}
  virtual ~CommandFactory() {}
  
  ICommand * Create( const std::string & str );
};
////////////////////////////////////////////////////////////////////////////////

#endif
