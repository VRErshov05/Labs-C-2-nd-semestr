#include <cstring>
class MyString
{
private:
	char* m_pStr;		// Элемент данных класса (адрес строки)
public:
    MyString ();
	MyString (const char* s);	// Объявление конструктора
    MyString(const MyString& other);
    ~MyString();		// Объявление деструктора
    
    MyString& operator=(const MyString& other) {
        if (this != &other) { 
            delete[] m_pStr; 

            if (other.m_pStr) {
                m_pStr = new char[strlen(other.m_pStr) + 1]; 
                strcpy_s(m_pStr, strlen(other.m_pStr)+1, other.m_pStr); 
            }
            else {
                m_pStr = nullptr;
            }
        }
        return *this; 
    }

	void Copy (char* s);
	char* GetString();	// Объявление метода (accessor)
	int GetLength();	// Объявление метода (длина строки)
};
