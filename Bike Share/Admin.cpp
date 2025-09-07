#include "Admin.h"
#include <iostream>

Admin::Admin(const string& userName, const string& password, const string& nationalNumber)
    : User(userName, password, nationalNumber) {
}

string Admin::showRole() const {
    return "Admin";
}