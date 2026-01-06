#include <iostream>
#include "ArrayBasedList.h"
using namespace std;

void showMenu() {
    cout << "\n===== MENU =====\n";
    cout << "1. Insert at position\n";
    cout << "2. Remove at position\n";
    cout << "3. Search item\n";
    cout << "4. Display list\n";
    cout << "5. Show size\n";
    cout << "6. Show free list head\n";
    cout << "0. Exit\n";
    cout << "Enter choice: ";
}

int main() {
    ArrayBasedList list;
    int choice;

    while (true) {
        showMenu();
        cin >> choice;

        if (choice == 0) break;

        if (choice == 1) {
            int pos;
            string value;
            cout << "Enter position: ";
            cin >> pos;
            cout << "Enter value: ";
            cin >> value;
            list.insert(pos, value);
        }
        else if (choice == 2) {
            int pos;
            cout << "Enter position: ";
            cin >> pos;
            list.remove(pos);
        }
        else if (choice == 3) {
            string value;
            cout << "Enter item to search: ";
            cin >> value;
            int pos = list.search(value);
            if (pos >= 0) cout << "Found at position " << pos << endl;
            else cout << "Item not found.\n";
        }
        else if (choice == 4) {
            list.display();
        }
        else if (choice is 5) {
            cout << "List size: " << list.size() << endl;
        }
        else if (choice == 6) {
            cout << "Free list head: " << list.getFree() << endl;
        }
        else {
            cout << "Invalid option.\n";
        }
    }

    cout << "Goodbye!\n";
    return 0;
}
