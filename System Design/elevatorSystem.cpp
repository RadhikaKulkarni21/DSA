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

enum Direction{
    UP,
    DOWN,
    IDLE
};

class Elevator{
public:
    int elevatorId;
    double capacity;
    int currentFloor;
    int currentLoad;
    Direction direction;

    vector<int> requests;

    Elevator(int ei, double c, int cf, int cl, Direction(d)) : elevatorId(ei), capacity(c), currentFloor(cf), currentLoad(cl), direction(d) {};

    int getCurrentFloor(){
        return currentFloor;
    }

    Direction getDirection(){
        return direction;
    }

    bool isIdle() const {
        return requests.empty();
    }

    void addRequest(int floor){
        requests.push_back(floor);
        updateDirection();
        sortRequests();
    }

    void updateDirection(){
        if(requests.empty()){
            direction = IDLE;
            return;
        }
        if (currentFloor < requests.front())
            direction = UP;
        else if (currentFloor > requests.front())
            direction = DOWN;
    }

    void sortRequests(){
        if (direction == UP)
            sort(requests.begin(), requests.end());
        else if (direction == DOWN)
            sort(requests.rbegin(), requests.rend());
    }

    void openDoor(){
        cout << "Door Opening at " << "Floor: " << currentFloor << endl;
    }
    void move(){
        if(requests.empty()){
            direction = IDLE;
            return;
        }

        int goToFloor = requests.front();

        if(currentFloor > goToFloor){
            currentFloor--;
            direction = DOWN;
        }
        else if(currentFloor < goToFloor){
            currentFloor++;
            direction = UP;
        }

        if(currentFloor == goToFloor){
            openDoor();
            requests.erase(requests.begin());
        }
    }
};

class Building{
public:
    int floor;
    int totalFloors;
    int totalAvailableElevators;

    Building(int f, int tf, int tae) : floor(f), totalFloors(tf), totalAvailableElevators(tae){};
};

class Operation{
public:
    bool direction;//true go up, false go down 
    int floorRequest;
    
};

int main(){

}