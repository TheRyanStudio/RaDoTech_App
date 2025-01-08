#ifndef DEVICESCANNER_H
#define DEVICESCANNER_H

#include <string>
#include <vector>
#include <random>
#include <iostream>

class DeviceScanner
{
    private:
        double nodeData;            // Data generated during scanning
        bool operationStatus;      // True if the scanner is active
        int currentMeridianPoint; // Tracks the active scanning point
        bool hasContact;         // Indicates body contact with the device

    public:
        DeviceScanner();
        int startScan();
        void endScan();
        double generateNodeData();
        bool getHasContact(){ return hasContact;} // Checks if contact exists
        void setHasContact() { hasContact = !hasContact; } // Toggles contact status
};

#endif
