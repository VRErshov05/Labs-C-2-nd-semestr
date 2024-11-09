#include "inclfile.h"
#include <cstring>
#include "Vector.h"


Vector::Vector (double c1, double c2)
{
	x=c1;  
	y=c2;
	Count++;
}

Vector::Vector ()
{
	x = y = 0.;
	Count++;
}

void Vector::Out()
{
	cout << "\nVector:  x = " << x << ",  y = " << y;
}

Vector::~Vector() {
	Count--;
}
//====== Переопределение операций =====//
Vector& Vector::operator= (const Vector& v)	// Присвоение
{
	if (this == &v)
		return *this;
	x = v.x;
	y = v.y;
	return *this;
}

