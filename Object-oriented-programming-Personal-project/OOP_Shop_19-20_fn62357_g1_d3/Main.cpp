#include "Store.h"
#include "User.h"
#include "Cart.h"
#include<iostream>


int main()
{
	User activeUser;
	std::cout << "Login: " << std::endl;
	activeUser.input();
	// functionality:
	std::cout << "\nFunctionality:\nA\tAdd new product to store\nX\tDelete product\nC\tChange product\nD\tDisplay products\nQ\tQuit\n\n";
	Store s;
	Cart c;
	s.addProduct({ "LZX", 540.50, 12 });
	s.addProduct({ "Flex", 950.50, 1 });
	s.addProduct({ "Vayex",  850.50, 15 });
	s.addProduct({ "Karda", 430.50, 3 });

	while (1)
	{
		char command; 
		std::cin >> command;
		if (command == 'Q')	break;
		switch (command)
		{
			case 'A':
			{
				std::cout << "Add product to store: " << std::endl;

				char* brand = new char[32];
				std::cout << "brand: ";
				std::cin.ignore();
				std::cin.getline(brand, 32);

				float price;
				std::cout << "price: ";
				std::cin >> price;
				std::cin.ignore();

				unsigned int count;
				std::cout << "count: ";
				std::cin >> count;
				std::cin.ignore();

				Product p(brand, price, count);
				s.addProduct(p);
				std::cout << "New product added\n";
				break;
			}
			case 'X':
			{
				std::cout << "Remove product at index: ";

				size_t index;
				std::cin >> index;
				bool isRemoved = s.removeProduct(index);
				if (isRemoved) std::cout << "Product at index " << index << " removed." << std::endl;
				else std::cout << "You did't removed anything. Index out of range." << std::endl;
				break;
			}
			case 'C':
			{
				int index;
				std::cout << "Which product do you want to change?\n";
				std::cin >> index;
				std::cin.ignore();

				char* brand = new char[32];
				std::cout << "brand: ";
				std::cin.getline(brand, 32);

				float price;
				std::cout << "price:";
				std::cin >> price;
				std::cin.ignore();

				unsigned int count;
				std::cout << "count:";
				std::cin >> count;
				std::cin.ignore();

				Product m(brand, price, count);

				s.changeProduct(index, m);
				delete[] brand;
				break;
			}
			case 'D':
			{
				std::cout << "Printing all products: " << std::endl;

				s.printStore();
				break;
			}
			case 'M':
			{
				std::cout << "Functionality:\nA\tAdd new product\nX\tDelete product\nC\tChange product\nD\tDisplay products\nQ\tQuit\n\n";
				break;
			}
			case 'AC':
			{
				
				char* brand = new char[32];
				std::cout << "brand: ";
				std::cin.ignore();
				std::cin.getline(brand, 32);

				float price;
				std::cout << "price: ";
				std::cin >> price;
				std::cin.ignore();

				unsigned int count;
				std::cout << "count: ";
				std::cin >> count;
				std::cin.ignore();
				
				Product p(brand, price, count);
				
				c.addToCart(p);
				std::cout << "New product added\n";
				break;
			}
			case ' ':
			case '\n':
				break;
			default:
				std::cout << "invalid command" << std::endl;
			}
	}
}