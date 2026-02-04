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
    bool isIssued;

    Book(string t, string a, int i, string cat) : title(t), author(a), id(i), category(cat), isIssued(false) {};

    void displayBook(){
        cout<< "Book: " << title << " by " << author << " Category: " << category 
        << " Currently" << (isIssued ? "available" : "issued") <<endl;
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

    void displayLibrarian(){
        cout << "Librarian ID: " << LibId << " " << " Name: "<< lName << endl;
    }
};

class LateFine{
public: 
    int returnDate;
    int actualReturnDate;//for late fees
    double lateFees;

    LateFine(int rd, int ard, double lf) : returnDate(rd), actualReturnDate(ard), lateFees(lf) {};

    int totalLateDates = actualReturnDate - returnDate;

    int getLateDays(){
        return max(0, totalLateDates);
    }

    double calculateFine(){
        return getLateDays() * lateFees;
    }
};

class BorrowingHistory{
public:
    Book* book;
    Member* member;
    Librarian* librarian;
    LateFine* lateFine = nullptr;//delete this later 
    int issueDate;
    int returnDate;

    BorrowingHistory(Book* b, Member* m, Librarian* l, int id, int rd) :
    book(b), member(m), librarian(l), issueDate(id), returnDate(rd) {};

    void returnBook(int actualReturnDate){
        book->isIssued = false;//making it available

        if(actualReturnDate > returnDate){
            lateFine = new LateFine(returnDate, actualReturnDate, 5.0);
        }
    }

    void displayBorrowingHistory(){
        cout << "Book Issued: " << book->title << endl
        << "Member Name" << member->mName << endl
        << "On: " << issueDate << " till" << returnDate << endl;

        if(lateFine != nullptr){
            //https://www.studyplan.dev/intro-to-programming/string-interpolation
            cout << "Returned passed due date. Late fees of has been incurred: " << lateFine << endl; 
        }
        else{
            cout <<"No late fees." << endl;
        }
    }

    ~BorrowingHistory(){
        delete lateFine;
    }
};

class Library{

private:
    vector<Book*> books;
    vector<Member*> members;
    vector<Librarian*> librarians;
    vector<BorrowingHistory*> history;

public:
    void addBook(Book* b){
        books.push_back(b);
    }

    void addMember(Member* m){

    }

    void addLibrarian(Librarian* l){
        librarians.push_back(l);
    }

    void issueBook(){

    }

    void returnBook(){

    }
};

int main(){

}