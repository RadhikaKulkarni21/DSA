#include "R:\C++\Project1\lcHeader.h"
/*
Student Record System
 o Classes: Student, Course, Grade.
 o Add-ons: GPA calculation, course enrolment.
*/

enum AcademicLevel{
    Freshman,
    Sophmore,
    Junior,
    Senior
};

enum Attendance{
    OPTIONAL,
    MANDOTARY
};

class Student{
public:
    string sName;
    int studentId;
    AcademicLevel level;

    Student(string sn, int sid, AcademicLevel al) : sName(sn), studentId(sid),
    level(al){};

    void displayStudent(){
        cout<< "Name: " << sName << endl
        << "ID: " << studentId << endl
        << "Academic Level: " << level << endl;
    }
};

class Course{
public:
    string courseName;
    int courseId;
    int maxCredits;
    Attendance required;
    int maxStudents;
    AcademicLevel level;
    int totalEnrolled = 0;

    Course(string cn, int ci, int mc,int ms, Attendance r,AcademicLevel al) : courseName(cn), courseId(ci), 
    maxCredits(mc),maxStudents(ms), required(r), level(al) {};

    void displayCourse(){
        cout << "Course ID: " << courseId << endl
        << "Course Name: " << courseName << endl;
    }

};

class Enrollment{
public:
    Student* student;
    Course* course;

    Enrollment(Student* s, Course* c) : student(s), course(c) {};

};

class Grade{//score not the class
public:
    Student* student;
    Course* course;
    int marks;

    Grade(Student* s, Course* c, int m) : student(s), course(c), marks(m) {};

    int getGrade(){
        return marks;
    }
};

class StudentRecord{
public: 
    vector<Student*> students;
    vector<Course*> courses;
    vector<Grade*> grades;
    vector<Enrollment*> enrollments;

    void addStudent(Student* s){
        students.push_back(s);
    }

    void addCourses(Course* c){
        courses.push_back(c);
    }

    void addGrades(Grade* g){
        grades.push_back(g);
    }

    Student* findStudent(int stdId){
        for(auto s : students){
            if(stdId == s->studentId){
                return s;
            }
        }
        return nullptr;
    }

    Course* findCourse(int cid){
        for(auto c : courses){
            if(cid == c->courseId){
                return c;
            }
        }
        return nullptr;
    }

    string setResult(int stdId, int crsId){
        Student* student = findStudent(stdId);
        Course* course = findCourse(crsId);
        for(auto g : grades){
            if(g->marks >= 60 && g->marks <= course->maxCredits){
                return "Pass";
            }
            else if(g->marks < 60 && g->marks > 40){
                return "Grace";
            }         
            else{
                return "fail";
            }
        }
    }

    void assignCourse(int stdId, int crsId){
        Student* student = findStudent(stdId);
        Course* course = findCourse(crsId);
        int studentCounter = 0;

        if(student->level != course->level){
            cout << "This course is not available for your academic level" << endl;
            return;
        }

        if(course->isEnrolled == true){
            cout << "You are already enrolled for the class" << endl;
            return;
        }
        
        if(studentCounter >= course->maxStudents){
            cout << "Course is already full, please join waitlist";
            return;
        }

        course->isEnrolled = true;

        Enrollment* e = new Enrollment(student, course);
        enrollments.push_back(e);
        studentCounter++;

        cout << "Assigned course to you" << course->courseName << " " << course->courseId << endl
        << "Attendance Requirement: " << course->required << endl;
        cout << "Maximum credits" << course->maxCredits;

    }
};