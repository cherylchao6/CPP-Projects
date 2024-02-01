#define _CRT_SECURE_NO_WARNINGS
#include "Room.h"
#include <cstring>
#include <iostream>
using namespace std;

namespace seneca {
// sets the Room by allocating a dynamic array of guests and setting the room
// number
// (no validation is done for room number)
void set(Room &room, int numberOfGuests, const char *roomNumber) {
  room.m_guests = nullptr;
  if (roomNumber != nullptr && numberOfGuests > 0 && roomNumber[0] != '\0') {
    strcpy(room.m_roomNumber, roomNumber);
    room.m_noOfGuests = numberOfGuests;
    // initialize the guests
    room.m_guests = new Guest[numberOfGuests];
    for (int i = 0; i < numberOfGuests; ++i) {
      room.m_guests[i].m_firstName = nullptr;
      room.m_guests[i].m_lastName = nullptr;
      room.m_guests[i].m_adult = false;
    }
  }
}

// Prints the room number and names of the guests in the following lines with
// four spaces of indentaion See correct_output.txt for the exact format
void print(const Room &room) {
  if (room.m_guests == nullptr) {
    cout << "Empty Room!" << endl;
  } else {
    cout << "Room Number: " << room.m_roomNumber << endl;
    for (int i = 0; i < room.m_noOfGuests; i++) {
      cout << "    ";
      print(room.m_guests[i]);
    }
  }
};

// Books a room by receiving the room number, number of guests and the guest
// information. See correct_output.txt for the exact format
// Room number: A1010
// Number of guests: 2
// 1:
// Name: Jane
// Lastname: Doe
// Age: 30
// 2:
// Name: Jake
// Lastname: Doe
// Age: 10
void book(Room &room) {
  char roomNumber[6];
  int numberOfGuests;
  cout << "Room number: ";
  cin.getline(roomNumber, 6);
  cout << "Number of guests: ";
  cin >> numberOfGuests;
  cin.ignore(1000, '\n');
  set(room, numberOfGuests, roomNumber);
  for (int i = 0; i < numberOfGuests; i++) {
    cout << i + 1 << ":" << endl;
    book(room.m_guests[i]);
  }
};

// vacates the room by dallocating all the memory used.
void vacate(Room &room) {
  if (room.m_guests != nullptr) {
    for (int i = 0; i < room.m_noOfGuests; i++) {
      vacate(room.m_guests[i]);
    }
    delete[] room.m_guests;
    room.m_guests = nullptr;
    room.m_noOfGuests = 0;
    room.m_roomNumber[0] = '\0';
  }
}

} // namespace seneca