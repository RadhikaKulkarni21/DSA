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
    int currentFloor;
    Direction direction;

    vector<int> requests;

    Elevator(int ei) : elevatorId(ei), currentFloor(0), direction(IDLE) {};

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
    vector<Elevator> elevators;
    int totalFloors;

    Building(int floors, int numEle): totalFloors(floors){
        for(int i = 0; i < numEle; i++){
            elevators.emplace_back(i);
        }
    }

    void requestElevator(int floor, Direction d){
        Elevator* hailElevator = nullptr;

        for(auto& e : elevators){
            if(e.isIdle()){
                hailElevator = &e;
                break;
            }
        }

        if(!hailElevator){
            hailElevator = &elevators[0];
        }

        hailElevator->addRequest(floor);
    }

    void movement(){
        for(auto& e: elevators){
            e.move();
        }
    }
};


int main(){
    Building building(10, 2);

    building.requestElevator(5, UP);
    building.requestElevator(8, UP);

    // Simulate steps
    for (int i = 0; i < 15; i++) {
        building.movement();
    }

    return 0;
}