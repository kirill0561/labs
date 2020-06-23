#include <iostream>
using namespace std;

void I1(double);
void I2(double);
void I3(double);
void I4(double);

int main()
{
    setlocale(LC_ALL, "ru");
    cout << "1.Посчитать 3+x\n";
    cout << "2.Посчитать x*x+2\n";
    cout << "3.Посчитать 12/x+4\n";
    cout << "4.Посчитать x-12*3\n";
    cout << "Какую функцию выбрать?\n ";
    int choose;
    cin >> choose;
    choose--;
    void (*Array_of_functions[4])(double) = { I1,I2,I3,I4 };
    (*Array_of_functions[choose])(choose);
    return 0;
}
void I1(double)
{
    cout << "Введите х" << endl;
    double a = 3, x;
    cin >> x;
    cout << "Результат равен: " << a + x;
}
void I2(double)
{
    cout << "Введите х" << endl;
    double a = 2, x;
    cin >> x;
    cout << "Результат равен: " << x * x + a;
}
void I3(double)
{
    cout << "Введите х" << endl;
    double a = 4, b = 12, x;
    cin >> x;
    cout << "Результат равен: " << b / x + 4;
}
void I4(double)
{
    cout << "Введите х" << endl;
    double a = 12, b = 3, x;
    cin >> x;
    cout << "Результат равен: " << x - a * b;
}
