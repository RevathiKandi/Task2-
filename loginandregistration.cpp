#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void registerUser() {
    string username, password;

    cout << "\n--- User Registration ---\n";
    cout << "Enter new username: ";
    cin >> username;
    cout << "Enter new password: ";
    cin >> password;

    ofstream userFile("users/" + username + ".txt");
    if (userFile.is_open()) {
        userFile << username << endl;
        userFile << password << endl;
        userFile.close();
        cout << "User registered successfully.\n";
    } else {
        cout << "Error creating user file.\n";
    }
}

void loginUser() {
    string username, password, u, p;

    cout << "\n--- User Login ---\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream userFile("users/" + username + ".txt");
    if (userFile.is_open()) {
        getline(userFile, u);
        getline(userFile, p);
        if (u == username && p == password) {
            cout << "Login successful. Welcome " << username << "!\n";
        } else {
            cout << "Incorrect password.\n";
        }
        userFile.close();
    } else {
        cout << "User not found.\n";
    }
}

int main() {
    int choice;

    cout << "----- Login & Registration System -----\n";
    cout << "1. Register\n2. Login\nEnter choice: ";
    cin >> choice;

    switch (choice) {
        case 1: registerUser(); break;
        case 2: loginUser(); break;
        default: cout << "Invalid choice.\n";
    }

    return 0;
}