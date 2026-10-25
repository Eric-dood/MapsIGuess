//COMSC-210 | Lab 27 | Eric-Giulio Hedes
#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    // declarations
    map<string, tuple<int, string, string>> villagerList;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerList["Drago"] = make_tuple(5, "Alligator", "Snap to it!");
    villagerList["Kyle"] = make_tuple(10, "Wolf", "Hubba hubba!");
    villagerList.insert({"Raymond", make_tuple(8, "Cat", "Nice fit")});

    // access the map using a range-based for loop
    cout << "Villagers and their favorite colors (range-based for loop):" << endl;
    for (auto pair : villagerList)
    {
        cout << pair.first << ": ";
        cout << "[" << get<0>(pair.second) << ", " << get<1>(pair.second) << ", " << get<2>(pair.second) << "]" << endl;
    }

    // access the map using iterators
    cout << "\nVillagers and their favorite colors (iterators):" << endl;
    for (map<string, tuple<int, string, string>>::iterator it = villagerList.begin(); it != villagerList.end(); ++it)
    {
        cout << it->first << ": ";
        cout << "[" << get<0>(it->second) << ", " << get<1>(it->second) << ", " << get<2>(it->second) << "]" << endl;
    }

    // delete an element
    villagerList.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Drago";
    auto it = villagerList.find(searchKey);
    if (it != villagerList.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s favorite colors: ";
        cout << "[" << get<0>(it->second) << ", " << get<1>(it->second) << ", " << get<2>(it->second) << "]" << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    //Report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerList.size() << endl;
    villagerList.clear();
    //Print the size after clearing
    cout << "Size after clear: " << villagerList.size() << endl;

    return 0;
}