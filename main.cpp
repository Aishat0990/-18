#include <iostream>
#include "array_io.h"
#include "array_utils.h"

int main() {
    std::vector<int> arr = readArrayFromKeyboard();

    std::cout << "Исходный массив: ";
    printArray(arr);

    ProductResult result = productOfElementsWithOneFive(arr);

    if (!result.found) {
        std::cout << "Нет элементов, в записи которых ровно одна цифра 5.\n";
        return 0;
    }

    std::cout << "Найдено подходящих элементов: " << result.count << "\n";
    std::cout << "Произведение: " << result.product << "\n";

    return 0;
}
