
/***********************************************************************
 // Name: Tuz Han Chao
 // id: 151593225
 // email: tchao3@mtsenecac.ca
 // I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/       \
#include "Power.h"
#ifndef SENECA_HERO_H
#define SENECA_HERO_H
#include <iostream>

namespace seneca {
class Hero {
private:
  char m_name[MAX_NAME_LENGTH + 1];
  Power *m_powers;
  int m_power_num;
  int m_power_level;

public:
  Hero();
  Hero(const char *name, Power powers[], int power_num);
  ~Hero();
  void setEmpty();
  void deallocate();
  int getLevel();
  std::ostream &display(std::ostream &os = std::cout) const;
  Hero &operator+=(const Power &power);
  Hero &operator-=(const int &num);
};
// Global helpers
bool operator>(Hero &hero1, Hero &hero2);
bool operator<(Hero &hero1, Hero &hero2);
Hero &operator>>(const Power &power, Hero &hero);
Hero &operator<<(Hero &hero, const Power &power);
} // namespace seneca
#endif