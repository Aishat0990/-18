#include "array_io.h"

#include <iostream>
#include <limits>

// Запрашивает у пользователя размер массива и его элементы.
// Сначала считывается размер (целое неотрицательное число),
// затем — ровно столько целых чисел, сколько указано в размере.
// Возвращает заполненный вектор.
std::vector<int> readArrayFromKeyboard() {
    int size = 0;

    // Цикл повторяется, пока пользователь не введёт корректный размер:
    // целое число >= 0.
    while (true) {
        std::cout << "Введите размер массива: ";
        if (std::cin >> size && size >= 0) {
            break;
        }
        std::cout << "Ошибка: размер должен быть целым неотрицательным числом.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::vector<int> arr;
    arr.reserve(static_cast<std::size_t>(size));

    if (size > 0) {
        std::cout << "Введите " << size << " целых чисел через пробел:\n";
    }

    for (int i = 0; i < size; ++i) {
        int value = 0;

        // Аналогично — ждём корректный ввод для каждого элемента.
        while (true) {
            if (std::cin >> value) {
                arr.push_back(value);
                break;
            }
            std::cout << "Ошибка: ожидается целое число. Повторите ввод элемента #"
                      << (i + 1) << ": ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    return arr;
}

// Выводит элементы массива в одну строку через пробел.
// Принимает вектор целых чисел по константной ссылке
// (чтобы не копировать данные).
void printArray(const std::vector<int>& arr) {
    if (arr.empty()) {
        std::cout << "(массив пуст)\n";
        return;
    }

    for (std::size_t i = 0; i < arr.size(); ++i) {
        if (i > 0) {
            std::cout << ' ';
        }
        std::cout << arr[i];
    }
    std::cout << '\n';
}
