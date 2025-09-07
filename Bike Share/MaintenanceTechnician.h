#pragma once
#include "User.h"
#include <map>
using namespace std;

// Forward declaration
class MaintenanceTicket;

/*******************************/
class MaintenanceTechnician : public User {
public:
    MaintenanceTechnician(const string& userName, const string& password, const string& nationalNumber);

    string showRole() const override;
    void addTicketOfUserForAllUserToMaintenanceTechnician(MaintenanceTicket* ticket);
    void SetStatus(int id_, const string& status);
    const map<int, MaintenanceTicket*>& getAllTickets();

private:
    map<int, MaintenanceTicket*> allMaintenanceTicketsForAllUsers; //0.....n cardinality
};

