//COMSC-210 | Lab 27 | Eric-Giulio Hedes
#include <iostream>
#include <map>
#include <vector>
#include <tuple>
using namespace std;

int main() {
    // declarations
    map<string, tuple<int, string, string>> villagerList;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerList["Drago"] = { 5, "Alligator", "Snap to it!" };
    villagerList["Kyle"] = { 10, "Wolf", "Hubba hubba!" };
    villagerList.insert({"Raymond", {8, "Cat", "Nice fit"}});

    // access the map using a range-based for loop
    cout << "Villagers and their favorite colors (range-based for loop):" << endl;
    for (auto pair : villagerList)
    {
        cout << pair.first << ": ";
        for (auto color : pair.first)
            cout << color << " ";
        cout << endl;
    }

    // access the map using iterators
    cout << "\nVillagers and their favorite colors (iterators):" << endl;
    for (map<string, tuple<int, string, string>>::iterator it = villagerList.begin(); 
                                               it != villagerList.end(); ++it) {
        cout << it->first << ": ";
        for (auto color : it->first) {
            cout << color << " ";
        }
        cout << endl;
    }

    // delete an element
    villagerList.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagerList.find(searchKey);
    if (it != villagerList.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s favorite colors: ";
        for (auto color : it->first)  // range loop to traverse the value/vector
            cout << color << " ";
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerList.size() << endl;
    villagerList.clear();
    cout << "Size after clear: " << villagerList.size() << endl;

    return 0;
}