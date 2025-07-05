#include "cart.h"
#include <iostream>
#include <vector>
#include "product.h"

CartItem::CartItem(Product* p, int q) {
    product = p;
    quantity = q;
}

void Cart::add(Product* product, int quantity) {
    if (quantity > product->quantity) {
        cout << "Not enough products in stock for " << product->name << endl;
        return;
    }
    totalCart.push_back(CartItem(product, quantity));
}

bool Cart::isEmpty() {
    return totalCart.empty();
}