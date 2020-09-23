#include "Store.h"
#include<iostream>
#include<limits>


void printMenuAdmin()
{
	cout << endl;
	cout << " -----------------------------------" << endl;
	cout << " -------     MENU ADMIN      -------" << endl;
	cout << " -----------------------------------" << endl;
	cout << " | 1. Add new product to the shop  |" << endl;
	cout << " | 2. Add new product to the cart  |" << endl;
	cout << " | 3. Change product in the shop   |" << endl;
	cout << " | 4. Delete product from the shop |" << endl;
	cout << " | 5. Delete product from the cart |" << endl;
	cout << " | 6. Print products in the shop   |" << endl;
	cout << " | 7. Print products in the cart   |" << endl;
	cout << " | 8. Back to main menu            |" << endl;
	cout << " -----------------------------------" << endl;
	cout << endl;
}

void printMenuUser()
{
	cout << endl;
	cout << " -----------------------------------" << endl;
	cout << " -------      MENU USER      -------" << endl;
	cout << " -----------------------------------" << endl;
	cout << " | 1. Add new product to the cart  |" << endl;
	cout << " | 2. Delete product from the cart |" << endl;
	cout << " | 3. Print products in the shop   |" << endl;
	cout << " | 4. Print products in the cart   |" << endl;
	cout << " | 5. Filtering by price           |" << endl;
	cout << " | 6. Back to main menu            |" << endl;
	cout << " -----------------------------------" << endl;
	cout << endl;
}

void printMenuEmployee()
{
	cout << endl;
	cout << " -----------------------------------" << endl;
	cout << " -------    MENU EMPLOYEE    -------" << endl;
	cout << " -----------------------------------" << endl;
	cout << " | 1. Add new product to the shop  |" << endl;
	cout << " | 2. Change product in the shop   |" << endl;
	cout << " | 3. Delete product from the shop |" << endl;
	cout << " | 4. Print products in the shop   |" << endl;
	cout << " | 5. Back to main menu            |" << endl;
	cout << " -----------------------------------" << endl;
	cout << endl;
}

void printMainMenu()
{
	cout << endl;
	cout << " -----------------------------------" << endl;
	cout << " -------      MAIN MENU      -------" << endl;
	cout << " -----------------------------------" << endl << endl;
	cout << "Choose a type of user: \n1. Employee \n2. User \n3. Admin \n4. Quit \n" << endl;
}

void Login()
{
	cout << endl;
	cout << " -----------------------------------" << endl;
	cout << " -------        LOGIN        -------" << endl;
	cout << " -----------------------------------" << endl << endl;
	string username;
	string password;
	cout << " Username: ";
	cin >> username;
	cout << " Password: ";
	cin >> password;
}
 
int main()
{
	cout << endl << " $ Welcome in the best Fitness store! $" << endl;
	Store store;
	int option1;
	int option2;
	
	do
	{
		printMainMenu();
		cout << "Choose an option: ";
	
		while (!(cin >> option1)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Try again: ";
		}


		if (option1 == 2)
		{
			Login();
			do
			{
				printMenuUser();
				cout << "Choose an option: ";

				while (!(cin >> option2)) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid input. Try again: ";
				}

				switch (option2)
				{
					case 1:
						store.addToCart();
						break;
					case 2:
						store.removeFromCart();
						break;
					case 3:
						store.printStore();
						break;
					case 4:
						store.printCart();
						break;
					case 5:
						int min, max;
						cout << endl << "Lower price: ";
						cin >> min;
						cout << "Higher price: ";
						cin >> max;
						store.filterByPrice(min, max);
						break;
					case 6: break;
					default:
						cout << "Wrong option!" << endl;
				}
			} while (option2 != 6);
		}
		else if (option1 == 1)
		{
			Login();
			do
			{
				printMenuEmployee();
				cout << "Choose an option: ";
				
				while (!(cin >> option2)) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid input. Try again: ";
				}


				switch (option2)
				{
				case 1:
					store.add();
					break;
				case 2:
					store.change();
					break;
				case 3:
					store.remove();
					break;
				case 4:
					store.printStore();
					break;
				case 5: break;
				default:
					cout << "Wrong option!" << endl;
				}
			} while (option2 != 5);
		}
		else if (option1 == 3)
		{
			Login();
			do
			{
				printMenuAdmin();
				cout << "Choose an option: ";

				while (!(cin >> option2)) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid input. Try again: ";
				}

			
				switch (option2)
				{
				case 1:
					store.add();
					break;
				case 2:
					store.addToCart();
					break;
				case 3:
					store.change();
					break;
				case 4:
					store.remove();
					break;
				case 5:
					store.removeFromCart();
					break;
				case 6:
					store.printStore();
					break;
				case 7:
					store.printCart();
					break;
				case 8: break;
				default:
					cout << "Wrong option!" << endl;
				}
			} while (option2 != 8);
		}
		else if (option1 == 4)
		{
			cout << endl << " Have a nice day :)" << endl;
		}
		else 
		{
			cout << "\nTry again! " << endl;
		}


	} while (option1 != 4);
		
	system("pause");
	return 0;

}




/*
int main()
{
	// functionality:
	std::cout << "\nFunctionality:\n " <<
		"A\tAdd new product to store\n"
		"X\tDelete product\n" <<
		"C\tChange product\n" <<
		"D\tDisplay products\n" <<
		"Q\tQuit\n\n";
	Store s;
	Cart c;


	while (1)
	{
		cout << "Choose an option: ";
		char command;
		cin >> command;
		if (command == 'Q')	break;
		switch (command)
		{
			case 'A':
			{
				std::cout << "1. Nutritional Supplement /n2. Outdoor equipment /n3. Stenght fitness equipment /n4. Treadmill /n/nChoose a type of product:" << std::endl;

				int type;
				cin >> type;

				string brand;
				cout << "brand: ";
				cin >> brand;

				double price;
				cout << "price: ";
				cin >> price;

				int count;
				cout << "count: ";
				cin >> count;
				switch (type)
				{

					case 1:
						string expirationDate;
						cin >> expirationDate;

						string ingredients;
						cin >> ingredients;

						double weight;
						cin >> weight;
						NutritionalSupplement one(brand, price, count, expirationDate, ingredients, weight);
						break;
					case 2:

				}


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
}*/
