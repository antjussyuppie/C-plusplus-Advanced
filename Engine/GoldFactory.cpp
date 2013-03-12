////////////////////
/// C++ Advanced
/// Adventure Game
/// Antti-Jussi Juppo
/// anttijussi.juppo@edu.pkamk.fi
////////////////////
#include "GoldFactory.h"
#include "Gold.h"
#include <cstdlib>
//For Module 6
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
////////////////////////////////////////////////////////////////////////////////
Gold *
GoldFactory::Create( size_t amount )
{
  Gold *pG = new Gold(amount);
  //Module 6 addon
  //*pG = (*pGoldTotal + *pGoldFound);
  return pG;
}
////////////////////////////////////////////////////////////////////////////////
