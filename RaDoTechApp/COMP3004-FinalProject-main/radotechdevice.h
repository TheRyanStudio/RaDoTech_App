#ifndef RADOTECHDEVICE_H
#define RADOTECHDEVICE_H

#include <string>
#include <iostream>
#include <vector>

class RaDoTechDevice
{
private:
    int batteryStatus;
    bool bluetoothStatus;
    bool powerStatus;

public:
    //Initializing the variables.
    RaDoTechDevice(/* args */){
        bluetoothStatus = false;
        powerStatus = false;
        batteryStatus = 100;
    };

    // Device Control
    void powerOn();
    void powerOff();

    // Battery Control

    // Drains the battery by 25 everytime it is called
    // and if it meets one of the conditions, a message will be outputted.
    void drainBattery(){
            batteryStatus -=25;

            if (batteryStatus <= 0){
                std::cout << "Battery is dead." << std::endl;
                return;
            } if (batteryStatus == 25){
                std::cout << "Low battery. Recharge battery." << std::endl;
                return;
            }
    }

    // Carges the battery to full charge (100) when it is called
    void chargeBattery(){
        std::cout <<"Battery status set to 100" << std::endl;
        batteryStatus = 100;
    }

    // Getters and Setters
    int getBatteryStatus() { return batteryStatus;}
    bool getBluetoothStatus(){ return bluetoothStatus;}
    void setBluetoothStatus(bool bs){ bluetoothStatus = bs;}
    void setPowerStatus(){ powerStatus = !powerStatus; }
    bool getPowerStatus(){ return powerStatus;}

};

#endif
