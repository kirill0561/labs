#include <iostream>
#include <string>
#include <fstream>
#include <string.h>

using namespace std;

struct student
{
    string name;
    int klass;
    int phone_number;
    int marks_math;
    int marks_physics;
    int marks_russian;
    int marks_literature;
};

void CreateStudent(student* Gos, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Введите" << i + 1 << " ФИО: ";
        while (cin.get() != '\n');
        getline(cin, Gos[i].name);
        cout << "Введите класс: ";
        cin >> Gos[i].klass;
        cout << "Введите номер телефона: ";
        cin >> Gos[i].phone_number;
        cout << "Введите отметку по математике: ";
        cin >> Gos[i].marks_math;
        cout << "Введите отметку по физике: ";
        cin >> Gos[i].marks_physics;
        cout << "Введите отметку по русскому языку: ";
        cin >> Gos[i].marks_russian;
        cout << "Введите отметку по литературе: ";
        cin >> Gos[i].marks_literature;
    }
}
void saveToFile(student* Gos, int n)
{
    ofstream fout;
    fout.open("Gos.txt", ios::app);
    for (int i = 0; i < n; i++)
    {
        fout << Gos[i].name << " ";
        fout << Gos[i].klass << " ";
        fout << Gos[i].phone_number << " ";
        fout << Gos[i].marks_math << " ";
        fout << Gos[i].marks_physics << " ";
        fout << Gos[i].marks_russian << " ";
        fout << Gos[i].marks_literature << endl;
    }
    cout << "Информация была успешно добавлена в файл. " << endl << endl;
    fout.close();
}

void strucFile(student* GosFile, int n)
{
    ifstream fin;
    fin.open("Gos.txt");
    ofstream fout;
    fout.open("Goss.txt");
    for (int i = 0; i < n - 1; i++)
    {
        fin >> GosFile[i].name;
        fin >> GosFile[i].klass;
        fin >> GosFile[i].phone_number;
        fin >> GosFile[i].marks_math;
        fin >> GosFile[i].marks_physics;
        fin >> GosFile[i].marks_russian;
        fin >> GosFile[i].marks_literature;
        for (int j = i + 1; j < n; j++)
        {
            fin >> GosFile[j].name;
            fin >> GosFile[j].klass;
            fin >> GosFile[j].phone_number;
            fin >> GosFile[i].marks_math;
            fin >> GosFile[i].marks_physics;
            fin >> GosFile[i].marks_russian;
            fin >> GosFile[i].marks_literature;
            if (GosFile[i].phone_number > GosFile[j].phone_number)
            {
                student x;
                x = GosFile[i];
                GosFile[i] = GosFile[j];
                GosFile[j] = x;
            }
        }
        fout << GosFile[i].name << " ";
        fout << GosFile[i].klass << " ";
        fout << GosFile[i].phone_number << " ";
        fout << GosFile[i].marks_math << " ";
        fout << GosFile[i].marks_physics << " ";
        fout << GosFile[i].marks_russian << " ";
        fout << GosFile[i].marks_literature << endl;
    }
    fout.close();
    fin.close();
    cout << "Информация была перезаписана в новый файл! " << endl << endl;
}

int countLines()
{
    int x = 0;
    ifstream fin;
    fin.open("Gos.txt");
    for (int i = 0; !fin.eof(); i++)
    {
        string str;
        getline(fin, str);
        x++;
    }
    return x;
}

int main()
{
    setlocale(LC_ALL, "rus");
    while (1)
    {
        cout << "Нажмите 1 для добавления информации. " << endl;
        cout << "Нажмите 2 для сортировки" << endl;
        cout << "Нажмите 3 для окончания работы с программой. " << endl;
        int flagMenu;
        cin >> flagMenu;
        if (flagMenu == 1)
        {
            cout << "Введите количество школьников: ";
            int n;
            cin >> n;
            student* Gos = new student[n];
            CreateStudent(Gos, n);
            saveToFile(Gos, n);
        }
        int strCount = 0;
        strCount = countLines();
        student* GosFile = new student[strCount];
        if (flagMenu == 2)
            strucFile(GosFile, strCount);
        if (flagMenu == 3)
            break;
    }
    return 0;
}
