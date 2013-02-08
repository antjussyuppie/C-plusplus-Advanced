////////////////////
/// C++ Advanced
/// Adventure Game
/// Antti-Jussi Juppo
/// anttijussi.juppo@edu.pkamk.fi
////////////////////
#include "CommandFactory.h"
#include "QuitCommand.h"
#include "SearchCommand.h"
#include "AttackCommand.h"
#include "UnknownCommand.h"
#include "MoveCommand.h"
//A new try
#include "SaveCommand.h"
#include "Game.h"
#include <sstream>
#include <string>
#include <iostream>
////////////////////////////////////////////////////////////////////////////////
using namespace std;
////////////////////////////////////////////////////////////////////////////////
ICommand * 
CommandFactory::Create( const std::string & str )
{
  std::istringstream s(str);
  std::string word;
  s >> word;

  if ( word == "quit" )
  {
    return new QuitCommand(m_pGame);
  }
  
  if ( word == "search")
  {
    return new SearchCommand(m_pGame);
  }
  
  if ( word == "attack" )
  {
    return new AttackCommand(m_pGame);
  }

  if ( word == "move" )
  {
    string dir;
    s >> dir;
    //cout << "got dir '" << dir << "'\n";
    MoveCommand *command = NULL;
    if ( dir == "north" )
    {
      command = new MoveCommand(m_pGame);
      command->SetDirection(North);
      return command;
    }
    else if ( dir == "south" )
    {
      command = new MoveCommand(m_pGame);
      command->SetDirection(South);
      return command;
    }
    else if ( dir == "east" )
    {
      command = new MoveCommand(m_pGame);
      command->SetDirection(East);
      return command;
    }
    else if ( dir == "west" )
    {
      command = new MoveCommand(m_pGame);
      command->SetDirection(West);
      return command;
    }
  }
  
  //Saving command starts here...
  
  if ( word == "save" )
  {
	return new SaveCommand(m_pGame);
  }
  
  throw InvalidCommandException();
  //return new UnknownCommand(m_pGame);  
}
////////////////////////////////////////////////////////////////////////////////
