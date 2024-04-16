/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: Account.h
// Version 1.0
// Date: 2024.03.18
// Author: Tzu Han Chao
// Description
// This file defines the Account class
// I have done all the coding by myself and only copied the code that my
// professor provided to complete my workshops and assignments.
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/
#ifndef SENECA_ACCOUNT_H
#define SENECA_ACCOUNT_H
#include "iAccount.h"

namespace seneca {
class Account : public iAccount {
private:
  double m_balance;
  void setBalance(double);

public:
  Account(double = 0.0);
  bool credit(double);
  bool debit(double);

protected:
  double balance() const;
};

} // namespace seneca
#endif