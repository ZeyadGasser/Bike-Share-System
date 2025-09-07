#include "CashPayment.h"
#include "Invoice.h"

CashPayment::CashPayment() {
}

bool CashPayment::MakePayment(Invoice& invoice) {
    invoice.SetIsPayBill(true);
    return true;
}

string CashPayment::GetServiceName() const {
    return "Cash Payment";
}