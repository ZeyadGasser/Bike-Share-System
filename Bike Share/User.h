#pragma once
#include <string>
using namespace std;

/****************************************Abstract class User************************************************/

class User {
public:
    User(const string& userName, const string& password, const string& nationalNumber);

    void setUserName(const string& name);
    string getUserName() const;
    string getPassword() const;
    void setPassword(const string& pas) ;
    string getNationalNumber() const;

    /*
         Pure virtual function to make 'User' an abstract class.
         This prevents creating a direct object of 'User'
         and forces derived classes (e.g., Customer, Admin)
         to provide their own implementation.
    */
    virtual string showRole() const = 0;

private:
    string userName;
    string password;
    string nationalNumber;
};
