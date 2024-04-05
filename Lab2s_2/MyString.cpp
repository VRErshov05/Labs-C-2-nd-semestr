#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

class MyString 
{
public:
	MyString(const string& str): str(str)
	{
		cout << "����������� " << this << endl;
	}
	MyString(const vector<string>& strs) {
		cout << "����������� ��� 9 ������� " << this << endl;
		for (const auto& str : strs) {    
			this->str += str;             
		}                                 
	}
	MyString() { cout << "������� ����������� " << this << endl; };
	

	MyString(const MyString& other) 
	{
		cout << "����������� ����������� " << this << endl;
		this->str = other.str;
	}
	MyString& operator=(const MyString& other)
	{
		cout << "�������� ������������ " << this << endl;
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
	
	~MyString() { cout << "���������� " << this << endl; }
private:
	string str;

};


/*
���������� ���� 9 ������� :

������������ ����� : ��� �������� ����������� ������������ ����� ��� ������ �� ��������(<string>), ���������(<vector>) � ������������� ���� ����������� ���������� C++ (<iostream>).

����� MyString : 
��� ���������� ����� MyString � ����� �������������� :
������ ����������� ��������� ������(const string & str) � �������������� ��������� ���� str ���� ���������.
������ ����������� ��������� ������ �����(const vector<string>&strs) � ���������� ��� ������ � ������� � ���� ������, ������� ����� ����������� � str.


������� concat : ������� concat ��������� ������ ���������� �� �������(const vector<const char*>& strs) � ���������� ������ MyString.
������� ������� ����� ������� � ���� ������� �����(strs_copy) � �������� ��� � ����������� MyString, ������� ���������� ��� ������ � ���� ������.

������� main :
� ������� main ����������� ��� ��������� �� �������(str1, str2, str3), ������� �������� ������ "Hello", "World" � "!", ��������������.
��������� ������ MyString s ����� ������ ������� concat � �������� ���������� �� �������.
����� str() ���������� ��� ������� s, � ��� ��������� ��������� � ����������� �����.��� ������� ������������ ������ "HelloWorld!" �� �������.

��� �������� ��� :
������� main ������� ������ ��������� �� �������, ������� ��������� �� ������ "Hello", ", ", "world" � "!".
������� concat ������� ������ ����� �� ���������� �� ������� � �������� ��� � ����������� MyString.
����������� MyString ���������� ��� ������ � ������� � ���� ������ � ��������� �� � ��������� ���� str.
����� print() �������� ������������ ������.
*/