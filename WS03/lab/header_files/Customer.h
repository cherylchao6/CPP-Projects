#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Car.h"
namespace seneca {
class Customer {
private:
  int m_id;
  char *m_name;
  // not dynamically allocated.
  // a pointer to be set to the address of a "Car" object.
  // it need use const so that the set could set the car* to it
  const Car *m_car;

public:
  int PRINT_WIDTH = 35;
  bool isEmpty() const;
  void setEmpty();
  void deallocateMemory();
  void set(int customerId, const char *name, const Car *car);
  void display() const;
  const Car &car() const;
};

} // namespace seneca

#endif