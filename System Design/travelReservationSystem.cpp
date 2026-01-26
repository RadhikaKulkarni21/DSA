#include "R:\C++\Project1\lcHeader.h"

class Seat{
public:
    int seatNo;
    bool isbooked;

    Seat(int sn) : seatNo(sn), isbooked(false) {};

    void displaySeats(){
        cout << "Seat: " << seatNo << (isbooked ? " Booked" : " Available") << endl;
    }
};

class Bus{
public:
    int busNo;
    string destination;
    string origin;
    vector<Seat> seats;

    Bus(int bn, string d, string o, int totalSeats) : busNo(bn),destination(d), origin(o){
        for(int i = 1; i <= totalSeats; i++){
            seats.push_back(Seat(i));
        }
    }
    
    bool bookSeat(int seatNo){
        for(auto &s : seats){
            if (s.seatNo == seatNo && !s.isbooked){
                s.isbooked = true;
                return true;
            }
        }
        return false;
    }

    Seat* getSeat(int seatNo){
        for(auto &seat : seats){
            if(seat.seatNo == seatNo){
                return &seat;
            }
        }
        return nullptr;
    }

    void displayBus(){
        cout << "Bus No.: " << busNo << endl;
        cout << "Bus Origin: " << origin << endl;
        cout << "Bus Destination: " << destination << endl;

        for(auto s : seats){
            if(s.isbooked) s.displaySeats();
        }
    }
};

class Passenger{
public:
    string name;

    Passenger(string n) : name(n) {};
};

class Ticket{
public:
    Passenger &p;
    Seat &s;
    Bus &b;

    Ticket(Passenger &pg, Seat &st, Bus &bn) : p(pg), s(st), b(bn) {};

    void displayTicket(){
        cout << "Ticket Details:" << endl;
        cout << "Passenger: " << p.name << endl;
        cout << "Bus No.: " << b.busNo << " Origin: " << b.origin << " Destination: " << b.destination << endl;
        cout << "Seat no.: " << s.seatNo << endl; 
    }
};

int main(){
    Bus bus(1, "Busan", "Seoul", 50);

    Passenger p1("Wooje");

    int seatNeeded = 2;//this is seat number needed

    if (bus.bookSeat(seatNeeded)) {
        Seat* bookedSeat = bus.getSeat(seatNeeded);
        Ticket t1(p1, *bookedSeat, bus);
        t1.displayTicket();
    } else {
        cout << "Seat not available!" << endl;
    }

    cout << "\nCurrent Bus Status:\n";
    bus.displayBus();

    return 0;
}