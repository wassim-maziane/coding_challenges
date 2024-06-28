#include <clocale>
#include <cwchar>
#include <fstream>
#include <iostream>
using namespace std;
int main() {
  setlocale(LC_CTYPE, "C.utf8");
  int count = 0;
  FILE *fp = fopen("test.txt", "r");
  wchar_t ch = fgetwc(fp);
  while (ch != WEOF) {
    count++;
    ch = fgetwc(fp);
  }
  cout << count;
}
