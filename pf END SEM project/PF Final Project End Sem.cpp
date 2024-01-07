#include <iostream>
#include "Players.h"
#include "Employees.h"
#include "Matches.h"
using namespace std;
int main() {
    int choice;
    while (true) {
        cout << "Player Information MENU:" << endl;
        cout << "1. Add Player Record" << endl;
        cout << "2. View Player Records" << endl;
        cout << "3. Search Player Record" << endl;
        cout << "4. Delete Player Record" << endl;
        cout << "5. Edit Player Record" << endl;

        cout << "\nEmployee Information MENU:" << endl;
        cout << "6. Add Employee Record" << endl;
        cout << "7. View Employee Records" << endl;
        cout << "8. Search Employee Record" << endl;
        cout << "9. Delete Employee Record" << endl;
        cout << "10. Edit Employee Record" << endl;

        cout << "\nMatches Information MENU:" << endl;
        cout << "11. Add Matches Record" << endl;
        cout << "12. View Matches Record" << endl;

        cout << "\nEnter your choice (0 to exit): ";
        cin >> choice;

        if (choice == 0) {
            break;
        }

        switch (choice) {
        case 1:
            addNewPlayerRecord();
            break;
        case 2:
            viewPlayerRecords();
            break;
        case 3:
            searchPlayerRecord();
            break;
        case 4:
            deletePlayerRecord();
            break;
        case 5:
            editPlayerRecord();
            break;
        case 6:
            addNewEmployeeRecord();
            break;
        case 7:
            viewEmployeeRecords();
            break;
        case 8:
            searchEmployeeRecord();
            break;
        case 9:
            deleteEmployeeRecord();
            break;
        case 10:
            editEmployeeRecord();
        case 11:
            addNewMatchRecord();
        case 12:
            viewMatchRecords();
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}