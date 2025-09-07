#include "CardInfo.h"

CardInfo::CardInfo(const string& visaNumber, const string& expiryDate,
    const string& cvv, const string& phoneNumber)
    : visaNumber(visaNumber), expiryDate(expiryDate),
    cvv(cvv), visaPhoneNumber(phoneNumber) {
}

string CardInfo::GetVisaNumber() const {
    return visaNumber;
}

string CardInfo::GetExpiryDate() const {
    return expiryDate;
}

string CardInfo::GetCvv() const {
    return cvv;
}

string CardInfo::GetVisaPhoneNumber() const {
    return visaPhoneNumber;
}