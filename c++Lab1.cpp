/*Лаб. 1. №7 Найти максимальный среди элементов тех столбцов, которые упорядочены либо по
возрастанию, либо по убыванию. Если упорядоченные столбцы в матрице отсутствуют, то
вывести 0.
Асташова В.*/
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <fstream>
#include <string>

using namespace std;

	int  **InputMatrix (int &m, int &n)
	{
		//ввод матрицы
		int **mas;
		mas = new int*[m]; 
		for ( int i = 0; i < m; i++) 
				mas[i] = new int[n];

		return mas;
	}

	//печать матрицы
	void PrintMatrix (int **mas, int &m, int &n)
	{
		for (int i = 0; i < m; i++) 
		{
			for (int j = 0; j < n; j++) 
				cout << setw(3) << mas[i][j] << "  "; 
				cout << endl;
		}     
		cin.get();
	}

	//ввод элементов матрицы в консоли
	void InputMatrConsol (int m, int n, int **mas)
	{
		for ( int i = 0; i < m; i++)
			{ 
				for ( int j = 0; j < n; j++) 
					{ 
						cout << "Введите элемент " << "[" << i << "][" << j << "]  "; 
						cin >> mas[i][j]; 
					}
			}
		cout << endl;
		PrintMatrix(mas, m, n);

	}

	void InputMatrRandom (int m, int n, int **mas)
	{
		for ( int i = 0; i < m; i++)
			{ 
				for ( int j = 0; j < n; j++) 
					{ 
						mas[i][j] = 1 + rand () % 51; //рандомное заполнение матрицы от 0 до 50 
					}
			}
		cout << endl;
		PrintMatrix(mas, m, n);
	}

	int **InputMatrFile(int &m, int &n)
	{
		char* Fname;
		int **mas;
			cout << "Введите имя файла: " << endl;
			cin >> Fname;
			ifstream file(Fname);
			//file.open(Fname);
		if (!file.is_open())
			{
				cout << "\nФайл не найден.\n";
				mas = NULL;
				return mas;
			}
		else 
		{
			if (!file.eof())   // считываем размерности массива
				file >> m;
			if (!file.eof())
				file >> n;

			mas = InputMatrix(m, n);// инициализируем матрицу

			for (int i = 0; i < m; i++)
				{
					for (int j = 0; j < n; j++)
						{
							if (!file.eof())
							file >> mas[i][j];
						}
					}
			}
	file.close();
	PrintMatrix(mas, m, n);
	return mas;
	}



	int Menu ()
	{
		cout << "	**************************************************** \n";
		cout << "	*                       МЕНЮ                       * \n";
		cout << "	**************************************************** \n";
		cout << "	*  1 - Ввести матрицу в консоли                    * \n";
		cout << "	*--------------------------------------------------* \n";
		cout << "	*  2 - Заполнить матрицу произвольными значениями  * \n";
		cout << "	*--------------------------------------------------* \n";
		cout << "	*  3 - Загрузить матрицу из файла                  * \n";
		cout << "	**************************************************** \n";
		int num;
		do {
			cin >> num;
			if ((num != 1) && (num != 2) && (num != 3))
				cout << "Ведено некорректное значение. Повторите ввод.\n";
		} while ((num != 1) && (num != 2) && (num != 3));

		
		getchar();
		cout << "\n"; 
		return num;
	}

void Task (int **mas, int &m, int &n)
{
	int k = 0;
	for (int j = 0; j < n; j++)
		{
			int i = 1;
			while ((i <= m-1) && (mas[i-1][j] < mas[i][j]) )// возрастает
				i++;
			if (i == m) 
			cout <<"Максимальный элемент в "<< j+1 << " столбце " << mas[i-1][j] << endl; // печатаем max элемент, т.е последний
			else 
			{ 
				i = 1;
				while ((i <= m-1) && (mas[i-1][j] > mas[i][j])) // убывает
					i++;
				if (i == m) 
			cout << "Максимальный элемент в "<< j+1 << " столбце " << mas[0][j] << endl; //  печатаем max элемент, т.е первый
				else
				{
					cout << "Столбец " << j+1 << " неупорядочен " << endl;
					k++;
				}
			}
		}
		if ( k == n) 
		 cout <<  "0 - упорядоченных столбцов нет" << endl;
		cin.get();
delete [] mas;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int **matrix; 
	int m = 0; int n = 0;

	//выбор способа ввода матрицы
	int number = Menu ();
	switch (number) 
		{
			case 1: 
				cout<<"Введите размерность матрицы M x N"<<endl;
				cout<<"Введите количество строк m = ";
				cin>>m;
				cout<<"Введите количество столбцов n = ";
				cin>>n;
				matrix = InputMatrix(m, n);//инициализируем матрицу
				InputMatrConsol(m, n, matrix); //заполняем матрицу
				break;
			case 2: 
				cout<<"Введите размерность матрицы M x N"<<endl;
				cout<<"Введите количество строк m = ";
				cin>>m;
				cout<<"Введите количество столбцов n = ";
				cin>>n;
				matrix = InputMatrix(m, n);//инициализируем матрицу
				InputMatrRandom(m, n, matrix); //заполняем матрицу
				break;
			case 3: matrix = InputMatrFile(m, n);
				break;
		}

	Task(matrix, m, n);
	system("pause");				
	return 0;
}


