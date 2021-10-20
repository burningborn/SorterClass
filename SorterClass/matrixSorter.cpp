#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <windows.h>
#include <stdio.h>
#include "matrixSorter.h"

using namespace std;

matrixSorter::matrixSorter()
{
	n = 0;
	arr = nullptr;
	cout << "NoParamConstructor" << endl;
}
matrixSorter::matrixSorter(int n)
{
	this->n = n;
	this->arr = new int[n];
	cout << "sizeConstructor" << endl;
}
matrixSorter::matrixSorter(int n, int* arr)
{
	this->n = n;
	this->arr = new int[n];
	for (int i = 0; i < n; i++)
	this->arr[i] = arr[i];
	cout << "arrConstructor" << endl;
}
matrixSorter::~matrixSorter()
{
	delete[] arr;
	cout << "Destructor" << endl;
}

matrixSorter& matrixSorter::fillArr()
{
	srand(time(0));
	if (n < 80)
	{
		for (int i = 0; i < n; i++)
		{
		int Rand, key = 0;
			do
			{
			Rand = rand() % 80 + 20;
			for (int j = 0; j < i + 1; j++)
				{
					if (arr[j] == Rand)
					++key;
					break;
				}	
			} while (key);
			arr[i] = Rand;
		}
	}
	else 
	{
		for (int i = 0; i < n; i++)
		{			
				for (int j = 0; j < i + 1; j++)
				{
					arr[i] = rand() % 80 + 19;
				}			
		}
	}
	return *this;
}
matrixSorter& matrixSorter::sortArr() 
{
	sort(arr, arr + n);
	return *this;
}

void matrixSorter::arrToFile(char name[])
{
	ofstream out;					//������ �����
	out.open(name);					//��������� ���� 
	if (!out.is_open())				//��������� ��� ���� ������
	{
		cout << "������ �������� �����!\n";
	}
	else
	{
		cout << "���� ������\n";
		for (int i = 0; i < n; i++) {
			out << arr[i] << " ";	//���������� ���������� �� ������� � ����
		}
	}
	out.close();					//��������� ����
}
void matrixSorter::fileToArr(char name[])
{
	ifstream in;							//������ �����
	in.open(name);							//��������� ���� 
	if (!in.is_open())						//��������� ��� ���� ������
	{
		cout << "������ �������� �����!\n";
	}
	else
	{
		cout << "���� ������\n";
		for (int i = 0; i < n; i++) {			
			in >> arr[i];					//���������� ���������� �� ����� � ������
		}
		cout << endl;
	}
	in.close();								//��������� ����
}

void matrixSorter::display()
{
	for (int i = 0; i < n; i++) {
		cout << arr[i] << "*";
		if ((i + 1)%20 == 0)
			cout << endl;
	}		
		cout << endl;
}
