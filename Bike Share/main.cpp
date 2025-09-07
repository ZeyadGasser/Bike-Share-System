#include <iostream>
#include "UIManager.h"
#include "UserManager.h"
#include "StationsManager.h"
using namespace std;

class BikeShareSystem {
private:
    UserManager userManager;
    StationsManager stationsManager;
    UIManager* ui;

public:
    BikeShareSystem() {
        cout << "Bike Share System Initialized!" << endl;
        stationsManager.LoadDataBase();
        userManager.LoadDataBase();

        ui = new UIManager(userManager, stationsManager);
    }

    ~BikeShareSystem() {
        delete ui;
    }

    void Start() {
        ui->StartSite();
    }
};

int main() {
    cout << "Check the UML diagrams to quickly understand the Bike & Scooter Rental System." << endl;

    BikeShareSystem system;
    system.Start();

    return 0;
}
