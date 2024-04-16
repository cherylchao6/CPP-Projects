/***********************************************************************
 // Name: Tuz Han Chao
 // id: 151593225
 // email: tchao3@mtsenecac.ca
 // I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/

#include "DepositUtility.h"
#include "iostream"
#ifndef SENECA_BANKACCOUNT_H
#define SENECA_BANKACCOUNT_H

#define MAX_NAME 50

namespace seneca {
class BankAccount {
  char m_name[MAX_NAME + 1]{};
  Date m_openDate;
  DepositInfo m_depInfo;
  double m_balance{};

protected:
  double getBalance() const;
  void setBalance(double balance);
  void writeCurrency(std::ostream &out, double amount) const;

public:
  BankAccount(){};
  BankAccount(const char *name, Date openDate, DepositInfo depInfo,
              double balance);
  std::ostream &write(std::ostream &out) const;
  std::istream &read(std::istream &in);
};

// helper function
std::istream &operator>>(std::istream &in, BankAccount &acct);
std::ostream &operator<<(std::ostream &out, const BankAccount &acct);
} // namespace seneca

#endif