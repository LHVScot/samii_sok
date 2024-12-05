#include <iostream>
#include <string>

using namespace std;

int

string sysOFnum(int a, int b) {
    // Проверка на корректность входных данных
    if (a < 1 || b < 2 || b > 36) {
        cout<<"Число должно быть положительным, а основание от 2 до 36.";
    }

    string res;
    const char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Перевод числа в нужную систему счисления
    while (a > 0) {
        int rem = a % b; // Остаток от деления
        res.insert(res.begin(), digits[rem]); // Вставляем символ в начало строки
        a /= b; // Уменьшаем число
    }

    return res;
}



int main() {
    setlocale(LC_ALL, "ru");

    int a, b;

    cout << "Введите положительное целое число: ";
    cin >> a;
    cout << "какая система счисления нужна? (от 2 до 36): ";
    cin >> b;
    
    string res = sysOFnum(a, b);
    cout << "Число " << a << " в системе счисления " << b << " равно " << res << endl;
    

   

    return 0;
}