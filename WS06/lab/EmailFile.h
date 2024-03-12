/***********************************************************************
// OOP244 Workshop # 6
//
// File:	EmailFile.h
// Version 1.0
// Date:
// Author: Sina Talebi Moghaddam
// Description
// This file must be completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
/***********************************************************************       \
 // Name: Tuz Han Chao                                                         \
 // id: 151593225                                                              \
 // email: tchao3@mtsenecac.ca                                                 \
 // I have done all the coding by myself and only copied the code that my      \
professor provided to complete my workshops and assignments.                   \
***********************************************************************/       \
#ifndef SENECA_EMAILFILE_H
#define SENECA_EMAILFILE_H
#include <iostream>

namespace seneca {

const int BUFFER_SIZE =
    1024; // Maximum possible size for all the fields of the Email record

class EmailFile;
class Email {
  char *m_email{nullptr};
  char *m_name{nullptr};
  char m_year[5]{'\0'};
  Email(){};
  Email &operator=(const Email &);
  bool load(std::ifstream &in);
  ~Email();
  // Prohibit the copy constructor for this class:
  Email(const Email &) = delete;
  // Make the EmailFile class a "friend" of the Email class
  friend class EmailFile;
};

class EmailFile {
  Email *m_emailLines{nullptr};
  char *m_filename{nullptr};
  int m_noOfEmails{0};
  void setFilename(const char *filename);
  void setEmpty();
  bool setNoOfEmails();
  void loadEmails();
  operator bool() const;

public:
  EmailFile();
  EmailFile(const EmailFile &);
  EmailFile(const char *filename);

  std::ostream &view(std::ostream &ostr) const;
  bool saveToFile(const char *filename) const;
  void fileCat(const EmailFile &obj, const char *name = nullptr);
  void copyFile(const EmailFile &f);

  EmailFile &operator=(const EmailFile &);

  ~EmailFile();
};

std::ostream &operator<<(std::ostream &ostr, const EmailFile &text);

} // namespace seneca
#endif // !SENECA_EMAILFILE_H
