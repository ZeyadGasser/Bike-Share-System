#pragma once
#include "User.h"
#include "CardInfo.h"
#include "IBike.h"
#include "MaintenanceTicket.h"
#include <iostream>
#include <map>
using namespace std;
class Customer : public User {
public:
    Customer(const string& userName, const string& password, const string& nationalNumber,
        CardInfo& card);

    void SetBike(IBike* bike_);
    const CardInfo& GetCardInfo() const;
    string showRole() const override;
    void addTicket(MaintenanceTicket* ticket);
    const map<int, MaintenanceTicket*>& showTickets() const;
    bool updateTicketDescription(int ticketId, const string& newDesc);
    IBike& GetInfoBikeWhoseCustomerRentIt() const;
    int GetCountTicket() const;

private:
    CardInfo cardInfo;
    map<int, MaintenanceTicket*> maintenanceTickets; //0.....n cardinality
    IBike* bike;
};
