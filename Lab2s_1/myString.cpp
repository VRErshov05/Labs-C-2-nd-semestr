#include <string>
#include "myString.h"
using namespace std;

// Определение конструктора.
MyString::MyString(const char* s) : m_pStr(s) {}

// Определение деструктора.
MyString::~MyString() {}
