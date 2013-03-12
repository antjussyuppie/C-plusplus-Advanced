////////////////////
/// C++ Advanced
/// Adventure Game
/// Antti-Jussi Juppo
/// anttijussi.juppo@edu.pkamk.fi
////////////////////
#include "Game.h"
#include "Player.h"
#include "GoldFactory.h"
#include "Gold.h"
#include "QuitCommand.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "TextRenderer.h"
#include <sstream>
#include "IRenderer.h"
#include "CommandFactory.h"
#include "Dungeon.h"
#include "Hallway.h"
#include "MonsterRoom.h"
#include "Chambers.h"
#include "globals.h"

//Module 5 modifications
//#include "Enemy.h"
//#include <ctime>
//#include <string>

//Module 6 modifications
//#include <list>
#include <algorithm>
////////////////////////////////////////////////////////////////////////////////
using namespace std;
#define DEV_NAME "anttijussi.juppo@karelia-amk"
#define YEAR 2013

////////////////////////////////////////////////////////////////////////////////
Game::Game() : running(true)
{
	//Module 6 modification
//	currentGold = 0;

  renderer = new TextRenderer();

  rooms[kDungeon] = new Dungeon();
  rooms[kDungeon]->SetGame(this);

  rooms[kHallway] = new Hallway();
  rooms[kHallway]->SetGame(this);

  rooms[kMonster] = new MonsterRoom();
  rooms[kMonster]->SetGame(this);
  
  rooms[kChambers] = new Chambers();
  rooms[kChambers]->SetGame(this);

  rooms[kDungeon]->SetNextRoom(North,rooms[kHallway]);

  rooms[kHallway]->SetNextRoom(South,rooms[kDungeon]);
  rooms[kHallway]->SetNextRoom(North,rooms[kMonster]);

  rooms[kMonster]->SetNextRoom(South,rooms[kHallway]);
  rooms[kMonster]->SetNextRoom(North,rooms[kChambers]);

  rooms[kChambers]->SetNextRoom(South,rooms[kMonster]);
  
  currentRoom = rooms[kDungeon];

  //This code was taken from Taneli Peltolas group
  //gold.ZeroCountAmount(0);

  //Module 5 mods
  /*eGuard = new Enemy();  
  eGuard->SetGame(this);  
  eGuard->SetName("Orc Warlord");  
  eGuard->CanMove=false;  
  eGuard->SetRoom(rooms[kMonster]);  
  s->GetUpdateables().push_back(eGuard);  
  e.push_back(eGuard);  
  ePatrol = new Enemy();  
  ePatrol->SetGame(this);  
  ePatrol->SetName("Bloody Rogue");  
  ePatrol->SetRoom(rooms[kMonster]);  
  s->GetUpdateables().push_back(ePatrol);  
  e.push_back(ePatrol);*/
}
////////////////////////////////////////////////////////////////////////////////
Game::~Game()
{

}
////////////////////////////////////////////////////////////////////////////////
void Game::Play()
{
  string cmd;
  renderer->Render("Welcome to Fiends'n'Frogs adventure game!\n");
  ostringstream s;
  s << "by " << DEV_NAME << "(c) " << YEAR << ". Licensed under GPLv3.\n";
  renderer->Render(s.str());

  renderer->Render("Test typing 'load'. ");
  getline(cin,cmd);
  if(cmd == "load")
  {
	  renderer->Render("LOADING... ");
	  Player::LoadGame(player);
  }
  //If we can load game from different than default file...
  /*
  if(LoadGame())
  {
	  renderer->Render("The game was loaded succesfully. ");
  }
  //else...
  else
  {
	Player::AskInfo(player);
	renderer->Render("\nPlayer statistics:\n\n");
	player.PrintSummary();
  }*/
  else
  {
	  Player::AskInfo(player);
  }
  //Player::AskInfo(player);
	renderer->Render("\nPlayer statistics:\n\n");
	player.PrintSummary();
	player.SetGame(this);

	if(cmd == "load")
	{
		renderer->Render("\nGame continues.\n\n");
		if(player.GetWhereID()==4)
		{
			SetCurrentRoom(rooms[kChambers]);
		}
		else if(player.GetWhereID()==3)
		{
			SetCurrentRoom(rooms[kDungeon]);
		}
		else if(player.GetWhereID()==2)
		{
			SetCurrentRoom(rooms[kHallway]);
		}
		else if(player.GetWhereID()==1)
		{
			SetCurrentRoom(rooms[kMonster]);
		}
	}
	else
	{
		renderer->Render("\nAnd behold, the adventure begins!\n");
	}
	//Error alapuolella
	/*
	if(cmd == "load")
	{
		if(player.GetWhereID()==4)
		{
			SetCurrentRoom(rooms[kChambers]);
		}
		else if(player.GetWhereID()==3)
		{
			SetCurrentRoom(rooms[kDungeon]);
		}
		else if(player.GetWhereID()==2)
		{
			SetCurrentRoom(rooms[kHallway]);
		}
		else if(player.GetWhereID()==1)
		{
			SetCurrentRoom(rooms[kMonster]);
		}
	}*/

	//srand(time(NULL));
  //This gave an error!

  while(running)
  {
    renderer->Render(GetCurrentRoom()->GetDescription());
    renderer->Render("\n> ");

    getline(cin,cmd);
	
	try
	{
		CommandFactory comm(this);
		ICommand *pCommand = comm.Create( cmd ); 
		if ( pCommand ) pCommand->Execute();
		delete pCommand;

		GetCurrentRoom()->Update();
	}

	//This is how it is done in the lecture recording.
	//If game is over, (player dies) happens following exception...
	catch(GameOverException & gameover)
	{
		running = false;
		renderer->Render(gameover.what());
		//renderer->Render(gameover.what()->"An exception was found."); <- This does not do any good.
	}

	//And if player inputs invalid command, following happens...
	catch(InvalidCommandException & invalidcommand)
	{
		renderer->Render(invalidcommand.what());
	}
	
	/*
    CommandFactory comm(this);
    ICommand *pCommand = comm.Create( cmd ); 
    if ( pCommand ) pCommand->Execute();
    delete pCommand;

    GetCurrentRoom()->Update();
      
    if ( player.GetHitpoints() <= 0 ) {
      
      renderer->Render("You're dead. Game over.\n");
      running = false;
    }*/
  }
  // final message to player
  renderer->Render("Exiting, bye!\n");
}
////////////////////////////////////////////////////////////////////////////////
void
Game::SetRenderer( IRenderer *pRenderer )
{
  renderer = pRenderer;
}
////////////////////////////////////////////////////////////////////////////////
IRenderer * 
Game::GetRenderer() const
{
  return renderer;
}
////////////////////////////////////////////////////////////////////////////////
bool
Game::IsRunning() const
{
  return running;
}
////////////////////////////////////////////////////////////////////////////////
void
Game::SetRunning( bool bFlag ) 
{
  running = bFlag;
}
////////////////////////////////////////////////////////////////////////////////
Player & 
Game::GetPlayer()
{
  return player;
}
////////////////////////////////////////////////////////////////////////////////

Room *
Game::GetCurrentRoom()
{
  return currentRoom;
}
////////////////////////////////////////////////////////////////////////////////
void 
Game::SetCurrentRoom( Room *pRoom )
{
  currentRoom = pRoom;
}
////////////////////////////////////////////////////////////////////////////////
void Game::SetCurrentGold(int gold)
{	
	goldTotal.push_back(gold);
}
////////////////////////////////////////////////////////////////////////////////
int Game::GetCurrentGold()
{
	int total = 0;	
	vectorSum sum(&total);	
	for_each(goldTotal.begin(), goldTotal.end(), sum);
	return total;
}
//Module 5 mods
/*IRenderer & Game::GetR() const
{	
	return r;
}
////////
void Game::Update()
{	
	s->Update();
}
////////
Enemy *Game::GetEnemy()
{	
	return eGuard;
}*/

//This code was taken from Taneli Peltolas group
/*
Gold & Game::GetGold()
{  
	return gold;
}*/

//I made these out of some examples
/*
void Game::SaveGame()
{
	ofstream savefile("gamestatus.txt");
	if (savefile.is_open())
	{
		savefile << player.GetName() << "\r\n";
		savefile << player.GetRace() << "\r\n";
		savefile << player.GetClass() << "\r\n";
		savefile << player.GetAge() << "\r\n";
		savefile << player.GetGender() << "\r\n";
		savefile << player.GetExperience() << "\r\n";
		savefile << player.GetHitpoints() << "\r\n";
		//I didn't know what exactly I should add to repesentative files.
		savefile << currentRoom->GetRoomID() << "\r\n";

		MonsterRoom *room = dynamic_cast<MonsterRoom*>(rooms[kMonster]);
		if(room != NULL)
		{
			savefile << room->GetEnemy().GetHitpoints() << "\r\n";
		}
		savefile.close();
	}
	else cout << "Unable to open file";
}*/
/*
int Game::LoadGame()
{
	ifstream savefile("gamestatus.txt");
	if (savefile.is_open())
	{
		int iTmp;
		int gTmp;
		string sTmp;

		savefile >> sTmp; player.SetName(sTmp);
		savefile >> sTmp; player.SetRace(sTmp);
		savefile >> iTmp; player.SetClass((Class)iTmp);
		savefile >> iTmp; player.SetAge(iTmp);
		savefile >> gTmp; player.SetGender((gTmp == 'm' ? Male : Female));
		savefile >> iTmp; player.SetExperience(iTmp);
		savefile >> iTmp; player.SetHitpoints(iTmp);
		
		savefile >> iTmp; currentRoom = rooms[iTmp];

		MonsterRoom *room = dynamic_cast<MonsterRoom*>(rooms[kMonster]);
		if(room != NULL)
		{
			savefile >> iTmp;
			room->GetEnemy().SetHitpoints(iTmp);
			if(!room->GetEnemy.IsAlive())
			{
				room->SetDescription("You are in the monster room. There is a pretty dead orc here.");
			}
		}
		savefile.close();
		//Why is this going like this?
		return 1;
	}
	return 0;
}*/