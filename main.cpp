#include <fstream>
#include "polinom.h"

void readme()
{
    ifstream in;
    in.open("README");
    string str;
    while (getline(in,str)) {
        cout << str << endl;
    }
    cout << endl;
    in.close();
}

int Menu()
{
    cout << "Введите номер пункта меню:" << endl;
    cout << "1. Сумма многочленов;" << endl;
    cout << "2. Разность многочленов;" << endl;
    cout << "3. Произведение многочленов;" << endl;
    cout << "0. Выход" << endl;
    int pt = 0;
    cin >> pt;
    return pt;
}

int main()
{
    readme();

    srand(time(NULL));

    while (int pt = Menu()) {
        int n = 0;
        cout << "Введите степень первого многочлена: ";
        cin >> n;
        Polinom a(n);
        a.output();
        cout << "Введите степень второго многочлена: ";
        cin >> n;
        Polinom b(n);
        b.output();

        switch (pt) {
            case 1: {
                Polinom c = a + b;
                cout << "C = A + B :   ";
                c.output();
                break;
            }
            case 2: {
                Polinom c = a - b;
                cout << "C = A - B :   ";
                c.output();
                break;
            }
            case 3: {
                Polinom c = a * b;
                cout << "C = A * B :   ";
                c.output();
                break;
            }
            default:
                cout << "Пункта меню с таким номером нет";
        }
    }
}
