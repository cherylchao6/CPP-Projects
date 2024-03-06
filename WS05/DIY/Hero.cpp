/***********************************************************************
 // Name: Tuz Han Chao
 // id: 151593225
 // email: tchao3@mtsenecac.ca
 // I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include "Hero.h"
#include <cstring>
#include <iostream>
using namespace std;
namespace seneca {
Hero::Hero() : m_powers(nullptr) { setEmpty(); }
Hero::Hero(const char *name, Power powers[], int power_num) {
  setEmpty();
  if (name[0] != '\0' && power_num > 0) {
    int rarity = 0;
    strcpy(m_name, name);
    m_powers = new Power[power_num];
    for (int i = 0; i < power_num; i++) {
      m_powers[i] = powers[i];
      rarity += powers[i].checkRarity();
    }
    m_power_level = rarity * power_num;
    m_power_num = power_num;
  }
}
void Hero::setEmpty() {
  m_powers = nullptr;
  m_name[0] = '\0';
  m_power_num = 0;
  m_power_level = 0;
}

void Hero::deallocate() {
  if (m_powers != nullptr) {
    delete[] m_powers;
    m_powers = nullptr;
  }
}

int Hero::getLevel() { return m_power_level; }

std::ostream &Hero::display(std::ostream &os) const {
  os << "Name: ";
  os << m_name << endl;
  displayDetails(m_powers, m_power_num);
  os << "Power Level: ";
  os << m_power_level;
  return os;
}

Hero &Hero::operator+=(const Power &power) {
  int totalRarity = 0;
  Power *newPower = new Power[m_power_num + 1];
  for (int i = 0; i < m_power_num; i++) {
    newPower[i] = m_powers[i];
    totalRarity += m_powers[i].checkRarity();
  }
  newPower[m_power_num] = power;
  totalRarity += power.checkRarity();
  deallocate();
  m_powers = newPower;
  m_power_num += 1;
  m_power_level = totalRarity * m_power_num;
  return *this;
}

Hero &Hero::operator-=(const int &num) {
  m_power_level -= num;
  return *this;
}

Hero::~Hero() { deallocate(); }

bool operator>(Hero &hero1, Hero &hero2) {
  return hero1.getLevel() > hero2.getLevel();
}

bool operator<(Hero &hero1, Hero &hero2) {
  return hero1.getLevel() < hero2.getLevel();
}

Hero &operator>>(const Power &power, Hero &hero) {
  hero += power;
  return hero;
};

Hero &operator<<(Hero &hero, const Power &power) {
  hero += power;
  return hero;
};

} // namespace seneca