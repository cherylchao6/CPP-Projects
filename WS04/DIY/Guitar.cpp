/***********************************************************************
// OOP244 Workshop #4 p2: tester program
//
// Version 1.0
// Date: Summer 2023
// Author Michael Huang
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
// name: Tzu Han Chao
// email: tchao3@myseneca.ca
// id: 151593225
// date: 2024/02/07
// I have done all the coding by myself and only copied the code that my
// professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include "Guitar.h"
#include <cstring>
#include <iostream>
using namespace std;

namespace seneca {
const char *GuitarStr::material() const { return m_material; }
double GuitarStr::gauge() const { return m_gauge; }
GuitarStr::GuitarStr(){};

GuitarStr::GuitarStr(const char *ma, double ga) {
  strncpy(m_material, ma, MAT_LEN);
  m_gauge = ga;
};

double GuitarStr::getGauge() { return m_gauge; };
char *GuitarStr::getMaterial() { return m_material; };

// Guitar
Guitar::Guitar(const char *mod) : m_strings(nullptr), m_numStrings(0){};
Guitar::Guitar(GuitarStr strs[], int ns, const char *mod) {
  if (ns > 0 && mod[0] != '\0') {
    m_strings = new GuitarStr[ns];
    for (int i = 0; i < ns; ++i) {
      m_strings[i] = strs[i];
    }
    m_numStrings = ns;
    strcpy(m_model, mod);
  } else {
    setEmpty();
  }
};

Guitar::~Guitar() { deallocate(); };

void Guitar::deallocate() {
  if (m_strings != nullptr) {
    delete[] m_strings;
    m_strings = nullptr;
  };
};

void Guitar::setEmpty() {
  deallocate();
  m_numStrings = 0;
  strcpy(m_model, defaultModelName);
};

bool Guitar::changeString(const GuitarStr &gs, int sn) {
  if (sn >= 0 && sn < m_numStrings - 1) {
    m_strings[sn] = gs;
    return true;
  } else {
    return false;
  }
};

void Guitar::reString(GuitarStr strs[], int ns) {
  if (ns > 0) {
    setEmpty();
    m_numStrings = ns;
    m_strings = new GuitarStr[ns];
    for (int i = 0; i < ns; ++i) {
      m_strings[i] = strs[i];
    }
  };
};

void Guitar::deString() {
  deallocate();
  m_numStrings = 0;
}

bool Guitar::strung() const {
  if (m_numStrings > 0) {
    return true;
  } else {
    return false;
  }
}

bool Guitar::matchGauge(double ga) const {
  bool matched = false;
  for (int i = 0; i < m_numStrings; i++) {
    if (m_strings[i].getGauge() == ga) {
      matched = true;
      break;
    }
  }

  return matched;
}

std::ostream &Guitar::display(std::ostream &os) const {
  if (m_strings == nullptr || m_numStrings == 0) {
    os << "***Empty Guitar***" << endl;
  } else {
    os << "Guitar Model: " << m_model << endl;
    os << "Strings: " << m_numStrings << endl;
    for (int i = 0; i < m_numStrings; i++) {
      os << "#" << i + 1;
      os.width(MAT_LEN);
      os << m_strings[i].getMaterial() << " | ";
      os.setf(ios::fixed);
      os.precision(1);
      os << m_strings[i].getGauge() << endl;
      os.unsetf(ios::fixed);
    }
  }
  return os;
};

} // namespace seneca
