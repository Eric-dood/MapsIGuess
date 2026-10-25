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
    int choice = 0;
    int age;
    string name, species, catchphrase;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerList["Drago"] = make_tuple(5, "Alligator", "Snap to it!");
    villagerList["Kyle"] = make_tuple(10, "Wolf", "Hubba hubba!");
    villagerList.insert({"Raymond", make_tuple(8, "Cat", "Nice fit")});

    // access the map using iterators
    while (true)
    {
        //Print the menu list
        cout << "1. Increase Friendship" << endl;
        cout << "2. Decrease Friendship" << endl;
        cout << "3. Search for Villager" << endl;
        cout << "4. Exit" << endl;

        //Prompt the user to make a choice
        cout << "Choice --> ";
        cin >> choice;
        cin.ignore(1000, 10);

        switch (choice)
        {
            case 1: //Insert

                
            case 2: //Remove

            case 3: //Find
                // search for an element using .find() to avoid errors
                string searchKey = "Drago";
                auto it = villagerList.find(searchKey);
                if (it != villagerList.end()) {  // the iterator points to beyond the end of the map
                                                // if searchKey is not found
                    cout << "\nFound " << searchKey << "'s favorite colors: ";
                    cout << "[" << get<0>(it->second) << ", " << get<1>(it->second) << ", " << get<2>(it->second) << "]" << endl;
                } else
                    cout << endl << searchKey << " not found." << endl;
        }

        if (choice == 4)
        {
            cout << "Quitting... Thanks for testing my program!" << endl;
            break;
        }
        else
        {
            //Print the villager list
            cout << "\nVillager details:" << endl;
            for (map<string, tuple<int, string, string>>::iterator it = villagerList.begin(); it != villagerList.end(); ++it)
            {
                cout << it->first << ": ";
                cout << "[" << get<0>(it->second) << ", " << get<1>(it->second) << ", " << get<2>(it->second) << "]" << endl;
            }
            cout << endl;
        }
    }

    // delete an element
    villagerList.erase("Raymond");

    //Report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerList.size() << endl;
    villagerList.clear();
    //Print the size after clearing
    cout << "Size after clear: " << villagerList.size() << endl;

    return 0;
}