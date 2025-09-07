#pragma once
#include <vector>
#include <map>
#include <string>
#include "Station.h"
#include "IBike.h"
#include "Scooter.h"
#include "NormalBike.h"
#include <algorithm>
#include <iostream>
using namespace std;

class StationsManager {
public:
    StationsManager();
    ~StationsManager();

    bool AddBike(const string& stationName, IBike* bike);
    bool RemoveBike(const string& stationName, int bikeId);
    IBike* SearchBike(const string& stationName, int bikeId);
    const map<string, vector<IBike*>>& GetAllStation() const;
    void LoadDataBase();

private:
    /**
    What helped me in this case was working with a list of bikes during the design,
    which represents the cardinality relationship in UML.
    ***/
    map<string, vector<IBike*>> stations;
};
