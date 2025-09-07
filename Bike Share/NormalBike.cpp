#include "NormalBike.h"
#include <iostream>

int NormalBike::normalBikeID = 0;

NormalBike::NormalBike(bool available_, double pricePerHour_)
    : available(available_), pricePerHour(pricePerHour_), isNeedMaintenance(false), ID(++normalBikeID) {
}

bool NormalBike::Start() {
    return true;
}

bool NormalBike::Stop() {
    return true;
}

bool NormalBike::Park() {
    return true;
}

double NormalBike::GetPricePerHour() const {
    return pricePerHour;
}

bool NormalBike::IsAvailable() const {
    return available;
}

void NormalBike::SetAvailable(bool available_) {
    available = available_;
}

bool NormalBike::IsNeedMaintenance() const {
    return isNeedMaintenance;
}

void NormalBike::SetNeedMaintenance(bool value) {
    isNeedMaintenance = value;
}

string NormalBike::GetCurrentLocation() const {
    //need API to get location from Google map
    return "Location not implemented";
}

void NormalBike::ToString() const {
    cout << "BIKE ID :" << GetId()
        << "Bike Type Is :NormalBike" << endl
        << "Price per hour : " << GetPricePerHour() << " EGP" << endl;
}
int NormalBike::GetId()const {
    return ID;
}
