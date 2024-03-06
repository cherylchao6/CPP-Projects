/***********************************************************************
// OOP244 Workshop #4 p2: tester program
// File  main.cpp
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
#ifndef SENECA_GUITAR_H
#define SENECA_GUITAR_H

#include <iostream>

namespace seneca {

const int MAT_LEN = 10;
const int MAX_MODEL_NAME = 15;
const char defaultModelName[13] = "Stratocaster";

class GuitarStr {
  char m_material[MAT_LEN]{};
  double m_gauge{};

public:
  const char *material() const;
  double gauge() const;
  GuitarStr();
  GuitarStr(const char *ma, double ga);
  double getGauge();
  char *getMaterial();
};

// Design and implement a class named Guitar that stores the following
// information:

// A dynamic array of GuitarStr (m_strings)
// The number of GuitarStr in the array (m_numStrings)
// A model name for the Guitar with a maximum length of 15 characters (m_model)
class Guitar {
  GuitarStr *m_strings;
  int m_numStrings;
  char m_model[MAX_MODEL_NAME + 1];
  void setEmpty();
  void deallocate();

public:
  Guitar(const char *mod = defaultModelName);
  Guitar(GuitarStr strs[], int ns, const char *mod);
  ~Guitar();

  bool changeString(const GuitarStr &gs, int sn);
  void reString(GuitarStr strs[], int ns);
  void deString();
  bool strung() const;
  bool matchGauge(double ga) const;
  std::ostream &display(std::ostream &os = std::cout) const;
};

} // namespace seneca

#endif
