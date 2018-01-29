#include "Shop.h"
#include <iostream>

Shop::Shop(std::string name, int money)
{
	_name = name;
	_money = money;
}

void Shop::printShop()
{
	std::cout << "*** Welcome to " << _name << " ***\n\n";
	std::cout << "Money:  " << _money << " GP\n\n";
	std::list<Item>::iterator lit;

	int i = 0;

	for (lit = _items.begin(); lit != _items.end(); lit++)
	{
		std::cout << i << ". " << (*lit).getName() << " x " << (*lit).getCount() << std::endl;
		i++;
	}

	std::cout << std::endl;
}

bool Shop::canAffordItem(std::string name, int money)
{
	std::list<Item>::iterator lit;

	for (lit = _items.begin(); lit != _items.end(); lit++)
	{
		if ((*lit).getName() == name)
		{
			if ((*lit).getValue() <= money)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	return false;
}

bool Shop::purchaseItem(std::string name, Item &newItem)
{
	std::list<Item>::iterator lit;

	for (lit = _items.begin(); lit != _items.end(); lit++)
	{
		if ((*lit).getName() == name)
		{
			newItem = (*lit);

			newItem.setCount(1);
			(*lit).removeOne();

			if ((*lit).getCount() == 0)
			{
				_items.erase(lit);
			}
			return true;
		}
	}
	return false;
}

void Shop::addItem(Item newItem)
{
	std::list<Item>::iterator lit;

	for (lit = _items.begin(); lit != _items.end(); lit++)
	{
		if ((*lit).getName() == newItem.getName())
		{
			(*lit).addOne();
			return;
		}
	}

	_items.push_back(newItem);
}