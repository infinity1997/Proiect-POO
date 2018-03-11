#pragma once
#include<fstream>
#include<iostream>
using namespace std;
class Data {
	int _zi;
	int _an;
	int _luna;
public:
	Data();
	Data(int zi, int luna, int an);
	~Data() = default;
	void citireData(ifstream &file);

	int getZi() { return _zi; }
	int getLuna() { return _luna; }
	int getAn() { return _an; }

};
