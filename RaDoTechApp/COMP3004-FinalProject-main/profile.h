#ifndef PROFILE_H
#define PROFILE_H

#include <string>

class Profile
{
private:
    std::string name;
    std::string phoneNumber;
    std::string emailAddress;
    double weight;
    double height;
    int profileID;
    std::string dateOfBirth;
    std::string password;


public:
    Profile(int profileID, const std::string& name, const std::string& email, double weight, double height, std::string dob, const std::string& phone, const std::string& password);

    //getters
    std::string getName(){ return name; }
    std::string getPhoneNumber(){ return phoneNumber; }
    std::string getEmailAddress(){ return emailAddress; }
    double getWeight(){ return weight; }
    double getHeight(){ return height; }
    std::string getDateOfBirth(){ return dateOfBirth; }
    std::string getPassword(){ return password; }
    int getProfileID(){return profileID;}

    //setters
    void setName(std::string n) { name = n; }
    void setPhoneNumber(std::string pn) { phoneNumber = pn; }
    void setEmailAddress(std::string ea) { emailAddress = ea; }
    void setWeight(double w) { weight = w; }
    void setHeight(double h) { height = h; }
    void setDateOfBirth(std::string dob) { dateOfBirth = dob; }
    void setPassword(std::string p) { password = p; }

};

#endif
