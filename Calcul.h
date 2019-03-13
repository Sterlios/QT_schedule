#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <stdlib.h>

using namespace std;

class Calcul
{
public:
	Calcul(string finName, string foutName);
	~Calcul();
	double GetMeanValue();
	double GetStandartDeviation();
	int* GetData();
	int GetSize();
private:
	double mean_value;
	double standart_deviation;
	int* data;
	int size;
	ifstream file_in;
	ofstream file_out;

	int ReadFile();
	int WriteFile();
	bool OpenInFile(string fName); 
	bool OpenOutFile(string fName);
	int MeanValue();
	int StandartDeviation();
};
