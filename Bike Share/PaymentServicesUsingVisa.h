#pragma once
#include "IPaymentService.h"

class PaymentServicesUsingVisa : public IPaymentService {
public:
    // This class does not override MakePayment or GetServiceName 
    // because it is meant to remain abstract as a base for Visa-based services.
    virtual ~PaymentServicesUsingVisa() {}
};
