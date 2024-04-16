/***********************************************************************
// Workshop # 9
//
// File: LibraryItem.h
// Version 1.0
// Date: 2024.03.26
// Author: Tzu Han Chao

// I have done all the coding by myself and only copied the code that my
// professor provided to complete my workshops and assignments.
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/
#ifndef SENECA_LIBRARYITEM_H
#define SENECA_LIBRARYITEM_H
#include <iostream>
using namespace std;

namespace seneca {
class LibraryItem {
private:
  // A pointer to store the title of the item.
  char *m_title = nullptr;
  // An integer to store the publication year of the item.
  int m_year{};

public:
  LibraryItem();
  LibraryItem(const char *title, int year);
  virtual ~LibraryItem();
  // copy constructor
  LibraryItem(const LibraryItem &libItem);
  // copy assignment operator
  LibraryItem &operator=(const LibraryItem &libItem);
  void deallocate();
  void setTitle(const char *title);
  void setYear(int year);
  virtual ostream &display(ostream &ostr = cout) const;
};

} // namespace seneca
#endif