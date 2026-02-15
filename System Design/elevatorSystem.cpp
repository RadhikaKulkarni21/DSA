/*
The building has multiple floors.
There are multiple elevators.
Users can:
Call an elevator from any floor (Up / Down button).
Select a destination floor from inside the elevator.
The system should:
Assign the best elevator to a request.
Move elevators in the correct direction.
Open/close doors at the right time.
Elevators should not exceed capacity.
*/

#include "R:\C++\Project1\lcHeader.h"

class Elevator{
public:
    int elevatorId;
    double capacity;
    float doorDuration;

    Elevator(int ei, double c, float dr) : elevatorId(ei), capacity(c), doorDuration(dr) {};
};

class Building{
public:
    int floor;
    int totalFloors;
    int totalAvailableElevators;

    Building(int f, int tf, int tae) : floor(f), totalFloors(tf), totalAvailableElevators(tae){};
};

class Direction{
public:
    bool goingup;
    bool goingDown;
};

class Operation{
public:
    bool direction;//true go up, false go down 
    int floorRequest;
    
};

int main(){

}