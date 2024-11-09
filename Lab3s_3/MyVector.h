#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>

using namespace std;

class Shape;


class Vector {

private:
	double x, y;	// Координаты вектора на плоскости

public:
	//========== Три конструктора
	Vector(double c1, double c2)
	{
		x = c1;
		y = c2;

	}

	Vector()
	{
		x = y = 0.;

	}

	// Default
	~Vector() {}
	//====== Переопределение операций =====//
	Vector& operator= (const Vector& v)	// Присвоение
	{
		if (this == &v)
			return *this;
		x = v.x;
		y = v.y;
		return *this;
	}
	void Out() {
		cout << "\nVector:  x = " << x << ",  y = " << y;
	}
	float getX() const { return x; } // Геттер для x
	float getY() const { return y; } // Геттер для y

	

	
	

};


#endif // MYVECTOR_H