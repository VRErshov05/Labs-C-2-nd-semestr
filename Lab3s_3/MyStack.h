#include "stdafx.h"



class StackOverflow : public exception {
public:
	const char* what() const noexcept override {
		return "Stack overflow";
	}
};

class StackUnderflow : public exception {
public:
	const char* what() const noexcept override {
		return "Stack underflow";
	}
};

class StackOutOfRange : public exception {
public:
	const char* what() const noexcept override {
		return "Index out of range";
	}
};


template<typename T, size_t MaxSize>
class MyStack {
private:
	T data[MaxSize];  // массив для хранения элементов
	size_t top;       // индекс верхнего элемента стека

public:
	MyStack() : top(0) {}

	void Push(const T& element) {
		if (top >= MaxSize) {
			throw StackOverflow();
		}
		data[top++] = element;
	}

	T Pop() {
		if (top == 0) {
			throw StackUnderflow();
		}
		return data[--top];
	}

	size_t GetSize() const {
		return top;
	}

	size_t Capacity() const {
		return MaxSize;
	}

	T& operator[](size_t index) {
		if (index >= top) {
			cout << "\nAttempt to access index " << index << " which is out of range." << endl; // отладочный вывод
			throw StackOutOfRange();
		}
		return data[index];
	}
};