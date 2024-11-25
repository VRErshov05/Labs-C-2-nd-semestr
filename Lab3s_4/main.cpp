// Контейнеры STL: 
//deque, stack, queue, priority_queue
//set, multiset, map, multimap
//Итераторы. Стандартные алгоритмы. Предикаты.

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <deque>
#include <string>
#include <string.h>
#include <cctype> // Для std::tolower
#include <iterator> // Для вставки итераторов
#include <ostream>
#include <cstring>
using namespace std;

template <class T>
void pr(T& v, string s)
{
	cout << "\n\n\t" << s << "  # Sequence:\n";


	typename T::iterator p;
	int i;

	for (p = v.begin(), i = 0; p != v.end(); ++p, ++i)
		cout << endl << i + 1 << ". " << *p;
	cout << '\n';
}
////////////////////////////////////////////////////////////////////////////////
class Point {
public:
	Point(double x = 0, double y = 0) : x(x), y(y) {}


	double Getx() const {
		return x;
	}
	void Setx(int x) {
		this->x = x;
	}
	double Gety() const{
		return y;
	}
	void Sety(int y) {
		this->y = y;
	}
	void print() {
		cout << "x = " << x << "\ty = " << y << endl;
	}

	// Перегрузка оператора << для вывода объекта Point
	friend ostream& operator<<(ostream& os, const Point& p) {
		os << "Point(x=" << p.Getx() << ", y=" << p.Gety() << ")";
		return os;
	}
	// Перегрузка оператора < и !=
	bool operator<(const Point& other) const {
		return (x < other.x) || (x == other.x && y < other.y);
	}
	bool operator!=(const Point& other) const {
		return x != other.x || y != other.y;
	}

	// Перегрузка оператора == для поиска
	bool operator==(const Point& other) const {
		return Getx() == other.Getx() && Gety() == other.Gety();
	}

	//перегрузка операторов +, +=, ++i, i++
	Point operator +(const Point& other) {
		Point tmp;
		tmp.x = x + other.x;
		tmp.y = y + other.y;
		return tmp;
	}
	Point operator +(double i) {
		Point tmp;
		tmp.x = i + this->x;
		tmp.y = i + this->y;
		return tmp;
	}
	friend Point operator+(double i, const Point& other) {
		Point tmp;
		tmp.x = i + other.x;
		tmp.y = i + other.y;
		return tmp;
	}


	Point operator-() {
		return Point(-x, -y);
	}

	Point operator+() {
		return Point(x, y);
	}


	Point operator +=(const Point& other) {
		x = x + other.x;
		y = y + other.y;
		return *this;
	}
	Point operator +=(double i) {
		x = x + i;
		y = y + i;
		return *this;
	}





	Point& operator ++() {
		this->x++;
		this->y++;
		return *this;
	}

	Point& operator ++(int value) {
		Point tmp(*this);
		this->x++;
		this->y++;
		return tmp;
	}



private:
	double x;
	double y;
};
class MyString
{
private:
	char* m_pStr; // Указатель на строку
public:
	MyString() : m_pStr(nullptr) {}

	MyString(const char* s) {
		if (s) {
			m_pStr = new char[strlen(s) + 1];
			strcpy_s(m_pStr, strlen(s) + 1, s);
		}
		else {
			m_pStr = nullptr;
		}
	}

	MyString(const MyString& other) {
		if (other.m_pStr) {
			m_pStr = new char[strlen(other.m_pStr) + 1];
			strcpy_s(m_pStr, strlen(other.m_pStr) + 1, other.m_pStr);
		}
		else {
			m_pStr = nullptr;
		}
	}

	~MyString() {
		delete[] m_pStr;
	}

	MyString& operator=(const MyString& other) {
		if (this != &other) {
			delete[] m_pStr;
			if (other.m_pStr) {
				m_pStr = new char[strlen(other.m_pStr) + 1];
				strcpy_s(m_pStr, strlen(other.m_pStr) + 1, other.m_pStr);
			}
			else {
				m_pStr = nullptr;
			}
		}
		return *this;
	}

	friend ostream& operator<<(ostream& os, const MyString& s) {
		if (s.m_pStr) {
			os << s.m_pStr;
		}
		else {
			os << "nullptr";
		}
		return os;
	}

	bool startsWithA() const {
		return m_pStr && (m_pStr[0] == 'A' || m_pStr[0] == 'a');
	}

	char* GetString() const {
		return m_pStr;
	}

};
class Rect {
private:
	Point topLeft, bottomRight;

public:
	Rect(Point tl = { 0, 0 }, Point br = { 0, 0 }) : topLeft(tl), bottomRight(br) {}

	// Геттеры для работы с вершинами
	const Point& GetTopLeft() const { return topLeft; }
	const Point& GetBottomRight() const { return bottomRight; }

	// Расстояние от центра прямоугольника до начала координат
	double DistanceFromOrigin() const {
		double centerX = (topLeft.Getx() + bottomRight.Getx()) / 2;
		double centerY = (topLeft.Gety() + bottomRight.Gety()) / 2;
		return sqrt(centerX * centerX + centerY * centerY);
	}

	friend ostream& operator<<(ostream& os, const Rect& r) {
		os << "TopLeft: " << r.GetTopLeft() << ", BottomRight: " << r.GetBottomRight();
		return os;
	}
};
////////////////////////////////////////////////////////////////////////////////

// Шаблон для вывода stack
template <typename T>
void printStack(stack<T> s, const string& name) {
	cout << "\n\n\t" << name << "  # Stack contents:\n";
	int i = 1;
	while (!s.empty()) {
		cout << i++ << ". " << s.top() << endl; // Выводим верхний элемент
		s.pop(); // Удаляем верхний элемент
	}
	cout << "\n";
}

// Шаблон для вывода queue
template <typename T>
void printQueue(queue<T> q, const string& name) {
	cout << "\n\n\t" << name << "  # Queue contents:\n";
	int i = 1;
	while (!q.empty()) {
		cout << i++ << ". " << *q.front() << endl; // Разыменовываем указатель
		q.pop(); // Удаляем первый элемент
	}
	cout << "\n";
}

// Шаблон для вывода priority_queue
template <typename T>
void printPriorityQueue(priority_queue<T> pq, const string& name) {
	cout << "\n\n\t" << name << "  # Priority Queue contents:\n";
	int i = 1;
	while (!pq.empty()) {
		cout << i++ << ". " << pq.top() << endl; // Выводим элемент с наибольшим приоритетом
		pq.pop(); // Удаляем элемент с наибольшим приоритетом
	}
	cout << "\n";
}

// Шаблон вывода множества
template <typename T>
void printSet(const set<T>& s, const string& name) {
	cout << "\n\n\t" << name << "  # Set contents:\n";
	int i = 1;
	for (const auto& el : s) {
		cout << i++ << ". " << el << endl;
	}
	cout << "Set size: " << s.size() << endl;
}

// Шаблон вывода multiset
template <typename T>
void printMultiset(const multiset<T>& ms, const string& name) {
	cout << "\n\n\t" << name << "  # Multiset contents:\n";
	int i = 1;
	for (const auto& el : ms) {
		cout << i++ << ". " << el << endl;
	}
	cout << "Multiset size: " << ms.size() << endl;
}

// Шаблон для вывода map
template <typename K, typename V>
void printMap(const map<K, V>& m, const string& name) {
	cout << "\n\n\t" << name << "  # Map contents:\n";
	for (const auto& pair : m) {
		cout << pair.first << " -> " << pair.second << endl;
	}
	cout << "Map size: " << m.size() << endl;
}

// Шаблонная функция для печати элементов последовательности
template <typename T>
void printElement(const T& elem) {
	cout << elem << " ";
}

// Функция для перевода строки в нижний регистр
string ToLowerCase(const string& str) {
	string result;
	transform(str.begin(), str.end(), back_inserter(result), [](unsigned char c) {
		return tolower(c);
		});
	return result;
}

// Функция для печати содержимого deque
void printDeque(const deque<MyString>& deq, const string& title) {
	cout << title;
	for (const auto& str : deq) {
		cout << str << " ";
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "rus");
	//Очередь с двумя концами - контейнер deque

	//Создайте пустой deque с элементами типа Point. С помощью
	//assign заполните deque копиями элементов вектора. С помощью
	//разработанного Вами в предыдущем задании универсального шаблона
	//выведите значения элементов на печать
	vector<Point> vec = { Point(1, 2), Point(3, 4), Point(5, 6) };
	deque<Point> deq1;
	deq1.assign(vec.begin(), vec.end());
	pr(deq1, "Deque of Points");


	//Создайте deque с элементами типа MyString. Заполните его значениями
	//с помощью push_back(), push_front(), insert()
	//С помощью erase удалите из deque все элементы, в которых строчки
	//начинаются с 'A' или 'a'
	 // Создаем deque
	deque<MyString> deq2;

	// Заполнение deque
	deq2.push_back(MyString("Apple"));
	deq2.push_front(MyString("Banana"));
	deq2.insert(deq2.begin() + 1, MyString("Avocado"));

	printDeque(deq2, "\n\tDeque of MyString before erasing:\n");

	// Удаление элементов, начинающихся на 'A' или 'a'
	auto it = remove_if(deq2.begin(), deq2.end(),
		[](const MyString& str) {
			return str.startsWithA();
		});
	deq2.erase(it, deq2.end());

	printDeque(deq2, "\n\tDeque of MyString after erasing:\n");

	////////////////////////////////////////////////////////////////////////////////////


	//Напишите шаблон функции для вывода значений stack, queue, priority_queue
	//Подумайте, как "получать" данное "с верхушки"?
	//Что происходит с контейнерами после вывода значений?




	////////////////////////////////////////////////////////////////////////////////////
	//stack

	//Создайте стек таким образом, чтобы
	//а) элементы стека стали копиями элементов вектора
	//б) при выводе значений как вектора, так и стека порядок значений был одинаковым 
	 // Создаем вектор
	vector<int> vecS = { 10, 20, 30, 40 };

	// Создаем стек и копируем элементы вектора в стек с сохранением порядка
	stack<int> st1;
	for (auto it = vecS.rbegin(); it != vecS.rend(); ++it) { // Копируем в обратном порядке
		st1.push(*it);
	}

	// Вывод вектора через функцию pr
	pr(vecS, "Vector");
	// Вывод стека
	printStack(st1, "Stack 1");


	//Сравнение и копирование стеков
	//а) создайте стек и любым способом задайте значения элементов
	//б) создайте новый стек таким образом, чтобы он стал копией первого
	//в) сравните стеки на равенство
	//г) модифицируйте любой из стеком любым образом (push, pop, top)
	//д) проверьте, какой из стеков больше (подумайте, какой смысл вкладывается в такое сравнение)
	{
		// Создаем второй стек (копия первого)
		stack<int> st2 = st1;

		// Сравнение стеков
		if (st1 == st2) {
			cout << "Stacks are equal.\n";
		}
		else {
			cout << "Stacks are not equal.\n";
		}

		// Модификация первого стека
		st1.push(50);
		st1.pop();

		// Проверяем сравнение после изменения
		if (st1 > st2) {
			cout << "st1 is greater than st2.\n";
		}
		else if (st1 < st2) {
			cout << "st1 is less than st2.\n";
		}
		else {
			cout << "Stacks are still equal.\n";
		}
	}


	////////////////////////////////////////////////////////////////////////////////////
	//queue

	//Создайте очередь, которая содержит указатели на объекты типа Point,
	//при этом явно задайте базовый контейнер.
	//Измените значения первого и последнего элементов посредством front() и back()
	//Подумайте, что требуется сделать при уничтожении такой очереди?
	{
		// Создаем очередь с указателями на Point
		queue<Point*> q;

		// Заполняем очередь
		q.push(new Point(1, 2));
		q.push(new Point(3, 4));
		q.push(new Point(5, 6));

		// Изменяем первый и последний элементы
		q.front()->Setx(10);
		q.back()->Sety(20);

		// Выводим элементы очереди
		cout << "Queue elements:\n";
		printQueue(q, "Queue");

		// Уничтожаем элементы очереди
		while (!q.empty()) {
			delete q.front();
			q.pop();
		}
	}
	////////////////////////////////////////////////////////////////////////////////////
	//priority_queue
	//а) создайте очередь с приоритетами, которая будет хранить адреса строковых литералов - const char*
	//б) проинициализируйте очередь при создании с помощью вспомогательного массива с элементами const char*
	//в) проверьте "упорядоченность" значений (с помощью pop() ) - если они оказываются не упорядоченными, подумайте:
	//		что сравнивается при вставке?


	{
		// Массив строковых литералов
		const char* strings[] = { "apple", "banana", "cherry", "date" };

		// Создаем priority_queue
		priority_queue<const char*> pq(begin(strings), end(strings));

		// Проверяем упорядоченность значений
		printPriorityQueue(pq, "Priority Queue");

	}


	////////////////////////////////////////////////////////////////////////////////////
	//set
	//a) создайте множество с элементами типа Point - подумайте, что необходимо определить
	//		в классе Point (и каким образом)
	//б) распечатайте значения элементов с помощью шаблона, реализованного в предыдущей лаб. работе
	//в) попробуйте изменить любое значение...
	//г) Создайте два множества, которые будут содержать одинаковые значения
	//		типа int, но занесенные в разном порядке
	//д) Вставьте в любое множество диапазон элементов из любого другого
	//	контейнера, например, элементов массива	(что происходит, если в массиве имеются дубли?)

	 // Создаем множество Point
	set<Point> points = { Point(1, 2), Point(3, 4), Point(5, 6) };

	// Вывод множества
	printSet(points, "Points Set");

	// Попытка изменить элемент (в set элементы неизменяемы)
	// Для изменения элемента нужно удалить старый и добавить новый
	points.erase(Point(1, 2));
	points.insert(Point(10, 20));
	printSet(points, "Modified Points Set");

	// Создаем два множества int
	set<int> set1 = { 5, 3, 1, 7 };
	set<int> set2 = { 7, 1, 3, 5 };

	// Вывод обоих множеств
	printSet(set1, "Set 1");
	printSet(set2, "Set 2");

	// Вставляем элементы из массива в set
	int arr[] = { 5, 8, 2, 8, 1 }; // Дубли будут игнорироваться
	set1.insert(arr, arr + 5);
	printSet(set1, "Set 1 after array insertion");


	////////////////////////////////////////////////////////////////////////////////////
	//multiset
	// Создаем multiset Point
	multiset<Point> points1 = { Point(1, 2), Point(3, 4), Point(1, 2) };

	// Вывод multiset
	printMultiset(points1, "Points Multiset");

	// Добавляем дубли
	points1.insert(Point(3, 4));
	printMultiset(points1, "Modified Points Multiset");



	////////////////////////////////////////////////////////////////////////////////////
	//map	
	//а) создайте map, который хранит пары "фамилия, зарплата" - pair<const char*, int>,
	//	при этом строки задаются строковыми литералами
	//б) заполните контейнер значениями посредством operator[] и insert()
	//в) распечатайте содержимое

	//е) замените один из КЛЮЧЕЙ на новый (была "Иванова", вышла замуж => стала "Петрова")

	// Создаем map для хранения "фамилия, зарплата"
	map<const char*, int> salaries;
	salaries["Иванов"] = 50000;
	salaries["Петров"] = 60000;
	salaries.insert({ "Сидоров", 45000 });

	// Вывод map
	printMap(salaries, "Salaries");

	// Изменение ключа
	auto it1 = salaries.find("Иванов");
	if (it1 != salaries.end()) {
		int value = it1->second; // Сохраняем значение
		salaries.erase(it1);     // Удаляем старую запись
		salaries["Иванова-Петрова"] = value; // Добавляем с новым ключом
	}

	// Вывод после изменения
	printMap(salaries, "Modified Salaries");
	

	////////////////////////////////////////////////////////////////////////////////////
	//multimap
	//а) создайте "англо-русский" словарь, где одному и тому же ключу будут соответствовать
	//		несколько русских значений - pair<string,string>, например: strange: чужой, странный...
	//б) Заполните словарь парами с помощью метода insert или проинициализируйте с помощью 
	//		вспомогательного массива пара (пары можно конструировать или создавать с помощью шаблона make_pair)
	//в) Выведите все содержимое словаря на экран
	//г) Выведите на экран только варианты "переводов" для заданного ключа. Подсказка: для нахождения диапазона
	//		итераторов можно использовать методы lower_bound() и upper_bound()

	 // Создаем multimap для англо-русского словаря
	cout << "\n\n\t# Multimap contents:\n";
	multimap<string, string> dictionary;

	// Заполнение словаря значениями через insert
	dictionary.insert({ "strange", "чужой" });
	dictionary.insert({ "strange", "странный" });
	dictionary.insert({ "kind", "добрый" });
	dictionary.insert({ "kind", "тип" });
	dictionary.insert({ "key", "ключ" });
	dictionary.insert({ "key", "основной" });

	// Вывод содержимого словаря
	cout << "Содержимое англо-русского словаря:\n";
	for (const auto& pair : dictionary) {
		cout << pair.first << " -> " << pair.second << '\n';
	}

	// Вывод переводов для заданного ключа
	string searchKey = "strange";
	cout << "\nПереводы для ключа \"" << searchKey << "\":\n";
	auto range = dictionary.equal_range(searchKey);
	for (auto it = range.first; it != range.second; ++it) {
		cout << it->second << '\n';
	}

///////////////////////////////////////////////////////////////////

	//Итераторы

	//Реверсивные итераторы. Сформируйте set<Point>. Подумайте, что
	//нужно перегрузить в классе Point. Создайте вектор, элементы которого 
	//являются копиями элементов set, но упорядочены по убыванию


	//Потоковые итераторы. С помощью ostream_iterator выведите содержимое
	//vector и set из предыдущего задания на экран.


	//Итераторы вставки. С помощью возвращаемых функциями:
	//back_inserter()
	//front_inserter()
	//inserter()
	//итераторов вставки добавьте элементы в любой из созданных контейнеров. Подумайте:
	//какие из итераторов вставки можно использовать с каждым контейнером.
	cout << "\n\n\t#Set<Point> content:\n";
	  // Создаем set<Point>
	set<Point> points2 = { {1, 2}, {3, 4}, {2, 3}, {5, 1} };

	// Вывод содержимого set с использованием ostream_iterator
	cout << "Set contents:\n";
	copy(points2.begin(), points2.end(), ostream_iterator<Point>(cout, "\n"));

	// Создаем вектор и копируем элементы из set в обратном порядке
	vector<Point> pointVector(points2.rbegin(), points2.rend());
	cout << "\nVector (reverse order from set):\n";
	copy(pointVector.begin(), pointVector.end(), ostream_iterator<Point>(cout, "\n"));

	// Использование итераторов вставки
	// 1. back_inserter() для vector
	vector<Point> vectorCopy1;
	copy(points2.begin(), points2.end(), back_inserter(vectorCopy1));
	cout << "\nVector copy with back_inserter:\n";
	copy(vectorCopy1.begin(), vectorCopy1.end(), ostream_iterator<Point>(cout, "\n"));

	// 2. inserter() для set
	set<Point> setCopy1;
	copy(vectorCopy1.begin(), vectorCopy1.end(), inserter(setCopy1, setCopy1.end()));
	cout << "\nSet copy with inserter:\n";
	copy(setCopy1.begin(), setCopy1.end(), ostream_iterator<Point>(cout, "\n"));

	// front_inserter() не подходит для vector и set (можно использовать только с контейнерами типа deque или list)


///////////////////////////////////////////////////////////////////

	//Обобщенные алгоритмы (заголовочный файл <algorithm>). Предикаты.

	// алгоритм for_each() - вызов заданной функции для каждого элемента любой последовательности
	//(массив, vector, list...)
	//С помощью алгоритма for_each в любой последовательности с элементами любого типа
	//распечатайте значения элементов
	//Подсказка : неплохо вызываемую функцию определить как шаблон
	  // Использование алгоритма for_each для печати элементов
	vector<int> nums = { 1, 2, 3, 4, 5 };
	cout << "\nPrinting integers using for_each:\n";
	for_each(nums.begin(), nums.end(), printElement<int>);
	cout << endl;




	//С помощью алгоритма for_each в любой последовательности с элементами типа Point
	//измените "координаты" на указанное значение (такой предикат тоже стоит реализовать 
	//как шаблон) и выведите результат с помощью предыдущего предиката

	  // 2. Изменение координат Point с помощью алгоритма for_each
	vector<Point> points3 = { {1, 2}, {3, 4}, {2, 3}, {5, 1} };

	cout << "\nOriginal Points:\n";
	for_each(points3.begin(), points3.end(), printElement<Point>);
	cout << endl;

	for_each(points3.begin(), points3.end(), [](Point& p) {
		p.Setx(p.Getx() + 10);
		p.Sety(p.Gety() + 10);
		});

	cout << "\nModified Points:\n";
	for_each(points3.begin(), points3.end(), printElement<Point>);
	cout << endl;


	//С помощью алгоритма find() найдите в любой последовательности элементов Point
	//все итераторы на элемент Point с указанным значением.

	// 3. Поиск элементов Point с использованием find
	Point target(13, 14);
	auto it2 = find(points3.begin(), points3.end(), target);
	if (it2 != points3.end()) {
		cout << "\nFound Point: " << *it2 << endl;
	}
	else {
		cout << "\nPoint not found\n";
	}



	//С помощью алгоритма sort() отсортируйте любую последовательность элементов Point. 
	////По умолчанию алгоритм сортирует последовательность по возрастанию.
	//Что должно быть определено в классе Point?
	// Замечание: обобщенный алгоритм sort не работает со списком, так как
	//это было бы не эффективно => для списка сортировка реализована методом класса!!!

	 // 4. Сортировка последовательности Point
	cout << "\nPoints before sorting:\n";
	for_each(points3.begin(), points3.end(), printElement<Point>);
	cout << endl;

	sort(points3.begin(), points3.end());

	cout << "\nPoints after sorting:\n";
	for_each(points3.begin(), points3.end(), printElement<Point>);
	cout << endl;


	//Создайте глобальную функцию вида: bool Pred1_1(const Point& ), которая будет вызываться
	//алгоритмом find_if(), передавая в качестве параметра очередной элемент последовательности.
	//С помощью алгоритма find_if() найдите в любой последовательности элементов Point
	//итератор на элемент Point, удовлетворяющий условию: координаты x и y лежат в промежутке
	//[-n, +m].

	  // 5. Использование find_if с предикатом
	auto pred = [](const Point& p) {
		return p.Getx() >= -5 && p.Getx() <= 15 && p.Gety() >= -5 && p.Gety() <= 15;
		};
	auto it3 = find_if(points3.begin(), points3.end(), pred);

	if (it3 != points3.end()) {
		cout << "\nPoint satisfying the condition: " << *it3 << endl;
	}
	else {
		cout << "\nNo Point satisfies the condition\n";
	}

	//С помощью алгоритма sort() отсортируйте любую последовательность элементов Rect,
	//располагая прямоугольники по удалению центра от начала координат.


	 // 6. Сортировка Rect по удалению центра от начала координат
	vector<Rect> rectangles = {
		Rect({0, 0}, {3, 4}),
		Rect({1, 1}, {5, 5}),
		Rect({2, 2}, {6, 6})
	};

	cout << "\nRectangles before sorting:\n";
	for_each(rectangles.begin(), rectangles.end(), [](const Rect& r) {
		cout << r << endl;
		});

	sort(rectangles.begin(), rectangles.end(), [](const Rect& a, const Rect& b) {
		return a.DistanceFromOrigin() < b.DistanceFromOrigin();
		});

	cout << "\nRectangles after sorting by distance from origin:\n";
	for_each(rectangles.begin(), rectangles.end(), [](const Rect& r) {
		cout << r << endl;
		});





	{//transform
		//Напишите функцию, которая с помощью алгоритма transform переводит 
		//содержимое объекта string в нижний регистр.
		//Подсказка: класс string - это "почти" контейнер, поэтому для него
		// определены методы begin() и end()

		 // Transform: перевод содержимого string в нижний регистр
		string str = "HeLLo WoRLd!";
		cout << "\nOriginal string: " << str << endl;

		string lowerStr = ToLowerCase(str);
		cout << "\nString in lower case: " << lowerStr << endl;
		//Заполните list объектами string. С помощью алгоритма transform сформируте
		//значения "пустого" set, конвертируя строки в нижний регистр

		 // Transform: заполнение list и преобразование строк в set
		list<string> strList = { "HELLO", "WORLD", "HELLO", "C++", "Transform" };
		set<string> strSet;

		transform(strList.begin(), strList.end(), inserter(strSet, strSet.end()), ToLowerCase);

		cout << "\nSet with strings in lower case:\n";
		for (const auto& s : strSet) {
			cout << s << " ";
		}
		cout << endl;



	}
	{// map

		//Сформируйте любым способом вектор с элементами типа string.
		//Создайте (и распечатайте для проверки) map<string, int>, который будет
		//содержать упорядоченные по алфавиту строки и
		//количество повторений каждой строки в векторе

		 // Map: создание map<string, int> для подсчета количества повторений строк
		vector<string> strVector = { "apple", "banana", "apple", "orange", "banana", "apple" };
		map<string, int> strMap;

		// Подсчет повторений
		for (const auto& s : strVector) {
			++strMap[s];
		}

		// Вывод содержимого map
		cout << "\nMap of strings and their counts:\n";
		for (const auto& pair : strMap) { // Используем auto для пары
			cout << pair.first << ": " << pair.second << endl; // Обращаемся к ключу и значению
		}
	}
	return 0;
}

