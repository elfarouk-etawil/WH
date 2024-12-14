#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <vector>
using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;

class Item {
private:
    int m_id;
    string m_name;
    string m_description;
    int m_quantity;
    double m_unitPrice;

public:
    // Constructor
    Item(int id, const string& name, const string& description, const string& category, int quantity, double unitPrice, const string& expiryDate)
        : m_id(id), m_name(name), m_description(description), m_quantity(quantity), m_unitPrice(unitPrice) {}

    // Default Constructor
    Item() : m_id(0), m_name(""), m_description(""), m_quantity(0), m_unitPrice(0.0) {}

    // Getters
    int getId() const { return m_id; }
    string getName() const { return m_name; }
    int getQuantity() const { return m_quantity; }
    double getUnitPrice() const { return m_unitPrice; }

    // Display item details
    void displayItem() const {
        cout << "ID: " << m_id << endl;
        cout << "Name: " << m_name << endl;
        cout << "Description: " << m_description << endl;
        cout << "Quantity: " << m_quantity << endl;
        cout << "Unit Price: " << m_unitPrice << endl;
    }

    void addItemDetails() { // Add item details
        int id;
        cout << "Enter ID: ";
        cin >> id;
        while (id <= 0) {
            cout << "Wrong ID, please enter the right one!" << endl;
            cin >> id;
        }
        m_id = id;

        cin.ignore(); // for a new line
        cout << "Enter item name: ";
        getline(cin, m_name);

        cout << "Enter item description: ";
        getline(cin, m_description);

        // Validate quantity input
        int quantity;
        cout << "Please enter the quantity: ";
        cin >> quantity;
        while (quantity <= 0) {
            cout << "Wrong input, please enter a valid quantity!" << endl;
            cin >> quantity;
        }
        m_quantity = quantity;

        // Validate price input
        double price;
        cout << "Enter unit price: ";
        cin >> price;
        while (price <= 0) {
            cout << "Wrong input, please enter the right price!" << endl;
            cin >> price;
        }
        m_unitPrice = price;

        cout << "Item added successfully!" << endl;
    }
};

class ItemDetails {
private:
    vector<Item> items;

public:
    // Add item to inventory
    void addItem() {
        Item newItem;
        newItem.addItemDetails();
        items.push_back(newItem); // push back to save details and display it
    }

    // Remove item from inventory
    void removeItem() {
        int id;
        cout << "Enter item ID to remove: ";
        cin >> id;

        for (auto it = items.begin(); it != items.end(); ++it) {
            if (it->getId() == id) {
                items.erase(it);
                cout << "Item removed successfully!" << endl;
                return;
            }
        }
        cout << "Item not found!" << endl;
    }

    // Search for an item
    void searchItem() {
        string name;
        cin.ignore();
        cout << "Enter item name to search: ";
        getline(cin, name);

        bool found = false;
        for (const auto& item : items) {
            if (item.getName() == name) {
                item.displayItem();
                found = true;
            }
        }
        if (!found) {
            cout << "Item not found!" << endl;
        }
    }

    // Display all items in inventory
    void displayInventory() {
        if (items.empty()) {
            cout << "Inventory is empty." << endl;
        }

        for (const auto& item : items) {
            item.displayItem();
            cout << "-------------------" << endl;
        }
    }
};

//int main() {
//    ItemDetails items;
//    int choice;
//    cout << "Welcome to Warehouse service" << endl;
//    while (true) {
//        cout << "Please Enter your choice:" << endl;
//        cout << "1. Add item" << endl;
//        cout << "2. Remove item" << endl;
//        cout << "3. Search item" << endl;
//        cout << "4. Display inventory" << endl;
//        cout << "5. Exit" << endl;
//        cout << "Choice: ";
//        cin >> choice;
//
//        switch (choice) {
//        case 1:
//            items.addItem();
//            break;
//        case 2:
//            items.removeItem();
//            break;
//        case 3:
//            items.searchItem();
//            break;
//        case 4:
//            items.displayInventory();
//            break;
//        case 5:
//            cout << "Exiting program..." << endl;
//            return 0;
//        default:
//            cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
//        }
//    } // end of loop
//    system("pause>0");
//}

#endif // !ITEM_H
