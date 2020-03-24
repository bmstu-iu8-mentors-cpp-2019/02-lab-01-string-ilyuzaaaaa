// Copyright 2020 Yangirova Ilyuza ilyuza.yangirova@gmail.com

#include <cstring>
#include <iostream>

#include "string.hpp"
using std::cin;
using std::cout;
size_t String::num_strings = 0;

String::String(const char* s) {
  len = std::strlen(s);
  Data = new char[len + 1];
  std::strcpy(Data, s);
  num_strings++;
}
String::String() {
    len = 0;
  Data = new char[1];
  Data[0] = '\0';
  num_strings++;
}
String::String(const String& st) {
  num_strings++;
  len = st.len;
  Data = new char[len + 1];
  std::strcpy(Data, st.Data);
}
String::~String() {
  --num_strings;
  delete[] Data;
}
std::ostream& operator<<(std::ostream& os, const String& st) {
  os << st.Data;
  return os;
}

String& String::operator=(const String& st) {
  if (this == &st) return *this;
  delete[] Data;
  len = st.len;
  Data = new char[len + 1];
  std::strcpy(Data, st.Data);
  return *this;
}

String& String::operator+=(const String& rhs) {
  len += rhs.len;
  char* s = new char[len + 1];
  strcat(strcpy(s, Data), rhs.Data);
  delete[] Data;
  Data = s;
  return *this;
}
String& String::operator*=(unsigned int m) {
    char* temp = new char [std::strlen(Data)];
    std::strcpy(temp, Data);
    Data = new char [strlen(temp)*m +1];
  for (unsigned int i = 0; i < m; i++) {
    strcat(Data, temp);
  }
  return *this;
}

char& String::operator[](size_t index) { return Data[index]; }
const char& String::operator[](size_t index) const { return Data[index]; }
size_t String::Size() const { return len; }
bool String::Empty() const { return (Size() == 0); }
void String::Replace(char oldSymbol, char newSymbol) {
  for (size_t i = 0; i < len; i++) {
    if (Data[i] == oldSymbol) {
      Data[i] = newSymbol;
    }
  }
}
void String::swap(String& oth) { std::swap(Data, oth.Data); }

String operator*(const String& a, unsigned int b) {
  String s = a;
  s*=b;
  return s;
}

bool String::operator<(const String& rhs) const {
  return std::strcmp(Data, rhs.Data) < 0;
}
size_t String::Find(const String& substr) const {
  bool flag = false;
  size_t index = 0;
  for (size_t i = 0; i < len; ++i) {
    if (Data[i] == substr.Data[0]) {
      flag = true;
      index = i;
      for (size_t j = 1; j < substr.len && i + j < len; ++j) {
        if (Data[i + j] == substr.Data[j]) {
          flag = true;
        } else {
          flag = false;
          break;
        }
      }
    }
    if (flag) {
      return index;
    }
  }
  return -1;
}

void String::RTrim(const char& symbol) {
  size_t countOfTrim = 0;
  for (int i = static_cast<int>(len) - 1; i >= 0; --i) {
    if (Data[i] == symbol) {
      ++countOfTrim;
    } else {
      break;
    }
  }
  char* tempArray = new char[len - countOfTrim + 1];
  std::copy(Data, Data + len - countOfTrim, tempArray);
  tempArray[std::strlen(tempArray)] = '\0';
  //cout << String(tempArray);
  //delete[] Data;
  Data = tempArray;
  len = std::strlen(tempArray);
}

void String::LTrim(const char& symbol) {
  size_t countOfTrim = 0;
  for (size_t i = 0; i < len; ++i) {
    if (Data[i] == symbol) {
      ++countOfTrim;
    } else {
      break;
    }
  }
  char* tempArray = new char[(len - countOfTrim) + 1];
  std::copy(Data + countOfTrim, Data + len + 1, tempArray);
    tempArray[std::strlen(tempArray)] = '\0';
  delete[] Data;
  Data = tempArray;
  len = std::strlen(tempArray);
}
bool operator==(const String& st1, const String& st2) {
  return (std::strcmp(st1.Data, st2.Data) == 0);
}
bool operator!=(const String& st1, const String& st2) { return !(st1 == st2); }
String operator+(const String& lhs, const String& rhs) {
  String ts = lhs;
  return ts += rhs;
}
