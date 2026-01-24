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
        cout<< "Movie: "<< name << "Duration: " << duration << " hrs"<< endl;
    }
};

class Seat{
    public:
    int seatNo;
    bool checkBook;

    Seat(int sn) : seatNo(sn), checkBook(false) {};

    //book the seat
    void bookSeat(){
        checkBook = true;
    }

    void displaySeats(){
        cout << "Seat: " << seatNo << (checkBook ? " Available" : " Booked") << endl;
    }
};

class Shows {
    public:
    Movie movie;
    string showTimes;
    vector<Seat> seats;

    Shows(Movie m, string s, int totalSeats) : movie(m), showTimes(s) {
        for(int i = 1; i <= totalSeats; i++){
            seats.push_back(Seat(i));
        }
    }

    void displayShows() {
        movie.displayMovie();

        cout << "Show Times: " << showTimes << endl;
        cout << "Seats:" << seats.size() << endl;

        for(auto seat : seats){
            seat.displaySeats();
        }
    }
};

int main(){
    Movie movieDetail("Tune in for love", 2.5);

    Shows showTimes(movieDetail, "7:00 PM", 20);

    showTimes.displayShows();
}