#include "R:\C++\Project1\lcHeader.h"

/*
Hotel Room Booking
 o Classes: Room, Guest, Booking.
 o Add-ons: check-in/check-out, availability.
*/

enum RoomType{
    single,
    twin,
    king,
    queen
};

//Enum to string conversion
string roomTypeToString(RoomType type) {
    switch (type) {
        case single: return "Single";
        case twin:   return "Twin";
        case king:   return "King";
        case queen:  return "Queen";
        default:     return "Unknown";
    }
}

class Guest{
public:
    string guestName;
    int guestId;

    Guest(string n, int gid) : guestName(n), guestId(gid){};

    void displayGuest(){
        cout<< "Welcome " << guestName << endl;
    }
};

class Room{
public:
    int roomNo;
    RoomType type;
    double price;
    bool isBooked = false;//availability

    Room(int rn, RoomType rt, double p) : roomNo(rn), type(rt) ,price(p) {};

    double getPrice(){
        return price;
    }

    void displayRoom(){
        cout << "Room No.: " << roomNo << endl 
        << "Type: " << roomTypeToString(type) << endl 
        << "Cost: " << price << " per night" << endl 
        << (isBooked ? "Booked" : "Available") << endl;
    }
};

class Booking{
public:
    Room* room;
    Guest* guest;
    int stayDays;
    int totalGuests;

    Booking(Room* r, Guest* g, int sd, int tg) : 
    room(r), guest(g), stayDays(sd), totalGuests(tg) {};

    double calculatePrice(){
        //total people will be the size of Guests vector
        return room->getPrice() * stayDays * totalGuests;
    }
};

class Hotel{
private:
    vector<Room*> rooms;
    vector<Guest*> guests;
    vector<Booking*> bookings;

public:
    void addRooms(Room* room){
        rooms.push_back(room);
    }

    void addGuests(Guest* guest){
        guests.push_back(guest);
    }

    Room* findRoom(int roomNo){
        for(auto r : rooms){
            if(r->roomNo == roomNo){
                return r;
            }
        }
        return nullptr;
    }

    Guest* findGuest(string guestName){
        for(auto guest : guests){
            if(guest->guestName == guestName){
                return guest;
            }
        }
        return nullptr;
    }

    void addBooking(int roomNo, string guestN, int stayDays,int totalGuests){
        Room* room = findRoom(roomNo);
        Guest* guest = findGuest(guestN);

        if(room->isBooked){
            cout << "Room is already booked" << endl;
            return;
        }

        if(!room || !guest){
            cout << "Invalid request" << endl;
            return;
        }
        room->isBooked = true;

        Booking* b = new Booking(room, guest, stayDays, totalGuests);
        bookings.push_back(b);

        cout<< "Booking successful for " << guest->guestName << endl
        << "Room type: " << roomTypeToString(room->type) 
        << " Room No: " << room->roomNo << endl
        << "Total cost: " << b->calculatePrice() << endl;
    }
};

int main(){
    Hotel hotel;

    //add rooms
    Room* room1 = new Room(101, single, 50);
    Room* room2 = new Room(102, twin, 100);
    Room* room3 = new Room(103, king, 300);

    hotel.addRooms(room1);
    hotel.addRooms(room2);
    hotel.addRooms(room3);

    //add guests
    Guest* guest1 = new Guest("Jihoon Jung", 1);
    Guest* guest2 = new Guest("Kiin Kim", 2);

    hotel.addGuests(guest1);
    hotel.addGuests(guest2);

    //add booking
    hotel.addBooking(101, "Kiin Kim", 4, 1);
    hotel.addBooking(102, "Jihoon Jung", 5, 2);
    hotel.addBooking(103, "Park Jaehyuk", 3, 1);
}