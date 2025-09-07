#include "Station.h"
#include "StationOperator.h"

Station::Station(const string& stationName_, StationOperator* stationOperator_, const string& stationLocatin_)
    : stationName(stationName_), stationOperator(stationOperator_), stationLocatin(stationLocatin_) {
}

string Station::GetStationName() const {
    return stationName;
}

StationOperator* Station::GetStationOperator() const {
    return stationOperator;
}

string Station::GetStationLocatin() const {
    return stationLocatin;
}