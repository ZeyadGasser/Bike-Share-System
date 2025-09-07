#include "StationsManager.h"

StationsManager::StationsManager() {
}

StationsManager::~StationsManager() {
    for (auto& pair : stations) {
        for (auto* bike : pair.second) {
            delete bike;
        }
        pair.second.clear();
    }
    stations.clear();
    cout << "StationsManager destroyed and all bikes deleted" << endl;
}

bool StationsManager::AddBike(const string& stationName, IBike* bike) {
    auto& bikeList = stations[stationName];
    for (auto* b : bikeList) {
        if (b->GetId() == bike->GetId()) {
            return false;
        }
    }
    bikeList.push_back(bike);
    return true;
}

bool StationsManager::RemoveBike(const string& stationName, int bikeId) {
    auto it = stations.find(stationName);
    if (it != stations.end()) {
        auto& bikeList = it->second;
        auto bikeIt = remove_if(bikeList.begin(), bikeList.end(),
            [bikeId](IBike* b) { return b->GetId() == bikeId; });

        if (bikeIt != bikeList.end()) {
            for (auto i = bikeIt; i != bikeList.end(); ++i) {
                delete* i;
            }
            bikeList.erase(bikeIt, bikeList.end());
            return true;
        }
    }
    return false;
}

IBike* StationsManager::SearchBike(const string& stationName, int bikeId) {
    auto it = stations.find(stationName);
    if (it != stations.end()) {
        for (auto* b : it->second) {
            if (b->GetId() == bikeId) {
                return b;
            }
        }
    }
    return nullptr;
}

const map<string, vector<IBike*>>& StationsManager::GetAllStation() const {
    return stations;
}

void StationsManager::LoadDataBase() {
    cout << "Start Load DataBase For Some Bikes \n";


    string stationA = "StationA";
    NormalBike* normal1 = new NormalBike(true, 5.00);
    AddBike(stationA, normal1);

    Scooter* scooter1 = new Scooter(true, 80, 10.00);
    AddBike(stationA, scooter1);

   
    string stationB = "StationB";
    NormalBike* normal2 = new NormalBike(true, 7.00);
    AddBike(stationB, normal2);

    Scooter* scooter2 = new Scooter(true, 60, 10.00);
    AddBike(stationB, scooter2);
}
