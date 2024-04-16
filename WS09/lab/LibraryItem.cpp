/***********************************************************************
// Workshop # 9
//
// File: LibraryItem.cpp
// Version 1.0
// Date: 2024.03.26
// Author: Tzu Han Chao

// I have done all the coding by myself and only copied the code that my
// professor provided to complete my workshops and assignments.
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/
#include "LibraryItem.h"
#include <cstring>

namespace seneca {
LibraryItem::LibraryItem() { cout << "default constructor " << endl; }
LibraryItem::LibraryItem(const char *title, int year) {
  setTitle(title);
  setYear(year);
}
// copy constructor
LibraryItem::LibraryItem(const LibraryItem &libItem) {
  if (libItem.m_title != nullptr) {
    setTitle(libItem.m_title);
  }
  setYear(libItem.m_year);
}
// copy assignment operator
LibraryItem &LibraryItem::operator=(const LibraryItem &libItem) {
  if (this != &libItem) {
    if (libItem.m_title != nullptr) {
      setTitle(libItem.m_title);
    }

    setYear(libItem.m_year);
  }
  return *this;
};
// destructor
LibraryItem::~LibraryItem() { deallocate(); }

void LibraryItem::setTitle(const char *title) {
  deallocate();
  if (title != nullptr) {
    m_title = new char[strlen(title) + 1];
    strcpy(m_title, title);
  }
}

void LibraryItem::setYear(int year) {
  if (year >= 0) {
    m_year = year;
  } else {
    m_year = 0;
  }
}

void LibraryItem::deallocate() {
  delete[] m_title;
  m_title = nullptr;
}

// Title: The Great Gatsby (1925)
ostream &LibraryItem::display(ostream &ostr) const {
  ostr << "Title: " << m_title << " (" << m_year << ")";
  return ostr;
}

} // namespace seneca