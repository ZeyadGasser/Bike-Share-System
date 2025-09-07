#pragma once
#include "IBike.h"

/*******************************/
class NormalBike : public IBike {
public:
    NormalBike(bool available_, double pricePerHour_);

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

private:
    bool available, isNeedMaintenance;
    double pricePerHour;
    static int normalBikeID;
    int ID;
};
