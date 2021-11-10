#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <windows.h>
//using std::cout;
#include "matrixSorter.h"
using namespace std;

//Реализовать класс - сортировщик, который позволяет :
//1) Сгенерировать массив случайных значений заданной длины   
//2) Записать массив в файл с заданным именем 
//3) Считать массив для сортировки из файла с заданным именем
//4) Отсортировать массив любым методом сортировки(на выбор). 
// 
//5) Для тестирования программы реализовать следующие сценарии :
//a):Сгенерировать массив; 
// записать массив в файл;
//b):Считать массив из файла, 
// отсортировать, 
// записать отсортированный массив в тот же файл вместо старого
//c):Считать массив из файла, 
// отсортировать, записать отсортированный массив в новый файл.
// 
//d):Так же следует прогнать программу на больших массивах(> 1000 элементов).

//Для работы с файлами использовать библиотеку fstream и механизм потоков C++.

//#define LITTLE_MATRIX
#define LARGE_MATRIX

int main()
{
	setlocale(LC_ALL, "Russian");
	
	
#ifdef LITTLE_MATRIX
	matrixSorter mat(5);
char name[] = "Arr.txt";
mat.fillArr();			//генерируем массив двузначных чисел
mat.display();
mat.arrToFile(name);	//записываем массив в файл
matrixSorter Mat(5);
Mat.fileToArr(name);	//считываем массив из файла
Mat.display();
Mat.sortArr();			//сортируем массив
Mat.display();
Mat.arrToFile(name);	//записываем массив в тот же файл вместо старого
mat.fileToArr(name);	//считываем массив из файла
mat.display();
mat.sortArr();			//сортируем массив
mat.display();
char next[] = "Next.txt";
mat.arrToFile(next);	//записываем массив в тот же новый файл   
#endif // LITTLE_MATRIX

#ifdef LARGE_MATRIX
matrixSorter big(15);
big.fillArr();
big.display();
char Big[] = "Big.txt";
try
{
big.arrToFile(Big);
}
catch (exception& ex)
{
	cout << " Мы поймали исключение 1 " << ex.what() << endl;
}
catch (const char* ex)
{
	cout << " Мы поймали исключение 2 " << ex << endl;
}
matrixSorter big_in(1500);
big_in.fileToArr(Big);
big.sortArr();
big.display();

#endif // LARGE_MATRIX


	
	return 0;
}	
