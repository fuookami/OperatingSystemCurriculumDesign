//
// Created by fuookami on 17-6-27.
//

#include "Data.h"

Data::Data()
	: null(true), currType(None)
{
	val.i = 0;
}

Data::Data(const int i)
	: null(false), currType(Int)
{
	val.i = i;
}

Data::Data(const double d)
	: null(false), currType(Double)
{
	val.d = d;
}

Data::Data(const std::string &str)
	: null(false), currType(String)
{
	val.str.reset(new std::string(str));
}

Data::Data(const Data &ano)
	: null(ano.null), currType(ano.currType)
{
	init(ano);
}

Data::Data(const Data &&ano)
	: null(ano.null), currType(ano.currType)
{
	init(ano);
}

Data::~Data()
{
	clear();
}

Data& Data::operator=(const Data &ano)
{
	null = ano.null;
	currType = ano.currType;
	init(ano);
	return *this;
}

Data& Data::operator=(const Data &&ano)
{
	null = ano.null;
	currType = ano.currType;
	init(ano);
	return *this;
}

int Data::toInteger() const
{
	return currType == Int ? val.i : 0;
}

double Data::toDouble() const
{
	return currType == Double ? val.d : 0.0;
}

const std::string& Data::toString() const
{
	const static std::string emptyStr("");
	return currType == String ? *val.str : emptyStr;
}

void Data::clear()
{
	if (currType == String)
		val.str.reset(nullptr);

	null = true;
	currType = None;
}

void Data::set(const int i)
{
	clear();
	null = false;
	currType = Int;
	val.i = i;
}

void Data::set(const double d)
{
	clear();
	null = false;
	currType = Double;
	val.d = d;
}

void Data::set(const std::string &str)
{
	clear();
	null = false;
	currType = String;
	val.str.reset(new std::string(str));
}

void Data::init(const Data &ano)
{
	switch (currType)
	{
		case Int:
			set(ano.toInteger());
			break;
		case Double:
			set(ano.toDouble());
			break;
		case String:
			set(ano.toString());
			break;
		default:
			break;
	}
}

void Data::init(const Data &&ano)
{
	switch (currType)
	{
		case Int:
			set(ano.toInteger());
			break;
		case Double:
			set(ano.toDouble());
			break;
		case String:
			val.str = ano.val.str;
			break;
		default:
			break;
	}
}