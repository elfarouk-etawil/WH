#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <iostream> 
#include <string>
#include <vector>

#include "section.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Warehouse
{
private:
    string m_name;
    long m_id;
    string m_location;
    long m_maxCapacity;
    long m_currentCapacity;
    vector<Section> m_sections;

public:

    Warehouse() {}

    Warehouse(string name, long id, string location)
    {
        setName(name);
        setId(id);
        setLocation(location);

        m_maxCapacity =  0;
        m_currentCapacity = 0;
    }

    void getWarehouse()
    {
        string name;
        cout << "Enter Warehouse's name: ";
        cin >> name;
        setName(name);

        string location;
        cout << "Enter Warehouse's Location: ";
        cin >> location;
        setLocation(location);

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        m_maxCapacity = 0;
        m_currentCapacity = 0;
    }

    void setName(string ware_name)
    {
        m_name = ware_name;
    }

    void setId(long ID)
    {
        if (ID < 0 || ID == 0)
        {
            cout << "WRONG ID" << endl;
        }
        else
        {
            m_id = ID;
        }
    }

    void setLocation(string ware_location)
    {
        m_location = ware_location;
    }

    void setMaxCapacity(long ware_maxCapacity)
    {
        if (ware_maxCapacity < 0)
        {
            cout << "WRONG Value.. Please try again";
        }
        else
        {
            m_maxCapacity = ware_maxCapacity;
        }
    }

    void setCurrentCapacity(long ware_currentCapacity)
    {
        if (ware_currentCapacity == 0)
        {
            cout << "THE WAREHOUSR IS EMPTY!";
        }
        else if (ware_currentCapacity < 0)
        {
            cout << "WRONG VALUE.. Please try again";
        }
        else
        {
            m_currentCapacity = ware_currentCapacity;
        }
    }

    string getName()
    {
        return m_name;
    }

    long getId()
    {
        return m_id;

    }

    string getLocation()
    {
        return m_location;
    }

    long getMaxCapacity()
    {
        return m_maxCapacity;
    }
    long getCurrentCapacity()
    {
        return m_currentCapacity;
    }

    vector<Section> getSections()
    {
        return m_sections;
    }

    void addSection(Section section)
    {
        m_sections.push_back(section);
        m_maxCapacity += section.getMaxCapacity();
    }

    void addItem(int index, Item item)
    {
        m_sections[index].addItem(item);
        updateCapacity();
    }

    void removeItem(int index, string itemName)
    {
        m_sections[index].removeItem(itemName);
        updateCapacity();
    }

    void updateCapacity()
    {
        m_maxCapacity = 0;
        m_currentCapacity = 0;

        for (int i = 0; i < m_sections.size(); i++)
        {
            m_maxCapacity += m_sections[i].getMaxCapacity();
            m_currentCapacity += m_sections[i].getCurrentCapacity();
        }
    }

    void displayInfo()
    {
        cout << "Warehouse: " << m_name << endl;
        cout << "Id: " << m_id << endl;
        cout << "Location: " << m_location << endl;
        cout << "Maximum Capacity: " << m_maxCapacity << endl;
        cout << "Current used capacity: " << m_currentCapacity << endl;
        cout << "No. of sections: " << m_sections.size();

        cout << endl;
        for (int i = 0; i < m_sections.size(); i++)
        {
            m_sections[i].displaySectionInfo();
        }
    }
};

#endif
