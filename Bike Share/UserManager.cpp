#include "UserManager.h"
#include <iostream>
using namespace std;

UserManager::UserManager() {
    
}

void UserManager::LoadDataBase() {
    cout << "Start Load DataBase For Some USER \n";

    Admin* admin = new Admin("zeyad gasser","123123", "12345678901234");
    AddUser(admin);

    CardInfo* cardInfo = new CardInfo("1111-2222-3333-4444","02/26","123","01001231231");
    Customer* customer = new Customer("zoz", "123", "12345678901234", *cardInfo);
    AddUser(customer);

    StationOperator* stationOperator = new StationOperator("zeyad OP", "123123", "12345678901234");
    AddUser(stationOperator);

    MaintenanceTechnician* maintenanceTechnician = new MaintenanceTechnician("zeyad MA", "123123", "12345678901234");
    AddUser(maintenanceTechnician);
}

bool UserManager::signUp(User* user) {
    if (users.find(user->getUserName()) != users.end()) {
        return false;
    }
    return AddUser(user);
}

bool UserManager::AddUser(User* user) {
    users[user->getUserName()] = user;
    return true;
}
bool UserManager::login(string& userName,string& pas) {
    auto it = users.find(userName);
    if (it != users.end() && it->second->getPassword() == pas) {

        return true;
    }
    //cout << "Checking: " << userName << " " << pas << endl;

    return false;
}

User* UserManager::search(const string& username) {
    auto it = users.find(username);
    if (it != users.end()) {
        return it->second; 
    }
    return nullptr;
}


UserManager::~UserManager() {
    for (auto& pair : users) {
        delete pair.second;
    }
    users.clear();
    cout << "UserManager destroyed and all user deleted" << endl;

}

