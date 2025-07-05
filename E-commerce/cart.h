#pragma once
#include <vector>
#include <iostream>
#include "product.h"
using namespace std;
class CartItem {
public:
	Product* product;
	int quantity;
	CartItem(Product* p, int q);

};
class Cart {
public:
	vector<CartItem> totalCart;
	void add(Product* product, int quantity);
	bool isEmpty();
};
