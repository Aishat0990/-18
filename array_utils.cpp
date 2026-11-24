#include "array_utils.h"
#include "digit_utils.h"

ProductResult productOfElementsWithOneFive(const std::vector<int>& arr) {
    ProductResult result;
    result.found = false;
    result.product = 1;
    result.count = 0;

    for (int value : arr) {
        // Неявное расширение int -> long long безопасно.
        if (hasExactlyOneFive(value)) {
            result.product *= static_cast<long long>(value);
            result.found = true;
            ++result.count;
        }
    }

    return result;
}
