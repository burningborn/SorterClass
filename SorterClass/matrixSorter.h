#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <stdio.h>
using namespace std;
class matrixSorter
{
private:
	int n;
	int* arr;

public:
	matrixSorter();
	matrixSorter(int n);
	matrixSorter(int n, int* arr);
	~matrixSorter();

	matrixSorter& fillArr();
	matrixSorter& sortArr();
	void arrToFile(char name[]);
	void fileToArr(char name[]);
	
	void display();
};

