#ifndef RADOTECHAPP_H
#define RADOTECHAPP_H

#include <string>
#include <iostream>
#include <vector>

#include "radotechdevice.h"
#include "profile.h"
#include "devicescanner.h"
#include "scanresult.h"
#include "defs.h"

class RaDoTechApp
{
private:
    int currentUser, dataHistory;
    bool connectionStatus;
    std::vector<Profile> userProfiles;
    std::vector<ScanResult> resultsList;
    int profileID;

public:
    RaDoTechApp();

    // Profile control
    bool createProfile(const std::string& name, const std::string& email,
                        double weight, double height, std::string dob, const std::string& phone,
                        const std::string& password);
    void updateProfile(double weight, double height);
    bool removeProfile(int profileID);
    bool login(const std::string& email, const std::string& password);
    bool emailExists(const std::string& email);

    // Scan ***********
    std::vector<ScanResult> fetchScanList() {return resultsList;}
    void notesPostScan();

    // Battery control
    void notifyLowBattery();
    void handleShutdown();

    // History
    void retrieveHistory();
    void navigateHistory();
    void requestScanHistory();

    // Display
    void displayInstructions();
    void displayScanResults();

    // Getters & Setters
    int getProfileID(){ return profileID; }
    void setCurrentUser(int currUser){currentUser= currUser ;}
    int getNumUsers(){return userProfiles.size();}
    int getCurrentUser(){ return currentUser ;}
    void clearProfiles() {userProfiles.clear(); }
    std::string getUserEmailByID(int userID);
    void setPostScan(double b, double h, double t, double s);

    void connectToDevice(RaDoTechDevice& device);
    void startMeasurement();

    RaDoTechDevice device;
    DeviceScanner scanner;
};

#endif // RADOTECHAPP_H
