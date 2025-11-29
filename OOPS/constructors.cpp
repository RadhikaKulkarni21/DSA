#include "R:\C++\Project1\lcHeader.h"

//simple constructor
class A {
public:
    A() { cout << "Default constructor called" << endl; }
};

//Parameterized constructor
class Student {
public:
    string name;
    int age;

    Student(string n, int a) {   // Parameterized constructor
        name = n;
        age = a;
    }
};

//copy constructor
class Student {
public:
    string name;
    int age;

    Student(string n, int a) {
        name = n;
        age = a;
    }

    // Copy constructor
    Student(const Student &s) {
        name = s.name;
        age = s.age;
    }
};

int main() {
    //parameterized constructor
    Student s1("Alice", 20);
    cout << s1.name << " " << s1.age << endl;

    //Copy constructor
    Student s1("Bob", 22);
    Student s2 = s1;  // Copy constructor called
    cout << s2.name << " " << s2.age << endl;
}
