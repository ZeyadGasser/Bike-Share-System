#pragma once
#include "User.h"

/*******************************/
class StationOperator : public User {
public:
    StationOperator(const string& userName, const string& password, const string& nationalNumber);
    string showRole() const override;

private:
};

