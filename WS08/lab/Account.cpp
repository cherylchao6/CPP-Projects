/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: Account.cpp
// Version 1.0
// Date: 2024.03.18
// Author: Tzu Han Chao
// Description
// This file implements the Account class
// I have done all the coding by myself and only copied the code that my
// professor provided to complete my workshops and assignments.
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/
#include "Account.h"
namespace seneca {
void Account::setBalance(double balance) {
  if (balance <= 0) {
    m_balance = 0.0;
  } else {
    m_balance = balance;
  }
}
Account::Account(double balance) { setBalance(balance); }

bool Account::credit(double amount) {
  if (amount > 0) {
    m_balance += amount;
    return true;
  } else {
    return false;
  }
}
bool Account::debit(double amount) {
  if (amount > 0) {
    m_balance -= amount;
    return true;
  } else {
    return false;
  }
}

double Account::balance() const { return m_balance; }
} // namespace seneca