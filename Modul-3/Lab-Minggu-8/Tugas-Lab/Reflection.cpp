#include <iostream>
#include <string>

struct Product {
    std::string name;
    double price;
    int quantity;
};

void displayInventory(Product arr[], int n) {
    double totalValue = 0;
    for (int i = 0; i < n; i++) {
        double productValue = arr[i].price * arr[i].quantity;
        totalValue += productValue;
        std::cout << arr[i].name << " | Price: $" << arr[i].price 
                  << " | Qty: " << arr[i].quantity 
                  << " | Total: $" << productValue << std::endl;
    }
    std::cout << "Total Inventory Value: $" << totalValue << std::endl;
}

int main() {
    Product store[3] = {
        {"Laptop", 800.0, 5},
        {"Mouse", 25.0, 20},
        {"Keyboard", 50.0, 10}
    };
    displayInventory(store, 3);
    return 0;
}