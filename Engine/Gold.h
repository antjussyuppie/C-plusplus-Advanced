////////////////////
/// C++ Advanced
/// Adventure Game
/// Antti-Jussi Juppo
/// anttijussi.juppo@edu.pkamk.fi
////////////////////
#ifndef __Gold_h__
#define __Gold_h__
////////////////////////////////////////////////////////////////////////////////
class GoldFactory;
//class Game;
////////////////////////////////////////////////////////////////////////////////
class Gold 
{
  friend class GoldFactory;
  //This addition is from Taneli Peltoniemi
  //friend class Game;
  //This addition is from Ville-Santeri Peltola
  friend class Player;
  friend class InventoryCommand;
private:
  //unsigned int m_nAmount;
  Gold(unsigned int value);
  //These are additions from Taneli Peltoniemi as well
  Gold();
  unsigned int a_value;
public:
  virtual ~Gold();
  unsigned int GetAmount() const;
  void SetAmount( unsigned int value );

  //More additions from Taneli Peltoniemi
  //unsigned int GetCountAmount() const;
  //void SetCountAmount(unsigned int count);
  //void ZeroCountAmount(unsigned int count);

  //Tanelis operators...
  /*Gold& operator+=(const int& amount)
  {
	a_value += amount;
	return *this;
  }

  Gold& operator+=(const Gold& gold)
  {
	a_value += gold.GetCountAmount();
	return *this;
  }*/

  Gold& operator+=(const Gold* gold)
  {
	a_value += gold->GetAmount();
	return *this;
  }
};
////////////////////////////////////////////////////////////////////////////////
#endif
