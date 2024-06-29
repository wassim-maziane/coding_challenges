#include <bits/stdc++.h>
#include <clocale>
#include <cstdio>
#include <cwchar>
#include <fstream>
#include <iostream>
#include <stdexcept>
using namespace std;
streamsize byteCount(string filename) {
  if (filename == "") {
    FILE *fp = stdin;
    int count = 0;
    char chr = fgetc(fp);
    while (chr != EOF) {
      count++;
      chr = fgetc(fp);
    }
    return count;
  } else {
    ifstream file;
    streamsize size;
    file.open(filename, ios::in | ios::binary | ios::ate);
    if (file.is_open()) {
      size = file.tellg();
      file.close();
      return size;
    } else
      return -1;
  }
}

int characterCount(string filename) {
  ifstream file;
  char countingObject;
  int count = 0;
  file.open(filename);
  if (file.is_open()) {
    while (file.get(countingObject))
      count++;
    file.close();
    return count;
  } else
    return -1;
}

int wideCharacterCount(string filename) {
  setlocale(LC_CTYPE, "C.utf8");
  FILE *fp = (filename != "") ? fopen(filename.c_str(), "r") : stdin;
  int count = 0;
  wchar_t countingObject;
  if (fp == NULL)
    return -1;
  else {
    countingObject = fgetwc(fp);
    while (countingObject != WEOF) {
      count++;
      countingObject = fgetwc(fp);
    }
    fclose(fp);
    return count;
  }
}

int wordCount(string filename) {
  string countingObject;
  if (filename == "") {
    int count = 0;
    while (cin >> countingObject)
      count++;
    return count;
  } else {
    ifstream file;
    int count = 0;
    file.open(filename);
    if (file.is_open()) {
      while (file >> countingObject)
        count++;
      file.close();
      return count;
    } else
      return -1;
  }
}

int lineCount(string filename) {
  if (filename == "") {
    int count = 0;
    string countingObject;
    while (getline(cin, countingObject))
      count++;
    return count;
  } else {
    ifstream file;
    string countingObject;
    int count = 0;
    file.open(filename);
    if (file.is_open()) {
      while (getline(file, countingObject))
        count++;
      file.close();
      return count;
    } else
      return -1;
  }
}

int main(int argc, char *argv[]) {
  vector<string> args(argv, argv + argc);
  set<char> flags = {'c', 'w', 'l', 'm'};
  string filename;
  int WCount, LCount, CCount;
  streamsize size;
  try {
    filename = args.at(1);
  } catch (const out_of_range &e) {
    filename = "";
  }
  if (argc <= 2 && filename[0] != '-') {
    WCount = wordCount(filename);
    LCount = lineCount(filename);
    size = byteCount(filename);
    if (size == -1 || WCount == -1 || LCount == -1) {
      {
        cout << "Failed to open file" << '\n';
        return -1;
      }
    } else {
      cout << LCount << ' ' << WCount << ' ' << size << ' ' << filename << '\n';
      return 0;
    }
  }

  if (argc > 3) {
    cerr << "Usage : wctool [flag] <filename>" << '\n';
    return 1;
  }
  try {
    filename = args.at(2);
  } catch (const out_of_range &e) {
    filename = "";
  }
  switch (args[1][1]) {
  case 'c': {
    size = byteCount(filename);
    if (size != -1) {
      cout << size << ' ' << filename << '\n';
      return 0;
    } else {
      cout << "Failed to open file" << '\n';
      return 1;
    }
    break;
  }
  case 'l': {
    LCount = lineCount(filename);
    if (LCount != -1) {
      cout << LCount << ' ' << filename << '\n';
      return 0;
    } else {
      cout << "Failed to open file" << '\n';
      return 1;
    }
    break;
  }
  case 'w': {
    WCount = wordCount(filename);
    if (WCount != -1) {
      cout << WCount << ' ' << filename << '\n';
      return 0;
    } else {
      cout << "Failed to open file" << '\n';
      return 1;
    }
    break;
  }
  case 'm': {
    CCount = wideCharacterCount(filename);
    if (CCount != -1) {
      cout << CCount << ' ' << filename << '\n';
      return 0;
    } else {
      cout << "Failed to open file" << '\n';
      return 1;
    }
    break;
  }
  default:
    cout << "Valid Flags : \n"
         << "\t-c : byte count \n"
         << "\t-l : line count \n"
         << "\t-w : word count \n"
         << "\t-m : character count \n";
    break;
  }
}
