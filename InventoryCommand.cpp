////////////////////
/// C++ Advanced
/// Adventure Game
/// Antti-Jussi Juppo
/// anttijussi.juppo@edu.pkamk.fi
////////////////////
#include "InventoryCommand.h"
#include "sstream"
//////////////////////////
void InventoryCommand::Execute()
{	
	std::ostringstream s;	
	s << "You have " << GetGame()->GetPlayer().gold.GetAmount() << " gold pieces!\n";    
	GetGame()->GetRenderer()->Render(s.str());
}
/////////////////////////////7