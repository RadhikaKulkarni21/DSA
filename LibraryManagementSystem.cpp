#include "R:\C++\Project1\lcHeader.h"
/*
Library Management System
 o Classes: Book, Member, Librarian, Transaction.
 o Add-ons: issue/return logic, due date fine
*/

class Book{
public:
    string title;
    string author;
    int id;
    string category;


    Book(string t, string a, int i, string cat) : title(t), author(a), id(i), category(cat) {};

    void displayBook(){
        cout<< "Book: " << title << " by " << author << endl;
    }

};

class Member{
public:
    int memberId;
    string mName;

    Member(int mid, string n) : memberId(mid), mName(n) {};

    void displayMember(){
        cout << "Member Id: " << memberId << "Member Name: " << endl;
    }
};

class Librarian{
public:
    int LibId;
    string lName;

    Librarian(int lid, string ln) : LibId(lid), lName(ln) {};
};

class LateFine{
public: 
    int returnDate;
    int actualReturnDate;//for late fees
    double lateFees;

    LateFine(int rd, int ard) : returnDate(rd), actualReturnDate(ard) {};

    int totalLateDates = actualReturnDate - returnDate;

    double calculateFine(int lateDays){
        return lateDays * lateFees;
    }
};

class Transactions{
public:
    int issueDate;
    
};

int main(){

}