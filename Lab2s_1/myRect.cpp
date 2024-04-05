#include<string>
#include<iostream>
using namespace std;

class Rect {
public:
	Rect(int m_left = 0, int m_right = 0, int m_top = 0, int m_bottom = 0) : m_left(m_left), m_right(m_right), m_top(m_top), m_bottom(m_bottom) {
		cout << "Вызвался конструктор: " << this << endl;
	}
	Rect(const Rect& other) {
		cout << "Вызывается конструктор копирования: "<< this << endl;
		this->m_left = other.m_left;
		this->m_right = other.m_right;
		this->m_top = other.m_top;
		this->m_bottom = other.m_bottom;
	}
	

	void print() {
		cout << m_left << " " << m_right << " " << m_top << " " << m_bottom << endl;
	}
	int InflateRect(int left, int right, int top, int bott){
		m_left += left;
		m_right += right;
		m_top += top;
		m_bottom += bott;
		return m_left, m_right, m_top, m_bottom;
	}
	int InflateRect(int a=1, int b=1) {
		m_left += a;
		m_right += b;
		m_top += a;
		m_bottom += b;
		return m_left, m_right, m_top, m_bottom;
	}
	void SetALL(int m_left, int m_right, int m_top, int m_bottom) {
		this ->m_left = m_left;
		this->m_right = m_right;
		this-> m_top = m_top;
		this-> m_bottom = m_bottom;
	}
	int  GetAll(string str) {
		if (str == "m_left") return m_left;
		if (str == "m_right") return m_right;
		if (str == "m_top") return m_top;
		if (str == "m_bottom") return m_bottom;
		return 0;
	}

	//ещё один вариант реализации гет олл, для его работы перепишите места, в которых использовался прошлый метод
	void  getall(int& m_left, int& m_right, int& m_top, int& m_bottom) {
		m_left = this->m_left;
		m_right = this->m_right;
		m_top = this->m_top;
		m_bottom = this->m_bottom;
	}
	//
	


	~Rect() {
		cout << "Вызвался деструктоp: " << this << endl;
		
	}
private: 
	int m_left;
	int m_right;
	int m_top;
	int m_bottom;
};