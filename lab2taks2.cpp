#include<iostream>
#include<string>
#include<vector>
using namespace std;
void Foo(string& S, char C)
{
	int size = S.size();
	for (int i = 0; i < size; i++)
	{
		if (S[i] == C)
		{
			S.erase(S.begin() + i);
			i--;
			size--;
		}
	}
}
int main()
{
	setlocale(0, "ru");
	char C;
	cout << "Введите символ ";
	cin >> C;
	string S;
	for (int i = 0; i < 5; i++)
	{
    	cout << "Введите строку ";
		cin >> S;
		Foo(S, C);
		cout << S << endl;
	}
	return 0;
}