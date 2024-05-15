#include <iostream>
#include <string.h>
#include "Circle.cpp"
#include<fstream>
using namespace std;

ostream& operator <<(ostream& out, const Point& p) {
	out << "(" << p.x << ";" << p.y << ")";
	return out;
}
istream& operator >>(istream& in, Point& p) {
	in.ignore(1);
	in >> p.x;
	in.ignore(1);
	in >> p.y;
	in.ignore(1);
	return in;
}
ostream& operator <<(ostream& out, const Circle& c) {
	out << "Площадь: " << c.GetS() << "\tрадиус: " << c.radius << "\tкоординаты: " << c.centr << "\n";
	return out;
}
istream& operator >>(istream& in, Circle& c) {
	in.ignore(strlen("Площадь: "));
	double s;
	in >> s;
	in.ignore(strlen("\tрадиус: "));
	in >> c.radius;
	in.ignore(strlen("\tкоординаты: "));
	in >> c.centr;
	return in;
}
ostream& operator <<(ostream& out, const List& l) {
	Node* ptr = l.Head.pNext;
	for (int i = 0; i < l.size; i++) {
		out << ptr->data;
		ptr = ptr->pNext;
	}
	return out;
}
istream& operator >>(istream& in, List& l) {
	Circle addData;
	while (in >> addData) {
		l.AddToTail(addData);
	}
	return in;
}


int main() 
{
	setlocale(LC_ALL, "rus");
	Point c1(8, 2);
	Point c2(10, 1);
	Point c3;
	Point c4(100, 200);
	Circle circle1(c1, 3);
	Circle circle2(c2, 5);
	Circle circle3(c3, 0);
	Circle circle4(c4, 1);
	List l; //Создается объект класса List для хранения кругов.

	//Круги добавляются в список l с использованием методов AddToHead() и AddToTail().
	l.AddToHead(circle1);
	l.AddToTail(circle2);
	l.AddToTail(circle3);
	l.AddToTail(circle4);
	l.AddToTail(circle2);

	//Вызывается метод sort() списка l, который сортирует круги в порядке убывания их площадей.
	l.sort();
	
	//Создается файл "res.txt", в который записывается содержимое списка l.
	ofstream file;
	file.open("res.txt");
	if (!file)
		cout << "Не найден";
	else {
		file << l;
	}
	file.close();

	//Список l очищается.
	l.Clear();

	//Из файла "res.txt" считывается содержимое и загружается в список l.
	ifstream ifile("res.txt");
	if (!ifile)
		cout << "Не найден";
	else {
		ifile >> l;
	}
	ifile.close();

	//Содержимое списка l выводится на экран.
	cout << l;
	return 0;
}