////////////////////
/// C++ Advanced
/// Adventure Game
/// Antti-Jussi Juppo
/// anttijussi.juppo@edu.pkamk.fi
////////////////////
#ifndef __SizeCounter_h__
#define __SizeCounter_h__
/////////////////////////////////////////////////////////////////
#include <cstdlib>
#include <stdexcept>
/////////////////////////////////////////////////////////////////
/// Template class for resource managers.
template<typename ETYPE, size_t SIZE>
class SizeCounter
{
private:

  /// Our array of elements
  ETYPE m_Array[SIZE];

public:

  /// Subscript operator
  ETYPE & operator[]( size_t index );

  /// Returns array size.
  size_t GetSize() const { return SIZE; }
};
/////////////////////////////////////////////////////////////////
#endif