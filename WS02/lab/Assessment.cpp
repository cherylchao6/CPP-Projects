#include "Assessment.h"
#include <cstdio>
#include <string.h>

namespace seneca {
// Reads one integer from the fptr file into the value reference and returns
// true if it was successful, otherwise, it will return false
bool read(int &value, FILE *fptr) {
  bool readResult = false;
  if (fptr != nullptr) {
    readResult = fscanf(fptr, "%d\n", &value) == 1;
  }
  return readResult;
}

// Reads one double from the fptr file into the value reference and returns true
// if it was successful, otherwise, it will return false
bool read(double &value, FILE *fptr) {
  bool readResult = false;
  if (fptr != nullptr) {
    readResult = fscanf(fptr, "%lf\n", &value) == 1;
  }
  return readResult;
}

// Skips a comma and then reads a cstring no longer than 60 characters from the
// fptr file into the address, cstr and returns true if it was successful,
// otherwise, it will return false
bool read(char *cstr, FILE *fptr) {
  bool readResult = false;
  if (fptr != nullptr) {
    fscanf(fptr, ",%60[^\n]\n", cstr);
    readResult = true;
  }
  return readResult;
}

bool read(Assessment &assess, FILE *fptr) {
  bool readResult = false;
  if (fptr != nullptr) {
    double mark = 0.0;
    char title[61];
    assess.m_mark = nullptr;
    assess.m_title = nullptr;
    if (read(mark, fptr) && read(title, fptr)) {
      assess.m_mark = new double;
      *assess.m_mark = mark;
      assess.m_title = new char[strlen(title) + 1];
      strcpy(assess.m_title, title);
      readResult = true;
    }
  }
  if (!readResult) {
    delete assess.m_mark;
    delete[] assess.m_title;
  }
  return readResult;
}

void freeMem(Assessment *&aptr, int size) {
  for (int i = 0; i < size; i++) {
    delete aptr[i].m_mark;
    delete[] aptr[i].m_title;
  }
  delete[] aptr;
}

int read(Assessment *&aptr, FILE *fptr) {
  int totalRead = 0;
  int numOfAssessments = 0;
  if (fptr != nullptr) {
    read(numOfAssessments, fptr);
    aptr = new Assessment[numOfAssessments];
    for (int i = 0; i < numOfAssessments; i++) {
      if (!read(aptr[i], fptr)) {
        break;
      } else {
        totalRead++;
      }
    }
  }

  if (totalRead != numOfAssessments) {
    freeMem(aptr, totalRead);
    totalRead = 0;
  }
  return totalRead;
}

} // namespace seneca