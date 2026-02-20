/*
Parking Lot System
 -	Classes: ParkingLot, Vehicle, Ticket.
 -	Add-ons: levels, spot allocation, time-based fee.
*/

#include "R:\C++\Project1\lcHeader.h"

class Ticket{
    int ticketId;
    float duration;
    int baseCost;
    float totalCost;

    Ticket(int tid, float d, int bc) : ticketId(tid), duration(d), baseCost(bc){};

    float getTotalCost(){
        if(duration > 1){
            return baseCost * duration;
        }
    }
};

class Vehicle{
    string vehicleType;
    string vehicleNumber;
};

class ParkingLot{

};