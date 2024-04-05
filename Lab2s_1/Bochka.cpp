#include<string>
#include<iostream>
using namespace std;

class Bochka {
public:
	Bochka(double volume = 0, double proc = 0) : volume(volume), proc(proc) {
		cout << "Вызвался конструктор " << this << endl;
	}
	~Bochka() {
		cout << "Вызвался деструктор " << this << endl; 
	}
	double GetV() {
		return volume;
	}
	double GetP() {
		return proc;
	}


	void print() {
		cout << "Объём: " << volume << "\nКонцетрат: " << proc << endl;
	}

	void Pereliv(Bochka* perem) {
		proc = ((((volume * proc) / 100) + (1 * ((*perem).GetP() / 100))) / (volume + 1)) * 100;
		volume += 1;
		(*perem).volminus();
	}


private:

	void volminus() {
		volume -= 1;
	}

	double volume;
	double proc;
};