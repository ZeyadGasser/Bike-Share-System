#include"Invoice.h"

Invoice::Invoice(const Trip& trip_) :trip(trip_), isPayBill(false) {}

double Invoice:: GetTotalCost() const { return CalculatePrice(); }

bool Invoice::GetIsPayBill() const { return isPayBill; }

void Invoice::SetIsPayBill(bool isPayBill_) { isPayBill = isPayBill_; }
      
