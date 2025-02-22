#include <iostream>
#include <string.h>
using namespace std;

class Point {
public:
	Point(double x = 0, double y = 0) : x(x), y(y) {}


	double Getx() const{ 
		return x;
	}
	void Setx(int x) { 
		this->x = x;
	}
	double Gety() const{
		return y;
	}
	void Sety(int y) {
		this->y = y;
	}
	void print() {
		cout << "x = " << x << "\ty = " << y << endl;
	}

	// ���������� ��������� << ��� ������ ������� Point
	friend ostream& operator<<(ostream& os, const Point& p) {
		os << "Point(x=" << p.Getx() << ", y=" << p.Gety() << ")";
		return os;
	}

	//���������� ���������� +, +=, ++i, i++
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


	
private:
	double x;
	double y;
};




