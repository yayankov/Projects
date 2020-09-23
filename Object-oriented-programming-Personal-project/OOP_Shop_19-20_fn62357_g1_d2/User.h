#ifndef USER_H
#define USER_H
#include "Cart.h"

#define _CRT_SECURE_NO_WARNINGS

class User {
private:
	char* username = nullptr;
	char* password = nullptr;
//	Cart cart;
public:
	User();
	User(const User&);
	User& operator=(const User&);
	~User();

	//getters
	const char* getUsername() const;
	const char* getPassword() const;

	//setters
	void setUsername(const char* newUsername);
	void changePassword(const char* newPassword);

	void addToCart();
	void removeFromCart();

	void input();

	
};



#endif