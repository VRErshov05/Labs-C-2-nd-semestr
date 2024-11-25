//=======================================================================
//	Лабораторная №3. Шаблоны функций. Шаблоны классов. Стандартные шаблоны С++.
//				Обработка исключений.
//=======================================================================
//Используйте недостающие файлы из лабораторной 2
#include "stdafx.h"
#include "MyVector.h"
#include "MyString.h"
#include "MyStack.h"




//============= Шаблон функции для вывода с помощью итератора
template <class T>
void pr(T& v, string s)
{
	cout << "\n\n\t" << s << "  # Sequence:\n";

	
	typename T::iterator p;
	int i;

	for (p = v.begin(), i = 0; p != v.end(); ++p, ++i)
		cout << endl << i + 1 << ". " << *p;
	cout << '\n';
	cout << "Size: " << v.size() << endl;
	cout << "Capacity: " << v.capacity() << endl; 
	cout << "Max size: " << v.max_size() << endl;
}

template<typename N> void Swap(N& f, N& s) {
	std::swap(f, s);
}



int main()
{
	setlocale(LC_ALL, "rus");
	//===========================================================
	// Шаблоны функций
	//===========================================================
	// Создайте шаблон функции перестановки двух параметров - Swap().
	// Проверьте работоспособность созданного шаблона с помощью
	// приведенного ниже фрагмента.
	{
		
		
		int i = 1, j = -1;
		Swap (i, j);


		double a = 0.5, b = -5.5;
		Swap (a, b);


		Vector u(1,2), w(-3,-4);
		Swap (u, w);
		

		MyString s1 ("Your fault"), s2 ("My forgiveness");
		Swap (s1, s2);
	}




	//===========================================================
	// Шаблоны классов
	//===========================================================
	// Создайте шаблон класса MyStack для хранения элементов любого типа T.
	// В качестве основы для стека может быть выбран массив.
	// Для задания максимального размера стека может быть использован
	// параметр-константа шаблона
	// Обязательными операциями со стеком являются "Push" и "Pop","GetSize" и "Capacity"
	// Необязательной - может быть выбор по индексу (operator[]).
	// Для того, чтобы гарантировать корректное выполнение этих операций 
	// следует генерировать исключительные ситуации.
	
	// С помощью шаблона MyStack создайте стек переменных типа int, затем
	// стек переменных типа double и, наконец, стек из переменных типа Vector 
	// Если вы подготовите три класса для обработки исключений,
	// то следующий фрагмент должен работать



	
	try
	{

		cout << "\tTest MyStack\n";
		MyStack <int, 3> stack;

		cout << "\nInteger Stack capacity: " << stack.Capacity();

		stack.Push(1);
		stack.Push(2);
		stack.Push(3);
		
		cout << "\nInteger Stack has: " << stack.GetSize() << " elements";

//		stack.Push(4);	// Здесь должно быть "выброшено" исключение

		cout << "\nInteger Stack pops: " << stack.Pop();
		cout << "\nInteger Stack pops: " << stack.Pop();
		
		cout << "\nInteger Stack has: " << stack.GetSize() << " elements";
		stack.Pop();
//		stack.Pop();		// Здесь должно быть "выброшено" исключение
		stack.Push(2);
		
//		int i = stack[3];	// Здесь должно быть "выброшено" исключение
		

		MyStack<Vector, 5> ptStack;
		
		cout << "\n\n\nVector Stack capacity: " << ptStack.Capacity();
		
		ptStack.Push(Vector(1,1));
		ptStack.Push(Vector(2,2));
		
		cout << "\nVector Stack pops: ";
		// Используйте метод класса Vector для вывода элемента
		ptStack.Pop().Out();
		
		cout << "\nVector Stack has: " << ptStack.GetSize() << " elements";
	}
	catch (StackOverflow)
	{
		cout << "\nStack overflow";
	}
	catch (StackUnderflow)
	{
		cout << "\nStack underflow";
	}
	catch (StackOutOfRange o)
	{
		o.what();
	}



	//=======================================================================
	// Контейнеры стандартной библиотеки. Последовательности типа vector
	//=======================================================================
	
	// Создайте пустой вектор целых чисел. Узнайте его размер с помощью метода size(),
	// С помощью метода push_back() заполните вектор какими-либо значениями.
	// Получите новый размер вектора и выведите значения его элементов.
	// В процессе работы с вектором вы можете кроме количества реально заполненных
	// элементов (size()) узнать максимально возможное количество элементов (max_size()),
	// а также зарезервированную память (capacity()).

	vector<int> v;
	int n = v.size();
	v.push_back(-1);
	v.push_back(-2);
	n = v.size();
	n = v.capacity();
	n = v.max_size();
		
	// Так как мы часто будем выводить последовательности, то целесообразно
	// создать шаблон функции для вывода любого контейнера.
	// Проанализируйте коды такого шабдлона (pr), который приведен выше
	// Используйте его для вывода вашего вектора

	pr (v, "Vector of ints");
	
	// Используем другой конструктор для создания вектора вещественных
	// с начальным размером в 2 элемента и заполнением (222.).
	// Проверим параметры вектора. Затем изменим размер вектора и его заполнение
	// (метод - resize()) и вновь проверим параметры.
	
	vector<double> vd;
	vd.push_back(1.11);
	vd.push_back(2.22);

	pr (vd, "Vector of doubles");
	n = vd.size();
	n = vd.capacity();
	n = vd.max_size();

	vd.resize(4,4.44);
	pr (vd, "After resize");
	n = vd.size();
	n = vd.capacity();
	n = vd.max_size();
	
	// Используя метод at(), а также операцию выбора [], измените значения
	// некоторых элементов вектора и проверьте результат.
	vd.at(2) = 3.33;
	pr (vd, "After at");
	
	// Создайте вектор вещественных, который является копией существующего.
	vector<double> wd;
	wd = vd;
	pr (wd, "Copy");
	
	// Создайте вектор, который копирует часть существующей последовательности
	vector<double> ud;
	ud.assign(wd.begin() + 1, wd.begin() + 3);
	pr (ud, "Copy part");

	// Создайте вектор вещественных, который является копией части обычного массива.
	double ar[] = { 0., 1., 2., 3., 4., 5. };

	vector<double> va(ar + 1, ar + 4);
	pr (va, "Copy part of array");
	
	// Создайте вектор символов, который является копией части обычной строки
	char s[] = "Array is a succession of chars";
	
	vector<char> vc(s, s+14);
	pr (vc, "Copy part of c-style string");

	// Создайте вектор элементов типа Vector и инициализируйте
	// его вектором с координатами (1,1).
	vector<Vector> vv;
	vv.push_back(Vector(1, 1));
	vv.push_back(Vector(2, 2));
	
	
	cout << "\n\nvector of Vectors\n";
	for (int i = 0; i < vv.size(); i++) {
		cout <<"\n"<< i + 1 << ". ";
		vv[i].Out();
	}
	
	// Создайте вектор указателей на Vector и инициализируйте его адресами
	// объектов класса Vector
	
	
	Vector v1(1, 1), v2(2, 2), v3(3, 3), v4(4, 4), v5(5, 5);
	vector<Vector*> vp{ &v1, &v2, &v3 };

	cout << "\n\nvector of pointers to Vector\n";
	for (size_t i=0;  i < vp.size();  i++)
		vp[i]->Out();
	
	// Научитесь пользоваться методом assign и операцией
	// присваивания = для контейнеров типа vector.
	vp.assign({ &v4, &v5 });

	cout << "\n\nAfter assign\n";
	for (size_t i=0;  i < vp.size();  i++)
		vp[i]->Out();
	
	// Декларируйте новый вектор указателей на Vector и инициализируйте его 
	// с помощью второй версии assign
	vector<Vector*> vpNew;
	vpNew.assign(vp.begin(), vp.end());
	
	cout << "\n\nNew vector after assign\n";
	for (size_t i=0;  i < vpNew.size();  i++)
		vpNew[i]->Out();


	// На базе шаблона vector создание двухмерный массив и
	// заполните его значениями разными способами.
	// Первый вариант - прямоугольная матрица
	// Второй вариант - ступенчатая матрица

	size_t rows = 3;    // Количество строк
	size_t cols = 4;    // Количество столбцов

	// Создаем прямоугольную матрицу с одинаковым количеством столбцов в каждой строке
	vector<vector<double>> rect(rows, vector<double>(cols));

	// Заполняем прямоугольную матрицу значениями
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			rect[i][j] = i * cols + j;  // Пример заполнения уникальными значениями
		}
	}

	cout << "\n\n\tПрямоугольная матрица:\n";
	for (size_t i = 0; i < rect.size(); i++) {
		cout << endl;
		for (size_t j = 0; j < rect[i].size(); j++) {
			cout << rect[i][j] << "  ";
		}
	}
	
	//========= Ступенчатая матрица
	//vector <vector
	size_t steps = 5;  // Количество строк в ступенчатой матрице
	vector<vector<double>> vdd(steps);

	// Заполняем ступенчатую матрицу значениями
	for (size_t i = 0; i < vdd.size(); i++) {
		vdd[i] = vector<double>(i + 1, double(i));  // Создаем строку с i+1 элементами, заполненную значением i
	}

	cout << "\n\n\tСтупенчатая матрица:\n";
	for (size_t i = 0; i < vdd.size(); i++) {
		cout << endl;
		for (size_t j = 0; j < vdd[i].size(); j++) {
			cout << vdd[i][j] << "  ";
		}
	}
  
	

	//===================================
	// Простейшие действия с контейнерами
	//===================================
	//3б. Получение значения первого и последнего элементов последовательности.
	//Получение размера последовательности. Присваивание значений
	//элементов одной последовательности элементам другой - assign().

	//Создайте и проинициализируйте вектор из элементов char. Размер -
	//по желанию.
	vector<char> vChar = { 'A', 'B', 'C', 'D', 'E' };

	//Создайте и проинициализируйте массив из элементов char. Размер -
	//по желанию.
	char cMas[] = { 'X', 'Y', 'Z' };

	//Получите значение первого элемента вектора ( front() )
	cout << "\n\nПервый элемент вектора: " << vChar.front() << endl; 

	//Получите значение последнего элемента вектора ( back() )
	cout << "Последний элемент вектора: " << vChar.back() << endl;

	//Получите размер вектора
	cout << "Размер вектора: " << vChar.size() << endl;

	//Присвойте вектору любой диапазон из значений массива cMas.
	vChar.assign(cMas, cMas + 3);

	//Проверьте размер вектора, первый и последний элементы.
	cout << "\nПосле присваивания значений из массива:\n";
	cout << "Новый размер вектора: " << vChar.size() << endl;
	cout << "Новый первый элемент вектора: " << vChar.front() << endl;
	cout << "Новый последний элемент вектора: " << vChar.back() << endl;
  


	//3в. Доступ к произвольным элементам вектора с проверкой - at()
	//и без проверки - []
	//Создайте неинициализированный вектор из 8 элементов char - vChar2.
	vector<char> vChar2(8);
	//С помощью at() присвойте четным элементам вектора значения
	//элементов vChar1 из предыдущего задания,
	vector<char> vChar1 = { 'A', 'B', 'C', 'D', 'E' };
	for (size_t i = 0; i < vChar2.size(); i += 2) {
		if (i / 2 < vChar1.size()) {
			vChar2.at(i) = vChar1.at(i / 2); // Доступ с проверкой
		}
	}
	//а с помощью [] присвойте нечетным элементам вектора vChar2 значения
	//массива {'K','U','K','U'}.
	char ku[] = { 'K', 'U', 'K', 'U' };
	for (size_t i = 1; i < vChar2.size(); i += 2) {
		vChar2[i] = ku[(i - 1) / 2]; // Доступ без проверки
	}
	  
	//Попробуйте "выйти" за границы вектора с помощью at() и
	//с помощью []. Обратите внимание: что происходит при
	//попытке обращения к несуществующему элементу в обоих случаях
	try {
		cout << "\nПопытка доступа к vChar2.at(10): ";
		cout << vChar2.at(10) << endl; // Это вызовет исключение
	}
	catch (out_of_range& e) {
		cout << "Ошибка: " << e.what() << endl;
	}

	cout << "\nПопытка доступа к vChar2[10]: ";
	//cout << vChar2[10] << endl; // Безопасности здесь нет - произойдет доступ к несуществующему элементу.
  
	

	//3г.Добавьте в конец вектора vChar2  - букву Z (push_back()). Для
	//расширения кругозора можете ее сразу же и выкинуть (pop_back())

	vChar2.push_back('Z');
	cout << "\n\nПоследний элемент после добавления Z: " << vChar2.back() << endl;
	vChar2.pop_back();
	cout << "Последний элемент после удаления Z: " << (vChar2.empty() ? "Вектор пуст" : string(1, vChar2.back())) << endl;
  
	
	//3д. Вставка-удаление элемента последовательности insert() - erase()
	//Очистка последовательности - clear()



	//Вставьте перед каждым элементом вектора vChar2 букву 'W'
	for (size_t i = 0; i < vChar2.size(); i += 2) {
		vChar2.insert(vChar2.begin() + i, 'W');
	}

	//Вставьте перед 5-ым элементом вектора vChar2 3 буквы 'X'
	if (vChar2.size() >= 5) {
		vChar2.insert(vChar2.begin() + 4, 3, 'X');
	}

	//Вставьте перед 2-ым элементом вектора vChar2 с третьего по
	//шестой элементы массива "aaabbbccc"
	char abc[] = "aaabbbccc";
	if (vChar2.size() >= 2) {
		vChar2.insert(vChar2.begin() + 1, abc, abc + 9);
	}
  
	//Сотрите c первого по десятый элементы vChar2
	if (vChar2.size() >= 10) {
		vChar2.erase(vChar2.begin(), vChar2.begin() + 10);
	}
  
	

	//Уничтожьте все элементы последовательности - clear()
	vChar2.clear();
	cout << "\nРазмер вектора после clear(): " << vChar2.size() << endl;
	
	//Создание двухмерного массива
	vector<vector<int>> twoDArray(3, vector<int>(3, 0)); // 3x3 массив, заполненный нулями

	cout << "\nДвумерный массив:\n";
	for (size_t i = 0; i < twoDArray.size(); ++i) {
		for (size_t j = 0; j < twoDArray[i].size(); ++j) {
			cout << twoDArray[i][j] << " ";
		}
		cout << endl;
	}
	/*
///////////////////////////////////////////////////////////////////

	//Задание 4. Списки. Операции, характерные для списков.
	//Создайте два пустых списка из элементов Vector - ptList1 и
	//ptList2
	 list<vector<Vector>> ptList1;
	 list<vector<Vector>> ptList2;

	//Наполните оба списка значениями с помощью методов push_back(),
	//push_front, insrert()
	 ptList1.push_back({ Vector(1,2), Vector(3,4) });
	 ptList2.push_back({ Vector(5,6), Vector(7,8) });

	 ptList1.push_front({ Vector(12,14) });
	 ptList2.push_front({ Vector(16,17) });

	 ptList1.insert(++ptList1.begin(), { Vector(21,32) });
	 ptList2.insert(++ptList2.begin(), { Vector(13,28) });

	 pr(ptList1, "ptList1");
	 pr(ptList2, "ptList2");

	//Отсортируйте списки - sort().
	//Подсказка: для того, чтобы работала сортировка, в классе Vector
	//должен быть переопределен оператор "<"

	 ptList1.sort();
	 ptList2.sort();

	 pr(ptList1, "ptList1 after sort");
	 pr(ptList2, "ptList2 after sort");
	

	//Объедините отсортированные списки - merge(). Посмотрите: что
	//при этом происходит со вторым списком.

	 ptList1.merge(ptList2);

	 pr(ptList1, "ptList1 after merge");
	 pr(ptList2, "ptList2 after merge");

	

	//Исключение элемента из списка - remove()
	//Исключите из списка элемент с определенным значением.
	//Подсказка: для этого необходимо также переопределить
	//в классе Vector оператор "=="
	 ptList1.remove({ Vector(12,14) });
	 pr(ptList1, "After remove (12,14)");
	 std::cout << endl;

	
///////////////////////////////////////////////////////////////////

	//Задание 5. Стандартные алгоритмы.Подключите заголовочный файл
	// <algorithm>
	//5а. Выведите на экран элементы ptList1 из предыдущего
	//задания с помощью алгоритма for_each()

	 for_each(ptList1.begin(), ptList1.end(), [](const std::vector<Vector>& vec) {
		 // Для каждого вектора выводим его элементы
		 for_each(vec.begin(), vec.end(), [](const Vector& vecElement) {
			 std::cout << vecElement << " "; // Выводим объект Vector с использованием перегруженного оператора <<
			 });
		 std::cout << std::endl; // Для отделения элементов разных векторов
		 });

	 cout << endl;
	

	//5б.С помощью алгоритма find() найдите итератор на элемент Vector с
	//определенным значением. С помощью алгоритма find_if() найдите
	//итератор на элемент, удовлетворяющий определенному условию, 
	//например, обе координаты точки должны быть больше 2.
	//Подсказка: напишите функцию-предикат, которая проверяет условие
	//и возвращает boolean-значение (предикат может быть как глобальной
	//функцией, так и методом класса)

	 bool found = false;
	 for (auto& vec : ptList1) {
		 auto it = std::find_if(vec.begin(), vec.end(), [](const Vector& v) {
			 return v.isGreaterThan2(); // Условие: обе координаты больше 2
			 });
		 if (it != vec.end()) {
			 std::cout << "Найден элемент, удовлетворяющий условию (обе координаты > 2): " << *it << std::endl;
			 found = true;
			 // Прерываем поиск, если нашли
		 }
	 }

	 if (!found) {
		 std::cout << "Элемент, удовлетворяющий условию (обе координаты > 2), не найден" << std::endl;
	 }

	  

	//Создайте список из указателей на элеметы Vector. С помощью 
	//алгоритма find_if() и предиката (можно использовать предикат - 
	//метод класса Vector, определенный в предыдущем задании) найдите в
	//последовательности элемент, удовлетворяющий условию

	 cout << endl;
	 list<Vector*> ptList;
	 Vector v11(1, 2);
	 Vector v22(3, 4);
	 Vector v33(5, 6);
	 Vector v44(7, 8);

	 ptList.push_back(&v11);
	 ptList.push_back(&v22);
	 ptList.push_back(&v33);
	 ptList.push_back(&v44);
	
	 auto it = std::find_if(ptList.begin(), ptList.end(), [](Vector* v) {
		 return v->isGreaterThan2(); // Предикат: обе координаты больше 2
		 });
	 // Выводим результат
	 if (it != ptList.end()) {
		 std::cout << "Найден элемент: " << **it << std::endl;
	 }
	 else {
		 std::cout << "Элемент, удовлетворяющий условию, не найден" << std::endl;
	 }

	//5в. Создайте список элементов Vector. Наполните список
	//значениями. С помощью алгоритма replace() замените элемент
	//с определенным значением новым значением. С помощью алгоритма
	//replace_if() замените элемент, удовлетворяющий какому-либо
	//условию на определенное значение. Подсказка: условие
	//задается предикатом.


 //Сформировали значения элементов списка
	 list<Vector> ptList3 = { Vector(1, 2), Vector(3, 4), Vector(5, 6), Vector(7, 8), Vector(9, 10) };

	 // Выводим начальный список
	 cout << "Начальный список: ";
	 for (const auto& vec : ptList3) {
		 std::cout << vec << " ";
	 }
	 cout << std::endl;

	 // 1. Используем replace() для замены элемента (5, 6) на (0, 0)
	 replace(ptList3.begin(), ptList3.end(), Vector(5, 6), Vector(0, 0));

	 // Выводим список после замены
	 std::cout << "Список после std::replace(): ";
	 for (const auto& vec : ptList3) {
		 std::cout << vec << " ";
	 }
	 cout << std::endl;

	 // 2. Используем replace_if() для замены всех элементов, у которых обе координаты больше 2, на (99, 99)
	 replace_if(ptList3.begin(), ptList3.end(), [](const Vector& v) {
		 return v.isGreaterThan2(); // Условие: обе координаты больше 2
		 }, Vector(99, 99));

	 // Выводим список после замены с условием
	 cout << "Список после std::replace_if(): ";
	 for (const auto& vec : ptList3) {
		 std::cout << vec << " ";
	 }
	 cout << std::endl;



	 cout << endl;
	 //5г. Создайте вектор строк (string). С помощью алгоритма count()
	 //сосчитайте количество одинаковых строк. С помощью алгоритма
	 //count_if() сосчитайте количество строк, начинающихся с заданной
	 //буквы

	 std::vector<std::string> strVec = { "apple", "banana", "cherry", "apple", "date", "apricot", "banana" };

	 // 1. Используем count() для подсчета одинаковых строк
	 string target = "apple";  // строка, которую мы ищем
	 int countApple = count(strVec.begin(), strVec.end(), target);
	 cout << "Количество строк, равных \"" << target << "\": " << countApple << endl;

	 // 2. Используем count_if() для подсчета строк, начинающихся с буквы 'a'
	 char startLetter = 'a'; // Буква, с которой должны начинаться строки
	 int countStartsWithA = std::count_if(strVec.begin(), strVec.end(), [startLetter](const std::string& str) {
		 return !str.empty() && str[0] == startLetter; // Проверка, начинается ли строка с заданной буквы
		 });
	 cout << "Количество строк, начинающихся с буквы '" << startLetter << "': " << countStartsWithA << endl;


	//5д. С помощью алгоритма count_if() сосчитайте количество строк,
	//которые совпадают с заданной строкой. Подсказка: смотри тему
	//объекты-функции

	 string target1 = "banana";

	 int countMatches = count_if(strVec.begin(), strVec.end(),
		 [&target1](const string& str) {
			 return str == target1; // Сравниваем строку с target
		 });
	 cout << "Количество строк, совпадающих с \"" << target1 << "\": " << countMatches << endl;
	
	*/
return 0;
 
}