#ifndef MYSHAPE_H
#define MYSHAPE_H

#include "inclfile.h"
#include <iostream>
using namespace std;

class Vector; 
class Shape {
protected:
    static int Count; 
    
public:
    static std::vector<Shape*> shapes; 
    Shape();
    virtual ~Shape();

    virtual void Move(Vector& v) = 0; 
    virtual void Out() = 0; 
    virtual double Area() = 0; 

    static void PrintCount();
    static int GetCount();
};

#endif // MYSHAPE_H