#pragma once
#include <string>
#include"Customer.h"
#include"IBike.h"
using namespace std;
/****************************************Class Trip************************************************/

class Trip {
public:
    Trip(const Customer& customer_, const string& startTimeTrip_);

    void SetStartTimeTrip(const string startTimeTrip_);
    void SetEndTimeTrip(const string endTimeTrip_);
    string GetStartTimeTrip() const;
    string GetEndTimeTrip() const;
    double GetTimeTrip() const;
    const Customer& GetCustomer() const;
    double GetPricePerHourForBike() const;

private:
    string startTimeTrip;
    string endTimeTrip;
    double TimeTrip;

    const Customer& customer;
    const IBike& bike;
};
