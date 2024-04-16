/***********************************************************************
 // Name: Tuz Han Chao
 // id: 151593225
 // email: tchao3@mtsenecac.ca
 // I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************//***********************************************************************
 // Name: Tuz Han Chao
 // id: 151593225
 // email: tchao3@mtsenecac.ca
 // I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/
#include "BankAccount.h"
#include "DepositUtility.h"
#include "iostream"
#ifndef SENECA_SAVINGSACCOUNT_H
#define SENECA_SAVINGSACCOUNT_H

#define MAX_NAME 50

namespace seneca {
class SavingsAccount : public BankAccount {
  double m_interest{};
  Date m_interestDate;
  void writeInterest(std::ostream &out) const;

public:
  SavingsAccount(){};
  SavingsAccount(const char *name, Date openDate, DepositInfo depInfo,
                 double balance, double interest, Date interestDate);
  void applyInterest(Date &dt);
  std::ostream &write(std::ostream &out) const;
  std::istream &read(std::istream &in);
};
// helper function
std::istream &operator>>(std::istream &in, SavingsAccount &acct);
std::ostream &operator<<(std::ostream &out, const SavingsAccount &acct);
} // namespace seneca

#endif