/***********************************************************************
// OOP244 Workshop #4 p1
//
// File	Fridge.cpp
// Version 1.0
// Date: Summer 2023
// Author Michael Huang
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
// Tzu Han Chao
// tchao3@myseneca.ca
// 151593225
// 2024.02.05
// I have done all the coding by myself and only copied the code that my
// professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include "Fridge.h"
#include <cstring>
#include <iostream>
using namespace std;

namespace seneca {

const char *Food::name() const { return m_name; }
int Food::weight() const { return m_weight; }
Food::Food() {}

Food::Food(const char *nm, int wei) {
  strncpy(m_name, nm, NAME_LEN);
  m_weight = wei;
}

Fridge::Fridge() : m_numFoods(0), m_model(nullptr){};
Fridge::~Fridge() {
  if (m_model != nullptr) {
    delete[] m_model;
    m_model = nullptr;
  }
}

// First set the the empty state by utilizing the default constructor and
// assigning that to the current object
Fridge::Fridge(Food farr[], int nf, const char *mod) : Fridge() {
  // Validate the parameters
  if (nf > 0 && mod != nullptr && mod[0] != '\0') {
    m_numFoods = nf;
    m_model = new char[strlen(mod) + 1];
    strcpy(m_model, mod);
    for (int i = 0; i < nf && i < FRIDGE_CAP; i++) {
      m_foods[i] = farr[i];
    }
  }
};

bool Fridge::addFood(const Food &f) {
  if (m_numFoods < FRIDGE_CAP) {
    m_foods[m_numFoods] = f;
    m_numFoods += 1;
    return true;
  } else {
    return false;
  }
}

void Fridge::changeModel(const char *m) {
  if (m != nullptr && m[0] != '\0') {
    delete[] m_model;
    m_model = new char[strlen(m) + 1];
    strcpy(m_model, m);
  }
}

bool Fridge::fullFridge() const {
  if (m_numFoods >= FRIDGE_CAP) {
    return true;
  } else {
    return false;
  }
}

bool Fridge::findFood(const char *f) const {
  bool found = false;
  for (int i = 0; i < m_numFoods; i++) {
    if (strcmp(m_foods[i].m_name, f) == 0) {
      found = true;
      break;
    }
  }
  return found;
};

std::ostream &Fridge::display(std::ostream &os) const {
  if (m_numFoods > 0) {
    os << "Fridge Model: " << m_model << endl;
    os << "Food count: " << m_numFoods << " Capacity: " << FRIDGE_CAP << endl;
    os << "List of Foods" << endl;
    for (int i = 0; i < m_numFoods; i++) {
      os.width(20);
      os << m_foods[i].m_name << " | " << m_foods[i].m_weight << endl;
    }
  }

  return os;
}

} // namespace seneca
