#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
#include "Shape.h"
using namespace std;

class Shape;

class Vector : public Shape {

private:
	double x, y;	// Координаты вектора на плоскости

public:
	//========== Три конструктора
	Vector (double c1, double c2);
	Vector ();							// Default
    ~Vector();
	//====== Переопределение операций =====//
	Vector& operator= (const Vector& v);	// Присвоение
	void Out();
	Vector operator+ (const Vector& other) const {
		return Vector(this->x + other.x, this->y + other.y);

	}
	float getX() const { return x; } 
	float getY() const { return y; } 
	
	double operator!() const {
		return std::sqrt(x * x + y * y);
	}
	bool operator>(const Vector& other) const {
		return !(*this) > !other;
	}
	bool operator==(const Vector& other) const {
		return !(*this) == !other;
	}
	
	friend Vector operator*(double scalar, const Vector& v) {
		return Vector(v.x * scalar, v.y * scalar);
	}
	
	Vector operator*(double scalar) const {
		return Vector(this->x * scalar, this->y * scalar);
	}

    friend class Rect;

	static void PrintCount() {
		cout << "\nNow there are " << Count << " shapes" << endl;
	}
	void Move(Vector& v) override {
		x += v.x;
		y += v.y;
	}
	
	double Area() override {
		return 0; 
	}
	

};


#endif // MYVECTOR_H