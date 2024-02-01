#define _CRT_SECURE_NO_WARNINGS
#include "Guest.h"
#include <cstring>
#include <iostream>
using namespace std;

namespace seneca {
// sets the Guest variables and sets the m_adult flag to true if the age is
// greater than or equal to 18
void set(Guest &guest, const char *first, const char *last, int age) {
  // validate empty strings and negative age
  guest.m_firstName = nullptr;
  guest.m_lastName = nullptr;
  if (first != nullptr && last != nullptr && age > 0 && first[0] != '\0' &&
      last[0] != '\0') {
    guest.m_firstName = new char[strlen(first) + 1];
    strcpy(guest.m_firstName, first);
    guest.m_lastName = new char[strlen(last) + 1];
    strcpy(guest.m_lastName, last);
    guest.m_adult = age >= 18;
  }
}

void print(const Guest &guest) {
  if (guest.m_firstName == nullptr || guest.m_lastName == nullptr) {
    cout << "Vacated!" << endl;
  } else {
    cout << guest.m_firstName << " " << guest.m_lastName;
    if (!guest.m_adult) {
      cout << "(Child)";
    }
    cout << endl;
  }
}

// books the guest information from the console:
// Name: Jake<ENTER>
// Lastname: Doe<ENTER>
// Age: 10<ENTER>
void book(Guest &guest) {
  char firstName[41];
  char lastName[41];
  int age;
  cout << "Name: ";
  cin.getline(firstName, 41);
  cout << "Lastname: ";
  cin.getline(lastName, 41);
  cout << "Age: ";
  cin >> age;
  // clear the buffer
  cin.ignore(1000, '\n');
  set(guest, firstName, lastName, age);
}
// vacates the guest by dallocating its memory.
void vacate(Guest &guest) {
  if (guest.m_firstName != nullptr) {
    delete[] guest.m_firstName;
    guest.m_firstName = nullptr;
  }
  if (guest.m_lastName != nullptr) {
    delete[] guest.m_lastName;
    guest.m_lastName = nullptr;
  }
}

} // namespace seneca