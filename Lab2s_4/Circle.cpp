#include <iostream>
#include <string.h>
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

class Point {
public:
	Point(int x = 0, int y = 0) : x(x), y(y) {
		//cout << "�������� ����������� Point: "<< this << endl;
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
		//cout << "�������� ���������� Point: " << this << endl;
	}



	bool operator ==(const Point& other)
	{
		return this->x == other.x and this->y == other.y;

	}
	friend ostream& operator <<(ostream&, const Point&);
	friend istream& operator >>(istream& in, Point& p);
	bool operator !=(const Point& other)
	{
		return x != other.x or y != other.y;

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

protected:
	double x;
	double y;
};

class Circle {
	Point centr;
	double radius;
public:
	Circle() :radius(0) {}
	Circle(Point p, int r) :centr(p), radius(r) {}
	bool operator==(const Circle& other) {
		return ((radius == other.radius) && (centr == other.centr));
	}
	const double GetS()const {
		return  M_PI * radius * radius;
	}
	friend ostream& operator <<(ostream&, const Circle&);
	friend istream& operator >>(istream& in, Circle& c);
};

//���� ����� �������� �� �������� � ���������� ������ � ���������� ������.
class Node {
	Circle data;
	Node* pNext;
	Node* pPrev;

	//������������� ��������� pNext � pPrev � nullptr, ��� ����������, ��� ���� �� ������ �� � ����� ������ �����.
	Node() :pNext(nullptr), pPrev(nullptr) {}

	/*
	��������� ��������� �� ���������� ���� prev � ������ ndata, ������� ����� ��������� � ����.
	�������������� ���� data ������� ndata.
	������������� ��������� pNext �������� ���� �� ��������� ���� ����� prev.
	������������� ��������� pPrev �������� ���� �� prev.
	��������� ��������� pNext ����������� ���� prev, ����� �� �������� �� ������� ����.
	��������� ��������� pPrev ���������� ���� ����� prev, ����� �� �������� �� ������� ����.
	*/
	Node(Node* prev, const Circle& ndata) :data(ndata) {
		pNext = prev->pNext;
		prev->pNext = this;
		pPrev = prev;
		pNext->pPrev = this;
	}
	~Node() {
		//���������, ���������� �� ���������� ���� pPrev.
		if (pPrev != nullptr)
			//���� ����������, ��������� ��������� pNext ����������� ����, ����� �� �������� �� ��������� ���� ����� �������� ���� pNext.
			pPrev->pNext = pNext;
		//���������, ���������� �� ��������� ���� pNext.
		if (pNext != nullptr)
			//���� ����������, ��������� ��������� pPrev ���������� ����, ����� �� �������� �� ���������� ���� ����� ������� ����� pPrev.
			pNext->pPrev = pPrev;
		//������������� pNext � pPrev � nullptr, ����� �������� ������������� ������ ����� �������� ����.
		pNext = nullptr;
		pPrev = nullptr;
	}
	friend class List;
	friend ostream& operator <<(ostream&, const List&);
	friend istream& operator >>(istream& in, List& l);
};

class List {
	Node Head; // ��������� �� ������ ������.
	Node Tail; //��������� �� ����� ������.
	int size; //���������� ��� ������������ ������� ������.
public:
	//����������� �� ��������� �������������� Head ���, ����� �� �������� �� Tail, � Tail ���, ����� �� �������� �� Head. 
	// ������ ������ ��������������� � 0.
	List() { 
		Head.pNext = &Tail;
		Tail.pPrev = &Head;
		size = 0;
	}

	//��������� ����� ���� � ������� data � ������ ������.
	void AddToHead(const Circle& data) {
		new Node(&Head, data);
		size++;
	}

	//��������� ����� ���� � ������� data � ����� ������.
	void AddToTail(const Circle& data) {
		new Node(Tail.pPrev, data);
		size++;
	}

	//������� ������ ����, ���������� ������ data, �� ������.
	bool RemoveFirst(const Circle& data) {
		Node* ptr = Head.pNext;
		for (int i = 0; i < size; i++) {
			if (ptr->data == data) {
				delete ptr;
				size--;
				return true;
			}
			ptr = ptr->pNext;
		}
		return false;
	}

	//������� ��� ����, ���������� ������ data, �� ������ � ���������� ���������� ��������� �����.
	int RemoveAllCount(const Circle& data) {
		int removes = 0;
		Node* ptr = Head.pNext;
		for (int i = 0; i < size; i++) {
			if (ptr->data == data) {
				Node* tmp = ptr->pNext;
				delete ptr;
				removes++;
				ptr = tmp;
			}
			else
				ptr = ptr->pNext;
		}
		size -= removes;
		return removes;
	}

	// ������� ������, ���������� ������, ������� ������.
	void Clear() {
		Node* ptr = Head.pNext;
		for (int i = 0; i < size; i++) {
			Node* tmp = ptr->pNext;
			delete ptr;
			ptr = tmp;
		}
		size = 0;
		/*if ((Head.pNext == &Tail) && (Tail.pPrev == &Head))
			std::cout << "Done!!!\n";*/
	}

	//��������� ������ � ������� �������� �������� �������� �����, ��������� ����� ���������� "���������".
	void sort() {
		if (size > 1) {
			Node* current = nullptr;
			Node* nextcurrent = nullptr;
			for (current = Head.pNext; current->pNext != &Tail; current = current->pNext) {
				for (nextcurrent = current->pNext; nextcurrent != &Tail; nextcurrent = nextcurrent->pNext) {
					if (current->data.GetS() < nextcurrent->data.GetS()) {
						Circle temp = current->data;
						current->data = nextcurrent->data;
						nextcurrent->data = temp;
					}
				}
			}
		}
	}
	friend ostream& operator <<(ostream&, const List&);
	friend istream& operator >>(istream& in, List& l);
};
