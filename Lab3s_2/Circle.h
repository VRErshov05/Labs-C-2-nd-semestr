#ifndef MYCIRCLE_H
#define MYCIRCLE_H

#include "Shape.h"


class Circle : public Shape {
private:
    Vector ptCntr; 
    double R; 

public:
    Circle(double x, double y, double r)
        : ptCntr(x, y), R(r) {}

    void Move(Vector& v) override {
        ptCntr.Move(v);
    }

    void Out() override {
        cout << "Circle (Center: " << ptCntr.getX() << ", " << ptCntr.getY() << ", Radius: " << R << ")";
    }

    double Area() override {
        return 3.14159 * R * R; 
    }
};

#endif // MYCIRCLE_H