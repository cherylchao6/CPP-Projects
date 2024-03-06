#include "Car.h"
#include <cstring>
#include <iostream>
using namespace std;

namespace seneca {
// Member function to check if the object is in a safe recognizable empty
// state. A car is considered empty if the either "make and model" or
// "service description" is either null or an empty cstring.
bool Car::isEmpty() const {
  return (m_makeModel == nullptr || m_makeModel[0] == '\0' ||
          m_serviceDesc == nullptr || m_serviceDesc[0] == '\0');
}
// Member function sets the object a safe recognizable empty state. setEmpty
// accomplishes this by setting the attributes to empty cstring, nullptr and
// 0.0.
void Car::setEmpty() {
  m_licencePlate[0] = '\0';
  m_makeModel = nullptr;
  m_serviceDesc = nullptr;
  m_cost = {};
};

// Member function to deallocate dynamically allocated memory for "make and
// model" and "service description" member variables.
void Car::deallocateMemory() {
  if (m_makeModel != nullptr) {
    delete[] m_makeModel;
    m_makeModel = nullptr;
  }
  if (m_serviceDesc != nullptr) {
    delete[] m_serviceDesc;
    m_serviceDesc = nullptr;
  }
};

// Member function to Set car information and service details as follows.

// Deallocates existing memory and then sets it to a safe empty state.
// If the incoming information is valid (license plate is not empty and "make
// and model" and "description" are not null and not empty. note: the cost is
// not validated) Copies the corresponding argument to the license plate
// attribute Allocates memory and copies the data for car make and model
// Allocates memory and copies the date for the service description
// Assigns the 'serviceCost' value to the corresponding argument value.
void Car::set(const char plateNo[], const char *carMakeModel,
              const char *serviceDesc, double serviceCost) {
  deallocateMemory();
  setEmpty();
  if (plateNo[0] != '\0' && carMakeModel != nullptr && serviceDesc != nullptr) {
    strcpy(m_licencePlate, plateNo);
    m_makeModel = new char[strlen(carMakeModel) + 1];
    strcpy(m_makeModel, carMakeModel);
    m_serviceDesc = new char[strlen(serviceDesc) + 1];
    strcpy(m_serviceDesc, serviceDesc);
    m_cost = serviceCost;
  }
}

// This function displays the car in the following format:

// The labels of the data are left justified in 15 spaces.
// The data of the attributes are right justified in 20 spaces.
// The cost is displayed with 2 digits after the decimal point.
// License Plate:                  ABC
// Model:                 Toyota Camry
// Service Name:     Engine oil change
// Service Cost:                 50.00
void Car::display() const {

  if (!isEmpty()) {
    string label;

    label = "License Plate:";
    cout << label;
    cout.width(PRINT_WIDTH - label.length());
    cout << right << m_licencePlate << endl;

    label = "Model:";
    cout << label;
    cout.width(PRINT_WIDTH - label.length());
    cout << right << m_makeModel << endl;

    label = "Service Name:";
    cout << label;
    cout.width(PRINT_WIDTH - label.length());
    cout << right << m_serviceDesc << endl;

    label = "Service Cost:";
    cout << label;
    // string costStr = to_string(m_cost);
    // costStr = costStr.substr(0, costStr.find(".") + 3); // 移除额外的0
    // cout.width(PRINT_WIDTH - label.length());
    cout.setf(ios::fixed);
    cout.precision(2);
    cout.width(PRINT_WIDTH - label.length());
    cout << right << m_cost << endl;
  }
}

} // namespace seneca