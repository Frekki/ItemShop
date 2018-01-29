#pragma once
#include <string>
#include <list>
#include "Item.h"

class Shop
{
public:
	Shop(std::string, int);

	void printShop();
	bool canAffordItem(std::string, int);
	bool purchaseItem(std::string, Item&);
	void addItem(Item);

	void addMoney(int money) { _money += money; }

	// Getters
	std::string getName() { return _name; }
	int getMoney() { return _money; }

private:
	std::string _name;
	std::list <Item> _items;
	int _money;
};

