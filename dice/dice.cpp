#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

void displayDice(int die1, int die2) {
    // Отображение кубиков
    cout << "Кубики: [" << die1 << ", " << die2 << "]" << endl;
}

int rollDice() {
    // Бросок двух кубиков
    return (rand() % 6 + 1) + (rand() % 6 + 1);
}

int main() {
    setlocale(LC_ALL, "ru");

    srand(static_cast<unsigned int>(time(0))); // Инициализация генератора случайных чисел

    int humanScore = 0, computerScore = 0;
    char firstTurn;

    // Выбор первого хода
    cout << "Кто начинает первым? (h - человек, c - компьютер): ";
    cin >> firstTurn;

    if (firstTurn != 'h' && firstTurn != 'c') {
ConsoleApplication1        cerr << "Некорректный ввод. Пожалуйста, введите 'h' для человека или 'c' для компьютера." << std::endl;
        return 1;
    }

    // Игровая логика - 5 раундов
    for (int round = 1; round <= 5; ++round) {
        cout << "\nРаунд " << round << ":\n";

        // Ход игрока
        if (firstTurn == 'h') {
            cout << "Ход человека:\n";
            int humanRoll = rollDice();
            humanScore += humanRoll;
            displayDice(humanRoll / 2, (humanRoll + 1) / 2); // Отображение кубиков (сумма делится на 2)
            firstTurn = 'c'; // Передаем ход компьютеру
        }
        else {
            cout << "Ход компьютера:\n";
            int computerRoll = rollDice();
            computerScore += computerRoll;
            displayDice(computerRoll / 2, (computerRoll + 1) / 2); // Отображение кубиков
            firstTurn = 'h'; // Передаем ход игроку
        }

        // Если ход компьютера, отображаем результат
        if (firstTurn == 'h') {
            cout << "Ход компьютера:\n";
            int computerRoll = rollDice();
            computerScore += computerRoll;
            displayDice(computerRoll / 2, (computerRoll + 1) / 2); // Отображение кубиков
            firstTurn = 'h'; // Передаем ход игроку
        }
    }

    // Итоги игры
    cout << "\nИтоговые результаты:\n";
    cout << "Сумма очков человека: " << humanScore << "\n";
    cout << "Сумма очков компьютера: " << computerScore << "\n";

    // Определение победителя
    if (humanScore > computerScore) {
        cout << "Победил человек!" << endl;
    }
    else if (humanScore < computerScore) {
        cout << "Победил компьютер!" << endl;
    }
    else {
        cout << "Ничья!" << endl;
    }

    // Вывод средней суммы очков
    cout << fixed << setprecision(2);
    cout << "Средняя сумма очков человека: " << static_cast<double>(humanScore) / 5 << endl;
    cout << "Средняя сумма очков компьютера: " << static_cast<double>(computerScore) / 5 << endl;

    return 0;
}