#include<iostream>
using namespace std;
void Foo1(double* arr, double* copyarr, int size);
void Foo2(double* arr, double* copyarr, int size);
double randfrom(double min, double max);
void FillArray(double* const arr, const int size);
void ShowArray(double* const arr, const int size);
int main()
{
	setlocale(0, "ru");
	cout << "Введите размер массива ";
	int size;
	cin >> size;
	double* arr = new double[size];
	double* copyarr = new double[size];
	FillArray(arr, size);
	ShowArray(arr, size);
	cout << "Введите количество сглаживаний массива ";//5 по заданию
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			Foo1(arr, copyarr, size);
			ShowArray(copyarr, size);
		}
		else
		{
			Foo2(arr, copyarr, size);
			ShowArray(arr, size);
		}
	}
	delete[] arr;
	delete[] copyarr;
	return 0;
}
void Foo1(double* arr, double* copyarr, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (i == 0)
		{
			copyarr[i] = arr[i];
			continue;
		}
		copyarr[i] = (arr[i] + arr[i - 1]) / 2;
	}
}
void Foo2(double* arr, double* copyarr, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (i == 0)
		{
			arr[i] = copyarr[i];
			continue;
		}
		arr[i] = (copyarr[i] + copyarr[i - 1]) / 2;
	}
}
double randfrom(double min, double max)
{
	double range = (max - min);
	double div = RAND_MAX / range;
	return round((min + (rand() / div)) * 10) / 10;
}
void FillArray(double* const arr, const int size)
{
	for (int i = 0; i < size; i++) {
		arr[i] = randfrom(1, 15);
	}
}
void ShowArray(double* const arr, const int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << "\t";
	    cout << endl;

}