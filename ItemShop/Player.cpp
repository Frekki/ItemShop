#include "Player.h"
#include <iostream>


Player::Player()
{
}

void Player::init(std::string name, int money)
{
	_name = name;
	_money = money;
}

void Player::printInventory()
{
	std::cout << "*** " << _name << "'s inventory ***\n\n";
	std::cout << "Money:  " << _money << " GP\n\n";

	std::list<Item>::iterator lit;

	int i = 0;

	for (lit = _items.begin(); lit != _items.end(); lit++)
	{
		std::cout << i << ". " << (*lit).getName() << " x " << (*lit).getCount() << "Price: " << (*lit).getValue() << " GP" << std::endl;
		i++;
	}
}

bool Player::canAffordItem(std::string name, int money)
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

bool Player::removeItem(std::string name, Item &newItem)
{
	std::list<Item>::iterator lit;

	for (lit = _items.begin(); lit != _items.end(); lit++)
	{
		if ((*lit).getName() == name)
		{
			newItem = (*lit);
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

void Player::addItem(Item newItem)
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
