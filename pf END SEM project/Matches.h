#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Match {
    int matchID;
    string venue;
    string date;
    string time;
    string weatherCondition;
};

const int MAX_MATCHES = 100;
Match matches[MAX_MATCHES];
int numMatches = 0;

void addNewMatchRecord() {
    if (numMatches < MAX_MATCHES) {
        int playerID;
        string playerName;

        cout << "Enter Match ID: ";
        cin >> matches[numMatches].matchID;
        cin.ignore();
        cout << "Enter Venue: ";
        getline(cin, matches[numMatches].venue);
        cout << "Enter Date: ";
        getline(cin, matches[numMatches].date);
        cout << "Enter Time: ";
        getline(cin, matches[numMatches].time);
        cout << "Enter Weather Condition: ";
        getline(cin, matches[numMatches].weatherCondition);

        bool playerAvailable = false;
        ifstream playerFile("playersRecord.txt");
        if (playerFile.is_open()) {
            cout << "Enter Player Name to confirm availability: ";
            getline(cin, playerName);

            string line;
            while (getline(playerFile, line)) {
                int id;
                string name, sport;
                playerFile >> id >> name >> sport;
                if (name == playerName) {
                    playerID = id;
                    playerAvailable = true;
                    break;
                }
            }
            playerFile.close();
        }
        else {
            cout << "Unable to open players file." << endl;
            return;
        }

        bool employeeAvailable = false;
        ifstream employeeFile("employees.txt");
        if (employeeFile.is_open()) {
            string employeeName;
            cout << "Enter Employee Name to confirm availability: ";
            getline(cin, employeeName);

            string line;
            while (getline(employeeFile, line)) {
                string name, contact, jobTitle, qualifications;
                employeeFile >> name >> contact >> jobTitle >> qualifications;
                if (name == employeeName) {
                    employeeAvailable = true;
                    break;
                }
            }
            employeeFile.close();
        }
        else {
            cout << "Unable to open employees file." << endl;
            return;
        }

        if (playerAvailable && employeeAvailable) {
            cout << "Match details added successfully." << endl;
            numMatches++;
        }
        else {
            cout << "Player or Employee not available." << endl;
        }
    }
    else {
        cout << "Maximum number of matches reached." << endl;
    }
}

void viewMatchRecords() {
    for (int i = 0; i < numMatches; ++i) {
        cout << matches[i].matchID << " " << matches[i].venue << " " << matches[i].date << " " << matches[i].time << " " << matches[i].weatherCondition << endl;
    }
}
