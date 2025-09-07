#include "PayPal.h"
#include "CardInfo.h"
#include "Invoice.h"

PayPal::PayPal(const CardInfo& cardInfo_) : PaymentServicesUsingVisa(), cardInfo(cardInfo_) {
}

bool PayPal::MakePayment(Invoice& invoice) {
    //Use PayPal API
    invoice.SetIsPayBill(true);
    return true;
}

string PayPal::GetServiceName() const {
    return "PayPal Services";
}