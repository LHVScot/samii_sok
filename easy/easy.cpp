#include <iostream>

using namespace std;

void pryam(int n, int k) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cout << "*";
        }
        cout << "\n";
    }
}

bool is_prime(int n) {
    cout << "если 1 - простое число\nесли 0 - не простое:\n";
    if (n <= 1) return false;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int fact(int a) {
    int res = 1;
    for (int i = 1; i <= a; i++) {
        res *= i;
    }
    return res;
}
void reverseArray(int array[], int size) {
    for (int i = 0; i < size / 2; ++i) {
        // Меняем местами элементы
        int temp = array[i];
        array[i] = array[size - i - 1];
        array[size - i - 1] = temp;
    }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "ru");
    int a, b, n,k;
    cout << "введите n: ";
    cin >> n;
    cout << "введите k: ";
    cin >> k;
    pryam(n, k);
    cout << "введите число факториала: ";
    cin >> a;
    cout << fact(a) << endl;
    cout << "введите число для проверки на простоту: ";
    cin >> b;
    cout << is_prime(b) << endl;
    
    int array[] = { 1, 2, 3, 4, 5 };
    int size = sizeof(array) / sizeof(array[0]);

    cout << "Исходный массив: ";
    printArray(array, size);

    reverseArray(array, size);

    cout << "Массив после инверсии: ";
    printArray(array, size);
}

