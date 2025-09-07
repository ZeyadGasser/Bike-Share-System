#include "MaintenanceTicket.h"

//For simplicity, I assume that the ticket price is 20 pounds.
const int priceMaintenanceTicket = 20;
int MaintenanceTicket::ID = 0;

MaintenanceTicket::MaintenanceTicket(const string& desc)
    : id(++ID), description(desc), status("Open") {
}

int MaintenanceTicket::getId() const {
    return id;
}

string MaintenanceTicket::getDescription() const {
    return description;
}

string MaintenanceTicket::getStatus() const {
    return status;
}

void MaintenanceTicket::setDescription(const string& desc) {
    description = desc;
}

void MaintenanceTicket::setStatus(const string& st) {
    status = st;
}

