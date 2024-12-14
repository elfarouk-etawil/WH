#include <iostream>
#include <string>
#include <vector>

#include "warehouse.h"
#include "section.h"
#include "item.h"


void displayList();



int main()
{
    Warehouse warehouse;
    warehouse.getWarehouse();
    warehouse.setId(1);
    
    int nSections;
    cout << "Enter number of sections to add: ";
    cin >> nSections;

    for (int i = 0; i < nSections; i++)
    {
        string sectionName, sectionCategory;
        int sectionCapacity;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Enter Data for section #" << i + 1 << endl;
        cout << "Category: ";
        cin >> sectionCategory;
        cout << "Section's Capacity: ";
        cin >> sectionCapacity;
        warehouse.addSection(Section(warehouse.getId() * 100 + warehouse.getSections().size(),
            sectionCategory, sectionCapacity));
        cout << "Section created with id " << warehouse.getId() * 100 + warehouse.getSections().size() - 1 << endl;
        system("pause");
    }

    vector<string> transactions;

    while (true)
    {
        system("cls");

        int choice;
        displayList();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int sectionId;
            cout << "Enter Section ID: ";
            cin >> sectionId;

            if (sectionId - 99 > warehouse.getSections().size())
            {
                cout << "Section Not found!\n";
                break;
            }

            Item item;
            item.addItemDetails();

            warehouse.addItem(sectionId - 100, item);
            transactions.push_back(string("Item ") + item.getName() + string("is added!"));
            system("pause");
            break;
        }
        case 2:
        {
            int sectionId;
            cout << "Enter Section ID: ";
            cin >> sectionId;

            if (sectionId - 99 > warehouse.getSections().size())
            {
                cout << "Section Not found!\n";
                break;
            }

            string itemName;
            cout << "Enter Item name: ";
            cin >> itemName;

            warehouse.removeItem(sectionId - 100, itemName);
            transactions.push_back(string("Item ") + itemName + string(" is removed!"));
            system("pause");
            break;
        }
        case 3:
        {
            string sectionName, sectionCategory;
            int sectionCapacity;
            cout << "Category: ";
            cin >> sectionCategory;
            cout << "Section's Capacity: ";
            cin >> sectionCapacity;
            warehouse.addSection(Section(warehouse.getId() * 100 + warehouse.getSections().size(),
                sectionCategory, sectionCapacity));
            cout << "Section created with id " << warehouse.getId() * 100 + warehouse.getSections().size() << endl;
            transactions.push_back(string("Section") + std::to_string(warehouse.getId() * 100 + warehouse.getSections().size()) + string("is added!"));
            system("pause");
            break;
        }
        case 4:
        {
            for (int i = 0; i < transactions.size(); i++)
            {
                cout << transactions[i] << endl;
            }
            system("pause");
            break;
        }
        case 5:
        {
            warehouse.displayInfo();
            system("pause");
            break;
        }
        case 6:
        {
            return 0;
        }
        default:
        {
            cout << "Invalid Choice!" << endl;
        }
        }
    }
    
}


void displayList()
{
    cout << "\tWarehouse Mangement" << endl;
    cout << "1. Add goods\n";
    cout << "2. Disbatch goods\n";
    cout << "3. Add section\n";
    cout << "4. Operations history\n";
    cout << "5. Generate report\n";
    cout << "6. Quit\n";
}