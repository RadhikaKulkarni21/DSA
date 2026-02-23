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
    Vehicle* parkedVechile;

    ParkingSpot(SpotType st, int sid) : 
    spotType(st), spotId(sid), occupied(false), parkedVechile(nullptr){};

    bool spotForVehicleType(VehicleType vt){
        if (spotType == small && vt == BICYCLE) return true;
        if (spotType == medium && (vt == BIKE || vt == BICYCLE)) return true;
        if (spotType == large && (vt == BIKE || vt == CAR)) return true;
        if (spotType == cargo &&  vt == CARGO) return true;
        return false;
    }

    void parkvehicle(Vehicle* v){
        parkedVechile = v;
        occupied = true;
    }

    void unParkvehicle(){
        parkedVechile = nullptr;
        occupied = false;
    }
};

class Ticket{
public:
    int ticketId;
    Vehicle* vehicle;
    ParkingSpot* spot;
    time_t entryStamp;
    time_t exitStamp;

    Ticket(int id, Vehicle* v, ParkingSpot* s) :
    ticketId(id), vehicle(v), spot(s){
        entryStamp = time(nullptr);
        exitStamp = 0;
    }

    void closeTicket(){
        exitStamp = time(nullptr);
    }

    double calculateParkingFees(){
        double hours = difftime(exitStamp, entryStamp) / 3600;
        if(hours < 1) hours = 1;//imposing need to pay for atleast an hour
        return hours * 10;
    }
};

class Level{
public:
    int levelNo;
    vector<ParkingSpot> spots;

    Level(int id, int totalSpots) : levelNo(id){
        for(int i = 0; i < totalSpots;i++){
            if(i  < totalSpots / 4){
                spots.emplace_back(small, i);
            }
            else if(i < 2 * totalSpots / 4){
                spots.emplace_back(medium, i);
            }
            else if(i  < 3 * totalSpots / 4){
                spots.emplace_back(large, i);
            }
            else spots.emplace_back(cargo, i);
        }
    };

    ParkingSpot* findAvailableSpots(VehicleType type){
        for(auto& spot : spots){
            if(!spot.occupied && spot.spotForVehicleType(type)){
                return &spot;
            }
        }
        return nullptr;
    }
};

class ParkingLot{
public:
    vector<Level> levels;
    int nextTicketId;

    ParkingLot(int numLevels, int spotsPerLevel)
        : nextTicketId(1) {
        for (int i = 0; i < numLevels; i++) {
            levels.emplace_back(i, spotsPerLevel);
        }
    }

    Ticket* parkVehicle(Vehicle* vehicle) {
        for (auto& level : levels) {
            ParkingSpot* spot = level.findAvailableSpots(vehicle->vehicleType);
            if (spot) {
                spot->parkvehicle(vehicle);
                Ticket* ticket = new Ticket(nextTicketId++, vehicle, spot);
                cout << "Vehicle parked. Ticket ID: " << ticket->ticketId << endl;
                return ticket;
            }
        }
        cout << "Parking Full!" << endl;
        return nullptr;
    }

    void unparkVehicle(Ticket* ticket) {
        ticket->closeTicket();
        double fee = ticket->calculateParkingFees();
        ticket->spot->unParkvehicle();

        cout << "Vehicle exited. Fee: $" << fee << endl;
    }
};

int main() {
    ParkingLot lot(2, 9);

    Vehicle car(CAR, "ABC123");
    Ticket* ticket = lot.parkVehicle(&car);

    // Simulate exit
    if (ticket) {
        lot.unparkVehicle(ticket);
    }
}

//we can pass the time into timestamps to showcase the ticket pricing