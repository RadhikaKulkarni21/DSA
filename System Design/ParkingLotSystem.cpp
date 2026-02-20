/*
Parking Lot System
 -	Classes: ParkingLot, Vehicle, Ticket.
 -	Add-ons: levels, spot allocation, time-based fee.
*/

#include "R:\C++\Project1\lcHeader.h"

enum VehicleType{
    CAR,
    BIKE,
    CARGO,
    BICYCLE
};

enum SpotType{
    small,
    medium,
    large,
    cargo
};

class Ticket{
public:
    int ticketId;
    float duration;
    int baseCost;

    Ticket(int tid, float d, int bc) : ticketId(tid), duration(d), baseCost(bc){};
};

class Vehicle{
public:
    VehicleType vehicleType;
    string vehicleNumber;

    Vehicle(VehicleType vt, string vm) :vehicleType(vt) ,vehicleNumber(vm) {};

};

class ParkingSpot{
public:
    SpotType spotType;
    int spotId;
    bool occupied;

    ParkingSpot(SpotType st, int sid) : spotType(st), spotId(sid){ occupied = false;}; 
};

class ParkingLot{
public:
    int totalSpots;
    bool spotAvailable;

    ParkingLot(int ts) : totalSpots(ts){};
};