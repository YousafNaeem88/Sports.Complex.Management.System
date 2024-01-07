#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct Player {
    int playerID;
    int playerAge;
    string playerName;
    string playerSport;
};

// Function to add a new player record to the file.
void addNewPlayerRecord() {
    ofstream file("playersRecord.txt", ios::app);
    if (file.is_open()) {
        Player newPlayer;

        cout << "Enter Player ID: ";
        cin >> newPlayer.playerID;
        cin.ignore();
        cout << "Enter Player Name: ";
        getline(cin, newPlayer.playerName);
        cout << "Enter Player Sport: ";
        getline(cin, newPlayer.playerSport);
        cout << "Enter Player Age: ";
        cin >> newPlayer.playerAge;

        cout << "Player record added successfully." << endl;
        cout << "**Player Id** : " << newPlayer.playerID << endl;
        cout << "**Name** : " << newPlayer.playerName << endl;
        cout << "**Sport** : " << newPlayer.playerSport << endl;
        cout << "**Age** :" << newPlayer.playerAge << endl;

        file << newPlayer.playerID << " " << newPlayer.playerName << " " << newPlayer.playerSport << " " << newPlayer.playerAge << "\n";

        file.close();
    }
    else {
        cout << "Unable to open file for writing." << endl;
    }
}

// Function to view all player records from the file.
void viewPlayerRecords() {
    ifstream file("playersRecord.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }
    else {
        cout << "Unable to open file for reading." << endl;
    }
}

// Function to search for a player record by ID.
void searchPlayerRecord() {
    ifstream file("playersRecord.txt");
    if (file.is_open()) {
        int searchID;
        cout << "Enter Player ID to search: ";
        cin >> searchID;

        bool found = false;
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            Player player;
            ss >> player.playerID >> player.playerName >> player.playerSport >> player.playerAge;
            if (player.playerID == searchID) {
                cout << line << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Player record not found." << endl;
        }
        file.close();
    }
    else {
        cout << "Unable to open file for reading." << endl;
    }
}

// Function to delete a player record by ID.
void deletePlayerRecord() {
    ifstream inFile("playersRecord.txt");
    ofstream tempFile("temp.txt");
    if (inFile.is_open() && tempFile.is_open()) {
        int deleteID;
        cout << "Enter Player ID to delete: ";
        cin >> deleteID;

        string line;
        bool found = false;
        while (getline(inFile, line)) {
            stringstream ss(line);
            Player player;
            ss >> player.playerID >> player.playerName >> player.playerSport >> player.playerAge;
            if (player.playerID != deleteID) {
                tempFile << line << endl;
            }
            else {
                found = true;
            }
        }
        inFile.close();
        tempFile.close();
        remove("playersRecord.txt");
        rename("temp.txt", "playersRecord.txt");
        if (found) {
            cout << "Player record deleted successfully." << endl;
        }
        else {
            cout << "Player record not found." << endl;
        }
    }
    else {
        cout << "Unable to open file(s)." << endl;
    }
}

// Function to edit a player record by ID.
void editPlayerRecord() {
    ifstream inFile("playersRecord.txt");
    ofstream tempFile("temp.txt");
    if (inFile.is_open() && tempFile.is_open()) {
        int editID;
        cout << "Enter Player ID to edit: ";
        cin >> editID;

        string line;
        bool found = false;
        while (getline(inFile, line)) {
            stringstream ss(line);
            Player player;
            ss >> player.playerID >> player.playerName >> player.playerSport >> player.playerAge;
            if (player.playerID == editID) {
                cout << "Enter updated Player Name: ";
                cin.ignore();
                getline(cin, player.playerName);
                cout << "Enter updated Player Sport: ";
                getline(cin, player.playerSport);
                cout << "Enter updated Player Age: ";
                cin >> player.playerAge;
                cout << "Player record updated successfully." << endl;
                tempFile << player.playerID << " " << player.playerName << " " << player.playerSport << " " << player.playerAge << "\n";
                found = true;
            }
            else {
                tempFile << line << endl;
            }
        }
        inFile.close();
        tempFile.close();
        remove("playersRecord.txt");
        rename("temp.txt", "playersRecord.txt");
        if (found) {
            cout << "Player record updated successfully." << endl;
        }
        else {
            cout << "Player record not found." << endl;
        }
    }
    else {
        cout << "Unable to open file(s)." << endl;
    }
}
