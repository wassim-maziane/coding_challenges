#include <bits/stdc++.h>
int main(int argc, char *argv[]) {
  using namespace std;
  set<char> flags = {'c', 'w'};
  ifstream file;
  string filename;
  string word;
  int wordCount = 0;

  if (argc != 3 || argv[1][0] != '-' || flags.find(argv[1][1]) == flags.end()) {
    cerr << "Usage : wctool [flag] filename" << '\n';
    return 1;
  }

  filename = argv[2];
  switch (argv[1][1]) {
  case 'c': {
    file.open(filename, ios::in | ios::binary | ios::ate);
    if (file.is_open())
      cout << file.tellg() << ' ' << filename << '\n';
    else {
      cout << "Failed to open file" << '\n';
      return 1;
    }
  }
  case 'w': {
    file.open(filename);
    if (file.is_open()) {
      while (file >> word)
        wordCount++;
    } else {
      cout << "Failed to open file" << '\n';
      return 1;
    }
  }
  }
}
