#include "Calcul.h"


Calcul::Calcul(string finName, string foutName)
{
	OpenInFile(finName);
	ReadFile();
	file_in.close();
	MeanValue();
	StandartDeviation();
	OpenOutFile(foutName);
	WriteFile();
	file_out.close();
}

Calcul::~Calcul()
{
}

double Calcul::GetMeanValue()
{
	return mean_value;
}

double Calcul::GetStandartDeviation()
{
	return standart_deviation;
}

int * Calcul::GetData()
{
	return data;
}

int Calcul::GetSize()
{
	return size;
}

int Calcul::ReadFile()
{
	file_in.seekg(0, ios_base::end);
	size = file_in.tellg() / sizeof(int);
	file_in.seekg(0, ios_base::beg);
	data = (int *)malloc(size * sizeof(int));
	file_in.read((char *)data, size * sizeof(int));
	return 0;
}

int Calcul::WriteFile()
{
	file_out << "M(x) = " << mean_value << '\n';
	file_out << "S(x) = " << standart_deviation << '\n';
	return 0;
}

bool Calcul::OpenInFile(string fName)
{
	file_in.open(fName, ios::binary);
	if (!file_in.is_open()) {
		return false;
	}
	return true;
}
bool Calcul::OpenOutFile(string fName)
{
	file_out.open(fName, ios::binary);
	if (!file_out.is_open()) {
		return false;
	}
	return true;
}

int Calcul::MeanValue()
{
	for (int i = 0; i < size; i++) {
		mean_value += (double)data[i] / (double)size;
	}	
	return 0;
}

int Calcul::StandartDeviation()
{
	double sum = 0.0;
	for (int i = 0; i < size; i++) {
		sum += (double)data[i];
	}
	sum = sum / (double)size;
	standart_deviation = 0.0;
	for (int i = 0; i < size; i++) {
		standart_deviation += pow((double)data[i] - sum, 2);
	}
	standart_deviation = sqrt(standart_deviation / (double)(size - 1));
	return 0;
}
