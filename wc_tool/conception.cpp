#include <clocale>
#include <cwchar>
#include <fstream>
#include <iostream>
using namespace std;
int main() {
  int count = 0;
  wifstream file("test.txt");
  file.imbue(locale("en_US.UTF-8"));
  wchar_t ch;
  while (file >> ch) {
    count++;
  }
  file.close();
  cout << count;
}
