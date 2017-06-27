//
// Created by fuookami on 17-6-27.
//

#pragma once
#include <vector>
#include <string>
#include <memory>

class Data
{
 private:
  using DataValue = struct value
  {
    int i = 0;
    double d = 0.0;
    std::shared_ptr<std::string> str = nullptr;
  };

  enum
  {
	Int,
	Double,
	String,
    None,
  };

  static const std::vector<std::string> types;

 public:
  Data();
  Data(const std::string &str);
  Data(const int i);
  Data(const double d);
  Data(const Data &ano);
  Data(const Data &&ano);
  ~Data();

  Data &operator=(const Data &ano);
  Data &operator=(const Data &&ano);

  inline bool isNull(void) const;
  inline const std::string &currTypeName(void) const;

  int toInteger(void) const;
  double toDouble(void) const;
  const std::string &toString(void) const;

  void clear();
  void set(const int i);
  void set(const double d);
  void set(const std::string &toString);

 private:
  void init(const Data &ano);
  void init(const Data &&ano);

 private:
  bool null;
  int currType;
  DataValue val;
};

bool Data::isNull() const
{
	return null;
}

const std::string &Data::currTypeName(void) const
{
	return types[currType];
}