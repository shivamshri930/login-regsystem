#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to register a new user
void registerUser() {
    string username, password;

    cout << "Enter a username: ";
    cin >> username;
    cout << "Enter a password: ";
    cin >> password;

    // Open the file in append mode to add a new user
    ofstream file("database.txt", ios::app);
    if (file.is_open()) {
        file << username << " " << password << endl;
        file.close();
        cout << "Registration successful!\n";
    } else {
        cout << "Error opening file for registration.\n";
    }
}

// Function to login a user
bool loginUser() {
    string username, password;
    string storedUsername, storedPassword;

    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    // Open the file in read mode to verify credentials
    ifstream file("database.txt");
    if (file.is_open()) {
        while (file >> storedUsername >> storedPassword) {
            if (storedUsername == username && storedPassword == password) {
                cout << "Login successful!\n";
                file.close();
                return true;
            }
        }
        file.close();
        cout << "Login failed: Invalid username or password.\n";
        return false;