#pragma once
#include <string>

class Item
{
public:
	Item(std::string, int);

	void addOne();
	void removeOne();

	// Gettters
	std::string getName() { return _name; }
	int getValue() { return _value; }
	int getCount() { return _count; }

	// Setters
	void setCount(int count) { _count = count; }

private:
	std::string _name;
	int _value;
	int _count;
};