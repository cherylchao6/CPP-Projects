/***********************************************************************
// Workshop # 8, Virtual Functions and Abstract Base Classes
//
// File: SavingsAccount.cpp
// Version 1.0
// Date: 2024.03.18
// Author: Tzu Han Chao
// Description
// This file implements the SavingsAccount class
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/
#include "SavingsAccount.h"
#include <iostream>
using namespace std;
namespace seneca {
SavingsAccount::SavingsAccount(double balance, double interestRate)
    : Account(balance) {
  if (interestRate > 0) {
    m_interestRate = interestRate;
  } else {
    m_interestRate = 0.0;
  }
}
void SavingsAccount::monthEnd() {
  double balance = this->balance();
  credit(balance * m_interestRate);
}

void SavingsAccount::display(std::ostream &ost) const {
  ost.setf(ios::fixed);
  ost.precision(2);
  ost << "Account type: Savings" << endl;
  ost << "Balance: "
      << "$" << this->balance() << endl;
  ost << "Interest Rate (%): " << m_interestRate * 100 << endl;
}
} // namespace seneca