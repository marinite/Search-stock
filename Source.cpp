#include <iostream>
#include <math.h>
using namespace std;

void input(int N, double** arraySM)
{
	//как связаны между собой элементы, направленный граф
	cout << "How are the elements connected? If elements are connected put 1, otherwise 0" << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << i + 1 << "-" << j + 1 << ": ";
			cin >> arraySM[i][j];
		}
	}
}

void search_stock(int N, double** arraySM)
{
	int* array = new int[N];
	for (int i = 0; i < N; i++)
	{
		array[i] = 0;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arraySM[i][j] == 1)
			{
				array[i] = 1;
				break;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		if (array[i] == 0)
			cout << "Stock: " << i + 1 << endl;
	}

	delete[]array;
}

int main()
{
	int N = 0; //количество элементов
	cout << "Enter the number of circuit elements: ";
	cin >> N;
	double** arraySM = new double* [N];
	for (int i = 0; i < N; i++)
	{
		arraySM[i] = new double[N];
	}

	input(N, arraySM);
	search_stock(N, arraySM);

	for (int i = 0; i < N; i++)
	{
		delete[] arraySM[i];  // удаляем массив
	}
	return 0;
}