#include "cart.h"
#include "product.h"
#include "customer.h"
#include "checkout.h"
#include <iostream>

using namespace std;

int main() {
    Product cheese = { "Cheese", 100.0, 10, false, true, 0.2 };
    Product biscuits = { "Biscuits", 150.0, 5, false, true, 0.7 };
    Product scratchCard = { "Scratch Card", 50.0, 100, false, false, 0.0 };

    Customer customer = { "John", 500.0 };

    // Test Case 1
    cout << "=== Test Case 1 ===" << endl;
    Cart cart1;
    cart1.add(&cheese, 2);
    cart1.add(&biscuits, 1);
    cart1.add(&scratchCard, 1);
    checkout(customer, cart1);
    cout << endl;

    // Test Case 2: Empty cart
    cout << "=== Test Case 2 ===" << endl;
    Cart cart2;
    checkout(customer, cart2);
    cout << endl;

    // Test Case 3: Expired product
    Product expiredMilk = { "Milk", 80.0, 5, true, true, 1.0 };
    Cart cart3;
    cart3.add(&expiredMilk, 1);
    checkout(customer, cart3);
    cout << endl;


    // Test Case 4: Insufficient balance
    cout << "=== Test Case 4 ===" << endl;  // Added newline and header
    Product tv = { "TV", 1000.0, 2, false, true, 15.0 };
    Cart cart4;
    cart4.add(&tv, 1);
    checkout(customer, cart4);

    return 0;
}