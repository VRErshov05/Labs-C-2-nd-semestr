#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
#include "stdafx.h"
using namespace std;



class Vector {

private:
    double x, y;  // Координаты вектора на плоскости

public:
    //========== Три конструктора
    Vector(double c1, double c2)
    {
        x = c1;
        y = c2;

    }

    Vector()
    {
        x = 0;
        y = 0;

    }

    // Default
    ~Vector() {}
    //====== Переопределение операций =====//
    Vector& operator= (const Vector& v)  // Присвоение
    {
        if (this == &v)
            return *this;
        x = v.x;
        y = v.y;
        return *this;
    }
    void Out() {
        cout << "\nVector:  x = " << x << ",  y = " << y;
    }
    float getX() const { return x; } // Геттер для x
    float getY() const { return y; } // Геттер для y

    friend std::ostream& operator<<(std::ostream& os, const Vector& v);

    bool operator<(const Vector& other) const {

        return x < other.x || (x == other.x && y < other.y);
    }

    bool operator==(const Vector& other) const {
        return x == other.x && y == other.y;
    }
    bool isGreaterThan2() const {
        return x > 2 && y > 2;
    }

};
template <typename T>
ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    os << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i != vec.size() - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}
bool predicate(const Vector& vec) {
    return vec.getX() > 2 && vec.getY() > 2; // Проверяем, что обе координаты больше 2
}
#endif // MYVECTOR_H