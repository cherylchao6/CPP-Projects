#include "Vendor.h"
#include <iostream>
using namespace std;
#define TAX_RATE 0.13

namespace seneca {

void Vendor::setEmpty() {
  m_icecream = nullptr;
  m_orderNum = 0;
  m_orderTotalPrice = 0;
};

void Vendor::clearData() {
  if (m_icecream != nullptr) {
    delete[] m_icecream;
    m_icecream = nullptr;
  }
}

void Vendor::takeOrders() {
  displayWelcomeMessage();
  cout << "How many Icecreams?" << endl;
  cout << "> ";
  getInt(&m_orderNum);
  m_icecream = new Icecream[m_orderNum];
  for (int i = 0; i < m_orderNum; i++) {
    cout << "Order number " << i + 1 << ":" << endl;
    m_icecream[i].getOrder();
    m_orderTotalPrice += m_icecream[i].m_totalPrice;
  }
}

void Vendor::displayWelcomeMessage() {
  cout << "Seneca Icecream shop" << endl;
  cout << "          @" << endl;
  cout << "        (' .)" << endl;
  cout << "       (*.`. )" << endl;
  cout << "        \\###/" << endl;
  cout << "         \\#/" << endl;
  cout << "          V" << endl;
}

void Vendor::getInt(int *num) {
  cin >> *num;
  while (cin.fail()) {
    cin.clear();
    cin.ignore(12000, '\n');
    cin >> *num;
  }
  cin.ignore(12000, '\n');
}

void Vendor::displayOrders() {
  cout << endl;
  cout << "********** Order Summary **********" << endl;
  for (int i = 0; i < m_orderNum; i++) {
    cout << "Order No: " << i + 1 << ":" << endl;
    m_icecream[i].printOrder();
    if (i < m_orderNum - 1) {
      cout << endl;
    }
  }

  cout << "-----------------------------------" << endl;
  // Order total price
  cout.setf(ios::left);
  cout.width(30);
  cout << "Price:";
  printPriceFormat(m_orderTotalPrice);

  // tax
  double tax = m_orderTotalPrice * TAX_RATE;
  cout.setf(ios::left);
  cout.width(30);
  cout << "Tax:";
  printPriceFormat(tax);

  // after tax total
  cout.setf(ios::left);
  cout.width(30);
  cout << "Total Price ($):";
  printPriceFormat(m_orderTotalPrice + tax);
};
} // namespace seneca