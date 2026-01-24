/*
Design a Movie Ticket Booking System using Object-Oriented Programming.
The system should allow users to:
View available movies
View show timings for a selected movie
Select seats for a show
Each movie has:
A name
A duration

Each show has:
A movie
A show time
A fixed number of seats

Each seat has:
A seat number
A booking status (available / booked)
*/
#include "R:\C++\Project1\lcHeader.h"

class Movie{
    public:
    string name;
    double duration;

    Movie(string n, double d) : name(n), duration(d) {};

    void displayMovie(){
        cout<< "Movie: "<< name << "Duration: " << duration << endl;
    }
};

class Shows : public Movie{
    public:
};