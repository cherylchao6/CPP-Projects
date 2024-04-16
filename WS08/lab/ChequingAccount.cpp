/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: ChequingAccount.cpp
// Version 1.0
// Date: 2024.03.18
// Author: Tzu Han Chao
// Description
// This file implements the ChequingAccount class
// I have done all the coding by myself and only copied the code that my
// professor provided to complete my workshops and assignments.
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/
#include "ChequingAccount.h"
#include "Account.h"
#include <iostream>
using namespace std;

namespace seneca {
ChequingAccount::ChequingAccount(double balance, double transactionFee,
                                 double monthlyFee)
    : Account(balance) {
  if (transactionFee > 0) {
    m_transactionFee = transactionFee;
  } else {
    m_transactionFee = 0.0;
  }

  if (monthlyFee > 0) {
    m_monthlyFee = monthlyFee;
  } else {
    m_monthlyFee = 0.0;
  }
}

bool ChequingAccount::credit(double amount) {
  bool isSuccess = Account::credit(amount);

  if (isSuccess) {
    Account::debit(m_transactionFee);
  }

  return isSuccess;
};

bool ChequingAccount::debit(double amount) {
  bool isSuccess = Account::debit(amount);

  if (isSuccess) {
    Account::debit(m_transactionFee);
  }

  return isSuccess;
}

void ChequingAccount::monthEnd() { Account::debit(m_monthlyFee); };

void ChequingAccount::display(std::ostream &ost) const {
  ost.setf(ios::fixed);
  ost.precision(2);
  ost << "Account type: Chequing" << endl;
  ost << "Balance: "
      << "$" << this->balance() << endl;
  ost << "Per Transaction Fee: " << m_transactionFee << endl;
  ost << "Monthly Fee: " << m_monthlyFee << endl;
}
} // namespace seneca