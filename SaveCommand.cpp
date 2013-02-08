////////////////////
/// C++ Advanced
/// Adventure Game
/// Antti-Jussi Juppo
/// anttijussi.juppo@edu.pkamk.fi
////////////////////
#include <fstream>
#include "SaveCommand.h"
#include "Game.h"
#include "Room.h"
//The following two are from Engine library
#include "GameObject.h"
#include "Enemy.h"
#include "Player.h"
//Codes above and below are borrowed from Villes code

void SaveCommand::Execute()
{
	/*ofstream savefile;
	savefile.open("gamestatus.txt");*/
	ofstream savefile("gamestatus.txt");
	if (savefile.is_open())
	{
	savefile << "#player " << GetGame()->GetPlayer().GetName() << "\r\n";
	savefile << GetGame()->GetPlayer().GetName() << "\r\n";
	savefile << GetGame()->GetPlayer().GetRace() << "\r\n";
	savefile << GetGame()->GetPlayer().GetClass() << "\r\n";
	savefile << GetGame()->GetPlayer().GetAge() << "\r\n";
	savefile << GetGame()->GetPlayer().GetGender() << "\r\n";
	savefile << GetGame()->GetPlayer().GetExperience() << "\r\n";
	savefile << GetGame()->GetCurrentRoom()->GetRoomID();
	}
	savefile.close();
	GetGame()->GetRenderer()->Render("Your game is saved. \n");
}