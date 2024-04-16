/***********************************************************************
// Workshop # 9
//
// File: Book.cpp
// Version 1.0
// Date: 2024.03.26
// Author: Tzu Han Chao

// I have done all the coding by myself and only copied the code that my
// professor provided to complete my workshops and assignments.
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/
#include "Book.h"
#include <cstring>
namespace seneca {

Book::Book() {}

Book::Book(const char *title, int year, const char *author)
    : LibraryItem(title, year) {
  setAuthor(author);
}

Book::~Book() { deallocate(); }

// copy constructor and copy assignment of the derived class must manage the
// copying and copy-assigning of the base class too. !!!!!!!

// copy constructor
Book::Book(Book &book) : LibraryItem(book) {
  if (book.m_author != nullptr) {
    setAuthor(book.m_author);
  }
}
// copy assignment operator
Book &Book::operator=(const Book &book) {
  if (this != &book) {
    LibraryItem::operator=(book);
    if (book.m_author != nullptr) {
      setAuthor(book.m_author);
    }
  }
  return *this;
};

// Title: The Great Gatsby (1925)<new line>
// Author: F. Scott Fitzgerald<no new line>
ostream &Book::display(ostream &ostr) const {
  LibraryItem::display();
  ostr << endl;
  ostr << "Author: " << m_author;
  return ostr;
}

bool Book::operator>(const Book &other) const {
  if (m_author == nullptr && other.m_author == nullptr)
    return false; // Both null, considered equal
  if (m_author == nullptr)
    return false; // Null is considered less than any non-null
  if (other.m_author == nullptr)
    return true; // Non-null is considered greater than null
  return strcmp(m_author, other.m_author) > 0;
}

void Book::setAuthor(const char *author) {
  deallocate();
  if (author != nullptr) {
    m_author = new char[strlen(author) + 1];
    strcpy(m_author, author);
  }
}
void Book::deallocate() {
  delete[] m_author;
  m_author = nullptr;
}
} // namespace seneca