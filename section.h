#ifndef SECTION_H
#define SECTION_H


#include <iostream>
#include <string>
#include <vector>

#include "item.h"


class Section
{
private:
    int m_id;
    std::string m_category;
    int m_maxCapacity; 
    int m_currentCapacity = 0;
    std::vector<Item> m_items; 

public:


    //constractor
    Section(int id, const std::string& category, int maxCapacity)
    {
        m_id = id;
        m_category = category;
        m_maxCapacity = maxCapacity;
    }

    int getMaxCapacity() const
    {
        return m_maxCapacity;
    }

    void addItem(const Item& item)
    {
        if (m_items.size() < m_maxCapacity)
        {
            m_items.push_back(item);
            m_currentCapacity += item.getQuantity();
            std::cout << "Item '" << item.getName() << "' added successfully.\n";
        }
        else
        {
            std::cout << "Cannot add item. Section is at full capacity!\n";
        }
    }

    void removeItem(const string& itemName)
    {
        int index = -1;
        for (int i = 0; i < m_items.size(); i++)
        {
            if (m_items[i].getName() == itemName)
            {
                index = i;
                break;
            }
        }
        if (index != -1)
        {
            m_items.erase(m_items.begin() + index);
            updateCapacity();
            std::cout << "Item '" << itemName << "' removed successfully.\n";
        }
        else
        {
            std::cout << "Item '" << itemName << "' not found in the section.\n";
        }
    }

    // ???? ???? ??????? ?????
    void displaySectionInfo() const
    {
        std::cout << "Section ID: " << m_id << "\n";
        std::cout << "Category: " << m_category << "\n";
        std::cout << "Maximum Capacity: " << m_maxCapacity << "\n";
        std::cout << "Current Capacity: " << m_items.size() << "\n";
        std::cout << "Items: ";
        for (int i = 0; i < m_items.size(); i++)
        {
            std::cout << m_items[i].getName() << " ";
        }
        std::cout << "\n";
    }

    // ???? ?????? ??? ????? ???????
    int getAvailableCapacity() const
    {
        return m_maxCapacity - m_currentCapacity;
    }

    int getCurrentCapacity()
    {
        return m_currentCapacity;
    }

    void updateCapacity()
    {
        m_currentCapacity = 0;

        for (int i = 0; i < m_items.size(); i++)
        {
            m_currentCapacity += m_items[i].getQuantity();
        }
    }
};

//int main()
//{
//    // ????? ???? ???? ???????? Constructor ?????
//    Section section1;
//    section1.initialize(1, "Electronics", "Storage", 5);
//
//    // ????? ?????
//    section1.addItem("Laptop");
//    section1.addItem("Monitor");
//    section1.addItem("Keyboard");
//
//    // ??? ??????? ?????
//    section1.displaySectionInfo();
//
//    // ????? ????
//    section1.removeItem("Monitor");
//
//    // ??? ??????? ????? ??? ???????
//    section1.displaySectionInfo();
//
//    // ????? ????? ???????
//    std::cout << "Available Capacity: " << section1.getAvailableCapacity() << "\n";
//
//    return 0;
//}

#endif // !SECTION_H
