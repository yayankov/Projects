#include "User.h"
#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS

const int MAX_SIZE = 300; // Default maximum size of dynamic array

User::User()
{
	setUsername("");
	changePassword("");
}

User::User(const User& rhs)
{
	setUsername(rhs.username);
	changePassword(rhs.password);
}

User& User::operator=(const User& rhs)
{
	if (this != &rhs)
	{
		setUsername(rhs.username);
		changePassword(rhs.password);
	}
	return *this;
}

void User::setUsername(const char* newUsername) {
	if (newUsername == nullptr) return;
	int Length = strlen(newUsername);
	char* temp = new char[Length + 1];
	strcpy_s(temp, Length+1, newUsername);
	delete[] username;
	username = temp;
}

void User::changePassword(const char* newPassword) {
	if (newPassword == nullptr) return;
	int Length = strlen(newPassword);
	char* temp = new char[Length + 1];
	strcpy_s(temp, Length + 1, newPassword);
	delete[] password;
	password = temp;
}

const char* User::getUsername() const {
	return this->username;
}

const char* User::getPassword() const {
	return this->password;
}

void User::addToCart() {
	std::cout << "Enter SKU of product from list to add in cart: ";
	int pos;
	std::cin >> pos;
//	cart.add(pos);
}
void User::removeFromCart() {
	std::cout << "Enter number of product in cart to remove from cart: ";
	int pos;
	std::cin >> pos;
//	cart.remove(pos);
}

void User::input()
{
	std::cout << "Enter username:";
	std::cin >> username;
	std::cout << "Enter password:";
	std::cin >> password;
}

User::~User()
{
	delete[] username;
	delete[] password;
}
