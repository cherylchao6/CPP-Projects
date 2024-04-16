/***********************************************************************
 // Name: Tuz Han Chao
 // id: 151593225
 // email: tchao3@mtsenecac.ca
 // I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include "SavingsAccount.h"
#include <iostream>
using namespace std;

namespace seneca {
//  Assume all data is valid.
SavingsAccount::SavingsAccount(const char *name, Date openDate,
                               DepositInfo depInfo, double balance,
                               double interest, Date interestDate)
    : BankAccount(name, openDate, depInfo, balance) {
  m_interest = interest;
  m_interestDate = interestDate;
}

void SavingsAccount::writeInterest(std::ostream &out) const {
  out.setf(ios::fixed);
  out.precision(3);
  out << m_interest << "%";
  out.unsetf(ios::fixed);
}

void SavingsAccount::applyInterest(Date &dt) {
  //  [Original Balance] + [Interest Amount] ([Interest Rate]) = [New Balance] |
  //  [Original Interest Date] => [New Interest Date]
  double balance = getBalance();
  double interest = balance * m_interest;
  double new_balance = balance + interest;
  cout << "   ";

  writeCurrency(cout, balance);
  cout << " + ";
  writeCurrency(cout, interest);
  cout.setf(ios::fixed);
  cout.precision(2);

  cout << " (";
  cout.unsetf(ios::fixed);
  writeInterest(cout);
  cout << ")";

  cout << " = ";
  writeCurrency(cout, new_balance);
  cout << " | ";
  m_interestDate.write(cout);
  cout << " => ";
  dt.write(cout);
  cout << endl;

  // update balance
  setBalance(new_balance);
  m_interestDate = dt;
}

std::ostream &SavingsAccount::write(std::ostream &out) const {
  BankAccount::write(out);
  out << " | ";
  writeInterest(out);
  out << " | " << m_interestDate;

  return out;
}

std::istream &SavingsAccount::read(std::istream &in) {
  BankAccount::read(in);
  cout << "Interest Date ";
  m_interestDate.read(in);
  cout << "Interest Rate: ";
  in >> m_interest;

  return in;
}

std::istream &operator>>(std::istream &in, SavingsAccount &acct) {
  acct.read(in);
  return in;
}

std::ostream &operator<<(std::ostream &out, const SavingsAccount &acct) {
  acct.write(out);
  return out;
}

} // namespace seneca