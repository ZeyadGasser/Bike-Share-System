#pragma once
#include <string>
using namespace std;

// Forward declaration
class StationOperator;

/****************************************Class Station***********************************************/
class Station {
public:
    Station(const string& stationName_, StationOperator* stationOperator_, const string& stationLocatin_);

    string GetStationName() const;
    StationOperator* GetStationOperator() const;
    string GetStationLocatin() const;

private:
    string stationName;
    string stationLocatin;
    StationOperator* stationOperator;
};

