#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;
int main()
{
	string fil1 = "Text1.txt";
	ifstream file1;
	file1.open(fil1);
	if (!file1.is_open())
	{
		cout << "error";
	}
	else
	{
		vector<double> v;
		double a;
		while (!file1.eof()) {
			file1 >> a;
			if (a - (int)a != 0)
			{
				v.push_back(a);
			}
		}
		double sum = 0;
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
			sum += v[i];
		}
		cout << endl;
		cout << "number of fractional numbers: " << v.size() << endl;
		cout << "sum= " << sum;
	}
	return 0;
}
