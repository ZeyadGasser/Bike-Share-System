#pragma once
#include <string>
using namespace std;

/****************************************Bikes Interface***********************************************/

//Eaaaa ZOZ -->only mandatory behavior
// A Minimal Interface means you have the least number of methods in it.
// The least number of methods that if are not present, the class is not a bike
class IBike {
public:
    virtual bool Start() = 0;
    virtual bool Stop() = 0;
    virtual bool Park() = 0;

    virtual double GetPricePerHour() const = 0;

    virtual bool IsAvailable() const = 0;
    virtual void SetAvailable(bool available) = 0;

    virtual bool IsNeedMaintenance() const = 0;
    virtual void SetNeedMaintenance(bool value) = 0;

    virtual string GetCurrentLocation() const = 0;

    virtual void ToString() const = 0;
    virtual int GetId()const=0;
    virtual ~IBike() = default;
};

