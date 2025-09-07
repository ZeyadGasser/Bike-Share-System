#include "StationOperator.h"
#include <iostream>

StationOperator::StationOperator(const string& userName, const string& password, const string& nationalNumber)
    : User(userName, password, nationalNumber) {
}

string StationOperator::showRole() const {
    return"StationOperator";
}