#pragma once
#include "PaymentServicesUsingVisa.h"
#include"CardInfo.h"
class PayPal : public PaymentServicesUsingVisa {
public:
    PayPal(const CardInfo& cardInfo_);
    bool MakePayment( Invoice& invoice) override;
    string GetServiceName() const override;

private:
    // 1. PayPal does not own the CardInfo object, it just uses it.
    // 2. Reference guarantees that a valid CardInfo must exist (cannot be null).
    const CardInfo& cardInfo;
};
