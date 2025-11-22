#include <iostream>

class Shape {
public:
    // Virtual function
    virtual void draw() {
        std::cout << "Drawing a generic shape." << std::endl;
    }
};

class Circle : public Shape {
public:
    // Overriding the base class method
    void draw() override {
        std::cout << "Drawing a circle." << std::endl;
    }
};

class Rectangle : public Shape {
public:
    // Overriding the base class method
    void draw() override {
        std::cout << "Drawing a rectangle." << std::endl;
    }
};

int main() {
    Shape* myShape;

    // myShape can point to a Circle or a Rectangle object
    Circle circleObj;
    myShape = &circleObj;
    myShape->draw(); // Output: "Drawing a circle." (runtime call)

    Rectangle rectObj;
    myShape = &rectObj;
    myShape->draw(); // Output: "Drawing a rectangle." (runtime call)

    return 0;
}