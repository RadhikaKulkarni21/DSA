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
        << " Currently the book is " << (isIssued ? "available" : "issued") <<endl;
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
        << "Member Name: " << member->mName << endl
        << "Issued On: " << issueDate << " for " << returnDate << " Days" <<endl;

        if(lateFine != nullptr){
            //https://www.studyplan.dev/intro-to-programming/string-interpolation
            cout << "Returned passed due date. Late fees of has been incurred: " << lateFine->calculateFine() << endl; 
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
        members.push_back(m);
    }

    void addLibrarian(Librarian* l){
        librarians.push_back(l);
    }

    Book* findBook(int bookId){
        for(auto b : books){
            if(b->id == bookId){
                return b;
            }
        }
        return nullptr;
    }

    Member* findMember(int mid){
        for(auto m : members){
            if(m->memberId == mid){
                return m;
            }
        }
        return nullptr;
    }

    Librarian* findLibrarian(int libId){
        for(auto l : librarians){
            if(l->LibId == libId){
                return l;
            }
        }
        return nullptr;
    }

    void issueBook(int bookId, int memId, int libId, int issueDate, int dueDate){
        Book* book = findBook(bookId);
        Member* member = findMember(memId);
        Librarian* librarian = findLibrarian(libId);

        if(book && member && !book->isIssued){
            book->isIssued = true;
            BorrowingHistory* h = new BorrowingHistory(book, member, librarian, issueDate, dueDate);
            history.push_back(h);

            cout<< book->title <<" has been issued to you" << endl
            << "To be returned: " << dueDate << endl;
        }
        else{
            cout << "Cannot issue the book currently" << endl; 
        }
    }

    void returnBook(int bookId, int actualReturnDate){
        for(auto h : history){
            if(h->book->id == bookId && h->book->isIssued){
                h->returnBook(actualReturnDate);
                h->displayBorrowingHistory();
                return;
            }
        }
        cout << "No history found" << endl;
    }

    //meed to delete as new references might affect the code
    ~Library(){
        for(auto b : books) delete b;
        for(auto m : members) delete m;
        for(auto l : librarians) delete l;
        for(auto h : history) delete h;
    }
};

int main(){
    Library library;

    //add books
    Book* book1 = new Book("My DonXiote", "Kim Ho Yoon", 1, "SLice of Youth");
    Book* book2 = new Book("The Healing Season of Pottery", "Somin Yeon", 2, "Healing");

    //add members
    Member* member1 = new Member(1, "Han Wangho");
    Member* member2 = new Member(2, "Ju Mingyu");

    //add librarians
    Librarian* librarian1 = new Librarian(1, "Sawako");
    Librarian* librarian2 = new Librarian(2, "Miran");

    //Add books to library
    library.addBook(book1);
    library.addBook(book2);

    //Add members
    library.addMember(member1);
    library.addMember(member2);
    
    //Add librarian
    library.addLibrarian(librarian1);
    library.addLibrarian(librarian2);

    //issue books
    library.issueBook(1, 1, 1, 1, 14);
    library.issueBook(2, 2, 2, 2, 14);

    //return books
    library.returnBook(1, 10);
    library.returnBook(2, 15);
}

/*
Future scope:
CIN >>

Maybe adding alphanumeric ID for ids


Change dates to date format
*/