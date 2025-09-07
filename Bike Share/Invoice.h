#pragma once
// Forward declaration
#include"Trip.h"

/****************************************Class Invoice************************************************/
class Invoice {
public:
    Invoice(const Trip& trip_);

    double GetTotalCost() const;
    bool GetIsPayBill() const;
    void SetIsPayBill(bool isPayBill_);

private:
    const Trip& trip;
    bool isPayBill;

    double CalculatePrice()const {
        return trip.GetTimeTrip() * trip.GetPricePerHourForBike();
    }
};

