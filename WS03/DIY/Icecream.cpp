#include "Icecream.h"
#include <cstring>
#include <iostream>
using namespace std;

namespace seneca {

Icecream::Icecream()
    : m_withWafer(false), m_numScoops(0), m_scoopPrice(0.0),
      m_flavourPrice(0.0), m_withWaferPrice(0.0), m_totalPrice(0.0) {
  m_flavour[0] = '\0';
}
// from professor notes
void Icecream::getInt(int *num, int min, int max) {
  cin >> *num;
  while (cin.fail() || *num > max || *num < min) {
    if (cin.fail()) {
      cout << "Invalid entry, retry" << endl;
      cout << "> ";
    } else {
      cout << "Invlid value(" << min << "<=val<=" << max << ")" << endl;
      cout << "> ";
    }
    cin.clear();
    cin.ignore(12000, '\n');
    cin >> *num;
  }
  cin.ignore(12000, '\n');
}

void Icecream::getOrder() {
  printMenu();
  // get flavor
  int flavor = 0;
  getInt(&flavor, 1, 5);
  switch (flavor) {
  case 1:
    strcpy(m_flavour, "Chocolate");
    break;
  case 2:
    strcpy(m_flavour, "Strawberry");
    break;
  case 3:
    strcpy(m_flavour, "Mango");
    break;
  case 4:
    strcpy(m_flavour, "Tutti fruit");
    break;
  case 5:
    strcpy(m_flavour, "Almond crunch");
    break;
  default:
    break;
  }

  // get scoop
  cout << "Number of Scoops (max " << MAX_SCOOP << ")" << endl;
  cout << "> ";
  getInt(&m_numScoops, 1, 3);
  // wafer
  cout << "Vanilla wafer cone?" << endl;
  cout << "(Y)es/(N)o > ";
  m_withWafer = withWafer();

  // cal price
  m_scoopPrice = m_numScoops * SCOOP_PRICE;
  if (strcmp(m_flavour, "Chocolate") == 0) {
    m_flavourPrice = m_numScoops * 1.00;
  }
  if (m_withWafer) {
    m_withWaferPrice = 5.00;
  }
  m_totalPrice = m_scoopPrice + m_flavourPrice + m_withWaferPrice;
}

void Icecream::printMenu() {
  cout << "Select flavour:" << endl;
  cout << "----------------" << endl;
  cout << "1: Chocolate" << endl;
  cout << "2: Strawberry" << endl;
  cout << "3: Mango" << endl;
  cout << "4: Tutti fruit" << endl;
  cout << "5: Almond crunch" << endl;
  cout << "----------------" << endl;
  cout << "> ";
}

// from professor notes
bool Icecream::withWafer() {
  bool done = false;
  char res{};
  char newline{};

  do {
    res = cin.get();
    newline = cin.get();
    if (newline != '\n') {
      cin.ignore(10000, '\n');
    } else if (res == 'y' || res == 'Y' || res == 'n' || res == 'N') {
      done = true;
    }
  } while (!done && cout << "Only Y or N are acceptable:\n> ");
  return res == 'Y' || res == 'y';
}

void Icecream::printOrder() {
  cout << "Order details:                Price" << endl;
  cout << "-----------------------------------" << endl;
  cout.setf(ios::left);
  cout.width(18);
  cout << "Number of scoops,";
  cout.width(2);
  cout << m_numScoops;
  cout.width(10);
  cout << "total:";
  printPriceFormat(m_scoopPrice);

  // flavour
  cout.setf(ios::left);
  if (m_flavourPrice > 0) {
    cout.width(30);
    string flavourText = m_flavour + string(" flavour:");
    cout << flavourText;
    printPriceFormat(m_flavourPrice);
  } else {
    string flavourText = m_flavour + string(" flavour");
    cout << flavourText << endl;
  }

  // Wafer
  cout.setf(ios::left);
  cout.width(30);
  cout << "Vanilla Wafer:";
  printPriceFormat(m_withWaferPrice);

  // Price
  cout.setf(ios::left);
  cout.width(30);
  cout << "Price:";
  printPriceFormat(m_totalPrice);
}

void printPriceFormat(double price) {
  cout.setf(ios::right);
  cout.setf(ios::fixed);
  cout.precision(2);
  cout.width(5);
  cout << price << endl;
  cout.unsetf(ios::right);
  cout.unsetf(ios::fixed);
}

} // namespace seneca