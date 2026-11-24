#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

#include <vector>

// Структура результата поиска произведения.
struct ProductResult {
    bool found;        // найден ли хотя бы один подходящий элемент
    long long product; // произведение подходящих элементов
    int count;         // количество подходящих элементов
};

// Вычисляет произведение элементов массива, в записи которых ровно одна цифра 5.
ProductResult productOfElementsWithOneFive(const std::vector<int>& arr);

#endif // ARRAY_UTILS_H
