#include "Shape.h"

int Shape::Count = 0;
std::vector<Shape*> Shape::shapes;

Shape::Shape() {
    Count++;
    shapes.push_back(this);
}

Shape::~Shape() {
    Count--;
    shapes.erase(std::remove(shapes.begin(), shapes.end(), this), shapes.end());
}

void Shape::PrintCount() {
    std::cout << "Now there are " << Count << " shapes" << std::endl;
}

int Shape::GetCount() {
    return Count;
}