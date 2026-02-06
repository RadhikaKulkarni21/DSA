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

string boolTostr(Attendance attendance){
    switch(attendance){
        case(OPTIONAL): return "Optional";
        case MANDOTARY : return "Mandotary";
    }
}

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
    int minCredits;
    int maxCredits;
    Attendance required;
    int maxStudents;
    AcademicLevel level;
    int totalEnrolled = 0;

    Course(string cn, int ci, int mc,int minc, int ms, Attendance r,AcademicLevel al) : courseName(cn), courseId(ci), 
    minCredits(minc), maxCredits(mc),maxStudents(ms), required(r), level(al) {};

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
        for(auto g : grades){
            if(g->student->studentId == stdId &&
               g->course->courseId == crsId){

                if(g->marks >= 60)
                    return "Pass";
                else if(g->marks >= 40)
                    return "Grace";
                else
                    return "Fail";
            }
        }
        return "Grades not available";
    }

    void assignCourse(int stdId, int crsId){
        Student* student = findStudent(stdId);
        Course* course = findCourse(crsId);

        if(!student || !course){
            cout << "Please check details again" << endl;
            return;
        }

        if(student->level != course->level){
            cout << "This course is not available for your academic level" << endl;
            return;
        }
        
        if( course->totalEnrolled >= course->maxStudents){
            cout << "Course is already full, please join waitlist";
            return;
        }

        Enrollment* e = new Enrollment(student, course);
        enrollments.push_back(e);
        course->totalEnrolled++;

        cout << "Assigned course to you is " << course->courseName << " " << course->courseId << endl
        << "Attendance Requirement: " << course->required << endl;
        cout << "Minimum credits required to pass: " << course->minCredits;
        cout << " Maximum credits: " << course->maxCredits << endl;

    }
};

int main() {
    StudentRecord record;

    // Create students
    Student* s1 = new Student("Paul", 1, Freshman);
    Student* s2 = new Student("Dana", 2, Junior);

    record.addStudent(s1);
    record.addStudent(s2);

    // Create courses
    Course* c1 = new Course("Esports theory", 101, 4, 2, 2, boolTostr(MANDOTARY), Freshman);
    Course* c2 = new Course("Korean Literature", 201, 5, 2, 1, boolTostr(OPTIONAL), Junior);

    record.addCourses(c1);
    record.addCourses(c2);

    // Assign courses
    record.assignCourse(1, 101);
    record.assignCourse(2, 201);

    // Add grades
    Grade* g1 = new Grade(s1, c1, 75);
    Grade* g2 = new Grade(s2, c2, 55);

    record.addGrades(g1);
    record.addGrades(g2);

    // Check results
    cout << "Paul Result: " << record.setResult(1, 101) << endl;
    cout << "Dana Result: " << record.setResult(2, 201) << endl;

    return 0;
}

/*
future scope
Add labs
*/
