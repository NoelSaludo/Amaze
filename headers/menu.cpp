#include "menu.h"
#include <iostream> // Add this line to include the necessary header

void registerUser(vector<User>& users, const User& user) {
    for (const auto& existingUser : users) {
        if (existingUser.username == user.username) {
            cout << "Username already exists. Please choose a different username.\n";
            return;
        }
    }
    users.push_back(user);
    cout << "User registered successfully.\n";
}

bool logIn(const vector<User>& users, const User& user) {
    for (const auto& existingUser : users) {
        if (existingUser.username == user.username && existingUser.password == user.password) {
            return true;
        }
    }
    return false;
}