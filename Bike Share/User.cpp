#include "User.h"

User::User(const string& userName, const string& password, const string& nationalNumber)
    : userName(userName), password(password), nationalNumber(nationalNumber) {
}

void User::setUserName(const string& name) {
    userName = name;
}

string User::getUserName() const {
    return userName;
}
void User::setPassword(const string& pas){
    password = pas;
}


string User::getNationalNumber() const {
    return nationalNumber;
}
string User::getPassword() const{
    return password;
}