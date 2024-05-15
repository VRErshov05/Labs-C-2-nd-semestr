#include <iostream>
#include <string.h>
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

class Point {
public:
	Point(int x = 0, int y = 0) : x(x), y(y) {
		//cout << "Вызвался конструктор Point: "<< this << endl;
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
		//cout << "Вызвался деструктор Point: " << this << endl;
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

//Этот класс отвечает за создание и управление узлами в двусвязном списке.
class Node {
	Circle data;
	Node* pNext;
	Node* pPrev;

	//Устанавливает указатели pNext и pPrev в nullptr, что обозначает, что узел не связан ни с каким другим узлом.
	Node() :pNext(nullptr), pPrev(nullptr) {}

	/*
	Принимает указатель на предыдущий узел prev и данные ndata, которые будут храниться в узле.
	Инициализирует поле data данными ndata.
	Устанавливает указатель pNext текущего узла на следующий узел после prev.
	Устанавливает указатель pPrev текущего узла на prev.
	Обновляет указатель pNext предыдущего узла prev, чтобы он указывал на текущий узел.
	Обновляет указатель pPrev следующего узла после prev, чтобы он указывал на текущий узел.
	*/
	Node(Node* prev, const Circle& ndata) :data(ndata) {
		pNext = prev->pNext;
		prev->pNext = this;
		pPrev = prev;
		pNext->pPrev = this;
	}
	~Node() {
		//Проверяет, существует ли предыдущий узел pPrev.
		if (pPrev != nullptr)
			//Если существует, обновляет указатель pNext предыдущего узла, чтобы он указывал на следующий узел после текущего узла pNext.
			pPrev->pNext = pNext;
		//Проверяет, существует ли следующий узел pNext.
		if (pNext != nullptr)
			//Если существует, обновляет указатель pPrev следующего узла, чтобы он указывал на предыдущий узел перед текущим узлом pPrev.
			pNext->pPrev = pPrev;
		//Устанавливает pNext и pPrev в nullptr, чтобы избежать нежелательных ссылок после удаления узла.
		pNext = nullptr;
		pPrev = nullptr;
	}
	friend class List;
	friend ostream& operator <<(ostream&, const List&);
	friend istream& operator >>(istream& in, List& l);
};

class List {
	Node Head; // Указатель на начало списка.
	Node Tail; //Указатель на конец списка.
	int size; //Переменная для отслеживания размера списка.
public:
	//Конструктор по умолчанию инициализирует Head так, чтобы он указывал на Tail, и Tail так, чтобы он указывал на Head. 
	// Размер списка устанавливается в 0.
	List() { 
		Head.pNext = &Tail;
		Tail.pPrev = &Head;
		size = 0;
	}

	//Добавляет новый узел с данными data в начало списка.
	void AddToHead(const Circle& data) {
		new Node(&Head, data);
		size++;
	}

	//Добавляет новый узел с данными data в конец списка.
	void AddToTail(const Circle& data) {
		new Node(Tail.pPrev, data);
		size++;
	}

	//Удаляет первый узел, содержащий данные data, из списка.
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

	//Удаляет все узлы, содержащие данные data, из списка и возвращает количество удаленных узлов.
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

	// Очищает список, освобождая память, занятую узлами.
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

	//Сортирует список в порядке убывания значений площадей фигур, используя метод сортировки "пузырьком".
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
