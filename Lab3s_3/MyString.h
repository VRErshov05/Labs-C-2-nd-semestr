﻿#include <cstring>
class MyString
{
private:
	char* m_pStr;		// Элемент данных класса (адрес строки)
public:
    MyString ();
	MyString (const char* s);	// Объявление конструктора
    MyString(const MyString& other);
    ~MyString();		// Объявление деструктора
    // Оператор присваивания
    MyString& operator=(const MyString& other) {
        if (this != &other) { // Проверка на самоприсваивание
            delete[] m_pStr; // Освобождаем старую память

            if (other.m_pStr) {
                m_pStr = new char[strlen(other.m_pStr) + 1]; // Выделяем память для новой строки
                strcpy_s(m_pStr, strlen(other.m_pStr)+1, other.m_pStr); // Копируем строку
            }
            else {
                m_pStr = nullptr;
            }
        }
        return *this; // Возвращаем ссылку на текущий объект
    }
    friend ostream& operator<<(ostream& os, const MyString& s) {
        os << s.m_pStr;
        return os;
    }
	void Copy (char* s);
	char* GetString();	// Объявление метода (accessor)
	int GetLength();	// Объявление метода (длина строки)
};
