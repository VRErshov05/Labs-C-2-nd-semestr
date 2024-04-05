#include <iostream>
#include <string>
//#include<map>
using namespace std;


enum Gender {
	Male,
	Female
};

struct Data {
	string name = ""; //key
	int age;  //data
	Gender gender; //data
	string post; //data
	double salary; //data
	Data(int age, Gender gender, string post, double salary): age(age), gender(gender), post(post), salary(salary){}
	Data() = default;
	Data& operator =(const Data& other) {
		if (!other.name.empty())
			name = other.name;
		age = other.age;
		gender = other.gender;
		post = other.post;
		salary = other.salary;
		return *this;
	}

	
};

struct BD {
	Data* elements;
	int capacity = 5;
	int size = 0;
	BD() :elements(new Data[5]) {}

	int hash(const string& key) { // уникальный номер для каждого слова-ключа
		int sum = 0;
		for (size_t i = 0; i != key.length(); ++i) {
			sum += key[i];
		}
		sum %= capacity;
		return sum;
	}

	void realloc() {
		if (size + 1 == capacity) {
			Data* NewEl = new Data[capacity * 2];
			for (int i = 0; i < capacity; i++) {
				NewEl[i] = elements[i];
			}
			delete[]elements;
			elements = std::move(NewEl);
			capacity *= 2;
		}
	}

	BD& operator=(const BD& other) {
		if (this == &other) {
			return *this;
		}
		size = other.size;
		capacity = other.capacity;
		elements = nullptr;
		elements = new Data[capacity];
		for (int i = 0; i < capacity; i++) {
			elements[i] = other.elements[i];
		}
		return *this;
	}

	Data& operator[](const string& LastName) {
		realloc();
		int hashed = hash(LastName);
		if (!elements[hashed].name.empty()) { // коллизия
			int tmp = hashed;
			for (; !elements[tmp].name.empty(); tmp++) {
				if (tmp == capacity - 1)
					tmp = 0;
				if (elements[tmp].name == LastName)
					return elements[tmp];
			}
			elements[tmp].name = LastName;
			size++;
			return elements[tmp];
		}
		else {
			elements[hashed].name = LastName;
			size++;
			return elements[hashed];
		}

	}

	void del(const string& LastName) {
		int hashed = hash(LastName);
		if (elements[hashed].name == LastName) {
			elements[hashed].name.clear();
			size--;
		}
		else {
			for (size_t i = hashed + 1;; ++i) {
				if (i == capacity - 1)
					i = 0;
				if (i == hashed) {
					cout << "There is no such person\n";
					break;
				}
				if (elements[i].name == LastName) {
					elements[i].name.clear();
					break;
				}
			}
		}
	}
};