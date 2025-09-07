#pragma once
#include <string>
#include"Invoice.h"
using namespace std;
/****************************************
 * Interface: IPaymentService
 * Purpose: Defines payment contract for all payment services
 ****************************************/

class IPaymentService {
public:
    // 1.The payment service does not create or own the invoice, it just updates it.
    // 2.Reference ensures that a valid Invoice object must be passed (cannot be null).
    virtual bool MakePayment(Invoice& invoice) = 0;
    virtual string GetServiceName() const = 0;
    virtual ~IPaymentService() {}
};
