#include "inclfile.h"
#include "String.h"
#include <cstring>


void MyString::Copy (char* s)
{
	delete [] m_pStr;
	// Динамически выделяем требуемое количество памяти.
	int len = strlen(s) + 1;
	m_pStr = new char[len];
	// + 1, так как нулевой байт тоже нужно скопировать
	// Если память выделена, копируем строку-аргумент в строку-член класса
	if (m_pStr)
		strcpy_s (m_pStr, len, s);
}

MyString::MyString() : m_pStr(nullptr) {}
MyString::MyString(const char* s) {
    if (s) {
        m_pStr = new char[strlen(s) + 1]; 
        strcpy_s(m_pStr, strlen(s) + 1, s); 
    }
    else {
        m_pStr = nullptr;
    }
}

MyString::MyString(const MyString& other) {
    if (other.m_pStr) {
        m_pStr = new char[strlen(other.m_pStr) + 1]; 
        strcpy_s(m_pStr, strlen(other.m_pStr) + 1, other.m_pStr); 
    }
    else {
       m_pStr = nullptr;
    }
}

// Определение деструктора.
MyString::~MyString()
{
	// Освобождение памяти, занятой в конструкторе для строки-члена класса
	delete[] m_pStr;
}

// Метод класса
char* MyString::GetString()
{
	return m_pStr;
}

int MyString::GetLength()
{
	return strlen(m_pStr) + 1;
}
