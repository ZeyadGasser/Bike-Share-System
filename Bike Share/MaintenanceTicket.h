#pragma once
#include <string>
using namespace std;

extern const int priceMaintenanceTicket;

class MaintenanceTicket {
public:
    MaintenanceTicket(const string& desc);

    int getId() const;
    string getDescription() const;
    string getStatus() const;

    void setDescription(const string& desc);
    void setStatus(const string& st);


private:
    static int ID;
    int id;
    string description;
    string status;      // e.g. "Open", "In Progress", "Closed"
};

