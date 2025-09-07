#pragma once
#include "IPaymentService.h"

class CashPayment : public IPaymentService {
public:
    CashPayment();
    bool MakePayment(Invoice& invoice) override;
    string GetServiceName() const override;
};
