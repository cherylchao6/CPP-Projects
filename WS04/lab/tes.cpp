// Trailing Whitespace
// trailing.cpp

#include <iostream>
using namespace std;

// int main() {
//   char str[11];

//   cout << "Enter a string : " << endl;
//   cin >> str;
//   cout << "|" << str << "|" << endl;
// }

// int main() {
//   int attendance = 27;
//   cout << "1234567890" << endl;
//   cout.fill('*');
//   cout.width(10);
//   cout << attendance << endl;
//   cout << attendance << endl;
// }

int main() {
  double pi = 3.141592653;
  cout << "1234567890" << endl;
  cout.width(10);
  cout.setf(ios::fixed);
  cout << pi << endl;
  cout.unsetf(ios::fixed);
  cout << pi << endl;
}

// #include <iostream>
// using namespace std;

// int main() {
//   double pi = 3.141592653;
//   cout << "1234567890" << endl;
//   cout.width(10);
//   cout.setf(ios::fixed);
//   cout << pi << endl;
// }