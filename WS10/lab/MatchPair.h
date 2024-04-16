/***********************************************************************
// Workshop # 10
//
// File: MatchPair
// Version 1.0
// Date: 2024.04.02
// Author: Tzu Han Chao
// ID: 151593225
// Email: tchao3@myseneca.ca

// I have done all the coding by myself and only copied the code that my
// professor provided to complete my workshops and assignments.
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/
#ifndef MATCH_PAIR_H
#define MATCH_PAIR_H
namespace seneca {
template <typename T1, typename T2> 
struct Pair {
public:
  T1 first;
  T2 second;
};

template <typename T, typename U>
void addDynamicPairElement(Pair<T, U> *&pArray, const T &first, const U &second,
                           int &size) {
  Pair<T, U> *temp = new Pair<T, U>[size + 1];
  for (int k = 0; pArray && k < size; k++) {
    temp[k] = pArray[k];
  }
  temp[size].first = first;
  temp[size].second = second;
  delete[] pArray;
  pArray = temp;
  size++;
}

template <typename T1, typename T2>
Pair<T1, T2> *matches(T1 arr1[], T2 arr2[], int T1Size, int T2Size, int &size) {
  Pair<T1, T2> *ptr = nullptr;
  size = 0;
  for (int i = 0; i < T1Size; i++) {
    for (int j = 0; j < T2Size; j++) {
      if (arr1[i] == arr2[j]) {
        addDynamicPairElement(ptr, arr1[i], arr2[j], size);
      }
    }
  }

  return ptr;
}

template <typename T> void releaseMem(T *ptr) {
  if (ptr != nullptr) {
    delete[] ptr;
    ptr = nullptr;
  }
}
} // namespace seneca

#endif