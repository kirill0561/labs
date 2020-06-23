﻿#include <iostream>
#include <string>
#include <vector>
#include<fstream>
using namespace std;

int main()
{
    string fil1 = "Text1.txt";
    string fil2 = "Text2.txt";
    ifstream file1;
    ofstream file2;
    file1.open(fil1);
    if (!file1.is_open())
    {
        cout << "error";
    }
    else
    {
        string f;
        vector<string>v;
        while (!file1.eof())
        {
            f = "";
            getline(file1, f);
            v.push_back(f);
        }
        file2.open(fil2, ofstream::app);
        if (!file2.is_open())
        {
            cout << "error";
        }
        else
        {
            file2 << endl;
            for (int i = 0; i < v.size(); i++)
            {
                file2 << v[i] << endl;
            }
            file2.close();
        }
        file1.close();
    }
    return 0;
}
