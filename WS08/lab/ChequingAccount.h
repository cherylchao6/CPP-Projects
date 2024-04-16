/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: ChequingAccount.h
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
#ifndef SENECA_CHEQUINGACCOUNT_H
#define SENECA_CHEQUINGACCOUNT_H
#include "Account.h"
#include <iostream>
namespace seneca {
class ChequingAccount : public Account {
private:
  double m_transactionFee;
  double m_monthlyFee;

public:
  ChequingAccount(double, double, double);
  bool credit(double);
  bool debit(double);
  void monthEnd();
  void display(std::ostream &) const;
};

} // namespace seneca
#endif