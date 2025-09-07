#include "UIManager.h"

UIManager::UIManager(UserManager& userMgr, StationsManager& stationMgr)
    : userManager(userMgr), stationsManager(stationMgr) {
}


UIManager::~UIManager(){
    delete cardInfo;
    delete newInvoice;
    delete newTrip;
    delete paymentService;
    cardInfo = nullptr;
    newInvoice = nullptr;
    newTrip = nullptr;
    paymentService = nullptr;
    currentUser = nullptr;//I dont delet this to avoid double deletet because userManger has ownerShip for this user
}




////////////////////////////////////////////StartSite//////////////////////////////////////////////////////////

void UIManager::StartSite() {
    cout << "===== Welcome to Bike Sharing System =====" << endl;

    int choice;
    cout << "1. Login\n2. SignUp\nChoose: ";
    cin >> choice;

    if (choice == 1) {
        // Login 
        string username, password;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;


        if (userManager.login(username, password)) {
            currentUser = userManager.search(username);
            AccessSystem(currentUser);
        }
        else {
            cout << "Login failed. Try again.\n";
            return;
        }
    }
    else if (choice == 2) {
        // SignUp
        string username, password, nid;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        cout << "Enter National ID: ";
        cin >> nid;

        // Card Information
        string visaNumber, expiryDate, cvv, phoneNumber;
        cout << "Enter Visa Number: ";
        cin >> visaNumber;
        cout << "Enter Expiry Date (MM/YY): ";
        cin >> expiryDate;
        cout << "Enter CVV: ";
        cin >> cvv;
        cout << "Enter Phone Number: ";
        cin >> phoneNumber;
        cardInfo = new CardInfo(visaNumber, expiryDate, cvv, phoneNumber);
        currentUser = new Customer(username, password, nid, *cardInfo);

        if (userManager.signUp(currentUser)) {
            cout << "SignUp successful. You can now login.\n";
            StartSite();
        }
        else {
            cout << "Username already exists.\n";
            StartSite();
        }
    }
    else {
        cout << "Invalid choice.\n";
        StartSite();
    }
}


/////////////////////////////////////////AccessSystem/////////////////////////////////////////////////////////////
void UIManager::AccessSystem(User* user) {
    string role = user->showRole();
   
    if (role == "Admin") {
        cout << "Welcome Admin "<<user->getUserName() << endl;
         //AdminView();
    }
    else if (role == "Customer") {
        cout << "Welcome Customer!" << user->getUserName() << endl;
         CustomerView();
    }
    else if (role == "StationOperator") {
        cout << "Welcome Operator!" << user->getUserName() << endl;
        //StationOperatorView();
    }
    else if (role == "MaintenanceTechnician") {
        cout << "Welcome Technician!" << user->getUserName() << endl;
        //MaintenanceTechnicianView();
    }
    else {
        cout << "Unknown role!" << endl;
    }

}

////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\////////////////////////////
void UIManager::CustomerView() {
    //need use google location but i assume some station near by user
    cout << "\n===== Customer Menu =====\n";
    cout << "1. Show nearby stations (assumed by location)\n";
    cout << "2. Logout\n";
    
    int choice,counter=1;
    cout << "Enter your choice: ";
    cin >> choice;
    cout << endl;
    if (choice == 1) {
        for (auto& it : stationsManager.GetAllStation()) {
            cout << "station"<< counter <<" :" << it.first << endl;
            counter++;
        }
        cout << "These are all the stations near you:" << endl;
        cout << "Choose a station to rent from (enter the number, e.g., 1, 2, 3...): \n";
        cout << "Enter youe choice :";
        cin >> choice;
        cout << "\nFor simplicity, we assume you rent a bike from Station A" << endl;
        cout << "and you will return it later at Station B." << endl;
        RentBike("StationA");
    }
    else if (choice == 2) {
        return;
    }
    else {
        cout << "Invalid choice.\n";
        CustomerView();
    }
}

////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\/////////////////\\\\\\\\\\\\\\////////////

void UIManager::RentBike(const string& stationName) {

     cout << "\n===== Available Bikes at " << stationName << " =====\n";
     const auto& stations = stationsManager.GetAllStation();
     auto it = stations.find(stationName);
     if (it == stations.end()) {
         cout << "Station not found!\n";
         return;
     }

     const vector<IBike*>& bikes = it->second;

     if (bikes.empty()) {
         cout << "No bikes available at this station. Please go to another station.\n";
         CustomerView(); 
         return;
     }
     for (auto bike : bikes) {
         bike->ToString();
     }

    int choice;
    cout << "Choose a bike by ID: ";
    cin >> choice;
    bool checkChoice=0;
    for (auto bike : bikes) {
        if (bike->GetId() == choice&&!bike->IsNeedMaintenance()) {
            checkChoice = 1;
            if (auto c = dynamic_cast<Customer*>(currentUser)) {
                c->SetBike(bike);
                
                //I need delet it from user leter
            }
            break;
        }
    }
    if (checkChoice) {
        cout << "Ok pro Bon voyage :) \n";
       // stationsManager.RemoveBike(stationName, choice);//error the customer Use-after-free
       //i need delet it from this station 
        if (auto c = dynamic_cast<Customer*>(currentUser)) {
            if (c->GetInfoBikeWhoseCustomerRentIt().Start()) {
                newTrip = new Trip(*c,"4:30");
                cout << "You are start trip at :"<< newTrip->GetStartTimeTrip();
            }
        }
    }
    else {
        cout << "Iviled choice\n";
        RentBike(stationName);
    }

    //I assume after user compleat trip he select ent trip and park in stationB;
    EndTripView("StationB",choice);
   

    
  
}

void UIManager::EndTripView(const string& stationName, int bikeID) {
    auto& availableBikes = stationsManager.GetAllStation();
    auto& ListOfBike = availableBikes.at(stationName);
    for (auto bike : ListOfBike) {
        if (bike->GetId() == bikeID) {
            //park in stationB
            stationsManager.AddBike(stationName, bike);
            cout << "\nBike returned to StationB successfully.\n";
           
        }
    }
    newInvoice = new Invoice(*newTrip);
    PrintInvoice(newTrip, newInvoice);

    cout << "Choose payment method:\n";
    cout << "1. Cash\n";
    cout << "2. PayPal\n";

    int choice;
    cin >> choice;

    if (choice == 1) {
        paymentService = new CashPayment();
        if (paymentService->MakePayment(*newInvoice)) {
            cout << "Thank you :)";
            return;
        }
    }
    else if (choice == 2) {
        cout << "You chose PayPal. Redirecting to PayPal payment...\n";
        paymentService = new PayPal(*cardInfo);
        if (paymentService->MakePayment(*newInvoice)) {
            cout << "Thank you :)";
            return;
        }
    }
    else {
        cout << "Invalid choice. Defaulting to Cash.\n";
    }
  

  
}

 void UIManager::PrintInvoice(Trip* trip, Invoice* invoice) {
    int countMaintenanceTicket = trip->GetCustomer().GetCountTicket();
    double tripCost = invoice->GetTotalCost();
    double maintenanceCost = countMaintenanceTicket * priceMaintenanceTicket;
    double totalCost = tripCost + maintenanceCost;

    cout << "==================== INVOICE ====================" << endl;
    cout << "Customer: " << trip->GetCustomer().getUserName() << endl;
    cout << "Trip Start: " << trip->GetStartTimeTrip() << endl;
    cout << "Trip End: " << trip->GetEndTimeTrip() << endl;
    cout << "Trip Duration: " << trip->GetTimeTrip() << " hours" << endl;
    cout << "Price per Hour: " << trip->GetPricePerHourForBike() << " EGP" << endl;
    cout << "Trip Cost: " << tripCost << " EGP" << endl;
    cout << "Maintenance Tickets: " << countMaintenanceTicket << endl;
    cout << "Maintenance Cost: " << maintenanceCost << " EGP" << endl;
    cout << "=================================================" << endl;
    cout << "TOTAL COST: " << totalCost << " EGP" << endl;
    cout << "=================================================" << endl;
}
