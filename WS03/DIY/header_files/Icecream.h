#ifndef SENECA_ICECREAM_H
#define SENECA_ICECREAM_H
#define SCOOP_PRICE 5.00
#define MAX_SCOOP 3

namespace seneca {
class Icecream {
public:
  Icecream();
  char m_flavour[30];
  bool m_withWafer;
  int m_numScoops;
  double m_scoopPrice;
  double m_flavourPrice;
  double m_withWaferPrice;
  double m_totalPrice;

  void getOrder();
  void printOrder();
  void getInt(int *, int, int);
  void printMenu();
  bool withWafer();
};
void printPriceFormat(double);
} // namespace seneca
#endif