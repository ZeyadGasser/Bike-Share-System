#include "MaintenanceTechnician.h"
#include "MaintenanceTicket.h"
#include <iostream>

MaintenanceTechnician::MaintenanceTechnician(const string& userName, const string& password, const string& nationalNumber)
    : User(userName, password, nationalNumber) {
}

string MaintenanceTechnician::showRole() const {
    return "MaintenanceTechnician";
}

void MaintenanceTechnician::addTicketOfUserForAllUserToMaintenanceTechnician(MaintenanceTicket* ticket) {
    allMaintenanceTicketsForAllUsers[ticket->getId()] = ticket;
}

void MaintenanceTechnician::SetStatus(int id_, const string& status) {
    allMaintenanceTicketsForAllUsers[id_]->setStatus(status);
}

const map<int, MaintenanceTicket*>& MaintenanceTechnician::getAllTickets() {
    return allMaintenanceTicketsForAllUsers;
}