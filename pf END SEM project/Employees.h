#pragma once
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

struct Employee {
    string name;
    string contact;
    string jobTitle;
    string qualifications;
};

const int MAX_EMPLOYEES = 100; // Maximum number of employees

Employee employees[MAX_EMPLOYEES]; // Array to hold employee records
int numEmployees = 0; // Current number of employees

// Function to add a new employee record to the array using structures and a single-dimensional array.
void addNewEmployeeRecord() {
    if (numEmployees < MAX_EMPLOYEES) {
        cout << "Enter Employee Name: ";
        cin.ignore();
        getline(cin, employees[numEmployees].name);
        cout << "Enter Contact Information: ";
        getline(cin, employees[numEmployees].contact);
        cout << "Enter Job Title: ";
        getline(cin, employees[numEmployees].jobTitle);
        cout << "Enter Qualifications: ";
        getline(cin, employees[numEmployees].qualifications);

        numEmployees++;

        cout << "Employee record added successfully." << endl;
    }
    else {
        cout << "Maximum number of employees reached." << endl;
    }
}

// Function to view all employee records from the array using structures and a single-dimensional array.
void viewEmployeeRecords() {
    for (int i = 0; i < numEmployees; ++i) {
        cout << employees[i].name << " " << employees[i].contact << " " << employees[i].jobTitle << " " << employees[i].qualifications << endl;
    }
}

// Function to search for an employee record by Name using structures and a single-dimensional array.
void searchEmployeeRecord() {
    string searchName;
    cin.ignore();
    cout << "Enter Employee Name to search: ";
    getline(cin, searchName);

    bool found = false;
    for (int i = 0; i < numEmployees; ++i) {
        if (employees[i].name == searchName) {
            cout << employees[i].name << " " << employees[i].contact << " " << employees[i].jobTitle << " " << employees[i].qualifications << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Employee record not found." << endl;
    }
}

// Function to delete an employee record by Name using structuresS and a single-dimensional array.
void deleteEmployeeRecord() {
    string deleteEmployeeName;
    cin.ignore();
    cout << "Enter Employee Name to delete: ";
    getline(cin, deleteEmployeeName);

    bool found = false;
    for (int i = 0; i < numEmployees; ++i) {
        if (employees[i].name == deleteEmployeeName) {
            for (int j = i; j < numEmployees - 1; ++j) {
                employees[j] = employees[j + 1];
            }
            numEmployees--;
            found = true;
            cout << "Employee record deleted successfully." << endl;
            break;
        }
    }
    if (!found) {
        cout << "Employee record not found." << endl;
    }
}

// Function to edit an employee record by Name using structures and a single-dimensional array.
void editEmployeeRecord() {
    string editEmployeeName;
    cin.ignore();
    cout << "Enter Employee Name to edit: ";
    getline(cin, editEmployeeName);

    bool found = false;
    for (int i = 0; i < numEmployees; ++i) {
        if (employees[i].name == editEmployeeName) {ds
            cout << "Enter updated Employee Name: ";
            getline(cin, employees[i].name);
            cout << "Enter updated Contact Information: ";
            getline(cin, employees[i].contact);
            cout << "Enter updated Job Title: ";
            getline(cin, employees[i].jobTitle);
            cout << "Enter updated Qualifications: ";
            getline(cin, employees[i].qualifications);

            found = true;
            cout << "Employee record updated successfully." << endl;
            break;
        }
    }
    if (!found) {
        cout << "Employee record not found." << endl;
    }
}
