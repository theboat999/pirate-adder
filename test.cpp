#include <iostream>
#include <vector>
using namespace std;

struct Pirate {
    string name;
    long long bounty;
};

void addPirates(vector<Pirate> &pirates) {
    int size;

    cout << "How many pirates would you like to add? ";
    cin >> size;

    pirates.resize(size);

    for (int i = 0; i < size; i++) {
        cout << "Add a pirate name: ";
        cin >> pirates[i].name;
    }

}

void addBounty(vector<Pirate> &pirates) {
    string searchPirate;
    bool found = false;

    cout << "Enter pirate name to add a bounty: "; 
    cin >> searchPirate;

    for (Pirate &pirate: pirates) {
        if (searchPirate == pirate.name) {
            cout << "Add bounty for: " << pirate.name << ": ";
            cin >> pirate.bounty;
            found = true;
            break;
        }
    }
}

void displayPirates(vector<Pirate> &pirates) {
    for (const Pirate &pirate: pirates) {
        cout << "Name: " << pirate.name << " Bounty: " << pirate.bounty << " berries" << endl;
    }
    cout << endl;
}

void searchPirates(vector<Pirate> &pirates) {
    string searchName;
    bool found = false;

    cout << "Search for a pirate: ";
    cin >> searchName;

    for (const Pirate &pirate: pirates) {
        if (searchName == pirate.name) {
            cout << "Name: " << pirate.name << endl;
            cout << "Bounty: " << pirate.bounty;
            found = true;
            break;
        }
    }
    cout << endl;
}
int main() {
    vector<Pirate> pirates;
    int choice;

    do {
        cout << "[1] Add pirates" << endl;
        cout << "[2] Add bounty" << endl;
        cout << "[3] View all pirates" << endl;
        cout << "[4] Search pirates " << endl;
        cout << "[5] Exit" << endl << endl;
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            addPirates(pirates); 
        } else if (choice == 2) {
            addBounty(pirates);
        } else if (choice == 3){
            displayPirates(pirates);
        } else if (choice == 4) {
            searchPirates(pirates);
        } else if (choice == 5) {
            cout << "Goodbye";
        }

    } while (choice != 5);

}