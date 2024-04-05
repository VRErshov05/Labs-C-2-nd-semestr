#include <iostream>
#include <string.h>
#include <vector>
#include <cstring>
#pragma warning(disable : 4996)
using namespace std;

class MyString 
{
public:
	MyString(const char* str): str(str)
	{
		//cout << "Конструктор " << this << endl;
	}
	MyString() 
	{
		//cout << "Базовый Конструктор " << this << endl; 
	};

	MyString(const MyString& other) 
	{
		//cout << "Конструктор копирования " << this << endl;
		this->str = other.str;
	}
	MyString& operator=(const MyString& other)
	{
		//cout << "Оператор присваивания " << this << endl;
		this->str = other.str;
		return *this;
	}
	
	string getStr() 
	{
		return str;
	}
	void setStr(const char* str) 
	{
		this->str = str;
	}
	void print()
	{
		cout << str << endl;
	}


	friend ostream& operator<<(ostream& os, const MyString& myStr) {
		os << "contents: \"" << myStr.str << "\"";
		return os;
	}

	MyString operator+(const MyString& other) {
		
		char* result = new char[strlen(str) + strlen(other.str) + 1];

		strcpy(result, str);
		strcat(result, other.str);
		return MyString(result);
	}
	
	MyString& operator+=(const MyString& other) {
	
		char* result = new char[strlen(str) + strlen(other.str) + 1];

		strcpy(result, str);
		strcat(result, other.str);

		str = result;
		return *this;
	}
	
	~MyString() 
	{
		//cout << "Деструктор " << this << endl; 
	}
private:
	const char* str;

};
