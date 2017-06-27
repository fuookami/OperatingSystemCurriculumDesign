//
// Created by fuookami on 17-6-27.
//

#pragma once
#include <string>
#include <memory>

class Data
{
 public:
  DataValue();
  DataValue(const std::string &str);
  DataValue(const int i);
  DataValue(const double d);
  ~DataValue();

  inline bool isNull(void) const;

  int toInteger(void) const;
  double toDouble(void) const;
  std::string &toString(void) const;

  void set(const int i);
  void set(const double d);
  void set(const std::string &toString) const;

 private:
  static enum
  {
	Int,
	Double,
	String,
  };
  bool null;
  unsigned int currType;

  union value
  {
    int i;
    double d;
	std::shared_ptr<std::string> str;
  };
};