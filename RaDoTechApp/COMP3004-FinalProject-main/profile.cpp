#include "profile.h"

Profile::Profile(int profileID, const std::string& name, const std::string& email, double weight, double height, std::string dob, const std::string& phone, const std::string& password)
    : name(name), phoneNumber(phone), emailAddress(email), weight(weight), height(height), profileID(profileID), dateOfBirth(dob), password(password) {
}
