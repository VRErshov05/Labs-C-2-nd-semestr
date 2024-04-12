#include <iostream>
#include <string.h>
using namespace std;

class Point {
public:
	Point(int x = 0, int y = 0) : x(x), y(y) {
		cout << "Вызвался конструктор Point: "<< this << endl;
	}


	double Getx() {
		return x;
	}
	void Setx(int x) {
		this->x = x;
	}
	double Gety() {
		return y;
	}
	void Sety(int y) {
		this->y = y;
	}
	void print() {
		cout << "x = " << x << "\ty = " << y << endl;
	}

	~Point() {
		cout << "Вызвался деструктор Point: " << this << endl;
	}



	bool operator ==(const Point& other)
	{
		return this->x == other.x and this->y == other.y;

	}

	bool operator !=(const Point& other)
	{
		return x != other.x or y != other.y;

	}
	//перегрузка операторов +, +=, ++i, i++
	Point operator +(const Point& other) {
		Point tmp;
		tmp.x = x + other.x;
		tmp.y = y + other.y;
		return tmp;
	}
	Point operator +(double i) {
		Point tmp;
		tmp.x = i + this->x;
		tmp.y = i + this->y;
		return tmp;
	}
	friend Point operator+(double i, const Point& other) {
		Point tmp;
		tmp.x = i + other.x;
		tmp.y = i + other.y;
		return tmp;
	}
	Point operator-() {
		return Point(-x, -y);
	}

	Point operator+() {
		return Point(x, y);
	}
	Point operator +=(const Point& other) {
		x = x + other.x;
		y = y + other.y;
		return *this;
	}
	Point operator +=(double i) {
		x = x + i;
		y = y + i;
		return *this;
	}
	Point& operator ++() {
		this->x++;
		this->y++;
		return *this;
	}

	Point& operator ++(int value) {
		Point tmp(*this);
		this->x++;
		this->y++;
		return tmp;
	}

protected:
	double x;
	double y;
};

class Circle {
public:
	Circle(Point centr, double radius = 0){
		this->centr = centr;
		this->radius = radius;
		cout << "Вызвался конструктор Circle: " << this << endl;
	}
	Circle() { 
		this->radius = 0;
		cout << "Вызвался базовый конструктор Circle: " << this << endl; 
	}

	void print() {
		centr.print();
		cout << "Радиус: " << radius << endl;
	}
	~Circle() {
		cout << "Вызвался деструктор Circle: " << this << endl;
	}
private:
	Point centr;
	double radius;
};
