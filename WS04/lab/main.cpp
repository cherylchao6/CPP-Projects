/***********************************************************************
// OOP244 Workshop #4 p1: tester program
//
// File	main.cpp
// Version 1.0
// Date: Summer 2023
// Author Michael Huang
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
// Tzu Han Chao
// tchao3@myseneca.ca
// 151593225
// 2024.02.05
// I have done all the coding by myself and only copied the code that my
// professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include "Fridge.h"
#include <iostream>
using namespace std;
using namespace seneca;

const int linelen = 30;

void printDivider(size_t cnt = linelen) {
  for (auto i = 0u; i < cnt; ++i)
    std::cout << "*";
  std::cout << std::endl;
}

void printHeader(const char *head) {
  std::cout << std::endl;
  printDivider(linelen);
  std::cout << head << std::endl;
  printDivider(linelen);
}

int main() {
  printHeader("Empty Fridge");
  Fridge fr;
  fr.display();
  printDivider();

  printHeader("Non Empty Fridge");
  Food fo[2]{Food{"Apples", 4}, Food{"Milk", 5}};
  Fridge frfr(fo, 2);
  printDivider();

  printHeader("Filling Empty Fridge");
  fr.changeModel("So Cold");
  bool act = fr.addFood(Food{"Brocolli", 10});
  if (act)
    fr.display();
  else
    cout << "Failed to add food (incorrect)" << endl;
  printDivider();

  printHeader("Full Fridge");
  frfr.addFood(Food{"Eggs", 3});
  frfr.addFood(Food{"Yogurt", 3});
  frfr.display();
  bool full = frfr.fullFridge();
  if (full)
    frfr.display();
  else
    cout << "Fridge isn't full (incorrect)" << endl;
  printDivider();

  printHeader("Find Food");
  bool found = fr.findFood("Brocolli");
  bool notfound = fr.findFood("Eggs");
  if (found)
    cout << "Found Brocolli (correct)" << endl;
  if (!notfound)
    cout << "No Eggs here (correct)" << endl;
  printDivider();
}
