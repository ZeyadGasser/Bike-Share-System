#pragma once
#include <map>
#include <string>
#include "User.h"
#include "Customer.h"
#include "StationOperator.h"
#include "Admin.h"
#include "MaintenanceTechnician.h"
using namespace std;

class UserManager {
public:
    UserManager();
    bool signUp(User* user);
    bool login(string& userName, string& pas) ;
    User* search(const string& username);
    void LoadDataBase();
    bool AddUser(User* user);
    ~UserManager();
private:
    map<string, User*> users; // key = username
};
