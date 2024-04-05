#include<string>
#include<iostream>
using namespace std;

class Bochka {
public:
	Bochka(double volume = 0, double proc = 0) : volume(volume), proc(proc) {
		cout << "�������� ����������� " << this << endl;
	}
	~Bochka() {
		cout << "�������� ���������� " << this << endl; 
	}
	double GetV() {
		return volume;
	}
	double GetP() {
		return proc;
	}


	void print() {
		cout << "�����: " << volume << "\n���������: " << proc << endl;
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