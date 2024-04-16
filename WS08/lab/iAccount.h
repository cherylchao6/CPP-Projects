/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: iAccount.h
// Version 1.0
// Date: 2024.03.18
// Author: Tzu Han Chao
// Description
// This file defines the iAccount interface
// I have done all the coding by myself and only copied the code that my
// professor provided to complete my workshops and assignments.
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/       \
#ifndef SENECA_IACCOUNT_H
#define SENECA_IACCOUNT_H
#include <iostream>
namespace seneca {
class iAccount {
private:
  /* data */
public:
  iAccount(){};
  virtual ~iAccount(){};

  // adds a positive amount to the account balance
  virtual bool credit(double) = 0;

  // subtracts a positive amount from the account balance
  virtual bool debit(double) = 0;

  // applies month-end transactions to the account
  virtual void monthEnd() = 0;

  // inserts account information into an ostream object
  virtual void display(std::ostream &) const = 0;
};

// helper function

//  receives a C-style string identifying the type of account and the initial
//  account balance, creates the account with the starting balance and returns
//  its address.
iAccount *CreateAccount(const char *, double);
} // namespace seneca
#endif