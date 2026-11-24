#include "digit_utils.h"

bool hasExactlyOneFive(long long n) {
    // Работаем с беззнаковым представлением модуля числа.
    // Это позволяет корректно обработать LLONG_MIN:
    // стандартный -n для него приводит к переполнению,
    // а преобразование в unsigned long long даёт корректный модуль.
    unsigned long long value =
        (n < 0) ? (0ULL - static_cast<unsigned long long>(n))
                : static_cast<unsigned long long>(n);

    // Отдельно обрабатываем ноль: в записи "0" нет цифры 5.
    if (value == 0ULL) {
        return false;
    }

    int countFives = 0;

    while (value > 0ULL) {
        if (value % 10ULL == 5ULL) {
            ++countFives;
            // Ранний выход: если пятёрок уже больше одной — ответ известен.
            if (countFives > 1) {
                return false;
            }
        }
        value /= 10ULL;
    }

    return countFives == 1;
}
