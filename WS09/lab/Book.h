/***********************************************************************
// Workshop # 9
//
// File: Book.h
// Version 1.0
// Date: 2024.03.26
// Author: Tzu Han Chao

// I have done all the coding by myself and only copied the code that my
// professor provided to complete my workshops and assignments.
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/
#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H
#include "LibraryItem.h"

namespace seneca {
class Book : public LibraryItem {
private:
  // A pointer to store the name of the author of the book.
  char *m_author = nullptr;

public:
  Book();
  Book(const char *title, int year, const char *author);
  ~Book();
  // copy constructor
  Book(Book &book);
  // copy assignment operator
  Book &operator=(const Book &book);

  ostream &display(ostream &ostr = cout) const;
  bool operator>(const Book &other) const;

  void setAuthor(const char *author);
  void deallocate();
};

} // namespace seneca
#endif