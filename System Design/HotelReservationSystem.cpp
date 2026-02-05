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
        cout << "Room No.: " << roomNo << endl << "Type: " << type << endl 
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
        }

        if(!room || !guest){
            cout << "Invalid request" << endl;
        }
        room->isBooked = true;

        Booking* b = new Booking(room, guest, stayDays, totalGuests);
        bookings.push_back(b);

        cout<< "Booking successful for " << guest->guestName << endl
        << "Room type: " << room->type << " Room No: " << room->roomNo << endl
        << "Total cost: " << b->calculatePrice() << endl;
    }
};

int main(){
    //TODO
}