#include "Customer.h"
#include "cstring"
#include <iostream>
using namespace std;

namespace seneca {
// This query method checks if the object is in a safe empty state. A customer
// is considered empty if the name pointer is null or empty cString or the car
// pointer is null.
bool Customer::isEmpty() const {
  return (m_name == nullptr || m_name[0] == '\0' || m_car == nullptr);
};

// This method sets the customer to a safe empty state by setting the pointers
// to null and the id to 0.
void Customer::setEmpty() {
  m_id = {};
  m_name = nullptr;
  m_car = nullptr;
};

// This Member function deallocates the dynamically allocated memory for the
// m_name member variable.
void Customer::deallocateMemory() {
  if (m_name != nullptr) {
    delete[] m_name;
    m_name = nullptr;
  }
};

// Member function to Set the Customer name, ID and Car.

// Deallocates existing memory and then sets it to a safe empty state.
// If the incoming information is valid (i.e. the name is not null and not empty
// and the Car pointer is not null. The ID is not validated) Copies the
// corresponding argument to the ID attribute Allocates memory and copies the
// data for the name of the customer Assigns the Car pointer attribute to the
// corresponding argument

void Customer::set(int customerId, const char *name, const Car *car) {
  deallocateMemory();
  setEmpty();
  if (name != nullptr && name[0] != '\0' && car != nullptr) {
    m_id = customerId;
    m_name = new char[strlen(name) + 1];
    strcpy(m_name, name);
    // not sure
    m_car = car;
  }
};

// This function displays the Customer in the following format:

// The labels of the data are left justified in 15 spaces.
// The data of the attributes are right justified in 20 spaces. After the
// customer information is printed, the Car will be displayed.
//   Customer ID:                   1005
//   First Name:              Jane Smith
//   License Plate:                  ABC
//   Model:                 Toyota Camry
//   Service Name:     Engine oil change
//   Service Cost:                 50.00
void Customer::display() const {
  string label;
  if (!isEmpty()) {
    label = "Customer ID:";
    cout << label;
    cout.width(PRINT_WIDTH - label.length());
    cout << right << m_id << endl;

    label = "First Name:";
    cout << label;
    cout.width(PRINT_WIDTH - label.length());
    cout << right << m_name << endl;
    car().display();
    // // to visit the member of the pointer
    // // use ->
    // m_car->display();
  } // namespace seneca
};
const Car &Customer::car() const { return *m_car; };
} // namespace seneca