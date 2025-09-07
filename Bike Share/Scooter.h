#pragma once
#include "IBike.h"

/*******************************/
class Scooter : public IBike {
public:
    Scooter(bool available_, int batteryPowerLevel_, double pricePerHour_);

    bool Start() override;
    bool Stop() override;
    bool Park() override;

    double GetPricePerHour() const override;

    bool IsAvailable() const override;
    void SetAvailable(bool available_) override;

    bool IsNeedMaintenance() const override;
    void SetNeedMaintenance(bool value) override;

    string GetCurrentLocation() const override;
    int GetId()const override;

    void ToString() const override;
    int GetBatteryPowerLevel() const;
    bool CheckBatteryPowerLevel() const;

private:
    bool available, isNeedMaintenance;
    int batteryPowerLevel;
    double pricePerHour;
    static int scooterID;
    int ID;
};

