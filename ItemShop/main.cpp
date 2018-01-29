#include <iostream>
#include <string>
#include"Player.h"
#include"Shop.h"

void initShops(std::list<Shop>&);

void initPlayer(Player&);
void enterShop(Player&, Shop&);

int main()
{
	std::list<Shop> shops;
	std::list<Shop>::iterator lit;
	Player player;
	std::string shopName;

	// Initialize
	initPlayer(player);
	initShops(shops);

	// Tells us when the game is over
	bool isDone = false;
	
	while (isDone == false)
	{
		std::cout << "Shops: \n";
		int i = 1;
		for (lit = shops.begin(); lit != shops.end(); lit++)
		{
			std::cout << i << ". " << (*lit).getName() << std::endl;
			i++;
		}

		std::cout << "\nWhat shop whould you like to enter? ";

		getline(std::cin, shopName);

		std::cout << std::endl;

		bool validShop = false;

		for (lit = shops.begin(); lit != shops.end(); lit++)
		{
			if ((*lit).getName() == shopName)
			{
				enterShop(player, (*lit));
				validShop = true;
			}
		}

		if (validShop == false)
		{
			std::cout << "Invalid Shop!\n";
			system("pause");
		}
	}

	system("pause");
	return 0;
}

void initShops(std::list<Shop> &shops)
{
	shops.push_back(Shop("Bill's Leather Shop", 500));
	shops.back().addItem(Item("Leather Boots", 50));
	shops.back().addItem(Item("Leather Hat", 50));
	shops.back().addItem(Item("Leather Gloves", 50));
	shops.back().addItem(Item("Leather Gauntletss", 50));
	shops.back().addItem(Item("Leather Chestpiece", 100));

	shops.push_back(Shop("The Blacksmith", 1500));
	shops.back().addItem(Item("Iron Boots", 100));
	shops.back().addItem(Item("Iron Hat", 100));
	shops.back().addItem(Item("Iron Gloves", 100));
	shops.back().addItem(Item("Iron Gauntletss", 200));
	shops.back().addItem(Item("Iron Sword", 150));
	shops.back().addItem(Item("Iron Shield", 150));

	shops.push_back(Shop("Beverly's Fruity Fruit Shop", 250));
	shops.back().addItem(Item("Grapes", 5));
	shops.back().addItem(Item("Appkes", 5));
	shops.back().addItem(Item("Orange", 5));
	shops.back().addItem(Item("Watermelon", 10));
	shops.back().addItem(Item("Tomato", 3));
}

void initPlayer(Player &player)
{
	std::cout << "Enter thy name sir knight: ";
	std::string name;
	getline(std::cin, name);
	player.init(name, 100);

	player.addItem(Item("Bronze Sword", 5));
}

void enterShop(Player &player, Shop &shop)
{
	bool isDone = false;
	char input;
	std::string itemName;
	Item newItem("NOITEM", 0);

	while (isDone == false)
	{
		shop.printShop();
		player.printInventory();

		std::cout << "Whould you like to buy or sell? Q to quit. (B/S): ";
		std::cin >> input;
		std::cin.ignore(64, '\n');
		std::cin.clear();

		if (input == 'Q' || input == 'q') return;

		if (input == 'B' || input == 'b') // Buy
		{
			std::cout << "Enter the item you wish to buy: ";
			getline(std::cin, itemName);

			if (shop.canAffordItem(itemName, player.getMoney())) {
				
				if (shop.purchaseItem(itemName, newItem) == true)
				{
					player.addMoney(-newItem.getValue());
					player.addItem(newItem);
					shop.addMoney(newItem.getValue());
				}
				else
				{
					std::cout << "That is an invalid item!\n";
					system("pause");
				}
			}
			else
			{
				std::cout << "You don't have enough money!\n";
				system("pause");
			}
		}
		else // Sell
		{
			std::cout << "Enter the item you wish to sell: ";
			getline(std::cin, itemName);

			if (player.canAffordItem(itemName, shop.getMoney())) {
				if (player.removeItem(itemName, newItem) == true)
				{
					shop.addMoney(-newItem.getValue());
					shop.addItem(newItem);
					player.addMoney(newItem.getValue());
				}				
				else
				{
					std::cout << "That is an invalid item!\n";
					system("pause");
				}
			}
			else
			{
				std::cout << "The shop doesn't have enough money!\n";
				system("pause");
			}
		}
	}
}