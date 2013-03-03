////////////////////
/// C++ Advanced
/// Adventure Game
/// Antti-Jussi Juppo
/// anttijussi.juppo@edu.pkamk.fi
////////////////////
#ifndef __IRenderer_h__
#define __IRenderer_h__
////////////////////////////////////////////////////////////////////////////////
class IRenderer 
{
public:
  virtual void Render( const std::string & str ) = 0;
};
////////////////////////////////////////////////////////////////////////////////
//This is from Tanelis group again
template<typename G>
IRenderer &operator << (IRenderer &r, const G& str)
{
	std::cout << str;
	return r;
}
#endif
