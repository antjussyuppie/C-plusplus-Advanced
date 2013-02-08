////////////////////
/// C++ Advanced
/// Adventure Game
/// Antti-Jussi Juppo
/// anttijussi.juppo@edu.pkamk.fi
////////////////////
#ifndef __Updateable_h__
#define __Updateable_h__
////////////////////////////////////////////////////////////////////////////////
struct Updateable 
{
  virtual ~Updateable(){}
  virtual void Update() = 0;
};
////////////////////////////////////////////////////////////////////////////////
#endif
