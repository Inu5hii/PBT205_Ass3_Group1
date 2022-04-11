#pragma once

#include "textpixels_enums.h"
#include "textpixels.h"

using namespace std;
using namespace textpixels;

class Stocks
{
private:
	string username;
	int buyer;
	int seller;
	int Quantity = 100; // quantity is a fixed number 
	double price; // input byt the buy or seller

public:
	Stocks();
	Stocks(string username, int buyer, int seller, double price);

	void price(int Quantity);
	void buying(string username, int buyer, double price);
	void selling(string username, int seller, double price);
};

