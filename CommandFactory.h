////////////////////
/// C++ Advanced
/// Adventure Game
/// Antti-Jussi Juppo
/// anttijussi.juppo@edu.pkamk.fi
////////////////////
#ifndef __CommandFactory_h__
#define __CommandFactory_h__
#include <string>
//New map
//#include <map>
class Game;
class ICommand;
////////////////////////////////////////////////////////////////////////////////
class CommandFactory 
{
private:
  Game * m_pGame;
  //Something new.
  //Here we start a new Map container called newMap, which is created out of ICommand struct.
  //std::Map<std::string,ICommand*> newMap;
public:
  CommandFactory( Game *pGame ) : m_pGame(pGame) {}
  virtual ~CommandFactory() {}
  
  ICommand * Create( const std::string & str );
};
////////////////////////////////////////////////////////////////////////////////

#endif
