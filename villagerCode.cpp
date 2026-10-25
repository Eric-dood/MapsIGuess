//COMSC-210 | Lab 27 | Eric-Giulio Hedes
#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <algorithm>
#include <string>
using namespace std;

//Start of main()
int main() {
    // declarations
    map<string, tuple<int, string, string>> villagerList;
    int choice = 0; //Will be used for menu choices

    //Insert the base villagers to the list
    villagerList["Drago"] = make_tuple(5, "Alligator", "Snap to it!");
    villagerList["Kyle"] = make_tuple(10, "Wolf", "Hubba hubba!");
    villagerList.insert({"Raymond", make_tuple(8, "Cat", "Nice fit")});

    // access the map using iterators
    while (true)
    {
        //Print the menu list
        cout << "1. Add Villager" << endl;
        cout << "2. Delete Villager" << endl;
        cout << "3. Increase Friendship" << endl;
        cout << "4. Decrease Friendship" << endl;
        cout << "5. Search for Villager" << endl;
        cout << "6. Exit" << endl;

        //Use a validation loop
        while (true)
        {
            //Prompt the user to make a choice
            cout << "Choice --> ";
            cin >> choice;
            cin.ignore(1000, 10);

            //If the choice is between 1 & 6, exit the validation loop
            if (choice >= 1 && choice <= 6) break;
            else //If the choice exceeds the list's maximum, print out an error message
                cout << "ERROR - Please insert a value between 1-4: ";
        }

        //Yay, declare more variables
        string searchKey;
        int friendship;
        string name, species, catchphrase;

        //Do a special check for choices 2 and 5; doing in a switch statement causes errors
        if (choice == 2 || choice == 5)
        {
            //Ask the user to enter the villager's name
            cout << "Which villager do you want to " << ((choice == 2) ? "delete" : "find") << "?" << endl << "Name --> ";
            getline(cin, searchKey);

            //Use a iterator & .find() to find the villager (using .find() avoids errors)
            auto it = villagerList.find(searchKey);
            if (it != villagerList.end())
            {  // the iterator points to beyond the end of the map
                //If the choice is 5, find the villager
                if (choice == 5)
                {
                    cout << "\nFound " << searchKey << "'s favorite colors: ";
                    cout << "[" << get<0>(it->second) << ", " << get<1>(it->second) << ", " << get<2>(it->second) << "]" << endl;
                }
                else //Otherwise delete the villager
                {
                    cout << "Deleting " << searchKey << "..." << endl;
                    villagerList.erase(searchKey);
                }
            }
            else //If the villager's name is not found, print a message
                cout << endl << searchKey << " not found." << endl;
        }

        //Start the choices
        switch (choice)
        {
            case 1: //Add Villager
                //Ask the user to enter the villager's information
                cout << "Enter the name of the villager --> ";
                getline(cin, name);
                cout << "Enter the friendship value of the villager --> ";
                cin >> friendship;
                cin.ignore(1000, 10);
                cout << "Enter the species of the villager --> ";
                getline(cin, species);
                cout << "What's the villager's catchphrase? --> ";
                getline(cin, catchphrase);
                //Insert the new villager to the list
                cout << name << " added." << endl;
                villagerList.insert(make_pair(name, make_tuple(friendship, species, catchphrase)));
                break;
            case 3: //Increase Friendship
                //Increase friendship value to every villager
                for (auto &pair : villagerList)
                    get<0>(pair.second) += 1;
                break;
            case 4: //Decrease Friendship
                //Decrease friendship value to every villager
                for (auto &pair : villagerList)
                {
                    //Make sure for the friendship values to not be lower than 0
                    if (get<0>(pair.second) > 0)
                        get<0>(pair.second) -= 1;
                }
                break;
        }

        //If the choice is equal to 6, exit the program entirely.
        if (choice == 6)
        {
            cout << "Quitting... Thanks for testing my program!" << endl;
            break;
        }
        else
        {
            //Print the villager list
            cout << "\nVillager details:" << endl;
            //Use a iterator loop to print every villager in the list
            for (map<string, tuple<int, string, string>>::iterator it = villagerList.begin(); it != villagerList.end(); ++it)
            {
                cout << it->first << ": ";
                cout << "[" << get<0>(it->second) << ", " << get<1>(it->second) << ", " << get<2>(it->second) << "]" << endl;
            }
            cout << endl;
        }
    }

    //Report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerList.size() << endl;
    villagerList.clear();
    //Print the size after clearing
    cout << "Size after clear: " << villagerList.size() << endl;

    //Return 0 :V
    return 0;
}