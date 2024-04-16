/***********************************************************************
 // Name: Tuz Han Chao
 // id: 151593225
 // email: tchao3@mtsenecac.ca
 // I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include "BankAccount.h"
#include "iostream"
#include <cstring>
using namespace std;

namespace seneca {
double BankAccount::getBalance() const { return m_balance; };
void BankAccount::setBalance(double balance) { m_balance = balance; };
void BankAccount::writeCurrency(std::ostream &out, double amount) const {
  out.setf(ios::fixed);
  out.precision(2);
  out << "$" << amount;
  out.unsetf(ios::fixed);
};
// Assume all data is valid.
BankAccount::BankAccount(const char *name, Date openDate, DepositInfo depInfo,
                         double balance) {
  strcpy(m_name, name);
  m_openDate = openDate;
  m_depInfo = depInfo;
  m_balance = balance;
}

std::ostream &BankAccount::write(std::ostream &out) const {
  // >> Jane Doe | $0.00 | 2023-05-19 | 04853,001,0037857
  out << ">>"
      << " " << m_name << " | ";
  writeCurrency(out, m_balance);
  out << " | " << m_openDate << " | " << m_depInfo;

  return out;
}
std::istream &BankAccount::read(std::istream &in) {

  cout << "Name: ";
  in.getline(m_name, sizeof(m_name));
  cout << "Opening Balance: ";
  in >> m_balance;
  cout << "Date Opened ";
  m_openDate.read(in);
  m_depInfo.read(in);

  in.ignore(10000, '\n');
  return in;
}

// helper function
std::istream &operator>>(std::istream &in, BankAccount &acct) {
  acct.read(in);
  return in;
};
std::ostream &operator<<(std::ostream &out, const BankAccount &acct) {
  acct.write(out);
  return out;
};
} // namespace seneca