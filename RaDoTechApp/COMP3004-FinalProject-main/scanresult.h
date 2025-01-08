#ifndef SCANRESULT_H
#define SCANRESULT_H

#include <string>

class ScanResult
{
private:
    /* data */
    std::string date;
    std::string name;
    std::string phone;
    std::string dob;
    std::string email;
    double energyValue;
    double immuneSystem;
    double metabolism;
    double psychoEmotionalStatus;
    double musculoskeletalSystem;
    double heartRate;
    double temp;
    double sleepTime;
    double bloodPressure;

public:
    // Getters for personal information
    std::string getName(){return name;}
    std::string getDate(){return date;}
    std::string getPhone(){return phone;}
    std::string getDob(){return dob;}
    std::string getEmail(){return email;}

    // Getters for health metrics
    double getEnergyLevel(){return energyValue;}
    double getImmuneSystem(){return immuneSystem;}
    double getMetabolism(){return metabolism;}
    double getPsychoEmotionalStatus(){return psychoEmotionalStatus;}
    double getMusculoskeletalSystem(){return musculoskeletalSystem;}
    double getBP(){return bloodPressure;}
    double getHR(){return heartRate;}
    double getTemp(){return temp;}
    double getSleepTime(){return sleepTime;}

    //Constructor
    ScanResult(std::string date2, std::string name2, double energyV,
                            double immuneS, double metabo, double psychoEmotionalS, double musculoskeletalS, std::string phone2, std::string dob2, std::string email2){
        date = date2;
        name = name2;
        energyValue = energyV;
        immuneSystem = immuneS;
        metabolism = metabo;
        psychoEmotionalStatus = psychoEmotionalS;
        musculoskeletalSystem = musculoskeletalS;
        phone = phone2;
        dob = dob2;
        email = email2;
    }

    //Setters
    void setBloodPressure(double b){bloodPressure = b;}
        void setHeartRate(double h){heartRate = h;}
        void setTemp(double t){ temp = t;}
        void setSleepTime(double s){ sleepTime = s;}
};

#endif
