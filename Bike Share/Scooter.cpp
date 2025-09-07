#include "Scooter.h"
#include <iostream>

int Scooter::scooterID = 10000;//to avoid duplacte key

Scooter::Scooter(bool available_, int batteryPowerLevel_, double pricePerHour_)
    : available(available_), batteryPowerLevel(batteryPowerLevel_),
    isNeedMaintenance(false), pricePerHour(pricePerHour_), ID(++scooterID) {
}

bool Scooter::Start() {
    return true;
}

bool Scooter::Stop() {
    return true;
}

bool Scooter::Park() {
    return true;
}

double Scooter::GetPricePerHour() const {
    return pricePerHour;
}

bool Scooter::IsAvailable() const {
    return available;
}

void Scooter::SetAvailable(bool available_) {
    available = available_;
}

bool Scooter::IsNeedMaintenance() const {
    return isNeedMaintenance;
}

void Scooter::SetNeedMaintenance(bool value) {
    isNeedMaintenance = value;
}

string Scooter::GetCurrentLocation() const {
    //need API to get location from Google map
    return "Location not implemented";
}

void Scooter::ToString() const {
    cout << "BIKE ID :" << GetId()
        << "Bike Type Is :Scooter" << endl
        << "Battery Power Level :" << GetBatteryPowerLevel() << "%"
        << endl
        << "Price per hour : " << GetPricePerHour() << " EGP" << endl;
}

int Scooter::GetBatteryPowerLevel() const {
    return batteryPowerLevel;
}

bool Scooter::CheckBatteryPowerLevel() const {
    if (GetBatteryPowerLevel() <= 20) {
        return false;
    }
    return true;
}

int Scooter::GetId()const {
    return ID;
}