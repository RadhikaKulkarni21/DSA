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
    bool direction;//true go up, false go down
    bool request;
};

class Building{
public:
    int floor;
    int totalFloors;
    Elevator elevator;
};