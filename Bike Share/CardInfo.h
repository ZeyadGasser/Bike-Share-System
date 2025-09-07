#pragma once
#include <string>
using namespace std;

/**************CardInfo*****************/
class CardInfo {
public:
    CardInfo(const string& visaNumber, const string& expiryDate,
        const string& cvv, const string& phoneNumber);

    string GetVisaNumber() const;
    string GetExpiryDate() const;
    string GetCvv() const;
    string GetVisaPhoneNumber() const;

private:
    string visaNumber;
    string expiryDate;
    string cvv;
    string visaPhoneNumber;
};

