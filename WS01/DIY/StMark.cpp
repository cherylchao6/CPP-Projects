#include <cmath>
#include <iostream>

#include "StMark.h"
#include "file.h"
#include "graph.h"
#include "io.h"

using namespace std;

namespace seneca {
/// <summary>
/// Tries to open the students' mark data file.
/// If successful it will print a report based on the
/// date in the file.
/// </summary>
/// <param name="filename">, holds the data file name</param>
/// <returns>True if the date files is opened succesfully,
/// otherwise returns false</returns>
bool printReport(const char *filename) {
  bool res = false;

  if (openFile(filename)) {
    int marksGroups[10] = {0};
    StMark marks[MAX_NO_RECS];

    int noOfMarks = readMarks(marks);
    if (noOfMarks > 0) {
      res = true;
      sortStMarks(marks, noOfMarks);
      marksGroup(marksGroups, marks, noOfMarks);
      printGraph(marksGroups, 10, "Students' mark distribution");
      printAllMarks(marks, noOfMarks);
    }

    closeFile();
  }
  return res;
};

// Sorts the array of StMark instances
void sortStMarks(StMark *marks, int size) {
  int i, j;
  StMark temp;
  for (i = 0; i < size - 1; i++) {
    for (j = 0; j < size - i - 1; j++) {
      if (marks[j].mark < marks[j + 1].mark) {
        temp = marks[j];
        marks[j] = marks[j + 1];
        marks[j + 1] = temp;
      }
    }
  }
}

// Groups the marks into 10 groups
void marksGroup(int *marksGroups, StMark marks[], int size) {
  int i;
  int group;
  for (i = 0; i < size; i++) {
    group = static_cast<int>(ceil(marks[i].mark / 10.0));
    if (group == 0)
      group = 1;
    // 100 is in first element
    marksGroups[9 - (group - 1)]++;
  }
}

// prints all the marks
void printAllMarks(StMark *marks, int size) {
  int i;
  for (i = 0; i < size; i++) {
    printInt(i + 1, 3);
    cout << ": [";
    printInt(marks[i].mark, 3);
    cout << "] " << marks[i].name << " " << marks[i].surname << endl;
  };
  cout << "----------------------------------------" << endl;
}
} // namespace seneca
