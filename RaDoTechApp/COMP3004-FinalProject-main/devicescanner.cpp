#include "devicescanner.h"

#include <random>
#include <ctime>
#include <cstdlib>

// Sets the operational status of the device scanner to false and whether the device has contact to false.
DeviceScanner::DeviceScanner()
{
    operationStatus = false;
    hasContact = false;
}

// Generates data for the scan, then calculates a value based on the result
int DeviceScanner::startScan()
{
    if (!getHasContact()){
           std::cout << "Error: Device is not touching skin" << std::endl;
        return -1;
    }

    operationStatus = true;
    double nodeDataArray[12];
    double sum =0;

    for (int i = 0; i < 12; i++){
        //currentMeridianPoint = listOfMeridianPoints[i];
        nodeDataArray[i] = generateNodeData();
        sum+= nodeDataArray[i];
    }
    sum = sum/24;
    return sum;
}

// Sets the operation status of the device scanner to false to end the scan.
void DeviceScanner::endScan()
{
    operationStatus = false;
}

//Generates the values for the scan
double DeviceScanner::generateNodeData()
{
    return (double)(rand() %20100) /100.00;
}
