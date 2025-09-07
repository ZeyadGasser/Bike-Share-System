#include "Customer.h"
Customer::Customer(const string& userName, const string& password, const string& nationalNumber,
    CardInfo& card)
    : User(userName, password, nationalNumber), cardInfo(card), bike(nullptr) {
}

void Customer::SetBike(IBike* bike_) {
    bike = bike_;
}

const CardInfo& Customer::GetCardInfo() const {
    return cardInfo;
}

string Customer::showRole() const {
   return"Customer";
}



void Customer::addTicket(MaintenanceTicket* ticket) {
    maintenanceTickets[ticket->getId()] = ticket;
}

const map<int, MaintenanceTicket*>& Customer::showTickets() const {
    return maintenanceTickets;
}

bool Customer::updateTicketDescription(int ticketId, const string& newDesc) {
    if (maintenanceTickets.empty()) {
        return false;
    }
    auto it = maintenanceTickets.find(ticketId);
    if (it != maintenanceTickets.end()) {
        maintenanceTickets[ticketId]->setDescription(newDesc);
        return true;
    }
    return false;
}

IBike& Customer::GetInfoBikeWhoseCustomerRentIt() const {
    if (bike != nullptr) {
        return *bike;
    }
    else {
        throw runtime_error("No bike rented by this customer!");
    }
}

int Customer::GetCountTicket() const {
    int count = 0;
    if (!maintenanceTickets.empty()) {
        for (const auto& it : maintenanceTickets) {
            count++;
        }
    }
    return count;
}