#pragma once
#include "UserManager.h"
#include "StationsManager.h"
#include "IPaymentService.h"
#include "CashPayment.h"
#include "PaymentServicesUsingVisa.h"
#include "PayPal.h"
#include "Invoice.h"
#include "Trip.h"
#include <iostream>
#include <string>
using namespace std;

class UIManager {
public:
    UIManager(UserManager& userMgr, StationsManager& stationMgr);
    void AccessSystem(User* user);
    void CustomerView();

    void StartSite();
    void RentBike(const string& stationName);
    void EndTripView(const string& stationName, int bikeID);
    void PrintInvoice(Trip* trip, Invoice* invoice); 
    ~UIManager();
private:
    UserManager& userManager;
    StationsManager& stationsManager;
    User* currentUser = nullptr;
    CardInfo* cardInfo = nullptr;
    Trip* newTrip = nullptr;
    Invoice* newInvoice = nullptr;
    IPaymentService* paymentService = nullptr;
};
