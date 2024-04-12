#include <iostream>
#include <string.h>
#include "Circle.cpp"
using namespace std;

int main() 
{
	setlocale(LC_ALL, "rus");
	Circle c;
	c.print();
	Circle cc(Point(1, 3), 5);
	cc.print();
}