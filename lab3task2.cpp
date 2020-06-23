#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

template<typename T>

void iswap(T& n1, T& n2)
{
	T temp = n1;
	n1 = n2;
	n2 = temp;
}


int main()
{
	ifstream file1;
	ofstream file2;
	string fil1 = "Text1.txt";
	file1.open(fil1);
	if (!file1.is_open())
		cout << "error";
	else
	{
		char f;
		vector<char> v;
		while (file1.get(f))
			if (f != ' ')
				v.push_back(f);
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << " ";
		cout << endl;
		//сортировка

		int sh = 0; // Смещение
		bool b;
		do
		{
			b = false;
			for (int i = 0; i < v.size(); i++)
			{
				if (i * 2 + 2 + sh < v.size())
				{
					if ((v[i + sh] > /*<*/ v[i * 2 + 1 + sh]) || (v[i + sh] > /*<*/ v[i * 2 + 2 + sh]))
					{
						if (v[i * 2 + 1 + sh] < /*>*/ v[i * 2 + 2 + sh])
						{
							iswap(v[i + sh], v[i * 2 + 1 + sh]);
							b = true;
						}
						else if (v[i * 2 + 2 + sh] < /*>*/ v[i * 2 + 1 + sh])
						{
							iswap(v[i + sh], v[i * 2 + 2 + sh]);
							b = true;
						}
					}
					// Дополнительная проверка для последних двух элементов;
					// с её помощью можно отсортировать пирамиду
					// состоящую всего лишь из трёх элементов
					if (v[i * 2 + 2 + sh] < /*>*/ v[i * 2 + 1 + sh])
					{
						iswap(v[i * 2 + 1 + sh], v[i * 2 + 2 + sh]);
						b = true;
					}
				}
				else if (i * 2 + 1 + sh < v.size())
				{
					if (v[i + sh] > /*<*/ v[i * 2 + 1 + sh])
					{
						iswap(v[i + sh], v[i * 2 + 1 + sh]);
						b = true;
					}
				}
			}
			if (!b)
				++sh; // Смещение увеличивается, когда на текущем этапе сортировать больше нечего
		} while (sh + 2 < v.size()); // Конец сортировки

		cout << endl << endl;
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << ' ';

		//запись данных в файл
		file2.open(fil1, ofstream::app);
		file2 << endl;
		if (!file2.is_open())
			cout << "error";
		else
			for (int i = 0; i < v.size(); i++)
				file2 << v[i] << " ";
		file2.close();
	}
	file1.close();
	return 0;
}
