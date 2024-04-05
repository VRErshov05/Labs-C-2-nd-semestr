#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

class MyString 
{
public:
	MyString(const string& str): str(str)
	{
		cout << "Конструктор " << this << endl;
	}
	MyString(const vector<string>& strs) {
		cout << "Конструктор для 9 задания " << this << endl;
		for (const auto& str : strs) {    
			this->str += str;             
		}                                 
	}
	MyString() { cout << "Базовый Конструктор " << this << endl; };
	

	MyString(const MyString& other) 
	{
		cout << "Конструктор копирования " << this << endl;
		this->str = other.str;
	}
	MyString& operator=(const MyString& other)
	{
		cout << "Оператор присваивания " << this << endl;
		this->str = other.str;
		return *this;
	}
	
	string getStr() 
	{
		return str;
	}
	void setStr(string str) 
	{
		this->str = str;
	}
	void print()
	{
		cout << str << endl;
	}
	
	~MyString() { cout << "Деструктор " << this << endl; }
private:
	string str;

};


/*
Объяснение кода 9 задания :

Заголовочные файлы : Код включает необходимые заголовочные файлы для работы со строками(<string>), векторами(<vector>) и пространством имен стандартной библиотеки C++ (<iostream>).

Класс MyString : 
Код определяет класс MyString с двумя конструкторами :
Первый конструктор принимает строку(const string & str) и инициализирует приватное поле str этим значением.
Второй конструктор принимает вектор строк(const vector<string>&strs) и объединяет все строки в векторе в одну строку, которая затем сохраняется в str.


Функция concat : Функция concat принимает вектор указателей на символы(const vector<const char*>& strs) и возвращает объект MyString.
Функция создает копию вектора в виде вектора строк(strs_copy) и передает его в конструктор MyString, который объединяет все строки в одну строку.

Функция main :
В функции main объявляются три указателя на символы(str1, str2, str3), которые содержат строки "Hello", "World" и "!", соответственно.
Создается объект MyString s путем вызова функции concat с вектором указателей на символы.
Метод str() вызывается для объекта s, и его результат выводится в стандартный вывод.Это выводит объединенную строку "HelloWorld!" на консоль.

Как работает код :
Функция main создает четыре указателя на символы, которые указывают на строки "Hello", ", ", "world" и "!".
Функция concat создает вектор строк из указателей на символы и передает его в конструктор MyString.
Конструктор MyString объединяет все строки в векторе в одну строку и сохраняет ее в приватном поле str.
Метод print() печатает получившуюся строку.
*/