#include "radotechapp.h"
#include <ctime>

RaDoTechApp::RaDoTechApp(){
    currentUser = -1;
    connectionStatus = false;
    profileID = 0;
}

// Profile Control, takes in values from mainwindow and creates a profile, pushes to vector
bool RaDoTechApp::createProfile(const std::string& name, const std::string& email, double weight, double height, std::string dob, const std::string& phone, const std::string& password) {

    if (userProfiles.size() >= MAX_PROFILES){
        std::cout << "Maximum number of profiles reached." << std::endl;
        return false;
    }

    Profile newProfile(profileID++, name, email, weight, height, dob, phone, password);
    userProfiles.push_back(newProfile);
    return true;
}
// Removes profile from vector
bool RaDoTechApp::removeProfile(int profileID)
{
    for (size_t i = 0; i < userProfiles.size(); i++){
        if (userProfiles[i].getProfileID() == profileID){
            currentUser = -1;
            userProfiles.erase(userProfiles.begin()+i);
            std::cout << "Profile " << profileID << " removed successfully." << std::endl;
            return true;
        }
    }

    std::cout << "Profile " << profileID << " does not exist." << std::endl;
    return false;
}

// Sets the current user based on email and password
bool RaDoTechApp::login(const std::string& email, const std::string& password)
{
    for (size_t i = 0; i < userProfiles.size(); i++) {
        if (userProfiles[i].getEmailAddress() == email && userProfiles[i].getPassword() == password) {
            currentUser = userProfiles[i].getProfileID();
            std::cout << "Successfully logged in as \"" << email << "\"." << std::endl;
            return true;
        }
    }
    std::cout << "Incorrect email and/or password. Please try again." << std::endl;
    return false;
}

// Device Control, runs when device is turned on
void RaDoTechApp::connectToDevice(RaDoTechDevice& device)
{
    if (device.getBatteryStatus() >= 25){
        connectionStatus = true;
        std::cout << "RaDoTech device connected successfully." << std::endl;
        return;
    } else {
        connectionStatus = false;
        std::cout << "RaDoTech device battery is too low to connect." << std::endl;
    }
}

// Generates data for the scan, then puts it in a ScanResult which is stored in a vector
void RaDoTechApp::startMeasurement()
{
    time_t timestamp;
    time(&timestamp);
    std::string dateTime = ctime(&timestamp);

    double avg = scanner.startScan();
    std::string name, phone, dob, email;
    for(size_t i =0; i< userProfiles.size(); i++){
        if(userProfiles[i].getProfileID() == getCurrentUser()){
            name = userProfiles[i].getName();
            phone = userProfiles[i].getPhoneNumber();
            dob = userProfiles[i].getDateOfBirth();
            email = userProfiles[i].getEmailAddress();
        }
    }
    srand(std::time(0));
    double a = 1+(rand() % 10) * avg;
    double b = 1+(rand() % 12) * avg;
    double c = 1+(rand() % 14) * avg;
    double d = 1+(rand() % 16) * avg;
    double e = 1+(rand() % 18) * avg;
    ScanResult sr = ScanResult(dateTime,name,a,b,c,d,e, phone, dob, email);
    resultsList.push_back(sr);

}

// Adds the info the users inputs after the scan is done
void RaDoTechApp::setPostScan(double b, double h, double t, double s)
{
    int lastPosition = resultsList.size() - 1;
    resultsList[lastPosition].setBloodPressure(b);
    resultsList[lastPosition].setHeartRate(h);
    resultsList[lastPosition].setTemp(t);
    resultsList[lastPosition].setSleepTime(s);
}

// Battery Control: calls the drainBattery function to drain the battery
void RaDoTechApp::notifyLowBattery()
{
    device.drainBattery();
}

// Checks if there is already a user with that email
bool RaDoTechApp::emailExists(const std::string& email)
{
    for (auto& profile : userProfiles) {
        if (profile.getEmailAddress() == email) {
            return true;
        }
    }
    return false;
}

// Returns email based on the matching user id
std::string RaDoTechApp::getUserEmailByID(int userID)
{
    for (auto& profile : userProfiles) {
        if (profile.getProfileID() == userID) {
            return profile.getEmailAddress();
        }
    }

    std::cout << "Error: User ID " << userID << " not found." << std::endl;
    return "";
}

// Updates members of profile based on user input
void RaDoTechApp::updateProfile(double weight, double height)
{
    for (size_t i = 0; i < userProfiles.size(); ++i) {
        if (userProfiles[i].getProfileID() == getCurrentUser()) {
            userProfiles[i].setWeight(weight);
            userProfiles[i].setHeight(height);
            return;
        }
    }
}
