/***********************************************************************
// OOP244 Workshop #5 Lab (part 1)
//
// File  bankaccount.h
// Version v0.8 Oct 21st 2023
// Author  Jitesh Arora
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
/***********************************************************************
 // Name: Tuz Han Chao
 // id: 151593225
 // email: tchao3@mtsenecac.ca
 // I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/
#pragma once
#ifndef SENECA_BANKACCOUNT_H_
#define SENECA_BANKACCOUNT_H_

namespace seneca {
const double CHECK_FEE = 1.25;
const double SAVING_FEE = 3.50;
const double CHECK_RATE = 0.5 / 100;
const double SAVING_RATE = 2.5 / 100;
const int ACCT_MAXLEN_USER = 16; // Max Length of user name

// Class Definition
class bankAccount {

private:
  // Data Members
  char m_userName[ACCT_MAXLEN_USER];
  double m_funds;
  bool m_checking;
  int m_monthlyTransactions;

  bool isOpen() const;

public:
  bankAccount(const char *name = nullptr, bool checking = false);
  bool setup(const char *name, bool checking);
  // Cast Operators
  operator bool() const;
  operator double() const;
  // Unary Operators
  bankAccount &operator++();
  bankAccount &operator--();
  // Binary Operators
  bool operator+=(double);
  bool operator-=(double);
  bool operator==(const bankAccount &) const;
  bool operator>(double) const;
  bool operator<=(double) const;
  // Additional Methods
  bool operator<<(bankAccount &);
  void display(void) const;
};

// Global helpers
bool operator>(double lhs, const bankAccount &rhs);
bool operator<=(double lhs, const bankAccount &rhs);
} // namespace seneca
#endif
