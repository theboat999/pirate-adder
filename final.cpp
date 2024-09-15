#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <thread>

using namespace std;
using namespace std::chrono;

struct Pirate {
    string name;
    long long bounty;
    string group;
};

void saveFile(vector<Pirate> &pirates) {
    try { 
        ofstream file("onePiece.txt", ios::trunc);
        if (!file.is_open()) {
            for (const Pirate &pirate: pirates) {
                throw runtime_error("Error: Unable to open file for saving.");
            }
        }

        for (const Pirate &pirate: pirates) {
            file << pirate.name << " " << pirate.bounty << " "<< pirate.group << endl;
        }
        file.close();
    } catch (const exception &e) {
        cerr << e.what() << endl;
    }
}

void loadFile(vector<Pirate> &pirates) {
    try {
        ifstream file("onePiece.txt");
        if (!file.is_open()) {
            throw runtime_error("Error: Unable to open file for saving.");
        }

        string tempName;
        long long tempBounty;
        string tempGroup;
        
        while (file >> tempName >> tempBounty >> tempGroup) {
            Pirate tempPirate;
            tempPirate.name = tempName;
            tempPirate.bounty = tempBounty;
            tempPirate.group = tempGroup;
            pirates.push_back(tempPirate);
        }
        file.close();
        cout << "Reading the text file..." << endl;
        auto start = high_resolution_clock::now();
        this_thread::sleep_for(seconds(1 + 1/2));
        auto end = high_resolution_clock::now();
        system("clear");
    } catch (const exception &e) {
        cerr << e.what() << endl;
    }
}

void addPirates(vector<Pirate> &pirates) {
    int size;
    cout << "Enter the amount of pirates you will add: ";
    cin >> size;

    for (int i = 0; i < size; i++) {
        string tempName;
        bool duplicate = false;

        cout << "Name of the pirate: ";
        cin >> tempName;

        for (const Pirate &pirate: pirates) {
            if (tempName == pirate.name) {
                duplicate = true;
                cout << "Pirate already on the list!";
                break;
            } 
        }

        string tempGroup;
        long long tempBounty;
        if (!duplicate) {
            cout << tempName << "'s bounty: ";
            cin >> tempBounty;
            cout << tempName << "'s group: ";
            cin >> tempGroup;
            Pirate tempPirate = {tempName, tempBounty, tempGroup};
            pirates.push_back(tempPirate);
            saveFile(pirates);
        }
        system("clear");
    }
}

void editPirates(vector<Pirate> &pirates) {
    string searchName;
    bool found = false;

    cout << "Pirate name: ";
    cin >> searchName;
    cout << "\nDo you want to make changes in this pirate?" << endl << endl;

    for (Pirate &pirate: pirates) {
        if (searchName == pirate.name) {
            found = true;
            char choice;
            cout << "Pirate: " << pirate.name << endl;
            cout << "Bounty: " << pirate.bounty << endl << endl;
            cout << "Press [P] to edit pirate name." << endl;
            cout << "Press [B] to edit pirate bounty." << endl;
            cout << "Press [G] to edit pirate group." << endl; 
            cout << "Press [A] to edit all." << endl;
            cout << "\nEnter choice: ";
            cin >> choice;
            
            switch(choice) {
                case 'p':
                    cout << "New pirate name: ";
                    cin >> pirate.name;
                    cout << "Pirate name successfully updated!";
                    break;
                
                case 'm':
                    cout << "New pirate bounty: ";
                    cin >> pirate.bounty;
                    cout << "Pirate bounty successfully updated!";
                    break;

                case 'g':
                    cout << "New pirate group: ";
                    cin >> pirate.group;
                    cout << "Pirate group successfully updated!";
                    break;
                
                case 'a':
                    cout << "New pirate name: ";
                    cin >> pirate.name;
                    cout << "New pirate bounty: ";
                    cin >> pirate.bounty;
                    cout << "New pirate group: ";
                    cin >> pirate.group;
                    cout << "Pirate name, bounty, and group are updated successfully!";
                
                default:
                    cout << "Invalid input.";
            }
            saveFile(pirates);
        }
    }
    if (!found) {
        cout << "Pirate: " << searchName << " was not found";
    } 
}

void viewPirates(vector<Pirate> &pirates) {
    for (const Pirate &pirate: pirates) {
        cout << "Name: " << pirate.name << endl;
        cout << "Bounty: " << pirate.bounty << endl;
        cout << "Member of: " << pirate.group << endl << endl;
    }
}

void searchPirates(vector<Pirate> &pirates) {
    string searchName;
    bool found = false;

    cout << "Pirate name: ";
    cin >> searchName;

    for (const Pirate &pirate: pirates) {
        if (searchName == pirate.name) {
            cout << "\nName: " << pirate.name << endl;
            cout << "Bounty: " << pirate.bounty << endl;
            cout << "Group: " << pirate.group << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Pirate " + searchName + " is not on the list." << endl;
    }
}

void searchGroups (vector<Pirate> &pirates) {
    string searchGroups;
    bool found = false;

    cout << "Search for a pirate group: ";
    cin >> searchGroups;

    cout << endl << searchGroups << " Members" << endl << endl;
    for (const Pirate &pirate: pirates) {
        if (searchGroups == pirate.group) {
            cout << "Name: " << pirate.name << endl;
            cout << "Bounty: "<< pirate.bounty << endl << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "There is no " << searchGroups << " group exists." << endl;
    }
}

int main() {
    vector<Pirate> pirates;
    loadFile(pirates);
    int choice;

    do {
        cout << "\n************ WANTED LIST ************" << endl << endl;
        cout << "[1] Add Pirates";
        cout << "      [2] Edit Pirates" << endl;
        cout << "[3] View Pirates";
        cout << "     [4] Search Pirates" << endl;
        cout << "[5] View groups";
        cout << "      [6] Exit" << endl;
        cout << "\nEnter choice: ";
        cin >> choice;
        system("clear");

        switch (choice) {
            case 1:
                addPirates(pirates);
                break;
            case 2:
                editPirates(pirates);
                break;
            case 3:
                viewPirates(pirates);
                break;
            case 4:
                searchPirates(pirates);
                break;
            case 5:
                searchGroups(pirates);
                break;
            case 6:
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid choice. Please enter 1 or 2." << endl;
                break;
        }

    } while (choice != 6);

    return 0;
}


/*
Thing to improve:
- Error handling (misinput)
- Sorting (bounty from highest to lowest or lowest to highest)
- Crew captains and positions (yonkos, warlord of the sea, etc...)
- Status (dead or alive, only dead, only alive)
*/