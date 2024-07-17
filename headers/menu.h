#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct User {
    string username;
    string password;
};

void registerUser(vector<User>& users, const User& user);
bool logIn(const vector<User>& users, const User& user);

#endif // MENU_H
