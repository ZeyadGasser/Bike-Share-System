#pragma once
#include <map>
#include <string>
#include "IBike.h"
#include "Scooter.h"
#include "NormalBike.h"
using namespace std;

class BikeManager {
public:
    BikeManager();
    ~BikeManager();

    bool AddBike(IBike* bike);
    bool RemoveBike(int bikeId);
    IBike* SearchBike(int bikeId);
    void LoadDataBase();

private:
    map<int, IBike*> bikes; // key = bikeId
};
