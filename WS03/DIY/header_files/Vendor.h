#ifndef SENECA_VENDOR_H
#define SENECA_VENDOR_H
#include "Icecream.h"

namespace seneca {
class Vendor {
  Icecream *m_icecream;
  int m_orderNum;
  double m_orderTotalPrice;

public:
  void setEmpty();
  void takeOrders();
  void displayOrders();
  void clearData();
  void displayWelcomeMessage();
  void getInt(int *num);
};
} // namespace seneca

#endif