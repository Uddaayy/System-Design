#include <iostream>
#include <vector>
using namespace std;

class Product {
public:
    int id;
    string name;
    float price;
    int stock;

    Product(int id, string name, float price, int stock) {
        this->id = id;
        this->name = name;
        this->price = price;
        this->stock = stock;
    }

    void display() {
        cout << "ID: " << id << ", Name: " << name
             << ", Price: $" << price << ", Stock: " << stock << endl;
    }
};

class ShoppingCartItem {
public:
    int productId;
    string name;
    float price;
    int quantity;

    ShoppingCartItem(int productId, string name, float price, int quantity) {
        this->productId = productId;
        this->name = name;
        this->price = price;
        this->quantity = quantity;
    }
};

class ShoppingSystem {
private:
    vector<Product> products;
    vector<ShoppingCartItem> cart;

public:
    void addProduct() {
        int id, stock;
        float price;
        string name;
        cout << "Enter Product ID: ";
        cin >> id;
        cout << "Enter Product Name: ";
        cin >> name;
        cout << "Enter Price: ";
        cin >> price;
        cout << "Enter Stock: ";
        cin >> stock;
        products.push_back(Product(id, name, price, stock));
        cout << "Product added successfully.\n";
    }

    void showProducts() {
        if (products.empty()) {
            cout << "No products available.\n";
            return;
        }
        cout << "--- Available Products ---\n";
        for (auto &p : products) {
            p.display();
        }
    }

    void addToCart() {
        int id, qty;
        cout << "Enter Product ID to buy: ";
        cin >> id;
        cout << "Enter Quantity: ";
        cin >> qty;

        for (auto &p : products) {
            if (p.id == id) {
                if (p.stock >= qty) {
                    cart.push_back(ShoppingCartItem(p.id, p.name, p.price, qty));
                    cout << "Added to cart!\n";
                } else {
                    cout << "Insufficient stock.\n";
                }
                return;
            }
        }
        cout << "Product not found.\n";
    }

    void viewCart() {
        if (cart.empty()) {
            cout << "Cart is empty.\n";
            return;
        }

        float total = 0;
        cout << "--- Your Cart ---\n";
        for (auto &item : cart) {
            float cost = item.price * item.quantity;
            cout << item.name << " x " << item.quantity << " = $" << cost << endl;
            total += cost;
        }
        cout << "Total = $" << total << endl;
    }

    void checkout() {
        if (cart.empty()) {
            cout << "Cart is empty. Nothing to checkout.\n";
            return;
        }

        for (auto &item : cart) {
            for (auto &p : products) {
                if (p.id == item.productId) {
                    p.stock -= item.quantity;
                }
            }
        }

        viewCart();
        cart.clear();
        cout << "Checkout complete. Thank you!\n";
    }
};

void showMenu() {
    cout << "\n--- Shopping Menu ---\n";
    cout << "1. Add Product\n";
    cout << "2. View Products\n";
    cout << "3. Add to Cart\n";
    cout << "4. View Cart\n";
    cout << "5. Checkout\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    ShoppingSystem system;
    int choice;

    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1: system.addProduct(); break;
            case 2: system.showProducts(); break;
            case 3: system.addToCart(); break;
            case 4: system.viewCart(); break;
            case 5: system.checkout(); break;
            case 6: cout << "Thank you for visiting!\n"; return 0;
            default: cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
