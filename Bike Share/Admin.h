#pragma once
#include "User.h"

/*******************************/
class Admin : public User {
public:
    Admin(const string& userName, const string& password, const string& nationalNumber);
    string showRole() const override;

private:
};

