#include "checkout.h"
#include "cart.h"
#include "customer.h"
#include <iostream>
using namespace std;

void checkout(Customer& customer, Cart& cart) {
    if (cart.isEmpty()) {
        cout << "Error: Cart is empty.\n";
        return;
    }

    double subtotal = 0;
    double shippingFee = 0;
    double totalWeight = 0;

    for (const CartItem& item : cart.totalCart) {
        if (item.product->expired) {
            cout << "Error: " << item.product->name << " is expired.\n";
            return;
        }
        subtotal += item.quantity * item.product->price;
        if (item.product->shippable) {
            totalWeight += item.quantity * item.product->weight;
        }
    }

    if (totalWeight > 0) {
        shippingFee = 30;
        cout << "** Shipment notice **\n";
        for (const CartItem& item : cart.totalCart) {
            if (item.product->shippable) {
                cout << item.quantity << "x " << item.product->name
                    << "  " << item.quantity * item.product->weight << "kg\n";
            }
        }
        cout << "Total package weight: " << totalWeight << "kg\n\n";
    }

    double total = subtotal + shippingFee;

    if (customer.balance < total) {
        cout << "Error: Insufficient balance.\n";
        return;
    }

    for (CartItem& item : cart.totalCart) {
        item.product->quantity -= item.quantity;
    }
    customer.balance -= total;

    cout << "** Checkout receipt **\n";
    for (const CartItem& item : cart.totalCart) {
        cout << item.quantity << "x " << item.product->name << "\t"
            << item.quantity * item.product->price << "\n";
    }
    cout << "----------------------\n";
    cout << "Subtotal\t" << subtotal << "\n";
    cout << "Shipping\t" << shippingFee << "\n";
    cout << "----------------------\n";  
    cout << "Total\t\t" << total << "\n";
    cout << "Balance after payment: " << customer.balance << "\n\n";  
}