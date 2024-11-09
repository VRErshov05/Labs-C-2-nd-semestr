#ifndef MYRECT_H
#define MYRECT_H

#include "Shape.h"
#include <iostream>
using namespace std;

class Rect : public Shape {
private:
    Vector ptLT; 
    Vector ptRB; 

public:
    Rect(float left, float top, float right, float bottom)
        : ptLT(left, top), ptRB(right, bottom) {}
    Rect(const Rect& other)
        : ptLT(other.ptLT), ptRB(other.ptRB) {}
    Rect(const Vector& lt, const Vector& rb)
        : ptLT(lt), ptRB(rb) {}

    Rect& operator=(const Rect& other) {
        if (this != &other) {
            ptLT = other.ptLT;
            ptRB = other.ptRB;
        }
        return *this;
    }

    void Inflate(float delta = 1) {
        ptLT.x -= delta;
        ptLT.y -= delta;
        ptRB.x += delta;
        ptRB.y += delta;
    }

    void Inflate(float deltaX, float deltaY) {
        ptLT.x -= deltaX;
        ptLT.y -= deltaY;
        ptRB.x += deltaX;
        ptRB.y += deltaY;
    }

    void Inflate(float leftDelta, float topDelta, float rightDelta, float bottomDelta) {
        ptLT.x -= leftDelta;
        ptLT.y -= topDelta;
        ptRB.x += rightDelta;
        ptRB.y += bottomDelta;
    }

    void Out() const {
        cout << "Rect (" << ptLT.x << "," << ptLT.y << "," << ptRB.x << "," << ptRB.y << ")" << endl;
    }
    
    void Move(Vector& v) override {
        ptLT.Move(v);
        ptRB.Move(v);
    }

    void Out() override {
        cout << "Rect (" << ptLT.x << ", " << ptLT.y << ", " << ptRB.x << ", " << ptRB.y << ")";
    }

    double Area() override {
        return (ptRB.x - ptLT.x) * (ptRB.y - ptLT.y);
    }
};

#endif // MYRECT_H