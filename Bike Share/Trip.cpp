#include "Trip.h"
#include "Customer.h"
#include "IBike.h"

Trip::Trip(const Customer& customer_, const string& startTimeTrip_)
    : customer(customer_), bike(customer.GetInfoBikeWhoseCustomerRentIt()),
    startTimeTrip(startTimeTrip_), endTimeTrip("00:00"), TimeTrip(0.0) {
}

void Trip::SetStartTimeTrip(const string startTimeTrip_) {
    startTimeTrip = startTimeTrip_;
}

void Trip::SetEndTimeTrip(const string endTimeTrip_) {
    endTimeTrip = endTimeTrip_;
}

string Trip::GetStartTimeTrip() const {
    return startTimeTrip;
}

string Trip::GetEndTimeTrip() const {
    //return endTimeTrip;
    return "9:30";
}

double Trip::GetTimeTrip() const {
    if (endTimeTrip != "00:00") {
        //TimeTrip=endTimeTrip - startTimeTrip
    }
   // return TimeTrip;
    //for simplicity 5 hour
    return 5.00;
}

const Customer& Trip::GetCustomer() const {
    return customer;
}

double Trip::GetPricePerHourForBike() const {
    return bike.GetPricePerHour();
}