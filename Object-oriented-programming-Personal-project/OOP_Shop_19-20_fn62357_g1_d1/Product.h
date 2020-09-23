#pragma once
class Product
{
	char* name = nullptr;
	char* brand = nullptr;
	char* id = nullptr;
	double price;

public:
	Product();
	Product(const char*, const char*, const char*, double);
	Product(const Product&);
	Product& operator=(const Product&);
	~Product();

	//setters
	void setName(const char*);
	void setBrand(const char*);
	void setId(const char*);
	void setPrice(double);

	//getters
	const char* getName() const;
	const char* getBrand() const;
	const char* getId() const;
	double getPrice() const;
};
