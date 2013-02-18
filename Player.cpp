////////////////////
/// C++ Advanced
/// Adventure Game
/// Antti-Jussi Juppo
/// anttijussi.juppo@edu.pkamk.fi
////////////////////
#include "Player.h"
#include "Game.h"
#include "IRenderer.h"
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <fstream>
using namespace std;
////////////////////////////////////////////////////////////////////////////////
Player::Player()
{
  SetHitpoints(3);
}
////////////////////////////////////////////////////////////////////////////////
Player::~Player()
{
  
}
////////////////////////////////////////////////////////////////////////////////
void
Player::Attack( GameObject *pObject )
{
  int hp = pObject->GetHitpoints();
  if ( (rand() % 100) < 63 )
  {
    // convert this into weapon 
    // with damage property
    pObject->SetHitpoints(hp-1); 
    ostringstream s;
    s << GetName() << " hits!\n";
    game->GetRenderer()->Render( s.str() );
  }
  else
  {
    ostringstream s;
    s << GetName() << " misses!\n";
    game->GetRenderer()->Render( s.str() );
  }
}
////////////////////////////////////////////////////////////////////////////////
void 
Player::PrintSummary()
{

  cout << "Name:" << GetName() << "\n";
  cout << "Race: " <<  GetRace() << "\n";
  cout << "Class: " << GetClass() << "\n";
  cout << "age: " << GetAge() << "\n";
  cout << "gender: " << GetGender() << "\n";
  cout << "experience: " << GetExperience() << "\n";
}
////////////////////////////////////////////////////////////////////////////////
void
Player::AskInfo( Player & p)
{
  ifstream f("playerdata.txt");
  while ( !f.eof()  )
  {
    string line;
    f >> line;
    if ( line == "#player")
    {
      int iTmp;
      string strTmp;
      char g;
      f >> strTmp; p.SetName(strTmp); 
      f >> strTmp; p.SetRace(strTmp);
      f >> iTmp; p.SetClass((Class)iTmp);
      f >> iTmp; p.SetAge(iTmp);
      f >> g; p.SetGender( (g == 'm' ? Male : Female) );
      f >> iTmp; p.SetExperience(iTmp);
    }
    /*
  cout << "\nPlease enter your details:\n\n";
  cout << "Your name:"; cin >> p.name;
  cout << "Race: "; cin >> p.race;
  int c;
  cout << "Class: ";cin >> c; p.myClass = (Class)c;
  cout << "age: "; cin >> p.age;
  char g;
  cout << "gender: "; cin >> g; p.gender = g == 'm' ? Male : Female;
  p.experience = 0;*/
  }
  //I found this from Villes example
  f.close();
}

//Description for GetWhereID and SetWhereID functions. Made these, thanks to Ville 
int Player::GetWhereID()
{
	return WhereID;
}
void Player::SetWhereID(int id)
{
	WhereID = id;
}

//The way Ville suggested we do this part.
void Player::LoadGame(Player &p)
{
	ifstream f("gamestatus.txt");
  while ( !f.eof()  )
  {
    string line;
    f >> line;
    if ( line == "#player")
    {
      int iTmp;
      string strTmp;
      char g;
      f >> strTmp; p.SetName(strTmp); 
      f >> strTmp; p.SetRace(strTmp);
      f >> iTmp; p.SetClass((Class)iTmp);
      f >> iTmp; p.SetAge(iTmp);
      f >> g; p.SetGender( (g == 'm' ? Male : Female) );
      f >> iTmp; p.SetExperience(iTmp);
      f >> iTmp; p.SetWhereID(iTmp);
//	  f >> iTmp; p.gold.SetAmount(iTmp);
    }
  }
  f.close();
}
////////////////////////////////////////////////////////////////////////////////
void 
Player::SetGame( Game * game )
{ 
  this->game = game;
}
////////////////////////////////////////////////////////////////////////////////
