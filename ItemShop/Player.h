#pragma once
#include <string>
#include <list>
#include"Item.h"

class Player
{
public:
	Player();

	void init(std::string, int);

	void printInventory();
	bool canAffordItem(std::string, int);

	bool removeItem(std::string, Item&);
	void addItem(Item);

	void addMoney(int money) { _money += money; }

	// Getters
	int getMoney() { return _money; }
	void subtracMoney(int amount) { _money -= amount; }

private:
	std::string _name;
	std::list<Item> _items;
	int _money;
};

