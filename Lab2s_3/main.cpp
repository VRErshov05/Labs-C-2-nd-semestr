// Темы:
// Перегрузка операторов.
// Встроенные объекты 
#include<iostream>
#include"MyString.cpp"
#include "Point.cpp"
//#include"BigData.cpp"
#include"HashmapBD.cpp"
using namespace std;
void numz(string n)
{
	using namespace std;
	cout << "\n--------------------------------" << endl;
	cout << "Задание " << n << ":\n" << endl;
}



// перегрузка оператора - для вычитания из точки числа
Point operator-(Point& pt1, int i) {
	Point tmp;
	tmp.Setx(pt1.Getx()-i);
	tmp.Sety(pt1.Gety() - i);
	return tmp;
}

// перегрузка оператора - для вычитания одной точки из другой
Point operator-(Point& pt1, Point& pt2) {
	Point tmp;
	tmp.Setx(pt1.Getx() - pt2.Getx());
	tmp.Sety(pt1.Gety() - pt2.Gety());
	return tmp;
}


ostream& operator<<(ostream& out, const BD& bd) {
	for (int i = 0; i < bd.capacity; i++) {
		if (!bd.elements[i].name.empty())
			out << "NAME: " << bd.elements[i].name << " Age: " << bd.elements[i].age << " Gender: " << bd.elements[i].gender << " Post: " << bd.elements[i].post << " Salary: " << bd.elements[i].salary << "\n";
	}
	return out;
}
ostream& operator<<(ostream& out, const Data& data) {
	out << "NAME: " << data.name << " Age: " << data.age << " Gender: " << data.gender << " Post: " << data.post << " Salary: " << data.salary << "\n";
	return out;
}


int main()
{
	setlocale(LC_ALL, "rus");
//////////////////////////////////////////////////////////////////////



	//Задание 1.Перегрузка операторов.

	//Подключите к проекту файлы MyString.cpp и MyString.h
	//класса MyString, разработанного Вами на предыдущем занятии
	//9a. Перегрузите оператор присваивания для класса MyString
	//Проверьте корректность работы перегруженного оператора

	{
		numz("1");
		MyString s1("AAA"), s2;
		s2=s1;
		s1.print();//AAA
		s2.print();//AAA
		s1="CCC";
		s1.print();//CCC
		s2= MyString("tmp");
		s2.print();//tmp
		s1=s1;
		s1.print();//CCC
	}




	//2.Создайте класс Point, который будет содержать координаты
	//"точки". Объявите конструктор (конструкторы) класса   

	//2b. "Перегрузите" оператор += так, чтобы при выполнении
	//операции типа pt2+=pt1; складывались
	//одноименные переменные объектов pt1 и pt2, а сумма
	//присваивалась соответствующим переменным объекта pt2 или
	// в случае  pt2+=1; обе переменные объекта pt2 увеличивались на
	// указанное значение
	//a) с помощью метода класса (оператор +=)
	//б) с помощью глобальной функции (оператор -=)
	//Проверьте корректность работы перегруженного оператора

	{
		numz("2b");
		Point pt1(1, 1);
		pt1.print();//1 1
		Point pt2(2, 2);
		pt2.print();//2 2
		pt2 += pt1;
		pt2.print();//3 3
		pt2 += 1;
		pt2.print();//4 4
		Point pt3(3, 3);
		pt2 += pt1 += pt3;
		pt2.print();//8 8

	}
	


	//Задание 2c. Перегрузите оператор +/- 
	//a)с помощью методов класса (оператор +)
	//б) с помощью  глобальных функций (оператор -)
	//так, чтобы любая из закомментированных строк
	//кода выполнялась корректно
	{
		numz("2c");
		Point pt1(1, 1);
		pt1.print();//1 1
		Point pt2(2, 2);
		pt2.print();//2 2
		Point pt3;

		pt3 = pt1 + 5;
		pt3.print();//6 6 
		pt3 = 2 + pt1;
		pt3.print();//3 3
		pt3 = pt1 + pt2;
		pt3.print();//3 3

		pt3 = pt1 - 5;
		pt3.print();//-4 -4
		pt3 = pt1 - pt2;
		pt3.print();//-1 -1
	}

	{
		numz("1d");
		Point pt1(1, 1);
		pt1.print();//1 1
		Point pt3;
		//Задание 1d. Перегрузите унарный оператор +/- 
		pt3 = -pt1;
		pt3.print();
		pt3 = +pt1;
		pt3.print();
	}



	{
		numz("2d");

		//Задание 2d. Перегрузите оператор << (вывода в поток) для
		//класса MyString таким образом, чтобы при выполнении приведенной строки
		//на экран было выведено:
		//contents:  "QWERTY"

		MyString s("QWERTY");
		cout << s << endl;



	}

	{
		numz("2e");
		//Задание 2e*. Перегрузите операторы + и += для класса MyString таким образом,
		  //чтобы происходила конкатенация строк
		MyString s1("QWERTY"), s2("AAA"), s3, s4("BBB");
		s3 = s1 + s2;
		s3.print();
		s4 += s1;
		s4.print();
	}

	{
		numz("3");
		//Задание 3. Разработать "базу данных" о сотрудниках посредством ассоциативного
		//массива. Ключом является фамилия (ключ в задании уникален, поэтому нескольких Ивановых
		//в базе быть не может), а данными: пол, возраст, должность, зарплата...
		//Реализуйте:
		//добавление сотрудников в базу
		//исключение
		//вывод информации о конкретном сотруднике
		//вывод всей (или интересующей) информации о всех сотрудниках
		
		BD bd;
		
		bd["Ivanov"] = Data(30, Male, "Президент", 300000.0);
		
		bd["Ivanov"] = Data(50, Male, "Президент", 300000.0);
		
		bd["Smirnov"] = Data(40, Male, "Вице-Президент", 200000.0);
		
		bd["Kuznecova"] = Data(30, Female, "Секретарь", 100000.0);
		
		bd["udalit"] = Data(30, Male, "CEO", 300000.0);
		
		bd["Krupskaya"] = Data(25, Female, "Химик-Биолог", 150000.0);
		
		bd.del("udalit");
		
		cout << bd << "\n";
		BD bdnew = bd;
		
		bdnew = bd;
		
		bdnew.del("netu");
		
		bdnew["Ershov"] = Data(18, Male, "Студент", 0.0);
		
		BD bdmove;
		
		bdmove = move(bdnew);
		
		cout << "\n" << bdmove;
		
		cout << "\n" << bdmove["Ershov"];
		
	}
	return 0;
}//endmain