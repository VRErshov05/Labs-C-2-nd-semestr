#pragma once
#include <iostream>
#include <string>
using namespace std;

class MyString
{
    const char* m_pStr;	//������-���� ������
public:
    MyString(const char* s);
    ~MyString();
    string GetString() {
        return m_pStr;
    }
    void StrNewString(const char* x_new) {
        m_pStr = x_new;
    }
};
