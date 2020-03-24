// Copyright 2020 Yangirova Ilyuza ilyuza.yangirova@gmail.com

#ifndef INCLUDE_STRING_HPP_
#define INCLUDE_STRING_HPP_

#include<iostream>
#include <utility>
class String {
 private:
  char *Data;
  size_t len;
  static size_t num_strings;

 public:
  ~String();
  String();
  String(const String & rhs);
  explicit String(const char *data);
  String & operator=(const String & rhs);
  String & operator+=(const String& rhs);
  String& operator*=(unsigned int m);
  friend bool operator==(const String &st, const String &st2);
  bool operator<(const String &rhs) const;
  friend bool operator>(const String &st1, const String &st2);
  size_t Find(const String& substr) const;
  void Replace(char oldSymbol, char newSymbol);
  size_t Size() const;
  bool Empty() const;
  const char & operator [](size_t index) const;
  char & operator[](size_t index);
  void RTrim(const char& symbol);
  void LTrim(const char&symbol);
  void swap(String& oth);
  friend std::ostream&operator <<(std::ostream & os, const String & st);
  friend bool operator!=(const String& st1, const String& st2);
  friend String operator+(const String&, const String&);
  friend String operator*(const String& a, unsigned int b);
};
#endif  // INCLUDE_STRING_HPP_
