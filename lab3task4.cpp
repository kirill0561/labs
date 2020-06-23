#include <iostream>
#include <vector>
#include<fstream>
#include<string>
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
        char f;
        vector<char>v;
        while (file1.get(f))
        {
            if (f == ' ')
                break;
            else
                v.push_back(f);
        }
        for (int i = 0; i < v.size(); i++)
            cout << v[i];
        file1.close();
    }
    return 0;
}
