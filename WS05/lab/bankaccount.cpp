/***********************************************************************
// OOP244 Workshop #5 Lab (part 1)
//
// File  bankaccount.cpp
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
#define _CRT_SECURE_NO_WARNINGS

#include "bankaccount.h"
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

namespace seneca {
// Default Constructor with default arguments
bankAccount::bankAccount(const char *name, bool checking) {
  m_userName[0] = '\0'; // Empty string implies is account is not open
  setup(name, checking);
}

// Open bank account: setup can only be done once!
bool bankAccount::setup(const char *name, bool checking) {
  if (isOpen())
    return false;
  if (name == nullptr)
    return false;

  strcpy(m_userName, name);
  m_monthlyTransactions = 0;
  m_checking = checking;
  m_funds = 0;
  return true;
}

// Account is open if user name string is not empty
bool bankAccount::isOpen() const { return (m_userName[0] != '\0'); }

// Cast Operators
bankAccount::operator bool() const { return isOpen(); };
bankAccount::operator double() const { return m_funds; };

// Unary Operators
bankAccount &bankAccount::operator++() {
  if (isOpen() && m_funds > 0) {
    double rate = m_checking ? CHECK_RATE : SAVING_RATE;
    m_funds *= (1 + rate);
  }
  return *this;
};
bankAccount &bankAccount::operator--() {
  if (isOpen()) {
    double fee = m_checking ? CHECK_FEE : SAVING_FEE;
    m_funds -= m_monthlyTransactions * fee;
  }
  return *this;
};
// Binary Operators
bool bankAccount::operator+=(double deposit) {
  if (isOpen()) {
    m_funds += deposit;
    m_monthlyTransactions += 1;

    if (deposit >= 0) {
      cout << "Deposit $";
      cout.setf(ios::fixed);
      cout.precision(2);
      cout << fabs(deposit);
      cout << " for ";
      cout << m_userName << endl;
    }
    return true;
  } else {
    return false;
  }
};
bool bankAccount::operator-=(double withdraw) {
  if (isOpen()) {
    *this += (-withdraw);

    cout << "Withdraw $";
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << withdraw;
    cout << " for ";
    cout << m_userName << endl;
    return true;
  } else {
    return false;
  }
};
bool bankAccount::operator==(const bankAccount &targetAccount) const {
  return (strcmp(m_userName, targetAccount.m_userName) == 0 &&
          m_checking == targetAccount.m_checking &&
          fabs(m_funds - targetAccount.m_funds) < 0.001);
};
bool bankAccount::operator>(double funds) const {
  if (isOpen()) {
    return m_funds > funds;
  } else {
    return false;
  }
}
bool bankAccount::operator<=(double funds) const {
  if (isOpen()) {
    return !(*this > funds);
  } else {
    return false;
  }
}
// Additional Methods
bool bankAccount::operator<<(bankAccount &account) {
  if (isOpen() && account.isOpen() && account.m_funds > 0.0) {
    cout << "Transfer $" << account.m_funds << " from " << account.m_userName
         << " to " << m_userName << endl;
    *this += account.m_funds;
    account -= account.m_funds;
    return true;
  } else {
    return false;
  }
};
void bankAccount::display(void) const {
  if (isOpen()) {
    cout << "Display Account -> User:";
    cout.width(ACCT_MAXLEN_USER);
    cout.fill('-');
    cout << m_userName;
    cout << " | ";
    cout.width(8);
    cout.fill(' ');
    if (m_checking) {
      cout << "Checking";
    } else {
      cout << "Savings";
    }
    cout << " | ";
    cout << "Balance: $";
    cout.width(8);
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << m_funds;
    cout.unsetf(ios::fixed);
    cout << " | ";
    cout << "Transactions:";
    cout.width(3);
    cout.fill('0');
    cout << m_monthlyTransactions << endl;
  } else {
    cout << "Display Account -> User:------- NOT OPEN" << endl;
  }
};

// Global Helpers
bool operator>(double lhs, const bankAccount &rhs) {
  if (rhs) {
    return !(rhs > lhs);
  } else {
    return false;
  }
}

bool operator<=(double lhs, const bankAccount &rhs) {
  if (rhs) {
    return !(rhs <= lhs);
  } else {
    return false;
  }
}
} // namespace seneca
